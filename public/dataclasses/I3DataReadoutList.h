/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DataReadoutList.h,v 1.8 2004/02/22 14:26:36 pretz Exp $

    @version $Revision: 1.8 $
    @date $Date: 2004/02/22 14:26:36 $
    @author

    @todo

*/
#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

struct I3DataReadoutList : public VectorPolicy<I3DataReadout>::ThePolicy
{

/*   I3DataReadoutList(const I3DataReadout&); */
/*   const I3DataReadoutList& operator=(const I3DataReadout&); */

 public:

  I3DataReadoutList(){};
  ~I3DataReadoutList(){};

};



#endif

