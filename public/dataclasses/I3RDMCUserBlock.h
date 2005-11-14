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

#ifndef I3RDMCUSERBLOCK_H
#define I3RDMCUSERBLOCK_H

#include "TObject.h"
#include "StoragePolicy.h"
#include <TClass.h>
#include "I3RDMCUserLine.h"

#include <sstream>
#include <iostream>


class I3RDMCUserBlock : public TObject, public STLMapStoragePolicy<string,I3RDMCUserLine>
{
 public:
  /**
   * Constructor
   */
  I3RDMCUserBlock() {};

  /**
   * destructor
   */
  virtual ~I3RDMCUserBlock() {};

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3RDMCUserBlock\n";
      I3RDMCUserBlock::const_iterator iter;
      for(iter = begin();iter!=end();iter++)
	{
	  o<<iter->first;
          o<<"[ ";
          o<<iter->second;
          o<<" ]";
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
  ClassDef(I3RDMCUserBlock,1);
};
/**
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3RDMCUserBlock& user_block)
{
  user_block.ToStream(o);
  return o;
}

typedef shared_ptr<I3RDMCUserBlock>  I3RDMCUserBlockPtr;

#endif

