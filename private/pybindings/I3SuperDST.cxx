/**
 * 
 *
 * copyright  (C) 2010
 * The Icecube Collaboration
 *
 * $Id: I3TableWriter.cxx 64296 2010-05-25 16:13:48Z jvansanten $
 *
 * @version $Revision$
 * @date $LastChangedDate$
 * @author Jakob van Santen <vansanten@wisc.edu> Last changed by: $LastChangedBy: jvansanten $
 */

#include "dataclasses/payload/I3SuperDST.h"

#include "dataclasses/payload/I3SuperDSTTrigger.h"
#include "dataclasses/status/I3DetectorStatus.h"

namespace bp = boost::python;

void
register_I3SuperDST()
{
	bp::class_<I3SuperDST, I3SuperDSTPtr, bp::bases<I3FrameObject> >(
	    "I3SuperDST", bp::no_init)
		.def(bp::init<const I3RecoPulseSeriesMap &>(bp::args("pulses")))	
		.def("unpack", &I3SuperDST::Unpack, bp::args("self"), "Unpack the compressed event data "
		    "into I3RecoPulses.")
	        .def( freeze() )
		#define RO_PROPS (EncodedSizes)
		BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3SuperDST, RO_PROPS)
		#undef RO_PROPS
		;
	register_pointer_conversions<I3SuperDST>();
	
	bp::class_<I3SuperDSTTriggerSeries, I3SuperDSTTriggerSeriesPtr, bp::bases<I3FrameObject> >(
	    "I3SuperDSTTriggerSeries", bp::no_init)
		.def(bp::init<const I3TriggerHierarchy &, const I3DetectorStatus &>(bp::args("triggers"), "status"))
		.def("unpack", &I3SuperDSTTriggerSeries::Unpack, bp::args("self"), "status", "Unpack the compressed event data "
		    "into I3Triggers.")
		.def( freeze() )
	;
	register_pointer_conversions<I3SuperDSTTriggerSeries>();
}

