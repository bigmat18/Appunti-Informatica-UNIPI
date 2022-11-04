#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

// esperimenti con l'artimetica dei puntatori


int main(int argc, char *argv[])
{
  int a=1,b=2,c=3;
  int *v;
  v = malloc(10*sizeof(int));
  for(int i=0;i<10;i++)
    v[i] = 10*i;
  
  printf("indirizzo di a=%p, contenuto di a: %d\n",&a,a);
  printf("indirizzo di b=%p, contenuto di b: %d\n",&b,b);
  printf("indirizzo di c=%p, contenuto di c: %d\n",&c,c);
  printf("indirizzo di v=%p, contenuto di v=%p\n",&v,v);
  
  
  //--- i due modi di utilizzare i puntatori sono interscambiabili:
  int *pb = &b; // pb contiene l'indirizzo di b 
  c = v[0];     // metto v[0] in c
  a = *pb;      // metto b in a
  // --- posso anche scrivere (menglio non farlo ma si può)
  c = *v;   // equivalente a v[0]
  a = pb[0]; //equivalente a *pb
  // --- attenzione: stampo elemento inesistente
  c = 3;
  printf("pb[1]=%d (perché?)\n",pb[1]);
  
  
  // -------- Aritmetica dei puntatori:
  assert(v==&v[0]);  // v contiene l'indirizzo di v[0]
  // &v[1]; // questo è l'indirizzo in memoria di v[1]
  // v+1;   // questo è un modo leggittimo di indicare &v[1]
  printf("indirizzo di v[1]=%p, v+1=%p\n",&v[1],v+1);
  // questo vale anche fuori dall'array  
  int i = 20;
  printf("indirizzo di v[%d]=%p, v+%d=%p\n",i,&v[i],i,v+i);
    
  // vediamo cosa succede per i caratteri
  char *s = argv[0];
  printf("Valore s: %p, valore s+1: %p\n",s,s+1); 
  // s+1 è l'indirizzo del carattere successivo
  // quindi dista 1 byte da s, notare la differenza con v+1
  // che dista 4 byte da v
        
  return 0;
}

