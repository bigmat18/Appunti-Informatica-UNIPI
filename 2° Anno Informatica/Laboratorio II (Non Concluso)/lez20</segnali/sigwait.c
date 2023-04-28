#include "xerrori.h"
#define QUI __LINE__,__FILE__

// esempio base gestione segnali con 
// un thread dedicato e la funzione sigwait


// struct contente i dati condivisi con il thread 
// che gestisce i segnali
typedef struct {
  int tot_segnali;
  bool continua; 
} dati;

// thread che gestisce i segnali
void *gbody(void *arg) {
  // recupera argomento passato al thread
  dati *d = (dati *) arg;
  // si mette in attesa di tutti i segnali
  sigset_t mask;
  sigfillset(&mask);
  sigdelset(&mask,SIGINT);
  int s;
  while(true) {
    int e = sigwait(&mask,&s);
    if(e!=0) perror("Errore sigwait");
    printf("Thread gestore svegliato dal segnale %d\n",s);
    d->tot_segnali++;
    if(s==SIGUSR2) {
      // forza uscita dal loop infinito del main()
      d->continua = false;
    } 
  }
  return NULL;
}


int main(int argc, char *argv[])
{
  // blocco tutti i segnali
  sigset_t mask;
  sigfillset(&mask);  // insieme di tutti i segnali
  sigdelset(&mask,SIGQUIT); // elimino sigquit da mask
  pthread_sigmask(SIG_BLOCK,&mask,NULL); // blocco tutto tranne sigquit

  // visualizza il pid
  printf("Se vuoi mandarmi dei segnali il mio pid e': %d\n", getpid());

  // inizializza dati
  dati d;
  d.tot_segnali = 0;
  d.continua = true;
  // lancia thread gestore 
  pthread_t gestore;
  xpthread_create(&gestore, NULL, &gbody, &d,QUI);
  
  do { // loop apparentemente senza uscita
    sleep(10); 
    puts("Mi sono svegliato");            
  } while(d.continua); 
  printf("Ricevuti: %d segnali\n", d.tot_segnali);   
  return 0;
}

