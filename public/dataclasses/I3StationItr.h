/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3StationItr.h,v 1.2 2005/03/30 14:48:27 pretz Exp $
 * @version $Revision: 1.2 $
 * @date $Date: 2005/03/30 14:48:27 $
 * @author niessen Thu Sep 16 17:24:51 EDT 2004
 */

#ifndef __I3STATIONITR_H_
#define __I3STATIONITR_H_


#include "services/I3Logging.h"
#include "dataclasses/I3StationMap.h"
#include "dataclasses/StoragePolicy.h"

using namespace boost;

typedef I3StationMap::iterator I3StationItr;

/**
 * @brief To loop over stations
 */
class station_iterator : public TObject, public I3StationItr {

 public:

  /**
   * constructor
   */
  station_iterator () {}

  /**
   * virtual destructor
   */
  virtual ~station_iterator () {}

  /**
   * assignment
   */
  station_iterator &operator= (I3StationItr itr);

  /**
   * incrementation
   */
  station_iterator &operator++ ();

 private:

  I3StationItr fItr; // memorise where we are?

  ClassDef (station_iterator, 0);
};



#endif

