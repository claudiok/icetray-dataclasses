/**
 *
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Monitoring.h,v 1.4 2004/08/16 16:22:13 pretz Exp $
 * 
 * @file I3Monitoring.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/08/16 16:22:13 $
 * @author pretz
 */
#ifndef I3MONITORING_H
#define I3MONITORING_H

#include "StoragePolicy.h"
#include "I3Atmosphere.h"

/**
 * @brief This is information that we may want to monitor, but have no direct 
 * control over.  This is a top-level object in the Frame
 *
 */
class I3Monitoring : public TObject{
  I3Atmosphere fAtmosphere; //||
 public:
  /**
   * constructor
   */
  I3Monitoring(){};

  /**
   * destructor
   */
  virtual ~I3Monitoring(){};

  /**
   * @return the Atmosphere as a constant object
   */
  const I3Atmosphere& GetAtmosphere() const { return fAtmosphere;}

  /**
   * @return the Atmosphere as a non-const object
   */
  I3Atmosphere& GetAtmosphere() { return fAtmosphere;}

  virtual void ToStream(ostream& o) const
    {
      o<<" [ I3Monitoring ]\n";
      o<<fAtmosphere<<"\n";
    }
  
 private:
  // copy and assignment private
  I3Monitoring(const I3Monitoring& rhs);
  const I3Monitoring& operator=(const I3Monitoring& rhs);

  //ROOT macro
  ClassDef(I3Monitoring,1);
};

inline ostream& operator<<(ostream& o,const I3Monitoring& mon)
{
  mon.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3Monitoring>::ThePolicy I3MonitoringPtr;


#endif // I3MONITORING_H
