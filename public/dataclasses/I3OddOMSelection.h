/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OddOMSelection.h,v 1.4 2004/12/20 20:05:58 deyoung Exp $
 *
 * @file I3OddOMSelection.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/12/20 20:05:58 $
 * @author deyoung
 */

#ifndef I3ODDOMSELECTION_H_INCLUDED
#define I3ODDOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3OddOMSelection : public I3OMResponseSelection {

public:
  
  I3OddOMSelection() {};
  
  virtual ~I3OddOMSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM's position on its
   * string is an odd number, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    if (element.first.GetOM() % 2) {
      return kTRUE;
    }
    return kFALSE;
  };

  virtual const I3OMResponseSelectionPtr GetCopy() {
    I3OMResponseSelectionPtr theCopy(new I3OddOMSelection(*this));
    return theCopy;
  };

private:

  /**
   * Nothing to do for assignment operator since the selection has no state
   */
  const I3OddOMSelection& operator=(const I3OddOMSelection& rhs) { 
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3OddOMSelection(const I3OddOMSelection& rhs) { *this = rhs; } 
  
  ClassDef(I3OddOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3OddOMSelection>::ThePolicy I3OddOMSelectionPtr;

#endif
