/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3GoodOMSelection.h,v 1.8 2005/02/08 20:04:27 deyoung Exp $
 *
 * @file I3GoodOMSelection.h
 * @version $Revision: 1.8 $
 * @date $Date: 2005/02/08 20:04:27 $
 * @author deyoung
 */

#ifndef I3GOODOMSELECTION_H_INCLUDED
#define I3GOODOMSELECTION_H_INCLUDED

#include "I3OMListSelection.h"

class I3GoodOMSelection;
typedef PtrPolicy<I3GoodOMSelection>::ThePolicy I3GoodOMSelectionPtr;

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
  
  VectorPolicy<OMKey>::ThePolicy GetGoodOMs() const {
    //    return omList_;
    return I3OMListSelection::GetOMList();
  };
  
  virtual void SetGoodOMs(const VectorPolicy<OMKey>::ThePolicy& good_list) {
//     if (omList_.Size() > 0) {
//       log_warn("Overwriting list of OMs.");
//       omList_.Clear();
//     }
//     omList_ = good_list;
    I3OMListSelection::SetOMList(good_list);
  }
  
  virtual void AddGoodOM(OMKey key) {
    //    omList_.Add(key);
    I3OMListSelection::AddOM(key);
  }

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

  //  VectorPolicy<OMKey>::ThePolicy omList_;
  
  ClassDef(I3GoodOMSelection,1);
};


#endif
