/**
 * copyright  (C) 2004
 * the icecube collaboration
 * @version $Id: I3TWRFrag.h,v 1.2 2005/02/21 06:47:54 ehrlich Exp $
 * 
 * @file I3TWRFrag.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005/02/21 06:47:54 $
 */
#ifndef I3TWRFRAG_H_INCLUDED
#define I3TWRFRAG_H_INCLUDED

// forward declarations


// header files

#include <vector>

#include <dataclasses/Utility.h>

// definitions


class I3TWRFrag 
{
  private:
  unsigned int startBin_;
  std::vector<unsigned int> rawFADC_;

  public:
  /** Default constructor.
   */
  I3TWRFrag() : startBin_(0u){}
  /** Destructor.
   */
  virtual ~I3TWRFrag();

  /** Returns the position of the fragment within the waveform.
   * 
   * @return The position.
   */
  unsigned int GetStartBin() const { return(startBin_); }
  /** Sets the position of the fragment within the waveform.
   * 
   * @param startBin The position.
   */
  void SetStartBin(unsigned int startBin) { startBin_ = startBin;}  
  /** Provides access to the waveform information of the fragment.
   *
   * @return The waveform information.
   */
  const std::vector<unsigned int>& GetWaveform() const { return(rawFADC_); }
  /** Provides access to the waveform information of the fragment.
   *
   * @return The waveform information.
   */
  std::vector<unsigned int>& GetWaveform() { return(rawFADC_); }

  private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);
};

//TODO: backwards compatible serialization
//BOOST_CLASS_VERSION(I3TWRFrag, 1);

I3_POINTER_TYPEDEFS(I3TWRFrag);

#endif /*I3TWRFRAG_H_INCLUDED*/


