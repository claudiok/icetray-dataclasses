/**
    $Id: I3StationHit.h,v 1.6 2005/04/04 15:49:25 pretz Exp $
    @file I3StationHit.h
    @version $Revision: 1.6 $
    @date Fri Jul  9 21:16:58 EDT 2004
    @author rulrich
*/
#ifndef I3StationHit_H
#define I3StationHit_H

#include <TObject.h>
#include <TObjArray.h>

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
  unsigned short fStationNumber;

  /*
    RU: I would think of a station only as a unit for triggering purposes,
        especially for low energetic air showers as a ICECUBE veto, so
        it may not need any of these:

  // signal of the station, to be computed from the signals in
  // the tank
  float fSignal;

  // time of the station, to be computed from the times in the tank
  float fTime;

  // x position of the hit, to be composed from the tank x
  float fX;

  // y postion of the hist, to be composed from the tank y
  float fY;
  */

 public:
  /**
   * constructor
   */
  I3StationHit(unsigned short station_number = 0) :
    fStationNumber( station_number ) {}
  
  /**
   * destructor
   */
  virtual ~I3StationHit() {;}

  /**
   * Get the station number
   */
  unsigned short StationNumber () const;

  /**
   * Set the station number
   */
  void StationNumber (unsigned short station_number);

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
  ClassDef(I3StationHit,1);
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
  I3StationHitMatchesStationNumber (unsigned short station_number)
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
  unsigned short fStationNumber;

};

#endif
