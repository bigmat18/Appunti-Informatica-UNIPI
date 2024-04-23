#define _GNU_SOURCE // avverte che usiamo le estensioni GNU
#include <assert.h> // permette di usare la funzione assert
#include <errno.h>
#include <stdbool.h> // gestisce tipo bool (variabili booleane)
#include <stdio.h>   // permette di usare scanf printf etc ...
#include <stdlib.h>  // conversioni stringa/numero exit() etc ...
#include <string.h>  // confronto/copia/etc di stringhe

// stampa un messaggio d'errore e termina il programma
void termina(const char *messaggio);

// // queste funzioni servono per testare cerca_coppia
// bool minore(int a, int b) { return a < b; }
// bool pari(int a, int b) { return (a % 2 == 0) && (b % 2 == 0); }

typedef struct cop
{
  int primo;
  int secondo;
  struct cop *next;
} coppia;

// crea una coppia contenente i valori x e y
coppia *crea_coppia(int x, int y);

// legge 2 interi dal file f (usando scanf)
// e crea una coppia con i valori corrispondenti
// chiamando la funzione crea_coppia()
// restituisce NULL se non e' possibile
// leggere i due interi dal file f
coppia *crea_coppia_file_testo(FILE *f);

// crea una lista con tutti gli interi presenti
// nel file il cui nome e' nomefile. Gli interi
// devono essere letti con crea_coppie_file_testo().
// Nella lista restituita le coppie devono essere
// ordinate per somma delle componenti crescenti
coppia *crea_lista_ordinata(char *nomefile);

// stampa sul file f tutte le coppie di lis
// !!! NON MODIFICATE QUESTA FUNZIONE!!!
void stampa_lista_coppie(coppia *lis, FILE *f);

// dealloca tutti gli elementi della lista lis
void distruggi_lista_coppie(coppia *lis);

coppia *cerca_coppia(coppia *lis, bool (*f)(int, int));

coppia *cancella_coppie(coppia *lis, bool (*f)(int, int));

// queste funzioni servono per testare cancella_coppie
bool minore(int a, int b)
{
  return a < b;
}
bool pari(int a, int b)
{
  return (a % 2 == 0) && (b % 2 == 0);
}
bool vero(int a, int b)
{
  return (b == 0);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Uso: %s nomefile\n", argv[0]);
    return 1;
  }
  // puts("==== inizio");
  // coppia *lista = crea_lista_ordinata(argv[1]);
  // stampa_lista_coppie(lista, stdout);
  // puts("---- 1");
  // coppia *lista2 = cerca_coppia(lista,minore);
  // stampa_lista_coppie(lista2,stdout);
  // puts("---- 2");
  // lista2 = cerca_coppia(lista,pari);
  // stampa_lista_coppie(lista2,stdout);
  // puts("---- 3");
  // distruggi_lista_coppie(lista);
  // puts("==== fine");

  puts("==== inizio");
  coppia *lista = crea_lista_ordinata(argv[1]);
  stampa_lista_coppie(lista, stdout);
  puts("---- 1");
  lista = cancella_coppie(lista, minore);
  stampa_lista_coppie(lista, stdout);
  // puts("---- 2");
  // lista = cancella_coppie(lista, pari);
  // stampa_lista_coppie(lista, stdout);
  // puts("---- 3");
  // lista = cancella_coppie(lista, vero);
  // stampa_lista_coppie(lista, stdout);
  // puts("---- 4");
  // // distruggi_lista_coppie(lista);
  // puts("==== fine");

  return 0;
}

coppia *crea_coppia(int x, int y)
{
  coppia *newCoppia = malloc(sizeof(coppia));
  newCoppia->primo = x;
  newCoppia->secondo = y;
  newCoppia->next = NULL;
  return newCoppia;
}

coppia *crea_coppia_file_testo(FILE *f)
{
  int x, y;
  int e = fscanf(f, "%d %d", &x, &y);
  if (e != 2)
    return NULL;
  return crea_coppia(x, y);
}

coppia *crea_lista_ordinata(char *nomeFile)
{
  FILE *f = fopen(nomeFile, "r");
  if (f == NULL)
    termina("File's open error");

  coppia *head = crea_coppia_file_testo(f);
  if (head == NULL)
    return NULL;

  coppia *currentCoppia = head;
  coppia *previusCoppia = NULL;

  while (true)
  {
    coppia *coppia = crea_coppia_file_testo(f);
    if (coppia == NULL)
      break;

    currentCoppia = head;
    previusCoppia = NULL;

    while (true)
    {
      if (currentCoppia == NULL)
      {
        previusCoppia->next = coppia;
        break;
      }
      else if (currentCoppia->primo + currentCoppia->secondo <=
               coppia->primo + coppia->secondo)
      {
        previusCoppia = currentCoppia;
        currentCoppia = currentCoppia->next;
      }
      else
      {
        if (currentCoppia == head)
        {
          coppia->next = head;
          head = coppia;
          break;
        }
        else
        {
          previusCoppia->next = coppia;
          coppia->next = currentCoppia;
          break;
        }
      }
    }
  }
  free(currentCoppia);
  free(previusCoppia);
  return head;
}

void stampa_lista_coppie(coppia *lis, FILE *f)
{
  while (lis != NULL)
  {
    fprintf(f, "%d %d\n", lis->primo, lis->secondo);
    lis = lis->next;
  }
}

coppia *cerca_coppia(coppia *lis, bool (*f)(int, int))
{
  coppia *current = lis;
  coppia *result = NULL;
  while (current != NULL)
  {
    if (f(current->primo, current->secondo))
    {
      result = current;
    }
    current = current->next;
  }
  return result;
}

void distruggi_lista_coppie(coppia *lis)
{
  coppia *current = lis;
  coppia *previus = NULL;
  while (current != NULL)
  {
    previus = current;
    free(current);
    current = previus->next;
  }
}

void termina(const char *messaggio)
{
  if (errno != 0)
    perror(messaggio);
  else
    fprintf(stderr, "%s\n", messaggio);
  exit(1);
}

coppia *cancella_coppie(coppia *lis, bool (*f)(int, int))
{
  coppia *previus = NULL;
  coppia *current = lis;

  while (current != NULL)
  {
    if (f(current->primo, current->secondo))
    {
      if (previus != NULL)
      {
        previus->next = current->next;
        free(current);
        current = previus->next;
      }
      else
      {
        lis = current->next;
        free(current);
        current = lis;
      }
    }
    else
    {
      previus = current;
      current = current->next;
    }
  }
  return lis;
}