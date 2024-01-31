#include "xerrori.h"

// programma per il conteggio di numero dei primi in un
// file di testo. 
// Usa shared memory e semafori per comunicare i risultati al
// genitore

#define Sommamem "/sommaprimi"
#define Sommasem "/sommaprimi"
#define Sommasem2 "/sommaprimi2"
#define Sommasem3 "/sommaprimi3"

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


int main(int argc, char *argv[]) {
  if(argc!=2) {
    printf("Uso:\n\t%s nomefile\n",argv[0]);
    exit(1);
  }
  fprintf(stderr, "Processo %d (figlio di %d) iniziato\n",getpid(),getppid());
  // ---- creazione array memoria condivisa
  int shm_size = sizeof(int)+sizeof(long); // uso solo 4+8=12 byte di memoria condivisa (a[0])
  int fd = xshm_open(Sommamem,O_RDWR, 0660,__LINE__,__FILE__);
  int *numprimi = simple_mmap(shm_size,fd, __LINE__,__FILE__);
  long *sommaprimi = (long *) (numprimi + 1);
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
    
  // ---- apro i semafori
  sem_t *sem1 = xsem_open(Sommasem,0,0666,1,__LINE__, __FILE__);
  sem_t *sem2 = xsem_open(Sommasem2,0,0666,0,__LINE__, __FILE__);
  sem_t *sem3 = xsem_open(Sommasem3,0,0666,0,__LINE__, __FILE__);

  // segnalo al processo principale che ho
  // fatto l'accesso a shm a sem 
  xsem_post(sem2,__LINE__, __FILE__);

  // apro il file e conto i primi
  FILE *f = fopen(argv[1],"rt");
  if(f==NULL) {
    // il figlio che termina perché non esiste il file deve comunque 
    // segnalarlo al genitore con una post su sem3
    xsem_post(sem3,__LINE__, __FILE__);
    xtermina("Apertura file fallita",__LINE__, __FILE__);
  }
  while(true) {
    int e, n;
    e = fscanf(f,"%d",&n);
    if(e!=1) break;
    if(primo(n)) {
      xsem_wait(sem1,__LINE__, __FILE__);
      *numprimi += 1;
      *sommaprimi += n;
      xsem_post(sem1,__LINE__, __FILE__);
    }
  }
  fclose(f);
  fprintf(stderr, "Processo %d (figlio di %d) terminato\n",getpid(),getppid());
  // segnalo la terminazione con una post
  xsem_post(sem3,__LINE__, __FILE__);
  // chiude i semafori
  xsem_close(sem1,__LINE__, __FILE__);
  xsem_close(sem2,__LINE__, __FILE__);
  xsem_close(sem3,__LINE__, __FILE__);
  exit(0);
}

