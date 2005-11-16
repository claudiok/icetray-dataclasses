/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3DigitalReadout.h
 * @version $Revision: 1.14 $
 * @date $Date$
 * @author pretz
 * @author blaufuss
 *
 */
#ifndef I3DIGITALREADOUT_H
#define I3DIGITALREADOUT_H

#include <iostream>
#include "StoragePolicy.h"
#include "I3DataReadout.h"
#include "I3DigitalLaunch.h"

/**
 * @brief Base class for digitial I3DataReadouts (containing waveform
 * information)
 *
 * This class forms the base for specific types of digitizing
 * (waveform) data readouts.  The basic information is just the time
 * of the beginning of the waveform, and a bin size that is the
 * length (in nanoseconds) of each sample in the waveform.
 * Derived classes such as I3DigitalTWRReadout may provide
 * additional information.
 */
class I3DigitalReadout : public I3DataReadout, public STLVectorStoragePolicy<I3DigitalLaunchPtr>
{
 public:
  /**
   * constructor
   */
  I3DigitalReadout() {}

  /**
   * destructor
   */
  virtual ~I3DigitalReadout();

  /**
   * dumps the class to the given ostream
   */
  virtual void ToStream(std::ostream& o) const
    {
      I3DataReadout::ToStream(o);
      const_iterator iter;
      for(iter = begin() ; iter!= end() ; iter++)
	{
	  o<<*(*iter);
	}
      o<<"\n";
    }
  
 private:

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
// private copy constructors and assignment
  I3DigitalReadout(const I3DigitalReadout& other);
  I3DigitalReadout& operator=(const I3DigitalReadout& other);

  // ROOT macro
  //ClassDef(I3DigitalReadout,1);
};

/*
 * @todo Fix this iterator.  I don't think it is right for a vector iterator
 */
//inline ostream& operator<<(ostream& o,const I3DigitalReadout& v)
//{
//  o<<"[ I3DigitalReadout: \n";
//  I3DigitalReadout::const_iterator iter;
//  for(iter=v.begin();iter!=v.end();iter++)
//    {
//      o<<iter->first;
//     if(iter->second==I3DigitalLaunchPtr((I3DigitalLaunch*)0))
//        o<<"Null I3DigitalLaunch";
//      else
//        o<<*(iter->second);
//    }
//  o<<"]\n";
//  return o;
//}

/**
 * Pointer typedeffed away to insulate users from the
 * memory-mananagement implementation
 */
typedef shared_ptr<I3DigitalReadout>  I3DigitalReadoutPtr;

#endif


