
// definizione struct che rappresenta
// una città con nome, e coordinate 
typedef struct {
  char *nome;
  double lat;
  double lon;
} capitale;


// stampa sul file *f i campi della capitale a
void capitale_stampa(capitale *a, FILE *f);

// crea oggetto capitale a partire dai sui campi
capitale *capitale_crea(char *s, double lat, double lon);
// distrugge (dealloca) un oggetto capitale 
void capitale_distruggi(capitale *a);


// legge un oggetto capitale dal file f
// restituisce il puntatore all'oggetto letto
// oppure NULL se non riesce a leggere dal file
capitale *capitale_leggi(FILE *f);

// confronto latitudini ordinando da nord a sud
int capitale_cmp_lat(capitale *a, capitale *b);
// confronto latitudini ordinando da sud a nord 
int capitale_cmp_latsud(capitale *a, capitale *b);
// confronto dei nomi
int capitale_cmp_nome(capitale *a, capitale *b);

//legge e restituisce un array di capitali *
capitale **capitale_leggi_file(FILE *f, int *num);




