CFLAGS= -g -Wall 
CC=gcc

# eseguibili dei programmi che usano l'assembler 
EXECS=primi strcmp quicksort quickarm quickarm2 tok


all: $(EXECS)


# costruisce array dei primi <=N
primi: primi.c primo.s
	$(CC) $(CFLAGS) $^ -o primi
	
# quicksort con funzione qs_arm del file quicksort.s		
quickarm: quicksort.c quicksort.s
	$(CC) $(CFLAGS) $^ -o $@ -DUSA_ARM

# quicksort con funzione qs_arm del file quicksort2.s		
quickarm2: quicksort.c quicksort2.s
	$(CC) $(CFLAGS) $^ -o $@ -DUSA_ARM


# pattern rule usata per compilare sia strcmp che tok
# la ricetta per ottenere il target è la stessa in quanto espressa
# in termini delle variabili speciali $ e $@
%: %.c %.s
	$(CC) $(CFLAGS) $^ -o $@


# regola per cancellare tutti gli  eseguibili e i file oggetto
# serve se voglio rifare tutta la compilazione da capo
# per eseguirla si deve scrivere `make clean` sulla linea di comando 
clean:
	rm -f $(EXECS) *.o
