/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3AnalogReadout.h,v 1.3 2004/04/27 02:32:05 pretz Exp $
 *
 * @file I3AnalogReadout.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/04/27 02:32:05 $
 * @author pretz
 */
#ifndef I3ANALOGREADOUT_H
#define I3ANALOGREADOUT_H

#include "dataclasses/I3DataReadout.h"
#include "StoragePolicy.h"

/**
 * @brief The base for all the I3Analog types of DataReadout.  
 * 
 * Just a 'time' which
 * is the first 'LeadingEdge' time. 
 */
class I3AnalogReadout : public I3DataReadout
{ 
 public:
  /**
   * constructor
   */
  I3AnalogReadout(){}

  /**
   * destructor
   */
  virtual ~I3AnalogReadout() {;}

  /**
   * @return the time of the first LE in the readout
   */
  virtual Double_t FirstLE() const = 0;

 private:
  // copy and assignment private
  I3AnalogReadout(const I3AnalogReadout &);
  const I3AnalogReadout& operator=(const I3AnalogReadout&);

  // ROOT macro
  ClassDef(I3AnalogReadout,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3AnalogReadout>::ThePolicy I3AnalogReadoutPtr;
#endif

