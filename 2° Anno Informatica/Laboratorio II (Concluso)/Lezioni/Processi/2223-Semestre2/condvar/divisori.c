/*
 * Esempio paradigma produttore consumatori
 * in cui abbiamo più di un produttore e più di consumatore
 * 
 * Soluzione che utilizza le condition variabiles invece dei semafori
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
  int *pdati;
  pthread_mutex_t *mutex;
  pthread_cond_t *empty;
  pthread_cond_t *full;
  FILE *outfile;  
  pthread_mutex_t *mutex_file;
} dati_consumatori;

// struct contenente i parametri di input 
// per i thread produttori
typedef struct {
  int *buffer; 
  int *ppindex;
  int *pdati;
  pthread_mutex_t *mutex;
  pthread_cond_t *empty;
  pthread_cond_t *full;
  char *nomefile;  
} dati_produttori;



// funzione eseguita dai thread consumer
void *cbody(void *arg)
{  
  dati_consumatori *a = (dati_consumatori *)arg; 

  puts("consumatore partito");
  int n;
  do {
    xpthread_mutex_lock(a->mutex,QUI);
    while(*(a->pdati)==0) {
      // attende fino a quando il buffer è vuoto
      xpthread_cond_wait(a->empty,a->mutex,QUI);
    }
    n = a->buffer[*(a->pcindex) % Buf_size];
    *(a->pcindex) += 1;
    *(a->pdati) -= 1;
    // segnala che il buffer non è più pieno
    xpthread_cond_signal(a->full,QUI);
    xpthread_mutex_unlock(a->mutex,QUI);
    if(n<0) break; 
    int div = divisori(n);
    xpthread_mutex_lock(a->mutex_file,QUI);
    fprintf(a->outfile,"%d %d\n",n,div);
    xpthread_mutex_unlock(a->mutex_file,QUI);
  } while(true);
  puts("Consumatore sta per finire");
  pthread_exit(NULL); 
}     

// funzione eseguita dai thread producer
void *pbody(void *arg)
{  
  dati_produttori *a = (dati_produttori *)arg; 

  printf("produttore partito sul file: %s\n",a->nomefile);
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
    xpthread_mutex_lock(a->mutex,QUI);
    while(*(a->pdati)==Buf_size) {
      // attende fino a quando il buffer rimane pieno 
      xpthread_cond_wait(a->full,a->mutex,QUI);
    }
    a->buffer[*(a->ppindex) % Buf_size] = n;
    *(a->ppindex) += 1;
    *(a->pdati) += 1;
    // segnala che il buffer non è più vuoto
    xpthread_cond_signal(a->empty,QUI);
    xpthread_mutex_unlock(a->mutex,QUI);
  } while(true);
  puts("produttore sta per finire");
  pthread_exit(NULL); 
}     


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
  int pindex=0, cindex=0, dati=0;
  pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mufile = PTHREAD_MUTEX_INITIALIZER;
  pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
  pthread_cond_t full = PTHREAD_COND_INITIALIZER;

  // dati per i thread
  dati_produttori ap[tp];
  dati_consumatori ac[tc];
  pthread_t prod[tp];       // id thread produttori
  pthread_t cons[tc];       // id thread consumatori 

  // creo tutti i produttori
  for(int i=0;i<tp;i++) {
    ap[i].ppindex = &pindex;
    ap[i].pdati = &dati;
		ap[i].buffer = buffer;
    ap[i].mutex = &mu;
		ap[i].empty = &empty;
		ap[i].full = &full;
    ap[i].nomefile = argv[i+1];
    xpthread_create(&prod[i], NULL, &pbody, &ap[i],QUI);     
  }
  // creo tutti i consumatori
  for(int i=0;i<tc;i++) {
    ac[i].pcindex = &cindex;
    ac[i].pdati = &dati;
		ac[i].buffer = buffer;
    ac[i].mutex = &mu;
    ac[i].mutex_file = &mufile;
		ac[i].empty = &empty;
		ac[i].full = &full;
    ac[i].outfile = outfile;
    xpthread_create(&cons[i], NULL, &cbody, &ac[i],QUI);     
  }

  // attendo i produttori
  for(int i=0;i<tp;i++) 
    pthread_join(prod[i],NULL);

  // comunico ai consumatori che possono terminare
  for(int i=0;i<tc;i++) {
    xpthread_mutex_lock(&mu,QUI);
    while(dati==Buf_size) {
      xpthread_cond_wait(&full,&mu,QUI);
    }
    buffer[pindex % Buf_size] = -1;
    pindex += 1;
    dati += 1;
    xpthread_cond_signal(&empty,QUI);
    xpthread_mutex_unlock(&mu,QUI);
  }
  // attendo i consumatori 
  for(int i=0;i<tc;i++) 
    pthread_join(cons[i],NULL);
  // deallocazione, saluti, etc....
  xpthread_mutex_destroy(&mu,QUI);
  xpthread_mutex_destroy(&mufile,QUI);
  xpthread_cond_destroy(&empty,QUI);
  xpthread_cond_destroy(&full,QUI);
  return 0;
}
