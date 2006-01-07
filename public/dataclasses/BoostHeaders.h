#ifndef BOOSTHEADERS_H
#define BOOSTHEADERS_H

#include "dataclasses/ttree_oarchive.h"

#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/is_abstract.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/tracking.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/split_member.hpp>

using boost::serialization::make_nvp;
using boost::serialization::base_object;

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
  void inst (boost::archive::polymorphic_oarchive& poa, const T& t)
  {
    poa & BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void 
  inst (ttree_oarchive& poa, const T& t)
  {
    poa << BOOST_SERIALIZATION_NVP(t);
  }

  template <typename T>
  void inst (boost::archive::polymorphic_iarchive& pia, T& t)
  {
    pia & BOOST_SERIALIZATION_NVP(t);
  }
}

#if BOOST_VERSION > 103200
#define I3_BOOST_EXPORT_MACROS(T) \
  BOOST_CLASS_TRACKING(T, boost::serialization::track_always); \
  BOOST_CLASS_EXPORT(T);

#else
#define I3_BOOST_EXPORT_MACROS(T) \
  BOOST_SHARED_POINTER_EXPORT(T);
#endif

#define I3_SERIALIZABLE(T)						\
  I3_BOOST_EXPORT_MACROS(T)						\
  template void ::detail::inst<T>(boost::archive::polymorphic_oarchive&, const T&); \
  template void ::detail::inst<T>(boost::archive::polymorphic_iarchive&, T&); \
  template void ::detail::inst<T>(ttree_oarchive&, const T&);


  //  BOOST_SHARED_POINTER_EXPORT(T);					

#endif
