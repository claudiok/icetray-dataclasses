#ifndef I3GEOMETRYHEADER_H
#define I3GEOMETRYHEADER_H
/**
 * Class: I3GeometryDataHeader
 *
 * Version: $Id: I3GeometryDataHeader.h,v 1.1 2004/02/15 15:25:32 troy Exp $
 *
 * Date: 13 Jan 2004
 *
 * (c) 2004 IceCube Collaboration
 */

// includes
#include "I3DataHeader.h"
#include "TString.h"

/**
 * I3Geometry Header is supposed to be a header for the geometry that
 * you can store in a file if you don't want to store the geometry.
 * It's supposed to have enough data to reconstruct the full geometry
 * from the database
 * @version $Id: I3GeometryDataHeader.h,v 1.1 2004/02/15 15:25:32 troy Exp $
 * @author pretz
 */
class I3GeometryDataHeader : public I3DataHeader{
 public:
  /**
   * constructor
   */
  I3GeometryDataHeader();

  /**
   * destructor
   */
  virtual ~I3GeometryDataHeader();

  /**
   * retrieve the number of OMs
   * @return the number of OMs in the geometry
   */
  Int_t GetNumOms();

  /**
   * retrieves the number of strings
   * @return the number of strings in the geometry
   */
  Int_t GetNumStrings();

  /**
   * retrieves the array name, for example AMAII
   * or B10 or IceCube or whatever.
   * @return the array name
   */
  const Char_t* GetArrayName();

  /**
   * retrieves the name of the stream this header is for.
   * ... "Geometry"
   */
  const Char_t* GetDataStream();

  /**
   * sets the number of oms in the geometry header
   * @param oms the new number of oms
   */
  void SetNumOms(Int_t oms);

  /**
   * sets the number of strings
   * @param strings the new number of strings
   */
  void SetNumStrings(Int_t strings);

  /** 
   * sets the array name
   * @param name the new array name
   */
  void SetArrayName(const Char_t* name);
 private:
  // copy and assignment are private
  I3GeometryDataHeader(const I3GeometryDataHeader&);
  I3GeometryDataHeader& operator=(const I3GeometryDataHeader&);

  // instance data
  Int_t fNumOms;
  Int_t fNumStrings;
  TString fArrayName;
  
  // ROOT Macro
  ClassDef(I3GeometryDataHeader,1);
};

#endif //I3GEOMETRYHEADER_H
