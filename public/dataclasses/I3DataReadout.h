/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataReadout.h,v 1.8 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3DataReadout.h
 * @version $Revision: 1.8 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */
#ifndef I3DATAREADOUT_H
#define I3DATAREADOUT_H

#include <TObject.h>
#include <TObjArray.h>
#include "StoragePolicy.h"
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
  Bool_t Raw() const {return fRaw;}

  /**
   * establishes this I3DataReadout as either coming from the detector
   * or from some later processing.
   * @param raw kTRUE if it came straight from the detector
   */
  void Raw(Bool_t raw) {fRaw = raw;}

 private:
  // copy and assignment are private
  I3DataReadout(const I3DataReadout& rhs); 
  const I3DataReadout& operator=(const I3DataReadout& rhs); 

  // ROOT Macro
  ClassDef(I3DataReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataReadout>::ThePolicy I3DataReadoutPtr;

#endif

