#include <stdio.h>
#include <stdlib.h>

extern int somma(int x, int *v, int n);

int main(void){

    int *v = malloc(4 * sizeof(int));

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[4] = 4;

    printf("%d\n", somma(3, v, 4));
    return 0;
}