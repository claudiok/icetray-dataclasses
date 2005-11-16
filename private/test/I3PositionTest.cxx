/**
    copyright  (C) 2004
    the icecube collaboration
    $Id$

    @version $Revision: 1.5 $
    @date $Date$
    @author pretz

    @todo
*/

#include <I3Test.h>

#include "dataclasses/I3Position.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

TEST_GROUP(I3PositionTest);


/**
 * check that constructor and destructor work
 */
TEST(constructor)
{
  I3PositionPtr ptr(new I3Position());
}

/**
 * check writing object to disk
 */
TEST(write)
{
  I3PositionPtr ptr(new I3Position());
  
  /** @todo should fill some data for I3Position here */
  
  TFile f_out("test.out.root","RECREATE");
  ptr->Write();
  f_out.Close();
  
  TFile f_in("test.out.root");
  TObject* object_in =
    f_in.FindObjectAny("I3Position");
  f_in.Close();
  ENSURE(object_in,"the read-in pointer is non-zero");
  
  I3Position* tested_in = dynamic_cast<I3Position*>(object_in);
  ENSURE(tested_in,"the read-in pointer is of the right type");
  
  I3PositionPtr ptr_in(tested_in);
  
  /** @todo should check the read-in data for I3Position here */

}

/**
 * check branching it to a tree
 */
TEST(branch)
{
  I3PositionPtr ptr(new I3Position());
  /** @todo add some setting of data here */
  
  I3Position* raw_ptr = &(*ptr);
  TTree tree("TestTree","Icecube");
  tree.Branch("branch","I3Position",&raw_ptr);
  
  tree.Fill();
  
  I3Position* raw_ptr_in = new I3Position();
  I3PositionPtr ptr_in (raw_ptr_in);
  
  tree.SetBranchAddress("branch",&raw_ptr_in);
  tree.GetEvent(0);
  
  /** @todo add some checking of the data of I3Position here */
  
}

/**
 * check branching object to a tree, writing the tree to disk,
 * and reading the tree back in, and finding the object in the tree.
 */
TEST(branch_and_write)
{
  I3PositionPtr ptr(new I3Position());
  /** @todo add some setting of data here */
  
  I3Position* raw_ptr = &(*ptr);
  TTree tree("TestTree","Icecube");
  tree.Branch("branch","I3Position",&raw_ptr);
  tree.Fill();
  
  TFile file_out("test.out.root","RECREATE");
  tree.Write();
  file_out.Close();
  
  
  TFile file_in("test.out.root");
  TTree* tree_in = (TTree*)file_in.FindObjectAny("TestTree");
  ENSURE(tree_in,"the test tree exists");
  
  I3Position* raw_ptr_in = new I3Position();
  I3PositionPtr ptr_in (raw_ptr_in);
  
  tree_in->SetBranchAddress("branch",&raw_ptr_in);
  tree_in->GetEvent(0);

  /** @todo add some checking of the data of I3Position here */
  
  delete tree_in;
}

/**
 * Make sure that the changing of coordinate systems works well
 */
TEST(coord_transforms)
{
  cout <<"Creating positions p(4,3,0) and q(0,0,0)..."<<endl;
  I3Position p(4,3,0);
  //I3PositionPtr q_ptr(new I3Position(1,2,3));
  I3Position q(1,2,3);
  cout <<"Setting position q to: 2,2,2 in car..."<<endl;
  q.SetPosition(2,2,2,I3Position::car);
  
  ENSURE_DISTANCE(p.GetX(),4.0,0.0001,"p.GetX failed");
  ENSURE_DISTANCE(p.GetY(),3.0,0.0001,"p.GetY failed");
  ENSURE_DISTANCE(p.GetZ(),0.0,0.0001,"p.GetZ failed");
  ENSURE_DISTANCE(p.GetR(),5.0,0.0001,"p.GetR failed");
  ENSURE_DISTANCE(p.GetTheta(),1.5708,0.0001,"p.GetTheta failed");
  ENSURE_DISTANCE(p.GetPhi(),0.6435,0.0001,"p.GetPhi failed");
  ENSURE_DISTANCE(p.GetRho(),5.0,0.0001,"p.GetRho failed");
  
  ENSURE_DISTANCE(q.GetX(),2.0,0.0001,"q.GetX failed");
  ENSURE_DISTANCE(q.GetY(),2.0,0.0001,"q.GetY failed");
  ENSURE_DISTANCE(q.GetZ(),2.0,0.0001,"q.GetZ failed");
  
  ENSURE_DISTANCE(p.CalcDistance(q),3.0,0.0001,"p.CalcDistance(q) failed");
  ENSURE_DISTANCE(q.CalcDistance(p),3.0,0.0001,"q.CalcDistance(p) failed");
  
  cout <<"Rotating p by Pi/4 around z-axis..."<<endl;
  p.RotateZ(3.141592/4);
  ENSURE_DISTANCE(p.GetX(),0.707108,0.0001,"p.GetX failed");
  ENSURE_DISTANCE(p.GetY(),4.94975,0.0001,"p.GetY failed");
  ENSURE_DISTANCE(p.GetZ(),0.0,0.0001,"p.GetZ failed");
  
  cout <<"Rotating p by Pi/2 around y-axis..."<<endl;
  p.RotateY(3.141592/2);
  ENSURE_DISTANCE(p.GetX(),0.0,0.0001,"p.GetX failed");
  ENSURE_DISTANCE(p.GetY(),4.94975,0.0001,"p.GetY failed");
  ENSURE_DISTANCE(p.GetZ(),-0.707108,0.0001,"p.GetZ failed");
  
  cout <<"Rotating p by Pi/2 around x-axis..."<<endl;
  p.RotateX(3.141592/2);
  ENSURE_DISTANCE(p.GetX(),0.0,0.0001,"p.GetX failed");
  ENSURE_DISTANCE(p.GetY(),0.707108,0.0001,"p.GetY failed");
  ENSURE_DISTANCE(p.GetZ(),4.94975,0.0001,"p.GetZ failed");
  
  cout <<"Creating position s and setting coordinates in sph..."<<endl;
  I3Position s;
  s.SetPosition(1.732050808,0.955316618,3.141592/4,I3Position::sph);
  ENSURE_DISTANCE(s.GetX(),1.0,0.0001,"s.GetX failed");
  ENSURE_DISTANCE(s.GetY(),1.0,0.0001,"s.GetY failed");
  ENSURE_DISTANCE(s.GetZ(),1.0,0.0001,"s.GetZ failed");
  
  cout <<"Creating position d and setting coordinates in car..."<<endl;
  I3Position d(1,1,1);
  ENSURE_DISTANCE(d.GetR(),1.73205,0.0001,"d.GetR failed");
  ENSURE_DISTANCE(d.GetTheta(),0.955317,0.0001,"d.GetTheta failed");
  ENSURE_DISTANCE(d.GetPhi(),0.785398,0.0001,"d.GetPhi failed");
  
  cout <<"Using the = operator on I3Position e=d..."<<endl;
  I3Position e = d;
  ENSURE_DISTANCE(e.GetR(),1.73205,0.0001,"e.GetR failed");
  ENSURE_DISTANCE(e.GetTheta(),0.955317,0.0001,"e.GetTheta failed");
  ENSURE_DISTANCE(e.GetPhi(),0.785398,0.0001,"e.GetPhi failed");
  
  cout <<"Creating position f from position d..."<<endl;
  I3Position f(d);
  ENSURE_DISTANCE(f.GetX(),1.0,0.0001,"f.GetX failed");
  ENSURE_DISTANCE(f.GetY(),1.0,0.0001,"f.GetY failed");
  ENSURE_DISTANCE(f.GetZ(),1.0,0.0001,"f.GetZ failed");
  
  cout <<"Shifting coordinate system of f by s..."<<endl;
  f.ShiftCoordSystem(s);
  ENSURE_DISTANCE(f.GetX(),0.0,0.0001,"shifted f.GetX failed");
  ENSURE_DISTANCE(f.GetY(),0.0,0.0001,"shifted f.GetY failed");
  ENSURE_DISTANCE(f.GetZ(),0.0,0.0001,"shifted f.GetZ failed");
  
  cout <<"Shifting coordinate system of f by p..."<<endl;
  f.ShiftCoordSystem(p);
  ENSURE_DISTANCE(f.GetX(),0.0,0.0001,"shifted f.GetX failed");
  ENSURE_DISTANCE(f.GetY(),-0.707108,0.0001,"shifted f.GetY failed");
  ENSURE_DISTANCE(f.GetZ(),-4.94975,0.0001,"shifted f.GetZ failed");
  ENSURE_DISTANCE(f.GetR(),5.0,0.0001,"shifted f.GetR failed");
  ENSURE_DISTANCE(f.GetTheta(),2.9997,0.0001,"shifted f.GetTheta failed");
  ENSURE_DISTANCE(f.GetPhi(),4.71239,0.0001,"shifted f.GetPhi failed");
  ENSURE_DISTANCE(f.GetRho(),0.707108,0.0001,"shifted f.GetRho failed");
  
}

