#ifndef I3WAVEFORM_H
#define I3WAVEFORM_H

#include "TObject.h"
#include <vector>
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Waveform.h,v 1.1 2004/03/10 15:53:56 pretz Exp $
 *
 * I3Waveform is the basic waveform class.   Basically just an array of amplitudes
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 15:53:56 $
 * @author pretz
 *
 * @todo having trouble with this in ROOT session.  Try same interface differently
 */
class I3Waveform : public TObject, public vector<Double_t>{
  Double_t fBinSize;
  Double_t fStartTime;
 public:
  I3Waveform(){}
  virtual ~I3Waveform(){}
  Double_t BinSize() const {return fBinSize;}
  void BinSize(Double_t binsize) {fBinSize = binsize;}
  ClassDef(I3Waveform,1)
};

#endif //I3WAVEFORM_H
