/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3DataReadoutList.h,v 1.10 2004/02/24 14:41:30 pretz Exp $

    @version $Revision: 1.10 $
    @date $Date: 2004/02/24 14:41:30 $
    @author

    @todo

*/
#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

class I3DataReadoutList : public VectorPolicy<I3DataReadout>::ThePolicy
{

/*   I3DataReadoutList(const I3DataReadout&); */
/*   const I3DataReadoutList& operator=(const I3DataReadout&); */

 public:


  I3DataReadoutList(){};
  virtual ~I3DataReadoutList(){};

  ClassDef(I3DataReadoutList,1);
};

typedef I3DataReadoutList* I3DataReadoutListPtr;

#endif

