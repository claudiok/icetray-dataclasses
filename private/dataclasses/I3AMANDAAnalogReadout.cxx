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

  // This is quite long, but I'm not sure I can assume that the LEs
  // and TEs vectors are sorted properly, so I'll generate the
  // match-ups as well as the differences on the fly.

  vector<double> theTOTs;

  if (LEs_.size() == 0 || TEs_.size() == 0) {
    return theTOTs;
  }

  for (vector<double>::const_iterator LEiter = LEs_.begin();
       LEiter != LEs_.end(); LEiter++) { 

    if (isnan(*LEiter)) continue;

    double nextTE = NAN;
    for (vector<double>::const_iterator TEiter = TEs_.begin();
	 TEiter != TEs_.end(); TEiter++) {

      if (isnan(*TEiter)) continue;

      if ((*TEiter > *LEiter) &&
	  isnan(nextTE) || *TEiter < nextTE) {
	nextTE = *TEiter;
      }
    } 

    if (!isnan(nextTE)) {
      theTOTs.push_back(*LEiter - nextTE);
    }
  }

  return theTOTs;
};
