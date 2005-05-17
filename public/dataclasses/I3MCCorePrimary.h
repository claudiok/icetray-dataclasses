/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3MCCorePrimary.h
 * @version $Revision: 1.2 $
 * @date $Date$
 * @author ehrlich
 * @author pretz
 */
#ifndef I3MCCOREPRIMARY_H
#define I3MCCOREPRIMARY_H

#include "dataclasses/StoragePolicy.h"
#include "I3PrimaryImpl.h"

#include "I3Directional.h"
#include "I3CoreLocalized.h"
#include "I3Energetic.h"

/**
 * @brief The basic class for a Monte Carlo primary, where all the data is 
 * known
 */
class I3MCCorePrimary : public I3PrimaryImpl<I3Directional,
	                                 I3CoreLocalized,
	                                 I3Energetic> 
{

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3MCCorePrimary",
		   base_object< I3PrimaryImpl<I3Directional,
	                                      I3CoreLocalized,
		                              I3Energetic> >(*this));
  }

  ClassDef(I3MCCorePrimary,1);
};

BOOST_SHARED_POINTER_EXPORT(I3MCCorePrimary);

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3MCCorePrimary>  I3MCCorePrimaryPtr;

#endif
