/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMSlrList.cxx,v 1.3 2004/10/25 23:30:07 pretz Exp $
 *
 * @file I3OMSlrList.cxx
 * @version $Revision: 1.3 $
 * @date $Date: 2004/10/25 23:30:07 $
 * @author deyoung
 */

#warning I3OMSlr Problems, fixme
#if 1
#ifndef I3OMSLRLIST_CXX_INCLUDED
#define I3OMSLRLIST_CXX_INCLUDED

#include "dataclasses/I3OMSlrList.h"

using namespace roost;

Bool_t I3OMSlrList::IsSelected(const I3OMItr current_omr) {
    if (find(fGoodOMs.begin(), fGoodOMs.end(), current_omr->first) 
	== fGoodOMs.end()) {
	log_debug("IsSelected returns false.");
	return kFALSE;
    } else {
	log_debug("IsSelected returns true.");
	return kTRUE;
    };
};

const I3OMSlrPtr I3OMSlrList::GetCopy() {
    I3OMSlrListPtr theCopy(new I3OMSlrList);
    theCopy->SetGoodOMs(fGoodOMs);
    I3OMSlrPtr baseCopy = theCopy;
    return baseCopy;
}  

void I3OMSlrList::SetGoodOMs(const vector<OMKey>& good_list) {
    log_debug("Setting good OMs:");
    for (Int_t i = 0; i < good_list.size(); i++) {
	log_debug("   OM %i on string %i", good_list[i].GetOM(),
		  good_list[i].GetString());
    }
    fGoodOMs = good_list;
    log_debug("Exit set.");
};

void I3OMSlrList::PrintGoodOMs() {
    for (int i = 0; i < fGoodOMs.size(); i++) {
	log_debug("OM %i on string %i is good.", fGoodOMs[i].GetOM(),
		  fGoodOMs[i].GetString());
    }
};

#endif //I3OMSLRLIST_CXX_INCLUDED
#endif
