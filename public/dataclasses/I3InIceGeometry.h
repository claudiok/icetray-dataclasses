/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3InIceGeometry.h,v 1.5 2004/03/01 20:19:49 pretz Exp $
 *
 * Right now just a containter for IceCube and Amanda OMGeos. This is the
 * the 'frozen-in-ice' information, as opposed to the stuff that changes.
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/03/01 20:19:49 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo should the copy and assignment be private?
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
 
