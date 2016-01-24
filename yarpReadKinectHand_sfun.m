function yarpReadKinectHand_sfun(block)
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
    block.NumOutputPorts = 1;

    % Setup port properties to be inherited or dynamic
    block.SetPreCompInpPortInfoToDynamic;
    block.SetPreCompOutPortInfoToDynamic;

    % Override output port properties
    % will be the image number
    block.OutputPort(1).Dimensions       = 1;
    block.OutputPort(1).DatatypeID  = 0; % double
    block.OutputPort(1).Complexity  = 'Real';
    block.OutputPort(1).SamplingMode = 'sample';  

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
    block.NumDworks = 0;
  

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
        handS = item.find('righthand');  %open,closed,lasso    

        if(strcmp(handS,'open')==1)
                block.OutputPort(1).Data = 1; 
        elseif(strcmp(handS,'closed')==1)
                block.OutputPort(1).Data = 2; 
        elseif(strcmp(handS,'lasso')==1)
                block.OutputPort(1).Data = 0; 
        elseif(strcmp(handS,'unknown')==1)
                block.OutputPort(1).Data = 3;
        else
                block.OutputPort(1).Data =4;
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

