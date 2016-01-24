function calculateDistance_sfun(block)

setup(block);

%endfunction
end

function setup(block)
disp('setup')

%% Register dialog parameters
block.NumDialogPrms  = 0;

%output is user compliances
%inputs are difference btw last and current distance, and userStatus
block.NumInputPorts  = 2;
block.NumOutputPorts = 1;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% agentState
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(1).SamplingMode = 'Sample';
%distanceD
block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(2).Complexity  = 'Real';
block.InputPort(2).DirectFeedthrough = true;
block.InputPort(2).SamplingMode = 'Sample';
%userCompliance
block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
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
  %dwork is used to save the current value of output
  block.NumDworks = 1;
  
  block.Dwork(1).Name            = 'v';
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
    agentState = block.InputPort(1).Data;
    distanceD = block.InputPort(2).Data;
    disp('agentState:');
    disp(agentState);
    if agentState>0 %agent point
        disp('agentstate is pointing');
           if distanceD >0   %user complies                 
               block.Dwork(1).Data =1;
               disp('user is compling');
           elseif distanceD <0
                block.Dwork(1).Data = -1;
                disp('user NOT compling');
           else
                disp('user stands still');
                block.Dwork(1).Data = block.Dwork(1).Data;
           end
    else
         disp('agentstate is NOT pointing');
         block.Dwork(1).Data = block.Dwork(1).Data;
    end
    

    compliance=block.Dwork(1).Data;
    block.OutputPort(1).Data = compliance;
 
%end Update
end

function Derivatives(block)

%end Derivatives
end

function Terminate(block)
 disp('Terminate')

end
%end Terminate

