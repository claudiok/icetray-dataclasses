/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadout.h,v 1.12 2004/07/12 12:23:11 pretz Exp $
 *
 * @file I3DataReadout.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/07/12 12:23:11 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include <TObject.h>
#include "StoragePolicy.h"
#include "TClass.h"
#include <iostream>

using namespace std;

/**
 * @brief A base class for all the data readout types. 
 */
class I3DataReadout : public TObject
{
  Bool_t fRaw;

  public:
  /**
   * default constructor
   */
  I3DataReadout(){};

  /**
   * default destructor
   */
  virtual ~I3DataReadout(){}

  /**
   * Indicates whether or not this readout came directly from the detector
   * or was put in later to emulate a particular kind of data.
   * @return kTRUE if this readout came directly from the detector
   */
  Bool_t IsRaw() const {return fRaw;}

  /**
   * establishes this I3DataReadout as either coming from the detector
   * or from some later processing.
   * @param raw kTRUE if it came straight from the detector
   */
  void SetRaw(Bool_t raw) {fRaw = raw;}

  /**
   * @todo finish implementing this method
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<" ]\n";
    }

 private:
  // copy and assignment are private
  I3DataReadout(const I3DataReadout& rhs); 
  const I3DataReadout& operator=(const I3DataReadout& rhs); 

  // ROOT Macro
  ClassDef(I3DataReadout,1);
};

inline ostream& operator<<(ostream& o,const I3DataReadout& readout)
{
  readout.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadout>::ThePolicy I3DataReadoutPtr;

#endif

