#ifndef I3OMSTATUS_H
#define I3OMSTATUS_H

#include <TObject.h>

#include "StoragePolicy.h"

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatus.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 * I3OMStatus is a base class for IceCube control parameters
 * for a single OM. The only local data members are the OM Number
 * and the PMT High Voltage.   Other functionality is in derived 
 * classes.
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 *
 * @todo 
 */
class I3OMStatus : public TObject
{
  UShort_t fOMNumber;
  Float_t fPMTHighVoltage;

  public:
  /**
   * constructor
   */
  I3OMStatus(){}

   /**
    * destructor
    */
  virtual ~I3OMStatus(){}

  /**
   * copy just uses assignment operator
   */
  I3OMStatus(const I3OMStatus& rhs){*this = rhs;}

  /**
   * assignment is just a direct member-wise assignment
   */
  const I3OMStatus& operator=(const I3OMStatus& rhs){
    if(this == &rhs) return *this;
    TObject::operator=(rhs);
    fOMNumber = rhs.fOMNumber;
    fPMTHighVoltage = rhs.fPMTHighVoltage;
    return *this;
  }

  /**
   * @return the number of the OM that this is the status for
   */
  UShort_t OMNumber() const {return fOMNumber;}

  /**
   * @param omnumber the new number for the om
   */
  void OMNumber(UShort_t omnumber) {fOMNumber = omnumber;}

  /**
   * @return the high voltage setting of the PMT
   */
  Float_t PMTHighVoltage() const {return fPMTHighVoltage;}

  /**
   * @param voltage the new high voltage for the OM.
   */
  void SetPMThighvoltage(Float_t voltage){fPMTHighVoltage = voltage;}

 private:

  //ROOT macro
  ClassDef(I3OMStatus,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3OMStatus>::ThePolicy I3OMStatusPtr;

#endif
