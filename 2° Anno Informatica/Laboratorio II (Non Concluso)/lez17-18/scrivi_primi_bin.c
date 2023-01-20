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


// dato k restituisco true se è primo, false altrimenti
bool primo(int k)
{
  assert(k>0);
  if(k%2==0)
    return k==2; // se k è pari allora è primo se e solo se k==2

  // mi occupo ora del caso k dispari
  assert(k%2!=0);
  for(int i=3; i<k; i+=2 ) {
    if(k%i==0) return false; // ho scoperto che il numero non è primo
    if(i*i>k) break;
  }
  return true;
}



int main(int argc, char *argv[])
{
  // verifica siano stati forniti esattamente 2 parametri 
  if(argc!=3) {
    printf("Uso: %s N nome_file\n",argv[0]);
    return 1;
  }
  // converte il primo parametro in un intero
  int n = atoi(argv[1]);
  if(n<=0) termina("Il parametro n deve essere positivo");
  // copia il puntatore nella variabile nome_file
  char *nome_file = argv[2];
  
  // apro il file in scrittura
  FILE *f = fopen(nome_file,"wb");
  if(f==NULL) termina("Apertura file fallita");

  // cerca i primi da 2 a n e li scrive dentro il file
  for(int i=2;i<=n;i++)
    if(primo(i)) {
      // scrittora dell'intero i in formato binario 
      int e = fwrite(&i,sizeof(i),1,f);
      if(e!=1) termina("Errore nella scrittura");
    }  

  // chiudi il file e termina 
  if(fclose(f)==EOF)
    termina("Errore chiusura file");; 
   
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
