#include "xerrori.h"

#define QUI __LINE__, __FILE__

bool primo(int n) {
  if(n<2) return false;
  if(n%2==0) {
    if(n==2)  return true;
    else return false; }
  for (int i=3; i*i<=n; i += 2) 
      if(n%i==0) return false;
  return true;
}

// conta i primi in [a,b)
int contap(int a, int b) {
  int tot = 0;
  for(int i=a;i<b;i++)
    if(primo(i)) tot++;
  return tot;  
}

int main(int argc, char *argv[]) {
    if(argc!=4) {
        printf("Uso:\n\t%s n1 n2 p\n",argv[0]);
        exit(1);
    }
    int n0 = atoi(argv[1]);
    int n1 = atoi(argv[2]);
    int p = atoi(argv[3]);
    assert(n0>0 && n1>=n0 && p>0);

    int up[2];
    xpipe(up, QUI);

    for(int i = 0; i < p; i++){
        pid_t pid = xfork(QUI);
        if(pid == 0){
            xclose(up[0], QUI);
            int n = (n1 - n0) / p;
            int start = n0 + n * i;
            int end = (i == p - 1) ? n1 : n0 + n * (i + 1);
            int tot = contap(start, end);
            ssize_t e = write(up[1], &tot, sizeof(int));
            if (e != sizeof(int)) termina("Errore scrittura pipe");
            xclose(up[1], QUI);
            exit(0);
        }
    }

    xclose(up[1], QUI);

    int tot  = 0;
    while(true){
        int x;
        ssize_t e = read(up[0], &x, sizeof(int));
        if (e == 0) break;
        tot += x;
    }

    xclose(up[0], QUI);

    printf("Numero primi p tali che  %d <= p < %d è: %d\n", n0, n1, tot);

    return 0;
}