/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * $Id$
 *
 * @file I3ShowerDirection.h
 * @version $Revision: 1.4 $
 * @date $Date$
 * @author Peter Niessen
 */

#ifndef __I3SHOWERDIRECTION_H_
#define __I3SHOWERDIRECTION_H_

#include "dataclasses/StoragePolicy.h"
#include "I3TopShowerImpl.h"

#include "I3Directional.h"
#include "I3NonLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a representation of the shower front by a
 * plane. Intention is to use it as a first guess.
 */
class I3ShowerDirection
: public I3TopShowerImpl<I3Directional, I3NonLocalized, I3NonEnergetic>
{
public:
  virtual ~I3ShowerDirection();

private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ClassDef (I3ShowerDirection, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef shared_ptr<I3ShowerDirection> I3ShowerDirectionPtr;

#endif

