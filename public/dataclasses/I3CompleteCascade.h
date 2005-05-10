/**
    copyright  (C) 2004
    the IceCube collaboration
    $Id: $

    @file I3CompleteCascade.h
    @version $Revision: $
    @date $Date: $
    @author deyoung
    @author Rodin
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3Energetic.h"
#include "I3NonComposite.h"

#ifndef I3COMPLETECASCADE_H_INCLUDED
#define I3COMPLETECASCADE_H_INCLUDED

#include "dataclasses/I3Cascade.h"

/**
 * @brief A cascade with full MC information.
 */
class I3CompleteCascade : public I3CascadeImpl<I3Directional,
	 I3Localized,
	 I3Energetic,
	 I3NonComposite>
{
  
  public:
  /**
   * constructor
   */
  I3CompleteCascade() {};

  /**
   * destructor
   */
  virtual ~I3CompleteCascade() {}
  
 private:
  // ROOT macro
  ClassDef(I3CompleteCascade,1);
};

/**
 * pointer typedeffed away to insulate users from memory management
 */
typedef shared_ptr<I3CompleteCascade>  I3CompleteCascadePtr;

#endif