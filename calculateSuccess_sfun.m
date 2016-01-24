function calculateSuccess_sfun(block)
%distance between user's position and target
setup(block);

%endfunction
end

function setup(block)
disp('setup')

%% Register dialog parameters
block.NumDialogPrms  = 0;

% inputs: x,y for user position; x,y for target are inputs
% outputs: xd for direction of movements and calculated distance
block.NumInputPorts  = 4;
block.NumOutputPorts = 1;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% Override input port properties
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DatatypeID  = 0;  % 2 for 'int8',
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(1).SamplingMode = 'Sample';

block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DatatypeID  = 0;  % 2 for 'int8',
block.InputPort(2).Complexity  = 'Real';
block.InputPort(2).DirectFeedthrough = true;
block.InputPort(2).SamplingMode = 'Sample';

block.InputPort(3).Dimensions        = 1;
block.InputPort(3).DatatypeID  = 0;  % 2 for 'int8',
block.InputPort(3).Complexity  = 'Real';
block.InputPort(3).DirectFeedthrough = true;
block.InputPort(3).SamplingMode = 'Sample';

block.InputPort(4).Dimensions        = 1;
block.InputPort(4).DatatypeID  = 0;  % 2 for 'int8',
block.InputPort(4).Complexity  = 'Real';
block.InputPort(4).DirectFeedthrough = true;
block.InputPort(4).SamplingMode = 'Sample';

block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0; % double
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'sample';

block.SampleTimes = [-1, 0];

block.SimStateCompliance = 'DefaultSimState';

block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
block.RegBlockMethod('InitializeConditions', @InitializeConditions);
block.RegBlockMethod('Start', @Start);
block.RegBlockMethod('Outputs', @Outputs);     % Required
block.RegBlockMethod('Update', @Update);
block.RegBlockMethod('Derivatives', @Derivatives);
block.RegBlockMethod('Terminate', @Terminate); % Required

%end setup
end

function DoPostPropSetup(block)
  block.NumDworks = 1;
  
  block.Dwork(1).Name            = 'x';
  block.Dwork(1).Dimensions      = 1;
  block.Dwork(1).DatatypeID      = 0;      % double
  block.Dwork(1).Complexity      = 'Real'; % real
  block.Dwork(1).UsedAsDiscState = true;

 end

function InitializeConditions(block)
disp('InitializeConditions')
%end InitializeConditions
end

function Start(block)
disp('Start')
block.Dwork(1).Data = 0;

%end Start
end

function Outputs(block)

%end Outputs
end


function Update(block)

 trackedItemXpos = block.InputPort(1).Data;
 trackedItemYpos = block.InputPort(2).Data;
 targetXpos = block.InputPort(3).Data;
 targetYpos = block.InputPort(4).Data;

 xd = targetXpos - trackedItemXpos;
 yd = targetYpos - trackedItemYpos;

% distance = sqrt(xd.^2 + yd.^2);
 distance = sqrt(xd.^2);
 block.OutputPort(1).Data = distance;

%end Update
end

function Derivatives(block)
%end Derivatives
end

function Terminate(block)
 disp('Terminate')
end
%end Terminate

