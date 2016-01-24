function calculateVA_LELN_sfun(block)

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

% satisfaction
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

%decayRate
block.InputPort(3).Dimensions = 1;
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

%triggerWeight
block.InputPort(6).Dimensions        = 1;
block.InputPort(6).DatatypeID  = 0; 
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
  block.OutputPort(1).Data = 0;%V=s+/i-f/d-s
  block.OutputPort(2).Data = -10; %A=s-/i-s/d-f
  block.Dwork(1).Data = 0;%initial value
  block.Dwork(2).Data = -10;
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
    LowNdecayRate=1; %LN goes faster to steady-state than others 
    
    MAX_V=100;%Valence curve cieling
    MAX_A=100;%Arousal curve cieling
    
    valenceTrigger = block.InputPort(1).Data;
    arousalTrigger = block.InputPort(2).Data; 
    DECAY = block.InputPort(3).Data; 
    B_FACTOR = block.InputPort(4).Data; 
    S_FACTOR = block.InputPort(5).Data; 
    triggerWeightV = block.InputPort(6).Data; 
    triggerWeightA = block.InputPort(7).Data; 
    decayRate=LowNdecayRate*DECAY;
    
    if valenceTrigger==1   %LELN low response to positive stimuli    
            %Low-neurotosicm
            if(block.Dwork(1).Data<MAX_V)
                block.Dwork(1).Data = block.Dwork(1).Data + (S_FACTOR*triggerWeightV); %V=s+/i-f/d-s
                %rate = 0.05;
            end
    elseif valenceTrigger== -1 %LELN low response to negative stimuli   
        if(block.Dwork(1).Data>(-1*MAX_V))
                 block.Dwork(1).Data = block.Dwork(1).Data - (S_FACTOR*triggerWeightV); 
        end  
    end    
    if arousalTrigger==1   %LELN low aroused   
            %Low-neurotosicm            
            if(block.Dwork(2).Data<MAX_A)             
                block.Dwork(2).Data = block.Dwork(2).Data + (S_FACTOR*triggerWeightA); %A=s-/i-s/d-f
                %rate = 0.05;
                
            end
    elseif arousalTrigger== -1  %LELN low aroused     
        if(block.Dwork(2).Data>(-1*MAX_A))

                block.Dwork(2).Data = block.Dwork(2).Data - (B_FACTOR*triggerWeightA);
        end  
    end
    %LELN initial A-  
    %tendency for returning to initial is  X=Xss - (Xss - X0)e-t/K
    %based on http://www.hpmuseum.org/software/33/33expgd.htm, check bellow
     block.Dwork(1).Data = (block.Dwork(1).Data)*exp(decayRate*sTime); 
     block.Dwork(2).Data = -10 -((-10 -block.Dwork(2).Data)*exp(decayRate*sTime)); 

     V=block.Dwork(1).Data;     
     A=block.Dwork(2).Data;
     
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

% Exponential Growth or Decay for the HP-33E/C
% Many growth or decay phenomena encountered in science and engineering obey an exponential 
% law of the general form:
% Xt = Xss - (Xss - X0)e-t/K
% where:
% Xt = Value at any time, t, (i.e., the instantaneous value)
% Xss = Steady state value (i.e., at t = infinity)
% X0 = Initial Value (i.e., at t = 0)
% t = Elapsed time (time after t = 0)
% K= Exponential time-constant for specific phenomena
% This program provides interchangeable solutions for any one of the four variables Xt, 
% Xss, X0, or t provided three variables and K are known.
