/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterData.h,v 1.3 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3FilterData.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3FILTERDATA_H
#define I3FILTERDATA_H

#include <TObject.h>
#include "StoragePolicy.h"

/**
 * @brief A place-holder for the filter data in the event.  No implementation
 * yet.  
 *
 * No real thought, as far as I know, on what should be in here.
 * @todo design and implement this class
 *
 */
class I3FilterData : public TObject
{
 public:
  /**
   * constructor
   */
  I3FilterData(){};

  /**
   * destructor
   */
  virtual ~I3FilterData(){};

 private:
  // ROOT Macro
  ClassDef(I3FilterData, 1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3FilterData>::ThePolicy I3FilterDataPtr;

#endif

