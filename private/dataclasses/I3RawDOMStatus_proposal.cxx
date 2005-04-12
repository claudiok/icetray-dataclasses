#include "dataclasses/I3RawDOMStatus_proposal.h"

#include "icetray/I3TrayException.h"
#include "services/I3Logging.h"
#include "dataclasses/I3Units.h"

const map<string,unsigned int>& I3RawDOMStatus_proposal::GetRawStatus() const
{
  return rawStatus_;
}

map<string,unsigned int>& I3RawDOMStatus_proposal::GetRawStatus() 
{
  return rawStatus_;
}

I3RawDOMStatus_proposal::TrigMode I3RawDOMStatus_proposal::GetTrigMode() const
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

I3RawDOMStatus_proposal::LCMode I3RawDOMStatus_proposal::GetLCMode() const
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
double I3RawDOMStatus_proposal::GetLCWindowUpPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_PRE just nanoseconds?" */
double I3RawDOMStatus_proposal::GetLCWindowDownPre() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_PRE"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_UP_POST just nanoseconds?" */
double I3RawDOMStatus_proposal::GetLCWindowUpPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_UP_Post"]) * I3Units::ns;
}

/** @todo Are the units on LOCAL_COIN_WIN_DOWN_POST just nanoseconds?" */
double I3RawDOMStatus_proposal::GetLCWindowDownPost() const
{
  return ((double)rawStatus_["LOCAL_COIN_WIN_DOWN_POST"]) * I3Units::ns;
}

I3RawDOMStatus_proposal::OnOff I3RawDOMStatus_proposal::GetStatusATWD_A() const
{
  if(rawStatus_["ATWD_SELECT"] == 0)
    return On;
  return Off;
}

I3RawDOMStatus_proposal::OnOff I3RawDOMStatus_proposal::GetStatusATWD_B() const
{
  if(rawStatus_["ATWD_SELECT"] == 1)
    return On;
  return Off;
}

I3RawDOMStatus_proposal::OnOff I3RawDOMStatus_proposal::GetStatusFADC() const
{
  if(rawStatus_["NUM_FADC_SAMPLES"] > 0)
    return On;
  return Off;
}

double I3RawDOMStatus_proposal::GetPMTHV() const
{
  return 0.5 * (double)rawStatus_["PMT_HV_DAC"] * I3Units::volt;
}

/** 
 *@todo Now I _KNOW_ this isn't right.  There should be some
 * transformation of the raw DAQ value here.  Gotta look up that transformation.
 * Kael sent it to me, but I can't find it now. 
 */
double I3RawDOMStatus_proposal::GetSingleSPEThreshold() const
{
  return (double)rawStatus_["DAC_SINGLE_SPE_THRESH"];
}
