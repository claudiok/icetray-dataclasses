/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3BadOMSelection.h,v 1.7 2005/02/08 20:04:27 deyoung Exp $
 *
 * @file I3BadOMSelection.h
 * @version $Revision: 1.7 $
 * @date $Date: 2005/02/08 20:04:27 $
 * @author deyoung
 */

#ifndef I3BADOMSELECTION_H_INCLUDED
#define I3BADOMSELECTION_H_INCLUDED

#include "I3OMListSelection.h"

class I3BadOMSelection : public I3OMListSelection {

public:
  
  I3BadOMSelection() {};

  I3BadOMSelection(const VectorPolicy<OMKey>::ThePolicy list) 
    : I3OMListSelection(list) {};
  
  virtual ~I3BadOMSelection() {};
 
  VectorPolicy<OMKey>::ThePolicy GetBadOMs() const {
    //    return omList_;
    return I3OMListSelection::GetOMList();
  }; 

  virtual void SetBadOMs(const VectorPolicy<OMKey>::ThePolicy& list) {
//     if (omList_.Size() > 0) {
//       log_warn("Overwriting list of bad OMs.");
//       omList_.Clear();
//     }
//     for (unsigned i = 0; i < list.Size(); ++i) {
//       omList_.Add(list[i]);
//     }
    I3OMListSelection::SetOMList(list);
  };

  virtual void AddBadOM(const OMKey& key) {
    //    omList_.Add(key);
    I3OMListSelection::AddOM(key);
  };

  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns false if the OM key is in the list of
   * true OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    return !(I3OMListSelection::operator()(element));
  };

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

  //  VectorPolicy<OMKey>::ThePolicy omList_;
  
  ClassDef(I3BadOMSelection,1);
};

/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3BadOMSelection>::ThePolicy I3BadOMSelectionPtr;

#endif
