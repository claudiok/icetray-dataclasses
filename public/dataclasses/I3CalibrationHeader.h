/**
 *
 * Definition of I3CalibrationHeader class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3CalibrationHeader.h,v 1.1 2005/02/07 17:22:22 tmccauley Exp $
 *
 * @file I3CalibrationHeader.h
 * @version $Revision: 1.1 $
 * @date $Date: 2005/02/07 17:22:22 $
 * @author tmccauley
 */

#ifndef I3CALIBRATIONHEADER_H
#define I3CALIBRATIONHEADER_H

#include "dataclasses/I3DataHeader.h"
#include "dataclasses/StoragePolicy.h"

using namespace std;

class I3CalibrationHeader : public I3DataHeader
{ 
public:
    I3CalibrationHeader()
	{};

    virtual ~I3CalibrationHeader() 
	{};

    I3CalibrationHeader(const I3CalibrationHeader& calib)
	{
	    *this = calib;
	};
  
    const I3CalibrationHeader& operator=(const I3CalibrationHeader& calib)
	{
	    if (this == &calib)
	    {
		return *this;
	    }

	    // Take care of data here

	    I3DataHeader::operator=(calib);
	    return *this;
	};
 
    const string GetDataStream() 
	{ 
	    return "Calibration"; 
	};
private:
  
    ClassDef(I3CalibrationHeader,1);
};

typedef PtrPolicy<I3CalibrationHeader>::ThePolicy I3CalibrationHeaderPtr;

#endif //I3CALIBRATIONHEADER_H
