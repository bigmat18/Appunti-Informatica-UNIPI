#include <stdio.h>
#include <stdlib.h>

extern int counter(unsigned int *A, unsigned int n, unsigned int v);

int main(int argc, char *argv[]){
    int n = 10;
    int a[10] = {1, 3, 4, 1, 3, 5, 1, 3, 1, 1};

    printf("\n[%d", a[0]);
    for(int i=1; i<9; i++){
        printf(", %d", a[i]);
    }
    printf("%d]\n", a[9]);

    int v = atoi(argv[1]);
    printf("numeri uguali ad %d: %d\n",v, counter(a, n, v));
    return 0;
}