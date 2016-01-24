function yarpReadKinectWave_sfun(block)
%%
%% read value from sensor
%% 
setup(block);

function setup(block)
    disp('setup')

    %% Register dialog parameters
    block.NumDialogPrms  = 2; %VARIABLE NAME(s)

    % Register number of ports
    block.NumInputPorts  = 0;
    block.NumOutputPorts = 4;

    % Setup port properties to be inherited or dynamic
    block.SetPreCompInpPortInfoToDynamic;
    block.SetPreCompOutPortInfoToDynamic;

    % Override output port properties
    % will be the image number
    block.OutputPort(1).Dimensions       = 1;
    block.OutputPort(1).DatatypeID  = 0; % double
    block.OutputPort(1).Complexity  = 'Real';
    block.OutputPort(1).SamplingMode = 'sample';
    
    block.OutputPort(2).Dimensions       = 1;
    block.OutputPort(2).DatatypeID  = 0; % double
    block.OutputPort(2).Complexity  = 'Real';
    block.OutputPort(2).SamplingMode = 'sample';
    %right wrist
    block.OutputPort(3).Dimensions       = 1;
    block.OutputPort(3).DatatypeID  = 0; % double
    block.OutputPort(3).Complexity  = 'Real';
    block.OutputPort(3).SamplingMode = 'sample';
    %left wrist
    block.OutputPort(4).Dimensions       = 1;
    block.OutputPort(4).DatatypeID  = 0; % double
    block.OutputPort(4).Complexity  = 'Real';
    block.OutputPort(4).SamplingMode = 'sample';
    
    block.SampleTimes = [0, 0];

    block.SimStateCompliance = 'DefaultSimState';

    block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
    block.RegBlockMethod('InitializeConditions', @InitializeConditions);
    block.RegBlockMethod('Start', @Start);
    block.RegBlockMethod('Outputs', @Outputs);     % Required
    block.RegBlockMethod('Update', @Update);
    block.RegBlockMethod('Derivatives', @Derivatives);
    block.RegBlockMethod('Terminate', @Terminate); % Required


function DoPostPropSetup(block)
    block.NumDworks = 1;
  
    block.Dwork(1).Name            = 'x1';
    block.Dwork(1).Dimensions      = 1;
    block.Dwork(1).DatatypeID      = 0;      % double
    block.Dwork(1).Complexity      = 'Real'; % real
    block.Dwork(1).UsedAsDiscState = true;

function InitializeConditions(block)
    disp('InitializeConditions')
    LoadYarp;
    import yarp.Port;
    import yarp.Bottle;
    import yarp.Network;
    global yportRead0;
    yportRead0=Port;
    strPortNameWrite = block.DialogPrm(1).Data;
    strPortNameRead = block.DialogPrm(2).Data;
    assert (size(strPortNameWrite,2)<16)
    assert (size(strPortNameRead,2)<16)
    sprintf('Going to open port %s', strPortNameRead);
    yportRead0.open(strPortNameRead);
    Network.connect(strPortNameWrite, strPortNameRead);
    bottleIn=Bottle;
    yportRead0.read(bottleIn);
    disp('1');
    if(bottleIn.size()>0)
        item = bottleIn.get(0);    
        disp('2');
        %trackedItemNeck = item.find('neck');   
        %disp(item.asDouble());
        %block.OutputPort(1).Data = item.asDouble();       
    end
    block.Dwork(1).Data = 0;
    %end InitializeConditions

function Start(block)
    disp('Start')

function Outputs(block)
%end Outputs

function Update(block)
    import yarp.Bottle;
    global yportRead0;

    bottleIn=Bottle;
    yportRead0.read(bottleIn);

    if(bottleIn.size()>0)
        item = bottleIn.get(0);     
        trackedItemJoint = item.find('joints');         
        jointsString= char(trackedItemJoint);
       
        headI = strfind(jointsString, 'tag head'); 
        wristrightI = strfind(jointsString, 'tag wristright'); 
        wristleftI = strfind(jointsString, 'tag wristleft'); 
        
        if(headI>0) 
            if(wristrightI>0)         
                if(wristleftI>0)
                    headStr=jointsString(headI:headI+108);
                    headPositionI=strfind(headStr, 'position');
                    headPositionStr=headStr(headPositionI+10:headPositionI+35);
                    ss =(strsplit(headPositionStr));
                    headPositionX=str2double(ss(1))*100;
                    headPositionY=str2double(ss(2))*100;
                    headPositionZ=str2double(ss(3))*100 ;  

                    wristrightStr=jointsString(wristrightI:wristrightI+108);
                    wristRPositionI=strfind(wristrightStr, 'position');
                    wristrightPositionStr=wristrightStr(wristRPositionI+10:wristRPositionI+35);
                    ss =(strsplit(wristrightPositionStr));
                    wristrightPositionY=str2double(ss(2))*100;

                    wristleftStr=jointsString(wristleftI:wristleftI+108);
                    wristLPositionI=strfind(wristleftStr, 'position');
                    wristleftPositionStr=wristleftStr(wristLPositionI+10:wristLPositionI+35);
                    ss =(strsplit(wristleftPositionStr));
                    wristleftPositionY=str2double(ss(2))*100;

                    if(wristrightPositionY > headPositionY )
                        handRUp = 1;
                    else
                        handRUp = 0;
                    end

                    if(wristleftPositionY > headPositionY )
                        handLUp = 1;
                    else
                        handLUp = 0;
                    end

                    block.OutputPort(1).Data = headPositionY; 
                    block.OutputPort(2).Data = wristrightPositionY;
                    block.OutputPort(3).Data = handRUp;                   
                    block.OutputPort(4).Data = handLUp;
                else
                    disp('zero input');
                    block.OutputPort(1).Data = 0; 
                    block.OutputPort(2).Data = 0;
                    block.OutputPort(3).Data = 0;
                    block.OutputPort(4).Data = 0;
                end
            end
        end

        
%        y=strfind(jointsString, 'position');
%         disp('testtttttttttttttttt');
%         disp(y);
%         if(y>0)
%              temp=jointsString(y:y+4)
%         end

        %strsplit
        %temp = trackedItemJoint.find('position')
        
        
%%ORIENTATION:       
%         trackedItemElbowright = trackedItemJoint.find('tag elbowright')
%         trackedElbowCoordinate = trackedItemElbowright.find('orientation');   
%         temp=char(trackedElbowCoordinate);
%         if (length(temp) > 0)
%             ss =(strsplit(temp));
%             
%             x=str2double(ss(1))*57
%             y=str2double(ss(2))*57
%             z=str2double(ss(3))*57
%             w=str2double(ss(4))*57
% 
%             block.OutputPort(1).Data = x; 
%             block.OutputPort(2).Data = y;
%             block.OutputPort(3).Data = z;
%             block.OutputPort(4).Data = w;
%         else
%              block.OutputPort(1).Data = 0; 
%              block.OutputPort(2).Data = 0;
%              block.OutputPort(3).Data = 0;
%              block.OutputPort(4).Data = 0;
%         end
    end

%end Update

function Derivatives(block)
%end Derivatives

function Terminate(block)
    disp('Terminate')

    global yportRead0;

    if exist('yportRead0', 'var')
         yportRead0.close;      
    end
%end Terminate

