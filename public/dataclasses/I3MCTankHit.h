/**
    $Id: I3MCTankHit.h,v 1.5 2004/08/16 16:22:13 pretz Exp $
    @file I3MCTankHit.h
    @version $Revision: 1.5 $
    @date Tue Jun 22 16:39:23 EDT 2004
    @author rulrich
*/

#ifndef I3MCTankHit_H
#define I3MCTankHit_H

#include <TObject.h>
#include <TObjArray.h>

#include "dataclasses/I3TankHit.h"
#include "dataclasses/I3IceTopParticle.h"
#include "dataclasses/StoragePolicy.h"

#include <string>

using namespace std;

/**
 * @brief The container for all the Array Hit-related data in the event
 *
 */
class I3MCTankHit : public I3TankHit, public VectorPolicy<I3IceTopParticlePtr>::ThePolicy
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

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3MCTankHit: \n";
      I3MCTankHit::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  if(*iter == I3IceTopParticlePtr((I3IceTopParticle*)0))
	    o<<"Null I3IceTopParticle";
	  else
	    o<<*(*iter);
	}
      o<<"]\n";
    }
  
 private:
  // copy and assignment are private
  I3MCTankHit(const I3MCTankHit&); 
  const I3MCTankHit& operator=(const I3MCTankHit&); 

  // ROOT macro
  ClassDef(I3MCTankHit,1);
};

inline ostream& operator<<(ostream& o,const I3MCTankHit& tankhit)
{
  tankhit.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCTankHit>::ThePolicy I3MCTankHitPtr;


#endif
