#include <stdio.h>
#include <stdlib.h>

extern int myatoi(char *);
extern int map(char **v, int n, int (*f)(char *p));

int func(char *p)
{
    return myatoi(p);
}

int main(int argc, char **argv)
{
    char *v1[] = {"12", "4", "22", "24"};
    char *v2[] = {"", "4", "12", "22"};
    char *v3[] = {"12", "4d", "22"};

    printf("Test 1: Riprova = 15 ASM = %d\n", map(v1, 4, func));
    printf("Test 2: Riprova = 9 ASM = %d\n", map(v2, 4, func));
    printf("Test 3: Riprova = 8 ASM = %d\n", map(v3, 3, func));

    char *v4[] = {"10", "20", "30"};
    printf("Test 4: Riprova = 14 ASM = %d\n", map(v4, 3, atoi)); // il compilatore qui da warning ma non importa

    return 0;
}