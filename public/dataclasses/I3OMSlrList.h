/**
 * copyright  (C) 2004
 * the IceCube collaboration
 *  $Id: I3OMSlrList.h,v 1.1 2004/10/22 21:08:44 deyoung Exp $
 *
 * @file I3OMSlrList.h
 * @version $Revision: 1.1 $
 * @date $Date: 2004/10/22 21:08:44 $
 * @author deyoung
 */

#ifndef I3OMSLRLIST_H_INCLUDED
#define I3OMSLRLIST_H_INCLUDED

#include "services/I3Logging.h"
#include "dataclasses/I3OMSlr.h"

using namespace roost;

/**
 * @brief 
 */
class I3OMSlrList : public I3OMSlr {

public:

    I3OMSlrList() {};
    virtual ~I3OMSlrList() {};
    
    virtual Bool_t IsSelected(const I3OMItr);
    virtual const I3OMSlrPtr GetCopy();

    void SetGoodOMs(const vector<OMKey>& good_list);
    void PrintGoodOMs();

 private:

    vector<OMKey> fGoodOMs;

    // Root Macro so that I3LineFit can be used from the interpreter
    ClassDef(I3OMSlrList,1);
}; 

#include "dataclasses/StoragePolicy.h"
/**
 * pointer type to insulate users from memory management
 */
typedef PtrPolicy<I3OMSlrList>::ThePolicy I3OMSlrListPtr;

#endif //I3OMSLRLIST_H_INCLUDED
