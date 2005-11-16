/**
 *
 * Based of the sieglinde class SLCalibrateDBAmacalib
 *
 * copyright  (C) 2004
 * the IceCube collaboration
 * $Id: I3AMANDAOMCalibration.h 7421 2005-05-09 03:41:09Z aya $
 *
 * @file I3AMANDAOMCalibration.h
 * @version $Revision: 1.14 $
 * @date $Date: 2005-05-08 23:41:09 -0400 (Sun, 08 May 2005) $
 * @author ehrlich
 */
#ifndef I3AMANDAOMCALIBRATION_XTALK_H
#define I3AMANDAOMCALIBRATION_XTALK_H

#include <sstream>
#include <TObject.h>
#include "dataclasses/OMKey.h"

class I3AMANDAOMCalib_XTalk : public TObject
{
  OMKey  receiver_;
  double timehigh_;
  double timelow_;
  double width_;
  double threshold_;
  
  public:
  I3AMANDAOMCalib_XTalk() {timehigh_=NAN; timelow_=NAN; width_=NAN;}
  virtual ~I3AMANDAOMCalib_XTalk();
  
  OMKey  GetReceiver()  {return receiver_;}
  double GetTimeHigh()  {return timehigh_;}
  double GetTimeLow()   {return timelow_;}
  double GetWidth()     {return width_;}
  double GetThreshold() {return threshold_;}

  void SetReceiver(OMKey receiver)    {receiver_=receiver;}
  void SetTimeHigh(double timehigh)   {timehigh_=timehigh;}
  void SetTimeLow(double timelow)     {timelow_=timelow;}
  void SetWidth(double width)         {width_=width;}
  void SetThreshold(double threshold) {threshold_=threshold;}

  virtual void ToStream(ostream& o) const
  {
    o<<"[ "
     <<"AMANDACalibration_XTalk"
     <<"]\n";
  };
  
  virtual string ToString() const
  {
    ostringstream out;
    ToStream(out);
    return out.str();
  }

  friend class boost::serialization::access;

  template <class Archive> void serialize(Archive & ar, unsigned version);
};

/**
 * streams an I3AMANDAOMCalib_XTalk to an arbitrary ostream
 */
inline ostream& operator<<(ostream& o, const I3AMANDAOMCalib_XTalk& c)
{
    c.ToStream(o); 
    return o;
}

typedef shared_ptr<I3AMANDAOMCalib_XTalk>  I3AMANDAOMCalib_XTalkPtr;

#endif

