import numpy
import random
import math

def getDirection(sdev, p_cardinal):
	#sdev = 15 
	#p_cardinal = .4

	cardinal = numpy.random.binomial(1, p_cardinal) # cardinal axis: up/down vs left/right
	pole = numpy.random.binomial(1, .5) # pol of cardinal axis up vs down, left vs right

	if cardinal==1: #up/down
		if pole==1: #up
			deg_mean = 0
		else: #down
			deg_mean =	180
			
	else: #left/righrt
		if pole==1: #left
			deg_mean = 270
		else: #right
			deg_mean = 90
		

	gaze_angle= random.gauss(deg_mean, sdev)
	return gaze_angle

'''
plotting the distribution
pipe output to data.txt
in R

data <- read.table("C:/Users/Ulysses/Desktop/PT/data.txt", quote="\"")
hist(data$V1, breaks=50, main="sdev = 35, p_cardinal=.5")
text(0, y=0, "up")
text(90, y=0, "right")
text(180, y=0, "down")
text(270, y=0, "left")

OR as polar histogram:

library(circular)
data <- read.table("C:/Users/Ulysses/Desktop/PT/data.txt", quote="\"")
rose.diag(circular(data$V1), bins=36, prop=3, zero=pi/2, main="sdev = 15, p_cardinal=.4")

'''


	
	
