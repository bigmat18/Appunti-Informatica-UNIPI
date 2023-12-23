È importante andare ad effettuare un ordinamento di archivi perché:
- Risultato di interrogazioni ordinato (order by)
- Per eseguire alcune operazioni relazionali (join, select distinct, group by)

Si usa un algoritmo di merge-sort che ha un costo di $n*\log(n)$
## Implementazione sort
L'algoritmo più comunemente utilizzato dai DBMS è quello detto **Merge-sort** a Z vie.
Supponiamo di dover ordinare un input che consiste di un file di NP pagine e di aver a disposizione solo NB < NP buffer in memoria centrale.
L'algoritmo opera in 2 fasi:
- **Sort interno**: Si leggono uno alla volta pe pagine del file, i record i ogni pagina vengono ordinati facendo uso di un algoritmo si sort interno (es. quicksort), ogni pagina così ordinata, detta anche "run" viene scritta su disco in un file temporaneo.
- **Merge**: operando uno o più passi di fusione, le run vengono fuse, fino a produrre un'unica run.

### Z-way merge sort caso base
Per semplicità consideriamo il caso base a Z = 2 vie, e supponiamo di avere a disposizione solo NB = 3 buffer in memoria centrale.
![[Screenshot 2023-12-08 at 21.03.17.png | 500]]

Nel caso base Z = 2 si fondono 2 run alla volta, con NB = 3 si associa un buffer ad ognuna delle run, il terzo buffer serve per produrre l'output, 1 pagina alla volta.

Si legge la prima pagina da ciascuna run e si può quindi determinare la prima pagina dell'output, quando tutti i record di una pagina di run sono stati consumati, si legge un'altra pagina della run. 
![[Screenshot 2023-12-08 at 21.34.22.png | 500]]

**Complessità caso base**
Consideriamo per semplicità solo il numero di operazioni di I/O. Nel caso base Z = 2 (e NB = 3) si può osservare che:
- Nella fase di sort interno si leggono e si riscrivono NP pagine
- Ad ogni passo di merge si leggono e si riscrivono NP pagine (2$*$NP). Il numero di passi fusione è pari a $\lceil \log_2NP\rceil$ in quanto ad ogni passo il numero di run si dimezza.
- Il costo complessivo è pertatno pari a $2 * NP * (\lceil log_2NP\rceil + 1)$ 

**Esempio**. per ordinare NP = 8000 pagine sono necessarie circa 224.000 (2*8000*( ⎡ log28000⎤ + 1)) operazioni di I/O; se ogni I/O richiede 20 msec, il sort richiede 4.480 secondi, ovvero circa 1h 15 minuti!

In realtà se NP non è una potenza di 2 il numero effettivo di I/O è leggermente minore di quello calcolato, in quanto in uno o più passi di fusione può capitare che una run non venga fusa con un’altra.

### Z-way Sort-merge caso generale
Una prima osservazione è che nel passo di sort interno, avendo a disposizione NB buffer, si possono ordinare NP pagine alla volta (anziché una sola), il che porta a un costo di $2*NP* (\lceil log_2 (NP/NB)\rceil + 1)$ 

**Esempio**. Con NP = 8000 pagine e NB = 3 si hanno ora 208.000 I/O.
Miglioramenti sostanziali si possono ottenere se, avendo NB > 3 buffer a disposizione, si fondono NB – 1 run alla volta (1 buffer è per l’output). In questo caso il numero di passi di fusione è logaritmico in NB – 1, ovvero è pari a $2 * NP * (\lceil \log_{NB-1}(NP/NB)\rceil + 1)$ 

**Esempio**. Con NP = 8000 pagine e NB = 11 si hanno 64000 I/O, per un tempo stimato pari a 1280 sec.
![[Screenshot 2023-12-08 at 22.53.44.png | 500]]

**Utilità del Sort**. Oltre che per ordinare le tuple, il sort può essere utilizzato per:
- Query in cui compare l'opzione DISTINCT, ovvero per eliminare i duplicati
- Query che contengono la clausola GROUP BY

## Realizzazione operatori relazionali 

### Proiezione
```sql
SELECT provincia
FROM Studenti R
```

```sql
SELECT DISTINCT provincia
FROM Studenti R
```

Caso di DISTINCT: approccio basato sull'ordinamento (non è l'unico!)
- Si legge R e si scrive T che contiene solo gli attributi della SELECT
- Si ordina T su tutti gli attributi
- Si eliminano i duplicati

### Restrizione con condizione semplice
```sql
SELECT *
FROM Studenti R
WHERE R.Provincia = 'PI'
```
Senza indice e dati disordinati: Npag(R). Con indice ($B^+$-albero): CI + CD

### Operazioni di aggregazione
**Senza** GROUB BY si visitano i dati e si calcolano le funzioni di aggregazione.
```sql
SELECT COUNT(*) 
FROM Persone
```

**Con** GROUP BY: Approccio basato sull'ordinamento (non è l'unico!). Si ordinano i dati sugli attributi del GROUP BY poi si visitano i dati e si calcolano le funzioni di aggregazione per ogni gruppo.
```sql
SELECT cognome, COUNT(cognome)
FROM Persone 
GROUP BY cognome
```
### Giunzione
```sql
SELECT *
FROM Studenti S, Esami E
WHERE S.Matricola = E.Matricola
```
Anche se logicamente il Join sia commutativo, dal punto di vista fisico vi è una chiara distinzione, che influenza anche le prestazioni, tra operando sinistro (o “esterno”, “outer”) e operando destro (o “interno”, “inner”).
R x S è grande; pertanto, R x S seguito da una restrizione è inefficiente.
![[Screenshot 2023-12-08 at 23.11.02.png | 500]]

### Nested loops
```
foreach record r in R do
	foreach record s in S do
		if ri = sj then
			aggiugni <r,s> al risultato
```
I costo di esecuzione dipende dallo spazio a disposizione in memoria centrale. Nel caso base in cui vi sia 1 buffer per R e 1 buffer per S, bisogna leggere 1 volta R e Nrec(R) volte S, ovvero tante volte quante solo le tuple della relazione esterna, per un totale di:
$$Npag(R) + Nrec(R) * Npag(S) \:I/O$$
Se è possibile allocare Npag(S) buffer per la relazione interna il costo si riduce a Npag(R)+Npag(S).

**Esempio relazioni esterna vs interna**. 
Se si fa il join tra Dipartimenti e Impiegati (DipImp = NumDip) e si ha:
	Npag(Dipartimenti) = 20             Nrec(Dipartimenti) = 100
	Npag(Impiegati) = 1000              Nrec(Impiegati) = 1000

**Dipartimenti esterna**
Npag(Dipartimenti) + Nrec(Dipartimenti) * Npag(Impiegati) = 100.020 I/O

**Impiegati esterna** 
Npag(Impiegati) + Nrec(Impiegati) * Npag(Dipartimenti) = 201.000 I/O

Per ogni record della relazione esterna R, si visita tutta la relazione interna S.
Costo: Npag(R) + Nrec(R) * Npag(S) $\approx$ Npag(R) $*$  $\large\frac{Nrec(R)}{Npag(R)}$ $*$ Npag(S)

Nrec(R)/Npag(R) < Nrec(S)/Npag(S) si sceglierà R come esterna e S come interna se Nrec(R) * Npag(S) < Nrec(S) * Npag(R) che corrisponde a dire che le tuple di R sono più grandi di quelle di S

Mentre con S esterna:
Costo: Npag(S) + Nrec(S) * Npag(R) $\approx$ Npag(S) $*$  $\large\frac{Nrec(S)}{Npag(S)}$ $*$ Npag(R)
Come esterna conviene la relazione con record più lunghi/grandi

**Cammini di accesso**
L’ordine con cui vengono generate le tuple del risultato coincide con l’ordine eventualmente presente nella relazione esterna.

![[Screenshot 2023-12-08 at 23.27.07.png | 550]]

Pertanto se l’ordine che si genera è “interessante”, ad esempio perché la query contiene ORDER BY R.A, la scelta della relazione esterna può risultarne influenzata.
### PageNestedLoop
Molti DBMS usano una variante del Nested Loops, detta Nested loop a pagine, che, rinunciando a preservare l’ordine della relazione esterna, risulta più efficiente in quanto esegue il join di tutte le tuple in memoria prima di richiedere nuove pagine della relazione interna.

Per ogni pagina $p_R$ di R:
	Per ogni pagina $p_s$ in S:
		esegui il join di tutte le tuple in $p_r$ e $p_s$

![[Screenshot 2023-12-08 at 23.28.43.png | 550]]
La strategia si estende anche al caso in cui a R siano assegnati più buffer.

### IndexNestedLoop
Data una tupla della relazione esterna R, la scansione completa della relazione interna S può essere sostituita da una scansione basata su un indice costruito sugli attributi di join di S, secondo il seguente schema.
![[Screenshot 2023-12-08 at 23.44.02.png]]
L’accesso alla relazione interna mediante indice porta in generale a ridurre di molto i costi di esecuzione del Nested Loops Join.

### SortMerge
Il **merge-sort join** è applicabile quando entrambi gli insiemi di tuple in input sono ordinati sugli attributi di join. 

La logica dell’algoritmo (senza considerare il tempo per il sort) sfrutta il fatto che entrambi gli input sono ordinati per evitare di fare inutili confronti, il che fa sì che il numero di letture sia dell’ordine di Npag(R) + Npag(S) se si accede sequenzialmente alle due relazioni.

Per R(S) ciò è possibile se:
- R(S) è fisicamente ordinata sugli attributi di join
- Esiste un indice sugli attributi di join di R(S)
![[Screenshot 2023-12-08 at 23.46.32.png]]

