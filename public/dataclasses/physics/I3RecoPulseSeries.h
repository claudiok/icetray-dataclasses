/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3RecoPulseSeries.h,v 1.27 2004/08/31 02:56:29 pretz Exp $
 * @file I3RecoPulseSeries.h
 * @date $Date: 2004/08/31 02:56:29 $
 */

#ifndef I3RECOPULSESERIES_H_INCLUDED
#define I3RECOPULSESERIES_H_INCLUDED

#include "I3RecoPulse.h"
#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"
#include <sstream>

/**
 * @brief A list of reco pulses
 */

class I3RecoPulseSeries : public I3Vector<I3RecoPulse>
{
  public:
  I3RecoPulseSeries() {};
  virtual ~I3RecoPulseSeries();

  double GetFirstPulseTime()
  {
    if(this->size())
    {
      double min = this->begin()->GetTime();
      I3RecoPulseSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++)
      {
        if(min>iter->GetTime()) min=iter->GetTime();
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
      o<<*iter;
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
  //  I3RecoPulseSeries (const I3RecoPulseSeries& rhs);
  //  const I3RecoPulseSeries& operator= (const I3RecoPulseSeries&);

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3RecoPulseSeries& series)
{
  series.ToStream(o);
  return o;
}

I3_POINTER_TYPEDEFS(I3RecoPulseSeries);

typedef I3Map<OMKey, I3RecoPulseSeries> I3RecoPulseSeriesMap;
I3_POINTER_TYPEDEFS(I3RecoPulseSeriesMap);

#endif //I3RECOPULSESERIES_H_INCLUDED


