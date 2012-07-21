/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3TriggerStatus.cxx 13154 2005-12-01 21:45:55Z  $
 *
 * @file I3TriggerStatus.cxx
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
 */
#include <icetray/serialization.h>
#include <dataclasses/status/I3TriggerStatus.h>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/find.hpp>

template <typename T>
void I3TriggerStatus::SetTriggerConfigValue(const std::string& key, T value){
  std::stringstream sstr;
  sstr<<value;
  settings_[key] = sstr.str();
}

template <typename T>
void I3TriggerStatus::SetTriggerConfigValue(const char* key, T value){
  std::string key_str(key);
  SetTriggerConfigValue(key_str,value);
}

// want explicit instantiations for int, float, and string and const char*
template void I3TriggerStatus::SetTriggerConfigValue(const std::string&,int);
template void I3TriggerStatus::SetTriggerConfigValue(const std::string&,float);
template void I3TriggerStatus::SetTriggerConfigValue(const std::string&,std::string);
template void I3TriggerStatus::SetTriggerConfigValue(const std::string&,const char*);

template void I3TriggerStatus::SetTriggerConfigValue(const char*,int);
template void I3TriggerStatus::SetTriggerConfigValue(const char*,float);
template void I3TriggerStatus::SetTriggerConfigValue(const char*,std::string);
template void I3TriggerStatus::SetTriggerConfigValue(const char*,const char*);

// gets the value by string and converts to an integer
// sets 'value' to INT_MIN on failure
void I3TriggerStatus::GetTriggerConfigValue(const std::string& key, int& value) const {
  value = INT_MIN;
  if( settings_.find(key) != settings_.end() ){
    std::string str_value( settings_.find(key)->second );
    if( boost::algorithm::all( str_value, boost::algorithm::is_digit()
			       || boost::algorithm::is_any_of("+-") )){
      // it's an integer
      value = atoi( str_value.c_str() );
    }else{
      log_error("not clear how to convert '%s' to an int.", str_value.c_str());	     
    }
  }
}

bool WellFormedFloat(const char* str_value){
  std::string s(str_value);
  return WellFormedFloat(s);
}

bool WellFormedFloat(std::string& str_value){
  // just convert to lower case right off the bat
  boost::algorithm::to_lower( str_value );

  // make some very basic checks first that there aren't
  // more than two decimal points, only one exponent ('e')
  // and not more than two signs.
  if( boost::algorithm::all( str_value, boost::algorithm::is_digit() 
			     || boost::algorithm::is_any_of(".+-e"))
      && std::count(str_value.begin(), str_value.end(), '.') <= 2 
      && std::count(str_value.begin(), str_value.end(), 'e') <= 1 
      && std::count(str_value.begin(), str_value.end(), '+') <= 2
      && std::count(str_value.begin(), str_value.end(), '-') <= 2 ){
    // let's add some more checks
    // s = sign
    // d = is an integer
    // . is literally a period ('.')
    // so we're looking for numbers of the two following forms:
    //   sd.d (e.g. "+10.4") 
    //   sd.desd.d (e.g. "-10.4e-9.1")

    // split the number between the mantissa and the exponent
    // the same exact checks can be applied to both
    std::vector<std::string> float_vector;
    boost::algorithm::split( float_vector, str_value, boost::algorithm::is_any_of("e") );
    //  at this point this vector size should be either 1 or 2
    //    [sd.d]
    //    [sd.d,sd.d]
    if( float_vector.size() != 1 && float_vector.size() != 2 )
      return false;

    // test the mantissa and exponent and make sure they're
    // well formed ( i.e. of the form "sd.d" )
    for( std::vector<std::string>::iterator iter = float_vector.begin();
	 iter != float_vector.end(); ++iter){

      // can't allow things like 'e-1.0' or '-1.0e'
      if(iter->size() == 0 ) return false;

      // trim off the leading sign
      // first make sure it starts with a "+" or "-"
      // then check that the next character is a digit (0-9) or a decimal point
      // if it's a sign just trim it off.  we don't need it.
      if( (boost::algorithm::starts_with(*iter,"+") && 
	   (iter->size() > 1 && std::isdigit( (*iter)[1] ) || (*iter)[1] == '.' ))
	  || (boost::algorithm::starts_with(*iter,"-") && 
	      (iter->size() > 1 && std::isdigit( (*iter)[1] ) || (*iter)[1] == '.' )))
	boost::algorithm::trim_left_if( *iter, boost::algorithm::is_any_of("+-") );
      
      // should be d.d now
      // split and check that each character sequence on either side of
      // the decimal point is an integer
      std::vector<std::string> num_vector;
      boost::algorithm::split( num_vector, *iter, boost::algorithm::is_any_of(".") );
      for( std::vector<std::string>::iterator num_v_iter = num_vector.begin();
	   num_v_iter != num_vector.end(); ++num_v_iter){
	// if there's anything other than a digit (0-9) this is not well formed
	if( !boost::algorithm::all( *num_v_iter, boost::algorithm::is_digit() ) )
	  return false;
      }
    }
  }else{
    return false;
  }
  return true;
}

// gets the value by string and converts to an float
// sets 'value' to NAN on failure
void I3TriggerStatus::GetTriggerConfigValue(const std::string& key, float& value) const {
  value = NAN;
  std::string str_value( settings_.find(key)->second );
  if( WellFormedFloat( str_value ) ){
      value = atof( str_value.c_str() );
  }else{
    log_error("not clear how to convert '%s' to a float.", str_value.c_str());
  }  
}

template <class Archive>
void I3TriggerReadoutConfig::serialize(Archive& ar, unsigned version)
{
  if (version>i3triggerreadoutconfig_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3TriggerReadoutConfig class.",version,i3triggerreadoutconfig_version_);
  ar & make_nvp("ReadoutTimeMinus",readoutTimeMinus);
  ar & make_nvp("ReadoutTimePlus",readoutTimePlus);
  ar & make_nvp("ReadoutTimeOffset",readoutTimeOffset);
}

// always write the latest class
template <class Archive>
void I3TriggerStatus::save(Archive& ar, unsigned version) const
{
  ar & make_nvp("Name", name_);
  ar & make_nvp("Settings", settings_);
  ar & make_nvp("ReadoutWindowConfigs",readoutconfigs_);
}

template <class Archive>
void I3TriggerStatus::load(Archive& ar, unsigned version) 
{
  if (version>i3triggerstatus_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3TriggerStatus class.",
	      version,i3triggerstatus_version_);

  ar & make_nvp("Name", name_);
  if(version<3)
    {
      std::map<std::string, int> settings;
      ar & make_nvp("Settings", settings);
      for(std::map<std::string,int>::iterator iter = settings.begin();
	  iter != settings.end(); ++iter){
	std::stringstream str;
	str<<iter->second;
	settings_[iter->first] = str.str();
      }
    }
  else
    {
      ar & make_nvp("Settings", settings_);
    }
  //in version 1, only a single readout window was saved -> map to global subdetector (0)
  // only provided for backward compatibility reading...
  if(version==1)
    {
      I3TriggerReadoutConfig readout;
      ar & make_nvp("ReadoutTimeMinus", readout.readoutTimeMinus);
      ar & make_nvp("ReadoutTimePlus", readout.readoutTimePlus);
      ar & make_nvp("ReadoutTimeOffset", readout.readoutTimeOffset);
      readoutconfigs_[I3TriggerStatus::ALL] = readout;
    }
  if(version>1)
    {
      ar & make_nvp("ReadoutWindowConfigs",readoutconfigs_);
    }
}

I3_SERIALIZABLE(I3TriggerStatus);
