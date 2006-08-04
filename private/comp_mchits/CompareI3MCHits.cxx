#include <dataio/FrameIO.h>
#include <dataio/FrameIO_Impl.h>
#include <dataio/BoostHeaders.h>

#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <ostream>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include "dataclasses/physics/I3RecoHit.h"
#include "dataclasses/I3Units.h"

using std::cout;
using std::endl;

namespace io = boost::iostreams;

void Init(io::filtering_istream&, std::string&);
I3FramePtr PopMeta(io::filtering_istream&);

int main(){

  io::filtering_istream s1;
  io::filtering_istream s2;
  
  std::string f1("pass1.MacOSX-libstdc++6-ppc.i3");
  std::string f2("pass2.MacOSX-libstdc++6-ppc.i3");

  Init(s1,f1);
  Init(s2,f2);

  I3FramePtr fp1;
  I3FramePtr fp2;

  int counter(0);
  int error_count(0);
  while(s1.good() && s2.good()){
    fp1 = PopMeta(s1);
    fp2 = PopMeta(s2);
    if(fp1 && fp2){
      std::cout<<"found a physics frame!("<<++counter<<")"<<std::endl;
      I3RecoHitSeriesMapConstPtr rh_ptr1 = fp1->Get<I3RecoHitSeriesMapConstPtr>("InIceRecoHitSeries");
      I3RecoHitSeriesMapConstPtr rh_ptr2 = fp2->Get<I3RecoHitSeriesMapConstPtr>("InIceRecoHitSeries");
      if(rh_ptr1 && rh_ptr2){
	cout<<"found both I3RecoHitSeriesMaps..."<<endl;
      }
      I3RecoHitSeriesMap::const_iterator i = rh_ptr1->begin();
      I3RecoHitSeriesMap::const_iterator j = rh_ptr2->begin();
      for( ; (i != rh_ptr1->end()) && (j != rh_ptr2->end()) ; i++,j++){
	I3RecoHitSeries::const_iterator ii = i->second.begin();
	I3RecoHitSeries::const_iterator jj = j->second.begin();
	for( ; (ii!=i->second.end()) &&(jj!=j->second.begin()) ; ii++,jj++){
	  //co something
	  if((fabs(ii->GetTime() -  jj->GetTime()) > 0.01 *I3Units::ns) ||
	     (ii->GetSourceIndex() != jj->GetSourceIndex())) error_count++;
	}
      }
    }
  }
  cout<<"***********************"<<endl;
  cout<<"****Number of errors: "<<error_count<<endl;
  cout<<"***********************"<<endl;
  return 0;
}

  
void Init(io::filtering_istream& ifs, std::string& filename){
  if (filename.rfind(".gz") == (filename.length() -3))
    {
      ifs.push(io::gzip_decompressor());
      log_info("Input file ends in .gz.  Using gzip decompressor.");
    }
  else
    {
      log_info("Input file doesn't end in .gz.  Not decompressing.");
    }
  ifs.push(io::file_source(filename));
  
  if (!ifs.good())
    log_fatal("Problem opening file \"%s\" for reading.", filename.c_str());  
}

I3FramePtr 
PopMeta(io::filtering_istream& ifs)
{
  std::vector<std::string> skip;//skip none
  bool skip_unregistered(true);
  
  I3FramePtr tmpframe;
  if(ifs.peek() == EOF)
    return I3FramePtr();
  try {
    tmpframe = I3::dataio::load<boost::archive::portable_binary_iarchive>(ifs, skip,
									  skip_unregistered);
  } catch (const boost::archive::archive_exception& e) {
    //
    // the EOF situation: we return "no more meta" *AND* next_event_ is empty.
    //
    log_info("caught archive exception \"%s\" while reading frame.", 
	     e.what());
    return I3FramePtr();
  }   
  // if it's a slow stream, cache it
  if (tmpframe->GetStop() == I3Frame::Physics) return tmpframe;
  else return I3FramePtr();  
}
