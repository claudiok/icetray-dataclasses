/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3GoodOMSelection.h,v 1.10 2005/02/09 18:36:37 deyoung Exp $
 *
 * @file I3GoodOMSelection.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/02/09 18:36:37 $
 * @author deyoung
 */

#ifndef I3GOODOMSELECTION_H_INCLUDED
#define I3GOODOMSELECTION_H_INCLUDED

#include "I3OMListSelection.h"

class I3GoodOMSelection;
typedef PtrPolicy<I3GoodOMSelection>::ThePolicy I3GoodOMSelectionPtr;

/**
 * @brief OMSelection class that selects all OMResponses whose OM keys are in
 * its list of good OMs.  All others are rejected.
 */
class I3GoodOMSelection : public I3OMListSelection {

public:
  
  I3GoodOMSelection() {};
  
  I3GoodOMSelection(const VectorPolicy<OMKey>::ThePolicy &theList) 
    : I3OMListSelection(theList) {};
  
  virtual ~I3GoodOMSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * good OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) 
    {
//       if (find(omList_.begin(), omList_.end(), element.first) != omList_.end())
// 	return true;
//       else
// 	return false;
      return I3OMListSelection::operator()(element);
    };

  /**
   * Returns the entire list of good OMs as a vector.  Equivalent to GetOMList().
   */
  VectorPolicy<OMKey>::ThePolicy GetGoodOMs() const {
    return I3OMListSelection::GetOMList();
  };
  
  /** 
   * Set the list of good OMs all at once.  Equivalent to SetOMList().
   */
  virtual void SetGoodOMs(const VectorPolicy<OMKey>::ThePolicy& good_list) {
    I3OMListSelection::SetOMList(good_list);
  }
  
  /**
   * Add a good OM to the list.  Equivalent to AddOM().
   */
  virtual void AddGoodOM(OMKey key) {
    I3OMListSelection::AddOM(key);
  }

  /**
   * Returns a copy of the current selection.
   * @todo Should return an independent copy.
   */
  virtual I3OMResponseSelectionPtr GetCopy() 
    {
      return I3OMResponseSelectionPtr(new I3GoodOMSelection(*this));
    }

  virtual void ToStream(ostream& o) const {
    o << "[ I3GoodOMSelection: \n";
    I3OMListSelection::ToStream(o);
  }

  // default-generated assignment and copy-constructor explicitly allowed

private:

  ClassDef(I3GoodOMSelection,1);
};


#endif
