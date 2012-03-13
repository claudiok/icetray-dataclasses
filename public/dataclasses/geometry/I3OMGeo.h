/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id$
 * @file I3OMGeo.h
 * @date $Date$
 */

#ifndef I3OMGEO_H_INCLUDED
#define I3OMGEO_H_INCLUDED

#include "dataclasses/I3Position.h"
#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Orientation.h"
#include <string>
#include <iostream>
#include <sstream>
#include "icetray/OMKey.h"
#include "dataclasses/Utility.h"


static const unsigned i3omgeo_version_ = 1;

//Simple struct to contain all pertinent OM info.  
//See I3Geometry.h for more info

struct I3OMGeo 
{
    enum OMType {UnknownType = 0, AMANDA = 10, IceCube = 20, IceTop = 30};

    I3OMGeo():omtype(UnknownType){} 
    
    virtual ~I3OMGeo();
    
    /**
     * the OM's (or PMT's) x,y,z position
     */
    I3Position position;
    
    /**
     * Orientation of the OM (or PMT)
     */ 
    I3Orientation orientation;

    /**
     * InIce? IceTop? AMANDA OM? (see enum above)
     */ 
    OMType omtype;

    /**
     * Effective collection area (use I3Units)
     */ 
    double area;

    /**
     * Gets the I3Direction from the I3Orientation
     */
    inline I3Direction GetDirection() const {return orientation.GetDir();}

    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive& ar, unsigned version);
};

I3_POINTER_TYPEDEFS(I3OMGeo);
BOOST_CLASS_VERSION(I3OMGeo, i3omgeo_version_);

#endif //I3OMGEO_H_INCLUDED
