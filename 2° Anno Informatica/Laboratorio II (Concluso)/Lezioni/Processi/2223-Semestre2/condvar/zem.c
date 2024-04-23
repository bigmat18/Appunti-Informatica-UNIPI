#include "xerrori.h"
#define QUI __LINE__,__FILE__


// Realizzazione di un semaforo usando mutex+condition variable

// il semaforo blocca solo sullo 0 mentre
// con una condition variable abbiamo visto che ci si può
// bloccare su condizioni più complesse, quindi è più generale 

// un semaforo si può realizzare con mutex + condition var
// come mostrato qui sotto. Notate che otteniamo un semaforo 
// che supporta incrementi diversi da +- 1


// struttura rappresentante il semaforo
typedef struct {
  int tot;  // valore del semaforo, non deve mai diventare negativo
  pthread_cond_t cond;   // condition variable
  pthread_mutex_t mutex; // mutex associato alla condition variable
} zem;


// inzializza semaforo al valore q
// deve essere chiamata prima di up e down
void zem_init(zem *z, int q)
{
	assert(q>=0);
  z->tot = q;
  xpthread_cond_init(&z->cond,NULL,QUI);
  xpthread_mutex_init(&z->mutex,NULL,QUI);
}

// analoga alla sem_wait (operazione P di Dijkstra)
void zem_down(zem *z, int q)
{
	assert(q>0);
  pthread_mutex_lock(&z->mutex);
  while(z->tot-q<0)
    pthread_cond_wait(&z->cond,&z->mutex);
  z->tot -= q;
  pthread_mutex_unlock(&z->mutex);
}

// analoga alla sem_post (operazione V di Dijkstra)
void zem_up(zem *z, int q)
{
	assert(q>0);
  pthread_mutex_lock(&z->mutex);
  z->tot+=q;
  pthread_cond_broadcast(&z->cond);
  pthread_mutex_unlock(&z->mutex);
}
