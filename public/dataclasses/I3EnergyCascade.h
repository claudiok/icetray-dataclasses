/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyCascade.h,v 1.7 2005/02/09 19:30:46 ehrlich Exp $

    @file I3EnergyCascade.h
    @version $Revision: 1.7 $
    @date $Date: 2005/02/09 19:30:46 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3Energetic.h"
#include "I3NonComposite.h"

#ifndef I3ENERGYCASCADE_H
#define I3ENERGYCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with energy information but no direction.
 */
class I3EnergyCascade : public I3CascadeImpl<I3NonDirectional,
	                                     I3Localized,
                                             I3Energetic,
                                             I3NonComposite>
{
public:
  /**
   * constructor
   */
  I3EnergyCascade(){};

  /**
   * destructor
   */
  virtual ~I3EnergyCascade(){}

  private:
  // ROOT macro
  ClassDef(I3EnergyCascade,1);
};

/**
 * pointer type to insulate users from memory management issues
 */
typedef PtrPolicy<I3EnergyCascade>::ThePolicy I3EnergyCascadePtr;
#endif
