/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DirectionalCascade.h,v 1.2 2004/04/22 15:55:44 pretz Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/04/22 15:55:44 $
    @author deyoung

    @todo

    A cascade with a known direction, but no energy information.

*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3DIRECTIONALCASCADE_H
#define I3DIRECTIONALCASCADE_H

#include "dataclasses/I3Cascade.h"

class I3DirectionalCascade : public I3CascadeImpl<I3Directional,
	                                          I3Localized,
                                                  I3NonEnergetic>
{
public:
    I3DirectionalCascade(){};
    virtual ~I3DirectionalCascade(){}
    ClassDef(I3DirectionalCascade,1);
};

#endif
