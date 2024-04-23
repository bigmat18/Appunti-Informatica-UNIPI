### Testo Esercizio

Scrivere un programma *raddoppia.out* che invocato dalla linea di comando scrivendo 
```
  raddoppia.out infile outfile
```
legge il contenuto del file di testo *infile* contenente interi e scrive in *outfile* gli interi positivi letti da *infile* raddoppiati. Il programma deve utilizzare tre thread ausiliari *t1*, *t2* e *t3* secondo il seguente schema:

* il thread *t1* legge un intero alla volta da *infile* e se l'intero è positivo e lo passa a *t2* mediante uno schema produttore/consumatore

* il thread *t2* legge gli interi passati da *t1*, li raddoppia e li passa a *t3* utilizzando un distinto schema produttore/consumatore.

* il thread *t3* scrive gli interi ricevuti su *outfile*.

Come detto il passaggio degli interi tra i vari thread deve essere effettuato mediante il meccanismo produttore/consumatore. Avremo quindi **due** di tali meccanismi (quindi due buffer) ognuno con un unico produttore e un unico consumatore: notare che il thread *t2* svolge il ruolo di consumatore rispetto al thread principale e il ruolo di produttore rispetto al thread *t3*.

Come di consueto il vostro programma deve prevedere un meccanismo attraverso il quale i produttori segnalano ai consumatori che non ci sono altri valori di input. 

La dimensione dei due buffer produttore/consumatore devono essere quelle indicate dalle costanti di compilazione:
```C
#define Buf1_size 10
#define Buf2_size 15
```

La valutazione terrà conto dell'uso efficiente degli strumenti di sincronizzazione: saranno penalizzate soluzioni che bloccano mutex, semafori, condition variables, etc.  più del tempo necessario.

Consegnare il compito nel contenitore `Consegna raddoppia`. Consegnate il makefile e tutti i file necessari per la compilazione. consegnate i file singolarmente (non consegnate un archivio compresso). 

Chiamate l'eseguibile `raddoppia.out` e verificate che eseguendo il comando `make` seguito da `./raddoppia.out` il vostro programma parta regolarmente. 

Le coppie file `small.in`, `small.out` e `verybig.in`, `verybig.out` sono esempi di input e del corrisponente output che deve essere prodotto dal vostro programma. Altri esempi possono essere creati con lo script `testradd.py`.


### Fase di autocorrezione 

Entro le 23:59 di oggi potete sottomettere una patch al vostro programma nel caso troviate errori che possono essere risolti con poche modifiche (qualche linea di codice al max); patch troppo consistenti saranno ignorate. La procedura da seguire è la solita:

* ricordarsi di chiamare il vostro sorgente `raddoppia.c`

* nel caso vogliate fare delle modifiche copiare il file consegnato in `raddoppia.orig` e fate le modifiche in `raddoppia.c`

* creare la patch con il comando `diff -u raddoppia.orig raddoppia.c > correzioni`. Vedere https://www.shellhacks.com/create-patch-diff-command-linux/ per i dettagli

* Consegnate il file `correzioni` nel contenitore `Correzione raddoppia` (il file consegnato si deve chiamare esattamente `correzioni` altrimenti verrà ignorato)

* Se la patch funziona, il voto finale non sarà comunque quello massimo e dipenderà anche dalla consistenza delle modifiche. 

* La procedura è totalmente volontaria: in mancanza di patch correggerò quanto avete consegnato
