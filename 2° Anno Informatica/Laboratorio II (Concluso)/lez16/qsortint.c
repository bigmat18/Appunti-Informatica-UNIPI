/* *********************************************************
 * Esempio di uso di qsort per ordinare array di interi 
 * ********************************************************* */
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <errno.h>    // richiesto per usare errno

// stampa un messaggio di errore e termina
void termina(const char *messaggio);


// funzione di confronto, con i tipi corretti
// necessita del casting al tipo __compar_fn_t
// nella chiamata del qsort altrimenti il compilatore
// da un warning
int confronta(int *a, int *b)
{
  if(*a<*b) return -1;
  else if(*a>*b) return 1;
  return 0; 
}


// funzione di confronto sbagliata, ma usando il casting 
// il compilatore non se ne può accorgere
// il programma gira ma ottengo un risultato sbagliato
int confronta2(int a, int b)
{
  if(a<b) return -1;
  else if(a>b) return 1;
  return 0; 
}


// funzione di confronto con il prototipo del tipo giusto
// posso usarla dentro al qsort senza il casting
// devo pero effetturare il casting di aa e bb dentro questa funzione
// altrimenti non riesco ad accedere ai valori da confrontare
int confronta3(const void *aa,const void *bb)
{
  int *a = (int *) aa; // casting di aa e bb al tipo int *
  int *b = (int *) bb;
  if(*a<*b) return -1;
  else if(*a>*b) return 1;
  return 0; 
}



int main(int argc, char *argv[])
{
  if(argc<=2) {  // input sulla linea di comando non corretto
    printf("Uso: %s i1 i2 i3 ... ik \n",argv[0]);
    return 1;
  }
  int n = argc-1; // Numero argomenti linea di comando

  // alloco array dinamico
  int *a = malloc(n*sizeof(int));
  if(a==NULL) termina("Memoria insufficiente");
  // riempio con interi passati sulla linea di comando
  for(int i=0;i<n;i++) 
    a[i] = atoi(argv[i+1]);

  // stampo array
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  puts(""); // a capo 

  // eseguo il sorting degli interi vcn qsort()
  // come spiegato a lezione per l'ultimo argomento ci vuole il casting  
  // qsort(a,n,sizeof(int), (__compar_fn_t) &confronta2); 

  // forma alternativa corretta per invocare qsort:
  // in qusto caso il casting viene fatto dentro la funzione contronta3
  qsort(a,n,sizeof(int), &confronta3);



  // stampo array
  puts("--- qsort eseguito ---");
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  puts(""); // a capo 
  
  // libero la memoria usata dall'array a[]
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
