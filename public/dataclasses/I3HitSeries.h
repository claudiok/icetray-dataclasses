#ifndef I3HITSERIES_H
#define I3HITSERIES_H

#include <TObject.h>
#include <TObjArray.h>
#include "I3Hit.h"

class I3HitSeries : public TObject
{
  protected:
  TObjArray  *hit;

  public:
           I3HitSeries();
  virtual ~I3HitSeries();

  int                  GetNumberHits() const;
  virtual const I3Hit* GetHit(unsigned short number) const;
  virtual void         AddHit(I3Hit* hit_);

  ClassDef(I3HitSeries, 1);
};
#endif
