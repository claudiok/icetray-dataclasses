/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleData.h,v 1.6.4.1 2005/02/04 06:11:43 troy Exp $
 *
 * @file I3MCParticleData.h
 * @version $Revision: 1.6.4.1 $
 * @date $Date: 2005/02/04 06:11:43 $
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

  I3ParticleMultiMap fPrimary;         //||
  I3ParticleMultiMap fInIceParticles;  //||
  I3ParticleMultiMap fIceTopParticles; //||

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
  const I3ParticleMultiMap& GetPrimary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3ParticleMultiMap& GetPrimary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3ParticleMultiMap& GetInIceParticles() const {return fInIceParticles;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3ParticleMultiMap& GetInIceParticles() {return fInIceParticles;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3ParticleMultiMap& GetIceTopParticles() const {return fIceTopParticles;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3ParticleMultiMap& GetIceTopParticles() {return fIceTopParticles;};

  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3ParticleMultiMap ] \n"
       <<fPrimary
       <<fInIceParticles
       <<fIceTopParticles;
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
typedef PtrPolicy<I3MCParticleData>::ThePolicy I3MCParticleDataPtr;

#endif //I3MCPARTICLEDATA_H
