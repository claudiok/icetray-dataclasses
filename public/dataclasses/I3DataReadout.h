#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadout.h,v 1.3 2004/02/25 16:27:46 pretz Exp $
 *
 * A base class for all the data readout types.  
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/02/25 16:27:46 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */

#include <TObject.h>
#include <TObjArray.h>

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
  I3DataReadout(const I3DataReadout& rhs);
  const I3DataReadout& operator=(const I3DataReadout& rhs);

  // ROOT Macro
  ClassDef(I3DataReadout,1);
};

typedef I3DataReadout* I3DataReadoutPtr;

#endif

