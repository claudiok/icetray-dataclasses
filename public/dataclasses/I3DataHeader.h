#ifndef I3DATAHEADER_H
#define I3DATAHEADER_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataHeader.h,v 1.6 2004/02/25 20:10:24 pretz Exp $
 *
 * I3DataHeader
 * This class represents a generic header for a data issued on some stream
 * Just a 'time' right now, but there may be stuff to add later.
 *
 * @version $Revision: 1.6 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 */

#include "TObject.h"
#include "StoragePolicy.h"

class I3DataHeader : public TObject
{
 private:

  /**
   * the modified Julian day of the data
   */
  Int_t fMjd;

  /**
   * the number of seconds after the fMjd
   */
  Int_t fSec;

  /**
   * the nanosecond part of the time
   */
  Int_t fNanoSec;


 public: 
  /**
   * constructor
   */
  I3DataHeader();

  /**
   * destructor
   */
  virtual ~I3DataHeader();

  /**
   * copy constructor.  uses assignment operator
   */
  I3DataHeader(const I3DataHeader& rhs){*this = rhs;}

  /**
   * assignment operator.  A simple memeber-wise copy
   */
  const I3DataHeader& operator=(const I3DataHeader& rhs){
    if(this == &rhs) return *this;
    TObject::operator=(rhs);
    fMjd = rhs.fMjd;
    fNanoSec = rhs.fNanoSec;
    fSec = rhs.fSec;
    return *this;
  }

  /**
   * @return the modified Julian day of the data event
   */
  Int_t JulianDay() const { return fMjd; } 

  /**
   * @param day the new modified Julian day of the event
   */
  void JulianDay(Int_t day) { fMjd = day; }

  /**
   * @return the number of seconds after the julian day of the data event
   */
  Int_t Sec() const { return fSec; }

  /**
   * @param the new number of seconds after the julian day of the data event
   */
  void Sec(Int_t sec) { fSec = sec; }

  /**
   * @return the nanosecond part of the data event
   */
  Int_t NanoSec() { return fNanoSec; }

  /**
   * @param the new nanosecond part of the data event
   */
  void NanoSec(Int_t nsec) { fNanoSec = nsec; }

  /**
   * The name of the stream on which the data occurs
   */
  virtual const std::string DataStream()=0;

  // ROOT Macro
  ClassDef(I3DataHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataHeader>::ThePolicy I3DataHeaderPtr;

#endif //I3DATAHEADER_H
