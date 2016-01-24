function [ arrBML,agentPosition ] = cmdBML_walkOppositeUser(x,y)
coder.extrinsic('sprintf')

% 1) Worldsim: x btw -200,200/Locomotion BML: x btw -3,3:  x=x*0.015;
% 1) AnTS:     x btw  200,600/Projector Locomotion BML: x btw 0,2:  x=(x-200)/200;

%x=x*0.015; %worldSim
x=(x-200)/200; %AnTS

% 2) calculate the position of the agent based on user position
if x>1
    x=x-1;
else
    x=x+1;
end

% 3) agentposition is compared with worldsim's x to calculate distance between user and
     %agent so we need to scale back
%agentPosition =round(x*66.66); %worldSim
agentPosition =round((x*200)+200); %AnTS

%calculate length of string: if x is negative length+1
if x<0
    c=116;
else
    c=115;
end

mystr=blanks(c);
mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><locomotion manner=\"walk\" facing=\"camera\" target=\"%0.2f %d\"/></bml></act>', x,0);
arrBML = encStr2Arr(mystr);

end



