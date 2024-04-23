#include "xerrori.h"

#define QUI __LINE__, __FILE__

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

bool primo(int n) {
  if(n<2) return false;
  if(n%2==0) {
    if(n==2)  return true;
    else return false; }
  for (int i=3; i*i<=n; i += 2) 
      if(n%i==0) return false;
  return true;
}

int main(int argc, char *argv[]) {
  if(argc!=3) {
    fprintf(stderr,"Uso\n\t%s m num_processi\n", argv[0]);
    exit(1);
  }
  // conversione input
  int num_primi= atoi(argv[1]);
  if(num_primi<1) termina("limite primi non valido");
  int num_proc= atoi(argv[2]);
  if(num_proc<=0) termina("numero di processi non valido");

  int shm_size = sizeof(int);
  int fd = xshm_open(Nome, O_RDWR | O_CREAT, 0660, QUI);
  xftruncate(fd, shm_size, QUI);
  int *memory = simple_mmap(shm_size, fd, QUI);
  close(fd);
  xshm_unlink(Nome, QUI);

  sem_t *sem_memory = xsem_open(Nome, O_CREAT | O_EXCL, 0666, 1, QUI);
  xsem_unlink(Nome, QUI);
  sem_t *sem_ended = xsem_open(Nome2, O_CREAT | O_EXCL, 0666, 0, QUI);
  xsem_unlink(Nome2, QUI);

  *memory = 0;
  for(int i = 0; i < num_proc; i++){
    pid_t pid = xfork(QUI);
    if(pid == 0){
      int n = num_primi / num_proc;
      int start = n * i;
      int end = (i == num_proc - 1) ? num_primi : n * (i + 1);

      for(int j = start; j < end; j++){
        if(primo(j)){
          xsem_wait(sem_memory, QUI);
          *memory += 1;
          xsem_post(sem_memory, QUI);
        }
      }
      xmunmap(memory, shm_size, QUI);
      xsem_post(sem_ended, QUI);

      xsem_close(sem_memory, QUI);
      xsem_close(sem_ended, QUI);

      exit(0);
    }
  }

  for(int i = 0; i<num_proc; i++){
    xsem_wait(sem_ended, QUI);
  }

  printf("Numero primi tra 1 e %d (escluso): %d\n", num_primi, *memory);

  xsem_close(sem_memory, __LINE__, __FILE__);
  xsem_close(sem_ended, __LINE__, __FILE__);

  xmunmap(memory, shm_size, __LINE__, __FILE__);

  return 0;
}