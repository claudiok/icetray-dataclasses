/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMSlr.cxx,v 1.3 2004/10/25 23:30:07 pretz Exp $
 *
 * @file I3OMSlr.cxx
 * @version $Revision: 1.3 $
 * @date $Date: 2004/10/25 23:30:07 $
 * @author deyoung
 */

#warning I3OMSlr problems, fixme
#if 1

#ifndef I3OMSLR_CXX_INCLUDED
#define I3OMSLR_CXX_INCLUDED

#include "dataclasses/I3OMSlr.h"

using namespace std;

I3OMSlr& I3OMSlr::IncrementUntil(I3OMItr limit) {
    log_debug("Enter operator++(itr).");
    I3OMItr::operator++();
    while( ( *this != limit) &&
	   (!IsSelected(*this)) ) {
	I3OMItr::operator++();
    };
    log_debug("Exit operator++.");
    return *this;
};

void I3OMSlr::SetLimit(I3OMItr limit) {
    fTheEnd = limit;
};

I3OMSlr& I3OMSlr::operator++() {
    log_debug("Enter operator++.");
    I3OMItr::operator++();
    while( ( *this != fTheEnd) &&
	 (!IsSelected(*this)) ) {
	I3OMItr::operator++();
    };
    log_debug("Exit operator++.");
    return *this;
};


I3OMSlr I3OMSlr::operator++(int) {
    log_debug("Enter operator++(int).");
    I3OMSlr temp = *this;
    operator++();
    log_debug("Exit operator++(int).");
    return temp;
};

I3OMSlr& I3OMSlr::operator=(I3OMItr itr) {
    log_debug("Calling operator=");
    I3OMItr::operator=(itr);

    if (!IsSelected(itr)) {
	operator++();
    }	
};

const I3OMSlrPtr I3OMSlr::GetCopy() {
    I3OMSlrPtr theCopy(new I3OMSlr);
    return theCopy;
};

#endif //I3OMSLR_CXX_INCLUDED
#endif
