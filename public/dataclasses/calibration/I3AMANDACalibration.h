/**
 *
 * Definition of I3AMANDACalibration class
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * @version $Id: I3AMANDACalibration.h 7468 2005-05-09 20:09:11Z ehrlich $
 *
 * @file I3AMANDACalibration.h
 * @date $Date: 2005-05-09 16:09:11 -0400 (Mon, 09 May 2005) $
*/

#ifndef I3AMANDACALIBRATION_H_INCLUDED
#define I3AMANDACALIBRATION_H_INCLUDED


#include "dataclasses/OMKey.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/calibration/I3AMANDAOMCalib.h"
#include "dataclasses/I3Map.h"

class I3AMANDACalibration : public I3Map<OMKey, I3AMANDACalibrationPtr>
{
public:
    I3AMANDACalibration()
	{};
    
    virtual ~I3AMANDACalibration();
    
    virtual void ToStream(ostream& o) const
	{
	    o<<"[ I3AMANDACalibration: \n";

	    I3AMANDACalibration::const_iterator iter;
	    
	    for( iter = begin();
		 iter != end();
		 iter++ )
	    {
		o<<iter->first;
		
		if( iter->second == I3AMANDAOMCalibPtr((I3AMANDAOMCalib*)0) )
		{
		    o<<"Null I3AMANDAOMCalib";
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
inline ostream& operator<<(ostream& o,const I3AMANDACalibration& v)
{
    v.ToStream(o);
    return o;
}

typedef shared_ptr<I3AMANDACalibration> I3AMANDACalibrationPtr;

#endif //I3AMANDACALIBRATION_H_INCLUDED


    

