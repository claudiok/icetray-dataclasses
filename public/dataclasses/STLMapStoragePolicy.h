/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLMapStoragePolicy.h,v 1.16.14.1 2005/02/22 17:48:10 deyoung Exp $

    @file STLMapStoragePolicy.h
    @version $Revision: 1.16.14.1 $
    @date $Date: 2005/02/22 17:48:10 $
    @author Troy Straszheim

*/
#ifndef STLMAPPOLICY_H
#define STLMAPPOLICY_H

#include <string>
#include <map>

using namespace std;

/**
 * @brief A template which provides a restricted interface to the
 * STL map class.  
 *
 * This template class provides the functionality of an STL map.  The
 * regular interface to an STL map is available (most of it, anyway),
 * as well as a more 'physics-y' interface similar to Root container
 * classes.
 *
 * Maps are containers of objects of a particular type, similar to
 * vectors or arrays.  However, these objects (the @em elements of the
 * map) are not stored in a particular order, but rather are indexed
 * by @em keys which identify each object.  In the dataclasses, the
 * keys to
 * a map are usually either strings (names) or @c OMKey 's (the string
 * number, position on string pair that uniquely identifies each OM).
 * Because maps are essentially look-up tables, they are also called
 * @em dictionaries, and the names of (most) map classes in the
 * dataclasses end with the suffix @c Dict to denote this. 
 *
 * Classes which inherit from this class are maps, with a particular
 * @c KeyType and @c ElementType (these are the template parameters
 * for this class).  For example, the 
 * @c I3OMResponseDict is a map of pointers to @c I3OMResponse 's,
 * indexed by @c OMKey 's.  All maps share the same interface,
 * however, which is provided by this class.  The actual inheritance
 * in the derived classes is from the @c MapPolicy, which is presently
 * set to be the @c STLMapStoragePolicy.
 *
 * See @ref stlsyntax and @ref iterators for more information about
 * using vectors. 
 *
 * The text for the documentation of STL methods is taken from the gnu 
 * libstdc++3 documentation
 * found here: http://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/
 *
 */
template <class KeyType, class ElementType>
class STLMapStoragePolicy {

 public:

  /**
   * The particular type of STL map we're dealing with.  For internal use.
   */
  typedef map<KeyType,ElementType> map_type;

  /**
   * An iterator over the map.
   */
  typedef typename map_type::iterator iterator;

  /**
   * A constant iterator.  Like a constant pointer.
   */
  typedef typename map_type::const_iterator const_iterator;

  /**
   * A type for the size of the map.  For internal use.
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
   * The same as operator[] -- provides access to a particular data element.
   */
  ElementType& Get(const KeyType& key) {return map_[key];}

  /**
   * Puts some data in the map with a particular key.  
   * @param element the data to be copied into the map
   * @param key the key used to retrieve the data
   * @return true if the key isn't already used and the put succeeds,
   * false otherwise.
   */
  bool Add(const ElementType& element, const KeyType& key)
    {
      iterator iter = find(key);
      if(iter != end())
	return false;
      else
	this->operator[](key) = element;
      return true;
    }

  //  const ElementType& operator[](const KeyType& key) const { return map_[key]; }

  /**
   * The same as begin()
   */
  iterator Begin() { return map_.begin();}

  /**
   * Returns a read/write iterator that points to the first pair in the map. 
   * Iteration is done in ascending order according to the keys.
   */
  iterator begin() { return map_.begin(); }

  /**
   * The same as the const version of begin()
   */
  const_iterator Begin() const { return map_.begin();}

  /**
   * Returns a read-only (constant) iterator that points to the first pair 
   * in the map. Iteration is done in ascending order according to the
   * keys.  This is the version of begin() that is executed if a
   * const_iterator is requested.
   */
  const_iterator begin() const { return map_.begin(); }

  /**
   * The same as end()
   */
  iterator End() {return map_.end();}

  /**
   * Returns a read/write iterator that points one past the last pair in the 
   * map. Iteration is done in ascending order according to the keys.
   */
  iterator end() { return map_.end(); }

  /**
   * The same as the const version of end()
   */
  const_iterator End() const { return map_.end();}

  /**
   * Returns a read-only (constant) iterator that points one past the last 
   * pair in the map. Iteration is done in ascending order according to the 
   * keys.
   */
  const_iterator end() const { return map_.end(); }

  /**
   * The same as empty()
   */
  bool IsEmpty() const {return map_.empty();}

  /**
   * Returns true if the map is empty.  (Thus begin() would equal end().)
   */
  bool empty() const { return map_.empty(); }
  
  /**
   * The same as clear()
   */
  void Clear() { map_.clear();}
  
  /**
   * Erases all elements in a map. Note that this function only erases the 
   * elements, and that if the elements themselves are pointers, the 
   * pointed-to memory is not touched in any way. Managing the pointer is 
   * the user's responsibilty, but if smart pointers are being used
   * the memory will be automatically deallocated if appropriate.
   */
  void clear() { map_.clear(); }

  /**
   * The same as size()
   */
  size_type GetSize() const {return map_.size();}

  /**
   * Returns the size of the map.
   */
  size_type size() const { return map_.size(); }

  /**
   * The same as max_size()
   */
  size_type GetMaxSize() const {return map_.max_size();}

  /**
   * Returns the maximum size of the map.
   */
  size_type max_size() const { return map_.max_size(); }

  /**
   * The same as erase()
   */
  size_type Erase(const KeyType& key) { return map_.erase(key);}

  /**
   * Erases elements according to the provided key.
   * @param key Key of element to be erased.
   * @return The number of elements erased.
   */
  size_type erase(const KeyType &key) { return map_.erase(key); }

  /**
   * The same as find()
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
};

#endif
