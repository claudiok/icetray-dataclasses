#include "dataclasses/I3AnalogSeries.h"

ClassImp(I3AnalogSeries);
  
I3AnalogSeries::I3AnalogSeries()  {pulse=NULL;}
I3AnalogSeries::~I3AnalogSeries() {if(pulse) {pulse->Delete(); delete pulse;} }

int             I3AnalogSeries::GetNumberPulses() const               {return((pulse==NULL) ? 0 : pulse->GetEntriesFast());}
const I3Analog* I3AnalogSeries::GetPulse(unsigned short number) const {return((GetNumberPulses()<=number) ? NULL : (I3Analog*)pulse->At(number));}
void            I3AnalogSeries::AddPulse(I3Analog* pulse_)            {if(pulse==NULL) pulse = new TObjArray(1); pulse->Add(pulse_);}

