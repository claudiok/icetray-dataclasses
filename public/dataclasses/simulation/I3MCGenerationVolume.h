/**
  copyright  (C) 2006
  the icecube collaboration
  @version $Id: I3MCGenerationVolume Rodin Porrata $
  @file I3MCGenerationVolume.h
  @date $Date: (Mon, June 26, 2006) $
 **/
#ifndef DATACLASSES_I3_MC_GENERATION_VOLUME_H_INCLUDED
#define DATACLASSES_I3_MC_GENERATION_VOLUME_H_INCLUDED

#include "icetray/I3FrameObject.h"
#include <dataclasses/Utility.h>
#include <string>

class I3MCGenerationVolume : public I3FrameObject
{

  public:
	  enum VolumeType { UNKNOWN, RECTANGULAR, CYLINDRICAL, SPHERICAL, OTHER };

  private:
	  
	  int type;

	  double x;
	  double y;
	  double z;

	  double area;
	  double length;

	  double radius;

	  double volume;

  public:
	  I3MCGenerationVolume();
	  I3MCGenerationVolume(double x, double y, double z);
	  I3MCGenerationVolume(double area, double length_of_cylinder );
	  I3MCGenerationVolume(double radius_of_sphere );
	  I3MCGenerationVolume(const I3MCGenerationVolume&);
	  I3MCGenerationVolume& operator=(const I3MCGenerationVolume&);

	  double Get();
	  string GetTypeString() const;

	  virtual ~I3MCGenerationVolume();
	  
  private: 
	  friend class boost::serialization::access;
	  template <typename Archive> void serialize(Archive & ar, unsigned version);

};

I3_POINTER_TYPEDEFS(I3MCGenerationVolume);


#endif
