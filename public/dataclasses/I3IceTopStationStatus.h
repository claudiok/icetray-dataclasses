/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStationStatus.h,v 1.6 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3IceTopStationStatus.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author pretz
 */
#ifndef I3ICETOPSTATIONSTATUS_H
#define I3ICETOPSTATIONSTATUS_H

#include "TObject.h"
#include "I3OMStatusIceCube.h"

/**
 * @brief the status of an IceTop station for the DetectorStatus stream.
 * Just holding a place for now
 *
 */
class I3IceTopStationStatus 
: public TObject, 
  public VectorPolicy<I3OMStatusIceCubePtr>::ThePolicy{
 public:
  /**
   * constructor
   */
  I3IceTopStationStatus(){}

  /**
   * destructor
   */
  virtual ~I3IceTopStationStatus(){};

  /**
 * dumps the object to the indicated ostream
 * @param o the ostream to dump the object to
 */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3IceTopStationStatus: \n";
      I3IceTopStationStatus::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
    {
      if(*iter == I3OMStatusIceCubePtr((I3OMStatusIceCube*)0))
	o<<"Null I3IceCubeStatus";
      else
	o<<*(*iter);
    }
      o<<"]\n";
    }
  
 private:
  // copy and assignment are private
/*   I3IceTopStationStatus(const I3IceTopStationStatus& rhs); */
/*   const I3IceTopStationStatus& operator=(const I3IceTopStationStatus& rhs); */

  // ROOT macro
  ClassDef(I3IceTopStationStatus,1);
};

inline ostream& operator<<(ostream& o,const I3IceTopStationStatus& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3IceTopStationStatus>::ThePolicy I3IceTopStationStatusPtr;

#endif
