/**
 * copyright  (C) 2007
 * the icecube collaboration
 *
 * Test Delta Compressions ability to encode and decode 
 *
 * @file    $File$
 * @version $Revision$
 * @date    $Date$
 * @author  Martin Merck
 */
#include <I3Test.h>
#include <dataclasses/physics/I3DOMLaunch.h>
#include <icetray/serialization.h>
#include <../private/dataclasses/physics/DeltaCompressor.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib> 
#include <limits> 

TEST_GROUP(DeltaCompressionTest)


TEST(RandomWaveTest)
{

  for (int trial=0; trial < 1000 ;trial++)
    {

      int waveform_constant=RAND_MAX/128;

      vector<int> orig_waveform(128,0);
      
      for (int i=0;i < 128; i++)
	{
	  orig_waveform[i]=rand()/waveform_constant;
	}

      I3DeltaCompression::DeltaCompressor compressor;
      compressor.reset();
      compressor.compress(orig_waveform);
      const vector<unsigned int>& compressed_waveform = compressor.getCompressed();

      I3DeltaCompression::DeltaCompressor uncompressor;
      uncompressor.reset();
      uncompressor.setCompressed( compressed_waveform );
      vector<int> new_waveform;
      new_waveform.clear();
      uncompressor.decompress( new_waveform );

      ENSURE(orig_waveform==new_waveform);
    }

}

