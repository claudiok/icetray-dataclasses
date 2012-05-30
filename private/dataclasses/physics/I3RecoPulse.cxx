#include <icetray/serialization.h>
#include <dataclasses/physics/I3RecoPulse.h>
#include <dataclasses/physics/I3Waveform.h>
#include <dataclasses/external/CompareFloatingPoint.h>
#include <string>
#include <stdio.h>

using CompareFloatingPoint::Compare;

I3RecoPulse::~I3RecoPulse() {}

template <class Archive> 
void 
I3RecoPulse::serialize(Archive& ar, unsigned version)
  {
    if (version>i3recopulse_version_)
    log_fatal("Attempting to read version %u from file but running version %u of I3RecoPulse class.",version,i3recopulse_version_);

	if (version < 2) {
		double t(time_), c(charge_), w(width_);
		int hitid(0);
		ar & make_nvp("Time", t);
		ar & make_nvp("HitID", hitid);
		ar & make_nvp("PulseCharge", c);
		ar & make_nvp("Width", w);
		time_ = t;
		charge_ = c;
		width_ = w;
		if (version > 0) {
			int sourceindex(-1);
			ar & make_nvp("sourceIndex",sourceindex);

			// Try to guess what this was supposed to be,
			// canonicalizing NFE's definition. NFE and FE pulses
			// used different meanings here, which are not actually
			// distinguishable. The I3Waveform::Source enum changed
			// in r71620, so we hard-code the former values.
			flags_ = 0;
			switch (sourceindex) {
				case I3Waveform::ATWD:
					flags_ |= I3RecoPulse::ATWD | I3RecoPulse::LC;
					break;
				case 10:
				case I3Waveform::FADC:
					flags_ |= I3RecoPulse::FADC | I3RecoPulse::LC;
					break;
				case 50:
				case I3Waveform::SLC:
					flags_ |= I3RecoPulse::FADC;
					break;
				default:
					break;
			}
		}
	} else {
		ar & make_nvp("Time", time_);
		ar & make_nvp("PulseCharge", charge_);
		ar & make_nvp("Width", width_);
		ar & make_nvp("Flags", flags_);
	}
}


bool 
I3RecoPulse::operator==(const I3RecoPulse& rhs) const
{
  return flags_ == flags_ 
    && (time_ == rhs.time_ || (isnan(time_) && isnan(rhs.time_)))
    && (charge_ == rhs.charge_ || (isnan(charge_) && isnan(rhs.charge_)))
    && (width_ == rhs.width_ || (isnan(width_) && isnan(rhs.width_)));
}

std::ostream& operator<<(std::ostream& oss, const I3RecoPulse& p){

  std::string flagstr;
  if (p.GetFlags() & I3RecoPulse::LC) flagstr.append("LC ");
  if (p.GetFlags() & I3RecoPulse::ATWD) flagstr.append("ATWD ");
  if (p.GetFlags() & I3RecoPulse::FADC) flagstr.append("FADC ");
  oss << "[ I3RecoPulse Time : " << p.GetTime() << std::endl
      << "            Charge : " << p.GetCharge() << std::endl
      << "             Width : " << p.GetWidth()  << std::endl
      << "             Flags : " << flagstr << std::endl
      << "]" ;
  return oss;
}


I3_SERIALIZABLE(I3RecoPulse);

I3_SERIALIZABLE(I3RecoPulseSeriesMap);
I3_SERIALIZABLE(I3RecoPulseMap);

int I3BaseMap<OMKey,std::vector<I3RecoPulse> >::CalcNChannel(std::vector<int> strings){
	I3BaseMap<OMKey,std::vector<I3RecoPulse> >::iterator it=this->begin();
	unsigned int n =0;
	if(strings.empty()){
		while(it!=this->end()){
			if(!(*it).second.empty())
				n++;
			it++;
		}
	}
	else{
		while(it!=this->end()){
				bool found = false;
				for(unsigned int i = 0; i < strings.size(); i++)
					if(strings[i] == (*it).first.GetString()){ 
						found = true;
						break; 			
					}				
				if(!(*it).second.empty() && found)
					n++;
				it++;
		}
	}
	return n;
}

int I3BaseMap<OMKey,std::vector<I3RecoPulse> >::CalcNString(std::vector<int> strings){
	I3BaseMap<OMKey,std::vector<I3RecoPulse> >::iterator it=this->begin();
	std::map<int,int> stringMap;
	if(strings.empty()){
		while(it!=this->end()){
			if(!(*it).second.empty())
				stringMap[(*it).first.GetString()];
			it++;
		}
	}
	else{
		
		while(it!=this->end()){
				bool found = false;
				for(unsigned int i = 0; i < strings.size(); i++)
					if(strings[i] == (*it).first.GetString()) {
						found = true;
						break;
					} 			
				
				if(!(*it).second.empty() && found)
					stringMap[(*it).first.GetString()];
				it++;
		}
	}
	return stringMap.size();
}

double I3BaseMap<OMKey,std::vector<I3RecoPulse> >::CalcQTot(std::vector<int> strings){
	I3BaseMap<OMKey,std::vector<I3RecoPulse> >::iterator it=this->begin();
	double q =0;
	if(strings.empty()){
		while(it!=this->end()){
			for(unsigned int j = 0; j<(*it).second.size();j++){
				q+=(*it).second[j].GetCharge();
			}
			it++;
		}
	}
	else{
		while(it!=this->end()){
				for(unsigned int i = 0; i < strings.size(); i++)
					if(strings[i] == (*it).first.GetString()){ 						
							for(unsigned int j =0; j<(*it).second.size();j++){
								q+=(*it).second[j].GetCharge();
							}
							break;
					}

				it++;
		}
	}
	return q;
}

I3RecoPulseSeriesMapPtr I3BaseMap<OMKey,std::vector<I3RecoPulse> >::GetPulsesInStrings(std::vector<int> strings){
	I3RecoPulseSeriesMapPtr newMap(new I3RecoPulseSeriesMap);
	I3BaseMap<OMKey,std::vector<I3RecoPulse> >::iterator it=this->begin();
	while(it!=this->end()){
		for(unsigned int i = 0; i < strings.size(); i++)
			if(strings[i] == (*it).first.GetString()){ 						
					newMap->operator[]( (*it).first ) = (*it).second; 
					break;
			}
		it++;
	}
	return newMap;
}
	
I3RecoPulseSeriesMapPtr I3BaseMap<OMKey,std::vector<I3RecoPulse> >::GetPulsesNotInStrings(std::vector<int> strings){
	I3RecoPulseSeriesMapPtr newMap(new I3RecoPulseSeriesMap);
	I3BaseMap<OMKey,std::vector<I3RecoPulse> >::iterator it=this->begin();
	while(it!=this->end()){
		bool found = false;
		for(unsigned int i = 0; i < strings.size(); i++)
			if(strings[i] == (*it).first.GetString())
				found = true;
		
		if(!found)
			newMap->operator[]( (*it).first ) = (*it).second;  
	
		it++;
	}
	return newMap;
}

