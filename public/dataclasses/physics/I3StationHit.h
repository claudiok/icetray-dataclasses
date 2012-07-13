/**
    @version $Id$
    @file I3StationHit.h
    @date Fri Jul  9 21:16:58 EDT 2004
*/

#ifndef I3STATIONHIT_H_INCLUDED
#define I3STATIONHIT_H_INCLUDED

#include "dataclasses/physics/I3TankHit.h"
#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/StationKey.h"
#include "dataclasses/I3Map.h"

#include <sstream>
/**
 * @brief The container for all the Station Hit-related data in an array
 *
 */
static const unsigned i3stationhit_version_ = 0;

class I3StationHit : public I3Vector<I3TankHitPtr> {

 private:

  // the station number
  unsigned short stationNumber_;

 public:

  I3StationHit(unsigned short station_number = 0) :
    stationNumber_( station_number ) {}
  
  virtual ~I3StationHit();

  /**
   * Get the station number
   */
  unsigned short StationNumber () const {
	  return stationNumber_;
  }

  /**
   * Set the station number
   */
  void StationNumber (unsigned short station_number) {
	  stationNumber_ = station_number;
  }

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3StationHit);
BOOST_CLASS_VERSION(I3StationHit, i3stationhit_version_);

typedef I3Map<StationKey, I3StationHit> I3StationHitMap;


I3_POINTER_TYPEDEFS(I3StationHitMap);

/**
 @brief Functor for find_if
 @class I3StationHitMatchesStationNumber
 @author Peter Niessen
 
*/
class I3StationHitMatchesStationNumber {
 public:

  /**
   * Constructor, pass on the station number to look for
   */
  I3StationHitMatchesStationNumber (unsigned short station_number)
    {
      stationNumber_ = station_number;
    }

  /**
   * Comparison operator
   */
  bool operator () (I3StationHitPtr station)
    {
      return station->StationNumber () == stationNumber_;
    }

 private:
  unsigned short stationNumber_;

};



#endif //I3STATIONHIT_H_INCLUDED
