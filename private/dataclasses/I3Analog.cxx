/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Analog.cxx,v 1.2 2004/02/15 18:20:37 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/15 18:20:37 $
    @author

    @todo

*/
#include "dataclasses/I3Analog.h"

ClassImp(I3Analog);
  
void
I3Analog::Init()
{
  fTime=0;
  fLet=0;
  fIntegratedcharge=0;
  fTot=0;
  fPeak=0;
}

