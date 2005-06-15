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

    void SetSize(int);
    void SetType(int);
    void SetOMKey(OMKey);
    void SetMBID(long long int);
    void SetRun(int);

 private:
    OMKey om_;
    long long int mbid_;
    int size_;
    int type_;
    int run_;

 ClassDef(I3MonitoringHeader,1);

  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& ar, unsigned version)
  {
    ar & make_nvp("om",om_);
    ar & make_nvp("mbid",mbid_);
    ar & make_nvp("size",size_);
    ar & make_nvp("type",type_);
    ar & make_nvp("run",run_);
  }

};

typedef shared_ptr<I3MonitoringHeader> I3MonitoringHeaderPtr;

#endif
