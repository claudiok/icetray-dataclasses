/**
 * copyright  (C) 2005
 * the IceCube Collaboration
 * $Id: I3OMSelectionDict.h,v 1.4 2005/01/26 16:40:14 deyoung Exp $
 *
 * @file I3OMSelectionDict.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/01/26 16:40:14 $
 * @author deyoung
 * @author troy
 */
#ifndef I3OMSELECTIONDICT_H_INCLUDED
#define I3OMSELECTIONDICT_H_INCLUDED

#include "I3OMResponseSelection.h"
#include "I3OMResponseMap.h"
#include "I3OMResponse.h"
#include "StoragePolicy.h"
using namespace std;

#ifndef __CINT__
#include <boost/iterator/filter_iterator.hpp>

typedef boost::filter_iterator<I3OMResponseSelection,I3OMResponseMap::iterator> I3OMSelector;
typedef PtrPolicy<I3OMSelector>::ThePolicy I3OMSelectorPtr;
#endif

/**
 * @brief An event-level container for the OMResponseSelection's of the Event.  
 *
 * @todo fix GetSelector to return copies of the selection rather than
 * the selection itself.
 *
 */
class I3OMSelectionDict : public TObject, 
			  public MapPolicy<string,I3OMResponseSelectionPtr>::ThePolicy 
{
  
 public:

  /**
   * constructor
   */
  I3OMSelectionDict(){};
  
  /**
   * destructor
   */
  virtual ~I3OMSelectionDict(){};

#ifndef __CINT__

  I3OMSelector GetSelector(const string &name, I3OMResponseMap& map) {

    // I should be using GetClone() to make an independent copy of the
    // selection object before packaging it into the selector.  But
    // the selector maintains a reference to its selection, not a
    // smart pointer.  So if I make a copy, the only smart pointer to
    // the copy will go out of scope when this function exits, and the
    // selection logic will be deleted when the selector is returned
    // to the calling module, leading to a seg fault.  For now I'll
    // use the original selection, which is fine as long as nobody
    // changes its state dynamically.
    I3OMResponseSelectionPtr selection = (*this)[name];

    return I3OMSelector(boost::make_filter_iterator<I3OMResponseSelection>
			(*selection, map.begin(),map.end()));
  }

#endif

  
  virtual void ToStream(ostream& o) const 
    {
      o << "[ I3OMSelectionDict: \n";

      I3OMSelectionDict::const_iterator iter;
      for(iter=begin(); iter!=end(); iter++) {
	o << iter->first;
	if (iter->second == 
	    I3OMResponseSelectionPtr((I3OMResponseSelection*)0)) {
	  o << "Null I3OMResponseSelection";
	} else {
	  o << *(iter->second); 
	}
      }
      o << "]\n";
    }

  virtual string ToString() const {
    ostringstream out;
    ToStream(out);
    return out.str();
  }  

 private:

  // ROOT macro
  ClassDef(I3OMSelectionDict,1);
};

/**
 * streams an I3OMSelectionDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3OMSelectionDict& v)
{
  v.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMSelectionDict>::ThePolicy I3OMSelectionDictPtr;

#endif
