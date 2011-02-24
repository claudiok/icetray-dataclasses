/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3Waveform.h 12673 2005-11-17 10:36:58Z tschmidt $
 *
 * @file I3Waveform.h
 * @version $Revision: 1.10 $
 * @date $Date: 2005-12-01 16:45:55 -0500 (Thu, 01 Dec 2005) $
*/
#ifndef I3_WAVEFORM_H_INCLUDED
#define I3_WAVEFORM_H_INCLUDED

#include <utility>
#include <vector>
#include <dataclasses/I3Map.h>
#include <dataclasses/OMKey.h>

static const unsigned i3waveform_version_ = 2;
class I3Waveform 
{
 public:
  enum Source
  {
    ATWD = 0,
    FADC = 10,
    TWR_ELECTRICAL = 20,
    TWR_OPTICAL = 30,
    ETC = 40,
    SLC = 50
  };
  
  /** Describes possible artefacts within the data.
   * 
   * The waveform is a hardware independent representation of the data aquired.
   * Nevertheless, it can carry artefacts due to hardware imperfections.
   * 
   * Saturation is an example, which is hard to recognize, since the waveform is
   * a vector of doubles. Of course, it is still possible to regognize saturation
   * using some more or less fancy algorithm, but the module converting the hardware
   * dependent data into hardware independent data can recognize artefacts much easier.
   * It should record this information using this enumeration.
   * 
   * If the DOM calibrator combines the ATWD channels, it should call bins that
   * saturate even in the lowest amplified channel ADULTERATED, bins that saturate
   * only in some channels SHADY and bins that do not saturate in the highest
   * amplified channel VIRGINAL.
   */
  enum Status
  {
    VIRGINAL = 0,
    SHADY = 10,
    ADULTERATED = 20
  };
  
  class StatusCompound
  {
   private:
    std::pair<unsigned long long int, unsigned long long int>
      interval_;
    Status status_;
  
   public:
    StatusCompound() : interval_(std::make_pair(0, 0)), status_(ADULTERATED) {}
    
    virtual ~StatusCompound();
    
    const std::pair<unsigned long long int, unsigned long long int>&
    GetInterval() const { return interval_; }
    
    std::pair<unsigned long long int, unsigned long long int>&
    GetInterval() { return interval_; }
    
    Status GetStatus() const { return status_; }
    
    void SetStatus(Status status) { status_ = status; }
    
    bool operator==(const StatusCompound& rhs) const
    {
      return status_ == rhs.status_
	&& interval_ == rhs.interval_;
    }
   private:
    friend class boost::serialization::access;
    template<class Archive> void serialize(Archive& ar, unsigned version);
  };

  /**
   * Returns a summary of a given waveform/status information.
   * 
   * @return ADULTERATED/SHADY if any included status compound is ADULTERATED/SHADY,
   * or VIRGINAL.
   */
  static Status GetStatus(const std::vector<StatusCompound>& waveformInfo);

 private:
  double startTime_;
  double binWidth_;
  std::vector<double> waveform_;
  std::vector<double> waveformSteps_; /* Digitizer step; unserialized for now. */
  std::vector<StatusCompound> waveformInfo_;
  Source source_;
  
 public:
  I3Waveform() :  startTime_(0), binWidth_(0), source_(ATWD) {}
  
  virtual ~I3Waveform();
  
  double GetStartTime() const {return startTime_;}

  void SetStartTime(double startTime) {startTime_ = startTime;}

  double GetBinWidth() const {return binWidth_;}

  void SetBinWidth(double binWidth) {binWidth_ = binWidth;}

  const std::vector<double>& GetWaveformSteps() const { return waveformSteps_; }

  void SetWaveformSteps(const std::vector<double>& steps) { waveformSteps_ = steps; }

  const std::vector<double>& GetWaveform() const {return waveform_;}

  std::vector<double>& GetWaveform() {return waveform_;}

  void SetWaveform(const std::vector<double>& waveform) {waveform_ = waveform;}

  /**
   * Returns a status information for this waveform.
   * 
   * @return A collection of status compounds.
   * A status compound consists of an interval and a status information.
   * It describes the status of all waveform bins with indeces
   * [GetInterval().first, GetInterval().second). If there are waveform bins not
   * described by a status compound, these bins are assumed to have a status equal
   * to VIRGINAL, e. g. GetWaveformInformation().empty() equal true means, all
   * waveform bins are good.
   */
  const std::vector<StatusCompound>& GetWaveformInformation() const
    {return waveformInfo_;}
  
  /**
   * Returns a status information for this waveform.
   * 
   * @return A collection of status compounds.
   * A status compound consists of an interval and a status information.
   * It describes the status of all waveform bins with indeces
   * [GetInterval().first, GetInterval().second). If there are waveform bins not
   * described by a status compound, these bins are assumed to have a status equal
   * to VIRGINAL, e. g. GetWaveformInformation().empty() equal true means, all
   * waveform bins are good.
   */
  std::vector<StatusCompound>& GetWaveformInformation() {return waveformInfo_;}
  
  /**
   * Set the status information for this waveform.
   * 
   * Note: This method was added since there is a set method for the waveforms, too.
   * One might want to use the non-const get methods instead.
   * 
   * @param info The status information.
   */
  void SetWaveformInformation(const std::vector<StatusCompound>& info)
    {waveformInfo_ = info;}

  Source GetSource() const{return source_;}

  void SetSource(Source source){source_ = source;}

 private:
  friend class boost::serialization::access;
  template<class Archive> void serialize(Archive& ar, unsigned version);
};

bool operator==(const I3Waveform& lhs, const I3Waveform& rhs);

typedef std::vector<I3Waveform> I3WaveformSeries;
typedef I3Map<OMKey, I3WaveformSeries> I3WaveformSeriesMap;

BOOST_CLASS_VERSION(I3Waveform, i3waveform_version_);
I3_POINTER_TYPEDEFS(I3Waveform);
I3_POINTER_TYPEDEFS(I3WaveformSeries);
I3_POINTER_TYPEDEFS(I3WaveformSeriesMap);
#ifdef I3_USE_FAST_OMKEY_MAP
BOOST_CLASS_VERSION(I3WaveformSeriesMap, 1);
#endif
#endif // I3_WAVEFORM_H_INCLUDED
