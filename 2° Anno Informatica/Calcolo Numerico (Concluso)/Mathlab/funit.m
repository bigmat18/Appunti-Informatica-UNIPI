function [x] = funit(x0, tol, maxit)
g = @(x)cos(x);
err = inf;
i = 0;

while(err > tol & i <= maxit) 
    x = g(x0);
    err = abs(x - x0);
    i = i + 1;
    x0 = x;
end
end

function [x] = funit2(x0, tol, maxit)
g = @(x)cos(x)/(1+sin(x));
err = inf;
i = 0;

while(err > tol & i <= maxit) 
    x = g(x0);
    err = abs(x - x0);
    i = i + 1;
    x0 = x;
end
end