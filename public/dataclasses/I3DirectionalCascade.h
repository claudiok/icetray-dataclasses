/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DirectionalCascade.h,v 1.7 2004/08/12 17:33:33 pretz Exp $

    @file I3DirectionalCascade.h
    @version $Revision: 1.7 $
    @date $Date: 2004/08/12 17:33:33 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3DIRECTIONALCASCADE_H
#define I3DIRECTIONALCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with a known direction, but no energy information.
 */
class I3DirectionalCascade : public I3CascadeImpl<I3Directional,
	                                          I3Localized,
                                                  I3NonEnergetic>
{
public:
  /**
   * constructor
   */
  I3DirectionalCascade(){};

  /**
   * destructor
   */
  virtual ~I3DirectionalCascade(){}

 private:
  // ROOT macro
  ClassDef(I3DirectionalCascade,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3DirectionalCascade>::ThePolicy I3DirectionalCascadePtr;

#endif
