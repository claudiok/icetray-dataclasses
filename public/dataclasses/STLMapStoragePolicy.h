/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMapStoragePolicy.h,v 1.5 2004/02/24 01:51:35 pretz Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/24 01:51:35 $
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
  typedef typename map_type::const_iterator const_iterator;
  typedef typename map_type::size_type size_type;

 private:

  map_type map_;

 public:
  STLMapStoragePolicy& operator=(const STLMapStoragePolicy &rhs) {
    if (this == &rhs) return *this;
    map_ = rhs.map_;
    return *this;
  }

 public:

  // these operations all mirror standard STL map operations

  ElementType& operator[](const KeyType& key) { return map_[key]; }
  //  const ElementType& operator[](const KeyType& key) const { return map_[key]; }
  iterator begin() { return map_.begin(); }
  const_iterator begin() const { return map_.begin(); }
  iterator end() { return map_.end(); }
  const_iterator end() const { return map_.end(); }

  bool empty() const { return map_.empty(); }
  void clear() { map_.clear(); }
  size_type size() const { return map_.size(); }
  size_type max_size() const { return map_.max_size(); }

  size_type erase(const KeyType &key) { return map_.erase(key); }
  iterator find (const KeyType& key) { return map_.find(key); }
};

#endif
