/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLHashStoragePolicy.h,v 1.1 2004/02/20 16:54:14 troy Exp $

    @version $Revision: 1.1 $
    @date $Date: 2004/02/20 16:54:14 $
    @author Troy Straszheim

*/
#ifndef STLHASHPOLICY_H
#define STLHASHPOLICY_H

#include <string>
#include <map> //this needs to be changed to hash_map

using namespace std;

template <class ElementType>
class STLHashStoragePolicy {

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
