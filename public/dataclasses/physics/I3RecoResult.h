/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3RecoResult.h
 * @date $Date$
 */

#ifndef I3RECORESULT_H_INCLUDED
#define I3RECORESULT_H_INCLUDED

#include <TObject.h>
#include "dataclasses/StoragePolicy.h"
#include <TClass.h>
#include <iostream>
#include <sstream>

/**
 *
 * @brief The base class from which all RecoResult's derive.  
 * 
 * Not much of an interface
 * since the various RecoResults are so diverse in what they can provide.
 */
class I3RecoResult : public TObject
{
 public:

  I3RecoResult(){}

  virtual ~I3RecoResult();

  /**
   * streams a RecoResult to an arbitrary ostream
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RecoResult ] Output withheld\n";
    }

  /**
   * streams a RecoResult to a std::string
   */
  string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// ROOT macro
  //ClassDef(I3RecoResult, 1);
};

/**
 * streams an I3RecoResult to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,I3RecoResult& result)
{
  result.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3RecoResult>  I3RecoResultPtr;

#endif //I3RECORESULT_H_INCLUDED

