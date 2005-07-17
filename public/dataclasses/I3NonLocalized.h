/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3NonLocalized.h
 * @version $Revision: 1.2 $
 * @date $Date$
 * @author ehrlich
 * @author Peter Niessen
 */
#ifndef I3NONLOCALIZED_H
#define I3NONLOCALIZED_H


/**
 * @brief The core position part of an I3Primary implementation.  
 * 
 * Represents a a primary where the core location is unknown.
 */
class I3NonLocalized 
{
 public:
  /**
   * indicates that the core position isn't known
   */
  bool IsCoreLocalized() const { return false;}

  /**
   * indicates that the inice position isn't known
   */
  bool IsLocalized() const { return false;}

  /**
   * nothing to copy. does nothing.
   */
  void CopyTo(I3Particle& destination) const {}

  virtual ~I3NonLocalized() { }
 private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    //This method intentionally left blank
  }

  //ROOT macro
  ClassDef(I3NonLocalized,1);
};

#endif
