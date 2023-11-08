#include <stdio.h>
#include <stdlib.h>

extern int hash(int x);

int main(int argc, char **argv){
    int a = 0x10372841;
    printf("%d", hash(a));
    return 0;
}
