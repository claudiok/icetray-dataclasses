/**
 * copyright  (C) 2005
 * the icecube collaboration
 *
 * @file I3Monitoring.h
 * @author pretz
 * @author Taboada
 */

#ifndef I3MONITORING_H
#define I3MONITORING_H

/**
 * @brief Class to represent the contents of DOM monitoring records
 */

class I3Monitoring 
{
 public:
    float GetTempCelcius();
    int GetTempRaw();
    float GetSPEScalerHz();
    int GetSPEScalerRaw();
    float GetMPEScalerHz();
    int GetMPEScalerRaw();

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
};

typedef shared_ptr<I3Monitoring> I3MonitoringPtr;

#endif
