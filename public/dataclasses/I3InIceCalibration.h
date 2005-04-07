/**
 *
 * Definition of I3InIceCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3InIceCalibration.h,v 1.5 2005/04/07 18:24:22 olivas Exp $
 *
 * @file I3InIceCalibration.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005/04/07 18:24:22 $
 * @author tmccauley
 */

#ifndef I3INICECALIBRATION_H
#define I3INICECALIBRATION_H


#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3DOMCalibration.h"

#include <map>
#include <TObject.h>

class I3InIceCalibration : public TObject, 
			   public MapPolicy<OMKey, I3DOMCalibPtr>::ThePolicy
{
public:
    I3InIceCalibration()
	{};
    
    virtual ~I3InIceCalibration()
	{};
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3InIceCalibration: \n";

	    I3InIceCalibration::const_iterator iter;
	    
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
    
    // NOTE: fix this later
    //I3InIceCalibration(const I3InIceCalibration& calibration);
    //const I3InIceCalibration& operator=(const I3InIceCalibration& calibration);
    
    ClassDef(I3InIceCalibration,1);    
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3InIceCalibration& v)
{
    v.ToStream(o);
    return o;
}

typedef PtrPolicy<I3InIceCalibration>::ThePolicy I3InIceCalibPtr;

#endif // I3INICECALIBRATION_H


    
