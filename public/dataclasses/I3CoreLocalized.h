#ifndef I3CORELOCALIZED_H
#define I3CORELOCALIZED_H

class I3CoreLocalized 
{
  Double_t fCoreX;
  Double_t fCoreY;
  Double_t fCoreT;
 public:
  Bool_t HasCorePosition() const { return kTRUE;}

  Double_t CoreX() const {return fCoreX;}
  void CoreX(Double_t corex) {fCoreX = corex;}

  Double_t CoreY() const {return fCoreY;}
  void CoreY(Double_t corey) {fCoreY = corey;}

  Double_t CoreT() const {return fCoreT;}
  void CoreT(Double_t coret) {fCoreT = coret;}
  ClassDef(I3CoreLocalized,1);
};

#endif
