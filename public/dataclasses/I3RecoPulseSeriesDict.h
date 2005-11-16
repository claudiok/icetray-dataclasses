#ifndef I3RECOPULSESERIESDICT_H
#define I3RECOPULSESERIESDICT_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoPulseSeriesDict.h,v 1.4 2004/10/27 23:09:40 spencer Exp $
 *
 * @file I3RecoPulseSeriesDict.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/10/27 23:09:40 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#include "I3RecoPulseSeries.h"
#include "StoragePolicy.h"

class I3RecoPulseSeriesDict : public TObject, public STLMapStoragePolicy<string,I3RecoPulseSeriesPtr>

 /**
  *   Container for RecoPulseSerieses
  */

{
  public:
  I3RecoPulseSeriesDict(){}
  virtual ~I3RecoPulseSeriesDict(){};

  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3RecoPulseSeriesDict: \n";
    I3RecoPulseSeriesDict::const_iterator iter;
    for(iter=begin();iter!=end();iter++)
    {
      o<<iter->first;
      if(iter->second==I3RecoPulseSeriesPtr((I3RecoPulseSeries*)0)) o<<"Null RecoPulseSeries";
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
/*   // copy and assignment are private */
  I3RecoPulseSeriesDict(const I3RecoPulseSeriesDict& rhs);
  const I3RecoPulseSeriesDict& operator=(const I3RecoPulseSeriesDict&);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
ClassDef(I3RecoPulseSeriesDict,1);
};

inline ostream& operator<<(ostream& o, const I3RecoPulseSeriesDict& dict)
{
  dict.ToStream(o);
  return o;
}

typedef shared_ptr<I3RecoPulseSeriesDict> I3RecoPulseSeriesDictPtr;

#endif


