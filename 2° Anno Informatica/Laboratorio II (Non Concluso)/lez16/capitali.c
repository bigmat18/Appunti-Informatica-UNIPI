#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno

#include "capitali.h"

// prototipo di funzione statica 
static void termina(const char *messaggio);


// stampa sul file *f i campi della capitale a
void capitale_stampa(capitale *a, FILE *f) {
  fprintf(f,"%20s (%f,%f)\n",a->nome,(*a).lat,a->lon);
}

// crea oggetto capitale a partire dai sui campi
capitale *capitale_crea(char *s, double lat, double lon)
{
  assert(s!=NULL);
  assert(lat>= -90 && lat <= 90);
  assert(lon>= -180 && lon <= 180);
  capitale *a = malloc(sizeof(*a));
  a->nome = strdup(s);
  a->lat = lat;
  a->lon = lon;
  return a;
}

// distrugge (dealloca) un oggetto capitale 
void capitale_distruggi(capitale *a)
{
  free(a->nome);
  free(a);
}


// legge un oggetto capitale dal file f
// restituisce il puntatore all'oggetto letto
// oppure NULL se non riesce a leggere dal file
capitale *capitale_leggi(FILE *f)
{
  assert(f!=NULL);
  char *s;
  double lat, lon;
  int e = fscanf(f,"%ms %lf %lf",&s,&lat,&lon);
  if(e!=3)
     return NULL;
  capitale *c = capitale_crea(s,lat,lon);
  free(s);
  return c;
}

//legge e restituisce un array di capitali *
capitale **capitale_leggi_file(FILE *f, int *num)
{
  assert(f!=NULL);
  int size=10; // dimensione attuale dell'array
  int messi=0; // numero di elementi attualmente nell'array
  capitale **a = malloc(size*sizeof(capitale *));
  if(a==NULL) 
    termina("Memoria insufficiente");
    
  while(true) {
    capitale *b = capitale_leggi(f);
    if(b==NULL) break;

    if(messi==size) {
        // ingrandisco l'array
        size = size*2;
        a = realloc(a,size*sizeof(capitale *));
        if(a==NULL)
          termina("realloc fallita");
    }
    assert(messi<size);
    a[messi] = b;
    messi += 1;
  }
  // ho messo tutti gli elementi che mi interessavano
  size = messi;
  a = realloc(a,size*sizeof(capitale *));
  if(a==NULL)
    termina("realloc fallita");
  
  // salvo il numero di elementi e restituisco l'array  
  *num = messi;
  return a;  
}


// confronto capitali per latitudini ordinando da nord a sud
int capitale_cmp_lat(capitale *a, capitale *b)
{
  if(a->lat > b->lat) return -1;
  else if(a->lat < b->lat) return 1;
  return 0;
}
// confronto capitali per nome
int capitale_cmp_nome(capitale *a, capitale *b)
{
  return strcmp(a->nome,b->nome);
}


// stampa su stderr il  messaggio che gli passo
// se errno!=0 stampa anche il messaggio d'errore associato 
// a errno. dopo queste stampe termina il programma
static void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}

