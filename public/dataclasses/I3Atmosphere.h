#ifndef I3ATMOSPHERE_H
#define I3ATMOSPHERE_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Atmosphere.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 * I3Atmosphere is a class that stores atmospheric monitoring
 * data, like the pressure and temperature
 * Units, etc. remain TBD
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 *
 * @todo 
 */

#include <TObject.h>

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
   Float_t Pressure() const {return fPressure;}

   /**
    * @param pressure the new pressure for the Atmosphere
    */
   void Pressure(Float_t pressure){fPressure = pressure;}

   /**
    * @return the temperature
    */
   float Temperature() const {return fTemperature;}

  /**
   * @param temp the new Temperatrure for the atmosphere
   */
   void Temperature(float temp){fTemperature = temp;}

  /**
   * @return the windspeed 
   */
  Float_t WindSpeed() const {return fWindSpeed;}

  /**
   * @param windspeed the new windspeed
   */
  void WindSpeed(Float_t windspeed) {fWindSpeed = windspeed;}

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
