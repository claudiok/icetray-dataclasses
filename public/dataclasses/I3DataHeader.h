#ifndef I3DATAHEADER_H
#define I3DATAHEADER_H
/**
 * Class: I3DataHeader
 * 
 * Version: $Id: I3DataHeader.h,v 1.1 2004/01/30 21:00:25 pretz Exp $
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
 * @version $Id: I3DataHeader.h,v 1.1 2004/01/30 21:00:25 pretz Exp $
 * @author pretz
 */

class I3DataHeader : public TObject{
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
   * Gets the modified Julian day of the data event
   */
  Int_t GetJulianDay();

  /**
   * Gets the number of seconds after the julian day of the data event
   */
  Int_t GetSec();

  /**
   * The nanosecond part of the data event
   */
  Int_t GetNanoSec();

  /**
   * sets the julian day
   */
  void SetJulianDay(Int_t day);

  /**
   * sets the number of seconds since the julian day
   */
  void SetSec(Int_t sec);


  /**
   * sets the nanosecond part
   */
  void SetNanoSec(Int_t nsec);

  /**
   * The name of the stream on which the data occurs
   */
  virtual const Char_t* GetDataStream()=0;
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

  ClassDef(I3DataHeader,1);
};

#endif //I3DATAHEADER_H
