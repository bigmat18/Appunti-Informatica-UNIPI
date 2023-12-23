**Operazioni sullo schema**: DDL (Data definition language). Operazioni di creazione, cancellazione e modifica di schemi di tabelle, creazione di viste, creazione indici...

**Operazioni sui dati**: DML (Data manipulation language): Query o interrogazione della base di dati oppure inserimento, cancellazione e modifica di dati.

*Definizione* (**Algebra relazionale**): insieme di operatori su relazioni che danno come risultato relzioni. Non si sua come linguaggio di interrogazione dei DMBS ma come rappresentazione interna delle interrogazioni.

Definizione (Calcolo relazionale): Linguaggio dichiarativo di tipo logico dal quale è stato derivato l'SQL.

Operazioni dell'algebra relazionale: unione, intersezione, differenza, ridenominazione, selezione, proiezione, join (join naturale, prodotto cartesiano, theta-join).

## Operatori insiemistici
Le relazioni sono insiemi, i risultati devono essere relazioni, è possibile applicare unione, intersezione, differenza solo a relazioni definite sugli stessi attribuiti (nome e tipo), cioè possono operare solo su tuple uniformi.
### Unione 
![[Screenshot 2023-11-26 at 16.33.04.png]]
Unione: $R \cup S$
### Differenza
![[Screenshot 2023-11-26 at 16.41.56.png]]
Differenza: $R \setminus S$

**Esempio**. Unione sensata ma impossibile.
![[Screenshot 2023-11-26 at 16.44.38.png]]
### Ridenominazione
Operatore **monadico** (con un argomento), "modifica lo schema" lasciando inalterata l'istanza dell'operatore. È indicato con la lettera $\rho$.

![[Screenshot 2023-11-26 at 17.00.15.png]]
### Proiezione
Operatore monadico, produce un risultato che, ha parte degli attributi dell'operando, contiene ennuple cui contribuiscono tutte le ennuple dell'operando ristrette agli attributi nella lista.
Sintassi: $\pi_{ListaAttributi}(Operando)$

**Esempio**. Matricola e cognome di tutti gli impiegati.
![[Screenshot 2023-11-26 at 17.02.22.png]]
**Proiezione**: $\pi_{Nome, Matricola}(Studenti)$

**Esempio**. Con duplicati
![[Screenshot 2023-11-26 at 17.20.01.png]]

Una proiezione contiene al più tante ennuple quante l'operando, può ovviamente contenerle meno.
Se $X$ è una superchiave di $R$, allora $\pi_X(R)$ contiene esattamente tante ennuple quante $R$.
Mentre se $X$ non è una superchiave, potrebbe esistere valori ripetuti su queli attributi, che quindi vengono rappresentati una sola volta.

### Selezione
Operatore monadico che produce un risultato che ha lo stesso schema dell'operando e contiene un sottoinsieme delle ennuple dell'operando. 

Quelle che soddisfano una condizione espressa combinando, con i connettivi logici $\land$ (and), $\lor$ (or), $\lnot$ (not), condizioni atomiche del tipo $A \:\: \Theta \:\: B$ o $A \:\: \Theta \:\: C$  dove $\Theta$ è un operatore di confronto, e $A$ e $B$ sono attributi su cui l'operatore abbia senso, $c$ una constante compatibile con dominio di $A$. 

È denotate con $\sigma$, con la condizione messa a pendice.

**Esempio**. Impiegato che guadagna più di 50 euro.
![[Screenshot 2023-11-26 at 17.44.20.png]]

**Esempio**. Impiegati che guadagnano più di 50 e lavorano a Milano.
![[Screenshot 2023-11-26 at 17.44.58.png]]

**Esempio**. Selezione con valori nulli.
![[Screenshot 2023-11-26 at 17.46.21.png]]
La condizione atomica è vera colo per valori non nulli.
### Restrizione
Restrizione (Selezione): $\sigma_{condizione}(R)$ 

**Esempi**:
- $\sigma_{Nome = 'Caio'}(Studenti)$
- **Composizione di operatori**: $\pi_{Matricola}(\sigma_{Nome = 'Caio'}(Studenti))$ 

![[Screenshot 2023-11-26 at 17.49.41.png]]

Un risultato non desiderabile:
$$\sigma_{età > 30}(Persona) \cup \sigma_{Età \leq 30}(Persone) \neq Persone$$
Questo perchè le sezioni vengono valutare separatamente. Ma anche:
$$ \sigma_{età > 30 \lor età \leq30} (Persone) \neq Persone $$
Perché anche le condizioni atomiche vengono valutate separatamente.
La condizione atomica è inoltre vera solo per valori non nulli, per riferirsi ai valori nulli esistono forme apposite di condizioni: IS NULL, IS NOT NULL.

A questo punto:
$$\sigma_{età > 30}(Persona) \cup \sigma_{Età \leq 30}(Persone) \cup \sigma_{Eta \: IS \: NULL}(Persone) = $$
$$= \sigma_{età > 30 \lor età \leq 30 \lor Età \: IS \: NULL} (Persone) = Persone$$
**Esempio**.
![[Screenshot 2023-11-26 at 18.09.15.png]]

### Priezione e restrizione
- Proiezione: $\pi_{A,b}(R)$
![[Screenshot 2023-11-26 at 18.11.30.png]]

- Restrizione: $\sigma_{Cond}(R)$
![[Screenshot 2023-11-26 at 18.11.17.png]]

Combinando selezione e proiezione, possiamo estrarre interessanti informazioni da una relazione.

**Esempio**. Matricola e cognome degli impiegati che guadagnano più di 50.
![[Screenshot 2023-11-26 at 18.13.38.png | 400]]

### Prodotto
![[Screenshot 2023-11-26 at 18.14.19.png | 400]]

**Esempio**.
![[Screenshot 2023-11-26 at 18.14.50.png | 400]]

### Intersezione
![[Screenshot 2023-11-26 at 18.15.16.png | 500]]

Possiamo derivare l'operatore intersezione usando gli operatori: $R(A,B), \:\: S(A, B)$, prodotto, ridenomazione, selezione, proiezione.

![[Screenshot 2023-11-26 at 18.16.29.png | 500]]

**Esempio**. Prove scritte in un concorso pubblico. I compiti sono anonimi e ad ognuno è associata una busta chiusa con il nome del candidato. Ciascun compito e la relativa busta vengono contrassegnati con uno stesso numero.

![[Screenshot 2023-11-26 at 18.21.43.png | 500]]

![[Screenshot 2023-11-26 at 18.21.56.png | 500]]

**Prodotto cartesiano a chiavi esterne**
![[Screenshot 2023-11-26 at 18.22.46.png]]
$$\pi_{Matr,Nome,Materia,Data,Voto}(\sigma_{matricola=s.matricola}(Esami \: \times \: \rho_s \: Stuedenti)$$
**Prodotto cartesiano, rappresentazione mediante albero**
![[Screenshot 2023-11-26 at 18.25.00.png]]

## Join (Giunzione)
Combinando selezione e proiezione, possiamo estrarre informazioni da una relazione, ma non possiamo però correlare informazioni presenti in relazioni diverse.

il join è l'operatore più interessante dell'algebra relazionale poiché permette di correlare dati in relazioni diverse.

### Join naturale
![[Screenshot 2023-11-26 at 18.26.15.png]]

Operatore binario (generalizzabile) che correla dati in relazioni diverse, sulla base di valori uguali in attributi con lo stesso nome.
- Produce un risultato: sull'unione degli attributi degli operandi con ennuple che sono ottenute combinando le ennuple degli operandi con valori uguali sugli attributi in comune.
- $R_1(X_1), R_2(X_2)$
- $R_1 \bowtie R_2$ è una relazione su $X_1 \cup X_2$.$$ R_1 \bowtie R_2 = \{ \: t \: su \: X_1 \cup X_2 \:\: \textbar \:\: t_1 \in R_1 \: e \: t_2 \in R_2 \: con \: T[X_1] = t_1\: e\: T[X_2] = t_2 \}$$
**Join naturale e attributi uguali.**
![[Screenshot 2023-11-26 at 18.30.57.png]]

**Join non completo.**![[Screenshot 2023-11-26 at 18.31.46.png]]

**Join vuoto.**
![[Screenshot 2023-11-26 at 18.32.01.png]]

**Join completo, con $n \times m$ ennuple**
![[Screenshot 2023-11-26 at 18.32.57.png]]

### Cardinalità delle join
Prendiamo $R_1(A,B), \: R_2(B,C)$, Il join di $R_1$ e $R_2$ contiene un numero di ennuple compreso fra zero ed il prodotto di $|R_1|$ e $|R_2|$:
$$ 0 \:\: \leq \:\: |R_1 \bowtie R_2| \:\: |R_1| \times |R_2|$$
Se la join fra $R_1$ ed $R_2$ è completo, allora contiene un numero di ennuple almeno uguale al massimo fra $|R_1|$ e $R_2$. Se la join coinvolge una chiave B  di $R_2$ allora il numero di ennuple è compreso fra zero e $|R_1|$:
$$0 \:\: \leq |R_1 \bowtie R_2| \:\: \leq |R_1|$$
Se il join coinvolge una chiave $B$ di $R_2$ e un vincolo di integrità referenziale tra attributi di $R_1$ ($B$ in $R_1$) e la chiave di $R_2$, allora il numero di ennuple è pari a $|R_1|$:
$$|R_1 \bowtie R_2| = |R_1|$$
Una difficoltà della join:
![[Screenshot 2023-11-26 at 21.06.46.png | 500]]

### Join esterno
Il join estende, con valori nulli, le ennuple che vorrebero tagliate fupri da un join (interno). Esiste in tre versioni: sinistro, destro esterno.
- **Sinistro** (left): mantiene tutte le ennuple del primo operando, estendendole con valori nulli, se necessario. $R \overleftarrow{\bowtie} S$ 
- **Destro** (left): mantiene tutte le ennuple del secondo operando, estendendole con valori nulli, se necessario. $R \overrightarrow{\bowtie} S$ 
- **Completo** (full): mantiene tutte le ennuple di entrambi gli operandi, estendendole con valori nulli, se necessario. $R \overleftrightarrow{\bowtie} S$ 

**Esempio**
![[Screenshot 2023-11-26 at 21.13.19.png]]

![[Screenshot 2023-11-26 at 21.13.39.png]]

![[Screenshot 2023-11-26 at 21.13.51.png]]

### Join e proiezioni

![[Screenshot 2023-11-26 at 21.15.06.png]]

![[Screenshot 2023-11-26 at 21.15.38.png]]

### Theta-join e equi-join
Un join naturale su relazioni senza attributi in comune contiene sempre un numero di ennuple pari al prodotto delle cardinalità degli operandi (le ennuple sono tutte combinabili).

Il prodotto cartesiano concatena tutle non necessariamente correlate dal punto di vista semantico.

![[Screenshot 2023-11-26 at 21.17.23.png]]

Il prodotto cartesiano è più utile se fatto seguire da una selezione. Prodotto cartesiano seguito dalla selezione che mantiene solo le tuple con valori uguali sull’attributo: Reparto di Impiegati e Codice di Reparti.

Il prodotto cartesiano, in pratica, ha senso solo se seguito da selezione:$\sigma_{condizione}(R_1 \bowtie R_2)$ 

L'operazione viene chiamata **theta-join** e può essere sintatticamente indicata con $R_1 \bowtie_{condizione} R_2$ 

Perché "theta-join"? La condizione $C$ è spesso una congiunzione ($\land$) di atomi di confronto di $A_1 \upvartheta A_2$ dove $\upvartheta$ è uno degli operatori di contronto ($=, >, <, \dots$) Se l'operatore è sempre l'uguaglianza ($=$) allora si parla di **equi-join**.

### Giunzione
![[Screenshot 2023-11-26 at 21.21.59.png]]

![[Screenshot 2023-11-26 at 21.24.45.png]]

### Self join 
Supponiamo di considerare la seguente relazione e di volere ottenere una relazione Nonno-Nipote.
![[Screenshot 2023-11-26 at 21.25.28.png]]
È ovvio che in questo caso abbiamo bisogno di utilizzare due volte la stessa tabella. Tuttavia Genitore $\bowtie$ Genitore = Genitore, poiché tutti gli attributi coincidono. 
In questo caso è utile effettuare una ridenomianzione:
$$\rho_{Nonno, Genitore\: \leftarrow \: Genitore, Figlio}(Genitore)$$
A questo punto effettuando una natural join con la tabelle Genitore, si ottiene l'informazione cercata.
![[Screenshot 2023-11-26 at 21.28.30.png]]
Eventualmente si può effettuare una proiezione.![[Screenshot 2023-11-26 at 21.29.47.png]]

**Esempio**. Join studenti ed esami
![[Screenshot 2023-12-06 at 12.34.47.png]]

Problemi: Matricola, Nome, cognome, voto degli studenti: 
- con (almeno un) voto maggiore di 28 (quantificatore esistenziale)
- non hanno mai ottenuto un voto maggiore di 28 (differenza)
- Nomi degli studenti che hanno ottenuto solo voti maggiore di 28 (quantificatore universale)

Esempio di trasformazione su quantificatore esistenziale.
Matricola, Nome, cognome, materia, data, voto degli studenti con voto maggiore di 28.
![[Screenshot 2023-12-06 at 12.35.42.png]]

**Non distribuititivà della proiezione rispetto alla differenza**
In generale:  $\pi_A(R_1 - R_2) <> \pi_A(R_1) - \pi_A(R_2)$
Se $R_1$ e $R_2$ sono definite su AB, e contengono tuple uguali su A e diverse su B.
![[Screenshot 2023-12-06 at 12.47.02.png]]
Dipende da chi è A.
Se $R_1$ e $R_2$ sono definite su AB e contengono tuple uguali su A e diverse su B, NO.

### Raggruppamento
Il raggruppamento si definisce come:
$${}_{\{A_i\}} \gamma_{f_i}(R)$$
Gli $A_i$ sono attributi di R e le $f_i$ sono espressioni che usano funzioni di aggregazione (min, max, count, sum, ...)

Il valore del raggruppamento è una relazione calcolata come segue:
- Si partizionano le ennuple di R mettendo nello stesso gruppo tutte le ennuple con valori uguali degli $A_i$.
- Si calcolano le espressioni $f_i$ per ogni gruppo.
- Per ogni gruppo si restituisce una sola ennupla con attributi i valori degli $A_i$ e delle espressioni $f_i$.
![[Screenshot 2023-12-06 at 13.30.00.png]]

**Esecuzione del raggruppamento**
Per ogni candidato: numero degli esami, voto minimo, massimo e medio:
$$\large{}_{\{Candidato\}}\gamma_{\{count(*), min(Voto),max(voto),avg(Voto)\}}(Esame)$$
![[Screenshot 2023-12-06 at 14.22.36.png]]

**Esempio** su due attributi.
![[Screenshot 2023-12-06 at 14.23.04.png]]

**Raggruppamento su chiave primaria**
![[Screenshot 2023-12-06 at 14.23.43.png]]

![[Screenshot 2023-12-06 at 14.24.15.png]]

## Trasformazioni algebriche
Basate su regole di equivalenza fra espressioni algebriche. Consentono di scegliere diversi origini di join e di anticipare proiezioni e restrizioni. Alcuni esempi con relazioni R(A, B, C, D):
![[Screenshot 2023-12-06 at 14.25.31.png]]

**Atomizzazione delle sezioni**
$$\sigma_{F1 \land F2}(E) = \sigma_{F1}(\sigma_{F2}(E))$$
Una selezione congiuntiva può essere sostituita da una cascata si selezioni atomiche.

**Idempotenza delle Proiezioni**
Una proiezione può essere trasformata in una cascata di proiezioni che eliminano i vari attributi in fasi diverse.
$$\pi_X(E) = \pi_X(\pi_{XY}(E))$$
se E è definita su un insieme di attributi che contiene Y oltre che X. Non ha effetto sull’efficienza. Ha effetto sulla leggibilità della query.

**Anticipazione della selezione rispetto al Join**
**Pushing selection down**
$$\sigma_F(E_1 \bowtie E_2) = E_1 \bowtie \sigma_F (E_2)$$
se F fa riferimento solo ad attributi di E2 . Aumenta l’efficienza della query perché la selezione riduce il numero delle righe di E2 prima del join.

**Pushing projection down**
$$\pi_{X1Y2}(E_1 \bowtie E_2) = E_1 \bowtie \pi_{Y2}(E_2)$$
Se $E_1$ e $E_2$ definite rispettivamente su $X_1$ e $X_2$, $Y_2 \subseteq X_2$ e gli attributi in $X_2 - Y_2$ non sono coinvolti nel join. Non ha effetto sull’efficienza ma sulla leggibilità.

**Distributività della selezione rispetto all'unione**
$$\sigma_F(E_1 \cup E_2) = \sigma_F(E_1) \cup \sigma_F(E_2)$$
**Distributività della selezione rispetto alla differenza**
$$\sigma_F(E_1 - E_2) = \sigma_F(E_1) - \sigma_F(E_2)$$
**Distributività della proiezione rispetto alla unione**
$$\pi_F(E_1 - E_2) = \pi_F(E_1) - \pi_F(E_2)$$
**Non distributività della proiezione rispetto alla differenza**
In generale:
$$\pi_F(E_1 - E_2) = \pi_F(E_1) - \pi_F(E_2)$$Se $R_1$ e $R:2$ sono definite sull’insieme di attributi $X = AB$, e contengono tuple uguali su A e diverse su B.

**Esempio**
![[Screenshot 2023-12-06 at 14.59.42.png]]
Dipende da chi è A. Se $R_1$ e $R_2$ sono definite su AB e contengono tuple uguali su A e diverse su B, NO.

**Inglobamento di una selezione in un prodotto cartesiano a formare un join**
$$\sigma_F(R_1 \bowtie R_2) \equiv R_1 \bowtie_F R_2$$
**Altre equivalenze**
![[Screenshot 2023-12-06 at 15.25.52.png]]
Si noti infine che valgono proprietà commutativa e associativa di tutti gli operatori binari (unione, intersezione, join) tranne la differenza.

**Operatori algebrici non insiemistici**
- $\pi^b_{A_i}(R)$: proiezione multiisiemistica (senza eliminazione dei dublicati)
- $\uptau_{\{A_i\}}(R)$: ordinamento

**Calcolo relazionale su ennuple**
Il calcolo relazionale è un linguaggio che permette di definire il risultato di un’interrogazione come l’insieme di quelle ennuple che soddisfano una certa condizione $\phi$.

L’insieme delle matricole degli studenti che hanno superato qualcuno degli esami elencati nella relazione Materie(Materia), si può definire come:
![[Screenshot 2023-12-06 at 15.28.33.png]]

Che è equivalente a:
![[Screenshot 2023-12-06 at 15.28.56.png]]