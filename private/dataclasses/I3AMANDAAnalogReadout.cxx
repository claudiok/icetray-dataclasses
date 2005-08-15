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
#include <functional>

double I3AMANDAAnalogReadout::GetFirstLE() const
{
  if(LEs_.size()==0)
    return NAN;

  vector<double> tmp=LEs_;
  sort(tmp.begin(),tmp.end());
  return tmp[0];
}

const vector<double>& I3AMANDAAnalogReadout::GetTOTs() const
{
  if(calculateTOTs_)
  {
    // this is not true for AMANDA data, but this is fixed in the
    // f2k reader
    if (LEs_.size() != TEs_.size())
      log_fatal("LEs.size() and TEs.size() should have same size");

    TOTs_.resize(LEs_.size());
    transform(TEs_.begin(), TEs_.end(), LEs_.begin(), TOTs_.begin(), minus<double>());
    calculateTOTs_ = false;
  }
                                                                                                                            
  return TOTs_;
}
