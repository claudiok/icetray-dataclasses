/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3BadOMSelection.h,v 1.8 2005/02/09 18:18:05 deyoung Exp $
 *
 * @file I3BadOMSelection.h
 * @version $Revision: 1.8 $
 * @date $Date: 2005/02/09 18:18:05 $
 * @author deyoung
 */

#ifndef I3BADOMSELECTION_H_INCLUDED
#define I3BADOMSELECTION_H_INCLUDED

#include "I3OMListSelection.h"

/**
 * OMSelection class that selects all OMs whose keys are *not* in its
 * Bad OM list.
 */
class I3BadOMSelection : public I3OMListSelection {

public:
  
  I3BadOMSelection() {};

  I3BadOMSelection(const VectorPolicy<OMKey>::ThePolicy list) 
    : I3OMListSelection(list) {};
  
  virtual ~I3BadOMSelection() {};
 
  /**
   * Returns the entire list of bad OMs as a vector.  Equivalent to GetOMList().
   */
  VectorPolicy<OMKey>::ThePolicy GetBadOMs() const {
    return I3OMListSelection::GetOMList();
  }; 

  /** 
   * Set the list of bad OMs all at once.  Equivalent to SetOMList().
   */
  virtual void SetBadOMs(const VectorPolicy<OMKey>::ThePolicy& list) {
    I3OMListSelection::SetOMList(list);
  };

  /**
   * Add a bad OM to the list.  Equivalent to AddOM().
   */
  virtual void AddBadOM(const OMKey& key) {
    I3OMListSelection::AddOM(key);
  };

  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair should be selected.  Returns false if the OM key is in the
   * list of bad OMs, true otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    return !(I3OMListSelection::operator()(element));
  };

  /**
   * Returns a copy of the current selection.
   * @todo Should return an independent copy.
   */
  virtual I3OMResponseSelectionPtr GetCopy() {
    return I3OMResponseSelectionPtr(new I3BadOMSelection(*this));
  };

  virtual void ToStream(ostream& o) const {
    o << "[ I3BadOMSelection: \n";
    I3OMListSelection::ToStream(o);
  }

private:

  /**
   * assignment operator is a member-wise assignment
   */
//   const I3BadOMSelection& operator=(const I3BadOMSelection& rhs) { 
//     omList_ = rhs.GetBadOMs();
//     return *this;
//   }

  /**
   * copy constructor just uses assignment operator
   */
//   I3BadOMSelection(const I3BadOMSelection& rhs) { *this = rhs; } 

  ClassDef(I3BadOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3BadOMSelection>::ThePolicy I3BadOMSelectionPtr;

#endif
