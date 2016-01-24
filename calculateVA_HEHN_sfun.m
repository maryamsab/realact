function calculateVA_HEHN_sfun(block)

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
block.NumInputPorts  = 7;
block.NumOutputPorts = 2;

% Setup port properties to be inherited or dynamic
block.SetPreCompInpPortInfoToDynamic;
block.SetPreCompOutPortInfoToDynamic;

% valence factor {interaction satisfaction,userSmile,userWave}
block.InputPort(1).Dimensions        = 1;
block.InputPort(1).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(1).Complexity  = 'Real';
block.InputPort(1).DirectFeedthrough = true;
block.InputPort(1).SamplingMode = 'Sample';

%arousal factor { interaction novelty, user invade space}
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

%triggerWeightV
block.InputPort(6).Dimensions        = 1;
block.InputPort(6).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(6).Complexity  = 'Real';
block.InputPort(6).DirectFeedthrough = true;
block.InputPort(6).SamplingMode = 'Sample';

%triggerWeightA
block.InputPort(7).Dimensions        = 1;
block.InputPort(7).DatatypeID  = 0;  % 8 for boolean,2 for 'int8',0 for double
block.InputPort(7).Complexity  = 'Real';
block.InputPort(7).DirectFeedthrough = true;
block.InputPort(7).SamplingMode = 'Sample';

block.OutputPort(1).Dimensions       = 1;
block.OutputPort(1).DatatypeID  = 0; % double
block.OutputPort(1).Complexity  = 'Real';
block.OutputPort(1).SamplingMode = 'sample';

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
    block.OutputPort(1).Data = 0; %V=s-/i-s/d-f
    block.OutputPort(2).Data = 0; %A=s-/i-s/d-f
    block.Dwork(1).Data = 0;
    block.Dwork(2).Data = 20;
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
    %N(t)=N0 * exp (decayRate * time)  --OR Xt = Xss - (Xss - X0)e-t/K
    %get simulation time for exponential function   
    rto=get_param('Expriment_All','SimulationTime');
    sTime=round(rto);
    LoWEdecayRate=1; %highN goes 5 times slower to steady-state than others

    MAX_V=100;%Valence curve cieling
    MAX_A=100;%Arousal curve cieling
    
    valenceTrigger = block.InputPort(1).Data;
    arousalTrigger = block.InputPort(2).Data; 
    DECAY = block.InputPort(3).Data; 
    B_FACTOR = block.InputPort(4).Data; 
    S_FACTOR = block.InputPort(5).Data;   
    triggerWeightV = block.InputPort(6).Data;
    triggerWeightA = block.InputPort(7).Data; 
    
    decayRate=LoWEdecayRate*DECAY;

    if valenceTrigger==1   %HEHN highly responsive to positive stimuli           
        if(block.Dwork(1).Data<MAX_V)
            block.Dwork(1).Data = block.Dwork(1).Data + (B_FACTOR*triggerWeightV); %V=s-/i-s/d-f
            %rate = 0.01;
        end   
    elseif valenceTrigger== -1 %HEHN highly responsive to negative stimuli
        if(block.Dwork(1).Data>(-1*MAX_V))
                 block.Dwork(1).Data = block.Dwork(1).Data - (B_FACTOR*triggerWeightV);  
                %rate = -0.01;
        end
    end  

    if arousalTrigger==1 %HEHN:highly aroused
        if(block.Dwork(2).Data<(MAX_A))
            block.Dwork(2).Data = block.Dwork(2).Data + (B_FACTOR*triggerWeightA); %A=s-/i-s/d-f
            %rate = 0.01;
        end   
    elseif arousalTrigger== -1 %HEHN:highly aroused
        if(block.Dwork(2).Data>(-1*MAX_A))
                 block.Dwork(2).Data = block.Dwork(2).Data - (S_FACTOR*triggerWeightA); 
                %rate = -0.01;
        end
    end  
    %HEHN initial state: A+ 
    %tendency for returning to initial is  X=Xss - (Xss - X0)e-t/K
    %Xss is the value when time=infit, 
    %X0 is the initial so each time V and A change we set it to current
    %value of V and A and start the decay from there
    %based on http://www.hpmuseum.org/software/33/33expgd.htm     
    block.Dwork(1).Data = (block.Dwork(1).Data)*exp(decayRate*sTime); 
    block.Dwork(2).Data = 20 -((20 -block.Dwork(2).Data)*exp(decayRate*sTime)); 
    A=block.Dwork(2).Data;
    V=block.Dwork(1).Data;
 
    block.OutputPort(1).Data = V;
    block.OutputPort(2).Data = A;
%     fprintf('valenceTrigger,triggerWeightV,V: %0.0f,%0.2f,%0.2f\r\n',valenceTrigger,triggerWeightV,V);
 
%end Update
end

function Derivatives(block)

%end Derivatives
end

function Terminate(block)
 disp('Terminate')

end
