/**
 * copyright  (C) 2007
 * the icecube collaboration
 * @version $Id:$
 * @file I3MCEventWeight.h
 * @date $Date:$
 */

#ifndef I3MCEVENTWEIGHT_H
#define I3MCEVENTWEIGHT_H

#include <icetray/I3FrameObject.h>

/**
 * @brief the weight of an event according to a specific model
 *
 *
 */
class I3MCEventWeight : public I3FrameObject
{
 public:
  double weight;
  double livetimePerFile;
  
  virtual I3MCEventWeight::~I3MCEventWeight();

  template <class Archive>
    void serialize(Archive& ar,unsigned version);
};

I3_POINTER_TYPEDEFS(I3MCEventWeight);

#endif // I3MCEVENTWEIGHT_H
