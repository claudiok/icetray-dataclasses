#ifndef I3AMANDAANALOGREADOUT_H
#define I3AMANDAANALOGREADOUT_H

#include "I3AnalogReadout.h"
#include "I3DataReadout.h"
#include "StoragePolicy.h"

#include <vector>

using namespace std;

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AMANDAAnalogReadout.h,v 1.1 2004/03/10 02:42:24 pretz Exp $
 *
 * An 'AMANDA' readout.  The 'old-style' before the TWR was added.  
 * Includes a series of LE's and TOT's and a single Amplitude
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/10 02:42:24 $
 * @author pretz
 *
 *  @todo
 *
 */
class I3AMANDAAnalogReadout : public I3AnalogReadout
{ 
  vector<Double_t> fLEs;
  vector<Double_t> fTOTs;
  Double_t fAmp;
 public:
  /**
   * constructor
   */
  I3AMANDAAnalogReadout(){}

  /**
   * destructor
   */
  virtual ~I3AMANDAAnalogReadout() {;}

  /**
   * @return the time of the first LE in the readout
   */
  virtual Double_t FirstLE() const {
    if(fLEs.size() >0) 
      return fLEs[0]; 
    return 0;
  }

  const vector<Double_t>& LEs() const {return fLEs;}

  vector<Double_t>& LEs(){return fLEs;}

  const vector<Double_t>& TOTs() const {return fTOTs;}

  vector<Double_t>& TOTs() {return fTOTs;}

  Double_t Amplitude() const {return fAmp;}

 private:
  // copy and assignment private
  I3AMANDAAnalogReadout(const I3AMANDAAnalogReadout &);
  const I3AMANDAAnalogReadout& operator=(const I3AMANDAAnalogReadout&);

  // ROOT macro
  ClassDef(I3AMANDAAnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AMANDAAnalogReadout>::ThePolicy I3AMANDAAnalogReadoutPtr;
#endif

