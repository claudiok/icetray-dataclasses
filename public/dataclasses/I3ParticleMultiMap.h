/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3ParticleMultiMap.h,v 1.4 2005/01/24 23:17:44 ehrlich Exp $
 *
 * @file I3ParticleMultiMap.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/01/24 23:17:44 $
 * @author ehrlich
 */

#ifndef I3MCPARTICLEMULTIMAP_H
#define I3MCPARTICLEMULTIMAP_H

#include "I3Particle.h"
#include "StoragePolicy.h"

/**
 * @brief A list of MC particles
 *
 * @todo figure out how to make copy and assignment private
 */
class I3ParticleMultiMap : public TObject, public MultiMapPolicy<string, I3ParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3ParticleMultiMap(){};

  /**
   * destructor
   */
  virtual ~I3ParticleMultiMap(){};

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

  // ROOT macro
  ClassDef(I3ParticleMultiMap,1);
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
typedef PtrPolicy<I3ParticleMultiMap>::ThePolicy I3ParticleMultiMapPtr;

#endif
