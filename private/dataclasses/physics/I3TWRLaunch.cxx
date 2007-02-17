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

#include <icetray/serialization.h>
#include <dataclasses/physics/I3TWRLaunch.h>

#include <math.h>

// namespace declarations


// implementation

I3TWRLaunch::~I3TWRLaunch()
{
}


template<class Archive> 
void 
I3TWRLaunch::serialize (Archive& ar, unsigned version)
{
  if(version < 1)
  {
    I3Vector<I3TWRFrag> tmp;
    ar & make_nvp("I3TWRLaunch", tmp);
    fragments_.swap(tmp);
  
    int id;
    ar & make_nvp("ID", id);
    double binSize;
    ar & make_nvp("BinSize", binSize);

    double baseline;
    ar & make_nvp("Baseline", baseline);
    baseline = round(baseline);
    if(baseline < 0) log_fatal("invalid baseline value");
    baseline_ = static_cast<unsigned int>(baseline);

    int stopDelay;
    ar & make_nvp("StopDelay", stopDelay);
    int threshold;
    ar & make_nvp("Threshold", threshold);
    bool optical;
    ar & make_nvp("Optical", optical);
  }
  else
  {
    ar & make_nvp("Baseline", baseline_);
    ar & make_nvp("Fragments", fragments_);
  }
}


I3_SERIALIZABLE(I3TWRLaunch);
I3_SERIALIZABLE(I3TWRLaunchSeriesMap);
