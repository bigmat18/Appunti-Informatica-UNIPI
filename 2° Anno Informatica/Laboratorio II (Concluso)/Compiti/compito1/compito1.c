#define _GNU_SOURCE // avverte che usiamo le estensioni GNU
#include <assert.h> // permette di usare la funzione assert
#include <errno.h>
#include <stdbool.h> // gestisce tipo bool (variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // confronto/copia/etc di stringhe

// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio);

int *elab_bigger(int a[], int n, int k)
{
    int *result = malloc((n * k) * sizeof(int));
    if (result == NULL)
        termina("Errore nell'allocazione");
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            result[pos] = a[i];
            pos++;
        }
    }
    return result;
}

int *elab_equal(int a[], int n, int k)
{
    int *result = malloc(n * sizeof(int));
    if (result == NULL)
        termina("Errore nell'allocazione");

    for (int i = 0; i < n; i++)
        result[i] = 0;

    return result;
}

int *elab_smaller(int a[], int n, int k)
{
    assert(k > 0);
    int *result = malloc((n * k) * sizeof(int));
    if (result == NULL)
        termina("Errore nell'allocazione");
    int pos = 0;

    for (int i = n - 1; i >= 0; i++)
    {
        for (int j = 0; j < k; j++)
        {
            result[pos] = a[i];
            pos++;
        }
    }
    return result;
}

int *elabora(int a[], int n, int k, int *nuovon)
{
    int *result = NULL;

    if (k > 0)
    {
        result = elab_bigger(a, n, k);
        *nuovon = n * k;
    }
    else if (k < 0)
    {
        result = elab_smaller(a, n, abs(k));
        *nuovon = n * k;
    }
    else
    {
        result = elab_equal(a, n, k);
        *nuovon = n;
    }

    return result;
}

// scheletro del main della soluzione
int main(int argc, char *argv[])
{

    int nuovon;
    char *file_name = argv[1];
    int size = 10;
    int pos = 0;
    int *array = malloc(size * sizeof(int));

    FILE *file = fopen(file_name, "rt");
    while (true)
    {
        int n;
        int e = fscanf(file, "%d", &n);

        if (e == EOF)
            break;

        if (pos == size)
        {
            size *= 2;
            array = realloc(array, size * sizeof(int));
        }
        array[pos] = n;
        pos++;
    }

    array = realloc(array, pos * sizeof(int));

    for (int i = 2; i < argc; i += 2)
    {
        FILE *f = fopen(argv[i + 1], "wt");
        int *b = elabora(array, pos, atoi(argv[i]), &nuovon);
        for (int i = 0; i < nuovon; i++)
        {
            fprintf(f, "%d\n", b[i]);
        }
        if (fclose(f) == EOF)
            termina("Errore chiusura file");
        free(b);
    }

    if (fclose(file) == EOF)
        termina("Errore chiusura file");

    free(array);

    return 0;
}

void termina(const char *messaggio)
{
    if (errno != 0)
        perror(messaggio);
    else
        fprintf(stderr, "%s\n", messaggio);
    exit(1);
}
