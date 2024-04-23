/*
 * Esempio semplice paradigma produttore consumatori
 * Il produttore legge interi da un file e i consumatori calcolano 
 * la somma dei primi
 * 
 * Usare il numeri.py per generare lunghi elenchi di interi positivi su cui testare il programma
 * 
 * Programma di esempio del paradigma 1 producer 1 consumer
 * i dati letti dal file vengono messi su un buffer in cui il producer scrive 
 * e i consumer leggono. In principio il buffer va bene di qualsiasi dimensione: 
 * piu' e' grande maggiore e' il lavoro pronto da svolgere nel caso
 * il produttore rimanga bloccato (ad esempio a leggere dal disco)
 * 
 * */
#include "xerrori.h"

#define QUI __LINE__,__FILE__
#define Buf_size 10


// funzione per stabilire se n e' primo  
bool primo(int n)
{
  if(n<2) return false;
  if(n%2==0) return (n==2);
  for (int i=3; i*i<=n; i += 2)
      if(n%i==0) return false;
  return true;
}

// struct contenente i parametri di input e output di ogni thread 
typedef struct {
  int quanti;   // output
  long somma;   // output
  int *buffer; 
  int *pcindex;
  pthread_mutex_t *pmutex;
  sem_t *sem_free_slots;
  sem_t *sem_data_items;  
} dati;

// funzione eseguita dai thread consumer
void *tbody(void *arg)
{  
  dati *a = (dati *)arg; 
  a->quanti = 0;
  a->somma = 0;
  int n;
  puts("consumatore partito");
  do {
    xsem_wait(a->sem_data_items,__LINE__,__FILE__);
    xpthread_mutex_lock(a->pmutex,QUI);
    n = a->buffer[*(a->pcindex) % Buf_size];
    *(a->pcindex) +=1;
    xpthread_mutex_unlock(a->pmutex,QUI);
    xsem_post(a->sem_free_slots,__LINE__,__FILE__);
    if(n>0 && primo(n)) {
      a->quanti++;
      a->somma += n;
    }
  } while(n!= -1);
  puts("Consumatore sta per finire");
  pthread_exit(NULL); 
}     


int main(int argc, char *argv[])
{
  // leggi input
  if(argc!=2) {
    printf("Uso\n\t%s file\n", argv[0]);
    exit(1);
  }
  int p = 3;
  assert(p>=0);
  int tot_primi = 0;
  long tot_somma = 0;
  int e,n,cindex=0;    
  // threads related
  int buffer[Buf_size];
  int pindex=0;
  pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
  pthread_t t[p];
  dati a[p];
  sem_t sem_free_slots, sem_data_items;
  xsem_init(&sem_free_slots,0,Buf_size,__LINE__,__FILE__);
  xsem_init(&sem_data_items,0,0,__LINE__,__FILE__);
  for(int i=0;i<p;i++) {
    // faccio partire il thread i
    a[i].buffer = buffer;
    a[i].pcindex = &cindex;
    a[i].pmutex = &mu;
    a[i].sem_data_items = &sem_data_items;
    a[i].sem_free_slots = &sem_free_slots;
    xpthread_create(&t[i],NULL,tbody,a+i,__LINE__,__FILE__);
  }
  puts("Thread ausiliari creati");
  // leggi file 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) {perror("Errore apertura file"); return 1;}
  while(true) {
    e = fscanf(f,"%d", &n);
    if(e!=1) break; // se il valore e' letto correttamente e==1
    assert(n>0);    // i valori del file devono essere positivi
    xsem_wait(&sem_free_slots,__LINE__,__FILE__);
    buffer[pindex++ % Buf_size]= n;
    xsem_post(&sem_data_items,__LINE__,__FILE__);
  }
  puts("Dati del file scritti");
  // terminazione threads
  for(int i=0;i<p;i++) {
    xsem_wait(&sem_free_slots,__LINE__,__FILE__);
    buffer[pindex++ % Buf_size]= -1;
    xsem_post(&sem_data_items,__LINE__,__FILE__);
  }
  puts("Valori di terminazione scritti");
  // join dei thread e calcolo risulato
  for(int i=0;i<p;i++) {
    xpthread_join(t[i],NULL,__LINE__,__FILE__);
    tot_primi += a[i].quanti;
    tot_somma += a[i].somma;
  }
  pthread_mutex_destroy(&mu);
  fprintf(stderr,"Trovati %d primi con somma %ld\n",tot_primi,tot_somma);
  return 0;
}

