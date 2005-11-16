#/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DigitalLaunch.h
 * @version $Revision: 1.6 $
 * @date $Date$
 * @author blaufuss
 */
#ifndef I3DIGITALLAUNCH_H
#define I3DIGITALLAUNCH_H

#include "TObject.h"
#include "TClass.h"
#include "dataclasses/StoragePolicy.h"
#include <sstream>

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

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
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
typedef shared_ptr<I3DigitalLaunch>  I3DigitalLaunchPtr;

#endif

