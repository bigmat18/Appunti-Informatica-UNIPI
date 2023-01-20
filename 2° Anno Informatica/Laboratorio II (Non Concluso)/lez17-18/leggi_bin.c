#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe
#include <errno.h>    // richiesto per usare errno

// Scopo del programma:
//  mostrare come si crea un file binario 
//  in questo esempio veine iscritto un intero alla volta

static void termina(const char *messaggio);



int main(int argc, char *argv[])
{
  // verifica siano stati forniti esattamente 2 parametri 
  if(argc!=2) {
    printf("Uso: %s nome_file\n",argv[0]);
    return 1;
  }
  char *nome_file = argv[1];
  
  // apro il file in lettura
  FILE *f = fopen(nome_file,"rb");
  if(f==NULL) termina("Apertura file fallita");

  // leggo tutti gli interi del file e li metto in un array
  // mi metto alla fine del file
  int e = fseek(f, 0, SEEK_END);
  if(e!=0) termina("Errore fseek");
  long lungfile = ftell(f);
  if(lungfile<0) termina("Errore ftell");
  if(lungfile%4!=0) termina("Il file non contiene int32");
  // numero di interi nel file
  int n = lungfile/4; 
  if(n==0) termina("file vuoto");
  // alloca array dove meteter gli interi
  int *a = malloc(n*sizeof(*a));
  if(a==NULL) termina("errore malloc");
  rewind(f); // "riavvolgo" il file
  size_t m = fread(a,sizeof(int),n,f);
  if(n!=m) termina("errore fread");
  // chiudi il file
  if(fclose(f)==EOF)
    termina("Errore chiusura file");; 
  // stampiamo gli interi letti
  for(int i=0;i<n;i++)
    printf("%8d", a[i]);
  puts("");
  free(a);
  return 0;
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
