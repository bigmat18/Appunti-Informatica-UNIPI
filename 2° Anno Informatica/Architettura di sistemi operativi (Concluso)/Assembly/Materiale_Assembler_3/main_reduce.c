#include <stdio.h>

// array dichiarato come variabile globale
int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main()
{
    int i = 0;
    int result = 0;
    for (int i=0; i<10; i++)
        result += array[i];
    printf("Il risultato e' %d\n", result);
    return 0;
}
