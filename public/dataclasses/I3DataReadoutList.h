/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DataReadoutList.h,v 1.7 2004/02/21 18:52:38 troy Exp $

    @version $Revision: 1.7 $
    @date $Date: 2004/02/21 18:52:38 $
    @author

    @todo

*/
#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

struct I3DataReadoutList : public VectorPolicy<I3DataReadout>::ThePolicy
{

  I3DataReadoutList(const I3DataReadout&);
  const I3DataReadoutList& operator=(const I3DataReadout&);

 public:

  I3DataReadoutList();
  ~I3DataReadoutList();

};



#endif

