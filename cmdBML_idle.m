function [ arrBML ] = cmdBML_idle()
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...

mystr=blanks(85);
mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><body posture=\"ChrBrad@Idle01_ToIdle02\"/></bml></act>');
arrBML = encStr2Arr(mystr);

end



