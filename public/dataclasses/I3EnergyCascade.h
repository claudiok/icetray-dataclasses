/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3EnergyCascade.h,v 1.1.2.2 2004/04/16 21:44:33 pretz Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/16 21:44:33 $
    @author deyoung

    @todo

    A cascade with energy information but no direction.

*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Identifiable.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3ENERGYCASCADE_H
#define I3ENERGYCASCADE_H

#include "dataclasses/I3Cascade.h"

class I3EnergyCascade : public I3CascadeImpl<I3NonDirectional,
	                                     I3Identifiable,
	                                     I3Localized,
                                             I3Energetic>
{
public:
    I3EnergyCascade(){};
    virtual ~I3EnergyCascade(){}
    ClassDef(I3EnergyCascade,1);
};

#endif
