/**
    copyright  (C) 2012
    the icecube collaboration
    @version $Id: $
    @date    $Date:  $
*/

#ifndef DATACLASSES_I3_BASE_MAP_H_INCLUDED
#define DATACLASSES_I3_BASE_MAP_H_INCLUDED

#include <icetray/serialization.h>
#include "icetray/I3Logging.h"
#include <map>
#include <string>
#include <vector>

#include <dataclasses/Utility.h>
#include <icetray/I3Logging.h>
#include <icetray/I3FrameObject.h>
#include "icetray/OMKey.h"


template <typename Key, typename Value> 
struct I3BaseMap: public I3Map<Key, Value>{
public:	
	I3BaseMap():I3Map<Key,Value>(){}	
	
};
#endif
