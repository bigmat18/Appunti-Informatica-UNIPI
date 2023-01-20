#include <stdio.h>
#include <stdlib.h>

extern void map(int *A, int n, int value);


int main(void){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("\n[%d", a[0]);
    for(int i=1; i<9; i++){
        printf(", %d", a[i]);
    }
    printf(", %d]\n", a[9]);

    map(a, 10, 4);

    printf("\n[%d", a[0]);
    for(int i=1; i<9; i++){
        printf(", %d", a[i]);
    }
    printf(", %d]\n", a[9]);

    return 0;
}