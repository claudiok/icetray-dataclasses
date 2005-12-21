/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Composite.h
 * @version $Revision: 1.12 $
 * @date $Date$
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
   I3ParticleMultiMap constituents_;
 public:
  /**
   * constructor
   */
  I3Composite(){}

  /**
   * destructor
   */
  virtual ~I3Composite();

  /**
   * indicates that the track is composite
   */
  bool IsComposite() const {return true;}

  /**
   * retrieves the constituents that make up this track as const
   */
  const I3ParticleMultiMap& GetConstituents() const {return constituents_;}

  /**
   * retrieves the constituents that make up this track as non-const
   */
  I3ParticleMultiMap& GetConstituents() {return constituents_;}

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
	  composite->constituents_ = constituents_;
	}
    }

  virtual void ToStream(ostream& o) const
    {
      o<<"Consituents: \n";
      I3ParticleMultiMap::const_iterator iter;
      for(iter= constituents_.begin() ; iter!= constituents_.end() ; iter++)
	{
	  o<<iter->first<<" "<<iter->second<<"\n";
	}
    }
 private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3Composite,1);
};

#endif


