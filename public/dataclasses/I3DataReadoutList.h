/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadoutList.h,v 1.11 2004/02/25 00:32:37 pretz Exp $
 *
 * Just an list of I3DataReadouts.  
 *
 * @version $Revision: 1.11 $
 * @date $Date: 2004/02/25 00:32:37 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo Shouldn't this be a list of DataReadoutPtrs ???
 */
#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

class I3DataReadoutList : public VectorPolicy<I3DataReadout>::ThePolicy
{


 public:
  /**
   * constructor
   */ 
  I3DataReadoutList(){};

  /**
   * destructor 
   */
  virtual ~I3DataReadoutList(){};

 private:
  // copy and assignment are private
  I3DataReadoutList(const I3DataReadout&);
  const I3DataReadoutList& operator=(const I3DataReadout&);

  // ROOT macro
  ClassDef(I3DataReadoutList,1);
};

typedef I3DataReadoutList* I3DataReadoutListPtr;

#endif

