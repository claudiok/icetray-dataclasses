/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMResponseSelection.h,v 1.6 2005/01/24 19:45:04 deyoung Exp $
 *
 * @file I3OMResponseSelection.h
 * @version $Revision: 1.6 $
 * @date $Date: 2005/01/24 19:45:04 $
 * @author deyoung
 * @author troy
 */

#ifndef I3OMRESPONSESELECTION_H_INCLUDED
#define I3OMRESPONSESELECTION_H_INCLUDED

#include <TObject.h>
#include "I3OMResponse.h"
#include "OMKey.h"

using namespace std;

class I3OMResponseSelection;
/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3OMResponseSelection>::ThePolicy I3OMResponseSelectionPtr;

/**
 * This is the class that users will inherit from when they want to make a 
 * new selection.  This class contains the selection logic; it is
 * built into a filter_iterator to make a selector.
 */
class I3OMResponseSelection : public TObject 
{
public:
  
  I3OMResponseSelection() {};
  
  virtual ~I3OMResponseSelection() {};
 
  /**
   * Virtual function for deciding whether a given <OMKey, OMResponse>
   * pair is selected.  By default, returns true for all OMResponses.
   */
  virtual bool operator()(const pair<OMKey, I3OMResponsePtr>& element) {
    return kTRUE; 
  };

  /**
   * Virtual function for obtaining an independent copy of the
   * selection.  This is necessary for using nested loops if the
   * Selection has state.  
   */
  virtual I3OMResponseSelectionPtr GetCopy() {
    return I3OMResponseSelectionPtr(new I3OMResponseSelection);
  };

  /**
   * Alternative name for GetCopy()
   */
  virtual I3OMResponseSelectionPtr GetClone() 
  {
    return this->GetCopy();
  };

  // Default copy and assignment intentionally allowed.

  virtual void ToStream(ostream& o) const 
    {
      o << "[ I3OMResponseSelection: ]\n";
    }

  virtual string ToString() const {
    ostringstream out;
    ToStream(out);
    return out.str();
  }  

private:

  ClassDef(I3OMResponseSelection,1);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3OMResponseSelection& readout)
{
  readout.ToStream(o);
  return o;
}


#endif
