#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <assert.h>  // permette di usare la funzione assert
#include <string.h>  // funzioni di confronto/copia/etc di stringhe

// le istruzioni qui sopra leggono i prototipi di alcune funzioni di libreria

// Scopo del programma:
//  mostrare la struttura dell'array argv contenente i parametri
//    passati sulla linea di comando
//  mostrare la differenza fra copiare un puntatore e copiare
//    il contenuto dell'arrat (funzione strdup)

// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio)
{
    puts(messaggio);
    exit(1);
}

int main(int argc, char *argv[])
{

    // stampo gli elementi di argv[] come stringhe
    for (int i = 0; i < argc; i++)
        printf("argv[%d]: %p  %s \n", i, argv[i], argv[i]);
    puts("---- fine ----");

    // questo crea variabile primo che punta alla stessa stringa di argv[0]
    // char *primo = argv[0];

    // come creare una stringa indipendente:

    // metodo "manuale": non usare
    // alloco la memoria
    // char *primo = malloc(strlen(argv[0])+1);
    // copio il contenuto
    // for(int i=0;i<strlen(argv[0])+1;i++)
    //  primo[i] = argv[0][i];

    // metodo "automatico": uso strdup() che fa tutto lei
    char *primo = strdup(argv[0]);

    // modifico carattere primo[1]
    primo[1] = 'X'; // fondamentale singolo apice ' invece di "

    // stampo stringa primo e ristampo le stringhe di argv[]
    printf("primo: %p  %s \n", primo, primo);
    for (int i = 0; i < argc; i++)
        printf("argv[%d]: %p  %s \n", i, argv[i], argv[i]);
    puts("---- fine ----");

    // dealloco la memoria usata da primo
    free(primo);
    // Nota: gli argv[i] non vanno dellocati perchè non sono
    //       stati creati con malloc()
    return 0;
}
