/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeo.cxx,v 1.7 2004/03/10 19:56:05 pretz Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/03/10 19:56:05 $
    @author

    @todo

*/
#include "dataclasses/I3OMGeo.h"

ClassImp(I3OMGeo);

void I3OMGeo::Init()
{
  fOMNumber = 0;
  fX = 0;
  fY = 0;
  fZ = 0;
  fOrientation = Unspecified;
  fString = 0;
  fRelativeQE = 0;
}


