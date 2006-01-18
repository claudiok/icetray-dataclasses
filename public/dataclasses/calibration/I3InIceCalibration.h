/**
 *
 * Definition of I3InIceCalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id$
 * @file I3InIceCalibration.h
 * @date $Date$
 */

#ifndef I3INICECALIBRATION_H_INCLUDED
#define I3INICECALIBRATION_H_INCLUDED


#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/calibration/I3DOMCalibration.h"
#include "dataclasses/I3Map.h"

#include <vector>


class I3InIceCalibration : public I3Map<OMKey, I3DOMCalibrationPtr>
{
public:
    I3InIceCalibration()
	{};
    
    virtual ~I3InIceCalibration();
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3InIceCalibration: \n";

	    I3InIceCalibration::const_iterator iter;
	    
	    for( iter = begin();
		 iter != end();
		 iter++ )
	    {
		o<<iter->first;
		
		if( iter->second == I3DOMCalibrationPtr((I3DOMCalibration*)0) )
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
    
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3InIceCalibration& v)
{
    v.ToStream(o);
    return o;
}

typedef shared_ptr<I3InIceCalibration>  I3InIceCalibrationPtr;

#endif // I3INICECALIBRATION_H_INCLUDED


    

