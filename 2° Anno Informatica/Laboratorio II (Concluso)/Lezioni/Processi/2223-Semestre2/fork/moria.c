#include "xerrori.h"

// esempio di generazione di processi mediante fork
// e di lettura dei valori di ritorno dei figli mediante wait


// notare l'uso delle funzioni x... che eseguono chiamate di sistema
// o di libreria e verificano la presenza di eventuali errori
// Il sorgente di queste funzioni e' in xerrori.c i prototipi in xerrori.h 

int main(int argc, char *argv[])
{ 
  int n=3;  // numero di figli da generare
  for(int i=0;i<n;i++) {
    pid_t p = xfork(__LINE__,__FILE__);
    if(p==0) {// figlio
      printf("Io sono %d, principe di Moria, figlio %d-esimo di %d\n",getpid(),i,getppid());
      // sleep(40 - 10*i);
      exit(3*i+1);
    }  
  }
  // padre
  printf("Io sono %d, re sotto la montagna, figlio di %d\n",getpid(),getppid());
  int tot_draghi = 0;
  for(int i=0;i<n;i++) {
    int status;
    pid_t p = xwait(&status,__LINE__,__FILE__);
    printf("E' terminata la missione del figlio %d\n",p);
    if(WIFEXITED(status)) { 
      tot_draghi += WEXITSTATUS(status); 
      printf("Draghi uccisi da questo figlio: %d\n",
             WEXITSTATUS(status));
    }
    else
      printf("Figlio non terminato con exit\n");  
  }
  printf("Finito\n");
  // il valore tot_draghi può visualizzato
  // dal prompt dei comandi con echo $?
  return tot_draghi;
}
