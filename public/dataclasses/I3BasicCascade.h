/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3BasicCascade.h,v 1.6.4.1 2005/02/04 21:49:05 troy Exp $

    @file I3BasicCascade.h
    @version $Revision: 1.6.4.1 $
    @date $Date: 2005/02/04 21:49:05 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3BASICCASCADE_H
#define I3BASICCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A plain vanilla cascade -- no direction or energy information,
 * just a position and particle type.
 */
class I3BasicCascade : public I3CascadeImpl<I3NonDirectional,
	                                    I3Localized,
                                            I3NonEnergetic>
{
public:
  /**
   * constructor
   */
  I3BasicCascade(){};

  /**
   * destructor
   */
  virtual ~I3BasicCascade(){}

 private:
  // ROOT macro
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3BasicCascade>::ThePolicy I3BasicCascadePtr;

#endif
