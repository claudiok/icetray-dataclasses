/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMapStoragePolicy.h,v 1.2 2004/02/23 17:11:10 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/23 17:11:10 $
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
  const ElementType& operator[](const KeyType& key) const { return map_[key]; }
  iterator find (const KeyType& key) { return map_.find(key); }

};

#endif
