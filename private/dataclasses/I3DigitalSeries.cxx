#include "dataclasses/I3DigitalSeries.h"

ClassImp(I3DigitalSeries);
  
I3DigitalSeries::I3DigitalSeries()  {starttime=0; binwidth=0; digit=NULL;}
I3DigitalSeries::~I3DigitalSeries() {if(digit) {digit->Delete(); delete digit;} }

double I3DigitalSeries::GetStartTime() const {return(starttime);}
float  I3DigitalSeries::GetBinWidth() const  {return(binwidth);}
void I3DigitalSeries::SetStartTime(double starttime_) {starttime=starttime_;}
void I3DigitalSeries::SetBinWidth(float binwidth_)    {binwidth=binwidth_;}

int              I3DigitalSeries::GetNumberDigits() const               {return((digit==NULL) ? 0 : digit->GetEntriesFast());}
const I3Digital* I3DigitalSeries::GetDigit(unsigned short number) const {return((GetNumberDigits()<=number) ? NULL : (I3Digital*)digit->At(number));}
void             I3DigitalSeries::AddDigit(I3Digital* digit_)           {if(digit==NULL) digit = new TObjArray(1); digit->Add(digit_);}

