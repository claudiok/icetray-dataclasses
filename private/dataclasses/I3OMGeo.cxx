/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3OMGeo.cxx,v 1.8 2004/07/05 17:13:11 pretz Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/07/05 17:13:11 $
    @author

    @todo

*/
#include "dataclasses/I3OMGeo.h"

ClassImp(I3OMGeo);

void I3OMGeo::Init()
{
  fOMNumber = 0;
  fOrientation = Unspecified;
  fString = 0;
  fRelativeQE = 0;
}


