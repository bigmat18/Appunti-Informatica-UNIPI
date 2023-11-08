#include<stdio.h>
#include<stdlib.h>

extern void maius(char *stringa);

int main(int argc, char **argv)
{
    printf("Stringa originale: %s\n", argv[1]);

    maius(argv[1]);

    printf("Stringa convertita: %s\n", argv[1]);
    return 0;
}
