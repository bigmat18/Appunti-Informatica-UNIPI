#include<stdio.h>
#include<stdlib.h>

struct nodo
{
    int value;
    struct nodo *next;
};

typedef struct nodo node_t;

extern node_t *merge(node_t *prima, node_t *seconda);

int main()
{
    // creo la prima lista
    int i=0;
    node_t *prima_list = NULL;
    node_t *prec = NULL;
    for (i=0; i<5; i++) {
        node_t *elem = (node_t *) malloc(sizeof(node_t));
        if (elem == NULL) {
            printf("Errore malloc\n");
            exit(1);
        }
        elem->value = i;
        if (prec != NULL) {
            prec->next = elem;
            prec = elem;
        }
        else {
            prima_list = elem;
            prec = elem;
        }
        elem->next = NULL;
    }
    // creo la seconda lista
    node_t *seconda_list = NULL;
    prec = NULL;
    for (; i<10; i++) {
        node_t *elem = (node_t *) malloc(sizeof(node_t));
        if (elem == NULL) {
            printf("Errore malloc\n");
            exit(1);
        }
        elem->value = i;
        if (prec != NULL) {
            prec->next = elem;
            prec = elem;
        }
        else {
            seconda_list = elem;
            prec = elem;
        }
        elem->next = NULL;
    }
    node_t *result_list = merge(prima_list, seconda_list);
    // stampo la lista unita
    printf("[ ");
    while (result_list != NULL) {
        printf("%d ", result_list->value);
        result_list = result_list->next;
    }
    printf("]\n");
    return 0;
}
