/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadoutDict.h,v 1.1 2004/06/30 21:24:36 pretz Exp $
 *
 * @file I3DataReadoutDict.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/06/30 21:24:36 $
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
class I3DataReadoutDict : public TObject, public MapPointainerPolicy<I3DataReadoutPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3DataReadoutDict(){};

  /**
   * destructor 
   */
  virtual ~I3DataReadoutDict(){};

 private:
  // copy and assignment are private
  I3DataReadoutDict(const I3DataReadout&);
  const I3DataReadoutDict& operator=(const I3DataReadout&);

  // ROOT macro
  ClassDef(I3DataReadoutDict,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadoutDict>::ThePolicy I3DataReadoutDictPtr;

#endif

