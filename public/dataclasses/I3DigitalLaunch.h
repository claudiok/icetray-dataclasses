#/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3DigitalLaunch.h,v 1.1 2004/07/30 15:11:00 blaufuss Exp $
 *
 * @file I3DigitalLaunch.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 15:11:00 $
 * @author blaufuss
 */
#ifndef I3DIGITALLAUNCH_H
#define I3DIGITALLAUNCH_H

#include "TObject.h"
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
