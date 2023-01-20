#include <stdio.h>
#include <stdlib.h>

extern int somma(int a, int b);
extern int divisione(int a, int b);

int main(int argc, char *argv[]){

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("%d + %d = %d\n", a, b, somma(a,b));
    printf("%d / %d = %d\n", a, b, divisione(a, b));
}