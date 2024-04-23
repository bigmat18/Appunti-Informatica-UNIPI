#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>


// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio);
// Quicksort per array di interi in assembler
void qs_arm(int a[], int n);


// genera un array di n elementi con interi random tra 0 e 999
int *random_array(int n, int seed)
{
  assert(n>0);
  srandom(seed);
  int *a = malloc(n* sizeof(int));
  if(a==NULL) termina("allocazione fallita");
  for(int i=0;i<n;i++)
    a[i] = 1000 - ((int) random()) % 2000;
  return a;
}

// verifica che l'array a[0..n-1] sia ordinato in maniera crescente
bool check_sort(int a[], int n)
{
  for(int i=0;i<n-1;i++)
     if(a[i]> a[i+1]) return false;
  return true;
}

// usato da sort 
int confronta_interi(const void *a, const void *b)
{
  const int *ai = a;
  const int *bi = b;
  return *ai - *bi;
}


// procedura di partizionamento di un array a[0..n-1]
// partiziona l'array in due parti in modo che gli elementi
// della prima parte sono <= degli elementi della seconda parte
// restituisce il numero di elementi nella prima parte
int partition(int a[], int n)
{
  assert(n>1);
  // scelgo pivot in posizione random 
  int k = random() % n;      // genero posizione random del pivot
  int pivot = a[k];          // elemento pivot
  a[k]=a[0];a[0]=pivot;      // scambia a[k]<->a[0] per mettere il pivot in a[0]

  // procedura di partizionamento
  // l'elemento pivot svolge anche la funzione di sentinella  
  int i= -1;      // puntatore oltre estremo sinistro
  int j = n;      //puntatore oltre estremo destro
  while(1) {
    while(a[--j]>pivot) 
      ; // esce se a[j]<=pivot
    while(a[++i]<pivot) 
      ; // esce se a[i]>=pivot
    if(i<j) {
      // scambia a[i] <-> a[j]
      int t=a[i]; a[i]=a[j]; a[j]=t;
    }
    else break; 
  }
  // la prima meta' e' a[0] .. a[j] quindi ha j+1 elementi   
  assert(j+1 >0);
  assert(j+1 < n);
  return j+1; 
}


// Quicksort: ordina array a[0]...a[n-1]
// Notate che tutto il lavoro viene fatto da partition!
void quicksort(int a[], int n) {
  if(n>1) {
    int q = partition(a,n);
    assert(q>0 && q<n);   // verifica che entrambe le partizioni non siano vuote
    quicksort(a,q);       // chiamata ricorsiva prima parte 
    quicksort(a+q,n-q);   // chiamata ricorsiva seconda parte
  }
}


int main(int argc, char *argv[])
{
  int *a, n;  //  n = num. interi da mettere nell'array a[]

  // lettura e verifica input 
  if(argc<3) {
    fprintf(stderr,"Uso:\n\t  %s numel seed\n",argv[0]);
    fprintf(stderr,"oppure:\n\t  %s el1 el2 el3 [el4 el5 el6 ...]\n\n",argv[0]);
    exit(1);
  }
  // genera array da ordinare in maniera random 
  if(argc==3) {
    n = atoi(argv[1]);
    int seed = atoi(argv[2]);
    a = random_array(n,seed);
  }
  // crea l'array con gli interi sulla linea di comando
  else {
    n = argc-1;
    a = malloc(n*sizeof(int));
    if(a==NULL) termina("errore malloc");
    for(int i=0;i<n;i++)
      a[i] = atoi(argv[i+1]);
  }   

  // stampa i primi 10 elementi dell'array di input
  // for(int i=0;i<n && i<20;i++)
  //  printf("%5d\n",a[i]); 

  
  // esegue il sort e verifica
  #ifdef USA_ARM
  qs_arm(a,n);
  #else
  quicksort(a,n);
  #endif 
  // qsort(a,n,sizeof(int), confronta_interi);
  // stampa i primi 10 elementi dell'array ordinato
  for(int i=0;i<n && i<20;i++)
    printf("%5d\n",a[i]); 
  // verifica tutto array
  if(check_sort(a,n))
    printf("Sort OK\n");
  else
    printf("Sorting fallito\n");
  
  return 0;
}


void termina(const char *messaggio){
  if(errno!=0) perror(messaggio);
    else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}
