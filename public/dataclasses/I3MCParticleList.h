/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCParticleList.h,v 1.1 2004/05/05 19:34:54 pretz Exp $
 *
 * @file I3MCParticleList.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/05/05 19:34:54 $
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
class I3MCParticleList : public TObject, public VecPointainerPolicy<I3ObservableParticlePtr>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCParticleList(){};

  /**
   * destructor
   */
  virtual ~I3MCParticleList(){};

 private:
  // copy and assignment private
/*   I3MCParticleList(const I3MCParticleList&);  */
/*   const I3MCParticleList& operator=(const I3MCParticleList&); */ 

  // ROOT macro
  ClassDef(I3MCParticleList,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCParticleList>::ThePolicy I3MCParticleListPtr;


#endif
