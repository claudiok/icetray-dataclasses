/**
 *  $Id$
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  Marcel Zoll <marcel.zoll@fysik.su.se>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#include "dataclasses/I3MapOMKeyMask.h"

//partial specialize this for icecube-archival types
template <> template <>
void
I3MapOMKeyMask<class Response>::bitmask::save<boost::archive::xml_oarchive>(boost::archive::xml_oarchive& ar, unsigned version) const
{
  ar & make_nvp("Size", size_);
  ar & make_nvp("Padding", padding_);
  // Generate a convenient ASCII representation of the mask bits
  std::string s(this->size(),'0');
  unsigned i = 0;
  for (std::string::iterator it = s.begin(); it != s.end(); it++, i++)
    if (this->get(i))
      *it = '1';
  ar & make_nvp("Bitmask", s);
};

template <> template <>
void
I3MapOMKeyMask<class Response>::bitmask::load<boost::archive::xml_iarchive>(boost::archive::xml_iarchive& ar, unsigned version)
{
  ar & make_nvp("Size", size_);
  ar & make_nvp("Padding", padding_);
  std::string s;
  ar & make_nvp("Bitmask", s);
  mask_ = (mask_t*)malloc(size_*sizeof(mask_t));
  memset(mask_, 0, size_*sizeof(mask_t));
  // Parse the ASCII representation of the mask bits, treating any non-'0' character as true
  unsigned i = 0;
  for (std::string::iterator it = s.begin(); it != s.end(); it++, i++)
    if (*it != '0')
      this->set(i, true);
}

I3_SPLIT_SERIALIZABLE(I3MapOMKeyMask<I3RecoPulse>);
