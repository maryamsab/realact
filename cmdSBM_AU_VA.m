function [arrSBM,eA] = cmdSBM_AU_VA(eAmount,c)
    coder.extrinsic('sprintf');
    coder.extrinsic('strcat');
    mystr=' ';viseme='W'; eA=0;
    %all_AUs=[1,2,4,5,6, 7,12,26,45,10, 25,26, 1011,1021,1031, 1032,1041, 1051,1052,1061];
    %16-12-2015, use Grammer's data to map AU and VA, SBMs
    switch c
        case 13  
            eA=eAmount(c)*0.9;viseme='W'; %like W%0.3
        case 14
            eA=eAmount(c)*0.9;viseme='ShCh';%like V%0.5
        %dimpler
        case 15
            eA=eAmount(c)*0.9;viseme='FV';%like F%0.3
        case 16
            eA=eAmount(c)*0.9;viseme='PBM';%like M%0.5

        case 17
            eA=eAmount(c);viseme='PBM';%1
        %lip tightner
        case 18
            eA=eAmount(c)*0.9;viseme='PBM';%0.2
        case 19
            eA=eAmount(c)*0.9;viseme='W';%0.6

        case 20            
            eA=eAmount(c)*0.9;viseme='W'; %0.3
            
    end 
    mystr=blanks(167);
   % mystr = sprintf('sbm char * viseme W %1.1f 1',viseme,eA);
   % mystr = sprintf('sbm char * viseme W 0.9 1');  
%     mystr = sprintf('scene.getPawn(\"gazeTarget\").setPosition(SrVec(%0.1f , %d ,%d))',1,1.7,2); %x btw 0,1
%     mystr = sprintf('sbm char * viseme W 0.9 1'); 
    mystr  = sprintf(' mycharacter = scene.getCharacter("ChrBrad"); mycharacter.setDoubleAttribute("eyelid.blinkPeriodMin", 5);mycharacter.setDoubleAttribute("eyelid.blinkPeriodMax", 9)');
    arrSBM = encStr2Arr(mystr);




