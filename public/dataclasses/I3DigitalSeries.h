#ifndef I3DIGITALSERIES_H
#define I3DIGITALSERIES_H

#include "I3Datareadout.h"
#include "I3Digital.h"

class I3DigitalSeries : public I3Datareadout
{
 protected:
  double    starttime;
  float     binwidth;
  TObjArray *digit;
  
 public:
  I3DigitalSeries();
  ~I3DigitalSeries();
  
  double GetStartTime() const;
  float  GetBinWidth() const;
  void   SetStartTime(double starttime_);
  void   SetBinWidth(float binwidth_);
  
  int GetNumberDigits() const;
  const I3Digital& GetDigit(unsigned short number) const;
  void AddDigit(I3Digital* digit_);
  
  ClassDef(I3DigitalSeries,1);
};
#endif

