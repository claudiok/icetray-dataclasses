/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3GoodOMSelection.h,v 1.6 2005/01/24 19:40:15 deyoung Exp $
 *
 * @file I3GoodOMSelection.h
 * @version $Revision: 1.6 $
 * @date $Date: 2005/01/24 19:40:15 $
 * @author deyoung
 */

#ifndef I3GOODOMSELECTION_H_INCLUDED
#define I3GOODOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3GoodOMSelection;
typedef PtrPolicy<I3GoodOMSelection>::ThePolicy I3GoodOMSelectionPtr;

class I3GoodOMSelection : public I3OMResponseSelection 
{
 public:
  
  VectorPolicy<OMKey>::ThePolicy goodOMs;

  I3GoodOMSelection() {};
  
  I3GoodOMSelection(const VectorPolicy<OMKey>::ThePolicy &list) 
    : goodOMs(list) {};
  
  virtual ~I3GoodOMSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM key is in the list of
   * good OMs, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) 
    {
      if (find(goodOMs.begin(), goodOMs.end(), element.first) != goodOMs.end())
	return true;
      else
	return false;
    };

  virtual I3OMResponseSelectionPtr GetCopy() 
    {
      return I3OMResponseSelectionPtr(new I3GoodOMSelection(*this));
    }

  virtual void ToStream(ostream& o) const {
    o << "[ I3GoodOMSelection: \n";
    o << "  Good OMs: \n";
    VectorPolicy<OMKey>::ThePolicy::const_iterator iter;
    for(iter = goodOMs.begin(); iter != goodOMs.end(); iter++) {
      o << *iter << "\n";
    }
    o << "]\n";
  }

  // default-generated assignment and copy-constructor explicitly allowed
  
  ClassDef(I3GoodOMSelection,1);
};


#endif
