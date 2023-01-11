#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <assert.h>  // permette di usare la funzione assert
#include <string.h>  // funzioni di confronto/copia/etc di stringhe

// le istruzioni qui sopra leggono i prototipi di alcune funzioni di libreria

// da compilare con:
//  gcc -std=c11 -Wall -O -g -o scrivi_primi scrivi_primi.c

// Scopo del programma:
//  mostrare come si crea un file di testo

// dato k restituisco true se è primo, false altrimenti
bool primo(int k)
{
    assert(k > 0);
    if (k % 2 == 0)
        return k == 2; // se k è pari allora è primo se e solo se k==2

    // mi occupo ora del caso k dispari
    assert(k % 2 != 0);
    for (int i = 3; i < k; i += 2)
    {
        if (k % i == 0)
            return false; // ho scoperto che il numero non è primo
        if (i * i > k)
            break;
    }
    return true;
}

// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio)
{
    // oltre al mio messaggio stampa il messaggio
    // associato alla variabile globale errno
    // utilizzando la funzione di libreria perror()
    perror(messaggio);
    exit(1);
}

int main(int argc, char *argv[])
{
    // verifica siano stati forniti esattamente 2 parametri
    if (argc != 3)
    {
        printf("Uso: %s N nome_file\n", argv[0]);
        return 1;
    }
    // converte il primo parametro in un intero
    int n = atoi(argv[1]);
    if (n <= 0)
        termina("Il parametro n deve essere positivo");
    // copia il puntatore nella variabile nome_file
    char *nome_file = argv[2];

    // apro il file in scrittura
    FILE *f = fopen(nome_file, "wt");
    if (f == NULL)
        termina("Apertura file fallita");

    // cerca i primi da 2 a n e li scrive dentro il file
    for (int i = 2; i <= n; i++)
        if (primo(i))
        {
            int e = fprintf(f, "%d\n", i); // scrive i nel file
            if (e < 0)
                termina("Errore nella scrittura");
        }

    // chiudi il file e termina
    if (fclose(f) == EOF)
        termina("Errore chiusura file");
    ;

    return 0;
}