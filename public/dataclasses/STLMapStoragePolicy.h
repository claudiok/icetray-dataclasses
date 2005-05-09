/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file STLMapStoragePolicy.h
    @version $Revision: 1.21 $
    @date $Date$
    @author Troy Straszheim

*/
#ifndef STLMAPPOLICY_H
#define STLMAPPOLICY_H

#include <string>
#include <sstream>
#include <map>
#include "services/I3Logging.h"

using namespace std;


/**
 * @brief A template which provides a restricted interface to the
 * STL map class.  
 *
 * The text for the documentation of stl methods is taken from the gnu 
 * libstdc++3 documentation
 * found here: http://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/
 *
 * @todo fuller documentation needed
 */
template <class KeyType, class ElementType>
class STLMapStoragePolicy 
{

 public:

 //  typedef string KeyType;
  /**
   * the stl map corresponding to this one
   */
  typedef map<KeyType,ElementType> map_type;

  /**
   * the map iterator
   */
  typedef typename map_type::iterator iterator;

  /**
   * A constant iterator.  Like a constant pointer.
   */
  typedef typename map_type::const_iterator const_iterator;

  /**
   * A type for the size of the map.
   */
  typedef typename map_type::size_type size_type;

  /**
   * A pointer for the map.
   */
#ifndef __CINT__ 
  typedef typename map_type::pointer pointer;
#endif

 private:

  map_type map_;

 public:
  /** 
   * assignment operator
   */
  STLMapStoragePolicy& operator=(const STLMapStoragePolicy &rhs) {
    if (this == &rhs) return *this;
    map_ = rhs.map_;
    return *this;
  }

  // these operations all mirror standard STL map operations

  /**
   * Subscript ( [] ) access to map data.
   * @param key The key for which data should be retrieved.
   * @return A reference to the data of the (key,data) pair.
   */ 
  ElementType& operator[](const KeyType& key) { return map_[key]; }

  /**
   * Similar to operator[] except that it checks to see
   * whether the key exists before retrieving it.
   * If it does not find the key you're looking for
   * it prints an error message and a list of possible keys.
   */
  ElementType& Get(const KeyType& key) {
    if(!count(key)){
      ostringstream debugStream;
      if(!IsEmpty()){
	debugStream<<endl<<"***WARNING: Key \'"<<key<<"\' not found."<<endl;
	debugStream<<"Here's a list of possible keys:"<<endl;
	for(typename map_type::iterator iter = begin(); iter != end(); iter++){
	  debugStream<<iter->first<<" ";
	}
      }else{
	debugStream<<"WARNING: You're trying to look for keys in an empty map."<<endl;
      }
      log_debug("%s",debugStream.str().c_str());
    }
    return map_[key];
  }

  /**
   * puts some data in the map with a particular key.  
   * @param element the data to be copied into the map
   * @param key the key used to retrieve the data
   * @return true if the key isn't already used and the put succeeds,
   * false otherwise.
   */
  bool Add(const ElementType& element, const KeyType& key)
    {
      iterator iter = find(key);
      ostringstream debugStream;
      if(iter != end()){
	debugStream<<"WARNING: Key \'"<<key<<"\' already used."<<endl;
	log_debug("%s",debugStream.str().c_str());
	return false;
      }else{
	this->operator[](key) = element;
      }
      return true;
    }

  //  const ElementType& operator[](const KeyType& key) const { return map_[key]; }

  /**
   * the same as begin()
   */
  iterator Begin() { return map_.begin();}

  /**
   * Returns a read/write iterator that points to the first pair in the map. 
   * Iteration is done in ascending order according to the keys.
   */
  iterator begin() { return map_.begin(); }

  /**
   * the same as begin() const
   */
  const_iterator Begin() const { return map_.begin();}

  /**
   * Returns a read-only (constant) iterator that points to the first pair 
   * in the map. Iteration is done in ascending order according to the keys
   */
  const_iterator begin() const { return map_.begin(); }

  /**
   * the same as end
   */
  iterator End() {return map_.end();}

  /**
   * Returns a read/write iterator that points one past the last pair in the 
   * map. Iteration is done in ascending order according to the keys.
   */
  iterator end() { return map_.end(); }

  /**
   * the same as end() const
   */
  const_iterator End() const { return map_.end();}

  /**
   * Returns a read-only (constant) iterator that points one past the last 
   * pair in the map. Iteration is done in ascending order according to the 
   * keys.
   */
  const_iterator end() const { return map_.end(); }

  /**
   * same as empty()
   */
  bool IsEmpty() const {return map_.empty();}

  /**
   * Returns true if the map is empty. (Thus begin() would equal end().)
   */
  bool empty() const { return map_.empty(); }
  
  /**
   * the same as clear()
   */
  void Clear() { map_.clear();}
  
  /**
   * Erases all elements in a map. Note that this function only erases the 
   * elements, and that if the elements themselves are pointers, the 
   * pointed-to memory is not touched in any way. Managing the pointer is 
   * the user's responsibilty.
   */
  void clear() { map_.clear(); }

  /**
   * same as size()
   */
  size_type GetSize() const {return map_.size();}

  /**
   * Returns the size of the map.
   */
  size_type size() const { return map_.size(); }

  /**
   * same as max_size()
   */
  size_type GetMaxSize() const {return map_.max_size();}

  /**
   * Returns the maximum size of the map.
   */
  size_type max_size() const { return map_.max_size(); }

  /**
   * same as erase()
   */
  size_type Erase(const KeyType& key) { return map_.erase(key);}

  /**
   * Erases elements according to the provided key.
   * @param key Key of element to be erased.
   * @return The number of elements erased.
   */
  size_type erase(const KeyType &key) { return map_.erase(key); }

  /**
   * same as find()
   */

  iterator Find(const KeyType& key) { return map_.find(key);}
  const_iterator Find(const KeyType& key) const { return map_.find(key);}

  /**
   * Tries to locate an element in a map.
   * @param key Key of (key, value) pair to be located.
   * @return Iterator pointing to sought-after element, or end() if not found.
   */
  iterator find (const KeyType& key) { return map_.find(key); }
  const_iterator find (const KeyType& key) const { return map_.find(key); }

  size_type count(const KeyType& key){ return map_.count(key); }

 private: 

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("map", map_);
  }

};


#endif
