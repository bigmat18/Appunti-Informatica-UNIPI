#include<stdio.h>
#include<stdlib.h>

extern unsigned int mydiv(unsigned int, unsigned int);

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("div(%d, %d)=%d\n", a, b, mydiv(a, b));
    return 0;
}
