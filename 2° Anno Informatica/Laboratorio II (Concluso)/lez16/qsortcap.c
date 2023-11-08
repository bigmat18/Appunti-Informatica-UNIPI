/* *********************************************************
 * Esempio di uso di qsort per ordinare array di interi 
 * ********************************************************* */
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <errno.h>    // richiesto per usare errno

#include "capitali.h"


// stampa un messaggio di errore e termina
void termina(const char *messaggio);

int confronta_capitali_lat(capitale **a, capitale **b)
{
  if((*a)->lat > (*b)->lat)
    return -1;
  else if((*a)->lat < (*b)->lat)
    return 1;
  return 0;
}


int main(int argc, char *argv[])
{
  if(argc!=2) {  // input sulla linea di comando non corretto
    printf("Uso: %s nomefile\n",argv[0]);
    return 1;
  }
  
  FILE *f = fopen(argv[1],"rt");
  if(f==NULL) termina("Errore apertura file");
  
  int n; // numero capitali
  capitale **a; // array di puntatore a capitali
  
  a = capitale_leggi_file(f,&n);
  if(a==NULL) termina("Nulla da ordinare");
  assert(n!=0);
  
  // stampo array
  for(int i=0;i<n;i++)
    capitale_stampa(a[i],stdout);
  puts(""); // a capo 


  // eseguo il sorting degli a[i]
  // come spiegato a lezione per l'ultimo argomento ci vuole il casting  
  qsort(a,n,sizeof(capitale *), 
        (__compar_fn_t) &confronta_capitali_lat); 

  // stampo array
  puts("--- qsort eseguito ---");
  // stampo array
  for(int i=0;i<n;i++)
    capitale_stampa(a[i],stdout);
  puts(""); // a capo 

  // libero la memoria usata dall'array a[]
  for(int i=0;i<n;i++)
    capitale_distruggi(a[i]);
  free(a);
  // a questo punto sarebbe un errore scrivere a[0]
  return 0;
}


// stampa su stderr il  messaggio che gli passo
// se errno!=0 stampa anche il messaggio d'errore associato 
// a errno. dopo queste stampe termina il programma
void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}
