/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLVectorPolicy.h,v 1.5 2004/02/18 21:39:46 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/18 21:39:46 $
    @author Troy Straszheim

*/
#ifndef STLVECTOR_POLICY_INCLUDED
#define STLVECTOR_POLICY_INCLUDED

#include <vector>
using namespace std;

template <class ElementType>
class StoragePolicy {

 public:

  typedef vector<ElementType>                           vector_type;
  typedef typename vector_type::iterator                iterator;
  typedef typename vector_type::const_iterator          const_iterator;
  typedef typename vector_type::reverse_iterator        reverse_iterator;
  typedef ElementType& 					reference;
  typedef const ElementType& 				const_reference;

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


  iterator begin() { return vector_.begin(); }
  iterator end() { return vector_.end(); }
  
  reference front() { return vector_.front(); }
  const_reference front() const { return vector_.front(); }

  reference back() { return vector_.back(); }
  const_reference back() const { return vector_.back(); }

  //rootcint meckert about friend function somethingorother
  //  bool empty() const { return vector_.empty() }

};

#endif
