/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DataHeader.h,v 1.15 2005/03/29 20:27:53 pretz Exp $
 *
 * @file I3DataHeader.h
 * @version $Revision: 1.15 $
 * @date $Date: 2005/03/29 20:27:53 $
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
  I3Time startTime_;
  I3Time endTime_;
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
   * Gets the start Time for this header
   */
  const I3Time& GetStartTime() const { return startTime_;}

  /**
   * Sets the start Time for this header
   */
  void SetStartTime(const I3Time& t) { startTime_ = t;}

  /**
   * Sets the ending time for this header
   */
  void SetEndTime(const I3Time& t){endTime_ = t;}

  /**
   * Gets the ending time for this header
   */
  const I3Time& GetEndTime() const { return endTime_;}

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
