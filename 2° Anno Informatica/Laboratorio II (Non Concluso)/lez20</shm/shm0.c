#include "xerrori.h"


// conteggio dei primi con piu' processi utilizzando
// un array condiviso 

// nome della shared memory 
#define Nome "/prova"

//Prototipi
bool primo(int n);

int main(int argc,char *argv[])
{
  if(argc!=2) {
    fprintf(stderr,"Uso\n\t%s m", argv[0]);
    exit(1);
  }
  // conversione input
  int n= atoi(argv[1]);
  if(n<1) termina("limite non valido");

  // ---- creazione array memoria condivisa
  int shm_size = n*sizeof(int); // un intero x processo
  int fd = xshm_open(Nome,O_RDWR | O_CREAT, 0660,__LINE__,__FILE__);
  xftruncate(fd, shm_size, __LINE__,__FILE__);
  int *a = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
  // scommentare per prenotare la cancellazione dell'oggetto nella shared memory 
  // xshm_unlink(Nome,__LINE__, __FILE__); // distrugge shm quando finito
  
  // riempio array
  for(int i=0; i<n; i++) {
    a[i] = i;
  }
  
  // unmap memoria condivisa e termina
  xmunmap(a,shm_size,__LINE__, __FILE__);
  // avendo commentato xshm_unlink() l'oggetto /dev/sham/prova
  // rimane nel filesystem (e occupa il relativo spazio fino al prossimo boot)
  return 0;
}

