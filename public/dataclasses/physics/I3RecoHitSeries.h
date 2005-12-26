/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoHitSeries.h
 * @version $Revision: 1.31 $
 * @date $Date$
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "dataclasses/physics/I3RecoHit.h"
#include "dataclasses/StoragePolicy.h"
#include <sstream>

/**
 * @brief A list of reco hits.
 */
class I3RecoHitSeries : public TObject, public vector<I3RecoHit>
{
 public:
  /**
   *constructor
   */
  I3RecoHitSeries() {};

  /**
   * destructor
   */
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

  private:
  // copy and assignment are private:
  I3RecoHitSeries (const I3RecoHitSeries& rhs);
  const I3RecoHitSeries& operator= (const I3RecoHitSeries&);

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

#endif


