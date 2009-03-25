//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id: ithon.cxx 25598 2006-11-25 02:52:57Z troy $
//
//   This file is part of IceTray.
//
//   IceTray is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
//   IceTray is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <vector>

#include <dataclasses/physics/I3MCTreeUtils.h>
#include <dataclasses/physics/I3MCTree.h>

using namespace boost::python;

inline boost::shared_ptr<I3Particle> GetMostEnergeticPrimary(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticPrimary(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr(new I3Particle());
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergeticInIce(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticInIce(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr(new I3Particle());
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergetic(I3MCTree* tree,I3Particle::ParticleType type)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergetic(*tree,type);
  if (itr==tree->end())
    {
      return I3ParticlePtr(new I3Particle());
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergeticTrack(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticTrack(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr(new I3Particle());
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}
inline boost::shared_ptr<I3Particle> GetMostEnergeticCascade(I3MCTree* tree)
{
  I3MCTree::iterator itr=I3MCTreeUtils::GetMostEnergeticCascade(*tree);
  if (itr==tree->end())
    {
      return I3ParticlePtr(new I3Particle());
    }
  else
    {
      return I3ParticlePtr(new I3Particle(*itr));
    }
}

inline vector<double> MPSpeedProfile(I3MCTree* tree){
  vector<double> speed_prof;
  I3MCTree::iterator iter = I3MCTreeUtils::GetMostEnergeticPrimary(*tree);
  while(iter.number_of_children()){
    if(iter.number_of_children() > 1) log_fatal("wasn't expecting more than one child.");
    if(iter->GetType() == I3Particle::Monopole){
      speed_prof.push_back(iter->GetSpeed()/I3Constants::c);
      iter = tree->child(iter,0);
    }
  }
  return speed_prof;
}

vector<I3Particle> GetInIce(I3MCTreePtr t){
  return I3MCTreeUtils::GetInIce(t);
}

void AddPrimary(I3MCTreePtr t, I3ParticlePtr p){
  return I3MCTreeUtils::AddPrimary(*t,*p);
}

void AppendChild(I3MCTreePtr t, I3ParticlePtr p, I3ParticlePtr d){
  return I3MCTreeUtils::AppendChild(*t,*p, *d);
}

int NCascades(I3MCTreePtr t){
  int n_cascades(0);
  I3MCTree::iterator t_iter = t->begin();
  for( ; t_iter != t->end(); t_iter++){
    if(t_iter->IsCascade()) n_cascades++;
  }
  return n_cascades;
}

vector<I3Particle> GetPrimaries(I3MCTreePtr t){
  return I3MCTreeUtils::GetPrimaries(t);
}

void Merge(I3MCTreePtr t, I3MCTreePtr t2){
  I3MCTree::sibling_iterator si;
  for(si = t2->begin(); si != t2->end(); si++){      
    t->insert_subtree(t->begin(),si);
  }
}

void TimeShift(I3MCTreePtr t, double dt){
  I3MCTree::iterator i;
  for(i = t->begin(); i != t->end(); i++){
    i->SetTime( i->GetTime() + dt);
  }
}

vector<I3Particle> 
GetDaughters(I3MCTreePtr t, I3ParticlePtr p){
  return I3MCTreeUtils::GetDaughters(*t,*p);
}

inline I3ParticlePtr Get(const I3MCTree& tree, const I3MCHit& hit)
{
  return I3ParticlePtr(new I3Particle(I3MCTreeUtils::Get(tree,hit)));
}

inline I3ParticlePtr GetPrimary(const I3MCTree& tree, const I3Particle& particle)
{
  return I3ParticlePtr(new I3Particle(*I3MCTreeUtils::GetPrimary(tree,particle)));
}

void register_I3MCTree()
{
  class_<I3MCTree, bases<I3FrameObject>, I3MCTreePtr>("I3MCTree")
    .def("GetMostEnergeticPrimary",&GetMostEnergeticPrimary)
    .def("GetMostEnergeticCascade",&GetMostEnergeticCascade)
    .def("GetMostEnergeticInIce",&GetMostEnergeticInIce)
    .def("GetMostEnergetic",&GetMostEnergetic)
    .def("GetMostEnergeticTrack",&GetMostEnergeticTrack)
    .def("MPSpeedProfile",&MPSpeedProfile)
    .def("GetInIce",&GetInIce)
    .def("GetPrimaries",&GetPrimaries)
    .def("NCascades",&NCascades)
    .def("Merge",&Merge)
    .def("TimeShift",&TimeShift)
    .def("GetDaughters",&GetDaughters)
    .def("AddPrimary",&AddPrimary)
    .def("AppendChild",&AppendChild)
    .def("Get",&Get)
    .def("GetPrimary",&GetPrimary)
    .def("__iter__", range<return_value_policy<copy_non_const_reference> >
	 (
	  (I3MCTree::pre_order_iterator(I3MCTree::*)() const) &I3MCTree::begin, 
	  (I3MCTree::pre_order_iterator(I3MCTree::*)() const) &I3MCTree::end
	  )
	 )
    ;

  register_pointer_conversions<I3MCTree>();
}
