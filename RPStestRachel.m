function varargout = RPStestRachel(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @RPStestRachel_OpeningFcn, ...
    'gui_OutputFcn',  @RPStestRachel_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   @RPStestRachel_Callback);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end
if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function RPStestRachel_OpeningFcn(hObject, eventdata, handles, varargin)
    global test1;
    global test2;
    global test3;
    test1=0;
    test2=0;
    test3=0;
    handles.output = hObject;
    handles.timer = timer(...
        'ExecutionMode', 'fixedRate', ...       % Run timer repeatedly
        'Period', 1, ...                        % Initial period is 1 sec.
        'TimerFcn', {@update_display,hObject}); % Specify callback function
    guidata(hObject, handles);

function varargout = RPStestRachel_OutputFcn(hObject, eventdata, handles) 
    varargout{1} = handles.output;

function btnStart_Callback(hObject, eventdata, handles)
    %initial
    setappdata(0,'gameStatus',0); 
    setappdata(0,'bradHand',3); 
    setappdata(0,'userHand',3); 
    setappdata(0,'win',3);
    setappdata(0,'uTotal',0); 
    setappdata(0,'bTotal',0); 
    setappdata(0,'gameNum',1); 
    set(handles.txtReadyGo,'String','Ready'); 
    status = get_param(bdroot,'simulationstatus');
    if strcmp(status,'stopped')
        set_param(bdroot,'simulationcommand','start')
    end
    if strcmp(get(handles.timer, 'Running'), 'off')
        start(handles.timer);
    end
   

function btn_stop_Callback(hObject, eventdata, handles)

    set(handles.txtReadyGo,'String','Ready'); 
    status = get_param(bdroot,'simulationstatus');
    if strcmp(status,'running')
        set_param(bdroot, 'SimulationCommand', 'Stop')
    end
    if strcmp(get(handles.timer, 'Running'), 'on')
        stop(handles.timer);
    end
    
    
    function update_display(hObject,eventdata,hfigure)
    global test1;
    global test2;
    global test3;

    handles = guidata(hfigure);
    % Get the value of the txtRead, txtUserHand,txtAgentHand,txtWinner and update GUI
    guiUserHand= getappdata(0,'userHand');
    guiWin = getappdata(0,'win');
    guiGameStatus = getappdata(0,'gameStatus');
    guiBradHand = getappdata(0,'bradHand');
    guiuTotal = getappdata(0,'uTotal');
    guibTotal = getappdata(0,'bTotal');
    guiGameNum = getappdata(0,'gameNum');

    set(handles.txtGameNum,'String',num2str(guiGameNum));

    if(guiGameStatus==7 &&  test1==0) %Ready
        set(handles.txtReadyGo,'String','Ready');
        [y1,Fs1] = audioread('ready.mp3');
        sound(y1,Fs1);
        test1=1;
        test2=0;
        test3=0;
    elseif(guiGameStatus==1 && test2==0) %Go
        set(handles.txtReadyGo,'String','Go');
        [y,Fs] = audioread('go.mp3');
        sound(y,Fs);
        test1=0;
        test2=1;
        test3=0;
    elseif(guiGameStatus==2) %Results
        set(handles.txtReadyGo,'String','Results:');
        test1=0;
        test2=0;
        test3=0;
    elseif(guiGameStatus==3 && test3==0) %GameOver
        if(guiuTotal < guibTotal)
            set(handles.txtReadyGo,'String','You lost! :(');
            [y,Fs2] = audioread('lost.mp3');
            sound(y,Fs2);
        elseif(guiuTotal == guibTotal)
            set(handles.txtReadyGo,'String','Same Results! :|');
            [y,Fs3] = audioread('same.mp3');
            sound(y,Fs3);
        else
            set(handles.txtReadyGo,'String','You Won! :)');
            [y,Fs4] = audioread('won.mp3');
            sound(y,Fs4);
        end
        test3=1;
        test1=0;
        test2=0;
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
        set(handles.txtWinner,'String','Rachel');
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


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
