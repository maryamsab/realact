#!/usr/bin/python

import yarp
import os

yarp.Network.init();

portIn = yarp.BufferedPortBottle();
portOut = yarp.BufferedPortBottle();

portIn.open("/python/in");
portOut.open("/testSender");

os.system("yarp connect /SHORE/actors/out /python/in");

while True : 
    #read from SHORE
    bottleIn = portIn.read()
    bottleOut = portOut.prepare();
    bottleOut.clear(); 
    if(bottleIn.size()>0) : 
        item = bottleIn.get(0)
        actorAffectHappy = item.find("Happy").asDouble()
		#send to port for smartbody
        bottleOut.addDouble(actorAffectHappy)
        print ("Sending ", bottleOut.toString());
        portOut.write();
	
portOut.close();  
yarp.Network.fini();

