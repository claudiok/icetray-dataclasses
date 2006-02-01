/**
    copyright  (C) 2006
    the icecube collaboration
    @version $Id: StoragePolicy.h 14347 2006-01-15 15:15:08Z pretz $
    @date    $Date: 2006-01-15 10:15:08 -0500 (Sun, 15 Jan 2006) $
*/

#ifndef DATACLASSES_I3VECTOR_H_INCLUDED
#define DATACLASSES_I3VECTOR_H_INCLUDED

#include "TObject.h"
#include <vector>
#include "dataclasses/StoragePolicy.h"

template <typename T>
struct I3Vector : public TObject, public std::vector<T>
{ 
  template <class Archive>
  void serialize(Archive & ar, unsigned version)
  {
    ar & make_nvp("vector", base_object< std::vector<T> >(*this));
    ar & make_nvp("TObject", base_object< TObject >(*this));
  }
};

#endif // I3VECTOR_H_INCLUDED

