/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyCascade.h,v 1.1.2.1 2004/04/16 20:27:05 deyoung Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/04/16 20:27:05 $
    @author deyoung

    @todo

    A cascade with energy information but no direction.

*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Identifiable.h"
#include "I3Localizable.h"
#include "I3Energetic.h"

#ifndef I3ENERGYCASCADE_H
#define I3ENERGYCASCADE_H

#include "dataclasses/I3Cascade.h"

class I3EnergyCascade : public I3CascadeImpl<I3NonDirectional,
	                                     I3Identifiable,
	                                     I3Localizable,
                                             I3Energetic>
{
public:
    I3EnergyCascade(){};
    virtual ~I3EnergyCascade(){}
    ClassDef(I3EnergyCascade,1);
};

#endif
