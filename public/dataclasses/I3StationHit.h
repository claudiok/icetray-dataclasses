/**
    $Id: I3StationHit.h,v 1.1 2004/07/13 15:37:53 niessen Exp $
    @file I3StationHit.h
    @version $Revision: 1.1 $
    @date Fri Jul  9 21:16:58 EDT 2004
    @author rulrich
*/
#ifndef I3StationHit_H
#define I3StationHit_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3TankHit.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Station Hit-related data in an array
 *
 */
class I3StationHit : public TObject, 
	 public VecPointainerPolicy<I3TankHitPtr>::ThePolicy {

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
   * Get the signal of the station
   */
  //Float_t Signal  () const;

  /**
   * Set the signal of the station
   */
  //void Signal (Float_t signal);

  /**
   * Get the time of the station
   */
  //Float_t Time () const;

  /**
   * Set the time of the station
   */
  //void Time (Float_t time);

  /**
   * Get the X of the station hit
   */
  //Float_t X () const;
  
  /**
   * Set the X of the station hit
   */
  //void X (Float_t x);

  /**
   * Get the Y of the station hit
   */
  //Float_t Y () const;
  
  /**
   * Set the Y of the station hit
   */
  //void Y (Float_t y);

 private:
  // copy and assignment are private
  I3StationHit(const I3StationHit&); 
  const I3StationHit& operator=(const I3StationHit&); 

  // ROOT macro
  ClassDef(I3StationHit,1);
};

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
