/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.6 2004/03/04 16:45:56 troy Exp $
 *
 * Right now just a containter for IceCube and Amanda OMGeos. This is the
 * the 'frozen-in-ice' information, as opposed to the stuff that changes.
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/03/04 16:45:56 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo should the copy and assignment be private?  
 *
 * @todo TDS: should contain two vectors, one by geonumber and one
 * with the current indexing scheme, whatever that is.  HasOMGeoNumber
 * and FindOmGeo both do the same thing (linear time search).  Lots of
 * wasted processing here.  Fatal error on "geo not found" makes no
 * sense.
 *
 */


#ifndef I3INICEGEOMETRY_H
#define I3INICEGEOMETRY_H

#include <TObject.h>
#include "I3DataExecution.h"
#include "I3OMGeo.h"
#include "StoragePolicy.h"

class I3InIceGeometry : public TObject, public VecPointainerPolicy<I3OMGeoPtr>::ThePolicy
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
  
  bool HasOMGeoNumber(unsigned int omnumber) const
  {
    for(unsigned int i=0; i<this->size(); i++)
    {if( (*this)[i]->OMNumber()==omnumber ) return(true);}
    return(false);
  }
  
  const I3OMGeo& FindOMGeo(unsigned int omnumber) const 
  { 
    for(unsigned int i=0; i<this->size(); i++)
    {
      if( (*this)[i]->OMNumber()==omnumber) return(*(*this)[i]);
    }
    I3DataExecution::Instance().Fatal("I3Geometry::FindOMGeo() asked for a non-existent OM");
    return(*(I3OMGeo*)NULL);
  }

  private:
/*   // copy and assignment are private */
/*   I3InIceGeometry(const I3InIceGeometry& rhs); */
/*   const I3InIceGeometry& operator=(const I3InIceGeometry& rhs); */

  // ROOT macro
  ClassDef(I3InIceGeometry,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3InIceGeometry>::ThePolicy I3InIceGeometryPtr;

#endif //I3INICEGEOMETRY_H
 
