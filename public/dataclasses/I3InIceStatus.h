/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceStatus.h,v 1.7.4.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3InIceStatus.h
 * @version $Revision: 1.7.4.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author pretz
 */
#ifndef I3INICESTATUSDATA_H
#define I3INICESTATUSDATA_H

#include "I3OMStatusIceCube.h"
#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include <sstream>

/**
 * @brief The status of the DeepIce detector.  
 *
 * Just a container for I3OMStatusIceCube objects
 */
class I3InIceStatus 
: public TObject, 
  public MapPolicy<OMKey,I3OMStatusIceCubePtr>::ThePolicy{
 public:
  /**
   * constructor
   */
  I3InIceStatus(){}

  /**
   * destructor
   */
  virtual ~I3InIceStatus(){};

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3InIceStatus: \n";
      I3InIceStatus::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3OMStatusIceCubePtr((I3OMStatusIceCube*)0))
	    o<<"Null I3OMStatusIceCube";
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
  // copy and assignment are private
  I3InIceStatus(const I3InIceStatus& rhs);
  const I3InIceStatus& operator=(const I3InIceStatus& rhs);


};

inline ostream& operator<<(ostream& o, const I3InIceStatus& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3InIceStatus>::ThePolicy I3InIceStatusPtr;

#endif
