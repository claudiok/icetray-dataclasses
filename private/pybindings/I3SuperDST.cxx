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
}

