/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AnalogPulse.cxx,v 1.1 2004/03/10 02:42:24 pretz Exp $
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 02:42:24 $
 * @author
 *
 * @todo
 *
 */
#include "dataclasses/I3AnalogPulse.h"

ClassImp(I3AnalogPulse);
  
void
I3AnalogPulse::Init()
{
  fLe=0;
  fIntegratedcharge=0;
  fTot=0;
  fPeak=0;
}

