function [xnew, it] = myjacobi(a,b,tol, maxit)
n = length(b);
xold=zeros(n,1);
err=inf;
dd=diag(diag(a)); it=0;
while(err>tol && it<=maxit)
	xnew=dd\((dd-a)*xold+b);
	err=norm(xnew-xold, inf);
	it=it+1;
	xold=xnew;
end
end