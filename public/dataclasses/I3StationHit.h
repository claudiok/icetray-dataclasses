/**
    $Id: I3StationHit.h,v 1.5.4.2 2005/02/04 21:49:05 troy Exp $
    @file I3StationHit.h
    @version $Revision: 1.5.4.2 $
    @date Fri Jul  9 21:16:58 EDT 2004
    @author rulrich
*/
#ifndef I3StationHit_H
#define I3StationHit_H

#include "dataclasses/I3TankHit.h"
#include "dataclasses/StoragePolicy.h"

#include <sstream>
/**
 * @brief The container for all the Station Hit-related data in an array
 *
 */
class I3StationHit : public TObject, 
	 //	 public VecPointainerPolicy<I3TankHitPtr>::ThePolicy {
	 public VectorPolicy<I3TankHitPtr>::ThePolicy {

 private:

  // the station number
  UShort_t fStationNumber;

  /*
    RU: I would think of a station only as a unit for triggering purposes,
        especially for low energetic air showers as a ICECUBE veto, so
        it may not need any of these:

  // signal of the station, to be computed from the signals in
  // the tank
  Float_t fSignal;

  // time of the station, to be computed from the times in the tank
  Float_t fTime;

  // x position of the hit, to be composed from the tank x
  Float_t fX;

  // y postion of the hist, to be composed from the tank y
  Float_t fY;
  */

 public:
  /**
   * constructor
   */
  I3StationHit(UShort_t station_number = 0) :
    fStationNumber( station_number ) {}
  
  /**
   * destructor
   */
  virtual ~I3StationHit() {;}

  /**
   * Get the station number
   */
  UShort_t StationNumber () const;

  /**
   * Set the station number
   */
  void StationNumber (UShort_t station_number);

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3StationHit: \n";
      I3StationHit::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  if(*iter == I3TankHitPtr((I3TankHit*)0))
	    o<<"Null I3TankHit";
	  else
	    o<<*(*iter);
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
  I3StationHit(const I3StationHit&); 
  const I3StationHit& operator=(const I3StationHit&); 

  // ROOT macro

};

inline ostream& operator<<(ostream& o,const I3StationHit& hit)
{
  hit.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3StationHit>::ThePolicy I3StationHitPtr;

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
  I3StationHitMatchesStationNumber (UShort_t station_number)
    {
      fStationNumber = station_number;
    }

  /**
   * Comparison operator
   */
  bool operator () (I3StationHitPtr station)
    {
      return station->StationNumber () == fStationNumber;
    }

 private:
  UShort_t fStationNumber;

};

#endif
