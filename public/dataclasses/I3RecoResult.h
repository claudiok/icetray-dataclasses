/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoResult.h
 * @version $Revision: 1.33 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include <TObject.h>
#include "StoragePolicy.h"
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
  /**
   * constructor
   */ 
  I3RecoResult(){}

  /**
   * destructor
   */
  virtual ~I3RecoResult() {}

  /**
   * streams a RecoResult to an arbitrary ostream
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ "<<IsA()->GetName()<<" ]\n";
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

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    //This method intentionally left blank
  }

  // ROOT macro
  ClassDef(I3RecoResult, 1);
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

#endif
