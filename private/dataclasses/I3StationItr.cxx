/**
 * copyright (C) 2004
 * the icecube collaboration
 * $Id: I3StationItr.cxx,v 1.3 2005/03/30 14:48:27 pretz Exp $
 * @version $Revision: 1.3 $
 * @date $Date: 2005/03/30 14:48:27 $
 * @author niessen Thu Sep 16 17:24:51 EDT 2004
 */

#include "dataclasses/I3StationItr.h"

using namespace boost;

ClassImp (station_iterator);

// assignment
station_iterator &station_iterator::operator= (I3StationItr itr) {
  log_info ("station_iterator::operator=");
  I3StationItr::operator= (itr);
  // why no return in our model, I3OMSlr.cxx?
  return *this;
}

// incrementation
station_iterator &station_iterator::operator++ () {

  log_info ("station_iterator::operator=");
  I3StationItr::operator++ ();
  return *this;

}
