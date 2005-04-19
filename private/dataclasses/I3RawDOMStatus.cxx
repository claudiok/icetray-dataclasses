#include "dataclasses/I3RawDOMStatus.h"

#include "icetray/I3TrayException.h"
#include "services/I3Logging.h"
#include "dataclasses/I3Units.h"

const map<string,unsigned int>& I3RawDOMStatus::GetRawStatus() const
{
  return rawStatus_;
}

map<string,unsigned int>& I3RawDOMStatus::GetRawStatus() 
{
  return rawStatus_;
}

I3RawDOMStatus::TrigMode I3RawDOMStatus::GetTrigMode() const
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
      throw I3TrayException();
    }
}

I3RawDOMStatus::LCMode I3RawDOMStatus::GetLCMode() const
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
      throw I3TrayException();
    }
}

/** @todo Are the units on LOCAL_COIN_WIN_UP_PRE just nanoseconds?" */
double I3RawDOMStatus::GetLCWindowUpPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_PRE just nanoseconds?" */
double I3RawDOMStatus::GetLCWindowDownPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_UP_POST just nanoseconds?" */
double I3RawDOMStatus::GetLCWindowUpPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_Post"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_POST just nanoseconds?" */
double I3RawDOMStatus::GetLCWindowDownPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_POST"]) * I3Units::ns;
}

I3RawDOMStatus::OnOff I3RawDOMStatus::GetStatusATWD_A() const
{
  if(rawStatus_["ATWD_SELECT"] == 0)
    return On;
  return Off;
}

I3RawDOMStatus::OnOff I3RawDOMStatus::GetStatusATWD_B() const
{
  if(rawStatus_["ATWD_SELECT"] == 1)
    return On;
  return Off;
}

I3RawDOMStatus::OnOff I3RawDOMStatus::GetStatusFADC() const
{
  if(rawStatus_["NUM_FADC_SAMPLES"] > 0)
    return On;
  return Off;
}

double I3RawDOMStatus::GetPMTHV() const
{
  return 0.5 * (double)rawStatus_["PMT_HV_DAC"] * I3Units::volt;
}

/** 
 *@todo Now I _KNOW_ this isn't right.  There should be some
 * transformation of the raw DAQ value here.  Gotta look up that transformation.
 * Kael sent it to me, but I can't find it now. 
 */
double I3RawDOMStatus::GetSingleSPEThreshold() const
{
  return (double)rawStatus_["DAC_SINGLE_SPE_THRESH"];
}

/**
 * @todo These 'magic numbers' come from conversion from DAC om mainboard units
 * to something sensible.  They are currently gleaned from Dima's code
 * and it would be good to verify them from some document somewhere.
 */
double I3RawDOMStatus::GetFEPedestal() const
{
  return 5.0 * ((double)rawStatus_["DAC_PMT_FE_PEDESTAL"])/4096.;
}
