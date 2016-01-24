function [ arrBML ] = cmdBML_smileS()
coder.extrinsic('sprintf')
 mystr=blanks(185);
 mystr = sprintf('<?xml version=\"1.0\" ?><act><bml><face type=\"FACS\" side=\"BOTH\" au=\"6\"  start=\"0\" end=\"10\" amount=\"0.5\"/><face type=\"FACS\" side=\"BOTH\" au=\"12\"  start=\"0\" end=\"10\" amount=\"2\"/></bml></act>');
 arrBML = encStr2Arr(mystr); 
end



