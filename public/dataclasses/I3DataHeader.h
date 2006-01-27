/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3DataHeader.h
 * @date $Date$
 */

#ifndef I3DATAHEADER_H_INCLUDED
#define I3DATAHEADER_H_INCLUDED

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
  I3DataHeader() : startTime_(), endTime_() { };

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
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);

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
typedef shared_ptr<I3DataHeader>  I3DataHeaderPtr;

#endif // I3DATAHEADER_H_INCLUDED

