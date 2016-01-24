function [ mystr ] = decArr2StrL( myarr356 )
%decoding
mystr = char(myarr356(myarr356 ~= 0)');
end

