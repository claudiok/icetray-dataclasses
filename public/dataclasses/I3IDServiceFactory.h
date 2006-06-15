#ifndef I3IDSERVICEFACTORY_H
#define I3IDSERVICEFACTORY_H
/*
 * class: I3IDServiceFactory
 *
 * Version $Id: I3IDServiceFactory.h 15721 2006-02-15 12:32:23Z troy $
 *
 * Date: 17 Feb 2004
 *
 * (c) IceCube Collaboration
 */

// Header files


// forward declarations

class I3Context;

// superclasses

#include "icetray/I3ServiceFactory.h"
#include "phys-services/I3IDService.h"

// namespace declarations

using namespace std;

/**
 * @brief This class installs a I3IDService.
 *
 * @author olivas
 */
class I3IDServiceFactory
: public I3ServiceFactory
{
 public:

  // Constructors and destructor

  I3IDServiceFactory(const I3Context& context);

  virtual ~I3IDServiceFactory();

  // public member functions

  /**
   * Installed this objects service into the specified services object.
   *
   * @param services the I3Context into which the service should be installed.
   * @return true if the services is successfully installed.
   */
  virtual bool InstallService(I3Context& services){
    if(!id_service_){
      id_service_ = I3IDServicePtr(new I3IDEventService);
    }
    return services.Put<I3IDService>(id_service_);//there can be only one
  }

  /**
   * Configure service prior to installing it. 
   */
  virtual void Configure();

 private:

  // private constructors, destructor and assignment

  I3IDServiceFactory
    (const I3IDServiceFactory& rhs); // stop default
  I3IDServiceFactory operator=
    (const I3IDServiceFactory& rhs); // stop default

  // instance member data
  I3IDServicePtr id_service_;
  

  SET_LOGGER("I3IDServiceFactory");
};


  // Constructors and destructor

I3IDServiceFactory::I3IDServiceFactory(const I3Context& context):
  I3SerivceFactory(context)
{}

#endif
