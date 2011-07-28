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
#include "dataclasses/physics/I3RecoPulse.h"

namespace bp = boost::python;

bp::object
Unpack(const I3SuperDST &self)
{
	I3RecoPulseSeriesMapPtr hlc_pulses;
	I3RecoPulseSeriesMapPtr slc_pulses;
	bool success;
	
	success = self.Unpack(hlc_pulses, slc_pulses);
	
	if (success)
		return bp::make_tuple(hlc_pulses, slc_pulses);
	else
		return bp::object(); /* Py_None */
}

void
register_I3SuperDST()
{
	bp::class_<I3SuperDST, I3SuperDSTPtr, bp::bases<I3FrameObject> >(
	    "I3SuperDST", bp::no_init)
		.def(bp::init<const I3RecoPulseSeriesMap &,
		    const I3RecoPulseSeriesMap &>(bp::args("hlc_pulses", "slc_pulses")))
		.def("Unpack", &Unpack, bp::args("self"), "Unpack the compressed event data "
		    "into I3RecoPulses. Returns a tuple (HLC pulses, SLC pulses).")
	        .def( freeze() )
		#define RO_PROPS (SubEvents)
		BOOST_PP_SEQ_FOR_EACH(WRAP_PROP_RO, I3SuperDST, RO_PROPS)
		#undef RO_PROPS
		;
}

