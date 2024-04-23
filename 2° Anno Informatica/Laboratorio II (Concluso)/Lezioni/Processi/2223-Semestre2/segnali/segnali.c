#include "xerrori.h"
#define QUI __LINE__,__FILE__

// esempio base di gestione segnali con handler


// variabili globali utilizzate da main e dal signal handler 
int tot_segnali = 0;
// il perche' della keyword volatile lo abbiamo visto a lezione
volatile bool continua = true;


// funzione che viene invocata quando viene ricevuto 
// un segnale USR1 USR2 o INT (Control-C)
void handler(int s)
{
  tot_segnali++;
  if(s!=SIGUSR1) {
    kill(getpid(),SIGUSR1); // manda SIGUSR1 a se stesso  
    kill(getpid(),SIGUSR1); // manda SIGUSR1 a se stesso  
  }
  printf("Segnale %d ricevuto dal processo %d\n", s, getpid());
  if(s==SIGUSR2) {
    // forza uscita dal loop infinito del main()
    continua = false;
  } 

}


int main(int argc, char *argv[])
{
  // definisce signal handler 
  struct sigaction sa;
  sa.sa_handler = &handler;
  // setta sa.sa_mask che è la maschera di segnali da bloccare
  // durante l'esecuzione di handler(). Blocca tutti i segnali
  sigfillset(&sa.sa_mask); 
  sigdelset(&sa.sa_mask,SIGUSR1);  // tranne SIGUSR1
  sa.sa_flags = SA_RESTART;     // restart system calls 
  sigaction(SIGUSR1,&sa,NULL);  // handler per USR1
  sigaction(SIGUSR2,&sa,NULL);  // stesso handler per USR2
  // definisco variabile dove salvo il settaggio attuale per SIGINT
  struct sigaction oldsa;
  sigaction(SIGINT,&sa,&oldsa);   // stesso handler per Control-C


  // visualizza il pid
  printf("Se vuoi mandarmi dei segnali il mio pid e': %d\n", getpid());
  
  // entra in orribile busy waiting attendendo i segnali
  continua = true;
  do { // loop apparentemente senza uscita
    ;
    // scommentare per evitare il busy waiting 
    // sleep(1000);   
    // puts("Mi sono svegliato");            
  } while(continua); 
  printf("Ricevuti: %d segnali\n", tot_segnali);

  // rimetti la vecchia gestione di SIGINT 
  sigaction(SIGINT,&oldsa,NULL);
  // ora SIGINT interrompe ll'esecuzione come per default

  // rientro nel loop, per uscire serve un altro segnale usr2
  // oppure un SIGINT....
  continua = true;
  do { // loop apparentemente senza uscita
    ;           
  } while(continua);
  printf("Ricevuti: %d segnali (secondo loop)\n", tot_segnali);
  return 0;
}

