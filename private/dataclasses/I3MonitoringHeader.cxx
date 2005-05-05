#include "dataclasses/I3MonitoringHeader.h"

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

long long int I3MonitoringHeader::GetMBID()
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

void I3MonitoringHeader::SetMBID(long long int id)
{
    mbid_ = id;
}

void I3MonitoringHeader::SetRun(int r)
{
    run_ = r;
}
