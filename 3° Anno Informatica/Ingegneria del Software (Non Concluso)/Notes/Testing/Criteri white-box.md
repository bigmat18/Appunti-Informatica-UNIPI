Sono criteri per l'individuazione dei casi di input che si basano sulla struttura del codice. Sinonimi: criteri strutturali, criteri a scatola aperta.

Perché criteri basati sul codice?
I criteri strutturali che vediamo oggi devono aiutare ad aggiungere altri test oltre a quelli generati con criteri funzionali. Rispondono alla domanda: “Quali altri casi devo aggiungere per far emergere malfunzionamenti che non sono apparsi con il testing fatto con casi di prova basati su criteri black-box? ”

Per abuso di linguaggio si parla di white/black-box testing: è solo la progettazione white/black box, non il testing!

Banalmente potremmo dire che un programma non è testato adeguatamente se alcuni suoi elementi non vengono mai esercitati dai test. 
I criteri strutturali di progettazione di casi di test (aka control flow testing) sono definiti per classi particolari di elementi e richiedono che i test esercitino tutti quegli elementi del programma. Gli elementi possono essere: comandi, branches (decisioni), condizioni o cammini.

### Grafo di flusso
*Definizione* (**Grafo di flusso**): definisce la struttura del codice identificandone le parti e come sono collegate tra loro, è ottenuto a partire dal codice.

I diagrammi a blocchi (detti anche diagrammi di flusso oflow chart) sono un linguaggio di modellazione grafico per rappresentare algoritmi (in senso lato).

**Esempio**.
```java
double eleva(int x, int y) { 
	if (y<0) 
		pow = 0-y; 
	else 
		pow = y; 
	z = 1.0; 
	while (pow!=0) { 
		z = z*x; 
		pow = pow-1;
	} 
	if (y<0) 
		z = 1.0 / z; 
	return z;
}
```

Grafo di flusso corrispondente al codice:
![[Screenshot 2023-12-04 at 16.07.43.png]]

### Criterio: copertura dei comandi
Si cercano valori per x e y che esercitino tutti i comandi
- { (x = 0, y = 0) } (non esercita tutti i comandi)
- { (x = 0, y = 0), (x = 2, y = 2) } (non esercita tutti i comandi)
- { (x = -2, y = 3), (x = 4, y = 0), (x = 0), (y = -5) } (esercita tutti i comandi)

![[Screenshot 2023-12-04 at 16.12.13.png]]

**Misura copertura dei comandi**. Misura di copertura = $\large\frac{numero \:\: di \:\: comandi \:\: esercitari}{numero \:\: di \:\: comandi \:\: totali}$

**Esempio**. 
Per avere una copertura totale servono almeno due casi di test uno con $y < 0$ ed uno con $y >= 0$. In particolare:
- { (x = 2, y = -2) } esercita i comandi lungo il cammino rosso ed ha una copertura di 8/9 = 89%
- { (x = 2, y = 0) } esercita i comandi lungo il cammino marrone ed ha una copertura di 6/9 = 66%
- { ( x = 2, y = -2),  (x = 2, y = 0) } ha una copertura di 9/9 = 100%

La copertura non è monotona rispetto alla dimensione dell’insieme di test:
{ (x=4, y=2) } ha una copertura più alta rispetto a { (x = 2, y = 0), (x = -2, y = 2)}

Al solito, cerchiamo di minimizzare il numero di test, a parità di copertura.
Ma non sempre vale la pena cercare a tutti i costi un insieme minimale che dia copertura al 100%.

### Criterio: copertura delle decisioni
Con (x=2,y=-1) si esercitano tutti i comandi ma… bisogna avere casi di test che esercitino entrambi i rami di ogni condizione. Per avere una copertura delle decisioni occorre avere almeno due casi di test: uno y<0 e uno y>=0. (Per coprire tutte le frecce).

**Misura di copertura** = $\large\frac{numero \: di \: archi \: esercitati}{numero \: di \: archi \: totali}$

Con (x = 2, y = -1) copertura di $\frac{9}{11}$ delle decisioni.

### Condizioni composte
```java
if (x > 1 || y == 0) { comando1 }
else { comando2 }
```
- Il test { x=0, y=0 } e { x = 0, y = 1 } garantisce la piena copertura delle decisioni ma non esercita tutti i valori di verità della prima condizione.
- Il test { x=2, y=2 } e { x=0, y=0 } esercita i valori di verità delle due condizioni (ma non tutte le decisioni)
- Il test { x= 2, y=0 }, {x=0, y=1 } esercita tutti i valori di verità delle due condizioni e tutte le decisioni.

### Copertura delle condizioni semplici
Un insieme di test T per un programma P copre tutte le condizioni semplici (basic condition) di P se, per ogni condizione semplice CS in P, T contiene un test in cui CS vale true e un test in cui CS vale false.$$Copertura\:delle\:basic\:condition\:=\: \large\frac{n. \:di\: valori\: assunti\: dalle\: basic\:condition}{2 * n.\: di\: basic\: conditions}$$
**Condizioni composte**
Nel esempio di prima
- Il test { x=0, y=0 } e { x = 0, y = 1 } ha copertura delle condizioni semplici: $\frac{3}{4}$.
- Il test { x=2, y=2 } e { x=0, y=0 } ha copertura delle condizioni semplici: $\frac{4}{4}$.
- Il test { x= 2, y=0 }, {x=0, y=1 } ha copertura delle condizioni semplici: $\frac{4}{4}$.

Prendiamo ora per esempio il codice:
```java
if (x > 1 && y == 0 && z > 3) { comando1 }
else { comando2 }
```
La multiple condition coverge richiede di testare le possibili combinazioni ($2^n$ con $n$ condizioni semplici).
Nell'esempio sarebbero $2^3$ casi ma (semantica java di &&) si può ridurre da 8 a 4 perché: vero vero vero; vero vero falso; vero falso _ ; false, _ , _

### Copertura dei cammini
Richiede di percorrere tutti i cammini. Cresce in modo esponenziale con il numero di decisioni ed in presenza di cicli il numero di cammini è potenzialmente infinito. 

Per limitare il numero di cammini da attraversare si richiedano casi di test che esercitino il ciclo: 0 volte, esattamente una volta, più di una volta.

Nota: alcuni cammini sono impossibili (1245679)
![[Screenshot 2023-12-05 at 12.08.29.png]]

## Fault based testing
Ipotizza dei difetti potenziali del codice sotto test. Crea e valuta una test suite sulla base della sua capacità di rilevare i difetti ipotizzati.

La più nota tecnica di fault based testing è il **test mutazionale** dove si iniettano difetti modificando il codice.

### Test mutazionale
Precondizione: aver esercitato un programma P su una batteria di test T, e aver verificato P corretto rispetto a T.
1. Si vuole fare una verifica più profonda sulla correttezza di P: si introducono dei difetti (piccoli, dette mutazioni) su P e si chiami P’ il programma modificato: P’ viene detto mutante.
2. Si eseguono su P’ gli stessi test di T. Il test dovrebbe manifestare dei malfunzionamenti. Se il test non rileva questi difetti, allora significa che la batteria di test non era abbastanza buona. Se li rivela, abbiamo una maggior fiducia sella batteria di test. 
Questo è un metodo per valutare la capacità di un test, e valutare se è il caso di introdurre test più sofisticati.

*Definizione* (**Mutazione**): una mutazione è una piccolo cambiamento in un programma.

**Esempio**. si cambia (i < 0) in (i <= 0).

**Ipotesi**: i difetti reali sono piccole variazioni sintattiche del programma corretto => mutanti sono modelli ragionevoli dei programmi con difetti.

**Che cos'è il test mutazionale?**
È un metodo di test strutturale volto a:
- Valutare/migliorare l'adeguatezza delle suite di test 
- Sistemare il numero di difetti nei sistemi sotto test.

Il processo dato un programma P e una suite di test T è il seguente:
1. Applichiamo delle mutazioni a P per ottenere una sequenza P1, P2, ..., Pn di mutanti di P.
2. Ogni mutante deriva dall'applicazioni di una singola operazione di mutazione a P.
3. Si esegue la suite di test T su ciascuno dei mutanti.

Si dice che **T uccide il mutante Pj** se rileva un malfunzionamento:
- il mutante viene ucciso se fallisce almeno in un caso di test di T
- Si dice anche che il caso di test in questione ha ucciso il mutente.

*Definizione* (**Efficacia di un test**) = quantità di mutanti uccisi/numero mutanti.
Se T uccide k mutanti su n, l'efficacia di T è k/n.

Un mutante sopravvive a una test suite se per tutti i test case della test suite non si distingue l’esito del test se eseguito sul programma originale o su quello mutante.

La tecnica si applica in congiunzione con altri criteri di test. Nella sua formulazione è prevista infatti l’esistenza, oltre al programma da controllare, anche di un insieme di test già realizzati. Uno dei vantaggi di questo approccio è che può essere quasi completamente automatizzato.

**Mettendo insieme tutte le ipotesi**
Test che trovano semplici difetti allora trovano anche difetti più complessi, una test suite che uccide i mutanti è capace anche di trovare difetti reali nel programma.

### Test mutazionale per valutare qualità di batteria di test
Specifica: la funzione foo restituisce x + y se x <= y e x * y altrimenti.
**Originale**
```java
int foo(int x, int y){
	if (x <= y) return x + y;
	else return x * y;
}
```
**Mutante**
```java
int foo(int x, int y){
	if (x < y) return x + y;
	else return x * y;
}
```

Consideriamo la batteria di test: { <(0,0), 0>, < (2,3), 5>, <(4,3), 12> }
Il mutante non viene ucciso (sopravvive), la batteria è poco adeguata e va ri-progettata anche se copre:
- criteri strutturali: tutte le decisioni, tutte le istruzioni.
- criteri funzionali: le classi di equivalenze e la frontiera.

### Test mutazione per stimare numero di difetti nel sistema
Immagina di dover contare il numero di pesci in un lago.
Mettiamo M pesci meccanici nel lago che contiene un numero imprecisato di pesci. Osserviamo N pesci e vediamo che di questi N, N1 sono meccanici.

Assunzione: i difetti che mettiamo sono rappresentativi di quelli che potrebbero esserci davvero

Ne avevamo messi M meccanici Ne osserviamo N. Di questi N1 sono meccanici. N1: N = M : Total, allora: $$Total = \large\frac{N \times M}{N_1}$$
**Esempi di mutazioni**
- crp: sostituzione (replacement) di costante per costante. Ad esempio: da (x <5) a (x <12) 
- ror: sostituzione dell'operatore relazionale. Ad esempio: da (x <= 5) a (x <5) 
- vie: eliminazione dell'inizializzazione di una variabile. Cambia int x = 5; a int x.
- lrc: sostituzione di un operatore logico. Ad esempio da & a | 
- abs: inserimento di un valore assoluto. Da x a |x|

*Definizione* (**Mutanti validi/invalido**): un mutante è invalido se non è sintatticamente corretto cioè se non passa la compilazione, è valido altrimenti.

*Definizione* (**Mutante utile**): un mutante è utile se è valido e distinguerlo dal programma originale non è facile. Cioè esiste solo un piccolo sottoinsieme di casi di test che permette di distinguerlo dal programma originale.

*Definizione* (**Mutante inutile**): un mutante è inutile se è ucciso da quasi tutti i casi di test.

Trovare mutazioni che producano mutanti validi e utili non è facile e dipende dal linguaggio.

**Come sopravvive un mutante**
- Un mutante può essere **equivalente** al programma originale. Cambiare (x <=0) a (x < 0 OR x=0) non ha cambiato l'output: La mutazione non è un vero difetto. Determinare se un mutante è equivalente al programma originale può essere facile o difficile; nel peggiore dei casi è indecidibile.
- Oppure la suite di test potrebbe essere inadeguata. Se il mutante poteva essere stato ucciso, ma non lo era, indica una debolezza nella suite di test

**Esempi**![[Screenshot 2023-12-05 at 12.51.02.png]]

Questa strategia è adottata con obiettivi diversi:
- favorire la scoperta di malfunzionamenti ipotizzati: intervenire sul codice può essere più conveniente rispetto alla generazione di casi di test ad hoc. 
- valutare l’efficacia dell’insieme di test, controllando se “si accorge” delle modifiche introdotte sul programma originale. 
- cercare indicazioni circa la localizzazione dei difetti la cui esistenza è statadenunciata dai test eseguiti sul programma originale.

Uso limitato dal gran numero di mutanti che possono essere definiti, dal costo della loro realizzazione, e soprattutto dal tempo e dalle risorse necessarie a eseguire i test sui mutanti e a confrontare i risultati.