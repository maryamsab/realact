function yarpReadKinectSendBMLs_sfun(block)
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
    if(bottleIn.size()>0)
        item = bottleIn.get(0);      
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
         disp('------new bottle------');
         jointsList ={ 'tag head','tag neck', 'tag spineshoulder', 'tag spinemid','tag spinebase', 'tag shoulderright', 'tag shoulderleft','tag hipright', 'tag hipleft', 'tag elbowright', 'tag wristright' ,'tag handright', 'tag handtipright', 'tag thumbright', 'tag elbowleft', 'tag wristleft', 'tag handleft', 'tag handtipleft', 'tag thumbleft',  'tag kneeright', 'tag ankleright','tag footright', 'tag kneeleft', 'tag ankleleft', 'tag footleft' };  
         item = bottleIn.get(0);                     
         for jointID=1:length(jointsList)  
            jointTag= jointsList(jointID);          
            disp('--------jointTg:------');
            disp(jointID);
            disp(jointTag);
            %ORIENTATION:
            trackedItemJoint = item.find('joints'); 
            disp('joints:');
            disp(trackedItemJoint);
            trackedItemJointT = trackedItemJoint.find(jointTag);
            disp('tag:');
            disp(trackedItemJointT);
            trackedJointCoordinate = trackedItemJointT.find('orientation');   
            temp=char(trackedJointCoordinate);
            disp('temp coord:');
            disp(temp);
            if (~isempty(temp))
                ss =(strsplit(temp));
                x=str2double(ss(1));
                y=str2double(ss(2));
                z=str2double(ss(3));
                w=str2double(ss(4));
                disp(x);
                disp(y);
                disp(z);
                disp(w);
                block.OutputPort(1).Data = jointID; 
                block.OutputPort(2).Data = x; 
                block.OutputPort(3).Data = y;
                block.OutputPort(4).Data = z;
                block.OutputPort(5).Data = w;
            else
                disp('in else');
                block.OutputPort(1).Data = jointID; 
                block.OutputPort(2).Data = 0;
                block.OutputPort(3).Data = 0;
                block.OutputPort(4).Data = 0;
                block.OutputPort(5).Data = 0;
            end
         end
    end
%     end
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

