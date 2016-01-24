function varargout = RPStest(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @RPStest_OpeningFcn, ...
    'gui_OutputFcn',  @RPStest_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   @RPStest_Callback);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end
if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function RPStest_OpeningFcn(hObject, eventdata, handles, varargin)
    %flags to make sure each state only is announced once per iteration
    global goFlag; 
    global resultFlag;
    global readyFlag;
    goFlag=0;
    resultFlag=0;
    readyFlag=0;
    handles.output = hObject;
    handles.timer = timer(...
        'ExecutionMode', 'fixedRate', ...       % Run timer repeatedly
        'Period', 1, ...                        % Initial period is 1 sec.
        'TimerFcn', {@update_display,hObject}); % Specify callback function
    guidata(hObject, handles);

function varargout = RPStest_OutputFcn(hObject, eventdata, handles)
    varargout{1} = handles.output;

function btnStart_Callback(hObject, eventdata, handles)
    %initial value for gui txts
    %setappdata(0,'gameStatus',0); %says ready too soon
    setappdata(0,'bradHand',3); %?
    setappdata(0,'userHand',3); %?
    setappdata(0,'win',3); %no-one
    setappdata(0,'uTotal',0); 
    setappdata(0,'bTotal',0); 
    setappdata(0,'gameNum',1);     
    
    set(handles.txtReadyGo,'String','Ready'); %inital txt value
    
    status = get_param(bdroot,'simulationstatus');
    if strcmp(status,'stopped')
        set_param(bdroot,'simulationcommand','start')
    end
    if strcmp(get(handles.timer, 'Running'), 'off')
        start(handles.timer);
    end

function btnStop_Callback(hObject, eventdata, handles)
    set(handles.txtReadyGo,'String','Ready');
    status = get_param(bdroot,'simulationstatus');
    if strcmp(status,'running')
        set_param(bdroot, 'SimulationCommand', 'Stop')
    end
    if strcmp(get(handles.timer, 'Running'), 'on')
        stop(handles.timer);
    end

function update_display(hObject,eventdata,hfigure)
%Game states are: STATE_READY=0;STATE_GO=1;STATE_HAND=2;STATE_OVER=3;
% STATE_BEFORE=4;  STATE_RESULT=5;STATE_WAIT=6;    

%Flags to only announce the game's state once in each iteration: 
    global readyFlag; %readyFlag
    global goFlag; %goFlag
    global resultFlag; %resultFlag
    handles = guidata(hfigure);
    % Get the value of the txtRead, txtUserHand,txtAgentHand,txtWinner and update GUI
    guiUserHand= getappdata(0,'userHand');
    guiWin = getappdata(0,'win');
    guiGameStatus = getappdata(0,'gameStatus');
    guiBradHand = getappdata(0,'bradHand');
    guiuTotal = getappdata(0,'uTotal');
    guibTotal = getappdata(0,'bTotal');
    guiGameNum = getappdata(0,'gameNum');
    set(handles.gameNum,'String',num2str(guiGameNum));
    if(guiGameStatus==7 & readyFlag==0) %Ready
        disp(guiGameStatus);
        set(handles.txtReadyGo,'String','Ready');
        [y1,Fs1] = audioread('ready.mp3');
        sound(y1,Fs1);     
        readyFlag=1;
        goFlag=0;
        resultFlag=0;  
    elseif(guiGameStatus==1 & goFlag==0) %Go
        set(handles.txtReadyGo,'String','Go');
        [y,Fs] = audioread('go.mp3');
        sound(y,Fs);       
        readyFlag=0;
        goFlag=1;
        resultFlag=0;
    elseif(guiGameStatus==5) %Results
        set(handles.txtReadyGo,'String','Results:');     
        readyFlag=0;
        goFlag=0;
        resultFlag=0; 
    elseif(guiGameStatus==3 & resultFlag==0) %GameOver
        if(guiuTotal < guibTotal)
            set(handles.txtReadyGo,'String','You lost! :(');
            [y,Fs2] = audioread('lost.mp3');
            sound(y,Fs2);
        elseif(guiuTotal == guibTotal)
            set(handles.txtReadyGo,'String','Same Results!');
            [y,Fs3] = audioread('same.mp3');
            sound(y,Fs3);
        else
            set(handles.txtReadyGo,'String','You Won! :)');
            [y,Fs4] = audioread('won.mp3');
            sound(y,Fs4);
        end
        resultFlag=1;
        readyFlag=0;
        goFlag=0;
    end

    if(guiBradHand==0)
        set(handles.txtAgentHand,'String','Scissors');
    elseif(guiBradHand==1)
        set(handles.txtAgentHand,'String','Paper');
    elseif(guiBradHand==2)
        set(handles.txtAgentHand,'String','Rock');
    else
        set(handles.txtAgentHand,'String','?');
    end

    if(guiUserHand==0)
        set(handles.txtUserHand,'String','Scissors');
    elseif(guiUserHand==1)
        set(handles.txtUserHand,'String','Paper');
    elseif(guiUserHand==2)
        set(handles.txtUserHand,'String','Rock');
    else
        set(handles.txtUserHand,'String','?');
    end

    if(guiWin==1)
        set(handles.txtWinner,'String','You');
    elseif(guiWin==2)
        set(handles.txtWinner,'String','Brad');
    else
        set(handles.txtWinner,'String','No-One');
    end
    set(handles.txtUserTotal,'String',num2str(guiuTotal));
    set(handles.txtAgentTotal,'String',num2str(guibTotal));

function figure1_CloseRequestFcn(hObject, eventdata, handles)
if strcmp(get(handles.timer, 'Running'), 'on')
    stop(handles.timer);
end
delete(hObject);
function figure1_CreateFcn(hObject, eventdata, handles)
function figure1_DeleteFcn(hObject, eventdata, handles)
function btnStop_ButtonDownFcn(hObject, eventdata, handles)
