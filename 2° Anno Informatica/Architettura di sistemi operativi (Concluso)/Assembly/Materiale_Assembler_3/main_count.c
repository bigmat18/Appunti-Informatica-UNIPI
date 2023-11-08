#include<stdio.h>
#include<stdlib.h>

extern unsigned int count(unsigned int *A, unsigned int size);

int main(int argc, char **argv)
{
    int i=0;
    int vect[10] = {0, 1, 2, 4, 0 , 5, 3, 0, 15, 0};

    printf("Vettore: [");
    for (i=0; i<9; i++)
        printf("%d, ", vect[i]);
    printf("%d]\n", vect[9]);

    printf("Numero di elementi uguali a zero: %d\n", count(vect, 10));
    return 0;
}
