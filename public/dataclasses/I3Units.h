/**
 @brief A ripped Geant4 header declaring unit conventions

 Modified 2-17-04 by John Pretz from a Geant4 header
 $Id: I3Units.h,v 1.14 2004/11/03 20:17:16 pretz Exp $
 
 @file I3Units.h  
 @version $Version:$
 @date $Date: 2004/11/03 20:17:16 $
 @author Geant4 Team (original) M.Maire, S.Giani
 @author pretz (IceCube modifications)
 
 Changes (c) 2004 IceCube Collaboration
 
 I just wrapped it all in a namespace I3Units
 
 Also removed  #include <CLHEP/config/CLHEP.h>
 since it wasn't needed.
 
 Also had to monkey around with the #define pascal hep_pascal because
 rootcint didn't like it.  That's all my changes.  Otherwise, it comes
 direct from Geant4
 
 Also changed it to use ROOT types, Double_t rather than Double_t, for
 example
 
 Also monkied around with the comments, so it'd document in doxygen

 Also changed the definition of Energy, so that GeV is the base units, rather
 than Joules

 Also removed everything but Time, Energy, Length, Angle, Areas and Volumes.
 Pressure, Power, stuff like that is not done, since the redefinition of
 GeV = 1.0 messes with all that.
 
 Here's the original Geant4 header:
 
<b>
 DISCLAIMER                                                       
 
 The following disclaimer summarizes all the specific disclaimers 
 of contributors to this software. The specific disclaimers,which 
 govern, are listed with their locations in:                      
 http://cern.ch/geant4/license                                  
 
 Neither the authors of this software system, nor their employing 
 institutes,nor the agencies providing financial support for this 
 work  make  any representation or  warranty, express or implied, 
 regarding  this  software system or assume any liability for its 
 use.                                                             
 
 This  code  implementation is the  intellectual property  of the 
 GEANT4 collaboration.                                            
 By copying,  distributing  or modifying the Program (or any work 
 based  on  the Program)  you indicate  your  acceptance of  this 
 statement, and all its terms.                                    
</b>
*/

#ifndef G4UNITSTEST_HH
#define G4UNITSTEST_HH

//#include <CLHEP/config/CLHEP.h>

/**
 * @namespace I3Units
 * @brief Unit definitions for the dataclasses
 *
 * The I3Units namespace contains a bunch of "static const Double_t's" which
 * define the units that are used in the dataclasses.  The header originally
 * comes from Geant4, and wrapping it in and I3Units namespace is an IceCube
 * modification.
 * 
 * The basic units are those of the International System:<br>
 *                                                       <br>
 *  		meter                                    <br>            
 * 		second                                   <br>
 * 		kilogram                                 <br>   
 * 		ampere                                   <br>
 * 		degree kelvin                            <br>
 *              the amount of substance (mole)           <br>
 *              luminous intensity      (candela)        <br>
 * 		radian                                   <br>
 *              steradian                                <br>
 *<br>
 *
 * The SI numerical value of the positron charge is defined here,
 * as it is needed for conversion factor : positron charge = e_SI (coulomb)
 * 
 * @version $Version:$
 * @date $Date: 2004/11/03 20:17:16 $
 * @author Geant4 Team (original) M.Maire, S.Giani
 * @author pretz (IceCube modifications)
 * @todo Should we have a 'speed' here too?
 * @todo add 'ergs'
 */
namespace I3Units
{
  /**
   * meter
   */
  static const Double_t meter  = 1.;
  
  /**
   * square meter
   */
  static const Double_t meter2 = meter*meter;

  /**
   * cubic meter
   */
  static const Double_t meter3 = meter*meter*meter;
  
  /**
   * millimeter
   */ 
  static const Double_t millimeter  = 0.001*meter;

  /**
   * square millimeter
   */
  static const Double_t millimeter2 = millimeter*millimeter;

  /**
   * cubic millimeter
   */
  static const Double_t millimeter3 = millimeter*millimeter*millimeter;
  
  /**
   * centimeter
   */
  static const Double_t centimeter  = 10.*millimeter;   

  /**
   * square centimeter
   */
  static const Double_t centimeter2 = centimeter*centimeter;

  /**
   * cubic centimeter
   */
  static const Double_t centimeter3 = centimeter*centimeter*centimeter;
  
  /**
   * kilometer
   */
  static const Double_t kilometer = 1000.*meter;                   

  /**
   * square kilometer
   */
  static const Double_t kilometer2 = kilometer*kilometer;

  /**
   * cubic kilometer
   */
  static const Double_t kilometer3 = kilometer*kilometer*kilometer;
  
  /**
   * parsec
   */
  static const Double_t parsec = 3.0856775807e+16*meter;
  
  /**
   * micrometer
   */
  static const Double_t micrometer = 1.e-6 *meter;             

  /**
   * nanometer
   */
  static const Double_t  nanometer = 1.e-9 *meter;

  /**
   * angstrom
   */
  static const Double_t  angstrom  = 1.e-10*meter;

  /**
   * fermi
   */
  static const Double_t fermi     = 1.e-15*meter;
  
  /**
   * barn
   */
  static const Double_t barn = 1.e-28*meter2;

  /**
   * millibarn
   */
  static const Double_t millibarn = 1.e-3 *barn;

  /**
   * microbarn
   */
  static const Double_t microbarn = 1.e-6 *barn;

  /**
   * nanobarn
   */
  static const Double_t nanobarn = 1.e-9 *barn;

  /**
   * picobarn
   */
  static const Double_t picobarn = 1.e-12*barn;
  
  /**
   * feet
   */
  static const Double_t feet = 0.3048*meter;
  
  // symbols
  /**
   * millimeter
   */
  static const Double_t mm  = millimeter;                        

  /**
   * square millimeter
   */
  static const Double_t mm2 = millimeter2;

  /**
   * cubic millimeter
   */
  static const Double_t mm3 = millimeter3;
  
  /**
   * centimeter
   */
  static const Double_t cm  = centimeter;   

  /**
   * square centimeter
   */
  static const Double_t cm2 = centimeter2;

  /**
   * cubic centimeter
   */
  static const Double_t cm3 = centimeter3;
  
  /**
   * meter
   */
  static const Double_t m  = meter;                  

  /**
   * square meter
   */
  static const Double_t m2 = meter2;

  /**
   * cubic meter
   */
  static const Double_t m3 = meter3;
  
  /**
   * kilometer
   */
  static const Double_t km  = kilometer;                   

  /**
   * square kilometer
   */
  static const Double_t km2 = kilometer2;

  /**
   * cubic kilometer
   */
  static const Double_t km3 = kilometer3;
  
  /**
   * parsec
   */
  static const Double_t pc = parsec;
  
  /**
   * feet
   */
  static const Double_t ft = feet;
  
  //
  // Angle
  //
  /**
   * radian
   */
  static const Double_t radian      = 1.;                  
  
  /**
   * milliradian
   */
  static const Double_t milliradian = 1.e-3*radian;

  /**
   * degree
   */
  static const Double_t degree = (3.14159265358979323846/180.0)*radian;
  
  /**
   * steradian
   */
  static const Double_t   steradian = 1.;
  
  // symbols
  /**
   * radian
   */
  static const Double_t rad  = radian;	

  /**
   * milliradian
   */
  static const Double_t mrad = milliradian;

  /**
   * steradian
   */
  static const Double_t sr   = steradian;

  /**
   * degree
   */
  static const Double_t deg  = degree;
  
  //
  // Time [T]
  //
  /**
   * second
   */
  static const Double_t second      = 1.e9;

  /**
   * nanosecond
   */
  static const Double_t nanosecond  = 1.e-9 *second;

  /**
   * millisecond
   */ 
  static const Double_t millisecond = 1.e-3 *second;

  /**
   * microsecond
   */
  static const Double_t microsecond = 1.e-6 *second;

  /**
   * picosecond
   */
  static const Double_t  picosecond = 1.e-12*second;
  
  /**
   * hertz
   */
  static const Double_t hertz = 1./second;

  /**
   * kilohertz
   */
  static const Double_t kilohertz = 1.e+3*hertz;

  /**
   * megahertz
   */
  static const Double_t megahertz = 1.e+6*hertz;
  
  // symbols
  /**
   * nanosecond
   */
  static const Double_t ns = nanosecond;			

  /**
   * second
   */
  static const Double_t  s = second;

  /**
   * millisecond
   */
  static const Double_t ms = millisecond;
  
  //
  // Energy [E]
  //
  /**
   * joule
   */
  //  static const Double_t joule = kg*m*m/(s*s);
  
  /**
   * eV
   */
  static const Double_t     electronvolt = 1.0e-9;

  /**
   * keV
   */
  static const Double_t kiloelectronvolt = 1.e+3*electronvolt;

  /**
   * MeV
   */
  static const Double_t megaelectronvolt = 1.e+6*electronvolt; 

  /**
   * GeV
   */
  static const Double_t gigaelectronvolt = 1.e+9*electronvolt;

  /**
   * TeV
   */
  static const Double_t teraelectronvolt = 1.e+12*electronvolt;

  /**
   * PeV
   */
  static const Double_t petaelectronvolt = 1.e+15*electronvolt;
  
  // symbols
  /**
   * MeV
   */
  static const Double_t MeV = megaelectronvolt;

  /**
   * eV
   */
  static const Double_t  eV = electronvolt;

  /**
   * keV
   */
  static const Double_t keV = kiloelectronvolt;

  /**
   * GeV
   */
  static const Double_t GeV = gigaelectronvolt;

  /**
   * TeV
   */
  static const Double_t TeV = teraelectronvolt;

  /**
   * PeV
   */
  static const Double_t PeV = petaelectronvolt;
  
  //
  // Miscellaneous
  //
  /**
   * percent
   */
  static const Double_t perCent     = 0.01 ;

  /**
   * perThousand
   */
  static const Double_t perThousand = 0.001;

  /**
   * perMillion
   */
  static const Double_t perMillion  = 0.000001;
  
};
#endif /* G4UNITSTEST_HH */
