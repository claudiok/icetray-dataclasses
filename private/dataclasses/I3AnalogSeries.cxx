#include "dataclasses/I3AnalogSeries.h"
#include "dataclasses/I3DataExecution.h"
#include "dataclasses/I3TCollectionIterator.h"
#include "dataclasses/I3ZeroItemIterator.h"

ClassImp(I3AnalogSeries);
  
I3AnalogSeries::I3AnalogSeries()  
{
  pulse=NULL;
}

I3AnalogSeries::~I3AnalogSeries() 
{
  if(pulse) {pulse->Delete();  delete pulse;} 
}

int I3AnalogSeries::GetNumberPulses() const
{
  return((pulse==NULL) ? 0 : pulse->GetEntriesFast());
}

const I3Analog& I3AnalogSeries::GetPulse(unsigned short number) const 
{
  if(GetNumberPulses()>number) return (*(I3Analog*)pulse->At(number));
  I3DataExecution::Instance().Fatal("I3AnalogSeries::GetPulse() asked for a pulse out of bounds");
  return(*(I3Analog*)NULL);
}

I3Iterator<const I3Analog>* I3AnalogSeries::MakeAnalogIterator() const
{
  if(!pulse)
    return new I3ZeroItemIterator<const I3Analog>();
  else
    return new I3TCollectionIterator<const I3Analog>(pulse);

}

void I3AnalogSeries::AddPulse(I3Analog* pulse_)
{
  if(pulse==NULL) pulse = new TObjArray(1); 
  pulse->Add(pulse_);
}


