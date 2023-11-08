
// definzione struct che rappresenta una stringa
typedef struct stringola {
  char *str;
  struct stringola *next;
} stringola;
  
stringola *stringola_crea(char *s);
void stringola_distruggi(stringola *a);
void stringola_stampa(stringola *a, FILE *f);
void lista_stringola_stampa(stringola *lis, FILE *f);
void lista_stringola_distruggi(stringola *lis);
stringola *lista_stringola_inserisci_lex(stringola *lis, stringola *c);

