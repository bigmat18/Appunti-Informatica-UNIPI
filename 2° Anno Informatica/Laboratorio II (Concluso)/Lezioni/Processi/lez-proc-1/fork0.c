#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


// primo esempio di generazione di un processo figlio mediante fork

// mostra anche la differenza di prestazioni fra fwrite e write
// quando vengono effettuate numerosi operazioni di scrittura 
// di piccole quantità di byte (nel nostro esempio n interi vengono
// scritti uno alla volta)


int main(int argc, char *argv[])
{ 
  if(argc!=2) {
    printf("Uso: %s intero_positivo\n",argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);
  // fork crea un nuovo processo
  pid_t p = fork();
  if(p==0) {
    // codice eseguito dal processo figlio
    printf("Io sono %d figlio di %d\n",getpid(),getppid());
    FILE *f = fopen("file_figlio.txt","w"); 
    for(int i=1;i<n;i++)
      fwrite(&i,sizeof(int),1,f);
    fclose(f);
  }
  else if(p>0) {
    // codice del processo padre
    printf("Io sono %d genitore di %d\n",getpid(),p);
    int fd = open("file_padre.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    for(int i=1;i<n;i++)
      // la scrittura con write non usa buffer
      // quindi per è più lenta
      write(fd,&i,sizeof(int));
    close(fd);
  }
  else {
    // codice eseguito dal processo padre in caso di errore
    printf("Errore nella fork\n");
    exit(1);
  }
  printf("Sono %d e termino\n",getpid());
  return 0;
}


