/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Composite.h,v 1.11 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3Composite.h
 * @version $Revision: 1.11 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author pretz
 */
#ifndef I3COMPOSITE_H
#define I3COMPOSITE_H

#include "I3Particle.h"
#include "I3ParticleMultiMap.h"

/**
 * @brief This class satisfies the "Composite" part of an I3Track 
 * Implementation, 
 * representing a track that is made up of several constituents.
 * @todo What do do in copy.  Deep copy?  Needs to be implemented.
 */
class I3Composite
{
 private:
   I3ParticleMultiMap fConstituents;
 public:
  /**
   * constructor
   */
  I3Composite(){}

  /**
   * destructor
   */
  virtual ~I3Composite(){}

  /**
   * indicates that the track is composite
   */
  bool IsComposite() const {return true;}

  /**
   * retrieves the constituents that make up this track as const
   */
  const I3ParticleMultiMap& GetConstituents() const {return fConstituents;}

  /**
   * retrieves the constituents that make up this track as non-const
   */
  I3ParticleMultiMap& GetConstituents() {return fConstituents;}

  /**
   * copies this particle's data into destination if a dynamic_cast
   * succeeds
   * @param destination the particle we're copying to.
   */
  void CopyTo(I3Particle& destination) const
    {
      I3Composite* composite = dynamic_cast<I3Composite*>(&destination);
      if(composite)
	{
	  composite->fConstituents = fConstituents;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Consituents: \n";
      I3ParticleMultiMap::const_iterator iter;
      for(iter= fConstituents.begin() ; iter!= fConstituents.end() ; iter++)
	{
	  o<<iter->first<<" "<<iter->second<<"\n";
	}
    }
 private:
  // ROOT macro
  ClassDef(I3Composite,1);
};

#endif

