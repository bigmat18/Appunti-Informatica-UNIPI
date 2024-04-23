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

#if 0
&& || 

a=2
b=9 
a && b -> true
-----
& | ^ bitwise   operazioni tra interi 

a =00000010 
b =00001001

a&b -> 00000000
a|b -> 00001011

esiste anche il ~

~a = 11111101

<< shift sin
>> shift dex

b = 00001001

c = b<<3 -> 01001000

c>>2 -> 00010010

d = 110000....1
d>>2
  possiamo ottenere 00110000....
  ma anche          1111000000
e = 001000....1
e>>2 ottengo sempre 00001000...
#endif

 
  
// converte intero in binario
int main(int argc, char *argv[])
{
  // verifica siano stati fornito un parametro 
  if(argc!=3) {
    printf("Uso: %s intero stringa01\n",argv[0]);
    return 1;
  }
  int n = atoi(argv[1]);

  for(int i=31;i>=0;i--) {
    int mask = 1<<i;
    char c = ( (n&mask) !=0  ) ? '1' : '0';
    printf("%c",c);
  }
  puts("");
  
  // convertiamo argv[2] in intero
  // argv[2] = 100011
  n = 0;
  for(int i=0;i<strlen(argv[2]);i++) {
    if(argv[2][i]=='1') {
      int mask = 1 << ( strlen(argv[2])-i-1  );
      n = n | mask;
    }
  }
  printf("Valore convertito: %d\n",n);
  

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
