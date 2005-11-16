/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterDict.h 11091 2005-09-27 09:32:13Z troy $
 *
 * @file I3FilterDict.h
 * @version $Revision: 1.4 $
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 * @author ehrlich
 * @author troy
 * @author pretz
 * @author deyoung
 *
 */
#ifndef I3FILTERDICT_H
#define I3FILTERDICT_H

#include <TObject.h>
#include "StoragePolicy.h"
#include "I3Filter.h"
#include <sstream>

/**
 * @brief A place holder for the Filter data within the event
 *
 */
class I3FilterDict : public TObject, public STLMapStoragePolicy<string,I3FilterPtr>
{
  public:
  I3FilterDict() {};
  virtual ~I3FilterDict() {};

  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3FilterDict: \n";
    I3FilterDict::const_iterator iter;
    for(iter=begin();iter!=end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3FilterPtr((I3Filter*)0)) o<<"Null I3Filter";
      else o<<*(iter->second);
    }
    o<<"]\n";
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

/**
 * streams an I3FilterDict to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3FilterDict& v)
{
  v.ToStream(o);
  return o;
}


/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3FilterDict> I3FilterDictPtr;

#endif


