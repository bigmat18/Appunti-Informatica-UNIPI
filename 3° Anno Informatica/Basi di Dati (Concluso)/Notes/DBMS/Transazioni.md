![[Screenshot 2023-12-09 at 00.45.25.png | 500]]
**Esempio**. Gestione ordini su un sito di ecommerce.
![[Screenshot 2023-12-09 at 00.46.16.png | 500]]
Due ordini in contemporanea eseguono la query.

## Gestione delle transazioni
*Definizione*: Le transazioni rappresentano l’unità di lavoro elementare (insiemi di istruzioni SQL) che modificano il contenuto di una base di dati.

Sintatticamente un transazione è contornata dai comandi begin transaction (e end transaction); all’interno possono comparire i comandi di commit work e rollback work.
```sql
begin transaction 
update SalariImpiegati 
set conto=conto*1.2 
where (CodiceImpiegato = 123) 
commit work
```
Le transazioni sono comprese tra una BEGIN transaction ed una commit/ rollback.
```sql
begin transaction 
update SalariImpiegati 
set conto=conto-10 
where (CodiceImpiegato = 123) if conto >0 
commit work; 
else rollback work
```

Proprietà ACID delle transazioni:
- **Atomicità**: La transazione deve essere eseguita con la regola del “tutto o niente”
- **Consistenza**: La transazione deve lasciare il DB in uno stato consistente, eventuali vincoli di integrità non devono essere violati
- **Isolamento**: L’esecuzione di una transazione deve essere indipendente dalle altre.
- **Persistenza (Durability)**: L’effetto di una transazione che ha fatto commit work non deve essere perso.

**Funzioni del DBMS in breve**
- **Gestione dei dati**: cura la memorizzazione permanente dei dati ed il loro accesso
- **Gestione del buffer**: cura il trasferimento dei dati da memoria di massa a memoria centrale, e il caching dei dati in memoria centrale
- **Ottimizzazione delle interrogazioni**: seleziona il piano di accesso di costo ottimo con cui valutare ciascuna interrogazione.
![[Screenshot 2023-12-09 at 00.50.41.png | 500]]

## Gestione dell'affidabilità
Ricordiamo che una **transazione** è un’unità logica di elaborazione che corrisponde a una serie di operazioni fisiche elementari (letture/scritture) sul DB.

**Esempi**. 
Trasferimento di una somma da un conto corrente ad un altro:
```sql
UPDATE CC 
SET Saldo = Saldo - 50 
WHERE Conto = ‘123’
```
Aggiornamento degli stipendi degli impiegati di una sede:
```sql
UPDATE Imp 
SET Stipendio = 1.1*Stipendio 
WHERE Sede = ‘PISA’
```

Una funzionalità essenziale di un DBMS è la **protezione dei dati** da malfunzionamenti e da interferenze dovute all’accesso contemporaneo ai dati da parte di più utenti.

La transazione per il programmatore:
- Una transazione è un programma sequenziale costituito da operazioni che il sistema deve eseguire garantendo: Atomicità, Consistenza, Serializzabilità , Persistenza.

*Definizione*: Una **transizione** è una sequenza di azioni di lettura e scrittura in memoria permanente e di elaborazioni di dati in memoria temporanea.

Gestore dell'affidabilità:
- **Atomicità**: Le transazioni che terminano prematuramente (aborted transactions) sono trattate dal sistema come se non fossero mai iniziate; pertanto eventuali loro effetti sulla base di dati sono annullati.
- **Persistenza**: Le modifiche sulla base di dati di una transazione terminata normalmente sono permanenti, cioè non sono alterabili da eventuali malfunzionamenti.

Gestore della concorrenza:
- **Serializzabilità**: Nel caso di esecuzioni concorrenti di più transazioni, l’effetto complessivo è quello di una esecuzione seriale.

Per aumentare l’efficienza prestazionale, tutti i DBMS utilizzano un buffer temporaneo di informazioni in memoria principale, il quale viene periodicamente scritto su memoria secondaria.
![[Screenshot 2023-12-09 at 00.55.19.png | 500]]

Una transazione può eseguire molte operazioni sui dati recuperati da una base di dati, ma al DBMS interessano solo quelle di lettura o scrittura della base di dati, indicate con $r_i[x]$ e $w_i[x]$.

Un dato letto o scritto può essere un record, un campo di un record o una pagina. Per semplicità supporremo che sia una pagina.
- **Un’operazione di lettura** $r_i[x]$ comporta la lettura di una pagina nel buffer, se non già presente.
- **Un’operazione di scrittura** $w_i[x]$ comporta l’eventuale lettura nel buffer di una pagina e la sua modifica nel buffer, ma non necessariamente la sua scrittura in memoria permanente. Per questa ragione, in caso di malfunzionamento, si potrebbe perdere l’effetto dell’operazione.

### Tipi di malfunzionamento
- **Fallimenti di transazioni**: non comportano la perdita di dati in memoria temporanea né persistente (es.: violazione di vincoli, violazione di protezione, stallo)
- **Fallimenti di sistema:** comportano la perdita di dati in memoria temporanea ma non di dati in memoria persistente (es.: comportamento anomalo del sistema, caduta di corrente, guasti hardware sulla memoria centrale)
- **Disastri**: comportano la perdita di dati in memoria persistente (es.: danneggiamento di periferica)

### Gestore dell'affidabilità
Verifica che siano garantite le proprietà di atomicità e persistenza delle transazioni.
- Responsabile di implementare i comandi di: begin transaction, commit, rollback
- Responsabile di ripristinare il sistema dopo **malfunzionamenti software** (**ripresa a caldo**)
- Responsabile di ripristinare il sistema dopo **malfunzionamenti hardware** (**ripresa a freddo**)

### File di log
Il controllore di affidabilità utilizza un log, nel quale sono indicate tutte le operazioni svolte dal DBMS.
![[Screenshot 2023-12-09 at 01.00.09.png | 500]]

**Primitive undo e redo**
Convenzioni notazionali: data una transazione T, indicheremo con B(T), C(T) e A(T) i record di **begin**, **commit** e **abort** relativi a T, rispettivamente, e con U(T, O, BS, AS), I(T, O, AS) e D(T, O, BS) i record di **update**, **insert** e **delete**, rispettivamente su un oggetto O, dove BS è before state and AS è after state.d.

I record del log associati ad una transazione, consentono di disfare e rifare le corrispondenti azioni sulla base di dati:
- primitive di **undo**: per **disfare** un’azione su un oggetto O, è sufficiente ricopiare in O il valore BS (l’insert viene disfatto cancellando l’oggetto O)
- primitiva di **redo**: per **rifare** un’azione su un oggetto O, è sufficiente ricopiare in O il valore AS (il delete viene rifatto cancellando l’oggetto O)

Il log si presenta con un **file sequenziale** diviso in record:
![[Screenshot 2023-12-09 at 11.21.12.png | 500]]
Ci sono due tipi di recor:
- **Record di transazione** (BLU). tengono traccia delle operazioni svolte da ciascuna transizione sul DBMS. Per ogni transazione, un record di begin (B), record di insert (I), delete (D) e update (U) e un record di commit (C) o di abort (A).
- **Record di sistema** (GRIGIO): tengono traccia delle operazioni di sistema (dump/checkpoint).

**Operazione di dump**
L’operazione di dump produce una copia completa della base di dati, effettuata in mutua esclusione con tutte le altre transazioni quando il sistema non è operativo.
La copia viene memorizzata in memoria stabile (backup).

Al termine del dump, viene scritto nel log un record di dump, che segnala l’avvenuta esecuzione dell’operazione in un dato istante. Il sistema riprende, quindi, il suo funzionamento normale.

**Regole di scrittura del Log**
- Regola **Write Ahead Log** (WAL): la parte BS (before state) di ogni record di log deve essere scritta prima che la corrispondente operazione venga effettuata nella base di dati.
- Regola di **Commit Precedence**: la parte AS (after state) di ogni record di log deve essere scritta nel log prima di effettuare il commit della transazione.
![[Screenshot 2023-12-09 at 11.26.04.png | 500]]
![[Screenshot 2023-12-09 at 11.26.48.png | 500]]
![[Screenshot 2023-12-09 at 11.27.23.png | 500]]

Gli algoritmi si differenziano a seconda del modo in cui si trattano le scritture sulla BD e la terminazione delle transazioni.
- Disfare–Rifare
- Disfare–NonRifare
- NonDisfare–Rifare
- NonDisfare–NonRifare
Ipotesi: Le scritture nel giornale vengono portate subito nella memoria permanente

**Disfare**
Quando si portano le modifiche nella BD?
Politica della **modifica libera**: le modifiche possono essere portate nella BD stabile prima che la T termini (disfare o steal).

Regola per poter disfare prescrittura nel giornale (**“Log Ahead Rule”** o **"Write Ahead Log"**): se la nuova versione di una pagina rimpiazza la vecchia sulla BD stabile prima che la transazione T abbia raggiunto il punto di Commit, allora la vecchia versione della pagina deve essere portata prima sul giornale in modo permanente.

**Rifare**
Come si gestisce la terminazione ?
**Commit libero**: una T può essere considerata terminata normalmente prima che tutte le modifiche vengano riportate nella BD stabile (occorre rifare).

Regola per poter rifare una T(“**Commit Rule**”) le modifiche (nuove versioni delle pagine) di una T devono essere portate stabilmente nel giornale prima che la T raggiunga il Commit (condizione per rifare).

### Checkpoint
Al momento del ripristino, solo gli aggiornamenti più recenti tra quelli riportati sul giornale/log potrebbero non essere stati ancora riportati sulla base di dati. Come ottenere la certezza che non è necessario ri-eseguire le operazioni più vecchie?

Periodicamente si fa un Checkpoint (CKP): si scrive la marca CKP sul giornale/log per indicare che tutte le operazioni che la precedono sono state effettivamente effettuate sulla BD.

UN modo (troppo semplice) per fare il CKP:
1. si sospende l’attivazione di nuove transazioni,
2. si completano le precedenti, si allinea la base di dati (ovvero si riportano su disco tutte le pagine “sporche” dei buffer),
3. si scrive nel giornale/log la marca CKP.
4. Si riprende l’esecuzione delle operazioni.

Si scrive sul giornale una marca di inizio checkpoint che riporta l’elenco delle transazioni attive (BeginCkp, $\{T_1, \dots, T_n\}$). In parallelo alle normali operazioni delle transazioni, il gestore del buffer riporta sul disco tutte le pagine modificate. 
Si scrive sul giornale una marca di EndCkp.
La marca di EndCkp certifica che tutte le scritture avvenute prima del BeginCkp ora sono sul disco. 
Le scritture avvenute tra BeginCkp e EndCkp forse sono sul disco e forse no.

### Ripresa dai malfunzionamento
- **Fallimento di transizione**: si scrive nel giornale (T, abort) e si applica la procedura disfare.
- **Fallimenti di sistema**: La BD viene ripristinata con il comando Restart (ripartenza di emergenza), a partire dallo stato al punto di allineamento, procedendo come segue:
	- Le T non terminate vanno disfatte 
	- Le T terminate devono essere rifatte.
- **Disastri**: si riporta in linea la copia più recente della BD e la si aggiorna rifacendo le modifiche delle T terminate normalmente (ripartenza a freddo).

**Ripresa a caldo**
Garantisce atomicità e persistenza delle transazioni. È composto da, quattro fasi:
1. trovare l'ultimo checkpoint (ripercorrendo il log a ritroso).
2. costruire gli insiemi UNDO (transazioni da disfare) e REDO (transazioni da rifare).
3. ripercorrere il log all'indietro, fino alla più vecchia azione delle transazioni in UNDO, disfacendo tutte le azioni delle transazioni in UNDO.
4. ripercorrere il log in avanti, rifacendo tutte le azioni delle transazioni in REDO.

![[Screenshot 2023-12-10 at 14.52.00.png | 450]]
**Esercizio**. Applicare il protocollo rifare e disfare.
![[Screenshot 2023-12-10 at 14.53.09.png | 500]]
**Fase 1**
![[Screenshot 2023-12-10 at 14.53.44.png | 500]]
**Fase 2**
![[Screenshot 2023-12-10 at 14.54.21.png | 500]]
**Fase 3 - undo**
![[Screenshot 2023-12-10 at 14.54.50.png | 500]]
**Fase 4 - redo**
![[Screenshot 2023-12-10 at 14.55.45.png | 500]]

## Gestione della concorrenza
*Definizione* (**Seriale**): Uno schedule S si dice seriale se le azioni di ciascuna transazione appaiono in sequenza, senza essere inframezzate da azioni di altre transazioni.
$$S = \{T_1, T_2, \dots, T_n\}$$Schedule seriale ottenibile se: 
1. Le transazioni sono **eseguite uno alla volta** (scenario non realistico)
2. Le transazioni sono **completamente indipendenti** l'una dall'altra (improbabile)

Il DBMS transazionale gestisce questi problemi garantendo la proprietà di isolamento. La proprietà di **isolamento** di una transazione garantisce che essa sia eseguita come se non ci fosse concorrenza. Questa proprietà è assicurata facendo in modo che ciascun insieme di transazioni concorrenti sottoposte al sistema sia "**serializzabile**". 

In un sistema reale, le **transazioni vengono eseguite in concorrenza** per ragioni di efficienza / scalabilità. Tuttavia, l'esecuzione concorrente determina un insieme di **problematiche** che devono essere gestite.
![[Screenshot 2023-12-10 at 15.02.58.png | 500]]
Se x=3, al termine delle due transazioni x vale 5 (esecuzione sequenziale) … cosa accade in caso di esecuzione concorrente?
**Perdita di aggiornamento**
![[Screenshot 2023-12-10 at 15.03.31.png | 500]]
**Lettura sporca/impropria**
![[Screenshot 2023-12-10 at 15.04.27.png | 500]]
**Letture inconsistenti/non riproducibili**
![[Screenshot 2023-12-10 at 15.04.56.png | 500]]
L’esecuzione concorrente di transazioni è essenziale per un buon funzionamento del DBMS. Il DBMS deve però garantire che l’esecuzione concorrente di transazioni avvenga senza interferenze in caso di accessi agli stessi dati.
![[Screenshot 2023-12-10 at 15.22.17.png | 400]]
Se eseguite in serie avrei: 1000+500- 800=700 euro. Se in concorrenza potrei avere un’anomalia.

*Definizione*: Un’esecuzione di un insieme di transazioni $\{T_1 , \dots, T_n\}$ si dice **seriale** se, per ogni coppia di transazioni $T_i$ e $T_j$ , tutte le operazioni di $T_i$ vengono eseguite prima di qualsiasi operazione $T_j$ o viceversa.

*Definizione*: Un’esecuzione di un insieme di transazioni si dice **serializzabile** se produce lo stesso effetto sulla base di dati di quello ottenibile eseguendo serialmente, in un qualche ordine, le sole transazioni terminate normalmente.

Nella pratica i DBMS implementano tecniche di controllo di concorrenza che garantiscono direttamente la serializzabilità delle transazioni concorrenti. Tali tecniche si dividono in due classi principali:
- Protocolli **pessimistici**/conservativi: tendono a «ritardare» l’esecuzione di transazioni che potrebbero generare conflitti, e quindi anomalie, rispetto alla transazione corrente. Cercano quindi di prevenire.
- Protocolli **ottimistici**, che permettono l’esecuzione sovrapposta e non sincronizzata di transazioni ed effettuano un controllo sui possibili conflitti generati solo a valle del commit.

**Controllo concorrenza ottimistica**
Ogni transazione effettua «liberamente» le proprie operazioni sugli oggetti della base di dati secondo l’ordine temporale con cui le operazioni stesse sono generate. 

Al commit, viene effettuato un controllo per stabilire se sono stati riscontrarti eventuali conflitti, e nel caso, viene effettuato il rollback delle azioni delle transazioni e la relativa riesecuzione. In generale, un protocollo di controllo di concorrenza ottimistico è basato su 3 fasi:
- **Fase di lettura**: ogni transazione legge i valori degli oggetti della BD su cui deve operare e li memorizza in variabili (copie) locali dove sono effettuati eventuali aggiornamenti.
- **Fase di validazione**: vengono effettuati dei controlli sulla serializzabilità nel caso che gli aggiornamenti locali delle transazioni dovessero essere propagati sulla base di dati.
- **Fase di scrittura**: gli aggiornamenti delle transazioni che hanno superato la fase di validazione sono propagati definitivamente sugli oggetti della BD.

Nella pratica i DBMS implementano tecniche di controllo di concorrenza che garantiscono direttamente la serializzabilità delle transazioni concorrenti. Tali tecniche si dividono in due classi principali:
- Metodi basati su lock
- Metodi basati su timestamp

### Implementazione con lock
I DMBS commerciali usano il meccanismo dei lock, per poter effettuare una qualsiasi operazioni di lettura/scrittura su una risorsa (tabella o valore di una cella), è necessario aver precedentemente acquisito il controllo (lock) sulla risorsa stessa.
- **Lock in lettura** (accesso condiviso)
- **Lock in scrittura** (mutua esclusione)

I DBMS per evitare anomalie nelle transazione concorrenti usano diverse tecniche. Una delle più comuni è basata su lock.

*Definizione*: Il **lock** è un meccanismo che blocca l'accesso ai dati ai quali una transazione accede ad altre transazioni.
- lock a livello di riga, tabella, pagina (multi granularità)
- lock in operazioni di scrittura (mutua esclusione) /lettura (accesso condiviso) (multimodale)

In generale, quando una risorsa è bloccata, le transazioni che ne richiedono l'accesso vengono in genere messe in coda • quindi devono aspettare (che il lock sia rimosso).
In sostanza, questo è un meccanismo efficace, ma influisce sulle prestazioni.

Su ogni lock possono essere definite due operazioni:
- **Richiesta** del lock in lettura/scrittura.
- **Rilascio** del lock (unlock) acquisito in precedenza.
![[Screenshot 2023-12-10 at 20.05.01.png | 500]]
### Serializzatore 2PL stretto
Il gestore della concorrenza (serializzatore) dei DBMS ha il compito di stabilire l’ordine secondo il quale vanno eseguite le singole operazioni per rendere serializzabile l’esecuzione di un insieme di transazioni.

*Definizione*: Il protocollo del blocco a due fasi stretto (**Strict Two Phase Locking**) è definito dalle seguenti regole:
1. Ogni transazione, prima di effettuare un’operazione acquisisce il blocco corrispondente (chiede il lock)
2. Transazioni diverse non ottengono blocchi in conflitto.

In **Strict Two Phase Lock (2PL)** i lock di una transazione sono rilasciati solo dopo aver effettuato le operazioni di commit/abort.

C'è però un **problema**, i protocolli 2PL possono generare schedule con situazioni di deadlock (stallo).
![[Screenshot 2023-12-10 at 20.07.08.png | 500]]
Per gestire le situazioni di deadlock causate dal gestore della concorrenza, si possono usare tre tecniche:
1. Uso dei **timeout:** ogni operazione di una transazione ha un timeout entro il quale deve essere completata, pena annullamento (abort) della transazione stessa.
	T1 : r_lock(x,4000), r(x), w_lock(y,2000), w(y), commit, unlock(x), unlock(y)
2. **Deadlock avoidance**: prevenire le configurazioni che potrebbero portare ad un deadlock. Questo è possibile con:
	- **Lock/Unlock** di tutte le risorse allo stesso tempo.
	- Utilizzo di **time-stamp** o di **classi di priorità** tra transazioni (problema: può determinare starvation!). starvation: quando una transazione è impossibilitata a proseguire la sua esecuzione per un periodo di tempo indefinito, mentre le altre transazioni del sistema proseguono tranquillamente.
3. **Deadlock detection**: utilizzare algoritmi per identificare eventuali situazioni di deadlock, e prevedere meccanismi di recovery dal deadlock.

	**Grafo delle richieste/risorse** utilizzato per identificare la presenza di cicli (corrispondenti a deadlock). In caso di ciclo, si fa abort delle transazioni coinvolte nel ciclo in modo da eliminare la mutua dipendenza

**Condizione di stallo**
Il problema si può risolvere con tecniche che prevengono queste situazioni (deadlock prevention), oppure con tecniche che rivelano una situazione di stallo e la sbloccano facendo abortire una o più transazioni in attesa (deadlock detection and recovery).

Un metodo alternativo al 2PL per la gestione della concorrenza in un DBMS prevede l’utilizzo dei time-stamp delle transazioni (metodo TS).
- Ad ogni transazione si associa un timestamp che rappresenta il momento di inizio della transazione
- Ogni transazione non può leggere o scrivere un dato scritto da una transazione con timestamp maggiore.
- Ogni transazione non può scrivere su un dato già letto da una transazione con timestamp maggiore.

### Livelli di isolamento/consistenza per transazione
- **Serializable** assicura che:
	- la transazione T legge solo cambiamenti fatti da transazioni concluse (che hanno fatto il commit)
	- nessun valore letto o scritto da T verrà cambiato da altre transazione finché T non è conclusa, se T legge un insieme di valori acceduti secondo qualche condizione di ricerca, l'insieme non viene modificato da altre transazione finché T non è conclusa.
- **Repeatable** assicura che:
	- la transazione T legge solo cambiamenti fatti da transazioni concluse (che hanno fatto il commit)
	- nessun valore letto o scritto da T verrà cambiato da altre transazione finché T non è conclusa.
- **Read committed** assicura che: 
	- la transazione T legge solo cambiamenti fatti da transazioni concluse (che hanno fatto il commit)
	- T non vede nessun cambiamento eventualmente effettuato da transazioni concorrenti non concluse tra i valori letti all'inizio di T
- **Read uncommitted**:
	- a questo livello di isolamento una transazione T può leggere modifiche fatte ad un oggetto da un transazione in esecuzione; ovviamente l'oggetto può essere cambiato mentre T è in esecuzione. Quindi T è soggetta a effetti fantasma.