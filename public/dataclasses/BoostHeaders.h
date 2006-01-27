
#ifndef BOOSTHEADERS_H_INCLUDED
#define BOOSTHEADERS_H_INCLUDED

#include "dataclasses/ttree_oarchive.h"

#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/is_abstract.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/split_member.hpp>

using boost::serialization::make_nvp;
using boost::serialization::base_object;

// this is a no-op.  Allows us to serialize classes derived from
// TObject via ptr/ref to TObject.
template <class Archive>
void 
serialize(Archive & ar, TObject & tobj, unsigned version)
{  
}

template <typename T>
struct instantiate_polymorphics
{
  typedef boost::archive::detail::interface_oarchive<
    boost::archive::polymorphic_oarchive> po;

  typedef boost::archive::detail::interface_iarchive<
    boost::archive::polymorphic_iarchive> pi;

  void instantiate(po & oa, const T & t);
  void instantiate(pi & ia, T & t);
};

template <typename T>
void instantiate_polymorphics<T>::instantiate(po & oa, const T & t) 
{
  oa & t;
}

template <typename T>
void instantiate_polymorphics<T>::instantiate(pi & ia, T & t) 
{
  ia & t;
}

namespace detail 
{
  template <typename T>
  void inst (boost::archive::binary_oarchive& poa, const T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::binary_iarchive& poa, T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::xml_oarchive& poa, const T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::polymorphic_oarchive& poa, const T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::ttree_oarchive_impl& poa, const T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::polymorphic_iarchive& pia, T& t)
  {
    pia & BOOST_SERIALIZATION_NVP(t);
  }
  template <typename T>
  void inst (boost::archive::xml_iarchive& pia, T& t)
  {
    pia & BOOST_SERIALIZATION_NVP(t);
  }
}

#define I3_SERIALIZABLE(T)						\
  template void ::detail::inst<T>(boost::archive::binary_oarchive&, const T&); \
  BOOST_SHARED_POINTER_EXPORT(T);					

#if 0
  template void ::detail::inst<T>(boost::archive::ttree_oarchive_impl&, const T&); \
  template void ::detail::inst<T>(boost::archive::polymorphic_oarchive&, const T&); \
  template void ::detail::inst<T>(boost::archive::xml_iarchive&, T&); \
  template void ::detail::inst<T>(boost::archive::xml_oarchive&, const T&); \
  template void ::detail::inst<T>(boost::archive::binary_iarchive&, T&); \
  template void ::detail::inst<T>(boost::archive::polymorphic_iarchive&, T&); \

#endif

#endif //BOOSTHEADERS_H_INCLUDED
