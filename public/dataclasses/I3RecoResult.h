#ifndef I3RECORESULT_H
#define I3RECORESULT_H

#include <TObject.h>
#include "StoragePolicy.h"
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResult.h,v 1.24 2004/04/26 04:11:57 ehrlich Exp $
 *
 * The base class from which all RecoResult's derive.  Not much of an interface
 * since the various RecoResults are so diverse in what they can provide.
 *
 * @version $Revision: 1.24 $
 * @date $Date: 2004/04/26 04:11:57 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo 
 *
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

 private:
  // copy and assignment are private
  I3RecoResult(const I3RecoResult& rhs);
  const I3RecoResult& operator=(const I3RecoResult&);

  // ROOT macro
  ClassDef(I3RecoResult, 1);
};

typedef PtrPolicy<I3RecoResult>::ThePolicy I3RecoResultPtr;

#endif
