/**
    $Id: I3MCTankHit.h,v 1.3 2004/07/19 16:46:01 pretz Exp $
    @file I3MCTankHit.h
    @version $Revision: 1.3 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3MCTankHit_H
#define I3MCTankHit_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3TankHit.h"
#include "dataclasses/I3ObservableParticle.h"

#include "dataclasses/StoragePolicy.h"

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3MCTankHit : public I3TankHit, public VectorPolicy<I3ObservableParticlePtr>::ThePolicy
{

 public:

  /**
   * constructor
   */
  I3MCTankHit(UShort_t tank_number = 0) :
    I3TankHit( tank_number ) {} 
  
  /**
   * destructor
   */
  virtual ~I3MCTankHit() {}
  

 private:
  // copy and assignment are private
  I3MCTankHit(const I3MCTankHit&); 
  const I3MCTankHit& operator=(const I3MCTankHit&); 

  // ROOT macro
  ClassDef(I3MCTankHit,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCTankHit>::ThePolicy I3MCTankHitPtr;


#endif
