/**
 *
 * Definition of I3IceTopCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3IceTopCalibration.h,v 1.2.2.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3IceTopCalibration.h
 * @version $Revision: 1.2.2.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author tmccauley
 */

#ifndef I3ICETOPCALIBRATION_H
#define I3ICETOPCALIBRATION_H

#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3DOMCalibration.h"

#include <map>

class I3IceTopCalibration : public TObject, 
			    public MapPolicy<OMKey, I3DOMCalibPtr>::ThePolicy
{
public:
    I3IceTopCalibration()
	{};
    
    virtual ~I3IceTopCalibration()
	{};
    
    virtual void ToStream(ostream& o) const
	{};
    
    virtual string ToString() const
    { return "FIXME"; }
    
};

typedef PtrPolicy<I3IceTopCalibration>::ThePolicy I3IceTopCalibPtr;

#endif // I3ICETOPCALIBRATION_H


    
