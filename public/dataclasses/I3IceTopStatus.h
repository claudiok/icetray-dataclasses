/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3IceTopStatus.h,v 1.7.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3IceTopStatus.h
 * @version $Revision: 1.7.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author pretz
 */
#ifndef I3ICETOPSTATUS_H
#define I3ICETOPSTATUS_H

#include <sstream>

#include "I3IceTopStationStatus.h"
#include "StoragePolicy.h"
#include "StationKey.h"

/**
 * @brief a container for I3IcetTopStationStatus objects.  Just holding a place
 * for now
 */
class I3IceTopStatus : public TObject, 
		       public MapPolicy<StationKey,I3IceTopStationStatusPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3IceTopStatus(){}

  /**
   * destructor
   */
  virtual ~I3IceTopStatus(){};

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3IceTopStatus: \n";
      I3IceTopStatus::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3IceTopStationStatusPtr((I3IceTopStationStatus*)0))
	o<<"Null I3IceTopStationStatus";
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
  I3IceTopStatus(const I3IceTopStatus& rhs);
  const I3IceTopStatus& operator=(const I3IceTopStatus& rhs);

  // ROOT macro
  ClassDef(I3IceTopStatus,1);
};

inline ostream& operator<<(ostream& o,const I3IceTopStatus& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3IceTopStatus>::ThePolicy I3IceTopStatusPtr;

#endif
