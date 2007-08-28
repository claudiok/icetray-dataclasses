/**
 * (c) 2005
 * the IceCube Collaboration
 * $Id:  $
 *
 * @file I3TWRFrag.cxx
 * @brief implementation of the I3TWRFrag class
 * @version $Revision:  $
 * @date $Date:  $
 * @author tschmidt
 */
 
// class header file

#include <icetray/serialization.h>
#include <dataclasses/physics/I3TWRFrag.h>

#include <math.h>

// namespace declarations


// implementation

I3TWRFrag::~I3TWRFrag()
{
}


template<class Archive>
void 
I3TWRFrag::serialize(Archive& ar, unsigned version)
{
  if (version>i3twrfrag_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3TWRFrag class.",version,i3twrfrag_version_);

  if(version < 1)
  {
    int id;
    ar & make_nvp("ID", id);
    int parentId;
    ar & make_nvp("ParentID", parentId);
    double fragStartTime;
    ar & make_nvp("FragStartTime", fragStartTime);

    int fragStartBin;
    ar & make_nvp("FragStartBin", fragStartBin);
    if(fragStartBin < 0) log_fatal("invalid start bin");
    startBin_ = static_cast<unsigned int>(fragStartBin);
    
    vector<double> waveform;
    ar & make_nvp("Waveform", waveform);
    rawFADC_.resize(waveform.size());
    for(unsigned int i = 0; i < waveform.size(); ++i)
    {
      waveform[i] = round(waveform[i]);
      if(waveform[i] < 0) log_fatal("invalid waveform value");
      rawFADC_[i] = static_cast<unsigned int>(waveform[i]);
    }
  }
  else
  {
    ar & make_nvp("StartBin", startBin_);
    ar & make_nvp("RawFADC", rawFADC_);
  }
}


I3_SERIALIZABLE(I3TWRFrag);
