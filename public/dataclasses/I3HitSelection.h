/**
 * copyright  (C) 2005
 * the IceCube collaboration
 *  $Id: I3HitSelection.h,v 1.1.2.2 2005/02/18 21:25:37 deyoung Exp $
 *
 * @file I3HitSelection.h
 * @version $Revision: 1.1.2.2 $
 * @date $Date: 2005/02/18 21:25:37 $
 * @author deyoung
 */

#ifndef DATACLASSES_I3HITSELECTION_H_INCLUDED
#define DATACLASSES_I3HITSELECTION_H_INCLUDED

#include <TObject.h>
#include "I3RecoHit.h"
//#include "OMKey.h"
//#include "I3RecoHitSeries.h"

//using namespace std;

class I3HitSelection;
/**
 * Pointer definition for use with smart pointers.
 */
typedef PtrPolicy<I3HitSelection>::ThePolicy I3HitSelectionPtr;

/**
 * @brief Base class for selecting I3RecoHits
 * 
 * This is the class that users will inherit from when they want to make a 
 * new selection, and the interface that clients use to access those
 * selections.  This class contains the selection logic; it is
 * built into a filter_iterator to make a selector.
 */
class I3HitSelection : public TObject 
{
public:
  
  I3HitSelection() {};
  
  virtual ~I3HitSelection() {};
 
  /**
   * Virtual function for deciding whether a given RecoHit
   * is selected.  By default, returns true for all hits.
   */
  virtual bool operator()(const I3RecoHitPtr& hit) {
    return true; 
  };

  /**
   * Alternate version of operator()
   */
  virtual bool IsSelected(const I3RecoHitPtr& hit) {
    return operator()(hit);
  };

  /**
   * Virtual function for obtaining an independent copy of the
   * selection.  This is necessary for using nested loops if the
   * Selection has state.  
   */
  virtual I3HitSelectionPtr GetCopy() {
    return I3HitSelectionPtr(new I3HitSelection);
  };

  /**
   * Alternative name for GetCopy()
   */
  virtual I3HitSelectionPtr GetClone() 
  {
    return this->GetCopy();
  };

  // Default copy and assignment intentionally allowed.

  virtual void ToStream(ostream& o) const 
    {
      o << "[ I3HitSelection: ]\n";
    }

  virtual string ToString() const {
    ostringstream out;
    ToStream(out);
    return out.str();
  }  

private:

  ClassDef(I3HitSelection,1);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3HitSelection& sel)
{
  sel.ToStream(o);
  return o;
}


#endif
