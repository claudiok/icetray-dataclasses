#ifndef I3WAVEFORM_H
#define I3WAVEFORM_H

#include "TObject.h"
#include <vector>
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Waveform.h,v 1.2 2004/03/10 17:54:43 pretz Exp $
 *
 * I3Waveform is the basic waveform class.   Basically just an array of amplitudes.  Also has a start time and a bin size.
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/03/10 17:54:43 $
 * @author pretz
 *
 * @todo having trouble with this in ROOT session.  Try same interface differently
 */
class I3Waveform : public TObject, public vector<Double_t>{
  Double_t fBinSize;
  Double_t fStartTime;
 public:
  /**
   * constructor
   */
  I3Waveform(){}

  /**
   * copy just uses assignment
   */
  I3Waveform(const I3Waveform& rhs){*this = rhs;}

  /**
   * assignment is a member-wise assignment
   */
  const I3Waveform& operator=(const I3Waveform& rhs){
    if(this == &rhs) return *this;
    TObject::operator=(rhs);
    vector<Double_t>::operator=(rhs);
    fBinSize = rhs.fBinSize;
    fStartTime = rhs.fStartTime;
    return *this;
  }

  /**
   * destructor
   */
  virtual ~I3Waveform(){}

  /**
   * @return the size of the time bins in this waveform
   */
  Double_t BinSize() const {return fBinSize;}

  /**
   * @param binsize is the new binsize for this waveform
   */
  void BinSize(Double_t binsize) {fBinSize = binsize;}


  ClassDef(I3Waveform,1)
};

#endif //I3WAVEFORM_H
