function [ arrBML ] = cmdBML_idle()
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...
r=  round(rand(1)*2);
if(r == 0)
    mystr=blanks(85);
    mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><body posture=\"ChrBrad@Idle01_ToIdle02\"/></bml></act>');
    arrBML = encStr2Arr(mystr);
else if(r==1)
    mystr=blanks(91);
    mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><body posture=\"ChrBrad@Idle01_ScratchChest01\"/></bml></act>');
    arrBML = encStr2Arr(mystr);
else 
    mystr=blanks(92);
    mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><body posture=\"ChrBrad@Idle01_ScratchHeadLf01\"/></bml></act>');
    arrBML = encStr2Arr(mystr);
end

end



