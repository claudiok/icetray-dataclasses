/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3GoodOMSelection.h,v 1.2 2004/11/23 18:57:04 deyoung Exp $
 *
 * @file I3GoodOMSelection.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/11/23 18:57:04 $
 * @author deyoung
 */

#ifndef I3GOODOMSELECTION_H_INCLUDED
#define I3GOODOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3GoodOMSelection : public I3OMResponseSelection {

public:
  
  I3GoodOMSelection() {};

  I3GoodOMSelection(VectorPolicy<OMKey>::ThePolicy list) : fGoodOMs(list) {};
  
  virtual ~I3GoodOMSelection() {};
 
  virtual void SetGoodOMs(const VectorPolicy<OMKey>::ThePolicy& list) {
    if (fGoodOMs.Size() > 0) {
      log_warn("Overwriting list of good OMs.");
      fGoodOMs.Clear();
    }
    for (Int_t i = 0; i < list.Size(); ++i) {
      fGoodOMs.Add(list[i]);
    }
  };

  virtual void AddGoodOM(const OMKey& key) {
    fGoodOMs.Add(key);
  };

  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * good OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    for (Int_t i = 0; i < fGoodOMs.size(); i++) {      
      if (element.first == fGoodOMs[i]) {
	return kTRUE;
      }
    }
    return kFALSE;
  };

protected:
  VectorPolicy<OMKey>::ThePolicy fGoodOMs;

private:
  /**
   * assignment operator is a member-wise assignment
   */
  const I3GoodOMSelection& operator=(const I3GoodOMSelection& rhs) { 
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3GoodOMSelection(const I3GoodOMSelection& rhs) { *this = rhs; } 
  
  ClassDef(I3GoodOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3GoodOMSelection>::ThePolicy I3GoodOMSelectionPtr;

#endif
