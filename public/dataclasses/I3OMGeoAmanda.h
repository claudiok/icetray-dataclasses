/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeoAmanda.h,v 1.5 2004/02/23 22:36:49 troy Exp $

    @version $Revision: 1.5 $
    @date $Date: 2004/02/23 22:36:49 $
    @author

    @todo

*/
#ifndef I3OMGEOAMANDA_H
#define I3OMGEOAMANDA_H

#include "I3OMGeo.h"

class I3OMGeoAmanda : public I3OMGeo
{

  public:
  I3OMGeoAmanda() {;}
  I3OMGeoAmanda(const I3OMGeoAmanda& rhs){*this = rhs;}
  virtual ~I3OMGeoAmanda(){}
  const I3OMGeoAmanda& operator=(const I3OMGeoAmanda& rhs){
    if(this == &rhs) return *this;
    I3OMGeo::operator=(rhs);
    return *this;
  }

  ClassDef(I3OMGeoAmanda,1);
};

#include "dataclasses/StoragePolicy.h"
typedef PtrPolicy<I3OMGeoAmanda>::ThePolicy I3OMGeoAmandaPtr;

#endif

