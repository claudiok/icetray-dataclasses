/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: STLVectorPolicy.h,v 1.2 2004/02/17 15:48:13 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/17 15:48:13 $
    @author Troy Straszheim

*/
#ifndef STLVECTOR_POLICY_INCLUDED
#define STLVECTOR_POLICY_INCLUDED

#include <vector>
using namespace std;

template <class ElementType>
class STLVectorPolicy {

 public:

  typedef vector<ElementType>                           vector_type;
  typedef typename vector_type::iterator                iterator;
  typedef typename vector_type::const_iterator          const_iterator;
  typedef typename vector_type::reverse_iterator        reverse_iterator;
  typedef ElementType& 					reference;
  typedef const ElementType& 				const_reference;

  void push_back(const ElementType &e) {
    vector_.push_back(e);
  }

  reference operator[](size_t n) { return vector_[n]; }

  const_reference operator[](size_t n) const { return vector_[n]; }

  size_t size() const { return vector_.size(); }
  void resize(size_t newsize_) { vector_.resize(newsize_); }
  iterator begin() { return vector_.begin(); }
  iterator end() { return vector_.end(); }
  
  //
 protected:

  vector_type vector_;

};

#endif
