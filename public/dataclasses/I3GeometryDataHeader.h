#ifndef I3GEOMETRYHEADER_H
#define I3GEOMETRYHEADER_H
/**
 * Class: I3GeometryDataHeader
 *
 * Version: $Id: I3GeometryDataHeader.h,v 1.2 2004/02/17 15:48:13 troy Exp $
 *
 * Date: 13 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

// includes
#include "I3DataHeader.h"
#include <string>
using namespace std;

/**
 * I3Geometry Header is supposed to be a header for the geometry that
 * you can store in a file if you don't want to store the geometry.
 * It's supposed to have enough data to reconstruct the full geometry
 * from the database
 * @version $Id: I3GeometryDataHeader.h,v 1.2 2004/02/17 15:48:13 troy Exp $
 * @author pretz
 */
class I3GeometryDataHeader : public I3DataHeader
{

  // copy and assignment are private
  I3GeometryDataHeader(const I3GeometryDataHeader&);
  I3GeometryDataHeader& operator=(const I3GeometryDataHeader&);

  // instance data
  Int_t fNumOms;
  Int_t fNumStrings;
  string fArrayName;
  
 public:
  I3GeometryDataHeader()  : fNumOms(-1), fNumStrings(-1){;}

  virtual ~I3GeometryDataHeader() {;}

  Int_t NumOms() { return fNumOms; }
  void NumOms(Int_t arg) { fNumOms = arg; }

  Int_t NumStrings() { return fNumStrings; }
  void NumStrings(Int_t strings) { fNumStrings = strings; }

  string ArrayName() { return fArrayName; }
  void  ArrayName( const string &arg) { fArrayName = arg; }

  // note that it is not a reference returned, we need that copy constructor
  const string DataStream() { return "Geometry"; }

  ClassDef(I3GeometryDataHeader,1);
};

#endif //I3GEOMETRYHEADER_H
