/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMSlr.h,v 1.2 2004/10/24 21:05:01 troy Exp $
 *
 * @file I3OMSlr.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/10/24 21:05:01 $
 * @author deyoung
 */

#warning I3OMSlr problems, fixme
#if 0
#ifndef I3OMSLR_H_INCLUDED
#define I3OMSLR_H_INCLUDED

#include "services/I3Logging.h"
#include "services/I3ConfigAccess.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3OMResponseMap.h"

using namespace std;

typedef I3OMResponseMap::iterator I3OMItr;

/**
 * @brief 
 */
class I3OMSlr : public TObject, public I3OMItr {
  
public:

  I3OMSlr() {};
  virtual ~I3OMSlr() {};
  
  /// this is where the logic itself lives.  We take an iterator that
  /// points to the current item and decide whether it passes the
  /// selection criterion.  Nontrivial logic is added in derived
  /// classes (see I3OMSlrList for an example).
  /// @todo Should also implement versions for pointers, refs to I3OMResponse
  virtual Bool_t IsSelected(const I3OMItr current_omr) {
    return kTRUE;
  };
  
  I3OMSlr& IncrementUntil(I3OMItr);
  void SetLimit(I3OMItr);
  
  I3OMSlr& operator++();   // Prefix increment operator
  I3OMSlr operator++(int); // Postfix increment operator
  
  I3OMSlr& operator=(I3OMItr);
  
  // Need a mechanism to return a pointer to a copy of the actual
  // object, whatever it may be
  virtual const PtrPolicy<I3OMSlr>::ThePolicy GetCopy();

private:
  
  // Need to keep a record of the end of my container, so I don't
  // iterate past it if the last element fails IsSelected().
  I3OMItr fTheEnd;
  
  // Root Macro so that this class can be used from the interpreter
  ClassDef(I3OMSlr,1);
}; 

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3OMSlr>::ThePolicy I3OMSlrPtr;

#endif //I3OMSLR_H_INCLUDED
#endif
