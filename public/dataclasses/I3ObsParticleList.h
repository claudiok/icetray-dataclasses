/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3ObsParticleList.h,v 1.1 2004/05/04 21:36:17 pretz Exp $
 *
 * @file I3ObsParticleList.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/04 21:36:17 $
 * @author pretz
 */

#ifndef I3OBSPARTICLELIST_H
#define I3OBSPARTICLELIST_H

#include "I3ObservableParticle.h"
#include "StoragePolicy.h"

/**
 * @brief A list of observable particles
 *
 * @todo figure out how to make copy and assignment private
 */
class I3ObsParticleList : public TObject, public VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3ObsParticleList(){};

  /**
   * destructor
   */
  virtual ~I3ObsParticleList(){};

 private:
  // copy and assignment private
/*   I3ObsParticleList(const I3ObsParticleList&);  */
/*   const I3ObsParticleList& operator=(const I3ObsParticleList&); */ 

  // ROOT macro
  ClassDef(I3ObsParticleList,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3ObsParticleList>::ThePolicy I3ObsParticleListPtr;


#endif
