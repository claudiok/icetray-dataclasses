/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalSeries.h,v 1.15 2004/02/26 18:53:12 pretz Exp $
 *
 * A collection of digital signals.  
 *
 * @version $Revision: 1.15 $
 * @date $Date: 2004/02/26 18:53:12 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo
 *
 */
#ifndef I3DIGITALSERIES_H
#define I3DIGITALSERIES_H

#include "I3Digital.h"
#include "StoragePolicy.h"

class I3DigitalSeries : public VectorPolicy<I3Digital>::ThePolicy
{
  Double_t    fStarttime;
  
 public:
  /**
   * constructor
   */
  I3DigitalSeries() {fStarttime = 0; }

  /**
   * destructor
   */
  virtual ~I3DigitalSeries(){;}
  
  /** 
   * @return the start time of the series
   */
  Double_t StartTime() const { return fStarttime; }

  /**
   * @param starttime the new start time for the series
   */
  void   StartTime(Double_t starttime) { fStarttime = starttime; }

 private:
  // copy and assignment private
  I3DigitalSeries(const I3DigitalSeries&);
  const I3DigitalSeries& operator=(const I3DigitalSeries&);

  // ROOT macro
  ClassDef(I3DigitalSeries,1);
};

typedef PtrPolicy<I3DigitalSeries>::ThePolicy I3DigitalSeriesPtr;

#endif

