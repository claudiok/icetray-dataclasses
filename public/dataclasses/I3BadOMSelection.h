/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3BadOMSelection.h,v 1.3 2004/11/23 20:57:25 deyoung Exp $
 *
 * @file I3BadOMSelection.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/11/23 20:57:25 $
 * @author deyoung
 */

#ifndef I3BADOMSELECTION_H_INCLUDED
#define I3BADOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3BadOMSelection : public I3OMResponseSelection {

public:
  
  I3BadOMSelection() {};

  I3BadOMSelection(VectorPolicy<OMKey>::ThePolicy list) : fBadOMs(list) {};
  
  virtual ~I3BadOMSelection() {};
 
  VectorPolicy<OMKey>::ThePolicy GetBadOMs() const {
    return fBadOMs;
  }; 

  virtual void SetBadOMs(const VectorPolicy<OMKey>::ThePolicy& list) {
    if (fBadOMs.Size() > 0) {
      log_warn("Overwriting list of bad OMs.");
      fBadOMs.Clear();
    }
    for (Int_t i = 0; i < list.Size(); ++i) {
      fBadOMs.Add(list[i]);
    }
  };

  virtual void AddBadOM(const OMKey& key) {
    fBadOMs.Add(key);
  };

  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns false if the OM key is in the list of
   * true OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    for (Int_t i = 0; i < fBadOMs.size(); i++) {      
      if (element.first == fBadOMs[i]) {
	return kFALSE;
      }
    }
    return kTRUE;
  };

  /**
   * assignment operator is a member-wise assignment
   */
  const I3BadOMSelection& operator=(const I3BadOMSelection& rhs) { 
    fBadOMs = rhs.GetBadOMs();
    return *this;
  }

  /**
   * copy constructor just uses assignment operator
   */
  I3BadOMSelection(const I3BadOMSelection& rhs) { *this = rhs; } 

private:

  VectorPolicy<OMKey>::ThePolicy fBadOMs;
  
  ClassDef(I3BadOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3BadOMSelection>::ThePolicy I3BadOMSelectionPtr;

#endif
