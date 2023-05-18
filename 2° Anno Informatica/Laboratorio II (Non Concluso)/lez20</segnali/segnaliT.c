#include "xerrori.h"
#define QUI __LINE__,__FILE__

// esperimenti con i segnali
//   esempio segnali diretti ai thread 
//   handler vs sigwait
//     * se un thread usa sia un handler che sigwait i segnali
//       li gestisce sigwait
//     * se il messaggio è in viato al processo con kill(getpid())
//       la gestione viene fatta da thread principale  
//     * se blocco tutti i segnali nel main gestisce tutto il 
//       thread gestore 


#if 0
// ridefinizione funzione gettid() (non è sempre disponibile) 
#include <sys/syscall.h>   /* For SYS_xxx definitions */
pid_t gettid(void)
{
	#ifdef __linux__
	  // il tid è specifico di linux
    pid_t tid = (pid_t)syscall(SYS_gettid);
    return tid;
  #else
	  // per altri OS restituisco -1
	  return -1;
  #endif
}
#endif


// il tipo sig_atomic_t è intero e garantisce che
// le operazioni sulla variabile siano atomic anche in 
// presenza di interrupt causati dai segnali  
volatile sig_atomic_t continua =1;

// handler async-signal safe
void mysafehandler(int s)
{
  char b[] = "Segnale XX gestito da mysafehandler\n";
  b[8] = '0' + s/10; // scrivo i codici ascii delle cifre del segnale
  b[9] = '0' + s%10; // in b[8] e b[9]
  // uso gettid che non è async-signal-safe
  int t = gettid(); b[34] = '0' + t%10; b[33] = '0' + (t/10)%10;
  int e = write(1,b,36);  // 1 è il file descriptor di stdout
  (void) e;               // evita warning "unused variable"   
  if(s==SIGUSR2)
     continua = 0;  // per uscire dal ciclo 
}


// thread nulla facente
// mostra il funzionamento di pause() e gettid() 
void *tbody(void *v) {
  while(true) {
    pause();
    printf("====== Thread %d svegliato\n",gettid());
  }
  return NULL;
}

// thread che effettua la gestione di tutti i segnali
void *tgestore(void *v) {
  sigset_t mask;
  sigfillset(&mask);
  int s;
  while(true) {
    int e = sigwait(&mask,&s);
    if(e!=0) perror("Errore sigwait");
    printf("------ Thread gestore %d ha ricevuto il segnale %d\n",gettid(),s);
  }
  return NULL;
}


int main (void) {
  // definisce signal handler per SIGINT USR1 e USR2
  struct sigaction sa;
  sigaction(SIGINT,NULL,&sa);    // copio sigaction corrente di SIGINT
  sa.sa_handler = mysafehandler; // definisco funzione di gestione
  sigaction(SIGINT,&sa,NULL);    // assegno sigaction
  sigaction(SIGUSR1,&sa,NULL);    
  sigaction(SIGUSR2,&sa,NULL);    
  
  // blocco i segnali tranne sigquit
  sigset_t mask;
  sigfillset(&mask);  // insieme di tutti i segnali
  sigdelset(&mask,SIGQUIT); // elimino sigquit dal'insieme
  pthread_sigmask(SIG_BLOCK,&mask,NULL); // blocco tutto tranne sigquit
  
  // creo nuovi thread che ereditano i settaggi dei segnali
  pthread_t t[3];
  xpthread_create(&t[0],NULL,tbody,NULL,QUI);     // thread nullafacenti
  xpthread_create(&t[1],NULL,tbody,NULL,QUI);
  xpthread_create(&t[2],NULL,tgestore,NULL,QUI);  // thread gestore segnali
    

  continua=1;
  while (continua) {
      sleep(4);
      // invia segnale USR1 a t[0], t[1], t[2] alternativamente
      // pthread_kill(t[++continua%3],SIGUSR1);
      kill(getpid(), SIGUSR1);
      // puts("main svegliato");
  }
  puts("Uscito dal ciclo");
  return 0 ;
}
