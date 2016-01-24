function num = countDigits( x )
num=0;
    if x<0
        num=num+1;
        x=abs(x);
    end    
    if (x>0) && (x<9)
            num=num+1;
        elseif (x>10) && (x<99)
            num=num+2;
        elseif (x>100) && (x<999)
            num=num+3;
    end
end



