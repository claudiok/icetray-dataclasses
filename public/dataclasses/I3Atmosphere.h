/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Atmosphere.h,v 1.7 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Atmosphere.h
 * @version $Revision: 1.7 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 */
#ifndef I3ATMOSPHERE_H
#define I3ATMOSPHERE_H

#include <TObject.h>
#include <TClass.h>
#include <sstream>
#include "StoragePolicy.h"

/**
 *
 * @brief Atmospheric monitoring
 * data, like the pressure and temperature
 *
 * Units, etc. remain TBD
 */
class I3Atmosphere : public TObject
{
  float fPressure;
  float fTemperature;
  float fWindSpeed;

  public:
  /**
   * constructor
   */
  I3Atmosphere() : fPressure(0),fTemperature(0),fWindSpeed(0){}

   /**
    * destructor
    */
   virtual ~I3Atmosphere(){}

   /**
    * copy constructor just uses assignment
    */
   I3Atmosphere(const I3Atmosphere& rhs){*this = rhs;}

   /**
    * assignment is just member-wise assignment
    */
   const I3Atmosphere& operator=(const I3Atmosphere& rhs){
     if(this == &rhs) return *this;
     TObject::operator=(rhs);
     fPressure = rhs.fPressure;
     fTemperature = rhs.fTemperature;
     fWindSpeed = rhs.fWindSpeed;
     return *this;
   }

   /**
    * @return the atmospheric pressure
    */
   float GetPressure() const {return fPressure;}

   /**
    * @param pressure the new pressure for the Atmosphere
    */
   void SetPressure(float pressure){fPressure = pressure;}

   /**
    * @return the temperature
    */
   float GetTemperature() const {return fTemperature;}

  /**
   * @param temp the new Temperatrure for the atmosphere
   */
   void SetTemperature(float temp){fTemperature = temp;}

  /**
   * @return the windspeed 
   */
  float GetWindSpeed() const {return fWindSpeed;}

  /**
   * @param windspeed the new windspeed
   */
  void SetWindSpeed(float windspeed) {fWindSpeed = windspeed;}

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<" ]\n"
       <<"Pressure: "<<fPressure<<"\n"
       <<"Temperature: "<<fTemperature<<"\n"
       <<"WindSpeed: "<<fWindSpeed<<"\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  //ROOT macro
  ClassDef(I3Atmosphere,1);
};

inline ostream& operator<<(ostream& o,const I3Atmosphere& atm)
{
  atm.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Atmosphere>::ThePolicy I3AtmospherePtr;

#endif
