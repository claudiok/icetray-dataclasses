/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: TClonesPolicy.h,v 1.5 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo   need to get name of element class, see "new TClonesArray"
*/

// ONLY ONE POLICY MUST BE INCLUDED
#ifndef TCLONES_POLICY_INCLUDED
#define TCLONES_POLICY_INCLUDED

#include <TClonesArray.h>
#include <TClass.h>

template <class ElementType>
class TClonesPolicy {

 protected:

  TClonesArray theclones;

 public:

  //  typedef vector<ElementType>                           vector_type;
  //  typedef typename vector_type::iterator                iterator;
  //  typedef typename vector_type::const_iterator          const_iterator;
  //  typedef typename vector_type::reverse_iterator        reverse_iterator;
  typedef ElementType& 					reference;
  typedef const ElementType& 				const_reference;

  //  void push_back(const ElementType &e) {
  //    vector_.push_back(e);
  //  }

  reference operator[](size_t n) { return *(ElementType*)(theclones)[n]; }

  const_reference operator[](size_t n) const { return *(ElementType*)(theclones)[n]; }

  size_t size() const { return theclones.GetEntriesFast(); }
  void resize(size_t newsize_) { theclones.Expand(newsize_); }
  //  iterator begin() { return vector_.begin(); }
  //  iterator end() { return vector_.end(); }
 
  // danger danger, need to get class name better
  TClonesPolicy() : theclones(ElementType::Class()->GetName(),0){ }
  ~TClonesPolicy() { }

};

#endif
