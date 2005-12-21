/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id$

    @file I3DirectionalCascade.h
    @version $Revision: 1.9 $
    @date $Date$
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3DIRECTIONALCASCADE_H
#define I3DIRECTIONALCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with a known direction, but no energy information.
 */
class I3DirectionalCascade : public I3CascadeImpl<I3Directional,
	                                          I3Localized,
                                                  I3NonEnergetic,
                                                  I3NonComposite>
{
public:
  /**
   * constructor
   */
  I3DirectionalCascade(){};

  /**
   * destructor
   */
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

#endif

