/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3BasicCascade.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3BasicCascade.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3BASICCASCADE_H
#define I3BASICCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * For a plain vanilla cascade -- no direction or energy information,
 * just a position and particle type.
 */
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
