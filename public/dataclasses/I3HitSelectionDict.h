/**
 * copyright  (C) 2005
 * the IceCube Collaboration
 * $Id: I3HitSelectionDict.h,v 1.1.2.1 2005/02/18 20:54:55 deyoung Exp $
 *
 * @file I3hITSelectionDict.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/02/18 20:54:55 $
 * @author deyoung
 */
#ifndef DATACLASSES_I3HITSELECTIONDICT_H_INCLUDED
#define DATACLASSES_I3HITSELECTIONDICT_H_INCLUDED

#include "I3HitSelection.h"
#include "I3RecoHitSeries.h"
#include "StoragePolicy.h"
#include "services/I3Logging.h"
//using namespace std;

#ifndef __CINT__
#include <boost/iterator/filter_iterator.hpp>

typedef boost::filter_iterator<I3HitSelection,I3RecoHitSeries::iterator> I3HitSelector;
typedef PtrPolicy<I3HitSelector>::ThePolicy I3HitSelectorPtr;
#endif

/**
 * @brief 
 *
 * @todo fix GetSelector to return copies of the selection rather than
 * the selection itself.
 *
 */
class I3HitSelectionDict : public TObject, 
			   public MapPolicy<string,I3HitSelectionPtr>::ThePolicy 
{
  
 public:

  // constructor and destructor
  I3HitSelectionDict(){};
  virtual ~I3HitSelectionDict(){};

#ifndef __CINT__

  I3HitSelector GetSelector(const string &name, I3RecoHitSeries& series) {

    // I should be using GetClone() to make an independent copy of the
    // selection object before packaging it into the selector.  But
    // the selector maintains a reference to its selection, not a
    // smart pointer.  So if I make a copy, the only smart pointer to
    // the copy will go out of scope when this function exits, and the
    // selection logic will be deleted when the selector is returned
    // to the calling module, leading to a seg fault.  For now I'll
    // use the original selection, which is fine as long as nobody
    // changes its state dynamically. 
    log_debug("Param name is %s", name.c_str());
    if (name.empty()) {
      // I should return a selector based on a base-class
      // I3HitResponseSelection.  But I need to create it dynamically
      // and maintain a smart pointer to it to prevent it from going
      // out of scope.  Once the above issue is resolved, I can just
      // pop one off and release it, but for now I'll add it to the
      // map under a hidden name, after first checking whether it's
      // already there.
      log_debug("Entering empty block");
      I3HitSelectionDict::iterator iter = find("_IGNORE_ME_"); 
      if (iter == end()) {
	log_debug("No dummy selection found");
	I3HitSelectionPtr dummy(new I3HitSelection);
	(*this)["_IGNORE_ME_"] = dummy;
      } else {
	log_debug("Using existing dummy.");
      }

      I3HitSelectionPtr selection = (*this)["_IGNORE_ME_"];
      return I3HitSelector(boost::make_filter_iterator<I3HitSelection>
			   (*selection, series.begin(),series.end()));
    } else {
      log_debug("Dummy selection already exists.");
      I3HitSelectionPtr selection = (*this)[name];
      return I3HitSelector(boost::make_filter_iterator<I3HitSelection>
			   (*selection, series.begin(),series.end()));
    }
  }

#endif

  
  virtual void ToStream(ostream& o) const 
    {
      o << "[ I3HitSelectionDict: \n";

      I3HitSelectionDict::const_iterator iter;
      for(iter=begin(); iter!=end(); iter++) {
	o << iter->first;
	if (iter->second == 
	    I3HitSelectionPtr((I3HitSelection*)0)) {
	  o << "Null I3HitSelection";
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

  SET_LOGGER("HitSelectionDict");

  // ROOT macro
  ClassDef(I3HitSelectionDict,1);
};

/**
 * streams an I3HitSelectionDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3HitSelectionDict& v)
{
  v.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3HitSelectionDict>::ThePolicy I3HitSelectionDictPtr;

#endif
