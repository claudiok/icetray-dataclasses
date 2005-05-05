/**
 * copyright  (C) 2005
 * the icecube collaboration
 *
 * @file I3MonitoringHeader.h
 * @author pretz
 * @author Taboada
 */

#ifndef I3MONITORINGHEADER_H
#define I3MONITORINGHEADER_H

#include "dataclasses/I3DataHeader.h"
#include "dataclasses/OMKey.h"

/**
 * @brief This class defines the entries in the header of a monitoring record
 * in a .mon file as produced by monolith.
 */
class I3MonitoringHeader : public I3DataHeader
{
 public:
    int GetSize();
    int GetType();
    OMKey GetOMKey();
    long long int GetMBID();
    int GetRun();
    I3Time GetTime();

    void SetSize(int);
    void SetType(int);
    void SetOMKey(OMKey);
    void SetMBID(long long int);
    void SetRun(int);
    void SetTime(I3Time);

 private:
    OMKey om_;
    long long int mbid_;
    int size_;
    int type_;
    int run_;
    I3Time record_time_;
};

typedef shared_ptr<I3MonitoringHeader> I3MonitoringHeaderPtr;

#endif
