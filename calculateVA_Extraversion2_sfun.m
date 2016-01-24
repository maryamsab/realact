function calculateVA_Extraversion2_sfun(block)
%Maryam 30/06/2015
%this function is to calculate arousal and valence of 
%HighExtrovert based on satisfaction from the interaction,
%how aroused she is and decay rate of them as time passes.

setup(block);

%endfunction
end

function setup(block)
disp('setup')

%% Register dialog parameters
block.NumDialogPrms  = 0;

% outputs are valence and arousal 
%inputs are user's compliance and old compliance 
%compliance is calulated by simulink chart comparing last and current distance
block.NumInputPorts  = 5;
block.NumOutputPorts = 2;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% satisfaction/valence
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(1).SamplingMode = 'Sample';

%arousal
block.InputPort(2).Dimensions        = 1;
block.InputPort(2).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(2).Complexity  = 'Real';
block.InputPort(2).DirectFeedthrough = true;
block.InputPort(2).SamplingMode = 'Sample';

%decay
block.InputPort(3).Dimensions        = 1;
block.InputPort(3).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(3).Complexity  = 'Real';
block.InputPort(3).DirectFeedthrough = true;
block.InputPort(3).SamplingMode = 'Sample';

%B_FACTOR
block.InputPort(4).Dimensions        = 1;
block.InputPort(4).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(4).Complexity  = 'Real';
block.InputPort(4).DirectFeedthrough = true;
block.InputPort(4).SamplingMode = 'Sample';

%S_FACTOR
block.InputPort(5).Dimensions        = 1;
block.InputPort(5).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(5).Complexity  = 'Real';
block.InputPort(5).DirectFeedthrough = true;
block.InputPort(5).SamplingMode = 'Sample';

%Valence
block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0; % double
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'sample';

%Arousal
block.OutputPort(2).Dimensions       = 1;
block.OutputPort(2).DatatypeID  = 0; % double
block.OutputPort(2).Complexity  = 'Real';
block.OutputPort(2).SamplingMode = 'Sample';

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
  %dwork is used to save the current value of valence and arousal
  block.NumDworks = 2;
  
  block.Dwork(1).Name            = 'v';
  block.Dwork(1).Dimensions      = 1;
  block.Dwork(1).DatatypeID      = 0;      % double
  block.Dwork(1).Complexity      = 'Real'; % real
  block.Dwork(1).UsedAsDiscState = true;
  
  block.Dwork(2).Name            = 'a';
  block.Dwork(2).Dimensions      = 1;
  block.Dwork(2).DatatypeID      = 0;      % double
  block.Dwork(2).Complexity      = 'Real'; % real
  block.Dwork(2).UsedAsDiscState = true;

 end

function InitializeConditions(block)
disp('InitializeConditions')
block.OutputPort(1).Data = 1;%V=s+/i-f/d-s, A=s+/i-f/d-s
block.OutputPort(2).Data = 1; 
block.Dwork(1).Data = 1;%initial value
block.Dwork(2).Data = 1; 
% end
%end InitializeConditions
end

function Start(block)
  disp('Start')
%end Start
end

function Outputs(block)

%end Outputs
end

function Update(block)
    %Decay rate is calculate from the following:
    %N(t)=N0 * exp (decayRate * time)  --OR Xt = Xss - (Xss - X0)e-t/K
    
    %get simulation time for exponential function   
    rto=get_param('ARP_02_PointUser_AnTS','SimulationTime');
    sTime=round(rto); 
    HighEdecayRate=1; %this is for HighE and HighN (LowN goes faster to steady-state than others)
 
    MAX_V=20;%Valence curve cieling
    MAX_A=20;%Arousal curve cieling
    
    satisfaction = block.InputPort(1).Data;%agent satisfaction
    arousal = block.InputPort(2).Data; 
    DECAY = block.InputPort(3).Data; 
    B_FACTOR = block.InputPort(4).Data; 
    S_FACTOR = block.InputPort(5).Data; 
    
    decayRate=HighEdecayRate*DECAY;
    if satisfaction==1   %agent is satisfied (user compling or agent wining)
        if(block.Dwork(1).Data<20)%emotion changes btw 20,-20
                block.Dwork(1).Data = block.Dwork(1).Data + B_FACTOR; %V=s+/i-f/d-s
         end
    elseif satisfaction== -1 %agent is not satisfied (user is not complying or agent loosing)
        if(block.Dwork(1).Data>(-1*MAX_V))
                block.Dwork(1).Data = block.Dwork(1).Data - S_FACTOR; 
                %rate = -0.05;
        end
    end  
    if arousal==1    %interaction exiting 
        if(block.Dwork(2).Data<MAX_A)%emotion changes btw 20,-20
                block.Dwork(2).Data = block.Dwork(2).Data + B_FACTOR; %A=s+/i-f/d-s
         end
    elseif arousal== -1  %interaction NOT exiting 
        if(block.Dwork(2).Data>(-1*MAX_A))
                block.Dwork(2).Data = block.Dwork(2).Data - S_FACTOR; 
                %rate = -0.05;
        end
    end
    
    block.Dwork(1).Data = 1 -((1 -block.Dwork(1).Data)*exp(decayRate*sTime));
    block.Dwork(2).Data = 1 -((1 -block.Dwork(2).Data)*exp(decayRate*sTime));
    
    A=block.Dwork(2).Data;
    V=block.Dwork(1).Data;     
 
    block.OutputPort(1).Data = V;
    block.OutputPort(2).Data = A;
 
%end Update
end

function Derivatives(block)
%end Derivatives
end

function Terminate(block)
 disp('Terminate')
end
%end Terminate
