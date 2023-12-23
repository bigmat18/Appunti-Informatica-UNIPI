![[Screenshot 2023-12-08 at 23.48.10.png | 600]]
**Esecuzione di un'interrogazione**
```js
// analisi lessicale e sintattica del comando SQL Q
SQLCommand parseTree = Parser.parseStatement(Q)

// analisi semantica del comando
Type type = parseTree.check();

// ottimizzazione dell'interrogazione
Value pianoDiAccesso = parseTree.Optimize(); 

// esecuzione del piano di accesso pianoDiAccesso.open(); 
while(!pianoDiAccesso.isDone()) { 
	Record rec = pianoDiAccesso.next(); 
	print(rec); 
} 
pianoDiAccesso.close();
```

## Ottimizzatore delle interrogazioni
L'ottimizzazione delle interrogazioni è fondamentale nei DBMS. È necessario conoscere il funzionamento dell'ottimizzatore per una buona progettazione fisica. Obiettivo dell'ottimizzatore: Scegliere il piano con costo minimo, fra possibili piani alternativi, usando le statistiche presenti nel catalogo.

**Fasi del processo di ottimizzazione**
```sql
SELECT Nome 
FROM Studenti S, Esami E 
WHERE S.Matricola=E.Matricola AND Provincia=‘PI’ AND Voto>25
```

![[Screenshot 2023-12-08 at 23.52.49.png | 150]]         ![[Screenshot 2023-12-08 at 23.53.06.png | 180]]
Verifica la correttezza del comando, normalizzazione e semplificazione della condizione.
![[Screenshot 2023-12-09 at 00.05.09.png | 160]]       ![[Screenshot 2023-12-09 at 00.05.18.png | 180]]
Trasformazione dell’albero con regole di equivalenza.

**Esempio** trasformazioni interessanti:
```sql
SELECT Matricola, Nome 
FROM Studenti 
WHERE Matricola IN ( SELECT Matricola FROM Esami WHERE Materia = 'BD');
```
																$\large \Downarrow$
```sql
SELECT Matricola, Nome 
FROM Studenti S, Esami E 
WHERE S.Matricola = E.Matricola AND Materia = 'BD';
```
																$\large \Downarrow$
```sql
SELECT Matricola, Nome 
FROM VistaStudentiPisani S, VistaEsamiBD E 
WHERE S.Matricola = E.Matricola;
```

![[Screenshot 2023-12-09 at 00.09.57.png | 170]]     ![[Screenshot 2023-12-09 at 00.10.44.png | 300]]
Piano di accesso: scelta dell’algoritmo per eseguire ogni operatore. 
**Ideale**: Trovare il piano migliore
**Euristica**: evitare i piani peggiori!

### Realizzazione degli operatori relazionali
Un operatore può essere realizzato con algoritmi diversi, codificati in opportuni **operatori fisici.**

Gli algoritmi per realizzare gli operatori relazionali si codificano in opportuni operatori fisici. Ad esempio TableScan (R), è l'operatore fisico per la scansione di R.

Abbiamo anche che ogni operatore fisico è un **iteratore**, un oggetto con metodi: open, next, isDone, reset, close. Realizzati usando gli operatori della macchina fisica, con next che ritorna un record.

Come esempio di operatori fisici prenderemo in considerazione quelli del sistema JRS e poi vedremo come utilizzarli per descrivere un algoritmo per eseguire un'interrogazione SQL (**piano di accesso**).

**Interfaccia a iteratore**
I DBMS definiscono gli operatori mediante un’interfaccia a “iteratore”, i cui metodi principali sono:
- **open** : inizializza lo stato dell’operatore, alloca buffer per gli input e l’output, richiama ricorsivamente open sugli operatori figli; viene anche usato per passare argomenti (ad es. la condizione che un operatore Filter deve applicare)
- **next** : usato per richiedere un’altra tupla del risultato dell’operatore; l’implementazione di questo metodo include next sugli operatori figli e codice specifico dell’operatore 
- **close**: usato per terminare l’esecuzione dell’operatore, con conseguente rilascio delle risorse ad esso allocate
- **isDone**: indica se vi sono ancora valori da leggere, in genera è booleano.

## Piani di accesso
Un **piano di accesso** è un algoritmo per eseguire un'interrogazione usando gli operatori fisici disponibili. 

**Interrogazione**
```sql
SELECT Nome 
FROM Studenti S, Esami E 
WHERE S.Matricola=E.Matricola AND Provincia=‘PI’ AND Voto>25
```

**Piano di accesso**
![[Screenshot 2023-12-09 at 00.20.08.png | 400]]
Le foglie sono le tabelle ed i nodi interni specificano le modalità con cui gli accessi alle tabelle e le operazioni relazionali sono effettuate.

## Operatori logici e fisici
![[Screenshot 2023-12-09 at 00.23.38.png | 550]]
![[Screenshot 2023-12-09 at 00.25.02.png | 550]]![[Screenshot 2023-12-09 at 00.25.33.png | 550]]

**Esempi**. TableScan e SortScan.
Per la scansione di R (non considerando le proiezione).
![[Screenshot 2023-12-09 at 00.29.48.png | 400]]
![[Screenshot 2023-12-09 at 00.32.11.png | 400]]
### Operatori fisici per la proiezione
Operatori per $\pi^b_{\{A_i\}}$ e $\pi_{\{A_i\}}$. 
- **Project** (O, {Ai}): per la proiezione dei record di O senza l'eliminazione dei duplicati.
![[Screenshot 2023-12-09 at 00.35.03.png | 400]]
- **Distinct** (O): per eliminare i duplicati dei record ordinati di O.
![[Screenshot 2023-12-09 at 00.36.11.png | 400]]

**Esempio** piano di acceso SFW
![[Screenshot 2023-12-09 at 00.38.08.png | 500]]

**Esempio** piano di accesso DISTINCT
![[Screenshot 2023-12-09 at 00.39.00.png | 500]]

**Esempio** piano di accesso con Indice
![[Screenshot 2023-12-09 at 00.39.38.png | 500]]

**Esempio** piano di accesso con GROUP BY
![[Screenshot 2023-12-09 at 00.40.25.png | 500]]

**Esempio** piano di accesso giunzione senza indice.
![[Screenshot 2023-12-09 at 00.41.31.png | 500]]

**Esempio** piano di accesso giunzione con indice.
![[Screenshot 2023-12-09 at 00.42.30.png | 500]]
IndexFilter("R", $Idx_{R.A}$, R.A = S.B) è un errore.