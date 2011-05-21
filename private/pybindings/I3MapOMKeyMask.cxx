
#include <dataclasses/I3MapOMKeyMask.h>
#include <icetray/python/copy_suite.hpp>

namespace bp = boost::python;

I3RecoPulseSeriesMapPtr
underhanded_apply(const I3RecoPulseSeriesMapMask& mask, const I3Frame &frame)
{
	return boost::const_pointer_cast<I3RecoPulseSeriesMap>(mask.Apply(frame));
}

void register_I3RecoPulseSeriesMapMask()
{
	void (I3RecoPulseSeriesMapMask::*set_om_all)(const OMKey&, bool) = &I3RecoPulseSeriesMapMask::Set;
	void (I3RecoPulseSeriesMapMask::*set_om_by_idx)(const OMKey&, const unsigned, bool) = &I3RecoPulseSeriesMapMask::Set;
	void (I3RecoPulseSeriesMapMask::*set_om_by_value)(const OMKey&, const I3RecoPulse&, bool) = &I3RecoPulseSeriesMapMask::Set;
	
	bp::class_<I3RecoPulseSeriesMapMask, bp::bases<I3FrameObject>,
	    I3RecoPulseSeriesMapMaskPtr>("I3RecoPulseSeriesMapMask",
	    bp::init<const I3Frame&, const std::string &>(bp::args("frame", "key")))
		.def(bp::copy_suite<I3RecoPulseSeriesMapMask>())
		.def("__and__", &I3RecoPulseSeriesMapMask::operator&)
		.def("__or__", &I3RecoPulseSeriesMapMask::operator|)
		.def("__xor__", &I3RecoPulseSeriesMapMask::operator^)
		.def("apply", &underhanded_apply, "Apply the mask to an I3Frame, returning an I3RecoPulseSeries.")
		.def("any", &I3RecoPulseSeriesMapMask::GetAnySet, "Are any of the bits set in the mask?")
		.def("all", &I3RecoPulseSeriesMapMask::GetAllSet, "Are all of the bits set in the mask?")
		.def("sum", &I3RecoPulseSeriesMapMask::GetSum, "Get the number of set bits in the mask.")
		.def("set", set_om_all, "Set/unset all bits for this OMKey.")
		.def("set", set_om_by_idx, "Set/unset the bit at this index.")
		.def("set", set_om_by_value, "Set/unset the bit corresponding to this RecoPulse.")
		.def("set_none", &I3RecoPulseSeriesMapMask::SetNone, "Unset all bits in the mask.")
	;
	
	register_pointer_conversions<I3RecoPulseSeriesMapMask>();
}
