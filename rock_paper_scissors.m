disp('A game of Rock-Paper-Scissors')
%Input player's choise
name=input('Make your move:','s');
%Create a numeric variable for player e.g. if
%player_name=='paper' then player_number=1
if strcmpi(name,'rock')
    player_number=2;
elseif strcmpi(name,'paper')
    player_number=1;
elseif strcmpi(name,'scissors')
    player_number=0;
else
	 error('myApp:argChk', 'Not a valid name, please choose only one of the three given superpowers.')
end
%Create a random number for the computer
computer_number=randi([0,2],1);
%Depending on the number, create a string value for computer's choise
if computer_number==0
    computer_name='Scissors';
elseif computer_number==1
    computer_name='Paper';
else
    computer_name='Rock';
end
%Compute the difference, make the comparison and find the winner
diff=mod(player_number-computer_number,3);
fprintf('Player chose %s \n Computer chose %s \n',name,computer_name)
if diff==2
    disp('Player Wins')
elseif diff==1
    disp('Computer Wins')
else
    disp('Draw')
end
disp('+++++++++++++++++++++++++++++++++++++++++++++')

%Created by Moysis Lazaros for the seminars 'An introduction to Matlab'
%in the Mathematics Dept. of Aristotle University of Thessaloniki

%This asssignment was inspired by the 1st week project
%of the course 'An introduction to interactive programming in Python'
%at coursera.org
