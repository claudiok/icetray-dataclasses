/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3EvenOMSelection.h,v 1.1 2004/11/19 22:10:14 deyoung Exp $
 *
 * @file I3EvenOMSelection.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/11/19 22:10:14 $
 * @author deyoung
 */

#ifndef I3EVENOMSELECTION_H_INCLUDED
#define I3EVENOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3EvenOMSelection : public I3OMResponseSelection {

public:
  
  I3EvenOMSelection() {};
  
  virtual ~I3EvenOMSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM's position on its
   * string is an even number, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponse>& element) {
    if (element.first.GetOM() % 2) {
      return kFALSE;
    }
    return kTRUE;
  };

private:
  /**
   * assignment operator is a member-wise assignment
   */
  const I3EvenOMSelection& operator=(const I3EvenOMSelection& rhs) { 
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3EvenOMSelection(const I3EvenOMSelection& rhs) { *this = rhs; } 
  
  ClassDef(I3EvenOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3EvenOMSelection>::ThePolicy I3EvenOMSelectionPtr;

#endif
