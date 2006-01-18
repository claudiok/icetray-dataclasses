/**
    copyright  (C) 2004
    the IceCube collaboration
    @version $Id$
    @file I3BasicCascade.h
    @date $Date$
*/

#include "dataclasses/physics/I3CascadeImpl.h"
#include "dataclasses/physics/I3NonDirectional.h"
#include "dataclasses/physics/I3Localized.h"
#include "dataclasses/physics/I3NonEnergetic.h"
#include "dataclasses/physics/I3NonComposite.h"

#ifndef I3BASICCASCADE_H_INCLUDED
#define I3BASICCASCADE_H_INCLUDED

#include "dataclasses/physics/I3Cascade.h"

/**
 * @brief A plain vanilla cascade -- no direction or energy information,
 * just a position and particle type.
 */
class I3BasicCascade : public I3CascadeImpl<I3NonDirectional,
	 I3Localized,
	 I3NonEnergetic,
	 I3NonComposite>
{
public:

  I3BasicCascade(){};

  virtual ~I3BasicCascade();

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3BasicCascade,1);
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef shared_ptr<I3BasicCascade>  I3BasicCascadePtr;

#endif //I3BASICCASCADE_H_INCLUDED

