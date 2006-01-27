#include <dataclasses/BoostHeaders.h>
#include <dataclasses/physics/I3RecoPulseSeries.h>

I3RecoPulseSeries::~I3RecoPulseSeries(){}

template <class Archive> 
void 
I3RecoPulseSeries::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("I3RecoPulseSeries", base_object< I3Vector<I3RecoPulse> >(*this));
}

  

I3_SERIALIZABLE(I3RecoPulseSeries);
