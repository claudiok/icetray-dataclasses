#ifndef TTREE_OARCHIVE_H_INCLUDED
#define TTREE_OARCHIVE_H_INCLUDED

#include <boost/archive/detail/common_oarchive.hpp>

#include <boost/utility/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>

#include <typeinfo>
#include <memory>
#include <stdexcept>

#include <boost/graph/adjacency_list.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <TTree.h>

#include <iostream>
#include <iomanip>
using namespace std;

#include <dataclasses/ttree_oarchive_graph_utils.h>
#include <dataclasses/ttree_typechar_traits.h>

namespace boost { 

  namespace archive {

    class ttree_oarchive_impl : 
      public boost::archive::detail::common_oarchive<ttree_oarchive_impl>
    {
      typedef boost::mpl::vector<const char*,
				 bool,
				 char, unsigned char,
				 short, unsigned short,
				 int, unsigned int,
				 int64_t, uint64_t,
				 float, double> treeable_types;

      unsigned stack;
      bool write_header;
      TTree& tree_;

    public:
      struct vertex_data_struct
      {
	char type_char;
	void *px;
	std::string name;
	std::string branch_name;
	bool is_unique;
	vertex_data_struct() : type_char('_'), px(0), name(""), is_unique(false) 
	{ }
	vertex_data_struct(char type_char_, void* px_, std::string name_) :
	  type_char(type_char_), px(px_), name(name_), is_unique(false)
	{ }
      };
  
    private:

      typedef property<vertex_data_t, vertex_data_struct> vertex_properties;
      typedef adjacency_list < vecS, vecS, bidirectionalS,
			       vertex_properties> directed_graph;
      typedef graph_traits<directed_graph>::vertex_descriptor vertex_descriptor;
      typedef property_map<directed_graph, vertex_data_t>::type vertex_property_map;

      directed_graph g;
      vertex_property_map props;
      vertex_descriptor current_vertex;

      // permit serialization system priviledged access to permit
      // implementation of inline templates for maximum speed.
      friend class boost::archive::save_access;
      friend class boost::archive::detail::common_oarchive<ttree_oarchive_impl>;
      friend class boost::archive::detail::interface_oarchive<ttree_oarchive_impl>;

      template <typename T>
      void
      save (const T& t)
      {
	if (! boost::mpl::contains<treeable_types, T>::value)
	  return;
	string column_name;

	get(props, current_vertex).type_char = boost::archive::root::typechar_traits<T>::value;
	get(props, current_vertex).px = const_cast<T*>(&t);

      }

      // Anything not an attribute and not a name-value pair is an
      // error and should be trapped here.
      template<class T>
      void save_override(const T& t, BOOST_PFTO int)
      {
	// If your program fails to compile here, its most likely due to
	// not specifying an nvp wrapper around the variable to
	// be serialized.
	BOOST_STATIC_ASSERT(0 == sizeof(T));
      }

      void write_to_stream()
      {
	generate_branchnames(g, props);

	typedef std::vector<vertex_descriptor> vertex_vec;
	vertex_vec leaves = data_nodes(g, props);

	for (vertex_vec::iterator i = leaves.begin(); 
	     i != leaves.end(); 
	     i++)
	  {
	    const string& branch_name = get(props, *i).branch_name;
	    const char    type_char   = get(props, *i).type_char;
	    void *address             = get(props, *i).px;
	    const string branch_name_w_spec = branch_name + "/" + type_char;
	    //	    cout << "branch_name_w_spec=" << branch_name_w_spec << "\n";
	    if (write_header)
	      tree_.Branch(branch_name.c_str(), address, branch_name_w_spec.c_str());
	    else
	      {
		TBranch* branch = tree_.GetBranch(branch_name.c_str());
		assert(branch);
		branch->SetAddress(address);
	      }
	  }

	tree_.Fill();
      }

    protected:

      template <typename T>
      void
      save_override(const ::boost::serialization::nvp<T>& nv_pair, int)
      {
	// enums get converted to ints, called with nvp with null name.
	if (nv_pair.name())
	  {
	    stack++;
	    if (num_vertices(g) == 0)
	      {
		current_vertex = add_vertex(g);
		put(props, current_vertex, vertex_data_struct('_', NULL, nv_pair.name()));
	      }
	    else
	      {
		vertex_descriptor new_vertex = add_vertex(g);
		put(props, new_vertex, vertex_data_struct('_', NULL, nv_pair.name()));
		add_edge(current_vertex, new_vertex, g);
		current_vertex = new_vertex;
	      }
	  }

	archive::save(*this->This(), nv_pair.value());

	if (nv_pair.name())
	  {
	    stack--;
	    current_vertex = source(*(in_edges(current_vertex, g).first), g);

	    if (stack == 0)
	      write_to_stream();
	  }
	       
      }

      template <typename T>
      void
      save_override(const ::boost::serialization::nvp<shared_ptr<T> >& nv_pair, int)
      {
	stack++;
	archive::save(*this->This(), nv_pair.value().px);
	stack--;

	if (stack == 0)
	  write_to_stream();
      }

      //////////////////////////////////////////////////////////
      // public interface used by programs that use the
      // serialization library

      // archives are expected to support this function
      void save_binary(void *address, std::size_t count);

      void save_override(const object_id_type & t, int){ }
      void save_override(const object_reference_type & t, int){ }
      void save_override(const version_type & t, int){ }
      void save_override(const class_id_type & t, int){ }
      void save_override(const class_id_optional_type & t, int){ }
      void save_override(const class_id_reference_type & t, int){ }
      void save_override(const class_name_type & t, int){ }
      void save_override(const tracking_type & t, int){ }

    public:
      ttree_oarchive_impl(TTree& tree, bool write_header_ = false) 
	: stack(0), write_header(write_header_), tree_(tree) 
      { 
	props = get(vertex_data, g);
      }
  
    }; 

    inline
    ostream&
    operator<<(ostream& os, const ttree_oarchive_impl::vertex_data_struct& ndata)
    {
      os << "[n:" << ndata.name << " bn:" << ndata.branch_name << " tc:" << ndata.type_char 
	 << " px:" << ndata.px << " u:" << ndata.is_unique << "]";
      return os;
    }

  }
}

#define BOOST_ARCHIVE_CUSTOM_OARCHIVE_TYPES boost::archive::ttree_oarchive_impl

class ttree_oarchive
{

  TTree& tree_;
  bool write_header_;

public:

  template <typename T>
  void operator<<(const T & t)
  {
    boost::archive::ttree_oarchive_impl impl(tree_, write_header_);
    // should check type of T here.
    impl << t;
    write_header_ = false;
  }

  ttree_oarchive(TTree& tree) : tree_(tree), write_header_(true) { }

};
#endif
