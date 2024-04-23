#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// funzioni somma e prodotto che prendono come 
// input due interi e restituiscono un intero
int somma(int a, int b) 
{
  return a+b;
}

int prod(int a, int b)
{
  return a*b;
}


// funzione che prende in input due interi e una funzione 
// e applica la funzione ai due interi 
int applica(int x, int y, int (*f)(int, int)) {
  int z = f(x,y);
  return z;
}


int main(int argc, char *argv[])
{
  int a,b;

  if (argc!=3) { 
    fprintf(stderr,"Uso:\n\t%s a b\n",argv[0]); exit(1);
  }
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  printf("Somma: %d, Prodotto %d\n",
            applica(a,b,&somma),
            applica(a,b,&prod));
  return 0;

}
