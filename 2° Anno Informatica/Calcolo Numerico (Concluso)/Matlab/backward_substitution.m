function[x]=backward_substitution(a,b)
    n=length(b);
    x = zeros(n,1);
    for k=n:1
        s=0;
        for j=k+1:n
            s=s+a(k,j)*x(j);
        end
    x(k)=(b(k)-s)/a(k,k);
    end