#include<stdio.h>
#include<stdlib.h>

extern void vect_scalar(int *, int, int);

int main(int argc, char **argv)
{
    int i=0;
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Vettore iniziale: [");
    for(i=0; i<8; i++) {
        printf("%d ", array[i]);
    }
    printf("%d]\n", array[8]);

    int x = 3;

    vect_scalar(array, x, 9);

    printf("Vettore finale: [");
    for(i=0; i<8; i++) {
        printf("%d ", array[i]);
    }
    printf("%d]\n", array[8]);
    return 0;
}
