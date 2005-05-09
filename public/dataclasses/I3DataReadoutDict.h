/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DataReadoutDict.h
 * @version $Revision: 1.13 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */

#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"
#include <sstream>

/**
 * @brief Container (map) of I3DataReadouts
 * 
 * The I3DataReadoutDict is a container of I3DataReadouts.  It is a
 * member of I3OMResponse, which
 * contains all information associated with a particular OM in a
 * single event, including hit information as well as raw and derived
 * data readouts.  The @c DataReadoutDict may contain any number of
 * I3DataReadouts.  Each I3DataReadout in the
 * @c DataReadoutDict is identified by a name, given by the software
 * that added the readout to the event.  
 * 
 * The @c DataReadoutDict is a map container.  The syntax for
 * accessing elements in the map is inherited from the MapPolicy,
 * which is currently set to STLMapStoragePolicy.
 */

class I3DataReadoutDict : public TObject, 
	public STLMapStoragePolicy<string,I3DataReadoutPtr>
{
 public:
  /**
   * constructor
   */ 
  I3DataReadoutDict(){};

  /**
   * destructor 
   */
  virtual ~I3DataReadoutDict(){};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3DataReadoutDict: \n";
      I3DataReadoutDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3DataReadoutPtr((I3DataReadout*)0))
	    o<<"Null I3DataReadout";
	  else
	    o<<*(iter->second);
	}
      o<<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3DataReadoutDict", 
		  base_object< STLMapStoragePolicy<string,I3DataReadoutPtr> >(*this));
  }

  // ROOT macro
  ClassDef(I3DataReadoutDict,1);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3DataReadoutDict& v)
{
  v.ToStream(o);
  return o;
   
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DataReadoutDict>  I3DataReadoutDictPtr;

#endif

