/**
 *
 * Definition of I3CalibrationHeader class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3CalibrationHeader.h
 * @date $Date$
 */

#ifndef I3CALIBRATIONHEADER_H_INCLUDED
#define I3CALIBRATIONHEADER_H_INCLUDED

#include "dataclasses/I3DataHeader.h"
#include "dataclasses/StoragePolicy.h"

using namespace std;

class I3CalibrationHeader : public I3DataHeader
{ 
public:
    I3CalibrationHeader()
	{};

    virtual ~I3CalibrationHeader();

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
  
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3CalibrationHeader>  I3CalibrationHeaderPtr;

#endif //I3CALIBRATIONHEADER_H_INCLUDED

