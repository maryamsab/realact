function [ arrBML ] = cmdSBM_image( imgNr )
coder.extrinsic('sprintf')
%coder.extrinsic('strcat')
% OK, this is matlab weiredness:
% in code generation sprintf returns a mxArray, not a string
% we need to force using a string by allocating string of the right size in
% the mystr variable (only took three days to find that out...) ugly, but
% works...

mystr=blanks(67);
% mystr = sprintf('image setMaterial ScreenA001 fakeIAPS%04d', imgNr);
mystr = sprintf('scene.vhmsg2("vrOgre", "image setMaterial ScreenA001 fakeIAPS%04d")', imgNr);


arrBML = encStr2Arr(mystr);
end
