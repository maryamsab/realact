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
	bottleOutSend = portOut.prepare();
	bottleOutSend.clear(); 

	for x in range(0, 3):        
		bottleOutList = bottleOutSend.addList();
	      
		bottleTemp = bottleOutList.addList(); 
		ss = "ID" + " " + str(random.randint(10,99))
		bottleTemp.fromString(ss) #this creates a searchable yarp.Value (!)
		bottleTemp = bottleOutList.addList(); 
		ss = "x" + " " + str(random.random())
		bottleTemp.fromString(ss) #this creates a searchable yarp.Value (!)
		bottleTemp = bottleOutList.addList(); 
		ss = "y" + " " + str(random.random())
		bottleTemp.fromString(ss) #this creates a searchable yarp.Value (!)

	print ("Sending ", bottleOutSend.toString());
	portOut.write();
	time.sleep(.1)

portOut.close();
yarp.Network.fini();			
