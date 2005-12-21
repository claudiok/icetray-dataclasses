/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id$
 *
 * @file I3Event.h
 * @version $Revision: 1.50 $
 * @date $Date$
 * @author Ralf Ehrlich
 */
#ifndef I3EVENT_H
#define I3EVENT_H

#include <TObject.h>

#include "I3OMResponseMap.h"
#include <sstream>

/**
 * @brief Top-level object for the event-specifc information (Physics
 * stream)
 *
 * This class stores all the information that is specific to the
 * single event record: OM and IceTop tank responses, reconstruction
 * results, trigger and filter records, etc.
 * It does not contain more 
 * static information, like geometry, calibration, or monitoring
 * data.  It also contains an I3Bag of user-defined information.
 */

// class boost::serialization::access;

class I3Event : public TObject
{
  I3OMResponseMap   oMResponseMap_; 
  I3OMResponseMap   topOMResponseMap_; 
  
  public:
  /**
   * default constructor
   */
  I3Event() { };
  
  /**
   * default destructor
   */
  virtual ~I3Event();

  /**
   * @return the OMResponseMap of the event as a constant object
   */
  const I3OMResponseMap& GetOMResponseMap() const { return oMResponseMap_; }

  /**
   * @return the OMResponseMap as non-constant object
   */
  I3OMResponseMap& GetTopOMResponseMap() { return topOMResponseMap_; }

  /**
   * @return the TopOMResponseMap of the event as a constant object
   */
  const I3OMResponseMap& GetTopOMResponseMap() const { return topOMResponseMap_; }

  /**
   * @return the TopOMResponseMap as non-constant object
   */
  I3OMResponseMap& GetOMResponseMap() { return oMResponseMap_; }

  /**
   * @param o the stream we're printing the object to
   */
  virtual void ToStream(ostream& o) const
    {
      o<<"[ I3Event \n"
       <<oMResponseMap_
       <<topOMResponseMap_
       <<"]\n";
    }

  virtual string ToString() const
    {
      ostringstream out;
      ToStream(out);
      return out.str();
    }

  // Allowing default copy and assignment operators

  private:

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version);

};


/** 
 * streaming operator
 */
inline ostream& operator<<(ostream& o,const I3Event& evt)
{
  evt.ToStream(o);
  return o;
}

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef shared_ptr<I3Event>  I3EventPtr;

#endif
