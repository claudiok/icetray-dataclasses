/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3BasicCascade.h,v 1.1.2.3 2004/04/20 16:51:16 pretz Exp $

    @version $Revision: 1.1.2.3 $
    @date $Date: 2004/04/20 16:51:16 $
    @author deyoung

    @todo

    For a plain vanilla cascade -- no direction or energy information,
    just a position and particle type.

*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3BASICCASCADE_H
#define I3BASICCASCADE_H

#include "dataclasses/I3Cascade.h"

class I3BasicCascade : public I3CascadeImpl<I3NonDirectional,
	                                    I3Localized,
                                            I3NonEnergetic>
{
public:
    I3BasicCascade(){};
    virtual ~I3BasicCascade(){}
    ClassDef(I3BasicCascade,1);
};

#endif
