#include "xerrori.h"

// conteggio dei primi con piu' processi utilizzando
// una singola variabile condivisa il cui accesso è
// regolato dal semaforo Nome

// un secondo semaforo Nome2 è utilizzato per permettere
// al processo padre di stabilire quando tutti i processi 
// ausiliari hanno terminato il calcolo dei primi 

// NOTA: questo programma ha solo interesse didattico:
// dal punto di vista delle prestazionei è una pessima idea 
// utilizzare una sola variabile condivisa a cui i processi 
// accedono continuamente. 

// Inoltre in questo caso i processi figli non fanno altre 
// operazioni dopo il calcolo dei primi quindi il meccanismo 
// della wait nel processo padre si potrebbe utilizzare

// La soluzione in contaprimi_shm.c è quindi preferibile



// nomi della shared memory e dei semafori
// ai nomi dei semafori viene automaticamente
// aggiunto il prefisso .sem
#define Nome "/contaprimi"
#define Nome2 "/contaprimi2"


//Prototipi
bool primo(int n);

int main(int argc,char *argv[])
{
  if(argc!=3) {
    fprintf(stderr,"Uso\n\t%s m num_processi\n", argv[0]);
    exit(1);
  }
  // conversione input
  int m= atoi(argv[1]);
  if(m<1) termina("limite primi non valido");
  int p= atoi(argv[2]);
  if(p<=0) termina("numero di processi non valido");

  // ---- creazione array memoria condivisa
  int shm_size = sizeof(int); // uso solo 4 byte di memoria condivisa (a[0])
  int fd = xshm_open(Nome,O_RDWR | O_CREAT, 0660,__LINE__,__FILE__);
  xftruncate(fd, shm_size, __LINE__,__FILE__);
  int *a = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
  xshm_unlink(Nome,__LINE__, __FILE__); // distrugge shm quando finito
  
  // ---- creo il semaforo
  sem_t *sem_a0 = xsem_open(Nome,O_CREAT|O_EXCL,0666,1,
                   __LINE__, __FILE__);
  xsem_unlink(Nome,__LINE__, __FILE__); // distrugge sem quando finito  
  // ---- creo il secondo semaforo
  sem_t *sem_finito = xsem_open(Nome2,O_CREAT|O_EXCL,0666,0,
                   __LINE__, __FILE__);
  xsem_unlink(Nome2,__LINE__, __FILE__); // distrugge sem quando finito

  
  // creazione processi figlio
  *a = 0;  // variabile condivisa
  for(int i=0; i<p; i++) {
    pid_t pid= xfork(__LINE__, __FILE__);
    if(pid==0) { //processo figlio
      int n = m/p;  // quanti numeri verifica ogni figlio + o - 
      int start = n*i; // inizio range figlio i
      int end = (i==p-1) ? m : n*(i+1);
      for(int j=start;j<end;j++)
        if(primo(j)) {
          // aspetta che il semaforo sia 1
          xsem_wait(sem_a0,__LINE__, __FILE__);
          *a += 1;
          // riporta il semaforo a 1
          xsem_post(sem_a0,__LINE__, __FILE__); 
        }
      fprintf(stderr,"Il processo %d ha terminato il conto\n",i);
      // unmap memoria condivisa perchè ho finito di usarla
      xmunmap(a,shm_size,__LINE__, __FILE__);
      // segnala al processo padre che questo processo ha finito 
      xsem_post(sem_finito,__LINE__, __FILE__);
      // chiude i semafori perché non li usa più 
      xsem_close(sem_a0,__LINE__, __FILE__);
      xsem_close(sem_finito,__LINE__, __FILE__);
      // dormo per un'ora (per mostrare che il genitore non ha bisogno che i figli terminino)
      sleep(3600); 
      exit(0);
    }
  }
  
  // codice processo padre
  // aspetta che tutti i figli abbiano fatto la post su sem_finito 
  for(int i=0; i<p; i++) 
    xsem_wait(sem_finito,__LINE__, __FILE__);
    
  // calcola e restituisce il risultato 
  printf("Numero primi tra 1 e %d (escluso): %d\n",m,*a);
  
  // chiude i semafori
  xsem_close(sem_a0,__LINE__, __FILE__);
  xsem_close(sem_finito,__LINE__, __FILE__);
  // unmap memoria condivisa e termina
  xmunmap(a,shm_size,__LINE__, __FILE__);
  return 0;
}



// restituisce true/false a seconda che n sia primo o composto
bool primo(int n)
{
  if(n<2) return false;
  if(n%2==0) {
    if(n==2)  return true;
    else return false; }
  for (int i=3; i*i<=n; i += 2) 
      if(n%i==0) return false;
  return true;
}

