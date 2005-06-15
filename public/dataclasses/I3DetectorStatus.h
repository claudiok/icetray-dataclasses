/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DetectorStatus.h
 * @version $Revision: 1.9 $
 * @date $Date$
 * @author pretz
 */
#ifndef I3DETECTORSTATUS_H
#define I3DETECTORSTATUS_H

#include "StoragePolicy.h"
#include "I3IceCubeStatus.h"
#include <sstream>

/**
 * @briefThis is the state of the aspects of the detector that people have 
 * direct control over.  
 *
 * Stuff that is a 'knob' on the detector.  This is a
 * top-level object in the frame related to this 'Detector Status' information.
 *
 */
class I3DetectorStatus : public TObject
{
  I3IceCubeStatus icecubeStatus_;

 public:
  /**
   * constructor
   */
  I3DetectorStatus(){};

  /**
   * destructor
   */
  virtual ~I3DetectorStatus(){};

  /**
   * @return the Atmosphere as a constant object
   */
  const I3IceCubeStatus& GetIceCubeStatus() const { return icecubeStatus_;}

  /**
   * @return the IceCubeStatus as a non-const object
   */
  I3IceCubeStatus& GetIceCubeStatus() { return icecubeStatus_;}

  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3DetectorStatus ]"
       << icecubeStatus_;
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:
  // copy and assignment private
  I3DetectorStatus(const I3DetectorStatus& rhs);
  const I3DetectorStatus& operator=(const I3DetectorStatus& rhs);

  //ROOT macro
  ClassDef(I3DetectorStatus,1);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("IcecubeStatus",icecubeStatus_);
  }

};

inline ostream& operator<<(ostream& o,const I3DetectorStatus& stat)
{
  stat.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DetectorStatus>  I3DetectorStatusPtr;


#endif // I3MONITORING_H
