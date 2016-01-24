function arrBML = cmdBML_AU(i,arrAU,eAmount)
    %#codegen
    coder.extrinsic('sprintf');
    coder.extrinsic('strcat');
    
    %Maryam, 14-10-2015
    %'strcat' dimension 2  maximum size is 453,it was not possible to concat and send all bmls 
    %for one emotion together(used simulink for loop )    
    
    AU=arrAU(i);eA=eAmount(i);   
    c1 = countDigits(AU);c2 = countDigits(eA);

    str1 = sprintf('<?xml version=\"1.0\" ?><act><bml>');
    
    if(max(ceil(log10(abs(AU))),1)==1) %if AU is one-digit
       % temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  start=\"0\" ready=\"1\" stroke=\"2\"  relax=\"3\" end=\"4\" amount=\"%0.1f\"/>',AU,eA); 
       temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  amount=\"%0.1f\"/>',AU,eA); 
        temp2=strcat(str1,temp);
        str1=temp2;
    else      
       % temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\" start=\"0\" ready=\"1\" stroke=\"2\"  relax=\"3\" end=\"4\" amount=\"%0.1f\"/>',AU,eA);
       temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\" amount=\"%0.1f\"/>',AU,eA);
        temp2=strcat(str1,temp);
        str1=temp2;
    end

    str2 = sprintf('</bml></act>');
    %n=length(arrAU);
    %mystr=blanks(arrAU(n));
    mystr=blanks(140+c1+c2);
    mystr = strcat (str1,str2);    
    arrBML = encStr2Arr(mystr);





