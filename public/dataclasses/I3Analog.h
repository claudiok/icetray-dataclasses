/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3Analog.h,v 1.2 2004/02/15 18:21:29 troy Exp $

    @version $Revision: 1.2 $
    @date $Date: 2004/02/15 18:21:29 $
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

