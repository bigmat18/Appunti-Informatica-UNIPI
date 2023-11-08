#define _GNU_SOURCE  // avverte che usiamo le estensioni GNU
#include <assert.h>  // permette di usare la funzione assert
#include <errno.h>   // rischiesto per usare errno
#include <stdbool.h> // gestisce tipo bool (variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // confronto/copia/etc di stringhe

// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio);

typedef struct node
{
    char *value;
    struct node *next;
} list;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Uso: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *fread = fopen(argv[1], "r");
    if (fread == NULL)
        termina("Errore apertura file");
    list *head = malloc(sizeof(list));
    size_t n = 0;
    ssize_t e = getline(&head->value, &n, fread);
    if (e < 0)
        termina("Errore nella lettura file");
    head->next = NULL;

    while (true)
    {
        struct node *node = malloc(sizeof(struct node));
        ssize_t e = getline(&node->value, &n, fread);
        if (e < 0)
            break;
        node->next = head;
        head = node;
    }

    fclose(fread);
    FILE *fwrite = fopen(argv[2], "w");
    if (fwrite == NULL)
        termina("Errore apertura file");

    struct node *current = head;
    int i = 1;
    while (current != NULL)
    {
        fprintf(fwrite, "%d %s", i, current->value);
        current = current->next;
        i++;
    }
    fclose(fwrite);
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
