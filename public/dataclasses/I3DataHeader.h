#ifndef I3DATAHEADER_H
#define I3DATAHEADER_H
/**
 * Class: I3DataHeader
 * 
 * Version: $Id: I3DataHeader.h,v 1.3 2004/02/18 18:28:38 pretz Exp $
 *
 * Date: 11 Dec 2003
 *
 * (c) 2003 IceCube Collaboration
 */

#include "TObject.h"

/**
 * I3DataHeader
 * This class represents a generic header for a data issued on some stream
 * Just a 'time' right now, but there may be stuff to add later.
 *
 * @version $Id: I3DataHeader.h,v 1.3 2004/02/18 18:28:38 pretz Exp $
 * @author pretz
 */

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

  I3DataHeader();
  virtual ~I3DataHeader();

  /**
   * Gets the modified Julian day of the data event
   */
  Int_t JulianDay() const { return fMjd; } 
  void JulianDay(Int_t day) { fMjd = day; }

  /**
   * Gets the number of seconds after the julian day of the data event
   */
  Int_t Sec() const { return fSec; }
  void Sec(Int_t sec) { fSec = sec; }

  /**
   * The nanosecond part of the data event
   */
  Int_t NanoSec() { return fNanoSec; }
  void NanoSec(Int_t nsec) { fNanoSec = nsec; }

  /**
   * The name of the stream on which the data occurs
   */
  virtual const std::string DataStream()=0;
  ClassDef(I3DataHeader,1);
};

#endif //I3DATAHEADER_H
