/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPhotonVect.h,v 1.4 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3MCPhotonVect.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author pretz
 */
#ifndef I3MCPHOTONVECT_H
#define I3MCPHOTONVECT_H

#include "StoragePolicy.h"
#include "I3MCPhoton.h"

/**
 * @brief A collection of I3MCPhotons.  
 *
 * This represents the full set of photons that arrive at a PMT during an
 * event
 */
class I3MCPhotonVect : public TObject, VectorPolicy<I3MCPhoton>::ThePolicy
{
 public:
  /**
   * default constructor
   */
  I3MCPhotonVect(){}

  /**
   * destructor
   */
  virtual ~I3MCPhotonVect() {}

  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3MCPhotonVect \n";
      I3MCPhotonVect::const_iterator iter;
      for(iter=begin();iter!=end();iter++)
	{
	  o<<*iter;
	}
      o<<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }
  
 private:
  //ROOT macro
  ClassDef(I3MCPhotonVect,1);
};

inline ostream& operator<<(ostream& o,const I3MCPhotonVect& vect)
{
  vect.ToStream(o);
  return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3MCPhotonVect>::ThePolicy I3MCPhotonVectPtr;

#endif //I3MCPHOTONVECT_H

