#include "dataclasses/I3RecoResultTensor.h"

ClassImp(I3RecoResultTensor);

I3RecoResultTensor::I3RecoResultTensor()  {number=0; moment=NULL;}
I3RecoResultTensor::~I3RecoResultTensor() {delete [] moment;}

Int_t          I3RecoResultTensor::GetNumber() const {return number;}
const Float_t* I3RecoResultTensor::GetMoment() const {return moment;}
void           I3RecoResultTensor::SetMoment(Float_t* moment_, Int_t number_) {moment=moment_; number=number_;}
