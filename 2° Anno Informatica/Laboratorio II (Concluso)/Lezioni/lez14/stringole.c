#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno

void termina(const char *messaggio);

// definzione struct che rappresenta
// una stringa
typedef struct stringola {
  char *str;
  struct stringola *next;
} stringola;


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

// "elimina" gli spazi in testa a una stringa
char *elimina_spazi_testa(char s[])
{
  int i=0;
  while(s[i]==' ')
    i++;
  assert(s[i]!=' ');
  return &s[i];
}





// main che legge le linee e le spezza al ;
int main(int argc, char *argv[])
{

  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");
  // costruzione lista stringhe leggendo dal file
  stringola *lista=NULL;  // lista vuota
  // ciclo di lettura dal file f
  char *buffer=NULL;    // usate da getline()
  size_t n=0;
  while(true) {
    //leggi linea dal file
    ssize_t e = getline(&buffer,&n,f);
    if(e<0) { // assumiamo sia finito il file
      free(buffer); break;  
    }
    if(buffer[e-1]=='\n') buffer[e-1] = '\0';
    // esegue il parsing di buffer 
    char *s = strtok(buffer,";");
    while(s!=NULL) {
      s = elimina_spazi_testa(s);
      if(s[0]!='\0') {
        stringola *c = stringola_crea(s);
        // aggiungo città alla lista
        lista = lista_stringola_inserisci_lex(lista,c);
      }
      s = strtok(NULL,";");
    }
    // ho messo tutte le stringhe date da strtok
  } // end while del getline
  fclose(f);
  lista_stringola_stampa(lista,stdout);
  lista_stringola_distruggi(lista);
  return 0;
}





// main che legge una linea alla volta
int main_linee(int argc, char *argv[])
{

  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");


  // costruzione lista stringhe leggendo dal file
  stringola *lista=NULL;
  // ciclo di lettura dal file f
  char *buffer=NULL;    // usate da getline
  size_t n=0;
  while(true) {
    //leggi linea dal file
    ssize_t e = getline(&buffer,&n,f);
    if(e<0) { // assumiamo sia finito il file
      free(buffer);
      break;  
    }
    if(buffer[e-1]=='\n') buffer[e-1] = '\0';
    stringola *c = stringola_crea(buffer);
    // aggiungo città alla lista
    lista = lista_stringola_inserisci_lex(lista,c);
  }
  fclose(f);
  lista_stringola_stampa(lista,stdout);
  lista_stringola_distruggi(lista);
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



