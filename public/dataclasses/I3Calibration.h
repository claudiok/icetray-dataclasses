/**
 *
 * Definition of I3Calibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id$
 *
 * @file I3Calibration.h
 * @version $Revision: 1.5 $
 * @date $Date$
 * @author tmccauley
 */

#ifndef I3CALIBRATION_H
#define I3CALIBRATION_H

#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3InIceCalibration.h"
#include "dataclasses/I3AMANDACalibration.h"
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

    const I3AMANDACalibration& GetAMANDACalibration() const 
	{
	    return AMANDACalibration_;
	};
    
    I3AMANDACalibration& GetAMANDACalibration() 
	{
	    return AMANDACalibration_;
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
    I3InIceCalibration  inIceCalibration_;
    I3AMANDACalibration AMANDACalibration_;
    //I3IceTopCalibration fIceTopCalibration_;
    
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
    
