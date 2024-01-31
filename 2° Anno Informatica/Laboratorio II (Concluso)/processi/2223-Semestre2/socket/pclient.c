#define _GNU_SOURCE   // permette di usare estensioni GNU
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // richiesto per usare errno
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// host e port a cui connettersi
#define HOST "127.0.0.1"
#define PORT 65432


// Client C per pserver.py a cui vengono chiesti i primi in un intervallo
// Confrontate questo codice con pclient.py
// e noterete che vengono fatte le stesse operazioni
// nello stesso ordine con funzioni che si chiamano 
// con nomi molto simili


/* Read "n" bytes from a descriptor 
   analoga alla funzione python recv_all() */
ssize_t readn(int fd, void *ptr, size_t n) {  
   size_t   nleft;
   ssize_t  nread;
 
   nleft = n;
   while (nleft > 0) {
     if((nread = read(fd, ptr, nleft)) < 0) {
        if (nleft == n) return -1; /* error, return -1 */
        else break; /* error, return amount read so far */
     } else if (nread == 0) break; /* EOF */
     nleft -= nread;
     ptr   += nread;
   }
   return(n - nleft); /* return >= 0 */
}


/* Write "n" bytes to a descriptor 
   analoga alla funzione python sendall() */
ssize_t writen(int fd, void *ptr, size_t n) {  
   size_t   nleft;
   ssize_t  nwritten;
 
   nleft = n;
   while (nleft > 0) {
     if((nwritten = write(fd, ptr, nleft)) < 0) {
        if (nleft == n) return -1; /* error, return -1 */
        else break; /* error, return amount written so far */
     } else if (nwritten == 0) break; 
     nleft -= nwritten;
     ptr   += nwritten;
   }
   return(n - nleft); /* return >= 0 */
}

// termina un processo con eventuale messaggio d'errore
void termina(const char *messaggio) {
  if(errno==0)  fprintf(stderr,"== %d == %s\n",getpid(), messaggio);
  else fprintf(stderr,"== %d == %s: %s\n",getpid(), messaggio,
              strerror(errno));
  exit(1);
}




// questa versione non permette di scegliere 
// host e port dalla linea di comando
// per cambiarli è necessario ricompilare
int main(int argc, char const* argv[])
{
  if(argc!=3) {
    printf("Uso\n\t%s inizio fine\n", argv[0]);
    exit(1);
  }
  // legge estremi intervallo 
  int inizio = atoi(argv[1]);
  int fine = atoi(argv[2]);  
  int fd_skt = 0;      // file descriptor associato al socket
  struct sockaddr_in serv_addr;
  size_t e;
  int tmp;

  // crea socket
  if ((fd_skt = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    termina("Errore creazione socket");
  // assegna indirizzo
  serv_addr.sin_family = AF_INET;
  // il numero della porta deve essere convertito 
  // in network order 
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = inet_addr(HOST);
  // apre connessione
  if (connect(fd_skt, &serv_addr, sizeof(serv_addr)) < 0) 
    termina("Errore apertura connessione");
    
  puts("Invio gli estremi dell'intervallo");
  tmp = htonl(inizio);
  e = writen(fd_skt,&tmp,sizeof(tmp));
  if(e!=sizeof(int)) termina("Errore write");
  tmp = htonl(fine);
  e = writen(fd_skt,&tmp,sizeof(tmp));
  if(e!=sizeof(int)) termina("Errore write");
  puts("Leggo il numero di primi");
  e = readn(fd_skt,&tmp,sizeof(tmp));
  if(e!=sizeof(int)) termina("Errore read");
  int n = ntohl(tmp);
  assert(n>=0);
  printf("Devo leggere %d primi\n",n);
  for(int i=0;i<n;i++) {
    e = readn(fd_skt,&tmp,sizeof(tmp));
    if(e!=sizeof(int)) termina("Errore read");
    printf(" %d\n",ntohl(tmp));
  }
  if(close(fd_skt)<0)
    perror("Errore chiusura socket");
  puts("Connessione terminata"); 
  return 0;
}
