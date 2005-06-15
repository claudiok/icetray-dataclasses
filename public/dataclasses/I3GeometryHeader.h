/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3GeometryHeader.h
 * @version $Revision: 1.10 $
 * @date $Date$
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
  int numOMs_;
  int numStrings_;
  string arrayName_;
  
 public:
  /**
   * constructor
   */
  I3GeometryHeader()  : numOMs_(-1), numStrings_(-1){;}

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
    numOMs_ = rhs.numOMs_;
    numStrings_ = rhs.numStrings_;
    arrayName_ = rhs.arrayName_;
    return *this;
  }

  /**
   * @return the total number of oms for the geometry
   */
  int GetNumOms() const{ return numOMs_; }

  /**
   * @param arg the new number of oms for the geometry
   */
  void SetNumOms(int arg) { numOMs_ = arg; }

  /**
   * @return the number of strings for the geometry
   */
  int GetNumStrings() const { return numStrings_; }

  /**
   * @param strings the new number of strings for the geometry
   */
  void SetNumStrings(int strings) { numStrings_ = strings; }

  /**
   * @return the name of the array.  E.g. 'AMANDAB10'
   */
  string GetArrayName() const{ return arrayName_; }

  /**
   * @param arg the new name for the array
   */
  void  SetArrayName( const string &arg) { arrayName_ = arg; }

  // note that it is not a reference returned, we need that copy constructor
  /**
   * @return the name of the stream on which this header belongs i.e "Geometry"
   */
  const string GetDataStream() { return "Geometry"; }

 private:
  
  // ROOT macro
  ClassDef(I3GeometryHeader,1);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("numOMs",numOMs_);
    ar & make_nvp("numStrings",numStrings_);
    ar & make_nvp("arrayName",arrayName_);
  }

};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3GeometryHeader>  I3GeometryHeaderPtr;

#endif //I3GEOMETRYHEADER_H
