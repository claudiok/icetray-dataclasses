/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

// $Id: I3Position.cxx,v 1.1 2004/06/09 21:56:34 dule Exp $

///////////////////////////////////////////////////////////////////////////
// Class I3Position
// Handling of positions in various reference frames.
//
// This class is meant to serve as a base class for ICECUBE objects
// that have a unique position in 3-dimensional space.
//
// Note :
// ------
// Positions (r) and reference frames (f) are specified via
//
//    SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame f)
//
// under the following conventions :
//
// f=car ==> r in Cartesian coordinates   (x,y,z)
// f=sph ==> r in Spherical coordinates   (r,theta,phi)
// f=cyl ==> r in Cylindrical coordinates (rho,phi,z)
//
// All angles are in radians.
//
// Example :
// ---------
//
// I3Position q;
// q.SetPosition(-1,25,7,car);
// q.GetPosition(r,theta,phi,sph);
//
//***********************************************************
//-- Created: Dusan Turcan UMD 26-05-2004
//   Taken from: Nick van Eijndhoven 06-feb-1999 UU-SAP Utrecht
//***********************************************************
///////////////////////////////////////////////////////////////////////////

#include <iostream>
//#include "geom/I3Position.h"
#include "dataclasses/I3Position.h"
 
ClassImp(I3Position) // Class implementation to enable ROOT I/O

//-----------------------------------------------------------
I3Position::I3Position()
{
// Creation of an I3Position object and initialization of parameters
// If no initial argument is given, do the default vector thing...
  ResetPosition();
// The unit scale for position coordinates is initialised to cm.
  fScale=1;
}

//-----------------------------------------------------------
I3Position::I3Position(Double_t x, Double_t y, Double_t z)
  : TVector3(x,y,z)
{
// Creation of an I3Position object and initialization of parameters
  CalcSphCylFromCar();
// The unit scale for position coordinates is initialised to m.
  fScale=1;
}

//-----------------------------------------------------------
I3Position::~I3Position()
{
// Destructor to delete dynamically allocated memory
}

//-----------------------------------------------------------
// ????
I3Position::I3Position(const I3Position& p) : TVector3(p)
{
// Copy constructor
  CalcSphCylFromCar();
  fScale=p.fScale;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::SetPosition(Double_t r1, Double_t r2, Double_t r3, RefFrame frame)
{
// Store position according to reference frame f
//  SetValues(r,f);
// All errors will be reset to 0
//   fDx=0;
//   fDy=0;
//   fDz=0;
//   fDresult=0;

//   Int_t frame=0;
//   if (f == "car") frame=1;
//   if (f == "sph") frame=2;
//   if (f == "cyl") frame=3;

  switch (frame) {
    //  case 1: // Input given in Cartesian coordinates
  case car: // Input given in Cartesian coordinates
    SetX(r1);
    SetY(r2);
    SetZ(r3);
    CalcSphCylFromCar(); // Calculate the other coordinates
//     cout <<"SetPosition: Calculating SPH and CYL from CAR..."<<endl;
    break;
      
    //  case 2: // Input given in Spherical coordinates
  case sph: // Input given in Spherical coordinates
    fR=r1;
    fTheta=r2;
    fPhi=r3;
    CalcCarCylFromSph(); // Calculate the other coordinates
//     cout <<"SetPosition: Calculating CAR and CYL from SPH..."<<endl;
    break;

    //  case 3: // Input given in Cylindrical coordinates
  case cyl: // Input given in Cylindrical coordinates
    fRho=r1;
    fPhi=r2;
    SetZ(r3);
    CalcCarSphFromCyl(); // Calculate the other coordinates
//     cout <<"SetPosition: Calculating CAR and SPH from CYL..."<<endl;
    break;
    
  default: // Unsupported reference frame
    cout << "*I3Position::SetPosition* Unsupported frame: " <<frame<<endl
	 << " Possible frames are 'car', 'sph' and 'cyl'." <<endl; 
    ResetPosition();
    break;
  }
}

//-----------------------------------------------------------
void I3Position::GetPosition(Double_t& r1, Double_t& r2, Double_t& r3, RefFrame frame)
{
// Provide position according to reference frame f
//  GetValues(r,f);

//   Int_t frame=0;
//   if (f == "car") frame=1;
//   if (f == "sph") frame=2;
//   if (f == "cyl") frame=3;

  if (!IsCalculated) {
    CalcSphCylFromCar();
//     cout <<"GetPosition: Calculating SPH and CYL from CAR..."<<endl;
  }

  switch (frame) {
    //  case 1: // Output wanted in Cartesian coordinates
  case car: // Output wanted in Cartesian coordinates
    r1=X();
    r2=Y();
    r3=Z();
    break;
    
    //  case 2: // Output wanted in Spherical coordinates
  case sph: // Output wanted in Spherical coordinates
    r1=fR;
    r2=fTheta;
    r3=fPhi;
    break;

    //  case 3: // Output wanted in Cylindrical coordinates
  case cyl: // Output wanted in Cylindrical coordinates
    r1=fRho;
    r2=fPhi;
    r3=Z();
    break;

  default: // Unsupported reference frame
    cout << "*I3Position::GetPosition* Unsupported frame : " << frame<<endl
	 << " Possible frames are 'car', 'sph' and 'cyl'." << endl; 
    r1=0;
    r2=0;
    r3=0;
    break;
  }
}

//-----------------------------------------------------------
void I3Position::ResetPosition()
{
// Set or Reset the position to 0.
  SetXYZ(0,0,0);
  fR=0;
  fTheta=0;
  fPhi=0;
  fRho=0;
  IsCalculated=kFALSE;
}

//-----------------------------------------------------------
void I3Position::SavePosition(Double_t& x, Double_t& y, Double_t& z)
{
// Return x,y,z only for saving to disk
  x=X();
  y=Y();
  z=Z();
}

//-----------------------------------------------------------
void I3Position::SetPosition(TVector3& p)
{
// Set position
  SetPosition(p.X(), p.Y(), p.Z(), car);
}

//-----------------------------------------------------------
I3Position& I3Position::GetPosition()
{
// Provide position
  return (*this);
}
//-----------------------------------------------------------

//-----------------------------------------------------------
Double_t I3Position::CalcDistance(const I3Position& p) const
{
// Provide distance of the current I3Position to position p.
// The error on the result can be obtained as usual by invoking
// GetResultError() afterwards. 
//
// In the case of two positions with different unit scales, the distance
// will be provided in the unit scale of the current I3Position.
// This implies that in such cases the results of r.GetDistance(q) and
// q.GetDistance(r) will be numerically different.
// As such it is possible to obtain a correctly computed distance between
// positions which have different unit scales.
// However, it is recommended to work always with one single unit scale.
//
  TVector3 d = p;
  Float_t pscale=p.GetUnitScale();
  if ((pscale/fScale > 1.1) || (fScale/pscale > 1.1)) d=d*(pscale/fScale);
  TVector3 q = (*this);
  d=d-q;
  Double_t dist=d.Mag();
  //  fDresult=d.GetResultError();
  return dist;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::SetUnitScale(Float_t s)
{
// Set the unit scale for the position coordinates.
// The scale is normalised w.r.t. the meter, so setting the unit scale
// to 0.01 means that all position coordinates are in cm.
// By default the unit scale is set to cm in the I3Position constructor.
// It is recommended to use one single unit scale throughout a complete
// analysis and/or simulation project.
//
// Note : This memberfunction does not modify the numerical values of
//        the position coordinates.
//        It only specifies their numerical meaning.
// 
  if (s>0.) {
    fScale=s;
  } else {
    cout << " *I3Position::SetUnitScale* Invalid argument s = " << s << endl;
  }
}

//-----------------------------------------------------------
Float_t I3Position::GetUnitScale() const
{
// Provide the unit scale for the position coordinates.
// The scale is normalised w.r.t. the meter, so a unit scale of 0.01
// means that all position coordinates are in cm.
  return fScale;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::SetPositionErr(Double_t r1, Double_t r2, Double_t r3, RefFrame f)
{
// Store position errors according to reference frame f
//  SetErrors(r,f);
}

//-----------------------------------------------------------
void I3Position::GetPositionErr(Double_t& r1, Double_t& r2, Double_t& r3, RefFrame f)
{
// Provide position errors according to reference frame f
//  GetErrors(r,f);
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::CalcSphCylFromCar()
{
  // Calculate Spherical and Cylindrical coordinates from Cartesian
  // Position is stored on disk in Cartesian coordinates only
  fR=sqrt(X()*X()+Y()*Y()+Z()*Z());
  fTheta=0;
  if (fR && fabs(Z()/fR)<=1.) {
    fTheta=acos(Z()/fR);
  } else {
    if (Z()<0.) fTheta=pi();
  }
  if (fTheta<0.) fTheta+=2.*pi();
  fPhi=0;
  if (X() || Y()) fPhi=atan2(Y(),X());
  if (fPhi<0.) fPhi+=2.*pi();
  fRho=fR*sin(fTheta);
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Position::CalcCarCylFromSph()
{
  // Calculate Cartesian and Cylindrical coordinates from Spherical
  fRho=fR*sin(fTheta);
  SetX(fRho*cos(fPhi));
  SetY(fRho*sin(fPhi));
  SetZ(fR*cos(fTheta));
  IsCalculated=kTRUE;
}

//-----------------------------------------------------------
void I3Position::CalcCarSphFromCyl()
{
  // Calculate Cartesian and Spherical coordinates from Cylindrical
  Double_t z=Z();
  fR=sqrt(fRho*fRho+z*z);
  if (fPhi<0.) fPhi+=2.*pi();
  fTheta=0;
  if (fR && fabs(z/fR)<=1.) {
    fTheta=acos(z/fR);
  } else {
    if (z<0.) fTheta=pi();
  }
  if (fTheta<0.) fTheta+=2.*pi();
  SetX(fRho*cos(fPhi));
  SetY(fRho*sin(fPhi));
  IsCalculated=kTRUE;
}
//-----------------------------------------------------------

//-----------------------------------------------------------
void I3Position::Translate(const I3Position& p)
{
  SetXYZ(X()-p.X(), Y()-p.Y(), Z()-p.Z());
}

//-----------------------------------------------------------
void I3Position::PrintPosition()
{
  cout <<"---------------------POSITION-INFO-----------------------"<<endl;
  cout <<"CAR coord (x,y,z): "<< X()<<" "<<Y()<<" "<<Z()<<endl;
  cout <<"SPH coord (r,theta,phi): "<< R()<<" "<<Theta()<<" "<<Phi()<<endl;
  cout <<"CYL coord (rho,phi,z): "<< Rho()<<" "<<Phi()<<" "<<Z()<<endl;
  cout <<"---------------------------------------------------------"<<endl;
}
//-----------------------------------------------------------
