/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleData.h,v 1.3 2004/07/28 19:10:34 ehrlich Exp $
 *
 * @file I3MCParticleData.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/07/28 19:10:34 $
 * @author pretz
 *
 */

#ifndef I3MCPARTICLEDATA_H
#define I3MCPARTICLEDATA_H

#include "dataclasses/I3MCPrimary.h"
#include "dataclasses/I3MCParticleMultiMap.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A set of causely-related MC particles.
 *
 * The stuff at the surface, and the stuff in the ice
 * @todo work out how the copy and assignment can be private.
 */
class I3MCParticleData : public TObject 
{

  I3MCParticleMultiMap fPrimary;
  I3MCParticleMultiMap fInIceParticles;
  I3MCParticleMultiMap fIceTopParticles;

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
  const I3MCParticleMultiMap& GetPrimary() const {return fPrimary;}

  /**
   * @return the primary track as non-const
   */
  I3MCParticleMultiMap& GetPrimary() {return fPrimary;}

  /**
   * @return the In-Ice tracks as constant
   */
  const I3MCParticleMultiMap& GetInIceParticles() const {return fInIceParticles;}

  /**
   * @return the In-Ice tracks as non-constant
   */
  I3MCParticleMultiMap& GetInIceParticles() {return fInIceParticles;}

  /**
   * @return the IceTop tracks as constant
   */
  const I3MCParticleMultiMap& GetIceTopParticles() const {return fIceTopParticles;}

  /**
   * @return the IceTop tracks as non-constant
   */
  I3MCParticleMultiMap& GetIceTopParticles() {return fIceTopParticles;};

 private:
  // copy and assignment are private
/*   I3MCParticleEvent(const I3MCParticleEvent&){} */
/*   const I3MCParticleEvent& operator=(const I3MCParticleEvent&); */

  ClassDef(I3MCParticleData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleData>::ThePolicy I3MCParticleDataPtr;

#endif //I3MCPARTICLEDATA_H
