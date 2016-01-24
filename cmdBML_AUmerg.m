function arrBML = cmdBML_AUmerg(arrAU,eAmount,L)
    coder.extrinsic('sprintf');
    coder.extrinsic('strcat');
    coder.extrinsic('fscanf')
    coder.extrinsic('get_param');
    coder.extrinsic('num2str');
    csum=1;
    %Maryam, 20-10-2015, resized encStr2Arr to 500
    str1 = sprintf('<?xml version=\"1.0\" ?><act><bml>');
    %L=length(arrAU);
    for j = 1:L
        AU=arrAU(j); eA=eAmount(j);  
        c1 = countDigits(AU);c2 = countDigits(eA);csum=c1+c2+csum;       
        if(max(ceil(log10(abs(AU))),1)==1) %if AU is one-digit
            temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  start=\"0\" ready=\"2\" stroke=\"4\"  relax=\"6\" end=\"8\" amount=\"%0.1f\"/>',AU,eA);
            %temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%1d\"  amount=\"%0.1f\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/>',AU,eA); 
            temp2=strcat(str1,temp);
            str1=temp2;
        else      
            temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\" start=\"0\" ready=\"2\" stroke=\"4\"  relax=\"6\" end=\"8\" amount=\"%0.1f\"/>',AU,eA);
            %temp = sprintf('<face type=\"FACS\" side=\"BOTH\" au=\"%2d\" amount=\"%0.1f\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/><face type=\"FACS\" side=\"BOTH\" au=\"1\"  amount=\"1\"/>',AU,eA);
            temp2=strcat(str1,temp);
            str1=temp2;
        end
        
        %11-12-2015: write all AU amounts to files and plot them after run
%         currentTime=get_param('Expriment_FacialExpr','SimulationTime');  %use name of simulink proj
%         all_AUs=[1,2,4,5,6,7,12,26,45];
%         for c=1:9
%             if( AU==all_AUs(c))
%                 filename=['AU' num2str(AU) '.txt'];
%                 fileID = fopen(filename,'a');
%                 fprintf(fileID,'%0.3f,%0.1f\r\n',eA,currentTime);%used 0.0 to get int there
%                 fclose(fileID);
%                 break;
%             end
%         end
%         use this for ploting amount over time for each AU
%         matrix = importdata('AU2.txt',',');figure(2);plot(matrix(:,2),matrix(:,1));title('AU2'); 


    end
    str2 = sprintf('</bml></act>');
    
    %maryam,7-12-2015: had to do this since matlab does not accept
    %variable size
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
    end
    
    %n=length(arrAU);
    %mystr=blanks(arrAU(n));
   % mystr=blanks(656);
    mystr = strcat (str1,str2);    
    arrBML = encStr2Arr(mystr);





