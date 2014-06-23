/**
 *  $Id$
 *
 *  Specializations of I3Frame::Get() that perform format
 *  conversions behind the scenes for MapOMKeyMasks and Unions
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  Marcel Zoll <marcel.zoll@fysik.su.se>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#include <icetray/I3Frame.h>
#include <icetray/I3Units.h>
#include <dataclasses/I3MapOMKeyMask.h>
#include <dataclasses/I3MapOMKeyUnion.h>
#include <dataclasses/physics/I3RecoHit.h>
#include <dataclasses/physics/I3RecoPulse.h>
#include <dataclasses/payload/I3SuperDST.h>
#include <dataclasses/payload/I3SuperDSTTrigger.h>
#include <dataclasses/physics/I3Trigger.h>
#include <dataclasses/status/I3DetectorStatus.h>

static I3RecoPulseSeriesMapPtr HitsAsPulses(I3RecoHitSeriesMapConstPtr hits);

/*
 * Only a little bit evil: Specialize the I3Frame::Get() to apply
 * a mask behind the scenes. This lets client code treat masks
 * and SuperDST payloads (and masked SuperDST payloads)
 * just like I3RecoPulseSeriesMaps.
 */ 
template <>
I3RecoPulseSeriesMapConstPtr
I3Frame::Get(const std::string& name, bool quietly, void*, void*) const
{
	I3FrameObjectConstPtr focp = this->Get<I3FrameObjectConstPtr>(name, quietly);
	
	I3RecoPulseSeriesMapConstPtr pulses =
	    dynamic_pointer_cast<const I3RecoPulseSeriesMap>(focp);
	
	if (!focp || pulses)
		return pulses;
	
	I3RecoPulseSeriesMapMaskConstPtr mask = 
	    dynamic_pointer_cast<const I3RecoPulseSeriesMapMask>(focp);
	
	if (mask)
		return mask->Apply(*this); 
		
	I3RecoPulseSeriesMapUnionConstPtr uni = 
	    dynamic_pointer_cast<const I3RecoPulseSeriesMapUnion>(focp);

	if (uni)
		return uni->Apply(*this);
	
	I3SuperDSTConstPtr superdst = 
	    dynamic_pointer_cast<const I3SuperDST>(focp);
	
	if (superdst)
		return superdst->Unpack();

	// Compatibility with old data
	I3RecoHitSeriesMapConstPtr hits = 
	    dynamic_pointer_cast<const I3RecoHitSeriesMap>(focp);

	if (hits)
		return HitsAsPulses(hits);
	else
		return pulses;
}

static I3RecoPulseSeriesMapPtr
HitsAsPulses(I3RecoHitSeriesMapConstPtr hits)
{
	I3RecoPulseSeriesMapPtr pulses(new I3RecoPulseSeriesMap);

	for (I3RecoHitSeriesMap::const_iterator i = hits->begin();
	    i != hits->end(); i++) {
		I3RecoPulseSeries &ps = (*pulses)[i->first];
		
		for (I3RecoHitSeries::const_iterator j = i->second.begin();
		    j != i->second.end(); j++) {
			I3RecoPulse pulse;
			pulse.SetTime(j->GetTime());
			pulse.SetCharge(1.0 /* PE */);
			pulse.SetWidth(3.3 * I3Units::ns /* Avg. ATWD bin */);
			ps.push_back(pulse);
		}
	}

	return pulses;
}


///Cheat by pretemplating this
template<class Response>
boost::shared_ptr <const I3Map<OMKey, std::vector<Response> > >
GetMaskable(const I3Frame *frame, const std::string& name, bool quietly)
{
  I3FrameObjectConstPtr focp = frame->Get<I3FrameObjectConstPtr>(name, quietly);
  
  boost::shared_ptr <const I3Map<OMKey, std::vector<Response> > > pulses =
      dynamic_pointer_cast<const I3Map<OMKey, std::vector<Response> > >(focp);
  
  if (!focp || pulses)
    return pulses;
  
  boost::shared_ptr <const I3MapOMKeyMask<Response> > mask = 
      dynamic_pointer_cast<const I3MapOMKeyMask<Response> >(focp);
  
  if (mask)
    return mask->Apply(*frame); 
  
  boost::shared_ptr <const I3MapOMKeyUnion<Response> > uni = 
      dynamic_pointer_cast<const I3MapOMKeyUnion<Response> >(focp);

  if (uni)
    return uni->Apply(*frame);
  
  return pulses;
}


template <> 
I3MCHitSeriesMapConstPtr
I3Frame::Get(const std::string& name, bool quietly, void*, void*) const
{
  return GetMaskable<I3MCHit>(this, name, quietly);
}

//======================= specialize I3TriggerHierachy =========
/*
 * specialize I3TriggerHierachy:
 * resolve duality of SuperDST and conventional TriggerHieracachy
 */
template <>
I3TriggerHierarchyConstPtr
I3Frame::Get(const std::string& name, bool quietly, void*, void*) const
{
	I3FrameObjectConstPtr focp = this->Get<I3FrameObjectConstPtr>(name, quietly);

	I3TriggerHierarchyConstPtr triggers =
	    dynamic_pointer_cast<const I3TriggerHierarchy>(focp);
	if (triggers)
		return triggers;
	
	I3SuperDSTTriggerSeriesConstPtr sdst =
	    dynamic_pointer_cast<const I3SuperDSTTriggerSeries>(focp);
	I3DetectorStatusConstPtr status =
	    this->Get<I3DetectorStatusConstPtr>();
	if (sdst && !status)
		log_fatal("Can't decode SuperDST triggers without an I3DetectorStatus!");
	else if (sdst && status)
		return sdst->Unpack(*status);
	
	return triggers;
}




