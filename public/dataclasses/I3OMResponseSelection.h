/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMResponseSelection.h,v 1.4.2.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3OMResponseSelection.h
 * @version $Revision: 1.4.2.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author deyoung
 */

#ifndef I3OMRESPONSESELECTION_H_INCLUDED
#define I3OMRESPONSESELECTION_H_INCLUDED

#include "I3OMResponse.h"
#include "OMKey.h"

using namespace std;

/**
 * This is the class that users will inherit from when they want to make a 
 * new selection
 */
class I3OMResponseSelection : public TObject {

public:
  
  I3OMResponseSelection() {};
  
  virtual ~I3OMResponseSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  By default, returns true for all OMResponses.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    return kTRUE;
  };

  // This confuses the dictionary generation, iff the function is virtual.
//   virtual const PtrPolicy<I3OMResponseSelection>::ThePolicy GetCopy() {
//     PtrPolicy<I3OMResponseSelection>::ThePolicy 
//       theCopy(new I3OMResponseSelection(*this));
//     return theCopy;
//   };

  // Pure virtual doesn't work either.
  //  virtual const PtrPolicy<I3OMResponseSelection>::ThePolicy GetCopy() = 0;

//  But this is perfectly OK; it's the pointer to this class that is
//  confusing the dictionary generator.
//   virtual const I3OMResponsePtr GetCopy() {
//     I3OMResponsePtr theCopy(new I3OMResponse);
//     return theCopy;
//   };

private:

  /**
   * Nothing to do for assignment, since the selection has no state
   */
  const I3OMResponseSelection& operator=(const I3OMResponseSelection& rhs) { 
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3OMResponseSelection(const I3OMResponseSelection& rhs) { *this = rhs; } 
  
  ClassDef(I3OMResponseSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3OMResponseSelection>::ThePolicy I3OMResponseSelectionPtr;

#endif
