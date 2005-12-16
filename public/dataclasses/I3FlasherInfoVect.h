#ifndef __I3_FLASHER_INFO_VECT_H
#define __I3_FLASHER_INFO_VECT_H

#include "dataclasses/I3Trigger.h"
#include "dataclasses/I3FlasherInfo.h"
#include <vector>

using namespace std;

class I3FlasherInfoVect : public I3Trigger
{
  public:
    I3FlasherInfoVect(){}
    virtual vector<I3FlasherInfoPtr>& GetFlashers() 
    {return flashers_;}

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
    virtual ~I3FlasherInfoVect(){}
  private:
    //member fields
    vector<I3FlasherInfoPtr> flashers_;
  private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& archive, unsigned version);
  ClassDef(I3FlasherInfoVect,1);    
};

typedef shared_ptr<I3FlasherInfoVect>  I3FlasherInfoVectPtr;
#endif
