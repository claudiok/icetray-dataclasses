/**
 *
 * Definition of I3IceTopCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3IceTopCalibration.h,v 1.2.16.1 2005/03/17 17:39:27 dima Exp $
 *
 * @file I3IceTopCalibration.h
 * @version $Revision: 1.2.16.1 $
 * @date $Date: 2005/03/17 17:39:27 $
 * @author tmccauley
 */

#ifndef I3ICETOPCALIBRATION_H
#define I3ICETOPCALIBRATION_H

#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3DataExecution.h"

#include "dataclasses/I3DOMCalibration.h"

#include <map>
#include <TObject.h>

class I3IceTopCalibration : public TObject, 
			    public MapPolicy<OMKey, I3DOMCalibPtr>::ThePolicy
{
public:
    I3IceTopCalibration()
	{};
    
    virtual ~I3IceTopCalibration()
	{};
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3IceTopCalibration: \n";

	    I3IceTopCalibration::const_iterator iter;
	    
	    for( iter = begin();
		 iter != end();
		 iter++ )
	    {
		o<<iter->first;
		
		if( iter->second == I3DOMCalibPtr((I3DOMCalibration*)0) )
		{
		    o<<"Null I3DOMCalibration";
		}
		
		else
		{
		    o<<*(iter->second);
		}
	    
		o<<"]\n";
	    }
	};
    
    virtual string ToString() const
      {
	    ostringstream out;
	    ToStream(out);
	    return out.str(); 
      };

    //I3IceTopCalibration(const I3IceTopCalibration& calibration);
    //const I3IceTopCalibration& operator=(const I3IceTopCalibration& calibration);
    
    ClassDef(I3IceTopCalibration,1);    
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3IceTopCalibration& v)
{
    v.ToStream(o);
    return o;
}

typedef PtrPolicy<I3IceTopCalibration>::ThePolicy I3IceTopCalibPtr;

#endif // I3ICETOPCALIBRATION_H


    
