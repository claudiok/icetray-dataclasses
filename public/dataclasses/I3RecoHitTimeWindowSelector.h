/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitTimeWindowSelector.h,v 1.1 2004/07/30 04:27:48 pretz Exp $
 *
 * @file I3RecoHitTimeWindowSelector.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 04:27:48 $
 * @author pretz
 */
#ifndef I3RECOHITTIMEWINDOWSELECTOR_H
#define I3RECOHITTIMEWINDOWSELECTOR_H

#include <vector>
#include "dataclasses/I3RecoHit.h"

using namespace std;

/**
 * @brief This class can be used to extract hits from an I3RecoHitSeries
 * that fall within a certain time window
 *
 * Check the SelectorTest.h for example usage
 */
class I3RecoHitTimeWindowSelector
{
 private:
  vector<I3RecoHitPtr>& fSelectedHits;
  Double_t fLowerBound;
  Double_t fUpperBound;

  // default constructor private
  I3RecoHitTimeWindowSelector();

 public:
  /**
   * @brief Built with a vector<I3RecoHitPtr> that it is supposed to extract
   * hits into
   * 
   * @param selected_hits the vector that we want to fill with hits
   * @param lower_bound the lowest time to select
   * @param upper_bound the highest time to select
   */
  I3RecoHitTimeWindowSelector(vector<I3RecoHitPtr>& selected_hits,
			      Double_t lower_bound,
			      Double_t upper_bound) :
    fSelectedHits(selected_hits),
    fLowerBound(lower_bound),
    fUpperBound(upper_bound) {}

  /**
   * @brief the operator that does the extraction. 
   */
  void operator()(I3RecoHitPtr p)
    {
      if(p->GetTime() >= fLowerBound && p->GetTime() <= fUpperBound)
	fSelectedHits.push_back(p);
    }

};

#endif // I3RECOHITTIMEWINDOWSELECTOR_H
