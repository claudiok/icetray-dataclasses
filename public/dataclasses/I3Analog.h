/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Analog.h,v 1.3 2004/02/22 14:26:36 pretz Exp $

    @version $Revision: 1.3 $
    @date $Date: 2004/02/22 14:26:36 $
    @author

    @todo

*/
#ifndef I3ANALOG_H
#define I3ANALOG_H

#include <TObject.h>

class I3Analog : public TObject
{
  ULong_t  fTime;
  ULong_t  fLet;
  Float_t          fIntegratedcharge;
  UShort_t fTot;
  Float_t          fPeak;

  public:
  void Init();

  I3Analog() { Init(); }
  I3Analog(const I3Analog& rhs){*this = rhs;}
  const I3Analog& operator=(const I3Analog& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    TObject::operator=(rhs); // call base class assignment operator
    fTime = rhs.fTime;
    fLet = rhs.fLet;
    fIntegratedcharge = rhs.fIntegratedcharge;
    fTot = rhs.fTot;
    fPeak = rhs.fPeak;
    return *this;
  }

  ULong_t  Time() const { return fTime; }
  void  Time(ULong_t t) { fTime = t; }

  ULong_t  Let() const { return fLet; }
  void  Let(ULong_t l)  { fLet = l; }

  Float_t IntegratedCharge() const { return fIntegratedcharge; }
  void IntegratedCharge(Float_t i) { fIntegratedcharge = i; }

  UShort_t Tot() const { return fTot; }
  void Tot(UShort_t t) { fTot = t; }
  
  Float_t Peak() { return fPeak; }
  void Peak(Float_t peak_) { fPeak = peak_; }

  ClassDef(I3Analog, 1);
};
#endif

