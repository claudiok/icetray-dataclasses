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
   double dacTrigBias;
   if(isnan(atwdQFit.quadFitC)) // Old style linear fit
     {
       log_trace("Linear fit from DOMCAL");
       double slope = atwdQFit.quadFitB;
       double intercept = atwdQFit.quadFitA;
       if(chip == 0) dacTrigBias =  status.dacTriggerBias0;
       else if(chip == 1) dacTrigBias =  status.dacTriggerBias1;
       else log_fatal ("No trigger bias for chip %ui\n",chip);

       rateCorrected = (slope * dacTrigBias + intercept)*20.;  //
       log_trace("calculated rate corrected %f MHz, for chip %d", rateCorrected, chip);
     }
   else // if not linear fit
     {
       log_trace("Quadratic Fit from DOMcal");
       
       if (atwdQFit.quadFitC == 0.0) 
	 {
	   log_warn("Found a quadratic fit with C=0.0, are you sure this is is a quadratic fit??");
	 } 
       else {                   
	 double c0 = atwdQFit.quadFitA;
	 double c1 = atwdQFit.quadFitB;
	 double c2 = atwdQFit.quadFitC;
	 if(chip == 0) dacTrigBias =  status.dacTriggerBias0;
	 else if(chip == 1) dacTrigBias =  status.dacTriggerBias1;
	 else log_fatal ("No trigger bias for chip %ui\n",chip);
	 
	 // f(MHz) = c2*dac*dac + c1*dac + c0
	 rateCorrected = (c2 * dacTrigBias * dacTrigBias + c1 * dacTrigBias + c0);
	 log_trace("I3DOMFunctions: rate corrected %f MHz, for chip %d", rateCorrected, chip);
       }                         
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
  
  if (hvgain.slope==0&&hvgain.intercept==0) {
    log_error("slope and intercept = 0");
    return NAN;
  }

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
    spemean = pmtgain *I3Units::eSI*I3Units::C; 
  }
  else {
    log_error("DOM gain is zero or NAN. Return SPE=NAN");
    spemean = NAN;
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
