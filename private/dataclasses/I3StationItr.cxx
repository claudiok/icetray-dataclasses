/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3StationItr.cxx,v 1.1 2004/09/17 21:18:15 niessen Exp $
 * @version $Revision: 1.1 $
 * @date $Date: 2004/09/17 21:18:15 $
 * @author niessen Thu Sep 16 17:24:51 EDT 2004
 */

#include "dataclasses/I3StationItr.h"

using namespace roost;

ClassImp (station_iterator);

// assignment
station_iterator &station_iterator::operator= (I3StationItr itr) {
  log_info ("station_iterator::operator=");
  I3StationItr::operator= (itr);
  // why no return in our model, I3OMSlr.cxx?
}

// incrementation
station_iterator &station_iterator::operator++ () {

  log_info ("station_iterator::operator=");
  I3StationItr::operator++ ();
  return *this;

}
