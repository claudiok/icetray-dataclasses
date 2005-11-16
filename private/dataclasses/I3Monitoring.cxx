#include "dataclasses/I3Monitoring.h"

float I3Monitoring::GetTempCelcius() const
{
    float temp;
    if (temperature_>32767)
    {
        temp = ((float)temperature_ - 65536)/256.0;
    }
    else
    {
        temp = ((float)temperature_)/256.0;
    }
    return temp;
}

int I3Monitoring::GetTempRaw() const
{
    return temperature_;
}

float I3Monitoring::GetSPEScalerHz() const
{
    float spe = (float)(SPE_Scaler_)/0.9;
    return spe;
}

int I3Monitoring::GetSPEScalerRaw() const
{
    return SPE_Scaler_;
}

float I3Monitoring::GetMPEScalerHz() const
{
    float mpe = (float)(MPE_Scaler_)/0.9;
    return mpe;
}

int I3Monitoring::GetMPEScalerRaw() const
{
    return MPE_Scaler_;
}

void I3Monitoring::SetTemperatureRaw(int temp) 
{
    temperature_ = temp;
}

void I3Monitoring::SetSPEScalerRaw(int spe) 
{
    SPE_Scaler_ = spe;
}

void I3Monitoring::SetMPEScalerRaw(int mpe)
{
    MPE_Scaler_ = mpe;
}
