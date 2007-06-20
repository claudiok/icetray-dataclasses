#include <icetray/serialization.h>
#include <dataclasses/physics/I3DOMLaunch.h>
#include <dataclasses/physics/DeltaCompressor.h>
#include <stdexcept>

I3DOMLaunch::I3DOMLaunch() 
  : startTime_(0.0),
    trigger_(TEST_PATTERN),
    mode_(UNDEFINED),
    whichATWD_(ATWDa),
    localCoincidence_(false),
    pedestal_(false)
{
  rawATWD_.resize(4);
}


I3DOMLaunch::~I3DOMLaunch() {}


template <class Archive>
void I3DOMLaunch::save(Archive& ar, unsigned version) const
{
  if (version>i3domlaunch_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3DOMLaunch class.",version,i3domlaunch_version_);

  ar & make_nvp("StartTime", startTime_);
  // ignore the "Trigger" information of old data
  if(version < 1)
  {
    int tmp;
    ar & make_nvp("Trigger", tmp);
  }
  // for version > 0 there is a trigger type and mode to be serialized
  if(version > 0)
  {
    ar & make_nvp("TriggerType", trigger_);
    ar & make_nvp("TriggerSituation", mode_);
  }
  ar & make_nvp("WhichATWD", whichATWD_);
  
  // since version 3 of the file the raw waveforms are stored in delta
  // compressed form. This is only done, if archived to a non XML archive,
  // to allow to inspect the waveforms with dataio_shovel.
  if( ( version > 2 )
      && 
      ( typeid(ar) != typeid(boost::archive::xml_oarchive) ) )
  {
    
    try
    {
      I3DeltaCompression::DeltaCompressor compressor;
      vector< vector<unsigned int> > compressedATWD;
      
      I3Vector<I3Vector<int> >::const_iterator it;
      for( it = rawATWD_.begin(); it < rawATWD_.end(); it++ )
      {
        // reset the compressor and compresse the waveform
        compressor.reset();
        compressor.compress( *it );
        
        // copy the compressed ATWD waveform to the compressed vector and 
        // add the vector to the fector of compressed ATWD waveforms.
        const vector<unsigned int>& compVals = compressor.getCompressed();
        vector<unsigned int> compVector( compVals.begin(), compVals.end() );
        compressedATWD.push_back( compVector );
      }
      // serialize all compressed ATWD waveforms
      ar & make_nvp("CompressedATWD", compressedATWD);
      
      // also write the number of samples for each ATWD waveform to the archive
      // as the decompressed waveforms need to be truncated from extra values
      // which are appended as the algorithm doesn't allow for a end marker.
      for( it = rawATWD_.begin(); it < rawATWD_.end(); it++ )
      {
        int numSamples = static_cast<int>( (*it).size() );
        ar & make_nvp( "NumSamplesATWD", numSamples );
      }
      
      // reset the compressor and compresse the waveform
      compressor.reset();
      compressor.compress( rawFADC_ );
      
      // copy the compressed waveform to the output vector and serialize this 
      // vector with the compressed FADC waveform.
      const vector<unsigned int>& compVals = compressor.getCompressed();
      vector<unsigned int> compressedFADC( compVals.begin(), compVals.end() );
      ar & make_nvp("CompressedFADC", compressedFADC );
      
      // also write the number of samples for this waveform to the archive
      // as the decompressed waveform needs to be truncated from extra values
      // which are appended as the algorithm doesn't allow for a end marker.
      int numSamples =  rawFADC_.size();
      ar & make_nvp("NumSamplesFADC", numSamples );
    }
    catch( const std::domain_error& ex )
    {
        log_fatal( ex.what() );
    }
  }
  else
  {
    ar & make_nvp("RawATWD", rawATWD_);
    ar & make_nvp("RawFADC", rawFADC_);
  }
  ar & make_nvp("LocalCoincidence", localCoincidence_);
  ar & make_nvp("RawChargeStamp", rawChargeStamp_);
  // Putting Pedestal into DOMLaunch for delta compressed data
  if(version > 2)
    {
      ar & make_nvp("Pedestal", pedestal_);
    }

  // ignore the range for the raw charge stamp of old data
  if(version < 2)
  {
    bool tmp;
    ar & make_nvp("ChargeStampRange", tmp);
  }
  // for version > 1 there is an index to be serialized,
  // addressing the highest sample of the charge stamp
  if(version > 1)
  {
    ar & make_nvp("ChargeStampHighestSample", chargeStampHighestSample_);    
  }
}

template <class Archive>
void I3DOMLaunch::load(Archive& ar, unsigned version)
{
  ar & make_nvp("StartTime", startTime_);
  // ignore the "Trigger" information of old data
  if(version < 1)
  {
    int tmp;
    ar & make_nvp("Trigger", tmp);
  }
  // for version > 0 there is a trigger type and mode to be serialized
  if(version > 0)
  {
    ar & make_nvp("TriggerType", trigger_);
    ar & make_nvp("TriggerSituation", mode_);
  }
  // for version <= 0 there is no trigger type and mode available
  // use default values instead
  else
  {
    trigger_ = TEST_PATTERN;
    mode_ = UNDEFINED;
  }
  ar & make_nvp("WhichATWD", whichATWD_);
 
  // since version 3 of the file the raw waveforms are stored in delta
  // compressed form. This is only done, if archived to a non XML archive,
  // to allow to inspect the waveforms with dataio_shovel.
  if( ( version > 2 )
      && 
      ( typeid(ar) != typeid(boost::archive::xml_iarchive) ) )
  {
    try
    {
      I3DeltaCompression::DeltaCompressor compressor;
      
      // Create the data structure for the compressed version 
      // of the waveforms and deserialize fro the archive
      vector< vector<unsigned int> > compressedATWD( rawATWD_.size() );
      ar & make_nvp("CompressedATWD", compressedATWD);
      
      vector< vector<unsigned int> >::const_iterator it;
      I3Vector<I3VectorInt >::iterator it2 = rawATWD_.begin();
      for( it = compressedATWD.begin(); it < compressedATWD.end(); it++, it2++ )
      {
        // reset compressor and initialize with the compressed data.
        compressor.reset();
        compressor.setCompressed( *it );
        
        // clear the rawATWD_ waveform and fill it with the decompressed values.
        (*it2).clear();
        compressor.decompress( dynamic_cast< vector<int>& >(*it2) );
        
        // get the number of real samples of the waveform and truncate any
        // extra values from the vector.
        int numSamples;
        ar & make_nvp( "NumSamplesATWD", numSamples );
        (*it2).resize( numSamples );
      }
      
      vector<unsigned int> compressedFADC;
      ar & make_nvp("CompressedFADC", compressedFADC);

      // reset compressor and initialize with the compressed data.
      compressor.reset();
      compressor.setCompressed( compressedFADC );
      
      // clear the rawFADC_ waveform and fill it with the decompressed values.
      rawFADC_.clear();
      compressor.decompress( rawFADC_ );
      
      // get the number of real samples of the waveform and truncate any
      // extra values from the vector.
      int numFADCSamples;
      ar & make_nvp("NumSamplesFADC", numFADCSamples);
      rawFADC_.resize(numFADCSamples);
    }
    catch( const std::domain_error& ex )
    {
        log_fatal( ex.what() );
    }
  }
  else
  {
    ar & make_nvp("RawATWD", rawATWD_);
    ar & make_nvp("RawFADC", rawFADC_);
  }
  ar & make_nvp("LocalCoincidence", localCoincidence_);
  ar & make_nvp("RawChargeStamp", rawChargeStamp_);
  if(version > 2)
    {
      ar & make_nvp("Pedestal", pedestal_);
    }
  // ignore the range for the raw charge stamp of old data
  if(version < 2)
  {
    bool tmp;
    ar & make_nvp("ChargeStampRange", tmp);
  }
  // for version > 1 there is an index to be serialized,
  // addressing the highest sample of the charge stamp
  if(version > 1)
  {
    ar & make_nvp("ChargeStampHighestSample", chargeStampHighestSample_);    
  }
  // for version <= 1 there is no index available
  // use a value of 0 instead - should be fine since rawChargeStamp_ is empty
  else
  {
    if(!rawChargeStamp_.empty()) log_warn("oops, coarse charge stamp is not empty");
    chargeStampHighestSample_ = 0u;
  }
}

I3_SERIALIZABLE(I3DOMLaunch);

I3_SERIALIZABLE(I3DOMLaunchSeriesMap);
