function yarpReadKinectHeadP_sfun(block)
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
    block.NumOutputPorts = 5;

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
    
    block.OutputPort(3).Dimensions       = 1;
    block.OutputPort(3).DatatypeID  = 0; % double
    block.OutputPort(3).Complexity  = 'Real';
    block.OutputPort(3).SamplingMode = 'sample';
    
    block.OutputPort(4).Dimensions       = 1;
    block.OutputPort(4).DatatypeID  = 0; % double
    block.OutputPort(4).Complexity  = 'Real';
    block.OutputPort(4).SamplingMode = 'sample';
    
    block.OutputPort(5).Dimensions       = 1;
    block.OutputPort(5).DatatypeID  = 0; % double
    block.OutputPort(5).Complexity  = 'Real';
    block.OutputPort(5).SamplingMode = 'sample';
    block.SampleTimes = [0, 0]; %simulation sample time is 0.01[-1, 0]

    block.SimStateCompliance = 'DefaultSimState';

    block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
    block.RegBlockMethod('InitializeConditions', @InitializeConditions);
    block.RegBlockMethod('Start', @Start);
    block.RegBlockMethod('Outputs', @Outputs);     % Required
    block.RegBlockMethod('Update', @Update);
    block.RegBlockMethod('Derivatives', @Derivatives);
    block.RegBlockMethod('Terminate', @Terminate); % Required
disp('end_setup')

function DoPostPropSetup(block)
disp('doPost');
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
    if(bottleIn.size()>0)
        item = bottleIn.get(0);    
        disp('portsize more than zero');     
    end
    block.Dwork(1).Data = 0;
    %end InitializeConditions

function Start(block)
    disp('Start')

function Outputs(block)
%end Outputs

function Update(block)
disp('update');
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
                    headPositionZ=str2double(ss(3))*100;  
                    
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

                    block.OutputPort(1).Data = headPositionX; 
                    block.OutputPort(2).Data = headPositionY;
                    block.OutputPort(3).Data = headPositionZ;
                    block.OutputPort(4).Data = handRUp;
                    block.OutputPort(5).Data = handLUp;
%         else
%                 disp('zero input');
%                 block.OutputPort(1).Data = 0; 
%                 block.OutputPort(2).Data = 0;
%                 block.OutputPort(3).Data = 0;   
%                 block.OutputPort(4).Data = 0;  
%                 block.OutputPort(5).Data = 0;  
                end
            end
        end
    
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

