#include <stdio.h>
#include <stdlib.h>

extern int reduce(unsigned int *A, unsigned int n);

int main(void){
    int n = 10;
    int A[10] = {1, 2, 5, 2, 0, 1, 3, 5, 9, 2};

    printf("Reduce: %d", reduce(A, n));
}