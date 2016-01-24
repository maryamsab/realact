function yarpReadKinectAllPosition_sfun(block)
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
    block.NumOutputPorts = 3;

    % Setup port properties to be inherited or dynamic
    block.SetPreCompInpPortInfoToDynamic;
    block.SetPreCompOutPortInfoToDynamic;
    
    
    % Override output port properties
    % Joint Position (x, y, z)
    block.OutputPort(1).Dimensions   = 1;
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
    
%     jointsList ={ 'tag head', 'tag neck', 'tag spineshoulder', 'tag spinemid','tag spinebase', 'tag shoulderright', 'tag shoulderleft','tag hipright', 'tag hipleft', 'tag elbowright', 'tag wristright' ,'tag handright', 'tag handtipright', 'tag thumbright', 'tag elbowleft', 'tag wristleft', 'tag handleft', 'tag handtipleft', 'tag thumbleft',  'tag kneeright', 'tag ankleright','tag footright', 'tag kneeleft', 'tag ankleleft', 'tag footleft' };  
%     for jointID=1:length(jointsList)
        if(bottleIn.size()>0)
            item = bottleIn.get(0);     
            trackedItemJoint = item.find('joints');         
            %Position
            jointsString= char(trackedItemJoint);
            jointI = strfind(jointsString, 'tag wristright'); 
            if(jointI>0)          
                    JointStr=jointsString(jointI:jointI+108);
                    JointPositionI=strfind(JointStr, 'position'); %orientation
                    JointPositionStr=JointStr(JointPositionI+10:JointPositionI+35);
                    ss =(strsplit(JointPositionStr));
                    JointPositionX=str2double(ss(1));
                    JointPositionY=str2double(ss(2));
                    JointPositionZ=str2double(ss(3));  

                    block.OutputPort(1).Data = JointPositionX; 
                    block.OutputPort(2).Data = JointPositionY;
                    block.OutputPort(3).Data = JointPositionZ;
                 
            else
                    block.OutputPort(1).Data = 0; 
                    block.OutputPort(2).Data = 0;
                    block.OutputPort(3).Data = 0;
                    
            end    
            
%         %ORIENTATION:       
%         trackedItemJoint = trackedItemJoint.find('tag elbowright');
%         trackedJointCoordinate = trackedItemJoint.find('orientation');   
%         temp=char(trackedJointCoordinate);
%         if (~isempty(temp))
%             ss =(strsplit(temp));
%             
%             x=str2double(ss(1))*57;
%             y=str2double(ss(2))*57;
%             z=str2double(ss(3))*57;
%             w=str2double(ss(4))*57;
% 
%             block.OutputPort(1).Data = x; 
%             block.OutputPort(2).Data = y;
%             block.OutputPort(3).Data = z;
%             block.OutputPort(4).Data = w;
%         else
%             block.OutputPort(1).Data = 0; 
%             block.OutputPort(2).Data = 0;
%             block.OutputPort(3).Data = 0;
%             block.OutputPort(4).Data = 0;
%         end
% 
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

