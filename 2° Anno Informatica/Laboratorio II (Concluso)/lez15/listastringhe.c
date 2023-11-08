#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

#include "listastringhe.h"



stringola *stringola_crea(char *s)
{
  stringola *a  = malloc(sizeof(*a));
  a->str = strdup(s); // creo una copia di s e l'assegno al nome
  a->next = NULL;
  return a;
}

void stringola_distruggi(stringola *a)
{
  free(a->str);
  free(a);
}

void stringola_stampa(stringola *a, FILE *f) {
  fprintf(f,"%-20s\n",a->str);
}

void lista_stringola_stampa(stringola *lis, FILE *f)
{
  while(lis!=NULL) {
    stringola_stampa(lis,f);
    lis = lis->next;
  }
}


void lista_stringola_distruggi(stringola *lis)
{
  if(lis!=NULL) {
    lista_stringola_distruggi(lis->next);
    stringola_distruggi(lis);
  }
}

// input lis: lista di stringole può essere vuota 
//             ma deve essere ordinata lessicograficamente
//          c: stringola da inserire deve eiustere c!=NULL
//  output la nuova lsta con c inserita matenemdo l'ordine
stringola *lista_stringola_inserisci_lex(stringola *lis, stringola *c) 
{
  assert(c!=NULL);
  if(lis==NULL) {
    c->next = NULL;
    return c;
  }
  if(strcmp(c->str,lis->str)<0) {
    // il nome in c è il più piccolo
    // diventa lui il primo elemento
    c->next = lis;
    return c;
  }
  else {
    // lis rimane il primo elemento, quindi restituisco lui
    // seguito dal resto della lista in cui la ricorsione
    // ha piazzato c al posto giusto
    lis->next = lista_stringola_inserisci_lex(lis->next,c);
    return lis;
  }
}
