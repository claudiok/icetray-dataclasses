/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterResult.cxx 7629 2005-05-15 15:35:25Z pretz $
 *
 * @file jebclasses/I3FilterResult.cxx
 * @version $Revision:  $
 * @date $Date: 2005-05-15 17:35:25 +0200 (Sun, 15 May 2005) $
 */

// class header file

#include <icetray/serialization.h>
#include <dataclasses/physics/I3FilterResult.h>

// definitions


// namespace declarations


// implementation

I3FilterResult::~I3FilterResult()
{
}


template <class Archive>
void I3FilterResult::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3FrameObject",base_object<I3FrameObject>(*this));
  ar & make_nvp("conditionPassed",conditionPassed);
  ar & make_nvp("prescalePassed",prescalePassed);
}

I3_SERIALIZABLE(I3FilterResult);

I3_SERIALIZABLE(I3FilterResultMap);
