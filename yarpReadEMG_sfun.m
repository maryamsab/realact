function yarpReadEMG_sfun(block)
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
    block.OutputPort(2).SamplingMode = 'sample';  
    
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
  block.Dwork(1).Name            = 'v';
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
    end
    block.Dwork(1).Data = 450;
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
        item = bottleIn.get(0).asDouble();   
        if(item>block.Dwork(1).Data)
            threshold= item/block.Dwork(1).Data;
        else
            threshold= block.Dwork(1).Data/item;
        end
        block.Dwork(1).Data = item;
        
        if(threshold>1.1)
            block.OutputPort(2).Data=2;
        else
            block.OutputPort(2).Data=1;
        end
        block.OutputPort(1).Data = item;

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

