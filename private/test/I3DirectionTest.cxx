/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.3 $
    @date $Date$
    @author dule

    @todo
*/

#include <I3Test.h>

#include "dataclasses/I3Direction.h"
#include "dataclasses/I3Units.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;
using namespace I3Units;

TEST_GROUP(I3DirectionTest);
  
/**
 * check that constructor and destructor work
 */
TEST(const_dest)
{
  I3DirectionPtr ptr(new I3Direction());
}
  
/**
 * check writing object to disk
 */
TEST(write_to_disk)
{
  I3DirectionPtr ptr(new I3Direction());
  
  /** @todo should fill some data for I3Direction here */
  
  TFile f_out("test.out.root","RECREATE");
  ptr->Write();
  f_out.Close();
  
  TFile f_in("test.out.root");
  TObject* object_in =
    f_in.FindObjectAny("I3Direction");
  f_in.Close();
  ENSURE(object_in,"the read-in pointer is non-zero");
  
  I3Direction* tested_in = dynamic_cast<I3Direction*>(object_in);
  ENSURE(tested_in,"the read-in pointer is of the right type");
  
  I3DirectionPtr ptr_in(tested_in);
  
  /** @todo should check the read-in data for I3Direction here */
  
}
   
/**
 * check branching it to a tree
 */
TEST(branch_to_tree)
{
  I3DirectionPtr ptr(new I3Direction());
  /** @todo add some setting of data here */
  
  I3Direction* raw_ptr = &(*ptr);
  TTree tree("TestTree","Icecube");
  tree.Branch("branch","I3Direction",&raw_ptr);
  
  tree.Fill();
  
  I3Direction* raw_ptr_in = new I3Direction();
  I3DirectionPtr ptr_in (raw_ptr_in);
  
  tree.SetBranchAddress("branch",&raw_ptr_in);
  tree.GetEvent(0);
  
  /** @todo add some checking of the data of I3Direction here */
  
}

/**
 * check branching object to a tree, writing the tree to disk,
 * and reading the tree back in, and finding the object in the tree.
 */
TEST(branch_and_write)
{
  I3DirectionPtr ptr(new I3Direction());
  /** @todo add some setting of data here */
  
  I3Direction* raw_ptr = &(*ptr);
  TTree tree("TestTree","Icecube");
  tree.Branch("branch","I3Direction",&raw_ptr);
  tree.Fill();
  
  TFile file_out("test.out.root","RECREATE");
  tree.Write();
  file_out.Close();
  
  
  TFile file_in("test.out.root");
  TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
  ENSURE(tree_in,"the test tree exists");
  
  I3Direction* raw_ptr_in = new I3Direction();
  I3DirectionPtr ptr_in (raw_ptr_in);
  
  tree_in->SetBranchAddress("branch",&raw_ptr_in);
  tree_in->GetEvent(0);
  
  /** @todo add some checking of the data of I3Direction here */
  
  delete tree_in;
}

/**
 * Make sure that the changing of coordinate systems works well
 */
TEST(coord_change)
{
  cout <<"Creating I3Direction..."<<endl;
  I3Direction dir;
  cout <<"Setting dir: zen=(180-54.74)deg, azi=-135deg (i.e.1,1,1)..."<<endl;
  dir.SetDirection((180-54.73561)*deg, -135*deg);
  ENSURE_DISTANCE(dir.GetZenith()/deg,125.264,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,-135.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir.GetX(),0.57735,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir.GetY(),0.57735,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir.GetZ(),0.57735,0.0001,"dir.GetZ failed");
  
  cout <<"Setting dir: x=1,y=1,z=0..."<<endl;
  dir.SetDirection(1,1,0);
  ENSURE_DISTANCE(dir.GetZenith()/deg,90.0,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,225.0,0.001,"dir.GetAzimuth failed");
  
  cout <<"Setting values for dir in zen=0,azi=0 (i.e. down)..."<<endl;
  dir.SetDirection(0,0);
  ENSURE_DISTANCE(dir.GetX(),0.0,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir.GetY(),0.0,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir.GetZ(),-1.0,0.0001,"dir.GetZ failed");
  
  cout <<"Rotating dir around x-axis by +90deg... ==> +y-axis"<<endl;
  dir.RotateX(90*deg);
  ENSURE_DISTANCE(dir.GetZenith()/deg,90.0,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,270.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir.GetX(),0.0,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir.GetY(),1.0,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir.GetZ(),0.0,0.0001,"dir.GetZ failed");
  
  cout <<"Rotating dir around z-axis by -45deg...==> x=1,y=1,z=0"<<endl;
  dir.RotateZ(-45*deg);
  ENSURE_DISTANCE(dir.GetZenith()/deg,90.0,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,225.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir.GetX(),0.707107,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir.GetY(),0.707107,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir.GetZ(),0.0,0.0001,"dir.GetZ failed");
  
  cout <<"Rotating dir around y-axis by -90deg... ==> x=0,y=1,z=1"<<endl;
  dir.RotateY(-90*deg);
  ENSURE_DISTANCE(dir.GetZenith()/deg,135.0,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,270.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir.GetX(),0.0,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir.GetY(),0.707107,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir.GetZ(),0.707107,0.0001,"dir.GetZ failed");
  
}

