#ifndef I3OMGEO_H
#define I3OMGEO_H

#include <TObject.h>
#include <TObjArray.h>

class I3OMGeo : public TObject
{
  protected:
  unsigned short omnumber;
  double         x;
  double         y;
  double         z;
  bool           orientation;
  unsigned char  version;

  public:
  I3OMGeo();

  unsigned short GetOMNumber() const;
  void           SetOMNumber(unsigned short omnumber_);

  double        GetX() const;
  double        GetY() const;
  double        GetZ() const;
  bool          GetOrientation() const;
  unsigned char GetVersion() const;

  void SetX(double x_);
  void SetY(double y_);
  void SetZ(double z_);
  void SetOrientation(bool orientation_);
  void SetVersion(unsigned char version_);

  ClassDef(I3OMGeo,1);
};
#endif

