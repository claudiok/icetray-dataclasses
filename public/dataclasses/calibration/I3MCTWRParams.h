/**
 *
 * Definition of I3MCTWRParams class
 *
 *
 * copyright  (C) 2006
 * the IceCube collaboration
 */

#ifndef I3TWRMCPARAMS_H_INCLUDED
#define I3TWRMCPARAMS_H_INCLUDED

#include "dataclasses/Utility.h"
#include <vector>
#include <sstream>

using namespace std;


struct I3MCTWRParams
{

int stop_delay;
int DMADD_thresh;
int TWR_thresh;
double rel_sens;
int wf_type;
double afterpulse_prob;
double afterpulse_time;
double noise_rate;
double amplitude;
double cable_delay;
  I3MCTWRParams() 
  {
    stop_delay=INT_MIN;
    DMADD_thresh=INT_MIN;
    TWR_thresh=INT_MIN;
    rel_sens=NAN;
    wf_type=INT_MIN;
    afterpulse_prob=NAN;
    afterpulse_time=NAN;
    noise_rate=NAN;
    amplitude=NAN;
    cable_delay=NAN;
  }

  virtual ~I3MCTWRParams();

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3MCTWRParams);

#endif

