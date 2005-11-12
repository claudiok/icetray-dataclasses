#ifndef TTREE_OARCHIVE_GRAPH_UTILS
#define TTREE_OARCHIVE_GRAPH_UTILS

#include <vector>
#include <boost/graph/adjacency_list.hpp>

using namespace boost;

namespace boost {
  enum vertex_data_t { vertex_data = 123 };
  BOOST_INSTALL_PROPERTY(vertex, data);
}

template <typename Graph, typename VertexPropertyMap>
void dump_graph(const Graph& g, const VertexPropertyMap& propertymap)
{
  typedef typename graph_traits<Graph>::vertex_iterator iter_t;
  
  cout << "GRAPH:\n";
  for (pair<iter_t,iter_t> p = vertices(g);
       p.first != p.second;
       ++p.first)
    {
      cout << "\t" <<  get(propertymap, *p.first) << "\n";
      //      cout << "\tbranchname:" << branchname(g, *p.first, propertymap, 1) << "\n";
      //      cout << "\tbranchname:" << branchname(g, *p.first, propertymap, 2) << "\n";
      //      cout << "\tbranchname:" << branchname(g, *p.first, propertymap, 3) << "\n";
    }
}


template <typename Graph, typename Vertex, typename PropertyMap>
std::string branchname(Graph g, Vertex v, PropertyMap p, unsigned maxdepth=32)
{
  string the_branchname;

  assert(in_degree(v, g) < 2);

  string my_name = get(p, v).name;

  if (in_degree(v,g) <= 0 || maxdepth <= 1)
    return my_name;
  
  Vertex parent = source(*(in_edges(v, g).first), g);
  
  if (out_degree(parent, g) > 1)
    return branchname (g, parent, p, maxdepth-1) + "." + my_name;
  else
    return branchname (g, parent, p, maxdepth-1);
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
      vertex_name_map.clear();

      for (typename vertex_vec::iterator i = leaves.begin(); 
	   i != leaves.end(); 
	   i++)
	{
	  //	  cout << get(props,*i);
	  vertex_name_map[get(props, *i).branch_name].push_back(*i);
	}

      for (typename vertex_name_map_t::iterator i = vertex_name_map.begin();
	   i != vertex_name_map.end();
	   i++)
	{
	  std::vector<vertex_desc> v = i->second;
	  if (v.size() != 1)
	    //	      cout << "UNIQUE:" << i->first << "\n";
	      //	      get(props,v[0]).is_unique = true;
	    //	  else
	    {
	      for (unsigned int j=0; j<v.size(); j++)
		{
		  string new_branchname = branchname (g, v[j], props, depth);
		  get(props, v[j]).branch_name = new_branchname;
		  //		  cout << "SET TO:" << get(props, v[j]).branch_name << "?=" << new_branchname << "\n";
		}
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
	    collision_remains = true;
	}
    } 
  //  dump_graph(g, props);
}

#endif
