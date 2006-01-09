/**
 * copyright (C) 2005
 * The IceCube collaboration
 *
 * @file I3FlasherInfoVect.h
 * @version
 * @date
 * @author Doug Rutledge
 */

#ifndef __I3_FLASHER_INFO_VECT_H
#define __I3_FLASHER_INFO_VECT_H

#include "dataclasses/I3Trigger.h"
#include "dataclasses/I3FlasherInfo.h"
#include <vector>

class I3FlasherInfoVect : public I3Trigger
{
  public:
    I3FlasherInfoVect()
    {flashers_.clear();}
    
    /*
     * Returns the internal list of flashers.
     * @return a reference to a vector of I3FlasherInfo objects
     */
    vector<I3FlasherInfoPtr>& GetFlashers() 
    {return flashers_;}

    /**
     * Dumps this object and its contents into a given output stream
     * @param ostream& o a reference to an output stream
     */
    virtual void ToStream(ostream& o) const
    {
      o<<"I3FlasherInfoVect: " << flashers_.size()<<" flashers| ";
		            
      vector<I3FlasherInfoPtr> :: const_iterator flasher_iter;

      for(flasher_iter = flashers_.begin();
          flasher_iter != flashers_.end();
	  flasher_iter++)
      {
        I3FlasherInfoPtr flasherInfo = *flasher_iter;
        flasherInfo->ToStream(o);
      }//end iteration over flashers
    }//end ToStream
  private:
    //member fields
    vector<I3FlasherInfoPtr> flashers_;
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& archive, unsigned version);
    
   typedef shared_ptr<I3FlasherInfoVect> I3FlasherInfoVectPtr; 
};

#endif
