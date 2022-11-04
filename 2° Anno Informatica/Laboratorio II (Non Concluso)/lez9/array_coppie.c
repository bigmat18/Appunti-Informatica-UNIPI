#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno

// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);

// Scopo del programma:
// Mostrare come si definiscono e usano le struct

// compilare ed eseguire con
//  make maincoppia
//  maincoppia 1 2 5 0 3 4 



// definisco la struct duetto
// dico che coppia è sinonimo di struct duetto
typedef struct duetto {
  int primo;
  int secondo;
} coppia;

// volendo posso scrivere ad esempio
typedef int intero;
typedef int *puntatore_a_int;
// per definire dei sinonimi di tipi esistenti


// scambia le componenti: attenzione il passaggio avviene per valore 
struct duetto scambia(struct duetto d)
{ 
  intero tmp = d.primo;
  d.primo = d.secondo;
  d.secondo = tmp;
  return d;
}


void coppia_stampa(coppia a, FILE *f) {
  fprintf(f,"(%d,%d)\n",a.primo,a.secondo);
}


int main(int argc, char *argv[])
{
  coppia *a;

  if(argc <3 || argc%2==0) {
    printf("Uso: %s un numero positivo pari di interi\n",argv[0]);
    exit(1);
  } 
  int n = (argc-1)/2;  // dimensione di a  == numero coppie
  a = malloc(n*sizeof(coppia));
  if(a==NULL) termina("allocazione fallita");

  for(int i=0;i<n;i++) {
    a[i].primo = atoi(argv[2*i+1]);
    a[i].secondo = atoi(argv[2*i+2]);  
  }

  for(int i=0;i<n;i++)
    coppia_stampa(a[i], stdout);

  free(a);
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

