
## Esercizio sui thread (calcolo gcd multipli)


Scrivere un programma *gcdT* che invocato dalla linea di comando scrivendo 
 
	    gcdT infile numt
 
calcola il massimo comun divisore delle coppie di valori in *infile* utilizzando *numt* thread ausiliari secondo il seguente procedimento. 

I thread ausiliari svolgono il ruolo di produttori e devono leggere coppie di interi dal file di testo *infile* assicurandosi che ogni coppia di *infile* venga letta da un unico thread.

I thread ausiliari devono passare le coppie al thread principale utilizzando il meccanismo produttore/consumatore mediante un buffer la cui dimensione deve essere una costante definita con *#define*. Il thread principale svolge il ruolo di unico consumatore; legge le coppie dal buffer e per ogni coppia calcola il massimo comun divisore con la funzione *gcd* che trovate nel sorgente C. 

Il thread principale deve salvare i valori dei massimo comun divisore in un array di *int* e quando tutti i produttori hanno terminato deve ordinare questo array (con qsort) e stampare su `stdout` i valori ordinati (uno per riga). Ogni altro messaggio del programma deve essere inviato su `stderr`.

Si noti che non si sa in anticipo quanti gcd saranno calcolati quindi l'array dei gcd deve essere gestito in maniera dinamica.


### Esperimenti

Il programma richiede come input un file di coppie. Salvate l'output in un file utilizzando la ridirezione. Per fare test significativi (almeno 100 coppie) potete usare il programma *coppie.py* che genera un file con un numero assegnato di coppie e produce anche un file con estensione .gcd contenente quello che dovrebbe essere l'output finale del programma (i gcd ordinati in maniera crescente). I file `100coppie` e `100coppie.gcd` sono un esempio di file di input e corrispondente output.


### Suggerimenti


* fa parte dell'esercizio scrivere il makefile che ottiene l'eseguibile compilando separatamente xerrori.c e gcdtT.c 

* Utilizzare un mutex per assicurarsi che i produttori leggano dal file in maniera esclusiva

* Ogni dato passato da produttori a consumatore consiste di due interi che devono essere processati insieme. Se il buffer consiste in un array di interi è necessaria un modifica allo schema che abbiamo sempre usato, altrimenti come buffer potete usare un array di struct, dove ogni signola struct contiene la coppia di interi

* Anche in questo caso abbiamo il problema della terminazione: i produttori prima di terminare devono in qualche modo segnalare al consumatore che non ci sono altri dati.

* L'esercizio ha solo scopo didattico: non è da considerare una soluzione modello per il problema. 