//
//   Copyright (c) 2004, 2005, 2006, 2007   Troy D. Straszheim  
//   
//   $Id$
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
#include <exception>

#include <dataclasses/physics/I3MCTree.h>
#include <dataclasses/physics/I3MCTreeUtils.h>
#include <dataclasses/I3Constants.h>
#include <icetray/python/copy_suite.hpp>
#include <icetray/python/operator_suite.hpp>
#include <icetray/python/boost_serializable_pickle_suite.hpp>
#include <boost/python/exception_translator.hpp>

using namespace boost::python;

struct not_found_exception : std::exception
{
  std::string msg;
  not_found_exception(std::string m) : msg(m) { }
  ~not_found_exception() throw () { }
  char const* what() const  throw() { return msg.c_str(); }
};
void translate(const not_found_exception& e)
{
    // Use the Python 'C' API to set up an exception object
    PyErr_SetString(PyExc_IndexError, e.what());
}

I3Particle getParticle(const I3MCTree::nonPtrType& ptr, std::string err="")
{
  if (ptr)
    return *ptr;
  else
    throw not_found_exception(err);
}
I3Particle get_head(const I3MCTree& t)
{ return getParticle(t.get_head(),"no head in tree"); }
I3Particle parent(const I3MCTree& t,const I3ParticleID& p)
{ return getParticle(t.parent(p),"particle not found or no parent"); }
I3Particle previous_sibling(const I3MCTree& t,const I3ParticleID& p)
{ return getParticle(t.previous_sibling(p),"particle not found or no sibling"); }
I3Particle next_sibling(const I3MCTree& t,const I3ParticleID& p)
{ return getParticle(t.next_sibling(p),"particle not found or no sibling"); }
I3Particle first_child(const I3MCTree& t,const I3ParticleID& p)
{ return getParticle(t.first_child(p),"particle not found or no chilren"); }
I3Particle at(const I3MCTree& t,const I3ParticleID& p)
{ return getParticle(t.at(p),"particle not found in tree"); }

bool contains(const I3MCTree& t,const I3ParticleID& p)
{ return bool(t.at(p)); }
const std::vector<I3Particle> (I3MCTree::*children)(const I3ParticleID&) const  = &I3MCTree::children;
void (I3MCTree::*erase)(const I3ParticleID&) = &I3MCTree::erase;
void (I3MCTree::*erase_children)(const I3ParticleID&) = &I3MCTree::erase_children;
void (I3MCTree::*append_child_subtree)(const I3ParticleID&,const I3MCTree&,const I3ParticleID&) = &I3MCTree::append_child;
void (I3MCTree::*append_children)(const I3ParticleID&,const std::vector<I3Particle>&) = &I3MCTree::append_children;
void (I3MCTree::*insert_head)(const I3Particle&) = &I3MCTree::insert;
void (I3MCTree::*insert_after_head)(const I3Particle&) = &I3MCTree::insert_after;
void (I3MCTree::*insert)(const I3ParticleID&,const I3Particle&) = &I3MCTree::insert;
void (I3MCTree::*insert_after)(const I3ParticleID&,const I3Particle&) = &I3MCTree::insert_after;
void (I3MCTree::*insert_subtree)(const I3ParticleID&,const I3MCTree&,const I3ParticleID&) = &I3MCTree::insert_subtree;
void (I3MCTree::*insert_subtree_after)(const I3ParticleID&,const I3MCTree&,const I3ParticleID&) = &I3MCTree::insert_subtree_after;
void (I3MCTree::*replace)(const I3ParticleID&,const I3Particle&) = &I3MCTree::replace;
void (I3MCTree::*replace_subtree)(const I3ParticleID&,const I3MCTree&,const I3ParticleID&) = &I3MCTree::replace;
void (I3MCTree::*flatten)(const I3ParticleID&) = &I3MCTree::flatten;
void (I3MCTree::*reparent)(const I3ParticleID&,const I3ParticleID&) = &I3MCTree::reparent;
I3MCTree::size_type (I3MCTree::*depth)(const I3ParticleID&) const = &I3MCTree::depth;
I3MCTree::size_type (I3MCTree::*number_of_children)(const I3ParticleID&) const = &I3MCTree::number_of_children;
I3MCTree::size_type (I3MCTree::*number_of_siblings)(const I3ParticleID&) const = &I3MCTree::number_of_siblings;
bool (I3MCTree::*is_in_subtree)(const I3ParticleID&,const I3ParticleID&) const = &I3MCTree::is_in_subtree;
bool (I3MCTree::*subtree_in_tree)(const I3MCTree&,const I3ParticleID&) const = &I3MCTree::subtree_in_tree;

void register_I3MCTree()
{
  {
    register_exception_translator<not_found_exception>(&translate);
    
    scope outer = 
      class_<I3MCTree, bases<I3FrameObject>, I3MCTreePtr>("I3MCTree",
        "A tree of I3Particles used for simulation.")
        // I3MCTreeUtils
        .def("get_daughters", &I3MCTreeUtils::GetDaughters, "Get all daughters/children of an I3ParticleID")
        .def("has_parent", &I3MCTreeUtils::HasParent, "Does the I3ParticleID have a parent?")
        .def("add_primary", &I3MCTreeUtils::AddPrimary, "Add an I3Particle as a primary (at root-level)")
        .def("get_primary", &I3MCTreeUtils::GetPrimary, "Get the primary that created the I3ParticleID")
        .def("get_primaries", &I3MCTreeUtils::GetPrimaries, "Get a list of all primaries")
        .add_property("primaries", &I3MCTreeUtils::GetPrimaries)
        .def("append_child", &I3MCTreeUtils::AppendChild, "Add a child to an I3ParticleID")
        .def("get_particle", &I3MCTreeUtils::GetParticle, "Get the I3Particle represented by the I3ParticleID")
        .def("dump", &I3MCTreeUtils::Dump, "Return tree as a string")
        
        // Base Class Methods
        .def("get_head", &get_head, "Get the left-most primary (the root or head of the tree)")
        .def("at", &at, "Get the I3Particle represented by the I3ParticleID")
        .def("parent", &parent, "Get the parent of the I3ParticleID")
        .def("previous_sibling", &previous_sibling, "Get the previous sibling of the I3ParticleID")
        .def("next_sibling", &next_sibling, "Get the next sibling of the I3ParticleID")
        .def("children", children, "Get the children of the I3ParticleID")
        .def("first_child", &first_child, "Get the first (left-most) child of the I3ParticleID")
        .def("clear", &I3MCTree::clear, "Clear everything from the tree")
        .def("erase", erase, "Erase the I3ParticleID and all children")
        .def("erase_children", erase_children, "Erase only the children of the I3ParticleID (keeping the I3ParticleID itself)")
        .def("append_child", append_child_subtree)
        .def("append_children", append_children, "Add multiple children to an I3ParticleID")
        .def("insert", insert_head, "Add an I3Particle at the root level, before other I3Particles")
        .def("insert_after", insert_after_head, "Add an I3Particle at the root level, after other I3Particles")
        .def("insert", insert, "Add an I3Particle before the sibling I3ParticleID")
        .def("insert_after", insert_after, "Add an I3Particle after the sibling I3ParticleID")
        .def("insert_subtree", insert_subtree, "Add a subtree of I3Particles before the sibling I3ParticleID")
        .def("insert_subtree_after", insert_subtree_after, "Add a subtree of I3Particles after the sibling I3ParticleID")
        .def("replace", replace, "Replace an I3ParticleID with another I3Particle")
        .def("replace", replace_subtree, "Replace an I3ParticleID and all children with another subtree of I3Particles")
        .def("flatten", flatten, "Move the children of the I3Particle to be siblings after it")
        .def("reparent", reparent, "Move all children of an I3ParticleID to be children under another I3ParticleID in the tree")
        .def("merge",&I3MCTree::merge, "Merge two trees, modifying the first tree")
        .def("size", &I3MCTree::size, "Get the number of I3Particles in the tree")
        .def("empty", &I3MCTree::empty, "Is the tree empty?")
        .def("depth", depth, "Get the depth from the I3ParticleID to the primary")
        .def("number_of_children", number_of_children, "Get the number of children an I3ParticleID has")
        .def("number_of_siblings", number_of_siblings, "Get the number of siblings an I3ParticleID has")
        .def("is_in_subtree", is_in_subtree, "Is an I3ParticleID in a subtree?")
        .def("subtree_in_tree", subtree_in_tree, "Is any part of a subtree in the tree?")
        
         // Python Special Methods
        .def("__str__", &I3MCTreeUtils::Dump)
        .def("__nonzero__", &I3MCTree::empty)
        .def("__len__", &I3MCTree::size)
        .def("__iter__", range<return_value_policy<copy_non_const_reference> >
          (
            (I3MCTree::pre_order_iterator(I3MCTree::*)()) &I3MCTree::begin, 
            (I3MCTree::pre_order_iterator(I3MCTree::*)()) &I3MCTree::end
          )
        )
        .def("__contains__", &contains)
        .def("__getitem__", &at)
        .def("__delitem__", erase)
        .def(copy_suite<I3MCTree>())
        .def(operator_suite<I3MCTree>())
        .def_pickle(boost_serializable_pickle_suite<I3MCTree>())
      ;
  }
  
  register_pointer_conversions<I3MCTree>();
}

