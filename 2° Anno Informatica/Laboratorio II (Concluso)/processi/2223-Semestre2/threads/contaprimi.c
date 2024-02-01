#include "xerrori.h"

// conteggio dei primi con thread multipli

// NOTA: questo programma ha solo interesse didattico!
// dal punto di vista delle prestazionei è una pessima idea 
// utilizzare una sola variabile condivisa a cui i thread 
// accedono continuamente. 

// Inoltre in questo caso i thread ausiliari non fanno altre 
// operazioni dopo il calcolo dei primi quindi il meccanismo 
// della join si potrebbe utilizzare per comunicare
// la terminazione al thread principale

//Prototipi
bool primo(int n);

// struct che uso per passare argomenti ai thread
typedef struct {
	int start;      // intervallo dove cercare i primo 
	int end;
  sem_t *a0;      // puntatore al semaforo a0x
  sem_t *finito;  // puntatore al semaforo finitox
  int *somma;     // puntatore alla somma condivisa 
} dati;

// funzione passata a pthred_create
void *tbody(void *v) {
	dati *d = (dati *) v;
	// cerco i primi nell'intervallo assegnato
	for(int j=d->start;j<d->end;j++) {
    if (primo(j)) {
      // aspetta che il semaforo sia 1
      xsem_wait(d->a0, __LINE__, __FILE__);
      *(d->somma) += 1;
      // riporta il semaforo a 1
      xsem_post(d->a0, __LINE__, __FILE__);
    }
  }
  fprintf(stderr,"Il thread che partiva da %d ha terminato\n",d->start);
  // segnala al processo padre che questo processo ha finito 
	xsem_post(d->finito,__LINE__, __FILE__);
  pthread_exit(NULL);
}


int main(int argc,char *argv[])
{
  if(argc!=3) {
    fprintf(stderr,"Uso\n\t%s m num_threads\n", argv[0]);
    exit(1);
  }
  // conversione input
  int m= atoi(argv[1]);
  if(m<1) termina("limite primi non valido");
  int p= atoi(argv[2]);
  if(p<=0) termina("numero di thread non valido");

  // ---- creo i semafori (senza nome)
	sem_t sem_a0x, sem_finitox;
  // inizalizzo sem_a0x e sem_finitox
	xsem_init(&sem_a0x,0,1,__LINE__, __FILE__);
	xsem_init(&sem_finitox,0,0,__LINE__, __FILE__);

  // creazione thread ausiliari
  pthread_t t[p];   // array di p indentificatori di thread 
	dati d[p];        // array di p struct che passerò allle p thread
	int somma = 0;        // variabile dove accumulo il numero di primi
  for(int i=0; i<p; i++) {
    int n = m/p;  // quanti numeri verifica ogni figlio + o - 
    d[i].start = n*i; // inizio range figlio i
    d[i].end = (i==p-1) ? m : n*(i+1);
		d[i].a0 = &sem_a0x;
		d[i].finito = &sem_finitox;
		d[i].somma = &somma;
    xpthread_create(&t[i], NULL, &tbody, &d[i],__LINE__, __FILE__); 
  }

  // aspetta che abbiano finito tutti i thread ausiliari
  // utilizzando il semaforo sem_finitox
  for(int i=0; i<p; i++) 
		xsem_wait(&sem_finitox,__LINE__, __FILE__);

  // distrugge i semafor 
  xsem_destroy(&sem_a0x,__LINE__, __FILE__);  
  xsem_destroy(&sem_finitox,__LINE__, __FILE__);  

  // restituisce il risultato 
  printf("Numero primi tra 1 e %d (escluso): %d\n",m,somma);
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

