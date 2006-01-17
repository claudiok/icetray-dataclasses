/**
   copyright  (C) 2004
   the icecube collaboration
   $Id$

   @file STLMultiMapStoragePolicy.h
   @version $Revision: 1.5 $
   @date $Date$
   @author Ralf Ehrlich

*/
#ifndef STLMULTIMAPPOLICY_H
#define STLMULTIMAPPOLICY_H

#include <string>
#include <map>

using namespace std;

/**
 * @brief A template which provides a restricted interface to the
 * STL multimap class.
 *
 * The text for the documentation of stl methods is taken from the gnu
 * libstdc++3 documentation
 * found here: http://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/
 *
 * @todo fuller documentation needed
 */
template <class KeyType, class ElementType>
class STLMultiMapStoragePolicy 
{
public:

  //  typedef string KeyType;
  /**
   * a type for the stl multimap that this one wraps
   */
  typedef multimap<KeyType,ElementType> map_type;

  /**
   * the multimap key type
   */
  typedef typename map_type::key_type key_type;
	 
  /**
   * the multimap mapped type
   */
  typedef typename map_type::mapped_type mapped_type;
	 
  /**
   * the multimap value type
   */
  typedef typename map_type::value_type value_type;

  /**
   * an iterator type
   */
  typedef typename map_type::iterator iterator;

  /**
   * a constant iterator type
   */
  typedef typename map_type::const_iterator const_iterator;

  /**
   * a size type for the map
   */
  typedef typename map_type::size_type size_type;

#ifndef __CINT__
  /**
   * A pointer for the map.
   */
  typedef typename map_type::pointer pointer;

  /**
   * A reference for the map.
   */
  typedef typename map_type::reference reference;

  /**
   * A constant reference for the map.
   */
  typedef typename map_type::const_reference const_reference;
#endif


private:

  map_type map_; 

public:

  /**
   * assignment operator
   */
  STLMultiMapStoragePolicy& operator=(const STLMultiMapStoragePolicy &rhs) {
    if (this == &rhs) return *this;
    map_ = rhs.map_;
    return *this;
  }

  // these operations all mirror standard STL map operations

  /**
   * puts some data in the map with a particular key.
   * @param key the key used to retrieve the data
   * @param element the data to be copied into the map
   */
  void insert(const KeyType& key, const ElementType& element) 
  {
    map_.insert(pair<KeyType, ElementType>(key, element));
  }

  /**
   * same as Insert
   */
  void Add(const KeyType& key, const ElementType& element) {map_.insert(pair<KeyType, ElementType>(key, element));}
  
  /**
   * Returns a read/write iterator that points to the first pair in the map.
   * Iteration is done in ascending order according to the keys.
   */
  iterator begin() { return map_.begin(); }

  /**
   * Returns a read-only (constant) iterator that points to the first pair
   * in the map. Iteration is done in ascending order according to the keys
   */
  const_iterator begin() const { return map_.begin(); }

  /**
   * Returns a read/write iterator that points one past the last pair in the
   * map. Iteration is done in ascending order according to the keys.
   */
  iterator end() { return map_.end(); }

  /**
   * Returns a read-only (constant) iterator that points one past the last
   * pair in the map. Iteration is done in ascending order according to the
   * keys.
   */
  const_iterator end() const { return map_.end(); }

  /**
   * Returns a read/write iterator that points to the first pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys.
   */
  iterator lower_bound(const KeyType& key) { return map_.lower_bound(key);}

  /**
   * Returns a read-only (constant) iterator that points to the first pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys
   */
  const_iterator lower_bound(const KeyType& key) const { return map_.lower_bound(key);}

  /**
   * Returns a read/write iterator that points one past the last pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys.
   */
  iterator upper_bound(const KeyType& key) { return map_.upper_bound(key);}

  /**
   * Returns a read-only (constant) iterator that points one past the last pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys
   */
  const_iterator upper_bound(const KeyType& key) const { return map_.upper_bound(key);}

  /**
   * Returns true if the map is empty. (Thus begin() would equal end().)
   */
  bool empty() const { return map_.empty(); }

  /**
   * Erases all elements in a map. Note that this function only erases the
   * elements, and that if the elements themselves are pointers, the
   * pointed-to memory is not touched in any way. Managing the pointer is
   * the user's responsibilty.
   */
  void clear() { map_.clear(); }

  /**
   * Returns the size of the map.
   */
  size_type size() const { return map_.size(); }

  /**
   * Returns the maximum size of the map.
   */
  size_type max_size() const { return map_.max_size(); }

  /**
   * Erases elements according to the provided key.
   * @param key Key of element to be erased.
   * @return The number of elements erased.
   */
  size_type erase(const KeyType &key) { return map_.erase(key); }

  /**
   * Tries to locate an element in a map.
   * @param key Key of (key, value) pair to be located.
   * @return Iterator pointing to sought-after element, or end() if not found.
   */
  iterator find (const KeyType& key) { return map_.find(key); }

  /**
   * same as Count()
   */
  size_type count(const KeyType& key) const {return map_.count(key);}

  virtual ~STLMultiMapStoragePolicy() { }

private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("multimap", map_);
  }

};

#endif
