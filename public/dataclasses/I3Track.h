#ifndef I3TRACK_H
#define I3TRACK_H

#include <TObject.h>
#include <TObjArray.h>
#include <TRef.h>
#include <TRefArray.h>

class I3Track : public TObject
{
  unsigned short tracknumber;
  unsigned short particletype;
  float          starttime;
  float          startx;
  float          starty;
  float          startz;
  float          stoptime;
  float          stopx;
  float          stopy;
  float          stopz;
  float          length;
  float          zenith;
  float          azimuth;
  float          energy;
  TRef           parenttrack;
  TRefArray      *childrentrack;

  public:
           I3Track();
  virtual ~I3Track();
    
  unsigned short GetTracknumber() const;
  unsigned short GetParticletype() const;
  float          GetStarttime() const;
  float          GetStartx() const;
  float          GetStarty() const;
  float          GetStartz() const;
  float          GetStoptime() const;
  float          GetStopx() const;
  float          GetStopy() const;
  float          GetStopz() const;
  float          GetLength() const;
  float          GetZenith() const;
  float          GetAzimuth() const;
  float          GetEnergy() const;

  void SetTracknumber(unsigned short tracknumber_);
  void SetParticletype(unsigned short particletype_);
  void SetStarttime(float time);
  void SetStartx(float x);
  void SetStarty(float y);
  void SetStartz(float z);
  void SetStoptime(float time);
  void SetStopx(float x);
  void SetStopy(float y);
  void SetStopz(float z);
  void SetLength(float length_);
  void SetZenith(float zenith_);
  void SetAzimuth(float azimuth_);
  void SetEnergy(float energy_);
  
  bool           IsParenttrack() const;
  const I3Track* GetParenttrack() const;
  void           SetParenttrack(I3Track* parenttrack_);

  unsigned short GetNumberChildrentracks() const;
  const I3Track* GetChildrentrack(unsigned short number) const;
  void           AddChildrentrack(I3Track* childrentrack_);

  ClassDef(I3Track, 1);
};
#endif
