import random
import math
import GazeDirectionCtrl
import time


# this is pretty shitty: these event functions are effectively static, 
# meaning we have to define all variables outside the class


class ClsGazeCtrl(SBScript):
	SA_mean = 11 #mean saccade amplitude in degrees
	SA_sdev = 5 #sded saccade amplitude
	SD_sdev = 15 #sdev saccade direction
	SD_p_cardinal = 0.3 #cardinal axis: < .5 = left/right, > .5 up/down
	pawn_name = "foo"
	
	#this might not be called...
	def start(self):
		print "Starting ClsGazeCtrl..." + self.pawn_name
		if scene.getPawn(self.pawn_name) == None:
			scene.createPawn(self.pawn_name)
		p = scene.getPawn(self.pawn_name)
		p.setPosition(SrVec(0, 175, -121))

		self.x = p.getPosition().getData(0)
		self.y = p.getPosition().getData(1)
		self.z = p.getPosition().getData(2)
		self.time_old = 0
	
	def stop(self):
		print "Stopping ClsGazeCtrl..."
				
	def update(self, time):
		fixation_duration = random.normalvariate(.5, .2)
		if (time - self.time_old) > fixation_duration : #this we can use to vary the fixation duration
			print "ClsGazeCtrl: During simulation step at time " + str(time) + " " + str(self.time_old)
			saccadic_amplitude = random.normalvariate(self.SA_mean, self.SA_sdev)
			gaze_angle = GazeDirectionCtrl.getDirection(self.SD_sdev, self.SD_p_cardinal)
			delta_x = math.cos(math.radians(gaze_angle)) * saccadic_amplitude
			delta_y = math.sin(math.radians(gaze_angle)) * saccadic_amplitude
			x_ = self.x + delta_x
			y_ = self.y + delta_y
			print(str(x_) + " " + str(y_))
			cmd = '<gaze sbm:target-pos="' + str(x_) + ' ' + str(y_) + ' ' + str(self.z) + '" sbm:joint-range="EYES NECK"/>'
			print(cmd)
			bml.execBML('brad', cmd)
			# #print(str(int(gaze_angle)) + "\t" + str(math.cos(math.radians(gaze_angle))) + "\t" + str(delta_x))
			# #x = x
			# #y = y_	
			self.time_old = time
	
	
		
		
		
		