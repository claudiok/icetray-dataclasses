/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.1.2.2 2004/04/16 21:44:33 pretz Exp $

    @version $Revision: 1.1.2.2 $
    @date $Date: 2004/04/16 21:44:33 $
    @author deyoung

    @todo

    A cascade with full MC information.

*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Identifiable.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3MCCASCADE_H
#define I3MCCASCADE_H

#include "dataclasses/I3Cascade.h"

class I3MCCascade : public I3CascadeImpl<I3Directional,
	                                 I3Identifiable,
	                                 I3Localized,
                                         I3Energetic>
{
public:
    I3MCCascade(){};
    virtual ~I3MCCascade(){}
    ClassDef(I3MCCascade,1);
};

#endif
