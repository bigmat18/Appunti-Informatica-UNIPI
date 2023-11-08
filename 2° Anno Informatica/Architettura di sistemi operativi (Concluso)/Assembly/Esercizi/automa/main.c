#include <stdio.h>

extern int automa(char *s);

int main(void){
    char *a = "aaabbba";
    printf("%d", automa(a));
    return 0;
}