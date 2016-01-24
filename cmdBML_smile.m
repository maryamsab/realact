function [ arrBML ] = cmdBML_beat()
coder.extrinsic('sprintf')
mystr=blanks(95);
mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><body posture=\"ChrBrad@Idle01_BeatHighLf01\"/></bml></act>');
arrBML = encStr2Arr(mystr);
end



