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

I3AnalogSeries::I3AnalogSeries(const I3AnalogSeries& h)
{
  pulse=NULL;
  int n=h.GetNumberPulses();
  if(n>0)
  {
    pulse=new TObjArray(n);
    for(int i=0; i<n; i++) pulse->Add(new I3Analog(h.GetPulse(i)));
  }
}

I3AnalogSeries& I3AnalogSeries::operator=(const I3AnalogSeries& h)
{
  if(this==&h) return(*this);
  if(pulse) {pulse->Delete(); delete pulse;}
  pulse=NULL;
  int n=h.GetNumberPulses();
  if(n>0)
  {
    pulse=new TObjArray(n);
    for(int i=0; i<n; i++) pulse->Add(new I3Analog(h.GetPulse(i)));
  }
  return(*this);
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

void I3AnalogSeries::AddPulse(I3Analog* pulse_)
{
  if(pulse==NULL) pulse = new TObjArray(1); 
  pulse->Add(pulse_);
}

I3Iterator<const I3Analog>* I3AnalogSeries::MakeAnalogIterator() const
{
  if(!pulse)
    return new I3ZeroItemIterator<const I3Analog>();
  else
    return new I3TCollectionIterator<const I3Analog>(pulse);

}

