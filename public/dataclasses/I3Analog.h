/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Analog.h,v 1.8 2004/02/26 19:58:26 pretz Exp $
 * One analog pulse from an OM.  
 *
 * @version $Revision: 1.8 $
 * @date $Date: 2004/02/26 19:58:26 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo What are the units here???
 * @todo What's the difference between Time() and LET()
 */

#ifndef I3ANALOG_H
#define I3ANALOG_H

#include <TObject.h>
#include "StoragePolicy.h"

class I3Analog : public TObject
{
  Double_t  fTime;
  Double_t  fLet;
  Float_t          fIntegratedcharge;
  Double_t fTot;
  Float_t          fPeak;

  public:
  /**
   * sets the data to 0
   */
  void Init();

  /**
   * default constructor
   */
  I3Analog() { Init(); }

  /**
   * copy constructor
   * @param rhs
   */
  I3Analog(const I3Analog& rhs){*this = rhs;}

  /**
   * assignment operator
   * @param rhs
   */
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

  /**
   * @return the time of the pulse
   */
  Double_t  Time() const { return fTime; }

  /**
   * @param t the time of the pulse
   */
  void  Time(Double_t t) { fTime = t; }

  /**
   * @return the leading edge time of the pulse
   */
  Double_t  LET() const { return fLet; }

  /**
   * sets the leading edge time of the pulse
   * @param l the new leading edge time
   */
  void  LET(Double_t l)  { fLet = l; }

  /**
   * @return the integrated charge
   */
  Float_t IntegratedCharge() const { return fIntegratedcharge; }

  /**
   * @param i the new integrated charge
   */
  void IntegratedCharge(Float_t i) { fIntegratedcharge = i; }

  /**
   * retrieves the time over threshold
   * @return the time over threshold
   */
  Double_t TOT() const { return fTot; }

  /**
   * @param t the new tot
   */
  void TOT(Double_t t) { fTot = t; }
  
  /**
   * @return the peak value
   */
  Float_t Peak() { return fPeak; }

  /**
   * @param peak the new peak value
   */
  void Peak(Float_t peak) { fPeak = peak; }

 private:
  // ROOT macro
  ClassDef(I3Analog, 1);
};

typedef PtrPolicy<I3Analog>::ThePolicy I3AnalogPtr;

#endif

