function [ arrBML ] = cmdBML_reach( button )
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...

mystr=blanks(169);
mystr = sprintf('<act><bml><sbm:reach sbm:action="touch" sbm:reach-finish="true" sbm:reach-type="right" sbm:reach-velocity="100" sbm:use-locomotion="true" target="Button0%d"/></bml></act>', button);
arrBML = encStr2Arr(mystr);

end



