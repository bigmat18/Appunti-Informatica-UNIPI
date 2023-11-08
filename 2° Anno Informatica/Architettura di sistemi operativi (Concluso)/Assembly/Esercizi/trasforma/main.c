#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern void trasforma(char *, char *, char *, int);

int main(int argc, char **argv) {
    int N = 5;
    char from[] = {'u', 'a', 'e', 'i', 'o'};
    char to[] = {'h', 'x', 'y', 'w', 'z'};
    char *s[] = {"", "u", "z", "ciao", "vediamo come va con questa frase"};
    char *ok[] = {"", "h", "z", "cwxz", "vydwxmz czmy vx czn qhystx frxsy"};
    int n = 5;
    int i;
    for (i = 0; i < n; i++)
    {
        char *tmp = (char *)malloc(strlen(s[i]) + 1);
        strcpy(tmp, s[i]);
        trasforma(tmp, from, to, N);
        if (strcmp(tmp, ok[i]) == 0)
        {
            printf("OK <%s> -> <%s>\n", s[i], tmp);
        }
        else
        {
            printf("Errore: %s -> %s\n", tmp, ok[i]);
        }
    }
    return 0;
}