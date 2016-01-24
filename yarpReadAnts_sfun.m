function yarpReadAnts_sfun(block)
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
    block.NumOutputPorts = 2;

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
    block.OutputPort(2).SamplingMode = 'Sample';
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
    global yportRead;
    yportRead=Port;
    strPortNameWrite = block.DialogPrm(1).Data;
    strPortNameRead = block.DialogPrm(2).Data;
    assert (size(strPortNameWrite,2)<16)
    assert (size(strPortNameRead,2)<16)
    sprintf('Going to open port %s', strPortNameRead);
    yportRead.open(strPortNameRead);
    Network.connect(strPortNameWrite, strPortNameRead);
    bottleIn=Bottle;
    yportRead.read(bottleIn);
    if(bottleIn.size()>0)
        item = bottleIn.get(0);      
        trackedItemXpos = item.find('x');
        trackedItemYpos = item.find('y');   
        block.OutputPort(1).Data = trackedItemXpos.asDouble();
        block.OutputPort(2).Data = trackedItemYpos.asDouble();
    end
    block.Dwork(1).Data = 0;
    %end InitializeConditions

function Start(block)
    disp('Start')

% LoadYarp;
% import yarp.Port;
% import yarp.Bottle;
% import yarp.Network;
% 
% global yportRead;
% 
% yportRead=Port;
% %strPortNameWrite = '/testSender'
% %strPortNameRead = '/simulink/in';
% 
% strPortNameWrite = block.DialogPrm(1).Data;
% strPortNameRead = block.DialogPrm(2).Data;
% 
% assert (size(strPortNameWrite,2)<16)
% assert (size(strPortNameRead,2)<16)
% 
% sprintf('Going to open port %s', strPortNameRead);
% 
% yportRead.open(strPortNameRead);
% 
% Network.connect(strPortNameWrite, strPortNameRead);
% 
% block.Dwork(1).Data = 0;

%end Start

function Outputs(block)
%end Outputs

function Update(block)
    import yarp.Bottle;
    global yportRead;

    bottleIn=Bottle;
    yportRead.read(bottleIn);

    if(bottleIn.size()>0)
        item = bottleIn.get(0);     
        trackedItemXpos = item.find('x');
        trackedItemYpos = item.find('y');   
        block.OutputPort(1).Data = trackedItemXpos.asDouble();
        block.OutputPort(2).Data = trackedItemYpos.asDouble();
end
%end Update

function Derivatives(block)
%end Derivatives

function Terminate(block)
    disp('Terminate')

    global yportRead;

    if exist('yportRead', 'var')
         yportRead.close;      
    end
%end Terminate

