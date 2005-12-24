#ifndef I3DATAACCESS_H
#define I3DATAACCESS_H

const map<OMKey,I3AMANDAAnalogReadout> 
GetAMANDAAnalogReadouts(I3Frame& frame,
		 const string& name);

const map<OMKey,vector<I3TWRLaunch> >
GetAMANDATWRReadouts(I3Frame& frame,
		     const string& name);

const map<OMKey,vector<I3DOMLaunch> >
GetIceCubeReadouts(I3Frame& frame,
		   const string& name);

const map<OMKey,I3RecoHitSeries> 
GetRecoHits(I3Frame& frame,
	    const string& name);
  
const map<OMKey,I3RecoPulseSeries> 
GetRecoPulsesSeries(I3Frame& frame,
		    const string& name);
  
const map<OMKey,I3RecoPulseSeries> 
GetRecoPulsesSeries(I3Frame& frame,
		    const string& name,
		    const string& selection);

const map<OMKey,I3RecoPulseSeries> 
GetRecoPulsesSeries(I3Frame& frame,
		    const string& name,
		    const string& selection);

const I3RecoResultPtr 
GetRecoResult(I3Frame& frame,
	      const string& name);

const I3FilterPtr 
GetFilter(I3Frame& frame,
	  const string& name);

const I3TriggerPtr 
GetTrigger(I3Frame& frame,
	   const string& name);

const map<OMKey,I3MCHitSeries> 
GetMCHitSeries(I3Frame& frame,
	       const string& name);

const map<OMKey,I3MCPMTResponsePtr>
GetMCPMTResponse(I3Frame& frame);


const map<OMKey,I3PMTPulseVect>
GetPMTPulseVect(I3Frame& frame);

const double 
GetMCWeight(I3Frame& frame,
	    const string& name);


#endif
 
