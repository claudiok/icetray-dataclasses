/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPhotonVect.h,v 1.2 2004/07/19 16:46:01 pretz Exp $
 *
 * @file I3MCPhotonVect.h
 * @version $Revision: 1.2 $
 * @date $Date: 2004/07/19 16:46:01 $
 * @author pretz
 */
#ifndef I3MCPHOTONVECT_H
#define I3MCPHOTONVECT_H

#include "StoragePolicy.h"
#include "I3MCPhoton.h"

/**
 * @brief A collection of I3MCPhotons.  
 *
 * This represents the full set of photons that arrive at a PMT during an
 * event
 */
class I3MCPhotonVect : public TObject, VectorPolicy<I3MCPhoton>::ThePolicy
{
 public:
  /**
   * default constructor
   */
  I3MCPhotonVect(){}

  /**
   * destructor
   */
  virtual ~I3MCPhotonVect() {}

 private:
  //ROOT macro
  ClassDef(I3MCPhotonVect,1);
};

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCPhotonVect>::ThePolicy I3MCPhotonVectPtr;

#endif //I3MCPHOTONVECT_H

