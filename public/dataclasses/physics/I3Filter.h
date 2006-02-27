/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3Filter.h 11091 2005-09-27 09:32:13Z troy $
 * @file I3Filter.h
 * @date $Date: 2005-09-27 05:32:13 -0400 (Tue, 27 Sep 2005) $
 */

#ifndef I3FILTER_H_INCLUDED
#define I3FILTER_H_INCLUDED

#include <TObject.h>
#include <TClass.h>
#include <string>
#include <iostream>
#include <sstream>

#include "dataclasses/Utility.h"

using namespace std; 

/**
 * @brief The basic Filter class.  
 * 
 * This is the base class for trigger records that will live in the I3FilterDict.
 */
class I3Filter : public TObject
{
public:
  
  /**
   * An enumerated type for if the Filter pass
   */
  enum FilterPass { No = 0, Yes = 1};
  
  I3Filter() {;}
  
  virtual ~I3Filter();
  
  
private:
  FilterPass filterPass_;       // Did the event pass this filter
  
  friend class boost::serialization::access;
  
  template <class Archive> void serialize(Archive & ar, unsigned version);

};


I3_POINTER_TYPEDEFS(I3Filter);

#endif //I3FILTER_H_INCLUDED


