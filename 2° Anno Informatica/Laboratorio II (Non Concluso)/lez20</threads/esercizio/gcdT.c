#include "xerrori.h"

// macro per indicare la posiine corrente
#define QUI __LINE__,__FILE__

// dimensione buffer produttori-consumatori
#define Buf_size 20


// calcola gcd di due interi >= 0 non entrambi nulli 
int gcd(int a, int b)
{
	assert(a>=0 && b>=0);
	assert(a!=0 || b!=0);
  if(b==0) return a;
  return gcd(b,a%b);
}


int main(int argc, char *argv[])
{
  // controlla numero argomenti
  if(argc!=3) {
      printf("Uso: %s file numT\n",argv[0]);
      return 1;
  }

  return 0;
}

