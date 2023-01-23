# definizione del compilatore e dei flag di compilazione
# che vengono usate dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -g
LDLIBS=-lm

# Variabili automatiche: https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
# nei comandi associati ad ogni regola:
#  $@ viene sostituito con il nome del target
#  $< viene sostituito con il primo prerequisito
#  $^ viene sostituito con tutti i prerequisiti

# elenco degli eseguibili da creare
EXECS=matrice scrivi_primi_bin leggi_bin


# primo target: gli eseguibili sono precondizioni
# quindi verranno tutti creati
all: $(EXECS) 


# esempio di target che non corrisponde a una compilazione
# ma esegue la cancellazione dei file oggetto e degli eseguibili
clean: 
	rm *.o $(EXECS)
	
# crea file zip della lezione	
zip:
	zip lezione18.zip *.c *.h makefile
 
