## Esercizio calcolo numero divisori

Scrivere un programma *divisoriT* che invocato dalla linea di comando scrivendo 
 
    divisoriT infile1 infile2 infile3 ... infileN outfile numt
 
con *numt>0* legge gli interi positivi contenuti nei file *infile1*, ... , *infileN*, e crea un file *outfile* contenente gli stessi interi e di fianco ad ogni intero il numero dei suoi divisori.

Il thread principale deve per prima cosa creare *N* thread produttori ad ognuno dei quali deve essere assegnato uno dei file di input. Ogni thread produttore deve leggere gli interi dal suo file, utilizzando ad esempio fscanf, e scriverli nel buffer produttori/consumatori condiviso. Ognuno di questi interi viene messo sul buffer produttore/consumatori e rappresenta una unità di lavoro per i consumatori. Il buffer deve avere una dimensione definita con *#define*.

Il thread principale deve successivamente aprire il file di ouput e creare *numt* thread consumatori ognuno dei quali deve ripetutamente:

* leggere dal buffer un intero

* calcolare il numero dei suoi divisori

* scrivere nel file di output l'intero seguito dal numero dei suoi divisori (sulla stessa riga)

Come in tutti gli schemi produttore-consumatore è necessario stabilire un meccanismo che permetta ai produttori di segnalare ai consumatori che non ci sono altri valori da elaborare. 

Si noti che tutti i consumatori scrivono sullo stesso file di output, è quindi necessario regolarne l'accesso mediante un mutex. Il file di output deve essere chiuso dal thread principale quando tutti i thread secondari sono terminati. 


## Esperimenti

Usare il programma *interi.py* per generare dei file di interi, e il programma *divisori.py* per generare il corrispondente file di divisori. Il vostro output può differire da quello prodotto da *divisori.py* per l'ordine delle righe; usare il comando `sort -n` per ottenere dei file con gli interi ordinati dal più piccolo al più grande.

