/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadoutList.h,v 1.14 2004/03/10 02:42:24 pretz Exp $
 *
 * Just an list of I3DataReadouts.  
 *
 * @version $Revision: 1.14 $
 * @date $Date: 2004/03/10 02:42:24 $
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

class I3DataReadoutList : public MapPolicy<I3DataReadoutPtr>::ThePolicy
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

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadoutList>::ThePolicy I3DataReadoutListPtr;

#endif

