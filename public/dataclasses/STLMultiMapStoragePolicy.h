/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMultiMapStoragePolicy.h,v 1.1 2004/07/26 23:44:09 ehrlich Exp $

    @file STLMultiMapStoragePolicy.h
    @version $Revision: 1.1 $
    @date $Date: 2004/07/26 23:44:09 $
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
class STLMultiMapStoragePolicy {

 public:

 //  typedef string KeyType;
  typedef multimap<KeyType,ElementType> map_type;
  typedef typename map_type::iterator iterator;
  typedef typename map_type::const_iterator const_iterator;
  typedef typename map_type::size_type size_type;

 private:

  map_type map_;

 public:

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
  void Insert(const KeyType& key, const ElementType& element) {map_.insert(pair<KeyType, ElementType>(key, element));}

  /**
   * same as Insert
   */
  void insert(const KeyType& key, const ElementType& element) {map_.insert(pair<KeyType, ElementType>(key, element));}

  /**
   * same as Insert
   */
  void Add(const KeyType& key, const ElementType& element) {map_.insert(pair<KeyType, ElementType>(key, element));}

  /**
   * Returns a read/write iterator that points to the first pair in the map.
   * Iteration is done in ascending order according to the keys.
   */
  iterator Begin() { return map_.begin();}

  /**
   * the same as Begin()
   */
  iterator begin() { return map_.begin(); }

  /**
   * Returns a read-only (constant) iterator that points to the first pair
   * in the map. Iteration is done in ascending order according to the keys
   */
  const_iterator Begin() const { return map_.begin();}

  /**
   * the same as Begin() const
   */
  const_iterator begin() const { return map_.begin(); }

  /**
   * Returns a read/write iterator that points one past the last pair in the
   * map. Iteration is done in ascending order according to the keys.
   */
  iterator End() {return map_.end();}

  /**
   * the same as end
   */
  iterator end() { return map_.end(); }

  /**
   * Returns a read-only (constant) iterator that points one past the last
   * pair in the map. Iteration is done in ascending order according to the
   * keys.
   */
  const_iterator End() const { return map_.end();}

  /**
   * the same as end() const
   */
  const_iterator end() const { return map_.end(); }

  /**
   * Returns a read/write iterator that points to the first pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys.
   */
  iterator Lower_bound(const KeyType& key) { return map_.lower_bound(key);}

  /**
   * the same as Lower_bound(key)
   */
  iterator lower_bound(const KeyType& key) { return map_.lower_bound(key);}

  /**
   * the same as Lower_bound(key)
   */
  iterator GetBeginWithKey(const KeyType& key)   { return map_.lower_bound(key);}

  /**
   * Returns a read-only (constant) iterator that points to the first pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys
   */
  const_iterator Lower_bound(const KeyType& key) const { return map_.lower_bound(key);}

  /**
   * the same as Lower_bound(key) const
   */
  const_iterator lower_bound(const KeyType& key) const { return map_.lower_bound(key);}

  /**
   * the same as Lower_bound(key) const
   */
  const_iterator GetBeginWithKey(const KeyType& key) const { return map_.lower_bound(key);}

  /**
   * Returns a read/write iterator that points one past the last pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys.
   */
  iterator Upper_bound(const KeyType& key) { return map_.upper_bound(key);}

  /**
   * the same as Upper_bound(key)
   */
  iterator upper_bound(const KeyType& key) { return map_.upper_bound(key);}

  /**
   * the same as Upper_bound(key)
   */
  iterator GetEndWithKey(const KeyType& key)   { return map_.upper_bound(key);}

  /**
   * Returns a read-only (constant) iterator that points one past the last pair
   * in the map with the specified key.
   * Iteration is done in ascending order according to the keys
   */
  const_iterator Upper_bound(const KeyType& key) const { return map_.upper_bound(key);}

  /**
   * the same as Upper_bound(key) const
   */
  const_iterator upper_bound(const KeyType& key) const { return map_.upper_bound(key);}

  /**
   * the same as Upper_bound(key) const
   */
  const_iterator GetEndWithKey(const KeyType& key) const { return map_.upper_bound(key);}

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
  /**
   * Tries to locate an element in a map.
   * @param key Key of (key, value) pair to be located.
   * @return Iterator pointing to sought-after element, or end() if not found.
   */
  iterator find (const KeyType& key) { return map_.find(key); }

  /**
   * Counts the number of elements in the a map which have the specified key
   * @param key Key of (key, value) pair to be counted
   * @return The number of elements in a map with the specified key
   */
  size_type Count(const KeyType& key) const {return map_.count(key);}

  /**
   * same as Count()
   */
  size_type count(const KeyType& key) const {return map_.count(key);}

};

#endif
