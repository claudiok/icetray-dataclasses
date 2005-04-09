/**
 *
 * Definition of I3Calibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3Calibration.h,v 1.4 2005/04/09 03:02:10 olivas Exp $
 *
 * @file I3Calibration.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005/04/09 03:02:10 $
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
	    return fInIceCalibration;
	};
    
    I3InIceCalibration& GetInIceCalibration() 
	{
	    return fInIceCalibration;
	};

//    const I3IceTopCalibration& GetIceTopCalibration() const
//	{
//	    return fIceTopCalibration;
//	};
//
//    I3IceTopCalibration& GetIceTopCalibration() 
//	{
//	    return fIceTopCalibration;
//	};
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3Calibration\n"<< fInIceCalibration <<"]\n";
	};
    
private:
    I3InIceCalibration  fInIceCalibration;
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
    
