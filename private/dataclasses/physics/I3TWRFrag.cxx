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

#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3TWRFrag.h>

// namespace declarations


// implementation

I3TWRFrag::~I3TWRFrag()
{
}


template<class Archive>
void 
I3TWRFrag::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("StartBin", startBin_);
  ar & make_nvp("RawFADC", rawFADC_);
}


I3_SERIALIZABLE(I3TWRFrag);
