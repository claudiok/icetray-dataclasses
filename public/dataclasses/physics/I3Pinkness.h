/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: I3TreeTest.cxx 10872 2005-08-31 16:19:29Z tschmidt $

    @version $Revision: 1.8 $
    @date $Date: 2005-08-31 12:19:29 -0400 (Wed, 31 Aug 2005) $
    @author tschmidt
*/
#include <dataclasses/physics/I3MCParticle.h>

using namespace std;

class I3Pinkness{
public:
  double GetPinkness(){ return pinkness_; };
  void SetPinkness(double p){ pinkness_ = p; };
private:
  double pinkness_;
  template <class Archive> void serialize(Archive & ar, unsigned version){
    ar & make_nvp("Pinkness", pinkness_ );}
};

typedef I3MCParticle<I3Pinkness> I3PinkParticle;
