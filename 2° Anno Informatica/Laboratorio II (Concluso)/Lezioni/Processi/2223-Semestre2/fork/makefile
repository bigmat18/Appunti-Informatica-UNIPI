# definizione del compilatore e dei flag di compilazione
# che vengono usate dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -g
LDLIBS=-lm


# su https://www.gnu.org/software/make/manual/make.html#Implicit-Rules
# sono elencate le regole implicite e le variabili 
# usate dalle regole implicite 

# Variabili automatiche: https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# nei comandi associati ad ogni regola:
#  $@ viene sostituito con il nome del target
#  $< viene sostituito con il primo prerequisito
#  $^ viene sostituito con tutti i prerequisiti

# elenco degli eseguibili da creare
EXECS=fork0 moria

# primo target: gli eseguibili sono precondizioni
# quindi verranno tutti creati
all: $(EXECS) 

moria: moria.o xerrori.o

# pattern rule che esprime che tutti i .o dipendono da xerrori.h
moria.o: moria.c xerrori.h

xerrori.o: xerrori.c xerrori.h

 

# esempio di target che non corrisponde a una compilazione
# ma esegue la cancellazione dei file oggetto e degli eseguibili
clean: 
	rm *.o $(EXECS)
	
# crea file zip della lezione	
zip:
	zip processi.zip *.c *.h makefile

	
	
	
	

