
#include <icetray/serialization.h>
#include <dataclasses/I3Matrix.h>

template <typename Archive>
void
I3Matrix::serialize(Archive &ar, unsigned int version)
{	
	ar & icecube::serialization::make_nvp("I3FrameObject", icecube::serialization::base_object<I3FrameObject>(*this));
	ar & icecube::serialization::make_nvp("Matrix", icecube::serialization::base_object<ublas_matrix_shim>(*this));
}

I3_SERIALIZABLE(ublas_storage_shim);
I3_SERIALIZABLE(ublas_matrix_shim);
I3_SERIALIZABLE(I3Matrix);
