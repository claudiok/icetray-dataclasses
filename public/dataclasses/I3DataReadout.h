#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadout.h,v 1.5 2004/02/25 20:10:24 pretz Exp $
 *
 * A base class for all the data readout types.  
 *
 * @version $Revision: 1.5 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo decide whether or not the copy should be private
 */

#include <TObject.h>
#include <TObjArray.h>
#include "StoragePolicy.h"

class I3DataReadout : public TObject
{
  public:
  /**
   * default constructor
   */
  I3DataReadout(){};

  /**
   * default destructor
   */
  virtual ~I3DataReadout(){}

  // not needed, I think because of the type-wise iteration
  // const char* GetReadoutType() const;

 private:
  // copy and assignment are private
/*   I3DataReadout(const I3DataReadout& rhs); */
/*   const I3DataReadout& operator=(const I3DataReadout& rhs); */

  // ROOT Macro
  ClassDef(I3DataReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadout>::ThePolicy I3DataReadoutPtr;

#endif

