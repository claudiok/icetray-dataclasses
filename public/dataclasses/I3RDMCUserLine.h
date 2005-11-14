/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Bag.h 11091 2005-09-27 09:32:13Z troy $
 *
 * @file I3Bag.h
 * @version $Revision: 1.23 $
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#ifndef I3RDMCUSERLINE_H
#define I3RDMCUSERLINE_H

#include "TObject.h"
#include "StoragePolicy.h"
#include <TClass.h>

#include <sstream>
#include <iostream>

class I3RDMCUserLine : public TObject, public STLMapStoragePolicy<string,double>
{
 public:
  /**
   * Constructor
   */
  I3RDMCUserLine() {};

  /**
   * destructor
   */
  virtual ~I3RDMCUserLine() {};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RDMCUserLine\n";
      I3RDMCUserLine::const_iterator iter;
      for(iter = begin();iter!=end();iter++)
	{
	  o<<iter->first;
          o<<iter->second;
          o<<"\n";
	}
      o<<"]";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  // ROOT macro
  ClassDef(I3RDMCUserLine,1);
};
/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3RDMCUserLine& user_line)
{
  user_line.ToStream(o);
  return o;
}

typedef shared_ptr<I3RDMCUserLine>  I3RDMCUserLinePtr;

#endif

