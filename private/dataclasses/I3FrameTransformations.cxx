/**
 *  $Id$
 *
 *  Specializations of I3Frame::Get() that perform format
 *  conversions behind the scenes.
 *  
 *  Copyright (C) 2011
 *  Jakob van Santen <vansanten@wisc.edu>
 *  and the IceCube Collaboration <http://www.icecube.wisc.edu>
 *  
 */

#include "icetray/I3Frame.h"
#include "dataclasses/I3MapOMKeyMask.h"
#include "dataclasses/physics/I3RecoPulse.h"
#include "dataclasses/payload/I3SuperDST.h"

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
	
	I3SuperDSTConstPtr superdst = 
	    dynamic_pointer_cast<const I3SuperDST>(focp);
	
	if (superdst)
		return superdst->Unpack();
	else
		return pulses;
}
