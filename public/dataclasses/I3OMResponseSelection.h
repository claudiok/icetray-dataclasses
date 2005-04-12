/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMResponseSelection.h,v 1.12 2005/04/12 23:09:49 olivas Exp $
 *
 * @file I3OMResponseSelection.h
 * @version $Revision: 1.12 $
 * @date $Date: 2005/04/12 23:09:49 $
 * @author deyoung
 * @author troy
 */

#ifndef I3OMRESPONSESELECTION_H_INCLUDED
#define I3OMRESPONSESELECTION_H_INCLUDED

#include <TObject.h>
#include "I3OMResponse.h"
#include "OMKey.h"
#include "I3OMResponseMap.h"

using namespace std;

class I3OMResponseSelection;
/**
 * Pointer definition for use with smart pointers.
 */
typedef shared_ptr<I3OMResponseSelection>  I3OMResponseSelectionPtr;

/**
 * @brief Base class for selecting I3OMResponses
 * 
 * This is the class that users will inherit from when they want to make a 
 * new selection, and the interface that clients use to access those
 * selections.  This class contains the selection logic; it is
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
    return true; 
  };

  /**
   * Alternate version of operator()
   */
  virtual bool IsSelected(const pair<OMKey, I3OMResponsePtr>& element) {
    return operator()(element);
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

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3OMResponseSelection", *this);
  }

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
