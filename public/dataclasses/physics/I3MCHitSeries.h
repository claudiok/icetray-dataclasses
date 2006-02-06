/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3MCHitSeries.h
 * @date $Date$
 */

#ifndef I3MCHITSERIES_H_INCLUDED
#define I3MCHITSERIES_H_INCLUDED

#include "I3MCHit.h"
#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"

#include <sstream>

/**
 * @brief Array of I3MCHits
 * 
 * Vector of the I3MCHits produced at an OM in an event.  The weight
 * variable (default 1) can be used to assign a statistical weighting
 * factor to the series as a whole, independent of the individual hits.
 */
class I3MCHitSeries : public I3Vector<I3MCHit>
{
  double weight_;
 public:

  I3MCHitSeries(){}

  virtual ~I3MCHitSeries();

  /**
   * @return the weight associated with this series
   */
  double GetWeight() { return weight_; }

  /**
   * @param weight the new weight for this series
   */
  void SetWeight(double weight) { weight_ = weight; }

  /**
   * earliest hit time
   */
  double GetFirstHitTime() {
    if (this->size()) { 
      double min = (*this->begin()).GetTime();
      I3MCHitSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++) {
	if(min>(*iter).GetTime()) min=(*iter).GetTime();
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
      o<<"[ I3MCHitSeries: \n";
      I3MCHitSeries::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<*iter;
	}
      o<<"]\n";
    }

  virtual std::string ToString() const
    {
      std::ostringstream out;
      ToStream(out);
      return out.str();
    }
  
  private:
/*   // copy and assignment are private */
  I3MCHitSeries(const I3MCHitSeries&); 
  const I3MCHitSeries& operator=(const I3MCHitSeries&); 

  friend class boost::serialization::access;

template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o,const I3MCHitSeries& series)
{
  series.ToStream(o);
  return o;
}

I3_POINTER_TYPEDEFS(I3MCHitSeries);

#endif //I3MCHITSERIES_H_INCLUDED

