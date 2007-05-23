/**
 * copyright  (C) 2007
 * the icecube collaboration
 *
 * Test cases to test the compression of ATWD and FADC waveforms
 *
 * @file    $File$
 * @version $Revision$
 * @date    $Date$
 * @author  Martin Merck
 */
#include <I3Test.h>
#include <dataclasses/physics/I3DOMLaunch.h>
#include <icetray/serialization.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib> 
#include <limits> 
//#include <boost/archive/binary_oarchive.hpp>
//#include <boost/archive/binary_iarchive.hpp>

TEST_GROUP(I3DOMLaunch)

//using boost::serialization::make_nvp;
//using boost::serialization::base_object;

TEST(serializeStandardWave)
{
	I3DOMLaunch wave;
  I3Vector<int>& atwd0 = wave.GetRawATWD(0);
  I3Vector<int>& atwd1 = wave.GetRawATWD(1);
  I3Vector<int>& atwd2 = wave.GetRawATWD(2);
  I3Vector<int>& fadc = wave.GetRawFADC();
  
  for( int i=0; i< 128; i++) 
  {
    atwd0.push_back( 3 );               // a constant waveform
    atwd1.push_back( i%2 * 1023);       // a waveform oszilating between 0 and 1023
    atwd2.push_back( 511 - i%2 * 1023); // a waveform oszilating between -512 and 511
  }
  
  for( int i=0; i< 256; i++) 
  {
    fadc.push_back( 143 + rand() % 10 );  // a waveform with a baseline of 143 and random noise
	}
	
  // Build a binary stringtream and serialize the I3DOMLaunch
	std::ostringstream oss(std::ostringstream::binary);
	{
		boost::archive::portable_binary_oarchive outAr( oss );
		outAr & make_nvp("Test", wave);;
	}
  
  // Deserialize a second I3DOMLaunch from the serialized stream for comparison
	I3DOMLaunch wave2;
	std::istringstream iss( oss.str(), std::istringstream::binary );
	{
		boost::archive::portable_binary_iarchive inAr( iss );
		inAr & make_nvp("Test", wave2);
	}

  // Compare size and content of waveform and ensure that they are equal.
  ENSURE_EQUAL( wave.GetRawATWD(0).size(), wave2.GetRawATWD(0).size(), 
                "size of constant waveforms don't agree" ); 
  
  ENSURE( std::equal( wave.GetRawATWD(0).begin(), wave.GetRawATWD(0).end(), wave2.GetRawATWD(0).begin() ),
          "constant waveforms don't agree" );
  
  ENSURE_EQUAL( wave.GetRawATWD(1).size(), wave2.GetRawATWD(1).size(), 
                "size of unsigned oscillating waveforms don't agree" ); 
  ENSURE( std::equal( wave.GetRawATWD(1).begin(), wave.GetRawATWD(1).end(), wave2.GetRawATWD(1).begin() ),
          "unsigned oscillating waveforms don't agree" );
  
  ENSURE_EQUAL( wave.GetRawATWD(2).size(), wave2.GetRawATWD(2).size(), 
                "size of signed oscillating waveforms don't agree" ); 
  ENSURE( std::equal( wave.GetRawATWD(2).begin(), wave.GetRawATWD(2).end(), wave2.GetRawATWD(2).begin() ),
          "signed oscillating waveforms don't agree" );
  

  ENSURE_EQUAL( wave.GetRawATWD(3).size(), wave2.GetRawATWD(3).size(), 
                "size of empty waveforms don't agree" ); 
  ENSURE( std::equal( wave.GetRawATWD(3).begin(), wave.GetRawATWD(3).end(), wave2.GetRawATWD(0).begin() ),
          "empty waveforms don't agree" );

  ENSURE_EQUAL( wave.GetRawFADC().size(), wave2.GetRawFADC().size(), 
                "size of noisy waveforms don't agree" ); 
  ENSURE( std::equal( wave.GetRawFADC().begin(), wave.GetRawFADC().end(), wave2.GetRawFADC().begin() ),
          "noisy waveforms don't agree" );
  	
}

TEST(serializeMaxIntegerWave)
{
	I3DOMLaunch wave;
  I3Vector<int>& atwd0 = wave.GetRawATWD(0);
  
  for( int i=0; i< 128; i++) 
  {
    if( i%2 == 0 )
      atwd0.push_back( 0 );       
    else
      atwd0.push_back( std::numeric_limits<int>::max() );       
   }
  
  try
  {
    // Build a binary stringtream and serialize the I3DOMLaunch
    std::ostringstream oss(std::ostringstream::binary);
    {
      boost::archive::portable_binary_oarchive outAr( oss );
      outAr & make_nvp("Test", wave);;
    }
    
    // Deserialize a second I3DOMLaunch from the serialized stream for comparison
    I3DOMLaunch wave2;
    std::istringstream iss( oss.str(), std::istringstream::binary );
    {
      boost::archive::portable_binary_iarchive inAr( iss );
      inAr & make_nvp("Test", wave2);
    }
  }
  catch( const std::runtime_error& error )
  {
    
  }
}
