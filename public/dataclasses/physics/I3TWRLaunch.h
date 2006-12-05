/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3TWRLaunch.h
 * @date $Date$
 */
#ifndef I3TWRLAUNCH_H_INCLUDED
#define I3TWRLAUNCH_H_INCLUDED

// forward declarations


// header files

#include <vector>

#include <dataclasses/I3Map.h>
#include <dataclasses/I3Vector.h>
#include <dataclasses/OMKey.h>
#include <dataclasses/Utility.h>
#include <dataclasses/physics/I3TWRFrag.h>

// definitions


/** The direct/raw digital readout of an Amanda OM using the TWR DAQ.
 */
class I3TWRLaunch
{
  private:
  unsigned int baseline_;
  std::vector<I3TWRFrag> fragments_;

  public:
  /** Default constructor.
   */
  I3TWRLaunch() : baseline_(0u){}
  /** Destructor.
   */
  virtual ~I3TWRLaunch();
  /** Returns the baseline/mean value of the waveform (as determined by the TWR DAQ).
   * 
   * @return The baseline/mean value.
   */
  unsigned int GetBaseline() const{ return(baseline_); }
  /** Sets the baseline/mean value of the waveform (as determined by the TWR DAQ).
   * 
   * @param baseline The baseline/mean value.
   */
  void SetBaseline(unsigned int baseline){ baseline_ = baseline_; }
  /** Provides access to the waveform's fragments.
   * 
   * @return Collection of waveform fragments.
   */
  const std::vector<I3TWRFrag>& GetFragments() const{ return(fragments_); }
  /** Provides access to the waveform's fragments.
   * 
   * @return Collection of waveform fragments.
   */
  std::vector<I3TWRFrag>& GetFragments(){ return(fragments_); }

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);
};

//TODO: backwards compatible serialization
//BOOST_CLASS_VERSION(I3TWRLaunch, 1);

typedef I3Vector<I3TWRLaunch> I3TWRLaunchSeries;
typedef I3Map<OMKey, I3TWRLaunchSeries> I3TWRLaunchSeriesMap;

I3_POINTER_TYPEDEFS(I3TWRLaunch);
I3_POINTER_TYPEDEFS(I3TWRLaunchSeries);
I3_POINTER_TYPEDEFS(I3TWRLaunchSeriesMap);

#endif /*I3TWRLAUNCH_H_INCLUDED*/


