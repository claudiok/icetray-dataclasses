/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleData.h,v 1.1 2004/05/04 23:40:06 pretz Exp $
 *
 * @file I3MCParticleData.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/04 23:40:06 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3MCPARTICLEDATA_H
#define I3MCPARTICLEDATA_H

#include "dataclasses/I3MCParticleEvent.h"
#include "TObject.h"

/**
 * @brief This is a map of I3MCParticleEvents.  
 *
 * It is supposed to contain all the
 * MC information for the tracks in the Event.  
 *
 */
class I3MCParticleData : public TObject, public MapPointainerPolicy<I3MCParticleEventPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCParticleData(){}

  /**
   * destructor
   */
  virtual ~I3MCParticleData() {};

 private:
  // copy and assignment private
  I3MCParticleData(const I3MCParticleData& rhs);
  const I3MCParticleData& operator=(const I3MCParticleData& rhs);

  // ROOT macro
  ClassDef(I3MCParticleData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleData>::ThePolicy I3MCParticleDataPtr;

#endif
