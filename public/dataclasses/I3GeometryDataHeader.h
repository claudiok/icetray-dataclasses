#ifndef I3GEOMETRYHEADER_H
#define I3GEOMETRYHEADER_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3GeometryDataHeader.h,v 1.3 2004/02/25 22:01:06 pretz Exp $
 *
 * I3Geometry Header is supposed to be a header for the geometry that
 * you can store in a file if you don't want to store the geometry.
 * It's supposed to have enough data to reconstruct the full geometry
 * from the database
 *
 * @version $Revision: 1.3 $
 * @date $Date: 2004/02/25 22:01:06 $
 * @author ehrlich
 * @author troy
 * @author pretz
 *
 * @todo change the name back to I3GeometryHeader
 * @todo modifiy to mirror changes in I3Geometry when they're done.
 * @todo move I3Geometry's header data here.
 */

// includes
#include "I3DataHeader.h"
#include "StoragePolicy.h"
#include <string>
using namespace std;

class I3GeometryDataHeader : public I3DataHeader
{
  // instance data
  Int_t fNumOms;
  Int_t fNumStrings;
  string fArrayName;
  
 public:
  /**
   * constructor
   */
  I3GeometryDataHeader()  : fNumOms(-1), fNumStrings(-1){;}

  /**
   * destructor
   */
  virtual ~I3GeometryDataHeader() {;}

  /**
   * copy constructor just uses assignment
   */
  I3GeometryDataHeader(const I3GeometryDataHeader& rhs){*this = rhs;}

  /**
   * assignment is just a member-wise assignment
   */
  const I3GeometryDataHeader& operator=(const I3GeometryDataHeader& rhs){
    if(this == &rhs) return *this;
    I3DataHeader::operator=(rhs);
    fNumOms = rhs.fNumOms;
    fNumStrings = rhs.fNumStrings;
    fArrayName = rhs.fArrayName;
    return *this;
  }

  /**
   * @return the total number of oms for the geometry
   */
  Int_t NumOms() { return fNumOms; }

  /**
   * @param arg the new number of oms for the geometry
   */
  void NumOms(Int_t arg) { fNumOms = arg; }

  /**
   * @return the number of strings for the geometry
   */
  Int_t NumStrings() { return fNumStrings; }

  /**
   * @param strings the new number of strings for the geometry
   */
  void NumStrings(Int_t strings) { fNumStrings = strings; }

  /**
   * @return the name of the array.  E.g. 'AmandaB10'
   */
  string ArrayName() { return fArrayName; }

  /**
   * @param arg the new name for the array
   */
  void  ArrayName( const string &arg) { fArrayName = arg; }

  // note that it is not a reference returned, we need that copy constructor
  /**
   * @return the name of the stream on which this header belongs i.e "Geometry"
   */
  const string DataStream() { return "Geometry"; }

 private:
  
  // ROOT macro
  ClassDef(I3GeometryDataHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3GeometryDataHeader>::ThePolicy I3GeometryDataHeaderPtr;

#endif //I3GEOMETRYHEADER_H
