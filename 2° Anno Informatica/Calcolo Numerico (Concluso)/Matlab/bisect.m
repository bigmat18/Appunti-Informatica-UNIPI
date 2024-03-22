function [x, it] = bisect(f,a,b,tol)
ya=f(a);
yb=f(b);
err=b-a;
it=0;
while(err>tol)
    x=(a+b)/2;
    y=f(x);
    if (ya*y<=0)
        b=x;
        yb=y;
    else
        a=x;
        ya=y;
    end
end