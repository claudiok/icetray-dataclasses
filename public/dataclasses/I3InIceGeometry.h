/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.18 2004/07/31 22:31:10 pretz Exp $
 *
 * @file I3InIceGeometry.h
 * @version $Revision: 1.18 $
 * @date $Date: 2004/07/31 22:31:10 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3INICEGEOMETRY_H
#define I3INICEGEOMETRY_H

#include <TObject.h>
#include <map>
#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "OMKey.h"
#include "StoragePolicy.h"
/**
 * @brief Container for IceCube and AMANDA OMGeos 
 *
 * This class is a list of geometry records for the InIce and AMANDA
 * optical modules.  Each module has an I3OMGeo record, which is
 * identified by its key.  An OMKey is just the (string number, om
 * number) pair that indicates the position of the module.
 * @todo make copy and assignment private.  conflict with something in tests
 */

class I3InIceGeometry : public TObject, 
	public MapPolicy<OMKey,I3OMGeoPtr>::ThePolicy
{
  public:
  /** 
   * constructor
   */
  I3InIceGeometry(){};

  /**
   * default destructor
   */
  virtual ~I3InIceGeometry(){};
  
  private:
/*   // copy and assignment are private */
  I3InIceGeometry(const I3InIceGeometry& rhs); 
  const I3InIceGeometry& operator=(const I3InIceGeometry& rhs); 

  // ROOT macro
  ClassDef(I3InIceGeometry,1);
};

/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3InIceGeometry& v)
{
  o<<"[ I3InIceGeometry: \n";
  I3InIceGeometry::const_iterator iter;
  for(iter=v.begin();iter!=v.end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3OMGeoPtr((I3OMGeo*)0))
	o<<"Null I3OMGeo";
      else
	o<<*(iter->second);
    }
  o<<"]\n";
  return o;
   
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3InIceGeometry>::ThePolicy I3InIceGeometryPtr;

#endif //I3INICEGEOMETRY_H
 
