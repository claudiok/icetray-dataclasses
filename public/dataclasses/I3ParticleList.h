#ifndef I3PARTICLELIST_H
#define I3PARTICLELIST_H

#include <vector>
#include "I3Particle.h"

class I3ParticleList : public TObject{
 private:
  vector<I3Particle*> fParticles;
 public:
  void Add(I3Particle* particle){fParticles.push_back(particle);}
  I3Particle* At(int i){return fParticles[i];}
  int Size(){return fParticles.size();}
  ClassDef(I3ParticleList,1);
};

#endif //I3PARTICLELIST_H
