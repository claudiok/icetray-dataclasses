/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMListSelection.h,v 1.1 2005/02/08 20:04:27 deyoung Exp $
 *
 * @file I3OMListSelection.h
 * @version $Revision: 1.1 $
 * @date $Date: 2005/02/08 20:04:27 $
 * @author deyoung
 */

#ifndef I3OMLISTSELECTION_H_INCLUDED
#define I3OMLISTSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3OMListSelection;
typedef PtrPolicy<I3OMListSelection>::ThePolicy I3OMListSelectionPtr;

class I3OMListSelection : public I3OMResponseSelection {

public:
  
  I3OMListSelection() {};
  
  I3OMListSelection(const VectorPolicy<OMKey>::ThePolicy &list) 
    : omList_(list) {};
  
  virtual ~I3OMListSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * good OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) 
    {
      if (find(omList_.begin(), omList_.end(), element.first) != omList_.end())
	return true;
      else
	return false;
    };
  
  VectorPolicy<OMKey>::ThePolicy GetOMList() const {
    return omList_;
  };
  
  virtual void SetOMList(const VectorPolicy<OMKey>::ThePolicy& list) {
    if (omList_.Size() > 0) {
      log_warn("Overwriting list of OMs.");
      omList_.Clear();
    }
    omList_ = list;
  }
  
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

  //protected:
  
  //  bool isGood_;
  
private:

  VectorPolicy<OMKey>::ThePolicy omList_;

  ClassDef(I3OMListSelection,1);
};


#endif
