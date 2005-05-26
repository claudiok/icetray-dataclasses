#include "dataclasses/I3TestDaqRawDOMStatus.h"

#include "services/I3Logging.h"
#include "dataclasses/I3Units.h"

const map<string,unsigned int>& I3TestDaqRawDOMStatus::GetRawStatus() const
{
  return rawStatus_;
}

map<string,unsigned int>& I3TestDaqRawDOMStatus::GetRawStatus() 
{
  return rawStatus_;
}

I3RawDOMStatus::TrigMode I3TestDaqRawDOMStatus::GetTrigMode() const
{
  switch(rawStatus_["TRIG_MODE"])
    {
    case 0:
      return TestPattern;
      break;
    case 1:
      return CPU;
      break;
    case 2:
      return SPE;
      break;
    default:
      log_fatal("unknown 'TRIG_MODE' setting");
    }
}

I3RawDOMStatus::LCMode I3TestDaqRawDOMStatus::GetLCMode() const
{
  switch(rawStatus_["LOCAL_COIN_MODE"])
    {
    case 0:
      return LCOff;
      break;
    case 1:
      return UpOrDown;
      break;
    case 2:
      return Up;
      break;
    case 3:
      return Down;
      break;
    case 4:
      return UpAndDown;
      break;
    default:
      log_fatal("unknown 'LOCAL_COIN_MODE' setting");
    }
}

/** @todo Are the units on LOCAL_COIN_WIN_UP_PRE just nanoseconds?" */
double I3TestDaqRawDOMStatus::GetLCWindowUpPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_PRE just nanoseconds?" */
double I3TestDaqRawDOMStatus::GetLCWindowDownPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_UP_POST just nanoseconds?" */
double I3TestDaqRawDOMStatus::GetLCWindowUpPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_Post"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_POST just nanoseconds?" */
double I3TestDaqRawDOMStatus::GetLCWindowDownPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_POST"]) * I3Units::ns;
}

I3RawDOMStatus::OnOff I3TestDaqRawDOMStatus::GetStatusATWD_A() const
{
  if(rawStatus_["ATWD_SELECT"] == 0)
    return On;
  return Off;
}

I3RawDOMStatus::OnOff I3TestDaqRawDOMStatus::GetStatusATWD_B() const
{
  if(rawStatus_["ATWD_SELECT"] == 1)
    return On;
  return Off;
}

I3RawDOMStatus::OnOff I3TestDaqRawDOMStatus::GetStatusFADC() const
{
  if(rawStatus_["NUM_FADC_SAMPLES"] > 0)
    return On;
  return Off;
}

double I3TestDaqRawDOMStatus::GetPMTHV() const
{
  return 0.5 * (double)rawStatus_["PMT_HV_DAC"];// * I3Units::volt;
}

/** 
 * @todo don't even ask me where this comes from.  I don't have the foggiest 
 * idea.  It's cut-and-pasted from Dima's code. Need to link
 * tis to some daq documentation so that we know it's right...
 */
double I3TestDaqRawDOMStatus::GetSingleSPEThreshold() const
{
  //  return (double)rawStatus_["DAC_SINGLE_SPE_THRESH"];
  double raw_spe_thresh = (double)rawStatus_["DAC_SINGLE_SPE_THRESH"];
  return (5.*raw_spe_thresh/1024.- GetFEPedestal())/(9.6*(1+2200./249.));

}

/**
 * @todo These 'magic numbers' come from conversion from DAC om mainboard units
 * to something sensible.  They are currently gleaned from Dima's code
 * and it would be good to verify them from some document somewhere.
 */
double I3TestDaqRawDOMStatus::GetFEPedestal() const
{
  return 5.0 * ((double)rawStatus_["DAC_PMT_FE_PEDESTAL"])/4096.;
}

double I3TestDaqRawDOMStatus::GetDACTriggerBias(int chip) const
{
    if(chip==0) return (double)rawStatus_["DAC_ATWD0_TRIGGER_BIAS"];
    else if(chip==1) return (double)rawStatus_["DAC_ATWD1_TRIGGER_BIAS"];
    else return 0;
}