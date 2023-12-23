**Obiettivo**: noto il valore di una chiave, trovare il record di una tabella con qualche accesso al disco (ideale: 1 accesso).

**Alternative**: 
- Metodo procedurale (hash) o tabellare (indice) 
- Organizzazione statica o dinamica.

## Hash file 
In un file hash i record vengono allocati in una pagina il cui indirizzo dipende dal valore di chiave del record:
$$key \to H(key) \to page\:address$$
Una comune funzione hash è il resto della divisione intera:
$$H(k) = k \mod NP$$
Si può applicare anche a chiavi alfanumeri che dopo averle convertite

![[Screenshot 2023-12-08 at 16.25.58.png | 550]]
### Metodo procedurale statico
Parametri di progetto: 
- La **funzione per la trasformazione** della chiave.
- Il **fattore di caricamento** d=N/(M $*$ c). (Frazione dello spazio fisico disponibile mediamente utilizzata. Se N è il numero di tuple previsto per il file, M il fattore di pagine e c il fattore di caricamento, il file può prevedere un numero di blocchi B pari al numero intero immediatamente superiore a d)
- La **capacità c** delle pagine.
- l metodo per la **gestione dei trabocchi**.

![[Screenshot 2023-12-08 at 16.27.48.png | 550]]

Le collisioni (overflow) sono di solito gestite con liste linked. E’ l'organizzazione più efficiente per l'accesso diretto basato su valori della chiave con condizioni di uguaglianza (**accesso puntuale**).

Non è efficiente per **ricerche basate su intervalli** (n. per ricerche basate su altri attributi). Funzionano solo con file la cui dimensione non varia molto nel tempo (PROCEDURALE **STATICO**)

Trade-off:
- Se il numero di blocchi  è troppo piccolo rispetto al database si hanno frequenti collisioni (con catene di overflow, etc)
- Se il numero di blocchi è troppo grande rispetto al database si ha un fattore di riempimento dei blocchi molto basso. 

La struttura Hash non è efficente per le query su un range di valori
```sql 
SELECT * 
FROM STUDENTI 
WHERE (MATRICOLA>10000) AND (MATRICOLA<20000)
```
Struttura Hash non è efficiente per le operazioni che coinvolgono attributi che non sono chiave.

### Metodo tabellare
Il metodo procedurale (hash) è utile per ricerche per chiave ma non per intervallo. Per entrambi i tipi di ricerche è utile invece il **metodo tabellare**: si usa un **indice**, ovvero di un **insieme ordinato** di coppie (k, r(k)), dove k è un valore della chiave ed r(k) è un riferimento al record con chiave k.

L’indice è gestito di solito con un'opportuna struttura albero detta $B^+$- albero, la struttura più usata e ottimizzata dai DBMS. Gli indici possono essere multi-attributi.

*Definizione* (**Indice**): struttura che contiene informazioni sulla posizione di memorizzazione delle tuple sulla base del valore del campo chiave.

La realizzazione di indici avviene tipicamente attraverso l’utilizzo di strutture ad albero multi-livello.

### Albero binario di ricerca
Albero binario etichettato, in cui per ogni nodo,
- il sottoalbero sinistro contiene solo etichette minori di quella del nodo 
- il sottoalbero destro etichette maggior
![[Screenshot 2023-12-08 at 19.20.20.png | 300]]
Tempo di ricerca (ed inserimento), pari alla profondità. Logaritmico nel caso "medio" (assumendo un ordine di inserimento casuale).

Ogni nodo ha (fino a) P figli e (fino a) P-1 etichette, ordinate. Un albero di ricerca di ordine p è un albero i cui nodi contengono al più p-1 search value e p puntatori nel seguente ordine:
$$<P_1, K_1, P_2, K_2, \dots, P_{q-1}, K_{q-1}, P_{q}> \: con\: q \leq p$$
Ogni $P_i$ è un puntatore ad un nodo figlio (o un puntatore nullo) e ogni $K_i$ è un search value appartenente ad un insieme totalmente ordinato.
![[Screenshot 2023-12-08 at 19.23.44.png | 500]]
Ogni albero di ricerca deve soddisfare due vincoli fondamentali:
1. In ogni nodo $K_1 < K_2 < \dots < K_{q-1}$
2. per tutti i valori di X presenti nel sottoalbero puntato da $P_i$ , vale la seguente relazione:
	- $K_{i-1} < X < K_i$ per $1 < i < q$
	- $X < K_i$ per $i = 1$
	- $K_{i-1} < X$ per $i = q$
Un albero di ricerca può essere utilizzato per cercare record memorizzati su disco. Ogni ricerca/modifica comporta la visita di un cammino radice foglia. I valori di ricerca (search value) possono essere i valori di uno dei campi del file (search field). Ad ogni valore di ricerca è associato un puntatore al record avente quel valore (oppure al blocco contenente quel record) nel file di dati.

L'albero stesso può essere memorizzato su disco, assegnando ad ogni nodo dell'albero una **pagina**. Quando un nuovo record deve essere inserito, l’albero di ricerca deve essere aggiornato includendo il valore del campo di ricerca del nuovo record, col relativo puntatore al record (o alla pagina che lo contiene), nell’albero di ricerca.

Per inserire (risp. cancellare) valori di ricerca nell’ (risp. dall’) albero di ricerca sono necessari specifici algoritmi che garantiscano il rispetto dei due vincoli fondamentali.

In generale, tali algoritmi **non garantiscono** che un albero di ricerca risulti sempre bilanciato (nodi foglia tutti allo stesso livello). Soluzione: B-alberi e $B^+$-alberi.

### B-tree
Un **B-tree di ordine p** di record in un file di dati, deve soddisfare le seguenti condizioni:
- Ogni nodo interno del B-tree ha la forma:
    $<P_1, <K_1, Pr_1>, <K_2, Pr_2>, \dots, <K_{q-1}, Pr_{q-1}>, P_{q}> \: con \: q \leq p$
    1. $P_i$ è un tree pointer (puntatore ad un altro nodo del B-tree)
    2. $K_i$ è la chiave di ricerca.
    3. $Pr_i$ è un data pointer (puntatore ad un record il cui campo chiave di ricerca è uguale a $K_i$ o alla pagina che contiene tale record)
- Per ogni nodo, si ha che: 
	$K_1 < K_2 < \dots < K_{q-1}$
- Ogni nodo ha al più p tree pointer

Inoltre abbiamo che per tutti i valori X della chiave di ricerca appartenenti al sottoalbero puntato da $P_i$ , si ha che:
- $K_{i-1} < X < K_i$ per $1 < i < q$
- $X < K_i$ per $i = 1$
- $K_{i-1} < X$ per i = q

La **radice** ha almeno due tree pointer, a meno che non sia l'unico nodo dell'albero.
Ogni **nodo**, esclusa la radice, ha almeno ⎡p/2⎤ tree pointer; un nodo con q tree pointer, q ≤ p, ha q-1 campi chiave di ricerca (e q-1 data pointer).
Tutti i **nodi foglia** sono posti allo stesso livello (i nodi foglia hanno la stessa struttura dei nodi interni, ad eccezione del fatto che tutti i loro tree pointer Pi sono nulli)
![[Screenshot 2023-12-08 at 19.41.11.png | 600]]
### $B^+$-tree
Un $B^+$-tree è un B-albero in cui i data pointer sono memorizzati solo nei nodi foglia dell'albero. La struttura dei nodi foglia differisce dal B-tree quindi da quella dei nodi interni.
- Se il campo di ricerca è un campo chiave, i nodi foglia hanno per ogni valore del campo di ricerca una entry e un puntatore ad un record.
- Se un campo di ricerca non è un campo chiave, i puntatori indirizzano un blocco che contiene i puntatori ai record del file di dati, rendendo così necessario un passo aggiuntivo per l'accesso ai dati.

I nodi foglia di un $B^+$-tree sono generalmente messi fra loro in relazione (ciò viene sfruttato nel caso di range query). Essi corrispondono al primo livello di un indice. I nodi interni corrispondono agli altri livelli di un indice. Alcuni valori del campo di ricerca presenti nei nodi foglia sono ripetuti nei nodi interni per guidare la ricerca.

La struttura dei **nodi interni** (di ordine p) di un $B^+$-tree è la seguente:
1. Ogni nodo interno del $B^+$-tree ha la forma:
			$<P_1, K_1, P_2, K_2, \dots, P_{q-1}, K_{q-1}, P_{q}> \: con\: q \leq p$
	ogni $P_i$ è un tree pointer (puntatore ad un altro nodo del $B^+$-tree)
2. Per ogni nodo interno, si ha che:
			$K_1 < K_2 < \dots < K_{q-1}$
3. Ogni nodo interno ha la più p tree pointer
4. Per tutti i valori di X della search key nel sottoalbero puntato da $P_i$ si ha che:
	- $K_{i-1} < X \leq K_i$ per $1 < i < q$
	- $X \leq K_i$ per $i = 1$
	- $K_{i-1} < X$ per i = q
5. Ogni nodo interno, esclusa la radice, ha almeno $\lceil P/2\rceil$ tree pointer. La radice ha almeno 2 tree pointer se è un nodo interno.
6. Un nodo interno con q tree pointer, con $q \leq p$ ha $q-1$ campi di ricerca.
![[Screenshot 2023-12-08 at 19.56.28.png | 600]]
La struttura dei **nodi foglia** (di ordine pleaf) di un $B^+$-albero è la seguente:
1. Ogni nodo foglia è della forma: 
	$< <K_1, Pr_1>, <K_2, Pr_s>, \dots, <K_q, Pr_q> P_{next}>$ dove $q \leq p_{leaf}$ 
	e per ogni nodi si ha che $K_1 < K_2 < \dots < K_q$ e che
	-  $P_{next}$ + un tree pointer al successivo nodo foglia del $B^+$-tree
	- ogni $Pr_i$ è un dato pointer che punta al record con valore del campo di ricerca uguale a $K_i$ o ad un blocco contenente tale record (o ad un blocco di puntatori ai record con valori del campo di ricerca uguale a $K_i$, se il campo di ricerca non è una chiave)
2. Ogni noto foglia ha almeno $\lceil p_{leaf}/2\rceil$ valori
3. Tutti i nodi foglia sono dello stesso livello
![[Screenshot 2023-12-08 at 20.23.40.png]]
### Indici
Di solito un indice è organizzato a $B^+$- albero per permettere di trovare con pochi accessi, a partire da un valore v, i record di R in cui il valore di A è in una relazione specificata con v.

Due tipologie di indici ad albero:
- **Indici statici**: la struttura ad albero viene creata sulla base dei dati presenti nel DB, e non più modificata (o modificata periodicamente)
- **Indici dinamici**: La struttura ad albero viene aggiornata ad ogni operazione sulla base di dati di inserimento o di cancellazioni, memorizzati, preservando le prestazioni senza bisogno di riorganizzazioni. 

*Definizione* (**Indice**): struttura che contiene informazioni sulla posizione di memorizzazione delle tuple sulla base del valore del campo chiave.

Tali strutture velocizzano l'accesso casuale via chiave di ricerca. 
Possiamo distinguere:
- **Indice primario**: in questo caso la chiave di ordinamento del file sequenziale coincide con la chiave di ricerca dell’indice.
- **Indice secondario**: in questo caso invece la chiave di ordinamento e la chiave di ricerca sono diverse.

Un indice può essere definito su di un insieme di $A_1, \dots, A_n$ di attributi.
In questo caso, l'indice contiene un record per ogni combinazione di valori assunti dagli attributi $A_1, \dots, A_n$ nella relazione, e può essere utilizzato per rispondere in modo efficiente ad interrogazioni che specifichino un valore per ciascuno di questi attributi.

**Indice primario**
Un indice primario è un file ordinato i cui record sono di lunghezza fissa e sono costituiti da due campi.
- Il primo campo è dello stesso tipo del campo chiave di ordinamento (Chiave primaria)
- Il secondo campo è un puntatore a un blocco del disco

Esiste un record nel file dell’indice per ogni blocco nel file di dati: $<K(i), RID(i)>$ 
![[Screenshot 2023-12-08 at 20.32.15.png | 400]]

**Indice secondario**
Un indice secondario può essere definito su un campo non chiave che è una chiave candidata e ha valori univoci, o su un campo non chiave con valori duplicati.
- Il primo campo è dello stesso tipo del campo che non viene usato per ordinare il file ed è chiamato campo di indicizzazione
- Il secondo campo è un puntatore al blocco oppure un puntatore al record (RID)
![[Screenshot 2023-12-08 at 20.42.17.png | 500]]

