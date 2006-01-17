/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file STLVectorStoragePolicy.h
    @version $Revision: 1.11 $
    @date $Date$
    @author Troy Straszheim
*/
#ifndef STLVECTOR_POLICY_INCLUDED
#define STLVECTOR_POLICY_INCLUDED

#include <vector>
using namespace std;

/**
 * @brief A template container akin to a STL vector but with a slightly 
 * restricted interface
 *
 * Note that the documentation text here comes from the gnu libstdc++3
 * documentaiton at http://gcc.gnu.org/onlinedocs/libstdc++/latest-doxygen/
 *
 */
template <class ElementType>
class STLVectorStoragePolicy  {

 public:

  /**
   * a type for the stl vector that this class wraps
   */
  typedef vector<ElementType>                           vector_type;
	 
	/**
	 * the vector value type
	 */
	typedef typename vector_type::value_type 								value_type;

  /**
   * an iterator type
   */
  typedef typename vector_type::iterator                iterator;

  /**
   * a constant iterator type.  Like a 'const XXX*'
   */
  typedef typename vector_type::const_iterator          const_iterator;

  /**
   * an iterator that goes backwards across the vector
   */
  typedef typename vector_type::reverse_iterator        reverse_iterator;

  /**
   * a reference type that is contained by this class
   */
  typedef ElementType& 					reference;

  /**
   * a constant reference type
   */
  typedef const ElementType& 				const_reference;

  /**
   * A pointer for the vector
   */
#ifndef __CINT__
  typedef typename vector_type::pointer                 pointer;
#endif

 private:
  vector_type vector_; 

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("vector", vector_);
  }


 public:

  /**
   * the same as push_back()
   */
  void Add(const ElementType& e) { vector_.push_back(e);}

  /**
   * Add data to the end of the vector.
   * @param e Data to be added.
   */
  void push_back(const ElementType &e) { vector_.push_back(e); }

  /**
   * Removes last element.
   */
  void pop_back() { vector_.pop_back(); }

  /**
   * Erases all the elements. Note that this function only erases the 
   * elements, and that if the elements themselves are pointers, the 
   * pointed-to memory is not touched in any way. Managing the pointer 
   * is the user's responsibilty.
   */
  void clear() { vector_.clear(); }

  /**
   * Subscript access to the data contained in the vector.
   * @param n The index of the element for which data should be accessed.
   * @return Read/write reference to data.
   */
  reference operator[](size_t n) { return vector_[n]; }

  /**
   * Subscript access to the data contained in the vector.
   * @param n The index of the element for which data should be accessed.
   * @return Read-only (constant) reference to data.
   */
  const_reference operator[](size_t n) const { return vector_[n]; }

  /**
   * the same as operator[]()
   */
  reference Get(size_t n) {return vector_[n];}

  /**
   * the same as operator[]()
   */
  const_reference Get(size_t n) const {return vector_[n];}

  /**
   * Returns the number of elements in the vector.
   */
  size_t size() const { return vector_.size(); }

  /**
   * Resizes the vector to the specified number of elements.
   */
  void resize(size_t newsize_) { vector_.resize(newsize_); }

  /**
   * Attempt to preallocate enough memory for specified number of elements.
   * @param n Number of elements required.
   */
  void reserve (size_t n) { vector_.reserve(n); }


  // these need to be template member functions with defaults to
  // ElementType (for a "regular" element)

  /**
   * Returns a read/write iterator that points to the first element 
   * in the vector. Iteration is done in ordinary element order.
   */
  iterator begin() { return vector_.begin(); }

  /**
   * Returns a read-only (constant) iterator that points to the first 
   * element in the vector. Iteration is done in ordinary element order.
   */
  const_iterator begin() const {return vector_.begin();}

  /**
   * Returns a read/write iterator that points one past the last element 
   * in the vector. Iteration is done in ordinary element order.
   */
  iterator end() { return vector_.end(); }

  /**
   * Returns a read-only (constant) iterator that points one past the 
   * last element in the vector. Iteration is done in ordinary element order.
   */
  const_iterator end() const {return vector_.end();}
  
  /**
   * Returns a read/write reference to the data at the first element of 
   * the vector.
   */
  reference front() { return vector_.front(); }

  /**
   * Returns a read-only (constant) reference to the data at the first 
   * element of the vector.
   */
  const_reference front() const { return vector_.front(); }

  /**
   * Returns a read/write reference to the data at the last element of the 
   * vector.
   */
  reference back() { return vector_.back(); }

  /**
   * Returns a read-only (constant) reference to the data at the last 
   * element of the vector.
   */
  const_reference back() const { return vector_.back(); }

  //rootcint meckert about friend function somethingorother
  //  bool empty() const { return vector_.empty() }

  // dont do this it is messy
  virtual ~STLVectorStoragePolicy() { }

};

#endif
