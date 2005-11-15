#ifndef TTREE_OARCHIVE_H_INCLUDED
#define TTREE_OARCHIVE_H_INCLUDED

#include <boost/archive/detail/common_oarchive.hpp>

#include <typeinfo>
#include <memory>
#include <stdexcept>

#include <boost/serialization/shared_ptr.hpp>

class TTree;

#include <iostream>
#include <iomanip>
using namespace std;

#include <dataclasses/ttree_proxy.h>
#include <dataclasses/ttree_typechar_traits.h>

namespace boost { 
  namespace archive {

    class ttree_oarchive_impl : 
      public boost::archive::detail::common_oarchive<ttree_oarchive_impl>
    {
      unsigned stack;
      ttree_proxy& ttree_proxy_;
      
    private:

      // permit serialization system priviledged access to permit
      // implementation of inline templates for maximum speed.
      friend class boost::archive::save_access;
      friend class boost::archive::detail::common_oarchive<ttree_oarchive_impl>;
      friend class boost::archive::detail::interface_oarchive<ttree_oarchive_impl>;

      template <typename T>
      void
      save (const T& t)
      {
	if (boost::archive::root::typechar_traits<T>::value == '?')
	  return;

	ttree_proxy_.branch(boost::archive::root::typechar_traits<T>::value,
			    const_cast<T*>(&t));
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
	ttree_proxy_.fill();
      }

    protected:

      template <typename T>
      void
      save_override(const ::boost::serialization::nvp<T>& nv_pair, int)
      {
	// enums get converted to ints, called with nvp with null name.
	if (nv_pair.name())
	  {
	    ttree_proxy_.push(nv_pair.name());
	    stack++;
	  }

	archive::save(*this->This(), nv_pair.value());

	if (nv_pair.name())
	  {
	    stack--;
	    ttree_proxy_.pop();
	    if (stack == 0)
	      ttree_proxy_.fill();
	  }
	       
      }

      // special case to skip px in shared_ptr
      template <typename T>
      void
      save_override(const ::boost::serialization::nvp< ::boost::shared_ptr<T> >& nv_pair, int)
      {
	// enums get converted to ints, called with nvp with null name.
	if (nv_pair.name())
	  {
	    ttree_proxy_.push(nv_pair.name());
	    stack++;
	  }

	archive::save(*this->This(), nv_pair.value().px);

	if (nv_pair.name())
	  {
	    stack--;
	    ttree_proxy_.pop();
	    if (stack == 0)
	      ttree_proxy_.fill();
	  }
	       
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
      ttree_oarchive_impl(ttree_proxy& ttree_proxy__) 
	: stack(0), ttree_proxy_(ttree_proxy__)
      { 
	//	props = get(vertex_data, g);
      }
  
    }; 

  }
}

#define BOOST_ARCHIVE_CUSTOM_OARCHIVE_TYPES boost::archive::ttree_oarchive_impl

class ttree_oarchive
{

  ttree_proxy ttree_proxy_;

public:

  template <typename T>
  void operator<<(const T & t)
  {
    boost::archive::ttree_oarchive_impl impl(ttree_proxy_);
    // should check type of T here.
    impl << t;
  }

  ttree_oarchive(TTree& tree) : ttree_proxy_(tree) { }

};
#endif
