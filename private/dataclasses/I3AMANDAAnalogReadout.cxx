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

using namespace std;

double I3AMANDAAnalogReadout::GetFirstLE() const
{
  if(LEs_.empty()) return NAN;

  if(processFirstLE_)
  {
    vector<double> tmp = LEs_;
    sort(tmp.begin(),tmp.end());
    firstLE_ = tmp[0];
    processFirstLE_ = false;
  }
  
  return firstLE_;
}

const vector<double>& I3AMANDAAnalogReadout::GetTOTs() const
{
  if(processTOTs_)
  {
    // this is not true for AMANDA data, but this is fixed in the
    // f2k reader
    if (LEs_.size() != TEs_.size())
      log_fatal("LEs.size() and TEs.size() should have same size");

    TOTs_.resize(LEs_.size());
    transform(TEs_.begin(), TEs_.end(), LEs_.begin(), TOTs_.begin(), minus<double>());
    processTOTs_ = false;
  }
                                                                                                                            
  return TOTs_;
}
