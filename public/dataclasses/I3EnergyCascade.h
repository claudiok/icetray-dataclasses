/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyCascade.h,v 1.4 2004/04/27 02:32:05 pretz Exp $

    @file I3EnergyCascade.h
    @version $Revision: 1.4 $
    @date $Date: 2004/04/27 02:32:05 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3ENERGYCASCADE_H
#define I3ENERGYCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with energy information but no direction.
 */
class I3EnergyCascade : public I3CascadeImpl<I3NonDirectional,
	                                     I3Localized,
                                             I3Energetic>
{
public:
    I3EnergyCascade(){};
    virtual ~I3EnergyCascade(){}
    ClassDef(I3EnergyCascade,1);
};

#endif
