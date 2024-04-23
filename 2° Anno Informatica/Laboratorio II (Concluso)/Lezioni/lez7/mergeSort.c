// Algoritmo Mergesort che sfrutta la notazione &a[n1] per ottenere 
// il puntatore all'inizio dell'array contenente al seconda metà
// dell'input.



#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno

// prototipi delle funzioni che appaiono dopo il main()
void stampa_array(int *a, int n, FILE *f);
void termina(char *messaggio);


// funzione per il merge di due array in un terzo
// merge di a[0...n1-1] e c[0... n2-1] dentro b[]
void merge(int a[], int na, int c[], int nc, int b[])
{
  assert(a!=NULL && c!=NULL && b !=NULL);
  int n = na+nc;  // lunghezza array risultato
  int ia,ib,ic;   // indici all'interno degli array
  ia=ic=ib=0;
  
  // eseguo merge riempiendo il vettore b
  for(ib=0;ib<n;ib++) {
    if(ia==na)
      b[ib] = c[ic++];
    else if(ic==nc)
      b[ib] = a[ia++];    
    else if(a[ia]<c[ic]) 
      b[ib] = a[ia++];
    else 
      b[ib] = c[ic++];
  }
  // verifica tutti gli indici sono arrivati in fondo
  assert(ia==na);
  assert(ic==nc);
  assert(ib==n);
}


// funzione mergesort ricorsiva
void mergesort(int a[], int n)
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;     // dimesione prima parte
  int n2 = n - n1;  // dimensione seconda parte
  
  mergesort(a,n1);
  mergesort(&a[n1],n2); // &a[n1] potevo scriverlo a+n1
  
  // ho le due metà ordinate devo fare il merge
  int *b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];
  
  free(b);
}



// ordina gli interi passati sulla linea di comando
int main(int argc, char *argv[])
{

  if(argc<2) {
    fprintf(stderr, "Uso:\n\t   %s i1 [i2 i3 i4 ... ]\n", argv[0]);
    fprintf(stderr, "dove i valori  i1 i2 ...  sono interi\n");
    exit(1);
  }
  int n = argc - 1;
  int *a = malloc(n * sizeof(int));
  if (a == NULL) {
    termina("Non è possibile allocare lo spazio necessario per l'input.");
  }
  // conversione argomenti da riga di comando in interi da inserire in a
  for (int i = 0; i < n; i++)
    a[i] = atoi(argv[i+1]);

  // ordina array a[] in place 
  mergesort(a,n);
  
  // stampo array e chiudo il file
  stampa_array(a,n,stdout);
  
  // dealloco l'array e termino
  free(a);   
  return 0;
}





// stampa un messaggio d'errore su stderr e termina il programma
void termina(char *messaggio)
{
  // se errno!=0 oltre al mio messaggio stampa il messaggio
  // associato alla variabile globale errno 
  // utilizzando la funzione di libreria perror()
  if(errno!=0) perror(messaggio);
  // altrimenti stampa solo il mio messaggio
  else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}


// visualizza elementi array di un qualsiasi 
// array di int sul terminale
void stampa_array(int *a, int n, FILE *f)
{
  assert(a!=NULL);
  // stampo il contenuto dell'array
  for(int i=0;i<n;i++)
    fprintf(f,"%8d",a[i]); // stampo gli elementi in un campo di 8 caratteri
  fprintf(f,"\nIn totale l'array contiene %d interi\n",n);
}










