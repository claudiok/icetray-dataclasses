/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: I3MCCascade.h,v 1.3 2004/04/22 16:55:52 pretz Exp $

    @file I3MCCascade.h
    @version $Revision: 1.3 $
    @date $Date: 2004/04/22 16:55:52 $
    @author deyoung

    @todo
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"

#ifndef I3MCCASCADE_H
#define I3MCCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * A cascade with full MC information.
 */
class I3MCCascade : public I3CascadeImpl<I3Directional,
	                                 I3Localized,
                                         I3Energetic>
{
public:
    I3MCCascade(){};
    virtual ~I3MCCascade(){}
    ClassDef(I3MCCascade,1);
};

#endif
