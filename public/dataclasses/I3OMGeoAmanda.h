/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeoAmanda.h,v 1.3 2004/02/20 18:42:16 pretz Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/02/20 18:42:16 $
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

  ClassDef(I3OMGeoAmanda,1);
};

typedef I3OMGeoAmanda* I3OMGeoAmandaPtr;

#endif

