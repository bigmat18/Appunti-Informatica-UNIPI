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
EXECS=listacitta qsortint qsortcap

# primo target: gli eseguibili sono precondizioni
# quindi verranno tutti creati
all: $(EXECS) 



# regole per la creazione dei file oggetto x listacitta

# versione con il comando di compilazione dato in 
# maniera esplicita (di solito non si fa)
listastringhe.o: listastringhe.c listastringhe.h	
	gcc -std=c11 -Wall -g -c listastringhe.c

# versione che usa le variabili (molto piu semplice)
listacitta.o: listacitta.c listastringhe.h
	$(CC) $(CFLAGS) -c $<


# regola per la creazione del file eseguibile listacitta
# qui uso $@ per indicare il target (listcitta)
listacitta: listacitta.o listastringhe.o
	gcc listacitta.o listastringhe.o -lm -o $@


# regole per la creazione di qsortcap
# molto semplici perché usiamo le variabili
capitali.o: capitali.c capitali.h
	$(CC) $(CFLAGS) -c $<
qsortcap.o: qsortcap.c capitali.h
	$(CC) $(CFLAGS) -c $<
qsortcap: qsortcap.o capitali.o
	$(CC) $^ -lm -o $@


# esempio di target che non corrisponde a una compilazione
# ma esegue la cancellazione dei file oggetto e degli eseguibili
clean: 
	rm *.o $(EXECS)
	
# crea file zip della lezione	
zip:
	zip lezione16.zip *.c *.h makefile capitali.txt
 
