function [ arrBML ] = cmdBML_AUs(AU,eA,L)
    coder.extrinsic('sprintf');
    coder.extrinsic('strcat');

    %'strcat' dimension 2  maximum size is 453
    str1 = sprintf('<?xml version=\"1.0\" ?><act><bml>');
    
    if(max(ceil(log10(abs(AU))),1)==1) %if AU is one-digit
        temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  start=\"0\" end=\"3\" amount=\"%0.1f\"/>',AU,eA); 
        temp2=strcat(str1,temp);
        str1=temp2;
    else      
        temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\"  start=\"0\" end=\"3\" amount=\"%0.1f\"/>',AU,eA);
        temp2=strcat(str1,temp);
        str1=temp2;
    end

    str2 = sprintf('</bml></act>');
    %n=length(arrAU);
    %mystr=blanks(arrAU(n));
    mystr=blanks(450+L);
    mystr = strcat (str1,str2);
    arrBML = encStr2Arr(mystr);





