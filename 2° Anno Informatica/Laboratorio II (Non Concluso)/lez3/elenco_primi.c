#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <assert.h>  // permette di usare la funzione assert
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // funzioni di confronto/copia/etc di stringhe

// le istruzioni qui sopra le spieghiamo più avanti


// SOMMA DI NUMERI UTILIZZATO UN ARRAY DINAMICO

// prototipo della funzione
bool primo(int k);

// NOTA: una vecchia caratteristica del C fa si che quando viene trovata una funzione
// senza un prototipo o che non riesce a trovare in nessuna librereia assume implicitamente
// che restituisca un intero

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

    int *a;        // dichiaro che a sarà usato come array
    int size = 10; // dimensione attuale dell'arrey
    int messi = 0;

    a = malloc(size * sizeof(int)); // Creazione array dinamico
    if (a == NULL)
    { // Se a è null vuol dire che è avvenuto un errore ed non ha allocato
        puts("Malloc fallita");
        exit(3);
    }

    // riempio l'array
    for (int i = 2; i <= n; i++)
    {
        if (primo(i))
        {
            // inserisco i nella tabella dei primi ma prima verifico che ci sia spazio
            if (messi == size)
            {
                size = 2 * size;
                a = realloc(a, size * sizeof(int));
                if (a == NULL)
                {
                    puts("Malloc fallita");
                    exit(3);
                }
            }
            // inserisco il primo elemento dentro a[]
            a[messi] = i;
            messi += 1;
        }
    }

    // in caso abbiamo una sitazione con 57 elemeni inseriti l'array sarà di dimensione
    // 80 perchè 10*2 = 20*2 = 40*2 = 80, andiamo aora a ridurre la tabella alla dimensione minima

    a = realloc(a, messi * sizeof(int));
    if (a == NULL)
    {
        puts("Realloc fallito");
        exit(4);
    }

    for (int i = 0; i < messi; i++)
        printf("%d\n", a[i]);

    free(a); // Libero la memoria dove si trova a

    return 0;
}

// dato k restituisco true se è primo, false altrimenti
bool primo(int k)
{
    for (int i = 2; i < k; i++)
        if (k % i == 0) return false;
    return true;
}

