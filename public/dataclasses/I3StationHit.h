/**
    $Id$
    @file I3StationHit.h
    @version $Revision: 1.9 $
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
	 public STLVectorStoragePolicy<I3TankHitPtr> {

 private:

  // the station number
  unsigned short stationNumber_;

 public:
  /**
   * constructor
   */
  I3StationHit(unsigned short station_number = 0) :
    stationNumber_( station_number ) {}
  
  /**
   * destructor
   */
  virtual ~I3StationHit() {;}

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

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version){
    ar & make_nvp("I3StationHit", 
		  base_object< STLVectorStoragePolicy<I3TankHitPtr> >(*this));
    ar & make_nvp("StationNumber",stationNumber_);

  }

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
typedef shared_ptr<I3StationHit>  I3StationHitPtr;

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

#endif
