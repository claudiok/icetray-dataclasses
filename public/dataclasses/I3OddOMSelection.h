/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OddOMSelection.h,v 1.3 2004/11/23 20:57:25 deyoung Exp $
 *
 * @file I3OddOMSelection.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/11/23 20:57:25 $
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
  
private:

  ClassDef(I3OddOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3OddOMSelection>::ThePolicy I3OddOMSelectionPtr;

#endif
