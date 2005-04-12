/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMStatus.h,v 1.9 2005/04/12 18:55:28 dule Exp $
 *
 * @file I3OMStatus.h
 * @version $Revision: 1.9 $
 * @date $Date: 2005/04/12 18:55:28 $
 * @author Spencer Klein (design)
 * @author pretz (implementation)
 */
#ifndef I3OMSTATUS_H
#define I3OMSTATUS_H

#include <TObject.h>
#include <TClass.h>
#include <sstream>
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
  float PMTHighVoltage_;

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
    PMTHighVoltage_ = rhs.PMTHighVoltage_;
    return *this;
  }

  /**
   * @return the high voltage setting of the PMT
   */
  float GetPMTHighVoltage() const {return PMTHighVoltage_;}

  /**
   * @param voltage the new high voltage for the OM.
   */
  void SetPMTHighVoltage(float voltage){PMTHighVoltage_ = voltage;}

  virtual void ToStream(ostream& o) const
    {
      o<<IsA()->GetName()<<"\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  //ROOT macro
  ClassDef(I3OMStatus,1);
};

/**
 * @todo needs to be flushed out more
 */
inline ostream& operator<<(ostream& o,const I3OMStatus& status)
{
  status.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3OMStatus>  I3OMStatusPtr;

#endif
