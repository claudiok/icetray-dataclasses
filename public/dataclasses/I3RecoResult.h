/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResult.h,v 1.30.4.1 2005/01/26 03:59:37 troy Exp $
 *
 * @file I3RecoResult.h
 * @version $Revision: 1.30.4.1 $
 * @date $Date: 2005/01/26 03:59:37 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include "StoragePolicy.h"
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
  // copy and assignment are private
  I3RecoResult(const I3RecoResult& rhs);
  const I3RecoResult& operator=(const I3RecoResult&);

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
typedef PtrPolicy<I3RecoResult>::ThePolicy I3RecoResultPtr;

#endif
