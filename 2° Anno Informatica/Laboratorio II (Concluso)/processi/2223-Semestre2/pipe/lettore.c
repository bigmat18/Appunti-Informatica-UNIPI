#include "xerrori.h"


int main(int argc, char *argv[])
{ 
  if(argc!=2) {
    printf("Uso:\n\t%s nome_pipe\n",argv[0]);
    exit(1);
  }
  // apre file descriptor associato alla named pipe
  // se il file non esiste termina con errore  
  int fd = open(argv[1],O_RDONLY);
  if(fd<0) termina("Errore apertura named pipe");
  while(true) {
    int val;
    ssize_t e = read(fd,&val,sizeof(val));
    if(e==0) break;
    printf("%d\n",val);
  }
  xclose(fd,__LINE__,__FILE__);
  printf("Lettura finita\n");
  return 0;
}
