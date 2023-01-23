#include <stdio.h>
#include <stdlib.h>

extern int fattoriale(int n);

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);

    printf("fact(%d) = %d\n", a, fattoriale(a));
}