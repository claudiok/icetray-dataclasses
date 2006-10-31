/**
 * (c) 2005
 * the IceCube Collaboration
 * $Id:  $
 *
 * @file I3TWRLaunch.cxx
 * @brief implementation of the I3TWRLaunch class
 * @version $Revision:  $
 * @date $Date:  $
 * @author tschmidt
 */
 
// class header file

#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3TWRLaunch.h>

// namespace declarations


// implementation

I3TWRLaunch::~I3TWRLaunch()
{
}


template<class Archive> 
void 
I3TWRLaunch::serialize (Archive& ar, unsigned version)
{
  ar & make_nvp("Baseline", baseline_);
  ar & make_nvp("Fragments", fragments_);
}


I3_SERIALIZABLE(I3TWRLaunch);
I3_SERIALIZABLE(I3TWRLaunchSeries);
I3_SERIALIZABLE(I3TWRLaunchSeriesMap);
