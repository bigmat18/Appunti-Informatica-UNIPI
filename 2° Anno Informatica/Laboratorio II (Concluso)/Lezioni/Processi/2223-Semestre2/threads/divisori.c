/*
 * Esempio paradigma produttore consumatori
 * in cui abbiamo più di un produttore e 
 * più di consumatore
 * 
 * I produttori leggono gli interi dai file e li scrivono 
 * nel buffer, i consumatori calcolano il numero di 
 * divisori di ogni intero
 * 
 * */
#include "xerrori.h"


#define QUI __LINE__,__FILE__
#define Buf_size 10


// funzione (inefficiente) per contare il numero di divisori 
int divisori(int n)
{
  assert(n>0);
  int d = 0;
  for (int i=1; i<=n; i ++)
      if(n%i==0) d++;
  return d;
}

// struct contenente i parametri di input 
// per i thread consumatori 
typedef struct {
  int *buffer; 
  int *pcindex;
  pthread_mutex_t *pmutex_buf;
  pthread_mutex_t *pmutex_file;
  sem_t *sem_free_slots;
  sem_t *sem_data_items;
  FILE *outfile;  
} dati_consumatori;

// struct contenente i parametri di input 
// per i thread produttori
typedef struct {
  int *buffer; 
  int *ppindex;
  pthread_mutex_t *pmutex_buf;
  sem_t *sem_free_slots;
  sem_t *sem_data_items;
  char *nomefile;  
} dati_produttori;



// funzione eseguita dai thread consumer
void *cbody(void *arg)
{  
  dati_consumatori *a = (dati_consumatori *)arg; 

  puts("consumatore partito");
  int n;
  do {
    xsem_wait(a->sem_data_items,__LINE__,__FILE__);
    xpthread_mutex_lock(a->pmutex_buf,QUI);
    n = a->buffer[*(a->pcindex) % Buf_size];
    *(a->pcindex) +=1;
    xpthread_mutex_unlock(a->pmutex_buf,QUI);
    xsem_post(a->sem_free_slots,__LINE__,__FILE__);
    int div = divisori(n);
    xpthread_mutex_lock(a->pmutex_file,QUI);
    fprintf(a->outfile,"%d %d\n",n,div);
    xpthread_mutex_unlock(a->pmutex_file,QUI);
  } while(n!= -1);
  puts("Consumatore sta per finire");
  pthread_exit(NULL); 
}     

// funzione eseguita dai thread producer
void *pbody(void *arg)
{  
  dati_produttori *a = (dati_produttori *)arg; 

  puts("produttore partito");
  // apre il file e termina se non riesce
  FILE *f = fopen(a->nomefile,"rt");
  if(f==NULL) {
    fprintf(stderr,"Apertura file %s fallita\n",a->nomefile);
    pthread_exit(NULL); 
  }
  int n;
  do {
    int e = fscanf(f,"%d",&n);
    if(e!=1) break;
    xsem_wait(a->sem_free_slots,QUI);
    xpthread_mutex_lock(a->pmutex_buf,QUI);
    a->buffer[*(a->ppindex) % Buf_size] = n;
    *(a->ppindex) +=1;
    xpthread_mutex_unlock(a->pmutex_buf,QUI);
    xsem_post(a->sem_data_items,QUI);
  } while(true);
  puts("produttore sta per finire");
  pthread_exit(NULL); 
}     

// main: da completare
int main(int argc, char *argv[])
{
  // leggi input
  if(argc<4) {
    printf("Uso\n\t%s file1 [file2 ...] outfile numt\n", argv[0]);
    exit(1);
  }
  // numero di thread prod e consumatori
  int tp = argc-3;
  int tc = atoi(argv[argc-1]);
  assert(tp>0);
  assert(tc>0);
  FILE* outfile = fopen(argv[argc-2],"wt");
  if(outfile==NULL)
    xtermina("impossibile aprire outfile",QUI);

  // buffer produttori-consumatori
  int buffer[Buf_size];
  int pindex=0, cindex=0;
  pthread_mutex_t mupbuf = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mucbuf = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mucfile = PTHREAD_MUTEX_INITIALIZER;
  sem_t sem_free_slots, sem_data_items;
  xsem_init(&sem_free_slots,0,Buf_size,__LINE__,__FILE__);
  xsem_init(&sem_data_items,0,0,__LINE__,__FILE__);

  // dati per i thread
  dati_produttori ap[tp];
  dati_consumatori ac[tc];
  pthread_t prod[tp];       // id thread produttori
  pthread_t cons[tc];       // id thread consumatori 


  // Da completare:

  // creo tutti i produttori
  // creo tutti i consumatori

  // attendo i produttori

  // comunico ai consumatori che possono terminare
  // attendo i consumatori 

  // deallocazione, saluti, etc....

  return 0;
}

