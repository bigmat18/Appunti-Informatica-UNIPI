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

#define QUI __LINE__, __FILE__
#define Buf_size 10

// funzione (inefficiente) per contare il numero di divisori
int divisori(int n) {
  assert(n > 0);
  int d = 0;
  for (int i = 1; i <= n; i++)
    if (n % i == 0)
      d++;
  return d;
}

typedef struct {
  int *buffer;
  char *fileName;
  int *pindex;
  sem_t *sem_free_slots;
  sem_t *sem_data_items;
  pthread_mutex_t *mutexBuffer;
} prod_data;

typedef struct {
  int *buffer;
  FILE *file;
  int *cindex;
  sem_t *sem_free_slots;
  sem_t *sem_data_items;
  pthread_mutex_t *mutexBuffer;
  pthread_mutex_t *mutexFile;
} cons_data;

// funzione eseguita dai thread consumer
void *cbody(void *arg) {
  cons_data *data = (cons_data *)arg;
  int n;
  do {
    xsem_wait(data->sem_data_items, QUI);
    xpthread_mutex_lock(data->mutexBuffer, QUI);
    n = data->buffer[*(data->cindex) % Buf_size];
    printf("C: %d - %d\n", *(data->cindex) % Buf_size, n);
    *(data->cindex) += 1;
    xsem_post(data->sem_free_slots, QUI);
    xpthread_mutex_unlock(data->mutexBuffer, QUI);

    if (n == -1)
      break;

    xpthread_mutex_lock(data->mutexFile, QUI);
    fprintf(data->file, "%d %d\n", n, divisori(n));
    xpthread_mutex_unlock(data->mutexFile, QUI);

  } while (true);
  pthread_exit(NULL);
}

// funzione eseguita dai thread producer
void *pbody(void *arg) {
  prod_data *data = (prod_data *)arg;
  FILE *file = xfopen(data->fileName, "rt", QUI);
  if (file == NULL)
    xtermina("Errore apertura file", QUI);
  int e, n;
  do {
    e = fscanf(file, "%d", &n);
    if (e != 1)
      n = -1;

    xsem_wait(data->sem_free_slots, QUI);
    xpthread_mutex_lock(data->mutexBuffer, QUI);
    data->buffer[*(data->pindex) % Buf_size] = n;
    printf("P: %d - %d\n", *(data->pindex) % Buf_size, n);
    *(data->pindex) += 1;
    xsem_post(data->sem_data_items, QUI);
    xpthread_mutex_unlock(data->mutexBuffer, QUI);
  } while (n != -1);
  fclose(file);
  pthread_exit(NULL);
}

// main: da completare
int main(int argc, char *argv[]) {
  // leggi input
  if (argc < 4) {
    printf("Uso\n\t%s file1 [file2 ...] outfile numt\n", argv[0]);
    exit(1);
  }

  FILE *outFile = xfopen(argv[argc - 2], "wt", QUI);
  if (outFile == NULL)
    xtermina("Error file opens", QUI);

  int numProdThreads = argc - 3;
  int numConsThreads = atoi(argv[argc - 1]);

  int buffer[Buf_size];
  int pindex = 0, cindex = 0;

  sem_t sem_free_slots, sem_data_items;
  pthread_mutex_t mutexPBuffer = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mutexCBuffer = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mutexFile = PTHREAD_MUTEX_INITIALIZER;
  xsem_init(&sem_free_slots, 0, Buf_size, __LINE__, __FILE__);
  xsem_init(&sem_data_items, 0, 0, __LINE__, __FILE__);

  pthread_t prod[numProdThreads];
  pthread_t cons[numConsThreads];

  prod_data prodData[numProdThreads];
  cons_data consData[numConsThreads];

  for (int i = 0; i < numProdThreads; i++) {
    prodData[i].buffer = buffer;
    prodData[i].fileName = argv[i + 1];
    prodData[i].mutexBuffer = &mutexPBuffer;
    prodData[i].pindex = &pindex;
    prodData[i].sem_data_items = &sem_data_items;
    prodData[i].sem_free_slots = &sem_free_slots;

    xpthread_create(&prod[i], NULL, &pbody, &prodData[i], QUI);
  }

  for (int i = 0; i < numConsThreads; i++) {
    consData[i].buffer = buffer;
    consData[i].cindex = &cindex;
    consData[i].file = outFile;
    consData[i].mutexFile = &mutexFile;
    consData[i].mutexBuffer = &mutexCBuffer;
    consData[i].sem_data_items = &sem_data_items;
    consData[i].sem_free_slots = &sem_free_slots;

    xpthread_create(&cons[i], NULL, &cbody, &consData[i], QUI);
  }

  for (int i = 0; i < numProdThreads; i++) {
    printf("Attendo thread prod %d\n", i);
    xpthread_join(prod[i], NULL, QUI);
  }

  for (int i = 0; i < numConsThreads; i++) {
    xsem_wait(&sem_free_slots, QUI);
    xpthread_mutex_lock(&mutexPBuffer, QUI);
    buffer[pindex % Buf_size] = -1;
    printf("P: %d - %d\n", pindex % Buf_size, -1);
    pindex += 1;
    xsem_post(&sem_data_items, QUI);
    xpthread_mutex_unlock(&mutexPBuffer, QUI);
  }

  printf("Inizio ad attendere consumatori\n");
  for (int i = 0; i < numConsThreads; i++) {
    printf("Attendo thread cons %d\n", i);
    xpthread_join(cons[i], NULL, QUI);
  }

  xpthread_mutex_destroy(&mutexPBuffer, QUI);
  xpthread_mutex_destroy(&mutexCBuffer, QUI);
  xpthread_mutex_destroy(&mutexFile, QUI);

  xsem_destroy(&sem_data_items, QUI);
  xsem_destroy(&sem_free_slots, QUI);

  fclose(outFile);
  return 0;
}