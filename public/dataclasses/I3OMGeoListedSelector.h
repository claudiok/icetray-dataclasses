/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3OMGeoListedSelector.h,v 1.1 2004/07/30 04:27:48 pretz Exp $
 *
 * @file I3OMGeoListedSelector.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/07/30 04:27:48 $
 * @author pretz
 */
#ifndef I3OMGEOLISTEDSELECTOR_H
#define I3OMGEOLISTEDSELECTOR_H

#include <vector>
#include <map>
#include "dataclasses/I3InIceGeometry.h"

using namespace std;

/**
 * @brief This class can be used to extract OMs from the geometry based
 * on a specific list of excluded OMs.  The 'bad-tube' list.
 *
 * Check the SelectorTest.h for example usage
 */
class I3OMGeoListedSelector
{
 private:
  map<OMKey,I3OMGeoPtr>& fSelectedOMs;
  vector<OMKey> fKeysToSelect;

  // default constructor private
  I3OMGeoListedSelector();

 public:
  /**
   * @brief Built with a map of I3OMGeo's to select oms into.
   * 
   * @param selected_oms the map we want to fill with oms
   * @param keys_to_select a vector of the keys that are not allowed to be
   * put in the final list.  The 'bad tube' list for instance.
   */
  I3OMGeoListedSelector(map<OMKey,I3OMGeoPtr>& selected_oms,
			const vector<OMKey>& keys_to_select) :
    fSelectedOMs(selected_oms), 
    fKeysToSelect(keys_to_select){}

  /**
   * @brief the operator that does the extraction. 
   */
  void operator()(pair<OMKey,I3OMGeoPtr> the_pair)
    {
      vector<OMKey>::iterator iter;
      // there's gotta be some stl thing to do this.
      for(iter=fKeysToSelect.begin();iter!=fKeysToSelect.end();iter++)
	{
	  if(the_pair.first == *(iter))
	    return;
	}
      fSelectedOMs[the_pair.first] = the_pair.second;
    }

};

#endif // I3OMGEOLISTEDSELECTOR_H
