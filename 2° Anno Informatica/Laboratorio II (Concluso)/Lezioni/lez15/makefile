# il funzionamento del makefile lo vedremo prossimamente

# definizione del compilatore e dei flag di compilazione
# che vengono usate dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -g
LDLIBS=-lm

# elenco degli eseguibili da creare
all:  listacitta

# regole per la creazione dei file oggetto
listacitta.o: listacitta.c listastringhe.h
	gcc -std=c11 -Wall -g -c listacitta.c
	
listastringhe.o: listastringhe.c listastringhe.h	
	gcc -std=c11 -Wall -g -c listastringhe.c
	
# regola per la creazione del file eseguibile
listacitta: listacitta.o listastringhe.o
	gcc listacitta.o listastringhe.o -lm -o listacitta

# esempio di target che non corrisponde a una compilazione
# ma esegue la cancellazione dei file oggetto e dell'eseguibile
clean: 
	rm *.o listacitta
