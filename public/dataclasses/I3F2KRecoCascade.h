/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @file I3F2KRecoCascade.h
    @version $Revision: 1.4 $
    @date $Date$
    @author ehrlich
*/

#include "I3CascadeImpl.h"
#include "I3Directional.h"
#include "I3Localized.h"
#include "I3NonEnergetic.h"
#include "I3NonComposite.h"

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
                                              I3NonEnergetic,
                                              I3NonComposite>
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

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
//ROOT macro
  ClassDef(I3F2KRecoCascade,1);
};

typedef shared_ptr<I3F2KRecoCascade>  I3F2KRecoCascadePtr;

#endif

