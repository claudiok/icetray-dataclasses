/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AnalogPulse.h,v 1.1 2004/03/10 02:42:24 pretz Exp $
 * One analog pulse from an OM.  
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 02:42:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */

#ifndef I3ANALOG_H
#define I3ANALOG_H

#include <TObject.h>
#include "StoragePolicy.h"

class I3AnalogPulse : public TObject
{
  Double_t  fLe;
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
  I3AnalogPulse() { Init(); }

  /**
   * copy constructor
   * @param rhs
   */
  I3AnalogPulse(const I3AnalogPulse& rhs){*this = rhs;}

  /**
   * assignment operator
   * @param rhs
   */
  const I3AnalogPulse& operator=(const I3AnalogPulse& rhs){
    if (this == &rhs) return *this; // check for assignment to self
    TObject::operator=(rhs); // call base class assignment operator
    fLe = rhs.fLe;
    fIntegratedcharge = rhs.fIntegratedcharge;
    fTot = rhs.fTot;
    fPeak = rhs.fPeak;
    return *this;
  }

  /**
   * @return the leading edge time of the pulse
   */
  Double_t  LE() const { return fLe; }

  /**
   * sets the leading edge time of the pulse
   * @param l the new leading edge time
   */
  void  LE(Double_t l)  { fLe = l; }

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
  ClassDef(I3AnalogPulse, 1);
};

typedef PtrPolicy<I3AnalogPulse>::ThePolicy I3AnalogPulsePtr;

#endif

