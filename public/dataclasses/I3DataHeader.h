/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataHeader.h,v 1.12 2004/08/16 16:22:13 pretz Exp $
 *
 * @file I3DataHeader.h
 * @version $Revision: 1.12 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DATAHEADER_H
#define I3DATAHEADER_H

#include "TObject.h"
#include "TClass.h"
#include "StoragePolicy.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief This class represents a generic header for a data issued on some 
 * stream
 *
 * Just a 'time' right now, but there may be stuff to add later.
 */
class I3DataHeader : public TObject
{
 private:

  /**
   * the modified Julian day of the data
   */
  ULong_t fMjd;

  /**
   * the number of seconds after the fMjd
   */
  ULong_t fSec;

  /**
   * the nanosecond part of the time
   */
  ULong_t fNanoSec;


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
  ULong_t GetJulianDay() const { return fMjd; } 

  /**
   * @param day the new modified Julian day of the event
   */
  void SetJulianDay(ULong_t day) { fMjd = day; }

  /**
   * @return the number of seconds after the julian day of the data event
   */
  ULong_t GetSec() const { return fSec; }

  /**
   * @param sec the new number of seconds after the julian day of the 
   * data event
   */
  void SetSec(ULong_t sec) { fSec = sec; }

  /**
   * @return the nanosecond part of the data event
   */
  ULong_t GetNanoSec() { return fNanoSec; }

  /**
   * @param nsec the new nanosecond part of the data event
   */
  void SetNanoSec(ULong_t nsec) { fNanoSec = nsec; }

  /**
   * The name of the stream on which the data occurs
   */
  virtual const std::string GetDataStream()=0;

  virtual void ToStream(ostream& o) const
    {
      o<<"[ "
       <<IsA()->GetName()
       <<" ]\n"
       <<"Modified Julain Day: "
       <<fMjd
       <<"\n"
       <<"Seconds: "
       <<fSec
       <<"\n"
       <<"Nano Seconds: "
       <<fNanoSec
       <<"\n";
    }
  
 private:
  // ROOT Macro
  ClassDef(I3DataHeader,1);
};

inline ostream& operator<<(ostream& o,const I3DataHeader& header)
{
  header.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DataHeader>::ThePolicy I3DataHeaderPtr;

#endif //I3DATAHEADER_H
