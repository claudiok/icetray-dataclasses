/**
    copyright  (C) 2004
    the icecube collaboration
    $Id: main.cxx,v 1.1.2.1 2005/02/05 01:33:42 troy Exp $

    @version $Revision: 1.1.2.1 $
    @date $Date: 2005/02/05 01:33:42 $
    @author Troy D. Straszheim

*/

//#include "TUT/tut.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

using boost::serialization::make_nvp;

//#include "dataclasses/I3Hit.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv)
{
  //  I3Hit u;

  // create and open a character archive for output
  std::ofstream txtofs("/tmp/filename.txt");
  std::ofstream binofs("/tmp/filename.bin");
  std::ofstream xmlofs("/tmp/filename.xml");

  try {
    throw std::logic_error("testthrow");
  } catch (const std::exception &e) {
    cout << "caught " << e.what() << endl;
  }

  try {
    boost::archive::text_oarchive txtoa(txtofs);
    boost::archive::binary_oarchive binoa(binofs);
    boost::archive::xml_oarchive xmloa(xmlofs);
    //    txtoa << u << u << u;
    //    binoa << u << u << u;
    //    xmloa << make_nvp("u", u) << make_nvp("u", u) << make_nvp("u", u);

    //    txtofs.close();
    //    binofs.close();
    //    xmlofs.close();

    //    std::ifstream txtifs("/tmp/filename.txt");
    //    std::ifstream binifs("/tmp/filename.bin");
    //    std::ifstream xmlifs("/tmp/filename.xml");

    //    boost::archive::text_iarchive txtia(txtifs);
    //    boost::archive::binary_iarchive binia(binifs);
    //    boost::archive::xml_iarchive xmlia(xmlifs);

    // read class state from archive

    //    I3Hit newhit;
    //    txtia >> newhit;
    //    ensure_equals("read in hit", newhit, u);

    //    binia >> newhit;

    //    xmlia >> make_nvp("newhit", newhit);
    //    ensure_equals("read in hit", newhit, u);
	
    // close archive
    //    txtifs.close();
    //    binifs.close();
    //    xmlifs.close();
  } catch (const std::exception &e) {
    cout << "caught " << e.what() << endl;
  }

}

