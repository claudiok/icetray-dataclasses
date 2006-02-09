/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3DOMLaunchSeries.h 14593 2006-01-20 16:50:01Z pretz $
 * @file I3DOMLaunchSeries.h
 * @date $Date: 2006-01-20 11:50:01 -0500 (Fri, 20 Jan 2006) $
 */

#ifndef I3DOMLAUNCHSERIES_H_INCLUDED
#define I3DOMLAUNCHSERIES_H_INCLUDED

#include "dataclasses/physics/I3DOMLaunch.h"
#include "dataclasses/Utility.h"
#include "dataclasses/I3Vector.h"
#include "dataclasses/I3Map.h"
#include "dataclasses/OMKey.h"
#include <sstream>

/**
 * @brief A list of reco hits.
 */
class I3DOMLaunchSeries : public I3Vector<I3DOMLaunch>
{
 public:

  I3DOMLaunchSeries() {};

  virtual ~I3DOMLaunchSeries();

  /**
   * dumps the object to the indicated ostream
   * @param o the ostream to dump the object to
   */
  virtual void ToStream(ostream& o) const
  {
    o<<"[ I3DOMLaunchSeries: ]\n";
  }

  virtual std::string ToString() const
  {
    std::ostringstream out;
    ToStream(out);
    return out.str();
  }

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

inline ostream& operator<<(ostream& o, const I3DOMLaunchSeries& series)
{
  series.ToStream(o);
  return o;
}

I3_POINTER_TYPEDEFS(I3DOMLaunchSeries);

typedef I3Map<OMKey, I3DOMLaunchSeries>  I3DOMLaunchSeriesMap;
I3_POINTER_TYPEDEFS(I3DOMLaunchSeriesMap);

#endif //I3DOMLAUNCHSERIES_H_INCLUDED


