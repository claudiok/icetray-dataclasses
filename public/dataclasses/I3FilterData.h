/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3FilterData.h,v 1.4 2004/07/12 12:23:11 pretz Exp $
 *
 * @file I3FilterData.h
 * @version $Revision: 1.4 $
 * @date $Date: 2004/07/12 12:23:11 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 */
#ifndef I3FILTERDATA_H
#define I3FILTERDATA_H

#include <TObject.h>
#include "StoragePolicy.h"
#include <iostream>

using namespace std;

/**
 * @brief A place-holder for the filter data in the event.  No implementation
 * yet.  
 *
 * No real thought, as far as I know, on what should be in here.
 * @todo design and implement this class
 *
 */
class I3FilterData : public TObject
{
 public:
  /**
   * constructor
   */
  I3FilterData(){};

  /**
   * destructor
   */
  virtual ~I3FilterData(){};

  /**
   * @todo this method needs implemented after the class is done
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3FilterData ]\n";
    }

 private:
  // ROOT Macro
  ClassDef(I3FilterData, 1);
};

inline ostream& operator<<(ostream& o,const I3FilterData& filter)
{
  filter.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3FilterData>::ThePolicy I3FilterDataPtr;

#endif

