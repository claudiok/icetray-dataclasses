/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3EvenOMSelection.h,v 1.5 2005/01/24 19:40:15 deyoung Exp $
 *
 * @file I3EvenOMSelection.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/01/24 19:40:15 $
 * @author deyoung
 */

#ifndef I3EVENOMSELECTION_H_INCLUDED
#define I3EVENOMSELECTION_H_INCLUDED

#include "I3OMResponseSelection.h"

class I3EvenOMSelection;

typedef PtrPolicy<I3EvenOMSelection>::ThePolicy I3EvenOMSelectionPtr;

class I3EvenOMSelection : public I3OMResponseSelection 
{
 public:
  
  I3EvenOMSelection() {};
  
  virtual ~I3EvenOMSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  Returns true if the OM's position on its
   * string is an even number, false otherwise.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) 
    {
      return ! (element.first.GetOM() % 2);
    };

  virtual I3OMResponseSelectionPtr GetCopy() 
    {
      return I3OMResponseSelectionPtr(new I3EvenOMSelection(*this));
    };

  // default-generated copy-constructor and assn. operator purposefully
  // allowed.

  virtual void ToStream(ostream& o) const {
    o << "[ I3EvenOMSelection ]\n";
  };

  ClassDef(I3EvenOMSelection,1);
};

#endif
