#include <dataclasses/ttree_proxy.h>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/adjacency_list.hpp>

#include <iostream>
#include <string>
#include <TTree.h>

#include "icetray/services/I3Logging.h"

using namespace std;
using boost::tuples::tie;

namespace boost {

  enum vertex_data_t { vertex_data = 123 };
  BOOST_INSTALL_PROPERTY(vertex, data);

  namespace archive {
    namespace detail {

      using namespace boost;

      struct always_true {
	template <typename Edge>
	bool operator()(const Edge& e) { return true; }
      };

      template <typename Graph, typename VertexPropertyMap>
      void dump_graph(const Graph& g, const VertexPropertyMap& propertymap)
      {
	typename graph_traits<Graph>::vertex_iterator iter, end;
  
	std::cout << "GRAPH:\n";

	for (tie(iter, end) = vertices(g);
	     iter != end;
	     ++iter)
	  {
	    std::cout << "\t" <<  get(propertymap, *iter) << "\n";
	  }
      }

      template <typename Vertex, typename Graph>
      Vertex parent(const Vertex &v, const Graph &g)
      {
	assert(in_degree(v,g) == 1);
	Vertex parent_vertex = source(*(in_edges(v, g).first), g);
	return parent_vertex;
      }

      template <typename Vertex, typename Graph>
      Vertex parent_n(const Vertex &v, const Graph &g, unsigned n)
      {
	Vertex parent_v = v;
	for (int i = 0; i<n; i++)
	  parent_v = parent(parent_v, g);
	return parent_v;
      }
      
      template <typename Vertex, typename Graph>
      unsigned depth(const Vertex &v, const Graph &g)
      {
	Vertex u = v;
	unsigned depth_=0;

	while (in_degree(u,g) == 1)
	  {
	    assert(in_degree(u,g) < 2);
	    u = parent(u,g);
	    depth_++;
	  }
	return depth_;
      }

      template <typename Graph, typename Vertex, typename PropertyMap>
      std::string branchname(Graph g, Vertex v, PropertyMap p, unsigned maxdepth=32, bool leaf=true)
      {
	string the_branchname;

	assert(in_degree(v, g) < 2);

	string my_name = get(p, v).name;

	if (in_degree(v,g) <= 0 || maxdepth <= 1)
	  return my_name;
  
	Vertex up = parent(v,g);
  
	// v is an only child and is not a leaf, omit my_name
	if (out_degree(up, g) == 1 && !leaf)
	  {
	    log_trace("skipping %s", my_name.c_str());
	    return branchname (g, up, p, maxdepth-1, false);
	  }
	else
	  // my name is useful.  keep it.
	  return branchname (g, up, p, maxdepth-1, false) + "_" + my_name;
      }

      //
      // "data" nodes are those whose px != null
      //
      template <typename Graph, typename PropertyMap>
      std::vector<typename graph_traits<Graph>::vertex_descriptor>
      data_nodes(const Graph& g, const PropertyMap& p)
      {
	std::vector<typename graph_traits<Graph>::vertex_descriptor> v;

	typename graph_traits<Graph>::vertex_iterator current, end;
  
	for (tie(current, end) = vertices(g);
	     current != end;
	     ++current)
	  {
	    if (get(p, *current).px != NULL)
	      v.push_back(*current);
	  }
	return v;
      }

      template <typename Graph, typename VertexProperties>
      void generate_branchnames(const Graph &g, VertexProperties& props)
      {
	typedef typename graph_traits<Graph>::vertex_descriptor vertex_desc;
	typedef std::vector<vertex_desc> vertex_vec;
	typedef map<std::string, std::vector<vertex_desc> > vertex_name_map_t;
	vertex_name_map_t vertex_name_map;

	vertex_vec leaves = data_nodes(g,props);

	bool collision_remains = true;

	unsigned depth = 1;
	while(collision_remains) 
	  {
	    //	    dump_graph(g,props);
	    vertex_name_map.clear();

	    for (typename vertex_vec::iterator i = leaves.begin(); 
		 i != leaves.end(); 
		 i++)
	      {
		vertex_name_map[get(props, *i).branch_name].push_back(*i);
	      }

	    // where vertex name map contains > 1 entry there is a name collison
	    // 
	    for (typename vertex_name_map_t::iterator i = vertex_name_map.begin();
		 i != vertex_name_map.end();
		 i++)
	      {
		std::vector<vertex_desc> v = i->second;
		if (v.size() != 1)
		  {
		    for (unsigned int j=0; j<v.size(); j++)
		      get(props, v[j]).branch_name = branchname (g, v[j], props, depth);
		  }
	      }
	    depth++;

	    collision_remains = false;
	    for (typename vertex_name_map_t::iterator i = vertex_name_map.begin();
		 i != vertex_name_map.end();
		 i++)
	      {
		std::vector<vertex_desc> v = i->second;
		if (v.size() > 1)
		  {
		    collision_remains = true;
		    log_trace("collision(%zu) %s", v.size(), (i->first).c_str());
		  }
	      }
	  } 
      }


      struct vertex_data_struct
      {
	char type_char;
	void *px;
	std::string name;
	std::string branch_name;
	int branch_order;
	vertex_data_struct() : type_char('_'), px(0), name(""), branch_order(-1) 
	{ }
	vertex_data_struct(char type_char_, void* px_, std::string name_) :
	  type_char(type_char_), px(px_), name(name_), branch_order(-1)
	{ }
      };
      
      inline
      ostream&
      operator<<(ostream& os, const vertex_data_struct& ndata)
      {
	os << "[n:" << ndata.name << " bn:" << ndata.branch_name << " tc:" << ndata.type_char 
	   << " px:" << ndata.px << " u:" << ndata.branch_order << "]";
	return os;
      }

      typedef property<vertex_data_t, vertex_data_struct> vertex_properties;
      typedef adjacency_list < vecS, vecS, bidirectionalS,
			       vertex_properties> directed_graph;
      typedef graph_traits<directed_graph>::vertex_descriptor vertex_descriptor;
      typedef property_map<directed_graph, vertex_data_t>::type vertex_property_map;

      //
      //  implements the ttree proxy
      // 
      class ttree_proxy_impl
      {
	directed_graph g;
	vertex_property_map props;
	vertex_descriptor current_vertex;

	TTree& tree_;
	bool write_header;
	
	// for speed
	unsigned branch_counter;
	vector<pair<TBranch*,void*> > branched;

      public:

	ttree_proxy_impl(TTree & tree) : tree_(tree), write_header(true), branch_counter(0)
	{
	  props = get(vertex_data, g);
	}

	void 
	branch(char type_char, void* px)
	{
	  if (write_header)
	    {
	      get(props, current_vertex).type_char = type_char;
	      get(props, current_vertex).px = px;
	      get(props, current_vertex).branch_order = branch_counter;
	    }
	  else
	    branched[branch_counter].second = px;

	  branch_counter++;
	}

	void push(const std::string & name)
	{
	  // TODO:  check here for bogus push of same name twice
	  if (write_header)
	    if (num_vertices(g) == 0)
	      {
		current_vertex = add_vertex(g);
		put(props, current_vertex, vertex_data_struct('_', NULL, name));
	      }
	    else
	      {
		vertex_descriptor new_vertex = add_vertex(g);
		put(props, new_vertex, vertex_data_struct('_', NULL, name));
		add_edge(current_vertex, new_vertex, g);
		current_vertex = new_vertex;
	      }
	}

	void pop()
	{
	  if (write_header)
	    current_vertex = source(*(in_edges(current_vertex, g).first), g);
	}

	void fill()
	{
	  if (write_header)
	    {
	      generate_branchnames(g, props);
	  
	      typedef std::vector<vertex_descriptor> vertex_vec;
	      vertex_vec leaves = data_nodes(g, props);

	      branched.resize(branch_counter);

	      for (vertex_vec::iterator i = leaves.begin(); 
		   i != leaves.end(); 
		   i++)
		{
		  const string& branch_name       = get(props, *i).branch_name;
		  const char    type_char         = get(props, *i).type_char;
		  void *address                   = get(props, *i).px;
		  int branchnum                   = get(props, *i).branch_order;
		  const string branch_name_w_spec = branch_name + "/" + type_char;
		  
		  branched[branchnum].first = 
		    tree_.Branch(branch_name.c_str(), address, branch_name_w_spec.c_str());
		  assert(branched[branchnum].first);
		}
	    }
	  else
	    {
	      for (unsigned j=0; j<branched.size(); j++)
		{
		  assert(branched[j].first);
		  assert(branched[j].second);
		  branched[j].first->SetAddress(branched[j].second);
		}
	    }

	  tree_.Fill();
	  branch_counter = 0;

	  if (write_header)
	    {
	      // clearing these graphs entirely is kind of a complicated
	      // business.  First the edges, then the vertices.
	      remove_edge_if(always_true(), g);
	      assert(num_edges(g) == 0);
	      g = directed_graph(); 
	      assert(num_vertices(g) == 0);
	      write_header = false;
	    }
	}
      };

    } // boost
  } // archive
} // detail


//
//  Here's the front end all that stuff above hides behind.
//

ttree_proxy::ttree_proxy(TTree& tree) 
  : impl_(new boost::archive::detail::ttree_proxy_impl(tree)) 
{ }
      
void
ttree_proxy::push(const std::string & name)
{
  impl_->push(name);
}

void
ttree_proxy::pop()
{
  impl_->pop();
}

void
ttree_proxy::branch(char typechar, void* address)
{
  impl_->branch(typechar, address);
}
      
void
ttree_proxy::fill()
{
  impl_->fill();
}

ttree_proxy::~ttree_proxy() { }

