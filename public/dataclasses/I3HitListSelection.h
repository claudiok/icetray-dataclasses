/**
 * copyright  (C) 2005
 * the IceCube collaboration
 *  $Id: I3HitListSelection.h,v 1.1.2.1 2005/02/18 21:25:37 deyoung Exp $
 *
 * @file I3HitListSelection.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/02/18 21:25:37 $
 * @author deyoung
 */

#ifndef DATACLASSES_I3HITLISTSELECTION_H_INCLUDED
#define DATACLASSES_I3HITLISTSELECTION_H_INCLUDED

#include "I3HitSelection.h"

/**
 * @brief Virtual base class for OMSelections that check against a list of OMKeys
 */
class I3HitListSelection : public I3HitSelection {

public:
  
  I3HitListSelection() {};
  
  I3HitListSelection(const VectorPolicy<unsigned int>::ThePolicy &list) 
    : hitList_(list) {};
  
  virtual ~I3HitListSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * OMs, false otherwise.
   */
  virtual bool operator()(const I3RecoHitPtr& hit) 
    {
      if (find(hitList_.begin(), hitList_.end(), hit->GetID()) != 
	  hitList_.end()) {
	return true;
      } else {
	return false;
      }
    };
  
  /**
   * Returns the list of Hits as a vector of Hit ID numbers
   */
  VectorPolicy<unsigned int>::ThePolicy GetHitList() const {
    return hitList_;
  };
  
  /**
   * Allows the list of Hits to be set all at once, overwriting any
   * existing list
   */ 
  virtual void SetHitList(const VectorPolicy<unsigned int>::ThePolicy& list) {
    if (hitList_.Size() > 0) {
      log_warn("Overwriting list of hits.");
      hitList_.Clear();
    }
    hitList_ = list;
  }
  
  /**
   * Adds a single hit ID to the list
   */
  virtual void AddHit(unsigned int hitNumber) {
    hitList_.Add(hitNumber);
  }

  virtual I3HitSelectionPtr GetCopy() = 0;

  virtual void ToStream(ostream& o) const {
    o << "  Hit List: \n";
    VectorPolicy<unsigned int>::ThePolicy::const_iterator iter;
    for(iter = hitList_.begin(); iter != hitList_.end(); iter++) {
      o << *iter << "\n";
    }
    o << "]\n";
  }

  // default-generated assignment and copy-constructor explicitly allowed

private:

  VectorPolicy<unsigned int>::ThePolicy hitList_;

  ClassDef(I3HitListSelection,1);
};

typedef PtrPolicy<I3HitListSelection>::ThePolicy I3HitListSelectionPtr;

#endif
