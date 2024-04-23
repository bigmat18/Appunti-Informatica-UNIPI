#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <assert.h>  // permette di usare la funzione assert
#include <string.h>  // funzioni di confronto/copia/etc di stringhe

// le istruzioni qui sopra le spieghiamo più avanti

// da compilare con:
//  gcc -std=c11 -Wall -O -g -o somma  somma.c

// Scopo del programma:
//  legge un intero N da tastiera
//  crea un array di N int
//  legge N interi mettendoli nell'array
//  calcola la somma degli elementi dell'array
//  stampa la somma

int main(int argc, char *argv[])
{
    int n; // definisco variabile intera di nome n

    // spiego cosa voglio leggere e lo leggo con scanf
    printf("Inserisci il numero di elementi: ");
    int e = scanf("%d", &n); // il motivo della & lo vedremo più avanti
    // controlli sulla lettura
    if (e != 1)
    {
        puts("Valore non trovato");
        exit(1);
    }
    if (n <= 0)
    {
        puts("Il numero di elementi deve essere positivo");
        exit(2);
    }

    // crea e riempi array
    int a[n];
    for (int i = 0; i < n; i++)
    { // esegue queste istruzioni per
      // i=0,1,2,..n-1
        printf("Inserisci l'elemento di posto %d: ", i);
        e = scanf("%d", &a[i]);
        if (e != 1)
        {
            puts("Valore non trovato");
            exit(1);
        }
    }

    // calcola e stampa la somma
    int somma = 0;
    for (int i = 0; i < n; i++)
        somma += a[i];

    printf("%d\n", somma);

    return 0;
}