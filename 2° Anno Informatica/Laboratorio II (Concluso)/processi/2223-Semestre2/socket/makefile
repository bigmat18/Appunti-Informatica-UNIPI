# definizione del compilatore e dei flag di compilazione
# che vengono usate dalle regole implicite
CC=gcc
CFLAGS=-g -Wall -O -std=c99
LDLIBS=-lm -lrt -pthread

EXEC=pclient.out

# se si scrive solo make di default compila main 
all: $(EXEC)

%.out: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)


# target che cancella eseguibili e file oggetto
clean:
	rm -f $(EXEC) *.o  

