#ifndef I3DIGITALTWRSERIES_H
#define I3DIGITALTWRSERIES_H
/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalTWRSeries.h,v 1.4 2004/02/25 20:10:24 pretz Exp $
 *
 * Just a placeholder class for a different kind of response
 *
 * @version $Revision: 1.4 $
 * @date $Date: 2004/02/25 20:10:24 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo implement this class
 */
#include "I3DigitalSeries.h"

typedef I3DigitalSeries I3DigitalTWRSeries;

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DigitalTWRSeries>::ThePolicy I3DigitalTWRSeriesPtr;

#endif

