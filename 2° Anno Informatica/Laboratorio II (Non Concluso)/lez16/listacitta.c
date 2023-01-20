#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno
#include <ctype.h> 

#include "listastringhe.h"


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);

// definizione struct che rappresenta
// una città con nome, popolazione, personaggi
typedef struct citta {
  char *nome;
  int pop;
  stringola *persone;  
  struct citta *next;
} citta; 

// stampa una singola citta
void citta_stampa(citta *a, FILE *f) {
  fprintf(f,"%-20s: %d\n",a->nome,a->pop);
  fprintf(f,"Personaggi famosi %s:\n", a->nome);
  lista_stringola_stampa(a->persone,f);
  fprintf(f,"---- Fine elenco %s \n", a->nome);
}

void lista_citta_stampa(citta *lis, FILE *f)
{
  while(lis!=NULL) {
    citta_stampa(lis,f);
    lis = lis->next;
  }
}


citta *citta_crea(char *s, int pop, stringola *lis)
{
  citta *a  = malloc(sizeof(*a));
  a->nome = strdup(s); // creo una copia di s e l'assegno al nome
  a->pop = pop;
  a->persone = lis;
  a->next = NULL;
  return a;
}


void citta_distruggi(citta *a)
{
  free(a->nome);
  lista_stringola_distruggi(a->persone);
  free(a);
}


void lista_citta_distruggi(citta *lis)
{
  if(lis!=NULL) {
    lista_citta_distruggi(lis->next);
    citta_distruggi(lis);
  }
}



// input lis: lista di citta può essere vuota 
//             ma deve essere ordinata per nome
//          c: citta da inserire deve esistere c!=NULL
//  output la nuova lsta con c inserita matenedo l'ordine
citta *lista_citta_inserisci_nome(citta *lis, citta *c) 
{
  assert(c!=NULL);
  if(lis==NULL) {
    c->next = NULL;
    return c;
  }
  if(strcmp(c->nome,lis->nome)<0) {
    // il nome in c è il più piccolo
    // diventa lui il primo elemento
    c->next = lis;
    return c;
  }
  else {
    // lis rimane il primo elemento, quindi resitutico lui
    // seguito dal resto della lista in cui la ricorsione
    // ha piazzato c al posto giusto
    lis->next = lista_citta_inserisci_nome(lis->next,c);
    return lis;
  }
}




// elimina gli spazi iniziali e finali 
// da una stringa MODIFICANDOLA
char *cancella_spazi(char *s){
  while(isspace(*s))
    s++;
  int t=strlen(s);
  for(int i=t-1;i>=0;i--)
    if(isspace(s[i]))
      s[i] = '\0';
    else break;
  return s;
}



int main(int argc, char *argv[])
{

  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");


  // costruzione lista leggendo citta dal file
  citta *lisc=NULL;
  // ciclo di lettura dal file
  size_t n=0;
  char *buffer=NULL;
  while(true) {
    ssize_t e = getline(&buffer,&n,f);
    if(e<0) break;
    char *n = strtok(buffer,";");
    if(n==NULL) termina("Errore file input (1)");
    char *p = strtok(NULL,";");
    if(p==NULL) termina("Errore file input (2)");
    stringola *lisp=NULL;
    while(true) {
      char *s = strtok(NULL,";");
      if(s==NULL) break;
      stringola *pers = stringola_crea(cancella_spazi(s));
      lisp = lista_stringola_inserisci_lex(lisp,pers);
    }
    citta *c =citta_crea(n,atoi(p),lisp);
    // aggiungo città alla lista
    lisc = lista_citta_inserisci_nome(lisc,c);
  }
  free(buffer);
  if(fclose(f)!=0) termina("Errore chiusura file");
  lista_citta_stampa(lisc,stdout);

  // dealloco la lista delle citta e dei personaggi
  lista_citta_distruggi(lisc);
  return 0;
}




// stampa su stderr il  messaggio che gli passo
// se errno!=0 stampa anche il messaggio d'errore associato 
// a errno. dopo queste stampe termina il programma
void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}


