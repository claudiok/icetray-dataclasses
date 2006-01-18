/**
 * copyright  (C) 2005
 * the icecube collaboration
 * @file I3MonitoringHeader.h
 */

#ifndef I3MONITORINGHEADER_H_INCLUDED
#define I3MONITORINGHEADER_H_INCLUDED

#include "dataclasses/I3DataHeader.h"
#include "dataclasses/OMKey.h"

/**
 * @brief This class defines the entries in the header of a monitoring record
 * in a .mon file as produced by monolith.
 */
class I3MonitoringHeader : public I3DataHeader
{
 public:
    virtual ~I3MonitoringHeader();
    int GetSize();
    int GetType();
    OMKey GetOMKey();
    int64_t GetMBID();
    int GetRun();

    void SetSize(int);
    void SetType(int);
    void SetOMKey(OMKey);
    void SetMBID(int64_t);
    void SetRun(int);

 private:
    OMKey om_;
    int64_t mbid_;
    int size_;
    int type_;
    int run_;

  friend class boost::serialization::access;

  template <class Archive>
    void serialize(Archive& ar, unsigned version);
};

typedef shared_ptr<I3MonitoringHeader> I3MonitoringHeaderPtr;

#endif //I3MONITERINGHEADER_H_INCLUDED
