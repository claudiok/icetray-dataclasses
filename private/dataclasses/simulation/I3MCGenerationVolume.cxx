/**
  copyright  (C) 2006
  the icecube collaboration
  @version $Id: I3MCGenerationVolume Rodin Porrata $
  @file I3MCGenerationVolume.cxx
  @date $Date: (Mon, June 26, 2006) $
 **/

#include <icetray/serialization.h>
#include <dataclasses/simulation/I3MCGenerationVolume.h>

I3MCGenerationVolume::~I3MCGenerationVolume() { }

I3MCGenerationVolume::I3MCGenerationVolume()
{
	type = UNKNOWN;
	
	x = 0.0;
	y = 0.0;
	z = 0.0;
	
	area = 0.0;
	length = 0.0;

	radius = 0.0;

	volume = 0.0;
}

I3MCGenerationVolume::I3MCGenerationVolume(double lx, double ly, double lz) 
{
	type = RECTANGULAR;
	
	x = lx;
	y = ly;
	z = lz;
	
	area = 0.0;
	length = 0.0;

	radius = 0.0;

	volume = lx * ly * lz;
}

I3MCGenerationVolume::I3MCGenerationVolume(double interaction_area, double length_of_cylinder )
{
	type = CYLINDRICAL;

	x = 0.0;
	y = 0.0;
	z = 0.0;

	area = interaction_area;
	length = length_of_cylinder;

	radius = 0.0;

	volume = area * length;
}

I3MCGenerationVolume::I3MCGenerationVolume(double radius_of_sphere )
{
	type = SPHERICAL;

	x = 0.0;
	y = 0.0;
	z = 0.0;

	area = 0.0;
	length = 0.0;

	radius = radius_of_sphere;

	volume = 4.0 * 3.14159265358979323846 * radius * radius * radius / 3.0;
}

double I3MCGenerationVolume::Get()
{
	return volume;
}


string I3MCGenerationVolume::GetTypeString() const
{
	switch( type ){
		case UNKNOWN: return("unknown");
		case RECTANGULAR: return("rectangular");
		case CYLINDRICAL: return("cylindrical");
		case SPHERICAL: return("spherical");
		case OTHER: return("other");
		default: return("unknown");
	}
}


template <class Archive> void I3MCGenerationVolume::serialize(Archive& ar, unsigned version)
{
  if (version>i3mcgenerationvolume_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3MCGenerationVolume class.",version,i3mcgenerationvolume_version_);

	ar & make_nvp("I3FrameObject", base_object<I3FrameObject>(*this));
	ar & make_nvp("type",type);
	ar & make_nvp("x",x);
	ar & make_nvp("y",y);
	ar & make_nvp("z",z);
	ar & make_nvp("area",area);
	ar & make_nvp("length",length);
	ar & make_nvp("radius",radius);
	ar & make_nvp("volume",volume);
}

I3_SERIALIZABLE(I3MCGenerationVolume);


