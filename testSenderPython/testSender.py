#!/usr/bin/python

import yarp
import os
import time
import random

yarp.Network.init();

portOut = yarp.BufferedPortBottle();

portOut.open("/testSender");

#os.system("yarp connect /ants/outUB /ctrl2/in/pos");
#os.system("yarp connect /ctrl/out/pos /3ds01/pos");

ii = 0
while ii<1 : 
	bottleOutList = portOut.prepare();
	bottleOutList.clear(); 
	nrVars = 3
	for x in range(0, nrVars):
		bottleTemp = bottleOutList.addList(); #yarp.Bottle();
#		bottleTemp.clear(); 
		ss = "var" + str(x) + " " + str(random.random())
		bottleTemp.fromString(ss) #this creates a searchable yarp.Value (!)
#		(bottleTemp)
	print ("Sending ", bottleOutList.toString());
	portOut.write();
	time.sleep(.1)

portOut.close();
yarp.Network.fini();			