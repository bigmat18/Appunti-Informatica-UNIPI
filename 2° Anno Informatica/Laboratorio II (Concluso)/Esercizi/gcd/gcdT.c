#include "xerrori.h"
#include <stdbool.h> // gestisce tipo bool

// macro per indicare la posiine corrente
#define QUI __LINE__,__FILE__

// dimensione buffer produttori-consumatori
#define Buf_size 20

typedef struct {
  int *buffer;
  int *index;
  int *pindex;
  pthread_mutex_t *mutex_buf;
  pthread_mutex_t *mutex_file;
  pthread_cond_t *empty;
  pthread_cond_t *full;
  int *end;
  FILE *file;
} thread_data;

int gcd(int a, int b) {
	assert(a>=0 && b>=0);
	assert(a!=0 || b!=0);
  if(b==0) return a;
  return gcd(b,a%b);
}

int cmpfunc(const void *a, const void *b){
  return (*(int *)a - *(int *)b);
}

void *tbody(void *arg){
  thread_data *data = (thread_data*)arg;
  //puts("Consumer starts");

  int e;
  int n1, n2, result = 0;
  do {
    xpthread_mutex_lock(data->mutex_file, QUI);
    e = fscanf(data->file, "%d %d", &n1, &n2);
    xpthread_mutex_unlock(data->mutex_file, QUI);

    if (e != 2) result = -1;
    else result = gcd(n1, n2);

    xpthread_mutex_lock(data->mutex_buf, QUI);
    while(*(data->index) == Buf_size){
      xpthread_cond_wait(data->empty, data->mutex_buf, QUI);
    }
    data->buffer[*(data->pindex) % Buf_size] = result;
    *(data->index) += 1;
    *(data->pindex) += 1;

    xpthread_cond_signal(data->empty, QUI);
    xpthread_mutex_unlock(data->mutex_buf, QUI);

  }while(e == 2);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  if(argc!=3) {
      printf("Uso: %s file numT\n",argv[0]);
      return 1;
  }

  FILE *file = xfopen(argv[1], "rt", QUI);
  if (file == NULL) xtermina("impossibile aprire outfile", QUI);

  int buffer[Buf_size];
  int index = 0;
  int pindex = 0;
  int cindex = 0;

  pthread_mutex_t mutexFile = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_t mutexBuffer = PTHREAD_MUTEX_INITIALIZER;
  pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
  pthread_cond_t full = PTHREAD_COND_INITIALIZER;

  int threadsSize = atoi(argv[2]);
  pthread_t threads[threadsSize];
  thread_data data[threadsSize];
  int end = 0;

  for(unsigned int i = 0; i < threadsSize; i++){
    data[i].buffer = buffer;
    data[i].index = &index;
    data[i].empty = &empty;
    data[i].full = &full;
    data[i].file = file;
    data[i].mutex_buf = &mutexBuffer;
    data[i].mutex_file = &mutexFile;
    data[i].end = &end;
    data[i].pindex = &pindex;

    xpthread_create(&threads[i], NULL, &tbody, &data[i], QUI);
  }
  int size = 10;
  int indexRes = 0;
  int *result = malloc(size * sizeof(int));

  do {
    xpthread_mutex_lock(&mutexBuffer, QUI);
  
    while(index == 0){
      xpthread_cond_wait(&empty, &mutexBuffer, QUI);
    }

    int n = buffer[cindex % Buf_size];
    index--;
    cindex++;

    if(n != -1){
      if(indexRes == size) {
        size += 10;
        result = realloc(result, size * sizeof(int));
      } 
      result[indexRes] = n;
      indexRes++;
    } else end++;

    xpthread_cond_signal(&full, QUI);
    xpthread_mutex_unlock(&mutexBuffer, QUI);

  } while (end != threadsSize);

  fclose(file);

  size = indexRes;
  result = realloc(result, size * sizeof(int));

  qsort(result, size, sizeof(int), cmpfunc);

  for(int i = 0; i < size; i++) 
    fprintf(stdout, "%d\n", result[i]);

  return 0;
}

