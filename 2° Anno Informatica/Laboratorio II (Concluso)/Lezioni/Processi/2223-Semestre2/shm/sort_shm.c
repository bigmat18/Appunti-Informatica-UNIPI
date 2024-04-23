#include "xerrori.h"
#include <time.h>

// algoritmo di sorting con 2 processi e memoria condivisa


// nome della shared memory 
#define Nome "/array"

// funzione di comparazione per qsort
int cmp(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}


int main(int argc,char *argv[])
{
  if(argc!=2) {
    fprintf(stderr,"Uso\n\t%s dim_array\n", argv[0]);
    exit(1);
  }
  // conversione input
  int n= atoi(argv[1]);
  if(n<=1) termina("dimensione non valida");

  // ---- creazione array memoria condivisa
  int shm_size = n*sizeof(int); // un intero x processo
  int fd = xshm_open(Nome,O_RDWR | O_CREAT, 0660,__LINE__,__FILE__);
  xftruncate(fd, shm_size, __LINE__,__FILE__);
  int *a = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
  // non effettuo la cancellazione per poter esaminare l'array dalla linea di comando
  // xshm_unlink(Nome,__LINE__, __FILE__); 

  // ---- inizializza array condiviso con interi random
  srand(1); // iniializza numeri casuali con lo stesso seed
  for(int i=0; i<n; i++) 
    a[i] = rand()%100000;
  int m = n/2;
  sleep(20);

  // durante la pausa di 20 secondi 
  // posso vedere l'array da ordinare in /dev/shm/array
  // con od -An -td4 /dev/shm/array
  puts("riprendo...");

  // ---- crea processo figlio  
  pid_t pid= xfork(__LINE__, __FILE__);
  if (pid != 0) {
    // processo pafre ordina la prima metà
    qsort(a, m, sizeof(int), cmp);
  }
  else
  { // processo figlio ordina la seconda metà
    qsort(a+m, n-m, sizeof(int), cmp);
    // unmap memoria condivisa perchè ho finito di usarla
    xmunmap(a, shm_size, __LINE__, __FILE__);
    // figlio termina
    exit(0);
  }
  // genitore aspetta che abbia finito il figlio:
  if(wait(NULL)<0)
    xtermina("Errore wait",__LINE__, __FILE__);
    
  // il processo genitore ha ordinato solo la prima metà ma
  // "magicamente" si trova orinata anche la seconda metà   
  // Manca il merge delle due metà ma posso vedere le due metà 
  // dell'array ordinate sempre in /dev/shm/array 


  // unmap memoria condivisa e termina
  xmunmap(a,shm_size,__LINE__, __FILE__);
  return 0;

  // non dimenticare di cancellare il file /dev/sham/array altrimenti
  // rimane ad occupare memoria fino al prossimo reboot 
}



