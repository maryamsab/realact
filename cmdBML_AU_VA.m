function arrBML = cmdBML_AU_VA(eAmount)
    coder.extrinsic('sprintf');
    coder.extrinsic('strcat');
    L=0;
    %15-12-2015, use Grammer's data to map AU and VA
    str1 = sprintf('<?xml version=\"1.0\" ?><act><bml>');
    all_AUs=[1,2,4,5,6, 7,12,26,45,10, 25 ,102,103,104,105];
    for c=1:15
        AU=all_AUs(c); eA=eAmount(c); 
        if(eA>=0.1)
            L=L+1;
%           fprintf('AU,eA: %0.0f,%0.1f\r\n',AU,eA);
            if(max(ceil(log10(abs(AU))),1)==1) %if AU is one-digit
                temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  start=\"0\" ready=\"2\" stroke=\"4\"  relax=\"6\" end=\"8\" amount=\"%0.3f\"/>',AU,eA);
                temp2=strcat(str1,temp);
                str1=temp2;
            else      
                temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\" start=\"0\" ready=\"2\" stroke=\"4\"  relax=\"6\" end=\"8\" amount=\"%0.3f\"/>',AU,eA);
                temp2=strcat(str1,temp);
                str1=temp2;
            end          
        end
    end
    str2 = sprintf('</bml></act>');

    if(L==1)
        mystr=blanks(103);
    elseif(L==2)
        mystr=blanks(206);
    elseif(L==3)
        mystr=blanks(306);
    elseif(L==4)
        mystr=blanks(412);
    elseif(L==5)
        mystr=blanks(515);
    elseif(L==6)
        mystr=blanks(656);
    elseif(L==7)
        mystr=blanks(759);
    elseif(L==8)
        mystr=blanks(862);
    elseif(L==9)
        mystr=blanks(965);
    elseif(L==10)
        mystr=blanks(1068); 
    elseif(L==11)
        mystr=blanks(1171);
    elseif(L==12)
        mystr=blanks(1474);
    elseif(L==13)
        mystr=blanks(1577);
    elseif(L==14)
        mystr=blanks(1610);
    elseif(L==15)
        mystr=blanks(1713);
    else
        fprintf(' ,L: %0.0f\r',L);
    end
    mystr = strcat (str1,str2);
    arrBML = encStr2Arr(mystr);




