#ifndef I3RECOHITSERIESDATA_H
#define I3RECOHITSERIESDATA_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoHitSeriesData.h,v 1.15 2004/04/27 13:35:23 pretz Exp $
 *
 * @file I3RecoHitSeriesData.h
 * @version $Revision: 1.15 $
 * @date $Date: 2004/04/27 13:35:23 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */

#include "I3RecoHitSeries.h"
#include "StoragePolicy.h"
#include "TObject.h"

/**
 * @brief This is the container for all the hit series reconstructions
 */
class I3RecoHitSeriesData : public TObject, 
      	public MapPointainerPolicy<I3RecoHitSeriesPtr>::ThePolicy
{
 public:
  /**
   * constructor
   */ 
  I3RecoHitSeriesData(){}

  /**
   * destructor
   */
  virtual ~I3RecoHitSeriesData(){};

 private:
/*   // copy and assignment are private */
  I3RecoHitSeriesData(const I3RecoHitSeriesData& rhs);
  const I3RecoHitSeriesData& operator=(const I3RecoHitSeriesData&);

  // ROOT macro
  ClassDef(I3RecoHitSeriesData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoHitSeriesData>::ThePolicy I3RecoHitSeriesDataPtr;

#endif

