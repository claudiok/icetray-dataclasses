#ifndef I3DETECTORSTATUS_H
#define I3DETECTORSTATUS_H

#include "StoragePolicy.h"
#include "I3InIceStatus.h"
#include "I3IceTopStatus.h"

/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DetectorStatus.h,v 1.1 2004/03/02 20:58:51 pretz Exp $
 *
 * This is the state of the aspects of the detector that people have direct 
 * control over.  Stuff that is a 'knob' on the detector.  This is a
 * top-level object in the frame related to this 'Detector Status' information.
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/03/02 20:58:51 $
 * @author pretz
 *
 * @todo 
 */
class I3DetectorStatus : public TObject{
  I3InIceStatus fInIceStatus;
  I3IceTopStatus fIceTopStatus;

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
  const I3InIceStatus& InIceStatus() const { return fInIceStatus;}

  /**
   * @return the InIceStatus as a non-const object
   */
  I3InIceStatus& InIceStatus() { return fInIceStatus;}

  /**
   * @return the Atmosphere as a constant object
   */
  const I3IceTopStatus& IceTopStatus() const { return fIceTopStatus;}

  /**
   * @return the IceTopStatus as a non-const object
   */
  I3IceTopStatus& IceTopStatus() { return fIceTopStatus;}

 private:
  // copy and assignment private
  I3DetectorStatus(const I3DetectorStatus& rhs);
  const I3DetectorStatus& operator=(const I3DetectorStatus& rhs);

  //ROOT macro
  ClassDef(I3DetectorStatus,1);
};

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3DetectorStatus>::ThePolicy I3DetectorStatusPtr;


#endif // I3MONITORING_H
