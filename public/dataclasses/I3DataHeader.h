/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataHeader.h,v 1.14 2005/03/29 17:55:01 pretz Exp $
 *
 * @file I3DataHeader.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005/03/29 17:55:01 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3DATAHEADER_H
#define I3DATAHEADER_H

#include "TObject.h"
#include "TClass.h"
#include "StoragePolicy.h"
#include "I3Time.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief This class represents a generic header for a data issued on some 
 * stream
 *
 * Just a 'time' right now, but there may be stuff to add later.
 */
class I3DataHeader : public TObject
{
  I3Time time_;
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
   * Gets the Time for this header
   */
  const I3Time& GetTime() const { return time_;}

  /**
   * Sets the Time for this header
   */
  void SetTime(const I3Time& t) { time_ = t;}

  virtual void ToStream(ostream& o) const
    {
/*       o<<"[ " */
/*        <<IsA()->GetName() */
/*        <<" ]\n" */
/*        <<"Modified Julain Day: " */
/*        <<fMjd */
/*        <<"\n" */
/*        <<"Seconds: " */
/*        <<fSec */
/*        <<"\n" */
/*        <<"Nano Seconds: " */
/*        <<fNanoSec */
/*        <<"\n"; */
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
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
