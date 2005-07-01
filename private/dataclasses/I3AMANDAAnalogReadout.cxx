/**
 * copyright  (C) 2005
 * the IceCube Collaboration
 * $Id: $
 *
 * @file I3AMANDAAnalogReadout.cxx
 * @version $Revision: $
 * @date $Date: $
 * @author deyoung
 */

#include "dataclasses/I3AMANDAAnalogReadout.h"
#include <algorithm>

double I3AMANDAAnalogReadout::GetFirstLE() const {
  if(LEs_.size()==0)
    return NAN;

  vector<double> tmp=LEs_;
  sort(tmp.begin(),tmp.end());
  return tmp[0];
};

vector<double> I3AMANDAAnalogReadout::GetTOTs() {

  if (LEs_.size() != TEs_.size()) {
    // this is not true for AMANDA data, but this is fixed in the
    // f2k reader
    log_fatal("LEs.size() and TEs.size() should have same size");
  }

  vector<double> theTOTs(LEs_.size());

  for(unsigned int i = 0 ; i < LEs_.size() ; i++)
    {
      theTOTs[i] = TEs_[i] - LEs_[i];
    }
                                                                                                                                                             
  return theTOTs;
};
