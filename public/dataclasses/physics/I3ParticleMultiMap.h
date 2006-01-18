/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3ParticleMultiMap.h
 * @date $Date$
 */

#ifndef I3MCPARTICLEMULTIMAP_H_INCLUDED
#define I3MCPARTICLEMULTIMAP_H_INCLUDED

#include "I3Particle.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3Map.h"

/**
 * @brief A list of MC particles
 *
 * @todo figure out how to make copy and assignment private
 */
class I3ParticleMultiMap : public I3Map<string, I3ParticlePtr>
{
 public:

  I3ParticleMultiMap(){};

  virtual ~I3ParticleMultiMap();

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3OMResponseMap: ]\n";
      I3ParticleMultiMap::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<iter->first;
	  if(iter->second==I3ParticlePtr((I3Particle*)0))
	    o<<"Null I3Particle";
	  else
	    o<<*(iter->second);
	}
      o<<"\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

};

inline ostream& operator<<(ostream& o,const I3ParticleMultiMap& rhs)
{
  rhs.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3ParticleMultiMap>  I3ParticleMultiMapPtr;

#endif //I3MCPARTICLEMULTIMAP_H_INCLUDED

