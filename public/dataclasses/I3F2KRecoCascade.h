/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3F2KRecoCascade.h,v 1.1.2.1 2004/07/29 18:56:57 ehrlich Exp $

    @file I3F2KRecoCascade.h
    @version $Revision: 1.1.2.1 $
    @date $Date: 2004/07/29 18:56:57 $
    @author ehrlich
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"

#ifndef I3F2KRECOCASCADE_H
#define I3F2KRECOCASCADE_H

#include "dataclasses/I3Cascade.h"

/**
 * @brief F2KCascade contains the parameter set corresponding to the F2000
 * track variables.
 *
 * It is intended primarily for backward compatibility.
 */
class I3F2KRecoCascade : public I3CascadeImpl<I3Directional,
                                              I3Localized,
                                              I3NonEnergetic>
{
 public:
  /**
   * constructor
   */
  I3F2KRecoCascade(){};

  /**
   * destructor
   */
  virtual ~I3F2KRecoCascade(){}

 private:
  //ROOT macro
  ClassDef(I3F2KRecoCascade,1);
};

typedef PtrPolicy<I3F2KRecoCascade>::ThePolicy I3F2KRecoCascadePtr;

#endif
