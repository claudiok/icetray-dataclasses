#ifndef I3ANALOG_H
#define I3ANALOG_H

#include <TObject.h>

class I3Analog : public TObject
{
  unsigned long  time;
  unsigned long  let;
  float          integratedcharge;
  unsigned short tot;
  float          peak;

  public:
  I3Analog();

  unsigned long  GetTime() const;
  unsigned long  GetLet() const;
  float          GetIntegratedCharge() const;
  unsigned short GetTot() const;
  float          GetPeak() const;

  void SetTime(unsigned long time_);
  void SetLet(unsigned long let_);
  void SetIntegratedCharge(float integratedcharge_);
  void SetTot(unsigned short tot_);
  void SetPeak(float peak_);

  ClassDef(I3Analog, 1);
};
#endif

