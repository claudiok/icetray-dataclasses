#include "dataclasses/I3DataHeader.h"

I3DataHeader::I3DataHeader()
  : fMjd(0),
    fSec(0),
    fNanoSec(0){
}

I3DataHeader::~I3DataHeader(){
}

Int_t I3DataHeader::GetJulianDay(){
  return fMjd;
}

Int_t I3DataHeader::GetSec(){
  return fSec;
}

Int_t I3DataHeader::GetNanoSec(){
  return fNanoSec;
}

void I3DataHeader::SetJulianDay(Int_t day){
  fMjd = day;
}

void I3DataHeader::SetSec(Int_t sec){
  fSec = sec;
}

void I3DataHeader::SetNanoSec(Int_t nsec){
  fNanoSec = nsec;
}
