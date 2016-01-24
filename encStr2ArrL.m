function [ myarr356 ] = encStr2ArrL( mystr )
%coder.varsize('myarr256', [256 1], 2);
coder.varsize('myarr356', [356, 1], [0 0])
maxarrsize = 356;
%mystr = 'this is a very long string that we want to send around to some other place on a different planet';
arr = double(mystr)';
ss = size(arr, 1);
padsize = maxarrsize - ss;
tt = zeros(356, 1);
tt(1:ss, 1) = arr; %padarray would be the function, but crashes...
myarr356 = tt(1:356,1);
end

