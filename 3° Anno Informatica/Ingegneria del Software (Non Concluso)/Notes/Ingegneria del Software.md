# Diagrammi UML

### [[Diagrammi casi d'uso]]
### [[Diagrammi delle classi]]
### [[Diagramma di Macchina a stati]]
### [[Diagramma sequenziale]]

# Progettazione: architetture del software
Costituisce la fase ponte fra la specifica e la codifica, è la fase in cui si passa da “che cosa” deve essere fatto a “come” deve essere fato. Il suo prodotto si chiama architettura (o progetto) del sw.
Si hanno durante la progettazione diversi livelli di estrazione:
- Progettazione di alto livello (o architettura): Scopo è la scomposizione di un sistema in sottosistemi quindi identificazione e specifica delle parti del sistema e delle loro inter-connessioni
- Progettazione di dettaglio: decisione su come la specifica di ogni parte sarà realizzata

La dedizione di architettura software: l’architettura di un sistema software (in breve architettura software) è la strutta del sistema costituita dalle parti del sistema, dalle relazioni tra le parti, dalle loro proprietà visibili.

In altre parole l’architettura:
- definisce la struttura del sistema sw.
- specifica le comunicazioni tra componenti.
- considera aspetti non funzionali.
- è un’astrazione.
- è un artefatto complesso

## Le viste
Ci sono 3 astrazioni interessanti, che sono 3 uni di vista simultanei sul sistema sw. Vista comportamentale, vista strutturale e vista logistica.
### [[Vista comportamentale]]
Aka component-and-connector, aka C&C La vista C&C descrive un sistema software come composizione di componenti software, specifica i componenti con le loro interfacce, descrive le caratteristiche dei connettori, descrivere la struttura del sistema in esecuzione, flusso dei dati, dinamica, parallelismo, replicazioni, ... 

È utile per:  analisi delle caratteristiche di qualità a tempo d’esecuzione come prestazioni, affidabilità, disponibilità, sicurezza. Utile anche per documentare lo stile dell’architettura
### [[Viste strutturale]]
Descrive la struttura del sistema come insieme di unità di realizzazione (codice) essi: Classi, packages… A cosa serve? Analizzare dipendenze tra packages, progettare test di unità e di integrazione, valutare la portabilità.
### [[Vista logistica]]
Aka vista di deployment. Descrive l’allocazione del sw su ambienti di esecuzione. A cosa serve? Permette di valutare prestazioni e affidabilità.

![[Screenshot 2023-10-25 at 10.32.59.png | 400]]

# Tecniche di progettazione: Design Patters
Esistono una serie di regole pratiche che il progettista può seguire per costruire qualcosa. Queste regole pratiche sono i design patters, e sono definiti grazie a anni di esperienza da parte di terze persone. Si applicano in fase di design.

![[Screenshot 2023-11-15 at 12.47.22.png]]

### GOF design patterns
Sono 23 design patters suddivisi in base al loro scopo:
- **Creazionali:** propongono soluzioni per creare oggetti
- **Comportamentali:** propongono soluzioni per gestire il modo in cui vengono suddivise le responsabilità delle classi e degli oggetti.
- **Strutturali:** propongono soluzioni per la composizione strutturale di classi e oggetti.

Perché i pattern nel software? “Progettare software OO è difficile e progettare software OO riutilizzabile è ancora più difficile” cit. Erich Gamma.
I progettisti esperti riutilizzano le soluzioni che hanno funzionato in passato, così i sistemi OO ben strutturati hanno modelli ricorrenti di classi e oggetti. La conoscenza degli schemi che hanno funzionato in passato consente al progettista di essere più produttivo e ai progetti risultanti di essere più flessibili e riutilizzabili.

Ci sono vari libelli di astrazioni per i design pattern. Si passa da design pattern complessi per intere applicazioni o sottosistemi. Si passa poi a soluzioni per problemi generali in un determinato contesto, fino ad arrivare a design class più semplici come linked List, hashtag table ecc..

Nell’architettura - progettazione di dettaglio-codice differenziamo i patterns dagli stili architetturali che sono pipes and filters, publish-subscribe, model-view-controller mentre i design patterns sono per la progettazione e raffinamento dei singoli componenti. 

Possiamo poi definire gli **Idiomi** che sono pattern di basso livello specifici di un linguaggio di programmazione.
### GOF patterns tramplate (come viene proposto)
1. Nome del pattern e classificazione
2. Scopo: piccolo riassunto di cosa il pattern va a fare
3. Conosciuto anche come: altri nomi con cui viene chiamato il pattern.
4. Motivazione: illustrazione di uno scenario dove il modello potrebbe essere utile.
5. Applicabilità: Situazione in cui è possibile utilizzare il modello.
6. Struttura: rappresentazione grafica del pattern.
7. Partecipanti: le classi e gli oggetti che partecipanti al pattern
8. Collaboratori: come interagiscono i partecipanti per svolgere le loro responsabilità?
9. Conseguenze: Quali sono i pro ed i contro dell’utilizzo del modello?
10. Implementazione: Suggerimenti e tecniche per implementare il modello.
11. Un sample del codice: un frammento di codice esempio dell’implementazione.
12. Dove viene usato: Esempi di veri sistemi che usano questo pattern
13. Pattern collegati: Altri pattern collegati a questo.
### Notazione usata da GOF
Il libro GoF usa la moderazione ad oggetti per la notazioni dei diagrammi di classi e oggetti

![[Screenshot 2023-11-15 at 14.36.44.png | 400]]

![[Screenshot 2023-12-07 at 13.03.07.png | 400]]

![[Screenshot 2023-11-15 at 14.37.25.png | 400]]

![[Screenshot 2023-11-15 at 14.37.39.png ]]

![[Screenshot 2023-11-15 at 14.37.52.png | 500]]

Classi e istanze (metadata & data)
![[Screenshot 2023-11-15 at 14.38.03.png | 500]]
## [[Factory]]

## [[Singleton]]

## [[Decorator]]

## [[Adapter]]

## [[Proxy]]

## Progettare fase di verifica
I progettisti della fase di verifica devono:
- scegliere e programmare la giusta combinazione di tecniche per raggiungere il livello richiesto di qualità entro i limiti di costo.
- Progettare una soluzione specifica che si adatta: al problema, ai requisiti e all'ambiente di sviluppo.
Tutto questo senza poter contare su "ricette" fisse.

**5 domande sa usare come guida**
1. <u>Quando iniziare verifica e convalida? Quando sono completo ?</u> 
	Il testing non è una fase finale dello sviluppo software. L'esecuzione dei test è solo una piccola parte del processo di verifica e convalida.
	
	V&V iniziano non appena decidiamo di creare un prodotto software. V&V durano molto oltre la consegna dei prodotti, di solito per tutto il tempo in cui software è in uso, per far fronte alle evoluzioni e agli adattamenti alle nuove condizione. 
	
	Quando iniziare quindi verifica e convalida?
	**Opzione 1**. Dallo studio di fattibilità di un nuovo progetto, essendo che deve tener conto delle qualità richieste e dell'impatto sul costo complessivo.
	
	In questa fase, le attività correlate alla qualità comprendono:
	- analisi del rischio.
	- definizione delle misure necessarie per valutare e controllare la qualità in ogni stadio di sviluppo.
	- valutazione dell'impatto di nuove funzionalità e nuovi requisiti di qualità.
	- valutazione economica delle attività di controllo della qualità: costi e tempi di sviluppo.
	
	**Opzione 2**. Dopo il rilascio. Le attività di manutenzione comprendono:
	- analisi delle modifiche ed estensioni.
	- generazione di nuove suite di test per le funzionalità aggiuntive.
	- riesecuzione dei test per verificare la non regressione delle funzionalità del software dopo le modifiche e le estensioni.
	- rilevamento e analisi dei guasti.

2. <u>Quali tecniche applicare ?</u>
	Nessuna singola tecnica di analisi e testing (A & T) è sufficiente per tutti gli scopi. 
	Le principali ragioni per combinare diverse tecniche sono: 
	- Efficacia per diverse classi di difetti: analisi statica invece di test per le race conditions.
	- Applicabilità in diverse fasi del processo di sviluppo, per esempio: ispezione per la convalida dei requisiti iniziali. 
	- Differenze negli scopi. Esempio: test statistico per misurare l'affidabilità.
	- Compromessi in termini di costo e affidabilità: usare tecniche costose solo per requisiti di sicurezza.
	
	![[Screenshot 2023-11-29 at 13.07.43.png]]
	
3. <u>Come possiamo valutare se un prodotto è pronto per essere rilasciato?</u>
	Alcune misure di **dependability**:
	- La **disponibilità** misura la qualità di un sistema in termini di tempo di esecuzione rispetto al tempo in cui il sistema è giù.
	- Il **tempo medio tra i guasti** (MTBF) misura la qualità di un sistema in termini di tempo tra un guasto ed il successivo.
	- **L'affidabilità** indica la percentuale di operazioni che terminano con successo.
	- 
	Per valutare se un prodotto è pronto per il rilascio dobbiamo definire bene le misura.
	
	**Esempio**. Applicazione e-shop realizzata con 100 operazioni. Il software funziona correttamente fino al punto in cui viene indicata una carta di credito: nel 50% dei casi viene addebitato l'importo sbagliato.

	Qual è l'affidabilità del sistema? Se contiamo la percentuale di operazioni corrette, solo una operazione su 100 fallisce: il sistema è affidabile al 99%. Se contiamo le sessioni, solo il 50% affidabile.
	
	**Alfa test**: test eseguiti dagli sviluppatori o dagli utenti in ambiente controllato, osservati dall'organizzazione dello sviluppo.
	**Beta test**: test eseguiti da utenti reali nel loro ambiente, eseguendo attività reali senza interferenze o monitoraggio ravvicinato.
	
4. <u>Come possiamo controllare la qualità delle release successive?</u>
	Attività dopo la consegna:
	- test e analisi del codice nuovo e modificato.
	- riesecuzione dei test di sistema.
	- memorizzazione di tutti i bug trovati.
	- test di regressione. Quasi automatico.
	- distinzione tra "major" e "minor" revisions: 2.0 vs 1.4, 1.5 vs 1.4.

5. <u>Come può essere migliorato il processo di sviluppo?</u>
	Si incontrano gli stessi difetti progetto dopo progetto:
	- identificare e rimuovere i punti deboli nel processo di sviluppo. Per esempio cattive pratiche di programmazione.
	- identificare e rimuovere i punti deboli del test e dell'analisi che consentono loro di non essere individuati

**Verifica vs Convalida**
*Definizione*: La **convalida** (aka validazione) risponde alla domanda: stiamo costruendo il sistema che serve all'utente? 

*Definizione*: La **verifica** risponde alla domanda: Stiamo costruendo un sistema che rispetta le specifiche?

![[Screenshot 2023-11-29 at 13.24.47.png]]

![[Screenshot 2023-11-29 at 13.24.59.png]]

**Terminologia IEEE: malfunzionamento**
Con un **Malfunzionamento** Il sistema software a tempo di esecuzione non si comporta secondo le specifiche. Es. output non atteso. Un malfunzionamento ha una natura dinamica: può essere osservato solo mediante esecuzione. Causato da un difetto (o più difetti).

**Terminologia IEEE: difetto**
Un **difetto** (o anomalia, bug, fault) è un difetto nel codice (appartiene alla struttura statica del programma), l'atto di correzione dagli difetti è detto debug o bugfixing.

Normalmente causa un malfunzionamento, ma non sempre, in questo caso si dice che il **difetto è latente**, ad esempio, il caso in cui il difetto è contenuto in un cammino che non viene praticamente mai eseguito; un altro caso è rappresentato dalla presenza di più difetti il cui effetto totale è nullo.

**Esempio**
```c
int raddoppia(int x) {
	return x * x;
}```

**Terminologia IEEE: errore**
Un **errore** è la cause di un difetto, può essere causato da un incomprensione umana nel tentativo di comprendere o risolvere un problema, o nell'uso di strumenti.

Per esempio nel metodo raddoppia, se c'è un difetto è errore di editing.

## Limiti teorici e pratici del testing
Il testing è una tecnica di verifica ed è come le altre sottoposta al problema dell'indecibilità.

Una **prova formale di correttezza** corrisponderebbe all’esecuzione del sistema con tutti i possibili input.

**Testing esaustivo**
Fare testing esaustivo vuol dire eseguire e provare ogni possibile input del programma. Esso richiederebbe però:
- un tempo infinito, se gli input sono infiniti (oltre ad esserci in questi casi limiti fisici di memoria).
- un tempo troppo lungo, per domini di input finiti ma molto grandi per un programma che fa la somma di due int ci vorrebbero:
$$2^{32} \times 2^{32} = 2^{64} \approx 10^{21}$$
Test. Ipotizzando 1 nanosecondo per ogni esecuzione:$$10^{21} \times 10^{-9} = 10^{12} \approx 30.000 \:\: anni$$
*Definizione* (**Tesi di Dijkstra**): il test di un programma può rilevare la presenza di difetti, ma non dimostrarne l'assenza.

## Tecniche di verifica: Verifica statica
Verifica che non prevede l'esecuzione del programma.
- Metodi manuali bassati sulla lettura del codice (desk-check), sono i più comunementi usati, più o meno formalmente documentati.
- Metodi formali o Analisi Static supportata da strumenti, model checking, esecuzione simbolia, interpretazione astratta, theorem proving.

Abbiamo due metodi di lettura del codice: **Ispection** e **Walkthrough**.
Sono metodi pratici basati sulla lettura del codice dipendenti dall'esperienza dei verificatori per organizzare le attività di verifica, per documentare l'attività ed i suoi risultati. Sono metodi complementari tra loro.
### [[Ispection]]

### [[Walkthrough]]

### [[Metodi formali]]

## Progettazione delle prove (fase di test)

Si compone in più fasi:
1. Progettazione: input, output atteso, ambiente di esecuzione del test.
2. Esecuzione del codice.
3. Analisi dei risultati. Output ottenuto con l'esecuzione vs output atteso
4. Debugging.

I test vengono fatti a più livelli:
- Test di unità
- Test di integrazione
- Vari tipi di test sul sistema
- Test di accettazione (o collaudo)

**Reperibilità delle prove**
Bisogna poter ripetere una sessione di test in condizione immutate come: ambiente definito (hardware, software), casi di prova definiti (ingressi e comportamenti attesi), procedure definite.

### Caso di prova
Un caso di prova (o test case), è una tripla <input, output, ambiente> (output si intende quello atteso)

### Test obligation (proof obligation)
*Definizione* (**Test obligation**) = una specifica (descrizione) di casi di test che richiede di testare proprietà ritenute importanti.

**Esempio**:
Specifica dei test case: "un input formato da due parole ed un input formato da tre"
I seguenti casi di testo sono 2 tra i tanti casi di test che soddisfano la test obligation: "alpha beta", "Milano pisa Roma".

**Adeguatezza dei casi di test**
Un modo per definire l'adeguatezza di un insieme di casi di test (test suite). Non possiamo dire: se il sistema supera un'adeguato insieme di test allora deve essere corretto, perché la correttezza è indecidibile.

**Criteri pratici di Inadeguatezza**
Criteri che identificano inadeguatezza nei casi di test. Esempi:
- Nella specifica del sistema ho due casi, il casi di test non testano che i due casi siano trattati differentemente.
- Nel codice si sono n istruzioni, i casi di test ne testano $k<n$.

Il fatto che il nostro insieme di test non verifichi un criterio ci suggerisce come modificarlo. Un criterio di adeguatezza = insieme di test obligations.

**Soddisfare un criterio di adeguatezza**
Un criterio di adeguatezza = insieme di test obligations. Un insieme di test soddisfa un criterio di adeguatezza:
1. Tutti i test hanno successo.
2. Ogni test obligation è soddisfatta da almeno un caso di test (nell'insieme di casi di test scelto).

**Esempio**.
Il criterio di adeguatezza della copertura delle istruzione è soddisfatto da un insieme di test S per il programma P se:
1. Ogni istruzione eseguibile in P è esercitata da almeno un test in S,
2. Il risultato dell'esecuzione corrisponde a quello atteso.

**Come definire le test obligations**
- Dalle funzionalità (a scatola chiusa, black box), guardando la specifica del SW basati sulle conoscenza delle funzionalità mirati a evidenziare malfuzionamento relativi a funzionalità.

	**Esempio**. Il metodo che restituisce il valore assoluto di una variabile in input, le test obligations richiede il testare il metodo almeno con un valore positivo e almeno con uno negativo. 

- E dalla struttura (a scatola aperta, white box): guardando il codice  basati sulla conoscenza del codice e mirati a esercitare il codice indipendentemente dalla funzionalità. Per esempio passare da ogni loop almeno una volta.

**Come definire le test obligations**
- dal modello del programma, modelli utilizzati nella specifica o nella progettazione, o derivati dal codice
	**Esempio**. Esercizio di tutte le transazioni nel modello di protocollo di comunicazione
- Da fault ipotetici, cercano defetti ipotizzati (bug comuni), per esempio il check per la gestione del buffer overflow testando con input molto grandi.

## Black-box vs white-box

**Criteri black-box test case** basati solo sulla specifica del metodo: isMCD restituisce true, se mcd è il massimo comune divisore di $a$ e $b$.
```java
public boolean isMCD(int a, int b, int mcd)
```

**White-box test case** bassati sul codice.
```java
public boolean isMCD(int a, int b, int mcd) { 
	if (a<=0 || b<=0) 
		throw new IllegalParameter(); 
	int min = a < b ? a : b;
	if (( a % mcd != 0) | (b % mcd != 0))
		return false;
	for (int i = mcd + 1; i <= min; i++) {
		if( (a % i == 0) && (b % i == 0)) 
			return false;
	}
	return true;
```

## Uno sguardo alle altre fasi del testing
*Definizione* (batteria di prove): un insieme (una sequenza di casi di prova)

*Definizione* (procedure di prova): le procedure (automatiche e non) per eseguire, registrare analizzare e valutare i risultati di una batteria di prove.

La procedura di prova in particolare è composta dai seguenti steps:
- Definizione dell'obiettivo della prova.
- Progettazione della prova, scelta e definizione dei casi di prova (della batteria di prova)
- Realizzazione dell'ambiente di prova, ci sono driver e stub da realizzare, ambienti da controllare, strumenti per la registrazione dei dati da realizzare.
- Esecuzione della prova l'esecuzione può richiedere del tempo.
- Analisi dei risultati, l'esame de risultati alla ricerca di evidenza di malfunzionamento.
- Valutazione della prova.

### Test scaffolding
L'operazione della realizzazione dell'ambiente di prova si chiama test scaffolding, esso è codice aggiuntivo necessario per eseguire un test.

Si chiama scaffolding, per analogia alle strutture temporanee erette attorno ad un edificio durante la costruzione o la manutenzione.

Lo scaffolding può includere:
- **Driver di test**: sostituiscono un programma principale o di chiamata.
- **Stub**: sostituiscono funzionalità chiamate o utilizzate dal software in prova **(mock)**. Se il metodo A usa B che usa C per testare B deve costruire del codice che simula A (driver) e del codice che simula C (stub).
- **Test harness**: sostituiscono parti dell'ambiente di distribuzione (Attenzione: per altri autori harness è sinonimo di scaffolding)
- **Tool per gestire l'esecuzione del test**
- **Tool per registrare i risultati**

## [[Metodi black box ]]

## [[Criteri white-box]]

## [[L'oracolo e individuazione degli output attesi]]
