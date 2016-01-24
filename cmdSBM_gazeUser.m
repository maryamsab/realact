function [ arrBML ] = cmdSBM_gazeUser( x,y )
coder.extrinsic('sprintf')
%for agent to gaze at the user, we create a pawn where user stands and agent gazes at the pawn

%1) AnTS: x btw 200,600/gaze btw 0,1
 x=(x-200)/400;

c = countDigits(x);

mystr=blanks(66+c);
%mystr = sprintf('scene.getPawn(\"gazeTarget\").setPosition(SrVec(%d, %d ,%d))',x,0,150);
mystr = sprintf('scene.getPawn(\"gazeTarget\").setPosition(SrVec(%0.1f , %d ,%d))',x,1.7,2); %x btw 0,1
arrBML = encStr2Arr(mystr);

end



