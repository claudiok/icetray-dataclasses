/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeries.h,v 1.27 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3RecoHitSeries.h
 * @version $Revision: 1.27 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "StoragePolicy.h"
#include <sstream>

/**
 * @brief A list of reco hits.
 */
class I3RecoHitSeries : public TObject, public VectorPolicy<I3RecoHitPtr>::ThePolicy
{
 public:
  /**
   *constructor
   */
  I3RecoHitSeries() {};

  /**
   * destructor
   */
  virtual ~I3RecoHitSeries() {};

  /**
   * earliest hit time
   */
  Double_t GetFirstHitTime() {
    if (this->size()) { 
      Double_t min = (*this->begin())->GetTime();
      I3RecoHitSeries::iterator iter;
      for(iter=this->begin(); iter!=this->end(); iter++) {
	if(min>(*iter)->GetTime()) min=(*iter)->GetTime();
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
	  if(*iter == I3RecoHitPtr((I3RecoHit*)0))
	    o<<"Null I3RecoHit";
	  else
	    o<<*(*iter);
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

  // ROOT macro
  ClassDef(I3RecoHitSeries,1);
};

inline ostream& operator<<(ostream& o, const I3RecoHitSeries& series)
{
  series.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3RecoHitSeries>::ThePolicy I3RecoHitSeriesPtr;

#endif

