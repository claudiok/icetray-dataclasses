#ifndef I3FILTERDATA_H
#define I3FILTERDATA_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterData.h,v 1.2 2004/02/25 20:10:24 pretz Exp $
 *
 * A place-holder for the filter data in the event.  No implementation
 * yet.  No real thought, as far as I know, on what should be in here.
 *
 * @version $Revision: 1.2 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo design and implement this class
 */
#include <TObject.h>
#include "StoragePolicy.h"

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

