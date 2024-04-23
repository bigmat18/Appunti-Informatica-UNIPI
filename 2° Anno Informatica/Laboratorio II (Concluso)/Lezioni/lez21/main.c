#include <stdio.h>   // permette di usare scanf printf
#include <stdlib.h>  // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <assert.h>  // permette di usare la funzione assert

// programma contenente errori da trovare con valgrind

void riempi(int *a, int n);

int main(int argc, char *argv[])
{
    int n, tot;
    int *a;

    // controllo e leggo input
    if (argc != 2)
    {
        printf("Uso:\n\t %s num_elementi\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    assert(n > 0); // almeno un elemento ci deve essere

    // allocazione
    a = malloc(n * sizeof(int));
    assert(a != NULL); // stop se allocazione fallita

    // inizializzazione
    riempi(a, n); // riempie array a[]

    // calcolo risultato
    tot = 0;
    for (int i = 0; i < n; i++)
        tot += a[i];

    // verifica
    if (tot == n)
        puts("giusto");
    else
        puts("sbagliato");

    return 0;
}

// inizializza array con il valore 1
void riempi(int *a, int n)
{
    for (int i = 1; i <= n; i++)
        a[i] = 1;
}