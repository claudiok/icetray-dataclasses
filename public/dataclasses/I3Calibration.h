/**
 *
 * Definition of I3Calibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3Calibration.h,v 1.5 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3Calibration.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author tmccauley
 */

#ifndef I3CALIBRATION_H
#define I3CALIBRATION_H

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3InIceCalibration.h"
//#include "dataclasses/I3IceTopCalibration.h"

#include <TObject.h>

class I3Calibration : public TObject
{
public:
    I3Calibration()
	{};
    
    virtual ~I3Calibration()
	{};
    
    const I3InIceCalibration& GetInIceCalibration() const 
	{
	    return inIceCalibration_;
	};
    
    I3InIceCalibration& GetInIceCalibration() 
	{
	    return inIceCalibration_;
	};

//    const I3IceTopCalibration& GetIceTopCalibration() const
//	{
//	    return iceTopCalibration_;
//	};
//
//    I3IceTopCalibration& GetIceTopCalibration() 
//	{
//	    return iceTopCalibration_;
//	};
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3Calibration\n"<< inIceCalibration_ <<"]\n";
	};
    
private:
    I3InIceCalibration inIceCalibration_;
    //I3IceTopCalibration fIceTopCalibration;
    
    I3Calibration(const I3Calibration& calibration);
    const I3Calibration& operator=(const I3Calibration& calibration);

    ClassDef(I3Calibration,1);
};

/** 
 * streaming operator
 */
inline ostream& operator<<(ostream& o, const I3Calibration& calib)
{
    calib.ToStream(o);
    return o;
}

typedef shared_ptr<I3Calibration>  I3CalibPtr;

#endif // I3CALIBRATION_H
    
