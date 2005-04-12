/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleData.h,v 1.9 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3MCParticleData.h
 * @version $Revision: 1.9 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author pretz
 *
 */

#ifndef I3MCPARTICLEDATA_H
#define I3MCPARTICLEDATA_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3ParticleMultiMap.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC particles.
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCParticleData : public TObject 
{

  I3ParticleMultiMap primary_;         //||
  I3ParticleMultiMap inIceParticles_;  //||
  I3ParticleMultiMap iceTopParticles_; //||

 public:
  /**
   * constructor
   */
  I3MCParticleData(){}

  /**
   * destructor
   */
  virtual ~I3MCParticleData(){}
  
  /**
   * @return the primary track as constant
   */
  const I3ParticleMultiMap& GetPrimary() const {return primary_;}

  /**
   * @return the primary track as non-const
   */
  I3ParticleMultiMap& GetPrimary() {return primary_;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3ParticleMultiMap& GetInIceParticles() const {return inIceParticles_;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3ParticleMultiMap& GetInIceParticles() {return inIceParticles_;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3ParticleMultiMap& GetIceTopParticles() const {return iceTopParticles_;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3ParticleMultiMap& GetIceTopParticles() {return iceTopParticles_;};

  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3ParticleMultiMap ] \n"
       <<primary_
       <<inIceParticles_
       <<iceTopParticles_;
    }
  
  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }


 private:

  ClassDef(I3MCParticleData,1);
};

inline ostream& operator<<(ostream& o, const I3MCParticleData& data)
{
  data.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCParticleData>  I3MCParticleDataPtr;

#endif //I3MCPARTICLEDATA_H
