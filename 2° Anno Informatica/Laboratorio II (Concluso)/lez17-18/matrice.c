/* *********************************************************
 * dimostrazione di uso degli array bidimensionali
 * sia statici che dinamici 
 * ********************************************************* */
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit()
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // prototipi delle funzioni per stringhe

// stampa un messaggio di errore e termina
void termina(const char *messaggio);


// stampa i valori di una matrice rxc
// allocata come variabile statica 
void stampa_matrice(int r, int c, int q[][c], FILE *f)
{
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++)
      fprintf(f,"%2d ",q[i][j]);
    fprintf(f,"\n");
  }
}


// stampa i valori di una matrice rxc allocata dinamicamente
// notiamo che il codice interno è identico, ma il prototipo 
// e differente, quindi non possiamo usare questa funzione per 
// stampare una matrice allocata staticamente
void stampa_matrice_dinamica(int r, int c, int **q, FILE *f)
{
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++)
      fprintf(f,"%2d ",q[i][j]);
    fprintf(f,"\n");
  }
}


// alloca e restituisce una matrice dinamica
// dato il numero di righe e colonne
int **crea_matrice_interi(int r, int c)
{    
  int **b;
  b = malloc(r*sizeof(*b));
  if(b==NULL) termina("Allocazione fallita");
  for(int i=0;i<r;i++) {
    b[i] = malloc(c*sizeof(int));
    if(b[i]==NULL) termina("Allocazione riga fallita");
  }
  return b;
}




int main(int argc, char *argv[])
{
  if(argc!=3) {
    fprintf(stderr,"Uso: %s righe colonne\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  // legge il numero di righe e colonne dalla riga di comando 
  int righe = atoi(argv[1]);
  int colonne = atoi(argv[2]);
  if(righe<1 || colonne <1)
    termina("Righe e colonne devono essere positive");
  
  // matrice allocata staticamente
  int a[righe][colonne];
  
  for(int i=0;i<righe;i++)
    for(int j=0;j<colonne;j++)
      a[i][j] = 10*i+j;
      
  // stampa contenuto della matrice 
  puts("Matrice allocata staticamente:");
  stampa_matrice(righe,colonne,a,stdout);    
  

  // ---- allocazione di una matrice dinamica
  int **b;
  b = crea_matrice_interi(righe,colonne);
  // riempio la matrice
  for(int i=0;i<righe;i++)
    for(int j=0;j<colonne;j++)
      b[i][j] = 20*i+j;
  puts("Matrice allocata dinamicamente:");
  stampa_matrice_dinamica(righe,colonne,b,stdout);

  // dealloco la matrice
  for(int i=0;i<righe;i++) 
    free(b[i]);
  free(b);  

  return 0;
}


// mostra il messaggio d'errore passato come parametro seguito
// dal messaggio associato all'ultimo errore di una funzione di libreria
// (mediante errno); dopo la stampa termina il programma  
void termina(const char *messaggio)
{
  perror(messaggio);
  exit(EXIT_FAILURE);
}
