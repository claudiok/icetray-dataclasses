/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3RecoResultAltTracks.h,v 1.6 2004/08/30 20:27:10 pretz Exp $
 *
 * @file I3RecoResultAltTracks.h
 * @version $Revision: 1.6 $
 * @date $Date: 2004/08/30 20:27:10 $
 * @author ehrlich
 */
#ifndef I3RECORESULTALTTRACKS_H
#define I3RECORESULTALTTRACKS_H

#include "I3RecoResult.h"
#include "I3Particle.h"

/**
 * @brief Reco result with several alternative solutions 
 */
class I3RecoResultAltTracks : public I3RecoResult, 
	public MapPolicy<string,I3ParticlePtr>::ThePolicy
{
  public:
  /**
   * constructor
   */
  I3RecoResultAltTracks(){}

  /**
   * destructor
   */
  virtual ~I3RecoResultAltTracks(){}

  /**
   * dumps the object to a given string
   */
  virtual const string ToStream() const
    {
      string to_return = I3RecoResult::ToStream();
      I3RecoResultAltTracks::const_iterator iter;
      for(iter = begin() ; iter!= end() ; iter++)
	{
	  to_return.append(iter->first);
	  to_return.append(":  ");
	  to_return.append(iter->second->ToStream());
	  to_return.append("\n");
	}
      return to_return;
    }

  private:
  // copy and assignment private
  I3RecoResultAltTracks(const I3RecoResultAltTracks&);
  const I3RecoResultAltTracks operator=(const I3RecoResultAltTracks);

  //ROOT macro
  ClassDef(I3RecoResultAltTracks,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3RecoResultAltTracks>::ThePolicy I3RecoResultAltTracksPtr;
#endif
