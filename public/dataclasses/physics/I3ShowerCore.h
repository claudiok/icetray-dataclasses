/**
 * Copyright (C) 2004
 * The IceCube collaboration
 * @version $Id$
 * @file I3ShowerCore.h
 * @date $Date$
 */

#ifndef I3SHOWERCORE_H_INCLUDED
#define I3SHOWERCORE_H_INCLUDED

#include "dataclasses/StoragePolicy.h"
#include "I3TopShowerImpl.h"

#include "I3NonDirectional.h"
#include "I3CoreLocalized.h"
#include "I3NonEnergetic.h"

/**
 * @brief This is a Shower core which is to be reconstructed by icetop
 * stations.
 */
class I3ShowerCore
: public I3TopShowerImpl<I3NonDirectional, I3CoreLocalized, I3NonEnergetic>
{
public:
  virtual ~I3ShowerCore();
private:
  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ClassDef (I3ShowerCore, 1);
};
       
/**
 * Typedeffed pointer which allows for change of technical details
 * later.
 */       
typedef shared_ptr<I3ShowerCore>  I3ShowerCorePtr;

#endif //I3SHOWERCORE_H_INCLUDED

