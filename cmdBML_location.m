function [ arrBML ] = cmdBML_location( x, y )
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...

mystr=blanks(91);
mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><locomotion manner=\"run\" target=\"%04d\" \"%04d\"/></bml></act>', x,y);

arrBML = encStr2Arr(mystr);
end

