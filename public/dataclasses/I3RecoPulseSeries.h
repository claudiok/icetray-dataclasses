/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoPulseSeries.h,v 1.27 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3RecoPulseSeries.h
 * @version $Revision: 1.27 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECOPULSESERIES_H
#define I3RECOPULSESERIES_H

#include "I3RecoPulse.h"
#include "StoragePolicy.h"
#include <sstream>

/**
 * @brief A list of reco pulses
 */

class I3RecoPulseSeries : public TObject, public STLVectorStoragePolicy<I3RecoPulsePtr>
{
  public:
  I3RecoPulseSeries() {};
  virtual ~I3RecoPulseSeries() {};

  double GetFirstPulseTime()
  {
    if(this->size())
    {
      double min = (*this->begin())->GetTime();
      I3RecoPulseSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++)
      {
        if(*iter) {if(min>(*iter)->GetTime()) min=(*iter)->GetTime();}
      }
      return(min);
    }
    else return(NAN);
  };
                                                                                                                                                             
  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3RecoPulseSeries: \n";
    I3RecoPulseSeries::const_iterator iter;
    for(iter=begin();iter!=end();iter++)
    {
      if(*iter == I3RecoPulsePtr((I3RecoPulse*)0)) o<<"Null I3RecoPulse";
      else o<<*(*iter);
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
  // copy and assignment are private:
  I3RecoPulseSeries (const I3RecoPulseSeries& rhs);
  const I3RecoPulseSeries& operator= (const I3RecoPulseSeries&);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
ClassDef(I3RecoPulseSeries,1);
};

inline ostream& operator<<(ostream& o, const I3RecoPulseSeries& series)
{
  series.ToStream(o);
  return o;
}

typedef shared_ptr<I3RecoPulseSeries> I3RecoPulseSeriesPtr;

#endif


