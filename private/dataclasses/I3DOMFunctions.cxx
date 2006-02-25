/**
 * copyright  (C) 2006
 * the icecube collaboration
 * @version $Id:  $
 * @file I3DOMFunctions.cxx
 * @date $Date: $
 */


#include "dataclasses/I3DOMFunctions.h"
#include "dataclasses/I3Units.h"

double ATWDSamplingRate ( unsigned int chip,
			  const I3DOMStatus& status, 
			  const I3DOMCalibration& calib)
{
   double rateCorrected=0; //sampling rate in MHz
   const QuadraticFit atwdQFit  = calib.GetATWDFreqFit(chip);
   if(isnan(atwdQFit.quadFitC)) // Old style linear fit
     {
       double dacTrigBias;
       double slope = atwdQFit.quadFitB;
       double intercept = atwdQFit.quadFitA;
       if(chip == 0) dacTrigBias =  status.dacTriggerBias0;
       else if(chip == 1) dacTrigBias =  status.dacTriggerBias1;
       else log_fatal ("No trigger bias for chip %ui\n",chip);

       rateCorrected = (slope * dacTrigBias + intercept)*20.;  //
       log_trace("calculated rate corrected %f MHz, for chip %d", rateCorrected, chip);
     }
   else
     {
       log_error("Quadratic fit found.  I need to be implemented!!");
       // @todo implement this
       rateCorrected = 0.0;
     }
   return rateCorrected / I3Units::microsecond;
}

double PMTGain (const I3DOMStatus& status , 
		const I3DOMCalibration& calib)
{
  double log_gain = 0.0;
  double thegain = 0.0;
  double currentVoltage=(status.pmtHV/I3Units::volt);
  const LinearFit hvgain = calib.GetHVGainFit();
  
  if(currentVoltage >0.0)
    {
      log_gain = hvgain.slope*log10(currentVoltage) + hvgain.intercept;
      thegain = pow(10.0,log_gain);
      
      log_trace("LOOK: pmt gain %f",thegain);
    }
  else
    {
      log_warn("DOM voltage is zero.  No Gain possible");
      
    }
  return thegain;
}

double SPEMean (const I3DOMStatus& status , 
		const I3DOMCalibration& calib)
{
  double spemean = 0.0;

  //First use PMTGain() to get the gain
  double pmtgain = PMTGain(status,calib);
  if(pmtgain>0.0) {
    spemean = pmtgain *I3Units::eSI*I3Units::pC; 
  }
  else {
    log_warn("DOM gain is zero.  SPE also zero");
    spemean = 0.0;
  }
  return spemean;
}

double FADCBaseline (const I3DOMStatus& status , 
		     const I3DOMCalibration& calib)
{
  const LinearFit fadcbase = calib.GetFADCBaselineFit();
  double dacFADCRef = status.dacFADCRef;
  
  double baseline = fadcbase.slope * dacFADCRef + fadcbase.intercept;

  return baseline;
}
