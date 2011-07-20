#!/usr/bin/env python

from I3Tray import *
from icecube import icetray, dataclasses, dataio
from os.path import expandvars
### open the GCD file you want to change 
filein = expandvars("$I3_PORTS/test-data/sim/GeoCalibDetectorStatus_IC80_DC6.54655.i3.gz")
oldgcd = dataio.I3File(filein)

### make a new I3File to write you new G,C, and/or D frames to
newgcd = dataio.I3File("./NEW_GeoCalibDetectorStatus_IC80_DC6.54655.i3",dataio.I3File.Mode.Writing)

### loop over the frames until you find the one with the geometry in it
while oldgcd.more():
    frame = oldgcd.pop_frame()
    if frame.Has("I3DetectorStatus") : 

        ### get the geometry from the frame
        i3ds = frame.Get("I3DetectorStatus")

        #trigStatMap = i3ds.TriggerStatus

        ## clear the the old triggers
        i3ds.TriggerStatus.clear()

        ## Setup the SMT 8 trigger
        smt_ts = dataclasses.I3TriggerStatus()
        smt_tk = dataclasses.TriggerKey()

        smt_tk.config_id = 1006
        smt_tk.source = dataclasses.I3Trigger.IN_ICE
        smt_tk.type = dataclasses.I3Trigger.SIMPLE_MULTIPLICITY
        
        smt_ts.TriggerName = 'SimpleMajorityTrigger'
        trigSet = smt_ts.TriggerSettings
        
        trigSet['threshold'] = 8
        trigSet['timeWindow'] = 5000
        
        inice_trc = dataclasses.I3TriggerStatus.I3TriggerReadoutConfig()
        inice_trc.ReadoutTimeMinus = 4000
        inice_trc.ReadoutTimePlus = 6000
        inice_trc.ReadoutTimeOffset = 0
        
        ictop_trc = dataclasses.I3TriggerStatus.I3TriggerReadoutConfig()
        ictop_trc.ReadoutTimeMinus = 10000
        ictop_trc.ReadoutTimePlus = 10000
        ictop_trc.ReadoutTimeOffset = 0
        
        readoutSet = smt_ts.ReadoutSettings
        
        readoutSet[dataclasses.I3TriggerStatus.INICE] = inice_trc
        readoutSet[dataclasses.I3TriggerStatus.ICETOP] = ictop_trc
        
        i3ds.TriggerStatus[smt_tk] = smt_ts
        
        ## String Trigger (5/7)
        str_ts = dataclasses.I3TriggerStatus()
        str_tk = dataclasses.TriggerKey()
        
        str_tk.config_id = 1007
        str_tk.source = dataclasses.I3Trigger.IN_ICE
        str_tk.type = dataclasses.I3Trigger.STRING
        
        str_ts.TriggerName = 'ClusterTrigger'
        trigSet2 = str_ts.TriggerSettings
        
        trigSet2['coherenceLength'] = 7
        trigSet2['domSet'] = 2
        trigSet2['multiplicity'] = 5 
        trigSet2['timeWindow'] = 1500
        
        strinice_trc = dataclasses.I3TriggerStatus.I3TriggerReadoutConfig()
        strinice_trc.ReadoutTimeMinus = 4000
        strinice_trc.ReadoutTimePlus = 6000
        strinice_trc.ReadoutTimeOffset = 0
        
        strictop_trc = dataclasses.I3TriggerStatus.I3TriggerReadoutConfig()
        strictop_trc.ReadoutTimeMinus = 10000
        strictop_trc.ReadoutTimePlus = 10000
        strictop_trc.ReadoutTimeOffset = 0
        
        readoutSet2 = str_ts.ReadoutSettings
        
        readoutSet2[dataclasses.I3TriggerStatus.INICE] = strinice_trc
        readoutSet2[dataclasses.I3TriggerStatus.ICETOP] = strictop_trc
        
        i3ds.TriggerStatus[str_tk] = str_ts


        ## print what we've got
        for trigKey,trigStat in i3ds.TriggerStatus:
            if trigKey.check_config_id():
                print 'Key',trigKey.source, trigKey.type, trigKey.config_id
            else:
                print 'Key',trigKey.source, trigKey.type
            print 'TriggerStatus for:',trigStat.TriggerName
            print 'ReadoutConfig:'
            readoutset = trigStat.ReadoutSettings
            for e in readoutset:
                print e.key()
                trc = e.data()
                print 'tminu:',trc.ReadoutTimeMinus,' tplus:', trc.ReadoutTimePlus, ' toffset:', trc.ReadoutTimeOffset
            print 'TriggerConfigs:'
            for foo,bar in trigStat.TriggerSettings:
                print foo, '->', bar




        ### remove the I3Geometry from the old frame
        del frame["I3DetectorStatus"]   
        ### put the new I3Geometry in the frame 
        frame["I3DetectorStatus"] = i3ds  
    newgcd.push(frame)   ### push the frame to our empty I3File

newgcd.close()   ##close it
