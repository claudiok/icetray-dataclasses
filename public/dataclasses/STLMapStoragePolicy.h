/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMapStoragePolicy.h,v 1.1 2004/02/23 02:13:50 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/23 02:13:50 $
    @author Troy Straszheim

*/
#ifndef STLMAPPOLICY_H
#define STLMAPPOLICY_H

#include <string>
#include <map>

using namespace std;

template <class ElementType>
class STLMapStoragePolicy {

 public:

  typedef string KeyType;
  typedef map<KeyType,ElementType> map_type;
  typedef typename map_type::iterator iterator;

 private:

  map_type map_;

 public:

  ElementType& operator[](const KeyType& key) { return map_[key]; }
  iterator find (const KeyType& key) { return map_.find(key); }
};

#endif
