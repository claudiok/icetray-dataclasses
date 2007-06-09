/**
 *
 * @version $Id: I3VEMCalibration.h$
 * @file I3VEMCalibration.h
 * @date $Date: 2007-04-11 15:35:43 -0400 (Mi, 11 Apr 2007) $
 */

#ifndef I3VEMCALIBRATION_H_INCLUDED
#define I3VEMCALIBRATION_H_INCLUDED

#include "dataclasses/Utility.h"


/**
 * @brief This class stores the VEM (Vertical Equivalent Muon) calibration
 * data for an IceTop DOM. In addition it contains information concerning the 
 * switching between the high gain (HG) and low gain (LG) DOMs in a Tank. 
 * @author Tilo Waldenmaier 
 */

class I3VEMCalibration
{    
 public:
    I3VEMCalibration();
    virtual ~I3VEMCalibration();
  
    /**
     * Set/Get number of PE per VEM
     */
    void   SetPEperVEM(double pe)       {pePerVEM_ = pe;};
    double GetPEperVEM() const          {return pePerVEM_;};
    
    /**
     * Set/Get width of the muon peak in PE
     */
    void   SetMuonWidth(double pe)      {muPeakWidth_ = pe;};
    double GetMuonWidth() const         {return muPeakWidth_;};
    
    /**
     * Set/Get the HG-LG crossover value in PE
     */
    void   SetHGLGCrossOver(double pe)  {hglgCrossOver_ = pe;};
    double GetHGLGCrossOver() const     {return hglgCrossOver_;};
    
    /**
     * Set/Get optional correction factor
     */
    void   SetCorrFactor(double factor) {corrFactor_ = factor;};
    double GetCorrFactor() const        {return corrFactor_;};
    
    template <class Archive> void serialize(Archive & ar, unsigned version);
    
 private:
    
    /**
     * Average number of PE per VEM  
     */
    double pePerVEM_;
    
    /**
     * Width of the the average muon peak for this tank in PE
     */
    double muPeakWidth_;

    /**
     * PE threshold for the HG pulses over which the corresponding LG pulses in the tank are used.
     * (This value is only valid/important for HG DOMs) 
     */
    double hglgCrossOver_;
    
    /**
     * Optional correction factor to adjust high gain and low gain DOMs
     * (Default value is set to 1)
     */
    double corrFactor_;
    
};

I3_POINTER_TYPEDEFS(I3VEMCalibration);

#endif //I3VEMCALIBRATION_H_INCLUDED

