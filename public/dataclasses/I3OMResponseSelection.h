/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMResponseSelection.h,v 1.3 2004/11/23 20:57:25 deyoung Exp $
 *
 * @file I3OMResponseSelection.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/11/23 20:57:25 $
 * @author deyoung
 */

#ifndef I3OMRESPONSESELECTION_H_INCLUDED
#define I3OMRESPONSESELECTION_H_INCLUDED

#include <TObject.h>
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
  
private:

  ClassDef(I3OMResponseSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3OMResponseSelection>::ThePolicy I3OMResponseSelectionPtr;

#endif
