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
#include <string>
using std::string;
using std::cout;
using std::endl;
using namespace I3Units;

TEST_GROUP(I3DirectionTest); 

#ifdef I3_USE_ROOT
#include "TFile.h"
#include "TTree.h"


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
#endif

/**
 * check that constructor and destructor work
 */
TEST(const_dest)
{
  I3DirectionPtr ptr(new I3Direction());
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
  
  cout <<"Creating another I3Direction..."<<endl;
  I3Direction dir2;
  dir2.SetDirection(1.0,0.0,1.0);  // Not properly normalized
  //Recall Azimuth/Zenith are the direction back to sourcethat originates a particle
  //  with this direction.
  ENSURE_DISTANCE(dir2.GetZenith()/deg,(180.0-45.0),0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir2.GetAzimuth()/deg,180.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir2.CalcTheta()/deg,(45.0),0.001,"dir.CalcTheta failed");
  ENSURE_DISTANCE(dir2.CalcPhi()/deg,0.0,0.001,"dir.CalcPhi failed");
  //Make sure the GetX, etc are properly renormalized.
  ENSURE_DISTANCE(dir2.GetX(),0.7071,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir2.GetY(),0.,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir2.GetZ(),0.7071,0.0001,"dir.GetZ failed");
  //Now change the direction, make sure everthing is updated properly
  dir2.SetDirection(1.0,1.0,1.0);  // Not properly normalized
  ENSURE_DISTANCE(dir2.GetZenith()/deg,(180.0-54.736),0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir2.GetAzimuth()/deg,(225.0),0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir2.CalcTheta()/deg,(54.736),0.001,"dir.CalcTheta failed");
  ENSURE_DISTANCE(dir2.CalcPhi()/deg,45.0,0.001,"dir.GetPhi failed");
  //Make sure the GetX, etc are properly renormalized.
  ENSURE_DISTANCE(dir2.GetX(),0.57735,0.0001,"dir.GetX failed");
  ENSURE_DISTANCE(dir2.GetY(),0.57735,0.0001,"dir.GetY failed");
  ENSURE_DISTANCE(dir2.GetZ(),0.57735,0.0001,"dir.GetZ failed");

  cout <<"Setting dir: x=1,y=1,z=0..."<<endl;
  dir.SetDirection(1,1,0);
  ENSURE_DISTANCE(dir.GetZenith()/deg,90.0,0.001,"dir.GetZenith failed");
  ENSURE_DISTANCE(dir.GetAzimuth()/deg,225.0,0.001,"dir.GetAzimuth failed");
  ENSURE_DISTANCE(dir.GetX(),0.7071,0.001,"dir.X failed");
  ENSURE_DISTANCE(dir.GetY(),0.7071,0.001,"dir.Y failed");
  ENSURE_DISTANCE(dir.GetZ(),0.0,0.001,"dir.Z failed");

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

TEST(setdir)
{
  I3Direction d(90*deg,-90*deg);
  ENSURE_DISTANCE(d.GetX(),0,0.0001);
  ENSURE_DISTANCE(d.GetY(),1,0.0001);
  ENSURE_DISTANCE(d.GetZ(),0,0.0001);
  ENSURE_DISTANCE(d.GetZenith(),90*deg,0.0001);
  ENSURE_DISTANCE(d.GetAzimuth(),-90*deg,0.0001);

  d.SetDir(1,1,1);
  ENSURE_DISTANCE(d.GetX(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetY(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetZ(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetZenith(),2.18627,0.0001);
  ENSURE_DISTANCE(d.GetAzimuth(),225*deg,0.0001);

  d.SetDir(2.18627,-135*deg);
  ENSURE_DISTANCE(d.GetX(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetY(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetZ(),1./sqrt(3.),0.0001);
  ENSURE_DISTANCE(d.GetZenith(),2.18627,0.0001);
  ENSURE_DISTANCE(d.GetAzimuth(),-135*deg,0.0001);
}
