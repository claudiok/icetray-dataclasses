/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatus.h,v 1.4 2004/07/30 15:08:55 pretz Exp $
 *
 * @file I3OMStatus.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/30 15:08:55 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 */
#ifndef I3OMSTATUS_H
#define I3OMSTATUS_H

#include <TObject.h>

#include "StoragePolicy.h"

/**
 * @brief I3OMStatus is a base class for IceCube control parameters
 * for a single OM. 
 * 
 * The only local data members are the OM Number
 * and the PMT High Voltage.   Other functionality is in derived 
 * classes.
 */
class I3OMStatus : public TObject
{
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
    fPMTHighVoltage = rhs.fPMTHighVoltage;
    return *this;
  }

  /**
   * @return the high voltage setting of the PMT
   */
  Float_t GetPMTHighVoltage() const {return fPMTHighVoltage;}

  /**
   * @param voltage the new high voltage for the OM.
   */
  void SetPMTHighVoltage(Float_t voltage){fPMTHighVoltage = voltage;}

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
