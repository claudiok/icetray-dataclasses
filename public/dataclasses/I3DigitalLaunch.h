#/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalLaunch.h,v 1.3 2004/08/12 17:33:33 pretz Exp $
 *
 * @file I3DigitalLaunch.h
 * @version $Revision: 1.3 $
 * @date $Date: 2004/08/12 17:33:33 $
 * @author blaufuss
 */
#ifndef I3DIGITALLAUNCH_H
#define I3DIGITALLAUNCH_H

#include "TObject.h"
#include "TClass.h"
#include "dataclasses/StoragePolicy.h"

/**
 * @brief A base class for Digital Readout Launches (DOM or TWR)
 *
 * 
 */
class I3DigitalLaunch : public TObject
{

 public:
  /**
   * default constructor
   */

  I3DigitalLaunch() {}

  /**
   * default destructor
   */
  virtual ~I3DigitalLaunch() {}

  /**
   * streams the I3DigitalLaunch to the indicated ostream
   */
  virtual void ToStream(ostream& o) const
    {
        o<<"[ "
         <<IsA()->GetName()
         <<" ]\n";
    }


 private:

  //ROOT macro
  ClassDef(I3DigitalLaunch,1);
};

/**
 * streams an I3DigitalLaunch to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3DigitalLaunch& g)
{
    g.ToStream(o);
    return o;
}

/**
 * pointer type to insulate users from memory management schemes
 */
typedef PtrPolicy<I3DigitalLaunch>::ThePolicy I3DigitalLaunchPtr;

#endif
