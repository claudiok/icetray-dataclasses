/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3DirectionalCascade.h,v 1.5 2004/04/27 13:35:23 pretz Exp $

    @file I3DirectionalCascade.h
    @version $Revision: 1.5 $
    @date $Date: 2004/04/27 13:35:23 $
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3DIRECTIONALCASCADE_H
#define I3DIRECTIONALCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with a known direction, but no energy information.
 */
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
