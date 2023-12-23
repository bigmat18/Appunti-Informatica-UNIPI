Una base di dati è un insieme organizzato di dati utilizzati per il support allo svolgimento di attività (di un ente, azienda, ufficio, persona).

Esempio:![[Screenshot 2023-11-19 at 21.00.50.png]]

Le basi di dati hanno quinidi un ruolo nel **sistema informativo e nell'organizzazione di un'azienda**. 

*Definizione*: Un sistema informativo di un'organizzazione è una combinazione di risorse, umane e materiali, e di procedure organizzate per: la raccolta, l'archiviazione, l'elaborazione e lo scambio delle informazioni necessarie alle attività:
- operative (informazioni di servizio)
- di programmazione e controllo (informazioni di gestione)
- di pianificazione strategica (informazioni di governo)

![[Screenshot 2023-11-19 at 21.04.14.png]]

Il **sistema informativo automatizzato** è quella parte del sistema informtivo in cui le informaizoni sono raccole, elaborate, archivivate e scambiate usando un sistema informatico.

Il **sistema informatico** è l'insieme delle teconologe informatiche e della comunicazione a support delle attività di organizzazione.

Terminologia:
- sistema informativo = sistema informativo automatizzato
- sistema infomrativo automatizzato = sistema informatico

## Componenti di un sistema informatico
![[Screenshot 2023-11-19 at 21.07.23.png]]

Classificazione sistemi informatici
![[Screenshot 2023-11-19 at 21.07.58.png]]

### Sistemi informatici operativi
I dati sono organizzati in DB. Le applicazioni si usano per svolgere le classiche attività strutturate e ripetitive dell'azienda nelle aree amministrativa e finanziaria, vendite, produzione, risorse umane ecc.

![[Screenshot 2023-11-19 at 21.09.33.png]]

Le caratteristiche delle basi di dati sono garantite da un sistema per la gestione di basi di dati (Data Base Management System, DBMS), che ha il controllo dei dati e li rende accessibili agli utenti autorizzati.

Sistemi di transizioni (OLTP):
Uno principale dei DBMS, tradizionale elaborazioni di transizioni, che realizzano i processi operativi per il funzionamento di organizzazioni: operazioni predefinite e relativamente semplici, ogni operazione coinvolge "Pochi" dati, dati di dettaglio, aggiornati.

### Sistemi informatici direzionali
I dati sono organizzati in **Data Warehouse (DW)** e gestiti da un opportuno sistema. Le applicazioni, dette di **Business intelligence**, sono strumenti di supporto ai processi di controllo delle prestazioni aziendali e di decisione manageriale.

![[Screenshot 2023-11-19 at 21.22.10.png]]

Uno degli usi principali dei dati warehouse è analisi di essi per il supporto alle decisioni come: operazioni complesse e non-ripetitive, ogni operazione può coinvolgere molti dati, dati aggregati, storici, anche non attualissimi.
### Differenza tra OLTP e OLAP![[Screenshot 2023-11-19 at 21.39.33.png]]

### Analisi dei dati: requisiti
Dati **aggregati**: non interessa un dato, ma la somma, la media, il minimo, il massimo di una misura. 

Presentazione **multidimensionale**: interessa incrociare le informazioni, per analizzarle da punti di vista diversi e valutare i risultati del business per intervenire sui problemi critici o per cogliere nuove opportunità. 

Analisi a **diversi livelli di dettaglio**: per es. una volta scoperto un calo delle vendite in un determinato periodo in una regione specifica, si passa ad un'analisi dettagliata nell'area di interesse per cercare di scoprire le cause (dimensioni con gerarchie).

### Big data
Big Data è un termine ampio, riferito a situazioni in cui l’approccio ‘schema-first’ tipico di DB o DW risulta troppo restrittivo o troppo lento.
Le tre V: Volume, Varietà e Velocità

## DBMS
*Definizione:* Un DBMS è un sistema centralizzato o distribuito che offre opportuni linguaggi per:
- definire lo schema di una basi di dati (lo schema va definito prima di creare dati).
- scegliere le strutture dati per la memorizzazione dei dati.
- memorizzare i dati rispettando i vincoli definiti nello schema. 
- recuperare e modificare i dati interattivamente (linguaggio di interrogazione o query language) o da programmi.

### Architettura DBMS centralizzati
![[Screenshot 2023-11-19 at 21.44.03.png]]

Una base di dati è una raccolta di dati permanenti suddivisi in due categorie: i metadati descrivono fatti sullo schema dei dati, utenti autorizzati, applicazioni, parametri quantitativi sui dati, ecc. 
- I **metadati** sono descritti da uno schema usando il modello dei dati adottato dal DBMS e sono interrogabili con le stesse modalità previste per i dati.
- i **dati**: le rappresentazioni di certi fatti conformi alle definizioni dello schema, con le seguenti caratteristiche.

Una delle caratteristiche dei dati gestiti dai DBMS è che:
- Sono organizzati in insiemi strutturati e omogenei, fra i quali sono definite delle relazioni. La struttura dei dati e le relazioni sono descritte nello schema usando i meccanismi di astrazione del modello dei dati del DBMS.
- Sono molti, in assoluto e rispetto ai metadati, e non possono essere gestiti in memoria temporanea.
- Sono accessibili mediante transazioni, unità di lavoro atomiche che non possono avere effetti parziali.
- Sono protetti sia da accesso da parte di utenti non autorizzati, sia da corruzione dovuta a malfunzionamenti hardware e software.
- Sono utilizzabili contemporaneamente da utenti diversi.

**Esempio di sessione con un DBMS relazionale.**

Il modello relazionale dei dati è il più diffuso fra i DBMS commerciali. Il meccanismo di astrazione fondamentale è la relazione (tabella), sostanzialmente un insieme di record con campi elementari; lo schema di una relazione ne definisce il nome e descrive la struttura dei possibili elementi della relazione (insieme di attributi con il loro tipo). 

Definizione base di dati:
```sql
create database EsempioEsami
```

Definizione schema:
```sql
create table Esami (Materia char(5), Candidato char(8), Voto int, Lode char(1),Data char(6))
```

Inserzione dati:
```sql
insert into Esami values ('BDSI1','080709',30, 'S', 070900)
```

Interrogazione:
```sql
select Candidato 
from Esami 
where Materia = "BDSI1" and Voto = 30
```

Inoltre: accesso ai dati da programma, interrogazioni con interfaccia grafica, direttive per definire le strutture fisiche…

## Funzionalità del DMBS
- Linguaggio per la definizione della base di dati.
- Linguaggi per l’uso dei dati.
- Meccanismi per il controllo dei dati.
- Strumenti per il responsabile della base di dati.
- Strumenti per lo sviluppo delle applicazioni.

È utile distinguere tre diversi livelli di descrizione dei dati (**schemi**)
![[Screenshot 2023-11-20 at 15.32.10.png]]

### Livello logico
*Definizione*: descrive la struttura degli insiemi di dati e delle relazioni fra loro, secondo un certo modello dei dati, senza nessun riferimento alla loro organizzazione fisica nella memoria permanente (Schema logico).

**Esempio**:
Studenti(Matricola char(8), Nome char(20), login char(8), AnnoNascita int, Reddito real) Corsi(IdeC char(8), Titolo char(20), Credito int) 
Esami(Matricola char(8), IdeC char(8), Voto int)

### Livello fisico
*Definizione*: descrive come vanno organizzati fisicamente i dati nelle memorie permanenti e quali strutture dati ausiliarie prevedere per facilitarne l’uso (Schema fisico o interno).

**Esempio**:
Relazioni Studenti e Esami organizzate in modo seriale, Corsi organizzata sequenziale con indice 
Indice su Matricola, (Matricola, IdeC)

### Livello vista logica
*Definizione*: descrive come deve apparire la struttura della base di dati ad una certa applicazione (Schema esterno o vista).

**Esempio** di schema estreno:
InfCorsi (IdeC char(8), Titolo char(20), NumEsami int)

**Esempio** banca:
Nell’organizzazione di una banca, lo schema logico conterrà tutte le tabelle e i dati relativi ai conti correnti, ma anche al personale. Lo schema logico conserva tutte le informazioni della banca. 
Nello schema esterno, ogni correntista potrà accedere solo ad alcune informazioni che sono per lui di interesse: quelle relative al proprio conto corrente.

L’approccio con tre livelli di descrizione dei dati è stato proposto come un modo per garantire le proprietà di indipendenza logica e fisica dei dati, che sono fra gli obiettivi più importanti dei DBMS.
- **Indipendenza logica**: i programmi applicativi non devono essere modificati in seguito a modifiche dello schema logico.
- **Indipendenza fisica**: i programmi applicativi non devono essere modificati in seguito a modifiche dell’organizzazione fisica dei dati.

Un DBMS deve prevedere più modalità d’uso per soddisfare le esigenze delle diverse categorie di utenti che possono accedere alla base di dati (dati e catalogo):
- Un'interfaccia grafica per accedere ai dati.
- Un linguaggio di interrogazione per gli utenti non programmatori
- Un linguaggio di programmazione per gi utenti che sviluppano applicazioni: integrazione DDL e DML nel linguaggio ospite: procedure predefinite, estensione del compilatore, precompilazione. Comunicazione tra linguaggi e DBMS.
- Un linugaggio per lo sviluppo di interfacce per le applicazioni.

Nel linguaggi di interrogazione di basi di dati distinguiamo tra:
- **Data Manipulation Language (DML)**: per l'interggoazione e l'aggiornamento di (istanze di) basi di dati. 
```sql 
select insegnamento
from orario
where docente = "Mario rossi"
```
- **Data Definition Language (DDL)**: per la definizione di schemi (logici, esterni, fisici) ed altre operazioni generali.
```sql 
create table orario (
	insegnamento char(20),
	docente CHAR(20), 
	aula CHAR(4), 
	ora CHAR(5)
)
```

Tra le altre funzionalità dei DMBS abbiamo:
- **Strumenti per l'amministratore** della base di dati come:
	- Un linguaggio per la definizione e la modifica degli schemi logico, interno ed sterno.
	- Strumenti per il controllo e messa a punto del funzionamento del sistema.
	- Strumenti per stabilite i diritti di accesso ai dati e per ripristinare la base di dati in caso di malfunzionamenti.
- **Strumenti per lo sviluppo** delle applicazioni

Fra i linguaggi per le basi di dati abbiamo: linguaggi testuali (SQL), comandi immessi in un linguaggio ospite (C, Cobol, etc.), commandi immersi in un linguaggio ad hoc (PL/SQL), con anche altre funzionalità, interfacce amichevoli.

**Esempio** PL/SQL:
```sql
declare Stip number; 
begin 
	select Stipendio into Stip from Impiegato where Matricola = '575488'
	for update of Stipendio; 
		if Stip > 30 then 
			update Impiegato set Stipendio = Stipendio * 1.1 where Matricola = '575488'; 
		else 
			update Impiegato set Stipendio = Stipendio * 1.15 where Matricola = '575488'; 
		end if; 
		commit; 
	exception when no_data_found then 
	insert into Errori values('Non esiste la matricola specificata',sysdate); 
end;
```

![[Screenshot 2023-11-20 at 17.10.07.png]]

### Meccanismi per il controllo dei dati nei DBMS
Una caratteristica molto importante dei DBMS è il tipo di meccanismi offerti per garantire le seguenti proprietà di una base di dati:
- **Integrità**: mantenimento delle proprietà specificate in modo dichiarativo nello schema (vincoli d’integrità).
- **Sicurezza**: protezione dei dati da usi non autorizzati.
- **Affidabilità**: protezione dei dati da malfunzionamenti hardware o software (fallimenti di transazione, di sistema e disastri) e da interferenze indesiderate dovute all’accesso concorrente ai dati da parte di più utenti.
### Le transizioni
*Definizione*: Una transazione è una sequenza di azioni di lettura e scrittura in memoria permanente e di elaborazioni di dati in memoria temporanea, con le seguenti proprietà:
- **Atomocità**: Le transazioni che terminano prematuramente (aborted transactions) sono trattate dal sistema come se non fossero mai iniziate; pertanto eventuali loro effetti sulla base di dati sono annullati.
- **Persistenza**: Le modifiche sulla base di dati di una transazione terminata normalmente sono permanenti, cioè non sono alterabili da eventuali malfunzionamenti
- **Serializzabilità**: Nel caso di esecuzioni concorrenti di più transazioni, l’effetto complessivo è quello di una esecuzione seriale.

**Recap sui DBMS**
Un DataBase Management System (DBMS) è un sistema (prodotto software) in grado di gestire collezioni di dati che siano (anche):
- **Grandi**
- **Persistenti**
- **Condivise**
garantendo **affidabilità** (resistenza a malfunzionamenti hardware e software-recovery) e **privatezza** (con una disciplina e un controllo degli accessi). Come ogni prodotto informatico, un DBMS deve essere **efficiente** (utilizzando al meglio le risorse di spazio e tempo del sistema) ed **efficace** (rendendo produttive le attività dei suoi utilizzatori).