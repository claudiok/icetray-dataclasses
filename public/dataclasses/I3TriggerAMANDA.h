/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Trigger.h,v 1.5 2004/08/31 02:56:29 pretz Exp $
 *
 * @file I3TriggerAMANDA.h
 * @version $Revision: 1.5 $
 * @date $Date: 2004/08/31 02:56:29 $
 * @author blaufuss
 * @author deyoung
 * @author ehrlich
 */

#ifndef I3TRIGGERAMANDA_H
#define I3TRIGGERAMANDA_H

#include "dataclasses/I3Trigger.h"
#include "dataclasses/StoragePolicy.h"

using namespace std; 

/**
 * @brief The trigger class for AMANDA triggers.  
 */
class I3TriggerAMANDA : public I3Trigger
{
  private:
  vector<double>  TriggerTime;      // Time at which the trigger was issued
  vector<double>  TriggerLength;    // Duration of triggered readout window
  int             TriggerChannel;   // Trigger Channel
  bool            Fired;            // fired
    
  public:
  I3TriggerAMANDA() {TriggerChannel=0; Fired=0;}
  virtual ~I3TriggerAMANDA() {}
  vector<double> GetTriggerTime() const {return TriggerTime;}
  vector<double> GetTriggerLength() const {return TriggerLength;}
  int GetTriggerChannel() const {return TriggerChannel;}
  void SetTriggerChannel(int channel) {TriggerChannel = channel;}
  bool GetTriggerFired() const {return Fired;}
  void SetTriggerFired(bool fired) {Fired = fired;}
  virtual TrigSubDetector GetSubDetector() const {return Amanda;}

  /**
   * @todo finish with all the data
   */
  virtual void ToStream(ostream& o) const
  {
	o<<"[ "
	 <<IsA()->GetName()
	 <<" Sub Detector ID:"
	 <<Amanda
	 <<" ]\n";
  }
/*
  virtual string ToString() const
  {
	ostringstream out;
	ToStream(out);
	return out.str();
  }
*/
    
  private:
  friend class boost::serialization::access;
  template <class Archive> void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("I3Trigger", base_object<I3Trigger>(*this));
    ar & make_nvp("TriggerTime",TriggerTime);
    ar & make_nvp("TriggerLength",TriggerLength);
    ar & make_nvp("TriggerChannel",TriggerChannel);
    ar & make_nvp("Fired",Fired);
  }

  ClassDef(I3TriggerAMANDA,1);
};

BOOST_SHARED_POINTER_EXPORT(I3TriggerAMANDA);

/**
 * streams an I3Trigger to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o,const I3TriggerAMANDA& g)
{
    g.ToStream(o); 
    return o;
}

/**
 * pointer type to insulate users from memory management
 */
typedef shared_ptr<I3TriggerAMANDA> I3TriggerAMANDAPtr;

#endif

