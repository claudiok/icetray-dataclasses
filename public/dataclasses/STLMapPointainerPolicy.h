#ifndef STLMAPPOINTAINERPOLICY_H
#define STLMAPPOINTAINERPOLICY_H

#include "STLMapStoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: STLMapPointainerPolicy.h,v 1.4 2004/03/16 18:20:08 pretz Exp $
 *
 * just like an STLMapPolicy but contains the added functionality that
 * it deletes all the members when it goes out of scope.
 *
 * @version $$
 * @date $Id: STLMapPointainerPolicy.h,v 1.4 2004/03/16 18:20:08 pretz Exp $
 * @author pretz
 *
 * @todo work out whether or not can implement this by just inheriting from
 * STLMapStoragePolicy
 * @todo I have examples of templated member functions working in ROOT, but
 * this isn't working in the interpreter.  Fix that.
 */

template <class ElementType>
class STLMapPointainerPolicy {
 public:
  /**
   * destructor.  Deletes all the pointed to objects.
   */
  virtual ~STLMapPointainerPolicy(){
    iterator iter;
    for(iter = begin() ; iter!=end() ; iter++){
      delete (iter->second);
      iter->second = 0;
    }
  }

  typedef string KeyType;
  typedef map<KeyType,ElementType> map_type;
  typedef typename map_type::iterator iterator;
  typedef typename map_type::const_iterator const_iterator;
  typedef typename map_type::size_type size_type;

 private:

  map_type map_;

 public:

  STLMapPointainerPolicy& operator=(const STLMapPointainerPolicy &rhs) {
    if (this == &rhs) return *this;
    map_ = rhs.map_;
    return *this;
  }

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

  template<class GottenType>
    GottenType Get(const string& name){
    if(find(name)==end())
      return (GottenType)0;
    return dynamic_cast<GottenType>(operator[](name));
  }
};

#endif
