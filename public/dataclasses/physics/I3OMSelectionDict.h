/**
 * copyright  (C) 2005
 * the IceCube Collaboration
 * $Id$
 *
 * @file I3OMSelectionDict.h
 * @version $Revision: 1.9 $
 * @date $Date$
 * @author deyoung
 * @author troy
 */
#ifndef I3OMSELECTIONDICT_H_INCLUDED
#define I3OMSELECTIONDICT_H_INCLUDED

#include "I3OMResponseSelection.h"
#include "I3OMResponseMap.h"
#include "I3OMResponse.h"
#include "dataclasses/StoragePolicy.h"
using namespace std;

#ifndef __CINT__
#include <boost/iterator/filter_iterator.hpp>

typedef boost::filter_iterator<I3OMResponseSelection,I3OMResponseMap::iterator> I3OMSelector;
typedef shared_ptr<I3OMSelector>  I3OMSelectorPtr;
#endif

/**
 * @brief An event-level container for the OMResponseSelection's of the Event.  
 *
 * @todo fix GetSelector to return copies of the selection rather than
 * the selection itself.
 *
 */
class I3OMSelectionDict : public TObject, 
			  public map<string,I3OMResponseSelectionPtr>
{
  
 public:

  /**
   * constructor
   */
  I3OMSelectionDict(){};
  
  /**
   * destructor
   */
  virtual ~I3OMSelectionDict();

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
    log_debug("Param name is %s", name.c_str());
    if (name.empty()) {
      // I should return a selector based on a base-class
      // I3OMResponseSelection.  But I need to create it dynamically
      // and maintain a smart pointer to it to prevent it from going
      // out of scope.  Once the above issue is resolved, I can just
      // pop one off and release it, but for now I'll add it to the
      // map under a hidden name, after first checking whether it's
      // already there.
      log_debug("Entering empty block");
      I3OMSelectionDict::iterator iter = find("_IGNORE_ME_"); 
      if (iter == end()) {
	log_debug("No dummy selection found");
	I3OMResponseSelectionPtr dummy(new I3OMResponseSelection);
	(*this)["_IGNORE_ME_"] = dummy;
      } else {
	log_debug("Using existing dummy.");
      }

      I3OMResponseSelectionPtr selection = (*this)["_IGNORE_ME_"];
      return I3OMSelector(boost::make_filter_iterator<I3OMResponseSelection>
      			  (*selection, map.begin(),map.end()));
    } else {
      log_debug("Dummy selection already exists.");
      I3OMResponseSelectionPtr selection = (*this)[name];
      return I3OMSelector(boost::make_filter_iterator<I3OMResponseSelection>
			  (*selection, map.begin(),map.end()));
    }
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

  SET_LOGGER("Selectors");

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

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
typedef shared_ptr<I3OMSelectionDict>  I3OMSelectionDictPtr;

#endif

