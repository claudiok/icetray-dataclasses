/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadoutList.h,v 1.19 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3DataReadoutList.h
 * @version $Revision: 1.19 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */

#ifndef I3DATAREADOUTLIST_H
#define I3DATAREADOUTLIST_H

#include "I3DataReadout.h"
#include "StoragePolicy.h"

/**
 * @brief Just an list of I3DataReadouts.  
 */
class I3DataReadoutList : public TObject, public MapPointainerPolicy<I3DataReadoutPtr>::ThePolicy
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

