/**
 * copyright  (C) 2005
 * the icecube collaboration
 *
 * @file I3Monitoring.h
 */

#ifndef I3MONITORING_H_INCLUDED
#define I3MONITORING_H_INCLUDED

#include <iostream>
#include "dataclasses/StoragePolicy.h"

using namespace std;

/**
 * @brief Class to represent the contents of DOM monitoring records
 */

class I3Monitoring 
{
 public:
    virtual ~I3Monitoring();
    float GetTempCelcius() const ;
    int GetTempRaw() const;
    float GetSPEScalerHz() const ;
    int GetSPEScalerRaw() const ;
    float GetMPEScalerHz() const;
    int GetMPEScalerRaw() const;

    void SetTemperatureRaw(int);
    void SetSPEScalerRaw(int);
    void SetMPEScalerRaw(int);

 private:
    /** I store the temperature, SPE_Scaler and MPE_Scaler in the
	DAQ format.
	Presently Temp is an unsigned int from 0 to 65535. 
	SPE_Scaler and MPE_scaler are counts per 0.9 seconds.
     */
    int temperature_;
    int SPE_Scaler_;
    int MPE_Scaler_;

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("temperature",temperature_);
    ar & make_nvp("SPE_Scaler",SPE_Scaler_);
    ar & make_nvp("MPE_Scaler",MPE_Scaler_);
  }

};

inline ostream& operator<<(ostream& o, const I3Monitoring& m)
{
  o<<"[ I3Monitoring: \n"
   <<"Temperature: "<<m.GetTempCelcius()<<" C\n"
   <<"SPE Scaler: "<<m.GetSPEScalerHz()<<" Hz\n"
   <<"MPE Scaler: "<<m.GetMPEScalerHz()<<" Hz ]\n"; 
  return o;
}

typedef shared_ptr<I3Monitoring> I3MonitoringPtr;

#endif //I3MONITERING_H_INCLUDED
