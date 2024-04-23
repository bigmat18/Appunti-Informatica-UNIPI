#include "xerrori.h"

// calcola il numero e la somma dei primi contenuti
// alcuni file di testo 
// utilizza dei processi ausiliari per il conteggio
// la comunicazione avviene attraverso 
// shared memory e con il controllo di alcuni semafori 

#define Sommamem "/sommaprimi"
#define Sommasem "/sommaprimi"
#define Sommasem2 "/sommaprimi2"
#define Sommasem3 "/sommaprimi3"



int main(int argc, char *argv[])
{ 
  if(argc<2) {
    printf("Uso:\n\t%s file1 [file2 file3 ...] \n",argv[0]);
    exit(1);
  }

  // ---- creazione array memoria condivisa
  int shm_size = sizeof(int)+sizeof(long); // uso solo 4+8=12 byte di memoria condivisa (a[0])
  int fd = xshm_open(Sommamem,O_RDWR | O_CREAT, 0660,__LINE__,__FILE__);
  xftruncate(fd, shm_size, __LINE__,__FILE__);
  // int *nump = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  // long *sommap = (long *) (nump + 1);
  // versione alternativa
  char *tmp = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  int *nump = (int *) (tmp);
  long *sommap = (long *) (tmp + 4);
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
    
  // ---- creo i semafori
  sem_t *sem1 = xsem_open(Sommasem,O_CREAT|O_EXCL,0666,1,__LINE__, __FILE__);
  sem_t *sem2 = xsem_open(Sommasem2,O_CREAT|O_EXCL,0666,0,__LINE__, __FILE__);
  sem_t *sem3 = xsem_open(Sommasem3,O_CREAT|O_EXCL,0666,0,__LINE__, __FILE__);
  // inizializzo variabili condivise 
  *nump = 0;
  *sommap = 0;

  // faccio partire i processi ausiliari
  int aux = argc-1;            // numero processi ausiliari
  for(int i=0;i<aux;i++) {
    if(xfork(__LINE__,__FILE__)==0) {
      if(execl("sommaprimi_aux.out", "sommaprimi_aux.out", argv[i+1], (char *) NULL)==-1)
        xtermina("exec fallita",__LINE__,__FILE__);
    }
  }

  // quando sono sicuro che i processi ausiliari hanno
  // aperto shm e semafori procedo a prenotare la cancellazione
  // attendo che i figli abbiano fatto sem_post su sem2
  for(int i=0;i<aux;i++)
    xsem_wait(sem2,__LINE__, __FILE__);
  xshm_unlink(Sommamem,__LINE__, __FILE__);  // distrugge shm quando finito
  xsem_unlink(Sommasem,__LINE__, __FILE__);  // distrugge sem quando finito  
  xsem_unlink(Sommasem2,__LINE__, __FILE__); // distrugge sem quando finito
  xsem_unlink(Sommasem3,__LINE__, __FILE__); // distrugge sem quando finito

  // attendo che i processi figli siano terminati
  // prima possibilità: attendo la terminazione dei figli con wait(2)
  // for(int i=0;i<aux;i++)
  //  xwait(NULL,__LINE__, __FILE__);
  // seconda possibilità: attendo che ogni processo esegua una sem_post(3)
  // su sem3 per indicare che ha concluso il calcolo 
  for(int i=0;i<aux;i++)
    xsem_wait(sem3,__LINE__, __FILE__);


  // ora che tutti i figli hanno terminato posso stampare il risultato
  printf("Numero primi: %d, Somma: %ld\n",*nump,*sommap);
  // chiude i semafori
  xsem_close(sem1,__LINE__, __FILE__);
  xsem_close(sem2,__LINE__, __FILE__);
  xsem_close(sem3,__LINE__, __FILE__);

  fprintf(stderr, "Io %d ho finito.\n",getpid());
  return 0;
}



