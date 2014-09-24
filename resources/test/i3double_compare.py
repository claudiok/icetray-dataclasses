#!/usr/bin/env python
from icecube import dataclasses
from icecube.icetray.I3Test import *

ENSURE( dataclasses.I3Double(12.0) == dataclasses.I3Double(12.0) , "I3Double == I3Double failed" )
ENSURE( dataclasses.I3Double(12.0) != dataclasses.I3Double(13) , "I3Double != I3Double failed" )
ENSURE( dataclasses.I3Double(12.0) < dataclasses.I3Double(13) , "I3Double < I3Double failed" )
ENSURE( dataclasses.I3Double(12.0) <= dataclasses.I3Double(13) , "I3Double <= I3Double failed" )
ENSURE( dataclasses.I3Double(14.0) > dataclasses.I3Double(13) , "I3Double > I3Double failed" )
ENSURE( dataclasses.I3Double(14.0) >= dataclasses.I3Double(13) , "I3Double >= I3Double failed" )

ENSURE( dataclasses.I3Double(12.0) == 12 , "I3Double == int failed" )
ENSURE( dataclasses.I3Double(12.0) != 13 , "I3Double != int failed" )
ENSURE( dataclasses.I3Double(12.0) < 13 , "I3Double < int failed" )
ENSURE( dataclasses.I3Double(12.0) <= 13 , "I3Double <= int failed" )
ENSURE( dataclasses.I3Double(14.0) > 13 , "I3Double > int failed" )
ENSURE( dataclasses.I3Double(14.0) >= 13 , "I3Double >= int failed" )

ENSURE( dataclasses.I3Double(12.0) == 12. , "I3Double == float failed" )
ENSURE( dataclasses.I3Double(12.0) != 13. , "I3Double != float failed" )
ENSURE( dataclasses.I3Double(12.0) < 13. , "I3Double < float failed" )
ENSURE( dataclasses.I3Double(12.0) <= 13. , "I3Double <= float failed" )
ENSURE( dataclasses.I3Double(14.0) > 13. , "I3Double > float failed" )
ENSURE( dataclasses.I3Double(14.0) >= 13. , "I3Double >= float failed" )
