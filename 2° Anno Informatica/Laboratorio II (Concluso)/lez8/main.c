#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <stdbool.h> // gestisce tipo bool
#include <assert.h>  // permette di usare la funzione assert
#include <string.h>  // funzioni per stringhe
#include <errno.h>   // rischiesto per usare errno

int *leggi_file(FILE *f, int *num_elementi)
{
    assert(f != NULL); // il file deve essere valido

    int size = 10; // dimensione attuale dell'array
    int messi = 0; // numero di elementi attulamente nell'array
    int *a = malloc(size * sizeof(int));
    if (a == NULL)
        termina("Memoria insufficiente");

    while (true)
    {
        int n;
        int e = fscanf(f, "%d", &n);
        if (e == EOF)
            break;
        if (e != 1)
            termina("Contenuto illegale nel file");
        // ho letto un intero dal file ed è stato messo in n
        if (messi == size)
        {
            // ingrandisco l'array
            size = size * 2;
            a = realloc(a, size * sizeof(int));
            if (a == NULL)
                termina("realloc fallita");
        }
        assert(size > messi);
        a[messi] = n;
        messi += 1;
    }
    // ho messo tutti gli elementi che mi interessavano
    size = messi;
    a = realloc(a, size * sizeof(int));
    if (a == NULL)
        termina("realloc fallita");
    // salvo il numero di elementi e restituisco l'array
    *num_elementi = messi;
    return a;
}

void merge(char *a[], int na, char *b[], int nc, char *c[]){
    assert(a != NULL && c != NULL && b != NULL);
    int n = na + nc; // lunghezza array risultato
    int ia, ib, ic;  // indici all'interno degli array
    ia = ic = ib = 0;

    // eseguo merge riempiendo il vettore b
    for (ib = 0; ib < n; ib++)
    {
        if (ia == na)
            b[ib] = c[ic++];
        else if (ic == nc)
            b[ib] = a[ia++];
        else if (strcmp(a[ia],c[ic]) < 0)
            b[ib] = a[ia++];
        else
            b[ib] = c[ic++];
    }
    // verifica tutti gli indici sono arrivati in fondo
    assert(ia == na);
    assert(ic == nc);
    assert(ib == n);
}

// si può scrivere sia char *a[] char **a come array di stringhe
void mergesort(char *a[], int n){
    assert(a != NULL);
    assert(n > 0);

    // caso base
    if (n == 1)
        return;

    int n1 = n / 2;  // dimesione prima parte
    int n2 = n - n1; // dimensione seconda parte

    mergesort(a, n1);
    mergesort(&a[n1], n2); // &a[n1] potevo scriverlo a+n1

    // ho le due metà ordinate devo fare il merge
    // se scrivo sizeof(*b) è come scrivere sizeof(sizeof(char *))
    char **b = malloc(n * sizeof(*b));
    if (b == NULL)
        termina("malloc fallita nel merge");
    merge(a, n1, &a[n1], n2, b);
    // copio il risultato da b[] ad a[]
    for (int i = 0; i < n; i++)
        a[i] = b[i];

    free(b);
}

void stampa_array_stringhe(char *a[], int n, FILE *f){
    
}

int main(int argc, char *argv[]){
    fprintf(stdin, "%s", "prova in\n");
    fprintf(stdout, "%s", "prova out\n");
    fprintf(stderr, "%s", "prova err\n");
    return 0;
}