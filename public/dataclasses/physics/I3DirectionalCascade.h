/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3DirectionalCascade.h
    @date $Date$
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3DIRECTIONALCASCADE_H_INCLUDED
#define I3DIRECTIONALCASCADE_H_INCLUDED

#include "dataclasses/physics/I3Cascade.h"

/**
 * @brief A cascade with a known direction, but no energy information.
 */
class I3DirectionalCascade : public I3CascadeImpl<I3Directional,
	                                          I3Localized,
                                                  I3NonEnergetic,
                                                  I3NonComposite>
{
public:

  I3DirectionalCascade(){};

  virtual ~I3DirectionalCascade();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3DirectionalCascade,1);
};

/** 
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3DirectionalCascade>  I3DirectionalCascadePtr;

#endif //I3DIRECTIONALCASCADE_H_INCLUDED

