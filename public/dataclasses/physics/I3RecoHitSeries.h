/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3RecoHitSeries.h
 * @date $Date$
 */

#ifndef I3RECOHITSERIES_H_INCLUDED
#define I3RECOHITSERIES_H_INCLUDED

#include "dataclasses/physics/I3RecoHit.h"
#include "dataclasses/StoragePolicy.h"
#include "dataclasses/I3Vector.h"
#include <sstream>

/**
 * @brief A list of reco hits.
 */
class I3RecoHitSeries : public I3Vector<I3RecoHit>
{
 public:

  I3RecoHitSeries() {};

  virtual ~I3RecoHitSeries();

  /**
   * earliest hit time
   */
  double GetFirstHitTime() 
  {
    if(this->size()) 
    { 
      double min = this->begin()->GetTime();
      I3RecoHitSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++) 
      {
        if(min>iter->GetTime()) min=iter->GetTime();
      }
      return(min);
    }
  else return(NAN);       
  };

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3RecoHitSeries: \n";
    I3RecoHitSeries::const_iterator iter;
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

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3RecoHitSeries& series)
{
  series.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3RecoHitSeries>  I3RecoHitSeriesPtr;

#endif //I3RECOHITSERIES_H_INCLUDED


