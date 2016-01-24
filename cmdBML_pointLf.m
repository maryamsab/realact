function [ arrBML ] = cmdBML_pointLf()
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...
r=  round(rand(1)*1);
if(r == 0)
    mystr=blanks(88);
    mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><animation name=\"ChrBrad@Idle01_PointLf01\"/></bml></act>');
    arrBML = encStr2Arr(mystr);
else
    mystr=blanks(90);
    mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><animation name=\"ChrBrad@Idle01_BesidesLf01\"/></bml></act>');
    arrBML = encStr2Arr(mystr);
end
end



