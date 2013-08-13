#include <dataclasses/physics/I3ParticleID.h>
#include <dataclasses/physics/I3Particle.h>
#include <icetray/python/dataclass_suite.hpp>
#include <boost/python/implicit.hpp>
#include <boost/python/operators.hpp>

using namespace boost::python;

void register_I3ParticleID()
{
	class_<I3ParticleID, boost::shared_ptr<I3ParticleID> >("I3ParticleID")
	.def_readwrite("majorID",&I3ParticleID::majorID)
	.def_readwrite("minorID",&I3ParticleID::minorID)
	.def(dataclass_suite<I3ParticleID>())
	//.def(self == self)
	//.def("__eq__",&I3ParticleID::operator==)
	;
	implicitly_convertible<I3Particle,I3ParticleID>();
}
