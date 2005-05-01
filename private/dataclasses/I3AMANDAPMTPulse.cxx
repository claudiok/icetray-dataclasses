#include <cmath>
#include <math.h>
#include "dataclasses/I3AMANDAPMTPulse.h"

double I3AMANDAPMTPulse::GetVoltage(const double time) 
{
  double t             = (time-timeZero_) / I3Units::ns;               //need to convert into explicite units
  double normalization = normalization_ / (I3Units::ns * I3Units::V);  //since the formula below requires explicite units

  return(t>0 ? 
	 - I3Units::V * normalization * norm_ 
	 * ( weight_/(sqrt(2*pi*stdDev1_*stdDev1_)) * (1/t)
	     * exp(-(log(t)-mu1_)*(log(t)-mu1_)/(2*stdDev1_*stdDev1_))
	     - (1-weight_)/(sqrt(2*pi*stdDev2_*stdDev2_)) * (1/t)
	     * exp(-(log(t)-mu2_)*(log(t)-mu2_)/(2*stdDev2_*stdDev2_)) )
	 + pedestal_ : 0);
};

double I3AMANDAPMTPulse::GetPeakTime() 
{
  double t = timeZero_ / I3Units::ns;  //need to convert into explicite units
  //since the formula below requires explicite units
    
  //get the peak time for the first term, the peak for the entire formula should be close to it
  double t1 = t + exp(stdDev1_*stdDev1_ + mu1_);  //this value is in ns
    
  double v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
  double v_at_t1     = GetVoltage((t1)*I3Units::ns);
  double v_after_t1  = GetVoltage((t1+1)*I3Units::ns);

  if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);

  if(v_at_t1 > v_before_t1)
    {
      for(int i=0; i<10000; i++)
	{
	  t1--;
	  v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
	  v_at_t1     = GetVoltage((t1)*I3Units::ns);
	  v_after_t1  = GetVoltage((t1+1)*I3Units::ns);
	  if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);
	}
      return(NAN);   //didn't find peak within 10000ns
    }

  if(v_at_t1 < v_before_t1)
    {
      for(int i=0; i<10000; i++)
	{
	  t1++;
	  v_before_t1 = GetVoltage((t1-1)*I3Units::ns);
	  v_at_t1     = GetVoltage((t1)*I3Units::ns);
	  v_after_t1  = GetVoltage((t1+1)*I3Units::ns);
	  if(v_at_t1 <= v_before_t1 && v_at_t1 <= v_after_t1) return(t1*I3Units::ns);
	}
      return(NAN);   //didn't find peak within 10000ns
    }

  return(NAN);   //didn't find peak
}

double I3AMANDAPMTPulse::GetPeakVoltage() 
{
  double peak = GetPeakTime();
  if (isnan(peak)) 
    return NAN;
  else
    return GetVoltage(peak);
};
