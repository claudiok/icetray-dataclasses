#ifndef I3MCPRIMARYDATA_H
#define I3MCPRIMARYDATA_H

/**
 * copyright  (C) 2004
 * the icecube collaboration
 * $Id: I3MCPrimaryData.h,v 1.1 2004/02/26 21:04:09 pretz Exp $
 *
 * A list of MCPrimaries used in the event
 *
 * @version $Revision: 1.1 $
 * @date $Date: 2004/02/26 21:04:09 $
 * @author pretz
 *
 * @todo decide if copy and assignment are private
 *
 */

#include "I3MCPrimary.h"
#include "StoragePolicy.h"

class I3MCPrimaryData : public VectorPolicy<I3MCPrimary>::ThePolicy
{
 public:
  /**
   * constructor
   */
  I3MCPrimaryData(){}

  /**
   * destructor
   */
  virtual ~I3MCPrimaryData(){}

 private:
  // copy and assignment private
/*   I3MCPrimaryData(const I3MCPrimaryData&); */
/*   const I3MCPrimaryData& operator=(const I3MCPrimaryData&); */

  // ROOT macro
  ClassDef(I3MCPrimaryData,1);
};

/**
 * Pointer typedeffed away to insulate users from the 
 * memory-mananagement implementation
 */
typedef PtrPolicy<I3MCPrimaryData>::ThePolicy I3MCPrimaryDataPtr;

#endif
