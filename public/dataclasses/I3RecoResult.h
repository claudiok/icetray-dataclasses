/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResult.h,v 1.26 2004/07/12 15:30:49 pretz Exp $
 *
 * @file I3RecoResult.h
 * @version $Revision: 1.26 $
 * @date $Date: 2004/07/12 15:30:49 $
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

  virtual void ToStream(ostream& o)
    {
      o<<"[ "<<IsA()->GetName()<<" ]\n";
    }

 private:
  // copy and assignment are private
  I3RecoResult(const I3RecoResult& rhs);
  const I3RecoResult& operator=(const I3RecoResult&);

  // ROOT macro
  ClassDef(I3RecoResult, 1);
};

inline ostream& operator<<(ostream& o,I3RecoResult& result)
{
  result.ToStream(o);
  return o;
}

typedef PtrPolicy<I3RecoResult>::ThePolicy I3RecoResultPtr;

#endif
