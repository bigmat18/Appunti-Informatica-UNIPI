#include<stdio.h>
#include<stdlib.h>

extern int fun(int, int);

int main(int argc, char ** argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("fun(%d,%d)=%d\n", a, b, fun(a,b));
    return 0;
}
