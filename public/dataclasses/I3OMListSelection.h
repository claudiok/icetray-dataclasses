/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMListSelection.h,v 1.3 2005/02/09 18:36:37 deyoung Exp $
 *
 * @file I3OMListSelection.h
 * @version $Revision: 1.3 $
 * @date $Date: 2005/02/09 18:36:37 $
 * @author deyoung
 */

#ifndef I3OMLISTSELECTION_H_INCLUDED
#define I3OMLISTSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3OMListSelection;
typedef PtrPolicy<I3OMListSelection>::ThePolicy I3OMListSelectionPtr;

/**
 * @brief Virtual base class for OMSelections that check against a list of OMKeys
 */
class I3OMListSelection : public I3OMResponseSelection {

public:
  
  I3OMListSelection() {};
  
  I3OMListSelection(const VectorPolicy<OMKey>::ThePolicy &list) 
    : omList_(list) {};
  
  virtual ~I3OMListSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) 
    {
      if (find(omList_.begin(), omList_.end(), element.first) != omList_.end())
	return true;
      else
	return false;
    };
  
  /**
   * Returns the list of OMs as a vector of OMKeys
   */
  VectorPolicy<OMKey>::ThePolicy GetOMList() const {
    return omList_;
  };
  
  /**
   * Allows the list of OMs to be set all at once, overwriting any
   * existing list
   */ 
  virtual void SetOMList(const VectorPolicy<OMKey>::ThePolicy& list) {
    if (omList_.Size() > 0) {
      log_warn("Overwriting list of OMs.");
      omList_.Clear();
    }
    omList_ = list;
  }
  
  /**
   * Adds a single OMKey to the list
   */
  virtual void AddOM(OMKey key) {
    omList_.Add(key);
  }

  virtual I3OMResponseSelectionPtr GetCopy() = 0;

  virtual void ToStream(ostream& o) const {
    o << "  OM List: \n";
    VectorPolicy<OMKey>::ThePolicy::const_iterator iter;
    for(iter = omList_.begin(); iter != omList_.end(); iter++) {
      o << *iter << "\n";
    }
    o << "]\n";
  }

  // default-generated assignment and copy-constructor explicitly allowed

private:

  VectorPolicy<OMKey>::ThePolicy omList_;

  ClassDef(I3OMListSelection,1);
};


#endif
