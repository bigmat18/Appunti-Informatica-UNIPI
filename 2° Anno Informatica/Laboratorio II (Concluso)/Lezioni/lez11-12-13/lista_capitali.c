#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>

// Scopo del programma:
// imparare a costruire, visualizzare e distruggere le liste in C


// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definzione struct che rappresenta
// una città con nome, e coordinate 
// + campo next per formare la lista 
typedef struct capit {
  char *nome;
  double lat;
  double lon;
  struct capit *next;
} capitale;


void capitale_stampa(capitale *a, FILE *f) {
  fprintf(f,"%20s (%f,%f)\n",a->nome,a->lat,a->lon);
}


capitale *capitale_crea(char *s, double lat, double lon)
{
  capitale *a  = malloc(sizeof(*a));
  a->lat = lat;
  a->lon = lon;
  a->nome = strdup(s); // creo una copia di s e l'assegno al nome
  a->next = NULL;
  return a;
}

void capitale_distruggi(capitale *a)
{
  free(a->nome);
  free(a);
}

// stampa tutti gli elementi della lista lis
void lista_capitale_stampa(capitale *lis, FILE *f)
{
  capitale *p = lis;  // se ne puo' fare a meno
  while(p!=NULL) {
    capitale_stampa(p,f);
    p = p->next;
  }
  return;
}

// distrugge tutti gli elementi della lista lis
void lista_capitale_distruggi(capitale *lis)
{
  while(lis!=NULL) {
    capitale *tmp = lis->next; // necessario
    capitale_distruggi(lis);
    lis = tmp;
  }
  return;
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


// inserisce elemento "c" in lista "testa" 
// mantenedo ordinamento per latitudine decrescente
capitale *inserisci_lat(capitale *testa, capitale *c)
{
  assert(c!=NULL); // devo avere un oggetto da inserire
  
  // tratta il caso testa==NULL (lista vuota)
  if(testa==NULL) {
    c->next = NULL;  // creo lista con solo c
    testa = c;
    return c;        // e la restituisco
  }
  
  assert(testa!=NULL);  // caso lista non vuota
  // verifico se c va messo prima di tutti 
  if(c->lat > testa->lat) {
    c->next = testa; // c va messa in testa
    testa = c;
    return testa; 
  }
  
  // ora so che c deve essere inserito dopo il primo elemento
  // questo implica che il primo elemento rimane quello 
  // a cui punta testa (quindi terminerò con return testa)
  capitale *p = testa;
  while(p->next!=NULL) {
    // controllo se c va inserito tra p e p->next
    assert(c->lat <= p->lat); 
    if(c->lat > p->next->lat) {
      // inserire c tra p e p->next
      c->next = p->next;
      p->next = c;
      // citta inserita posso terminare
      return testa;
    }
    p = p->next; // considero il prossimo elemento della lista
  }
  assert(p->next==NULL);
  // c va inserita in fondo
  p->next = c;
  c->next = NULL;
  return testa;
} 


// funzioni di confronto per l'inserimento ordinato parametrico

// confronto latitudini ordinando da nord a sud
int capitale_cmp_lat(capitale *a, capitale *b)
{
  if(a->lat > b->lat) return -1;
  else if(a->lat < b->lat) return 1;
  return 0;
}
// confronto latitudini ordinando da sud a nord 
int capitale_cmp_latsud(capitale *a, capitale *b)
{
  if(a->lat > b->lat) return 1;
  else if(a->lat < b->lat) return -1;
  return 0;
}
// confronto dei nomi
int capitale_cmp_nome(capitale *a, capitale *b)
{
  if(strcmp(a->nome,b->nome)<0) return -1;
  else if(strcmp(a->nome,b->nome)>0) return 1;
  return 0;// confronto latitudini da nord a sud
  // posso scrivere semplicemente 
  //   return strcmp(a->nome,b->nome);
}


// inserimento ricorsivo in lista con funzione di confronto
// passata come parametro
capitale *inserisci_generica_ric(capitale *testa, capitale *c,
                        int (*cmp)(capitale *,capitale *)   )
{
  // caso base ricorsione
  if(testa==NULL) {
    c->next = NULL; // lista vuota
    return c;
  }
  if( cmp(c,testa)<0 ) {
    c->next = testa; // c in cima alla lista
    return c;
  }
  testa->next = inserisci_generica_ric(testa->next,c,cmp);
  return testa;
}


// elimina da lis la prima capitale c tale che c->nome coincide con nome
// restituisco la nuova lista 
// aggiunte delle stampe per mostrare il funzionamento 
capitale *lista_cancella_nome(capitale *lis, char *nome)
{
  assert(nome!=NULL);
  // caso lista vuota
  if(lis==NULL) {
    fprintf(stderr, "Attenzione: la lista è vuota!\n");
    return NULL;
  }
  // caso eliminare primo elemento
  if(strcmp(lis->nome,nome)==0) {
    capitale *tmp = lis->next;
    capitale_distruggi(lis);
    return tmp; 
  }
  // non modificare lis!!!
  capitale *p = lis;
  // p punta all'elemento precedente di quello 
  // che devo eventualmente cancellare
  while(p->next!=NULL) {
    if(strcmp(p->next->nome,nome)==0) {
      capitale *dacancellare = p->next;
      p->next = dacancellare->next;
      capitale_distruggi(dacancellare);
      fprintf(stderr,"Elemento %s cancellato!\n",nome);
      return lis; // puntatore al primo elemento
    }
    else p = p->next;
  }
  fprintf(stderr,"Elemento %s non trovato (ma la lista non era vuota)\n", nome);
  return lis; // restituisce puntatore al primo elemento
              // che non è cambiato 
}


// versione ricorsiva: per chiarire il funzionamento vengono
// prodotte le stesse stampe della versione non ricorsiva 
capitale *lista_cancella_nome_ric(capitale *lis, char *nome) {
  assert(nome!=NULL);
  if(lis==NULL) {
    fprintf(stderr, "Attenzione: la lista è vuota!\n");
    return NULL;
  }
  // considero il primo elemento
  if(strcmp(lis->nome,nome)==0) {
    capitale *tmp = lis->next;
    capitale_distruggi(lis);
    fprintf(stderr,"Elemento %s cancellato!\n",nome);
    return tmp;
  }
  // cancella nome dal secondo elemento in poi
  if(lis->next!=NULL)
    lis->next = lista_cancella_nome_ric(lis->next,nome);
  else 
    fprintf(stderr,"Elemento %s non trovato (ma la lista non era vuota)\n", nome);
  return lis;
}



int main(int argc, char *argv[])
{

  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");

  // costruzione lista leggendo capitali dal file
  capitale *testa=NULL;
  // capitale *coda=NULL;  // serve per l'inserimento in coda
  while(true) {
    capitale *b = capitale_leggi(f);
    if(b==NULL) break;
    // inserisco b mantenendo l'ordinamento
    testa = inserisci_generica_ric(testa,b,capitale_cmp_nome);
         
    // inserisco b in testa alla lista
    // b->next = testa;
    // testa = b;
    
    // inserisco b in coda alla lista
    //~ if(testa==NULL) {
      //~ assert(coda==NULL);
      //~ testa = coda = b;
      //~ b->next = NULL;
    //~ }
    //~ else {
      //~ assert(testa!=NULL && coda!=NULL);
      //~ assert(coda->next==NULL);
      //~ coda->next = b;
      //~ b->next = NULL;
      //~ coda = b;
    //~ }
  }  
  if(fclose(f)==EOF)
    termina("Errore chiusura");
  
  // stampa lista capitali appena creata
  lista_capitale_stampa(testa,stdout);
  puts("------------ test cancellazione --------");
  testa = lista_cancella_nome(testa,"Atene");
  testa = lista_cancella_nome(testa,"Atene");
  testa = lista_cancella_nome(testa,"Roma");
  testa = lista_cancella_nome(testa,"Varsavia");  
  testa = lista_cancella_nome(testa,"Parigi");  
  testa = lista_cancella_nome(testa,"Roma");
  testa = lista_cancella_nome(testa,"Zagabria");
  lista_cancella_nome(NULL,"Berlino");
  lista_capitale_stampa(testa,stdout);
  
  // dealloca la memoria usata dalla lista 
  lista_capitale_distruggi(testa);
  
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

