/**
 *
 * Definition of I3Calibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3Calibration.h,v 1.1.2.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3Calibration.h
 * @version $Revision: 1.1.2.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author tmccauley

 * @todo Something is screwy when FrameAccess<I3Calibration> is used. This
         needs to be investigated and fixed.
 */

#ifndef I3CALIBRATION_H
#define I3CALIBRATION_H

#include "dataclasses/StoragePolicy.h"

#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3IceTopCalibration.h"

class I3Calibration : public TObject
{
public:
    I3Calibration()
	{};
    
    virtual ~I3Calibration()
	{};
    

    // NOTE: const?
    I3InIceCalibration& GetInIceCalibration() 
	{
	    return fInIceCalibration;
	};
    
    I3IceTopCalibration& GetIceTopCalibration() 
	{
	    return fIceTopCalibration;
	};
    
    virtual void ToStream(ostream& o)
	{};
    
private:
    I3InIceCalibration fInIceCalibration;
    I3IceTopCalibration fIceTopCalibration;
    
    I3Calibration(const I3Calibration& calibration);
    const I3Calibration& operator=(const I3Calibration& calibration);
    
    ClassDef(I3Calibration,1);
};

typedef PtrPolicy<I3Calibration>::ThePolicy I3CalibPtr;

#endif // I3CALIBRATION_H
    
