/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id$

    @file I3BasicCascade.h
    @version $Revision: 1.9 $
    @date $Date$
    @author deyoung
*/

#include "I3CascadeImpl.h"
#include "I3NonDirectional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

#ifndef I3BASICCASCADE_H
#define I3BASICCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief A plain vanilla cascade -- no direction or energy information,
 * just a position and particle type.
 */
class I3BasicCascade : public I3CascadeImpl<I3NonDirectional,
	 I3Localized,
	 I3NonEnergetic,
	 I3NonComposite>
{
public:
  /**
   * constructor
   */
  I3BasicCascade(){};

  /**
   * destructor
   */
  virtual ~I3BasicCascade(){}

 private:

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3BasicCascade", 
		  base_object< I3CascadeImpl<I3NonDirectional,
		                             I3Localized,
		                             I3NonEnergetic,
		                             I3NonComposite> >(*this));
  }

  // ROOT macro
  ClassDef(I3BasicCascade,1);
};

BOOST_SHARED_POINTER_EXPORT(I3BasicCascade);

/**
 * pointer type to insulate users from memory management issues
 */
typedef shared_ptr<I3BasicCascade>  I3BasicCascadePtr;

#endif
