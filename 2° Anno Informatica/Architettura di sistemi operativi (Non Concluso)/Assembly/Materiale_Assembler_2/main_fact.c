#include<stdio.h>
#include<stdlib.h>

extern unsigned int fact(unsigned int);

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);

    printf("fact(%d)=%d\n", a, fact(a));
    return 0;
}
