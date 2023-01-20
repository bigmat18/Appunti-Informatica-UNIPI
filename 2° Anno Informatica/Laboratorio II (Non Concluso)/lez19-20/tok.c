#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

// le istruzioni qui sopra le spieghiamo più avanti 

void termina(char *messaggio)
{
  puts(messaggio);
  exit(1);
}


// emulazione della funzione strtok in assembler
char *miatok(char *s, int delim);



// lconcatena argomenti passati sulal linea di comando
int main(int argc, char *argv[])
{
  if(argc==2) {
    char *tok = miatok(argv[1],',');
    while(tok!=NULL) {
      puts(tok);
      tok = miatok(NULL,',');
    }
    // verifico che anche la successiva chiamata a miatok restituisca NULL
    assert(miatok(NULL,',')==NULL);
  }
  else 
    printf("Uso: %s stringa\n",argv[0]);
  return 0;
}

