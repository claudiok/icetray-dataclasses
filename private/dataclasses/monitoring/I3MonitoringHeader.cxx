#include "dataclasses/BoostHeaders.h"
#include "dataclasses/I3MonitoringHeader.h"

I3MonitoringHeader::~I3MonitoringHeader() {}

int I3MonitoringHeader::GetSize()
{
    return size_;
}

int I3MonitoringHeader::GetType()
{
    return type_;
}

OMKey I3MonitoringHeader::GetOMKey()
{
    return om_;
}

int64_t I3MonitoringHeader::GetMBID()
{
    return mbid_;
}

int I3MonitoringHeader::GetRun()
{
    return run_;
}

void I3MonitoringHeader::SetSize(int s)
{
    size_ = s; 
}

void I3MonitoringHeader::SetType(int t)
{
    type_ = t;
}

void I3MonitoringHeader::SetOMKey(OMKey ok)
{
    om_ = ok;
}

void I3MonitoringHeader::SetMBID(int64_t id)
{
    mbid_ = id;
}

void I3MonitoringHeader::SetRun(int r)
{
    run_ = r;
}

template <class Archive>
void 
I3MonitoringHeader::serialize(Archive& ar, unsigned version)
{
  ar & make_nvp("om",om_);
  ar & make_nvp("mbid",mbid_);
  ar & make_nvp("size",size_);
  ar & make_nvp("type",type_);
  ar & make_nvp("run",run_);
}

I3_SERIALIZABLE(I3MonitoringHeader);

