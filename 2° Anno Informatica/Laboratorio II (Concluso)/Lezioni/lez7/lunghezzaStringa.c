// Esempio calcolo lunghezza stringa utilizzando l'aritmetica dei puntatori

#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno

void termina(char *messaggio);


// funzione semplice per calcolare la lunghezza di una stringa:
// conto quanti caratteri vedo prima di raggiungere lo \0
int lung_stringa1(char s[])
{
  assert(s!=NULL);
  int i=0;
  while(s[i] != '\0') 
    i++;
  return i;
}


// usa *(s+i) invece di s[i] (mettodi equivalenti)
int lung_stringa2(char s[])
{
  int i=0;
  while(*(s+i) != '\0')   // s+i == &s[i] , quindi *(s+i)=s[i]
    i++;
  return i;
}

// incrementa s invece di scrivere s+i 
// non c'è motivo di usarlo ma bisogna saperlo riconoscere
int lung_stringa3(char s[])
{
  int i=0;
  while(*s != '\0') {   // s+i == &s[i] , quindi *(s+i)=s[i]
    i++; s++;           // s++ equivalente s = s+1
  }
  return i;
}


// incrementa s dentro il test del while. Poco leggibile:
// sfrutta il fatto che ++ ha precedenza maggiore di *
int lung_stringa4(char s[])
{
  int i=0;
  while(*s++ != '\0')    // s+i == &s[i] , quindi *(s+i)=s[i]
    i++;                 // s++ equivalente s = s+1
  return i;
}


// legge una stringa dalla linea di comando e ne 
// calcola la lunghezza con le differenti funzioni
int main(int argc, char *argv[])
{

  if(argc!=2) {
    fprintf(stderr, "Uso:\n\t   %s stringa\n", argv[0]);
    exit(1);
  }

  int n = lung_stringa1(argv[1]);
  printf("lungh_stringa1: %d\n",n);
  n = lung_stringa2(argv[1]);
  printf("lungh_stringa2: %d\n",n);
  n = lung_stringa3(argv[1]);
  printf("lungh_stringa3: %d\n",n);
  n = lung_stringa4(argv[1]);
  printf("lungh_stringa4: %d\n",n);
  return 0;
}


// stampa su stderr il messaggio che gli passo
// se errno!=0 stampa anche il messaggio d'errore associato 
// a errno. dopo queste stampe termina il programma
void termina(char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}
