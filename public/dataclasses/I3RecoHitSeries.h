/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeries.h,v 1.27.16.1 2005/02/22 17:48:10 deyoung Exp $
 *
 * @file I3RecoHitSeries.h
 * @version $Revision: 1.27.16.1 $
 * @date $Date: 2005/02/22 17:48:10 $
 * @author ehrlich
 * @author pretz
 */

#ifndef I3RECOHITSERIES_H
#define I3RECOHITSERIES_H

#include "I3RecoHit.h"
#include "StoragePolicy.h"
#include <sstream>

/**
 * @brief A list of @c I3RecoHit 's.  
 *
 * This class represents a reconstructed series of photoelectrons, or
 * @em hits, which a particular algorithm believes to have produced the
 * observed @c I3DataReadout in this @c I3OMResponse.  RecoHitSeries
 * are produced by hit extraction or feature extraction algorithms,
 * which try to extract individual PE production times from the readout.
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
  
  /** 
   * For dumping the RecoHitSeries to a string.  For a C-style string,
   * use ToString().c_str().
   */
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

