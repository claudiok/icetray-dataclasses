/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: STLVecPointainerPolicy.h,v 1.4 2004/04/27 13:35:23 pretz Exp $
 *
 * @file STLVecPointainerPolicy.h
 * @version $Version:$
 * @date $Id: STLVecPointainerPolicy.h,v 1.4 2004/04/27 13:35:23 pretz Exp $
 * @author pretz
 */

#ifndef STLVECPOINTAINERPOLICY_H
#define STLVECPOINTAINERPOLICY_H

#include "STLVectorStoragePolicy.h"

/**
 * @brief Just like an STLVecPointainerPolicy  which contains the added 
 * functionality that  it deletes all the members when it goes out of scope.
 * @todo can this be implemented as just inheriting from STLVectorStoragePolicy
 */

template <class ElementType>
class STLVecPointainerPolicy {
 public:
  /**
   * destructor.  Deletes all the pointed to objects.
   */
  virtual ~STLVecPointainerPolicy(){
    iterator iter;
    for(iter = begin() ; iter!=end() ; iter++){
      delete *iter;
      *iter = 0;
    }
  }
  typedef vector<ElementType>                           vector_type;
  typedef typename vector_type::iterator                iterator;
  typedef typename vector_type::const_iterator          const_iterator;
  typedef typename vector_type::reverse_iterator        reverse_iterator;
  typedef ElementType& 					reference;
  typedef const ElementType& 				const_reference;

  template <class Type> class type_iterator
    {
    public:

      // tds
      const vector_type* thevec; //!
      typename vector_type::iterator iter;


      type_iterator() { 
	thevec=NULL; 
      }
      type_iterator(const type_iterator& rhs) { *this = rhs; }
      ~type_iterator() {;}

      type_iterator& operator=(const type_iterator& rhs) {
	thevec = rhs.thevec;
	iter = rhs.iter;
	return *this;
      }

      // here we need type and bounds checking
      type_iterator& operator++(int i) 
	{
	  iter++; 
	  while (iter != thevec->end())
	    {
	      Type t = dynamic_cast<Type>(*iter);
	      if (t!=NULL) { return *this; }
	      iter++;
	    }
	  return *this;
	}
      
      Type operator->() { return dynamic_cast<Type>(*iter); }
      Type operator*() { return dynamic_cast<Type>(*iter); }
      bool operator!=(const type_iterator<Type> &otheriter) {
	return (iter != otheriter.iter);
      }
    };


 private:
  vector_type vector_;

 public:

  void push_back(const ElementType &e) { vector_.push_back(e); }
  void pop_back() { vector_.pop_back(); }
  void clear() { vector_.clear(); }

  reference operator[](size_t n) { return vector_[n]; }
  const_reference operator[](size_t n) const { return vector_[n]; }

  size_t size() const { return vector_.size(); }
  void resize(size_t newsize_) { vector_.resize(newsize_); }
  void reserve (size_t n) { vector_.reserve(n); }


  // these need to be template member functions with defaults to
  // ElementType (for a "regular" element)
  iterator begin() { return vector_.begin(); }
  const_iterator begin() const {return vector_.begin();}
  iterator end() { return vector_.end(); }
  const_iterator end() const {return vector_.end();}
  
  template <class Type> type_iterator<Type> begin() 
    { 
      type_iterator<Type> titer;
      titer.thevec = &vector_;
      titer.iter = vector_.begin();
      if(dynamic_cast<Type>(*(titer.iter)) == NULL)
	titer++;
      return titer;
    }

  template <class Type> type_iterator<Type> end() 
    { 
      type_iterator<Type> titer;
      titer.iter = vector_.end();
      titer.thevec = &vector_;
      return titer;
    }

  reference front() { return vector_.front(); }
  const_reference front() const { return vector_.front(); }

  reference back() { return vector_.back(); }
  const_reference back() const { return vector_.back(); }

  //rootcint meckert about friend function somethingorother
  //  bool empty() const { return vector_.empty() }

  // dont do this it is messy
  //  virtual ~StoragePolicy() {;}

  //  ClassDef(StoragePolicy,1);

};



#endif
