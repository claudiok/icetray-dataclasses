/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Filter.h 11091 2005-09-27 09:32:13Z troy $
 *
 * @file I3Filter.h
 * @version $Revision: 1.5 $
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 * @author blaufuss
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3FILTER_H
#define I3FILTER_H

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>

#include "dataclasses/StoragePolicy.h"

using namespace std; 

/**
 * @brief The basic Filter class.  
 * 
 * This is the base class for trigger records that will live in the I3FilterDict.
 */
class I3Filter : public TObject
{
public:
  
  /**
   * An enumerated type for if the Filter pass
   */
  enum FilterPass { No = 0, Yes = 1};
  
  I3Filter() {;}
  
  virtual ~I3Filter() {;}
  
  
  virtual const string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  }
  
  virtual void ToStream(ostream& o) const
  {
    o<<"[I3Filter:   FilterPass:"<<filterPass_;
  }
  
private:
  FilterPass filterPass_;       // Did the event pass this filter
  
  friend class boost::serialization::access;
  
  template <class Archive> void serialize(Archive & ar, unsigned version);
  ClassDef(I3Filter,1);
};

/**
 * streams an I3Filter to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3Filter& filt)
{
  filt.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3Filter> I3FilterPtr;

#endif


