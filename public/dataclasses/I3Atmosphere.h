/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Atmosphere.h,v 1.3 2004/06/30 17:20:26 pretz Exp $
 *
 * @file I3Atmosphere.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/06/30 17:20:26 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 */
#ifndef I3ATMOSPHERE_H
#define I3ATMOSPHERE_H

#include <TObject.h>

/**
 *
 * @brief Atmospheric monitoring
 * data, like the pressure and temperature
 *
 * Units, etc. remain TBD
 */
class I3Atmosphere : public TObject
{
  Float_t fPressure;
  Float_t fTemperature;
  Float_t fWindSpeed;

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
   Float_t GetPressure() const {return fPressure;}

   /**
    * @param pressure the new pressure for the Atmosphere
    */
   void SetPressure(Float_t pressure){fPressure = pressure;}

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
  Float_t GetWindSpeed() const {return fWindSpeed;}

  /**
   * @param windspeed the new windspeed
   */
  void SetWindSpeed(Float_t windspeed) {fWindSpeed = windspeed;}

 private:
  //ROOT macro
  ClassDef(I3Atmosphere,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Atmosphere>::ThePolicy I3AtmospherePtr;

#endif
