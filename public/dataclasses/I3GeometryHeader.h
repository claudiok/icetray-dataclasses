/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3GeometryHeader.h,v 1.8 2005/04/04 15:49:25 pretz Exp $
 *
 * @file I3GeometryHeader.h
 * @version $Revision: 1.8 $
 * @date $Date: 2005/04/04 15:49:25 $
 * @author ehrlich
 * @author troy
 * @author pretz
 */
#ifndef I3GEOMETRYHEADER_H
#define I3GEOMETRYHEADER_H

// includes
#include "I3DataHeader.h"
#include "StoragePolicy.h"
#include <string>
using namespace std;

/**
 * @brief The header for the data on the Geometry stream
 *
 * Summary information for the geometry that
 * which you can store in a file if you don't want to store the geometry.
 * It's will have enough data to reconstruct the full geometry
 * from the database
 *
 */
class I3GeometryHeader : public I3DataHeader
{
  // instance data
  int fNumOms;
  int fNumStrings;
  string fArrayName;
  
 public:
  /**
   * constructor
   */
  I3GeometryHeader()  : fNumOms(-1), fNumStrings(-1){;}

  /**
   * destructor
   */
  virtual ~I3GeometryHeader() {;}

  /**
   * copy constructor just uses assignment
   */
  I3GeometryHeader(const I3GeometryHeader& rhs){*this = rhs;}

  /**
   * assignment is just a member-wise assignment
   */
  const I3GeometryHeader& operator=(const I3GeometryHeader& rhs){
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
  int GetNumOms() const{ return fNumOms; }

  /**
   * @param arg the new number of oms for the geometry
   */
  void SetNumOms(int arg) { fNumOms = arg; }

  /**
   * @return the number of strings for the geometry
   */
  int GetNumStrings() const { return fNumStrings; }

  /**
   * @param strings the new number of strings for the geometry
   */
  void SetNumStrings(int strings) { fNumStrings = strings; }

  /**
   * @return the name of the array.  E.g. 'AMANDAB10'
   */
  string GetArrayName() const{ return fArrayName; }

  /**
   * @param arg the new name for the array
   */
  void  SetArrayName( const string &arg) { fArrayName = arg; }

  // note that it is not a reference returned, we need that copy constructor
  /**
   * @return the name of the stream on which this header belongs i.e "Geometry"
   */
  const string GetDataStream() { return "Geometry"; }

 private:
  
  // ROOT macro
  ClassDef(I3GeometryHeader,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3GeometryHeader>::ThePolicy I3GeometryHeaderPtr;

#endif //I3GEOMETRYHEADER_H
