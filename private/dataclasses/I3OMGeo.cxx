/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeo.cxx,v 1.6 2004/03/10 15:53:55 pretz Exp $

    @version $Revision: 1.6 $
    @date $Date: 2004/03/10 15:53:55 $
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
  fOrientation = 0;
  fString = 0;
  fRelativeQE = 0;
}


