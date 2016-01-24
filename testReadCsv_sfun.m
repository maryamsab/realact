function testReadCsv_sfun(block)
%%
%% read value from sensor
%% 
setup(block);

function setup(block)
    disp('setup')

    %% Register dialog parameters
    block.NumDialogPrms  = 0; %VARIABLE NAME(s)

    % Register number of ports
    block.NumInputPorts  = 0;
    block.NumOutputPorts = 8; 

    % Setup port properties to be inherited or dynamic
    block.SetPreCompInpPortInfoToDynamic;
    block.SetPreCompOutPortInfoToDynamic;
    
    
    % Override output port properties
    % Joint Position (x, y, z)
    block.OutputPort(1).Dimensions   = 1;
    block.OutputPort(1).DatatypeID  = 0; %double
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
    
    block.OutputPort(6).Dimensions       = 1;
    block.OutputPort(6).DatatypeID  = 0; % double
    block.OutputPort(6).Complexity  = 'Real';
    block.OutputPort(6).SamplingMode = 'sample';
    
    block.OutputPort(7).Dimensions       = 1;
    block.OutputPort(7).DatatypeID  = 0; % double
    block.OutputPort(7).Complexity  = 'Real';
    block.OutputPort(7).SamplingMode = 'sample';
    
    block.OutputPort(8).Dimensions       = 1;
    block.OutputPort(8).DatatypeID  = 0; % double
    block.OutputPort(8).Complexity  = 'Real';
    block.OutputPort(8).SamplingMode = 'sample';
    
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
    block.NumDworks = 2;  
    block.Dwork(1).Name            = 'x1';
    block.Dwork(1).Dimensions      = 1;
    block.Dwork(1).DatatypeID      = 0;      % double
    block.Dwork(1).Complexity      = 'Real'; % real
    block.Dwork(1).UsedAsDiscState = true;

    block.Dwork(2).Name            = 'x2';
    block.Dwork(2).Dimensions      = 1;
    block.Dwork(2).DatatypeID      = 0;      % double
    block.Dwork(2).Complexity      = 'Real'; % real
    block.Dwork(2).UsedAsDiscState = true;

function InitializeConditions(block)
    disp('InitializeConditions')
    block.Dwork(1).Data = 1;
    block.Dwork(2).Data = 1;
    %end InitializeConditions

function Start(block)
    disp('Start')

function Outputs(block)
%end Outputs

function Update(block)     
%    mocapList={'Hips','Spine','Spine1','Spine2','Spine3','Neck','Head','RightShoulder','RightArm','RightForeArm','RightHand','RightHandEnd','RightHandThumb1','RightHandThumb1','RightLeg','RightFoot','RightToeBase'};                  
   walkQuat = csvread('quat3.csv',0,0);    %M = csvread(filename,R1,C1)
   [row,col]=size(walkQuat);
   if(row~=0)         
        walkQuatC = block.Dwork(1).Data;
        walkQuatR = block.Dwork(2).Data;
        

        %if it is root, then read the positon (first 3 cols)
        if walkQuatC==1
            block.OutputPort(6).Data =  walkQuat(walkQuatR,1);
            block.OutputPort(7).Data =  walkQuat(walkQuatR,2);
            block.OutputPort(8).Data =  walkQuat(walkQuatR,3);
            walkQuatC = 4;
            tagID = 1;
        else
            tagID     = walkQuatC/4;
        end
        %1,3,2,4            
        block.OutputPort(5).Data = tagID;  %tagID: in simulink it is connected to first input of sendSmartbody.m
        block.OutputPort(1).Data = walkQuat(walkQuatR,walkQuatC); %w
        block.OutputPort(2).Data = -1* walkQuat(walkQuatR,1+walkQuatC); %x
        block.OutputPort(3).Data = -1* walkQuat(walkQuatR,2+walkQuatC); %y
        block.OutputPort(4).Data = -1* walkQuat(walkQuatR,3+walkQuatC); %z
        
        disp(block.OutputPort(1).Data );
        disp(block.OutputPort(2).Data );
        disp(block.OutputPort(3).Data );
        disp(block.OutputPort(4).Data );
        disp(block.OutputPort(5).Data );
        disp(block.OutputPort(6).Data );
        disp(block.OutputPort(7).Data );
        disp(block.OutputPort(8).Data );
        disp('------------------------------');
        
        if(block.Dwork(1).Data<107) %27*4 + 3
            if walkQuatC==4
                block.Dwork(1).Data=block.Dwork(1).Data+7; %column count
            else
                block.Dwork(1).Data=block.Dwork(1).Data+4; %column count
            end
        else
           block.Dwork(1).Data=1;
           block.Dwork(2).Data=block.Dwork(2).Data+1; %row count
        end     
   else
        disp('in else');
        block.OutputPort(1).Data = 0;
        block.OutputPort(2).Data = 0;
        block.OutputPort(3).Data = 0;
        block.OutputPort(4).Data = 0;
        block.OutputPort(5).Data = 0;
         block.OutputPort(6).Data = 0;
          block.OutputPort(7).Data = 0;
           block.OutputPort(8).Data = 0;
   end   
    
%end Update

function Derivatives(block)
%end Derivatives

function Terminate(block)
    disp('Terminate')
%end Terminate

