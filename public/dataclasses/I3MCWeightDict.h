/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: $
 *
 * @file I3MCWeightDict.h
 * @version $Revision: $
 * @date $Date: $
 * @author aya
 *
 */

#ifndef I3MCWEIGHTDICT_H
#define I3MCWEIGHTDICT_H

#include "StoragePolicy.h"
#include <sstream>

/**
 * @brief Container (map) to store weights for MC simulations
 * 
 * The I3MCWeightDict is a container of weigts (float).  The key is a
 * string which gives the information about what kind of weight the 
 * number is representing. 
 * The @c I3MCWeightDict may contain any number of float of weights.
 * The @c I3MCWeightDict is a map container.  The syntax for
 * accessing elements in the map is inherited from the MapPolicy,
 * which is currently set to STLMapStoragePolicy.
 */
class I3MCWeightDict : public TObject, public STLMapStoragePolicy<string, float> {
 public:
  /**
   * constructor
   */ 
  I3MCWeightDict(){};

  /**
   * destructor 
   */
  virtual ~I3MCWeightDict();

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3MCWeightDict: \n";
      I3MCWeightDict::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first <<" ";
	  if(!(iter->second))
	    o<<"Null I3MCWeight";
	  else
	    o<<(iter->second)<<" ";
	}
      o<<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};


/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3MCWeightDict& v)
{
  v.ToStream(o);
  return o;
   
}

typedef shared_ptr<I3MCWeightDict>  I3MCWeightDictPtr;

#endif


