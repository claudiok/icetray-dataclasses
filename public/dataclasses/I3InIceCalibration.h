/**
 *
 * Definition of I3InIceCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3InIceCalibration.h,v 1.2.2.2 2005/02/04 21:51:03 troy Exp $
 *
 * @file I3InIceCalibration.h
 * @version $Revision: 1.2.2.2 $
 * @date $Date: 2005/02/04 21:51:03 $
 * @author tmccauley
 */

#ifndef I3INICECALIBRATION_H
#define I3INICECALIBRATION_H


#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3DOMCalibration.h"

#include <map>

class I3InIceCalibration : public TObject, 
			   public MapPolicy<OMKey, I3DOMCalibPtr>::ThePolicy
{
public:
    I3InIceCalibration()
	{};
    
    virtual ~I3InIceCalibration()
	{};
    
    virtual void ToStream(ostream& o) const
	{};
    
    virtual string ToString() const
	{ return "FIXME"; }
    
};

typedef PtrPolicy<I3InIceCalibration>::ThePolicy I3InIceCalibPtr;

#endif // I3INICECALIBRATION_H


    
