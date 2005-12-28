/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3RecoHit.h
 * @version $Revision: 1.12 $
 * @date $Date$
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3RECOHIT_H
#define I3RECOHIT_H

#include <TObject.h>
#include "dataclasses/physics/I3Hit.h"

/**
 * @brief A base class for reconstruted hits.  
 *
 * Carries no information beyond 'hit'
 * but can be sub-classed as part of a hit series reconstruction.
 *
 */
class I3RecoHit : public I3Hit
{
  public:
  I3RecoHit(){}

  virtual ~I3RecoHit();

  const map<string,double>& GetUserParameters() const {return user_;}

  map<string,double>& GetUserParameters(){return user_;}

 private:
  map<string,double> user_;

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

typedef shared_ptr<I3RecoHit>  I3RecoHitPtr;


#endif


