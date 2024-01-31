Partiamo dalla domanda: cos'è un protocollo?
*Definizione* (**Protocollo**): un protocollo è un insieme di regole che permettono a due entità di comunicare.
![[Screenshot 2024-01-18 at 17.54.27.png | 600]]
**Esempio**. organizzazione del sistema postale
![[Screenshot 2024-01-18 at 17.54.59.png | 600]]
Ci sono una serie di passi. Ad ogni passo viene eseguito un particolare compito su un messaggio, che viene integrato e trasferito ad un altro agente, seguendo specifiche regole di esecuzione. Per ogni strato, contenitore del messaggi ed indirizzo. Il destinatario farà in percorso inverso.
##### Perché stratificare?
Scomposizione dei sistemi complessi:
- La struttura esplicita permette l'identificatore delle relazioni tra gli elementi di un sistema complesso come: modello di riferimento stratificato, suddivisione di funzioni ed attori.
- La modularizzazione facilita la manutenzione e l'aggiornamento del sistema. 
	- Un modulo (o più precisamente livello/strato) svolge un insieme limitato di compiti e nel sistema appare come una black box (input/output). 
	- Ciascun livello offre servizi allo strato superiore 1) implementando azioni all'interno del livello stesso e 2) utilizzando servizi del livello inferiore.
- Separazione tra servizi offerti (interfaccia) e implementazione: il cambiamento dell'implementazione di un servizio in un livello è sostanzialmente trasparente per il resto del sistema. Es: il cambiamento del modulo per l'accettazione delle raccomandate non influisce sul lavoro dell'ufficio smistamento.
##### Come stratificare?
- **Separation of Concern**: Separazione degli interessi e delle responsabilità, fare ciò che compete, delegando ad altri tutto ciò che è delegabileò
- **Information Hiding**: Nascondere tutte le informazioni che non sono indispensabili per il committente per definire compiutamente l'operazione.

**Esempio**. Organizzazione del servizio postale con altra visione.
![[Screenshot 2024-01-18 at 18.56.12.png | 500]]
Ogni strato implementa un servizio:
- Attraverso le sue azioni interne allo strato
- Confida sui servizi forniti dagli strati sottostanti
- Ha uno strato corrispondente e reciproco (entità omologhe svolgono compiti reciproci operando sugli stessi oggetti)
- Percorso del messaggio inverso lato destinazione

**Versione estesa.**
![[Screenshot 2024-01-18 at 18.59.22.png | 600]]
Una o più stazioni intermedie:
- accettano lettere da più mittenti
- le inoltrano versno le destinazioni finali
- N.B. non vengono reimplementate tutte le funzionalità (ulteriore vantaggio del modello stratificato)
##### Come definire gli strati?
Ogni livello logico di astrazione è realizzato in un apposito strato. Un livello viene creato quando si rende necessario un diverso grado di astrazione. Ogni strato svolge una sola e ben definita funziona. 
Il flusso dati attraverso le interfacce si ogni strato deve essere minimizzato. Il numero degli strati deve essere minimizzato, compatibilmente con la loro complessità:  numero sufficientemente alto per garantire che nessun livello sia troppo complesso e contenga troppe funzioni, ma anche sufficientemente basso per non rendere troppo onerosa l'integrazione e l'architettura poco flessibile.

## OSI RM (Open Systems Interconnection)
Questo è il modello di riferimento che regola le comunicazioni di rete
#### Sistemi chiusi
Le prime reti di calcolatori nascono come sistemi chiusi dove tutti i componenti della rete devono essere dello stesso costruttore quindi si avevano delle reti specializzare per specifici servizi.

Questo però portava ad un **problema di interoperabilità**, infatti gli apparate non riescono ad interpretare i segnali degli altri in altre reti, di conseguenze i programmi applicativi non riescono ad operare in ambiente distribuito.

#### Sistemi aperti
L'**obiettivo** è quello di realizzare una rete di calcolatori in cui qualsiasi terminale comunica con un qualsiasi fortinore di servizi mediante qualsiasi rete.
Per realizzare un sistema aperto è necessario stabilire delle regole comuni, quindi sono necessari degli standard.

Un seti di protocolli si dice **aperto** se:
- I dettagli del protocollo sono disponibili pubblicamente
- I cambiamenti sono gestiti da un'organizzazione la cui partecipazione è aperta al pubblico.
Un sistema che implementa protocolli aperti è un **sistema aperto**.
L'international Organization for Standards (ISO) ha specificato uno standard per l'interconnessione di sistemi aperti.
- Modello di riferimento Open System Interconnection (OSI)
- OSI ha molto influenzato il modo di pensare ai protocolli stratificati.

# Modello ISO/OSI
Il modello ISO/OSI prevede di dividere le funzionalità del protocollo di telecomunicazione in strati o layers ognuno dei quali svolge una parte piccola e indipendente dalle altre allo scopo di permettere una realizzazione o revisione delle singole funzionalità senza dover toccare le altre o anche di permettere una compatibilità a livelli diversi tra diverse implementazioni.

La comunicazione tra i vari livelli è assicurata da chiamate standard; **ogni livello è tenuto a rispondere in maniera corretta alle chiamate che gli competono e che verranno generate dai due livelli ad esso adiacenti** (superiore e inferiore).

La modalità con cui le funzioni competenti ad un livello vengono svolte non è visibile dall'esterno che ne è così svincolato.
![[Screenshot 2024-01-18 at 19.58.25.png | 300]]
- Uno strato fornisce servizi allo strato superiore e riceve servizi dallo strato inferiore.
- La comunicazione tra due strati avviene attraverso un'interfaccia.
- Lo strato n-esimo di una entità comunica con lo strato n-esimo di un'altra entità secondo un protocollo assegnato.

*Definizione* (**Strato**): È un modulo interamente definito attraverso i servizi, protocolli e le interfacce che lo caratterizzano. (Nota: è spesso indacto con il nome di LIVELLO)

*Definizione* (**Servizio**): Servizi che uno strato fornisce ad uno strato soprastante attraverso primitive di servizio (es. CONNECT.request)

*Definizione* (**Interfaccia**): Insieme di regole che gonvernano il formato ed il significato delle unità di dati (es. messaggi, sementi o pacchetti) che vengono scambiati **tra due strati adiacenti della stessa entità**.

*Definizione* (**Protocollo**): Insieme di regole che:
- Permettono a **due entità omologhe (stesso strato)** uno scambio efficace ed efficiente delle informazioni.
- Definiscono il formato e l'ordine dei messaggi inviti e ricevuti tra **entità omologhe** della rete e le azioni che vengono fatte per la trasmissione e ricezione dei messaggi.
- **Efficace**: Un sistema che riesce a raggiungere lo scopo prefissato con la maggior frequenza possibile.
- **Efficiente**: Un sistema che riesce a raggiungere lo scopo prefissato con il minor sforzo possibile.
![[Screenshot 2024-01-18 at 20.05.20.png | 600]]
**Cosa specificare in un protocollo?**
- La sintassi di un messaggio.
- La semantica del messaggio.
- Le azioni da intraprendere dopo la ricezione di un msg.

#### Pila di Protocolli ("Protocol stack")
![[Screenshot 2024-01-18 at 20.06.25.png]]
#### Gerarchia di strati ("layer")
![[Screenshot 2024-01-18 at 20.07.24.png || 600]]
- **Livello fisico**: 
	- Comprende tutte le funzioni (procedure meccaniche ed elettroniche) che permettono una connessione a livello fisico. 
	- Si occupa della trasmissione dei bit attraverso il mezzo trasmissivo e delle caratteristiche di cavi e connettori.
- **Livello di collegamento**: 
	- Definisce le regole per inviare e ricevere informazioni tra due sistemi in comunicazione. 
	- Permette il trasferimento affidabile di ddati attraverso il livello fisico. Si occupa di formare i dati da inviare attraverso il livello fisico. 
	- Si occupa anche di formare i dati da inviare attraverso il livello fisico incapsulando i dati in un pacchetto provvisto di header (intestazione) e tail (code), chiamato frame.
- **Strato di rete**: 
	- Deve far giungere i “pacchetti” a destinazione. 
	- Si occupa dell’istradamento (“routing”) dei pacchetti cioè di determinare la sequenza di collegamenti punto-punto necessari per trasmettere un pacchetto da un nodo generico della rete a un altro.
![[Screenshot 2024-01-18 at 20.11.11.png | 350]]
- **Strato di trasporto**: 
	- Questo strato fornisce un servizio di trasferimento dati end-to-end.
	- Si occupa di instaurare, mantenere terminare una connessione.
	- Può offrire funzionalità per frammentare e riassemblare i dati, rilevare e correggere gli errori, controllare il flusso dei dati.
- **Strato di sessione**: Assembla il dialogo tra nodi in unità logiche (sessione).
- **Strato di presentazione**: Adatta la sintassi dei dati di ciascuna applicazione alla sintassi richiesta dalla sessione
- **Strato di applicazione**: Protocolli a supporto di applicazioni distribuite.

#### Collegamento tra end-systems
![[Screenshot 2024-01-18 at 20.13.32.png | 600]]
##### Modalità di servizio
- **Connection-oriented**: Associare logica tra sue o più sistemi al fine di trasferire dati. Gestione della connessione: instaurazione della connessione, trasferimenti dei dati, chiusura della connessione.
- **Connection-less**: i dati vengono transferiti senza stabilire una connessione.

##### Flusso dell'informazione
Per la rete, l'informazione ha origine al livello applicativo. L'informazione discende i vari livelli fino alla trasmissione sul canale fisico. 
Ogni livello aggiunge all'informazione del livello superiore una propria sezione informatica (o più di una), header che contiene informazioni riguardanti esclusivamente quel livello. Per i dati ricevuti si segue il cammino inverso.

Processo di incapsulamento delle informazioni, ogni livello esegue una operazione di incapsulamento su dati già incapsulati dal livello precedente, è un processo reversibile, infatti la definizione dell'incapsulamento è tale da garantire la possibilità di estrarre i dati precedentemente incapsulati.

##### Incapsulamento
- **Header**: qualificazione del pacchetto dati per questo livello.
- **Data**: payload proveniente dal livello superiore.
- **Trailer**: generalemnte usato in funzione di trattamento dell'errore (rivelazione, correzione).
![[Screenshot 2024-01-18 at 20.29.28.png]]
**Incapsulamento dei dati**
![[Screenshot 2024-01-18 at 20.29.45.png]]

#### Stack protocollare TCP/IP
TCP/IP è una famiglia di protocolli attualmente utilizzata in internet. Si tratta di una gerarchia di protocolli, ciascuno dei quali fornisce funzionalità specifiche. 

Il termine gerarchia significa che ciscuno protocollo di livello superiore è supportato dai servizi forniti dai protocolli di livello inferiore.

Definita in origine in termini di quattro livelli software soprastanti a un livello hardware, la pila TCP/IP. è oggi intesa come composta di cinque livelli.
- **Applicazione**: supporta le applicazioni di rete, collegamento logico end-to-end: scambio di messaggi tra due processi (ftp, smtp, http)
- **Trasporto**: trasferimento dati end-to-end, da un host sorgente all'host destinatario, (tcp, udp).
- **Rete**: instradamento dei datagrammi dalla sorgente all destinazione (ip, ICMP).
- **Link**: trasferimento dati in frame attraverso il collegamento tra elementi di rete vicini (ppp, ethernet, ... qualunque cosa).
- **Fisico**: trasferimenti dei bit di un frame sul mezzo trasmissivo. 
![[Screenshot 2024-01-18 at 23.36.33.png | 150]]
##### Vista logica
![[Screenshot 2024-01-18 at 23.37.25.png | 600]]

##### Vista fisica
![[Screenshot 2024-01-18 at 23.38.01.png | 600]]

##### Incapsulamento
![[Screenshot 2024-01-18 at 23.38.52.png | 600]]
![[Screenshot 2024-01-18 at 23.39.52.png | 600]]

##### ISO/OSI vs TCP/IP
|  | ISO/OSI | TCP/IP |
| ---- | ---- | ---- |
| Pro | - generale<br>- definizione di servizio, interfaccia e protocollo | - Standard de facto<br>- /-implementation driven |
| Contro | - Poco efficiente, alcuni livelli poco utili e chiari<br>- Alcune funzioni sono presenti in più livelli<br>- Standard difficili<br>- Telco-oriented<br>- I protocolli TCP/IP già in uso non si collocano perfettamente | - Specifiche non astratte e rigorose<br>- Modello non generale<br>- Oltre e TCP/IP, presenza di protocolli minori (per problemi ad -hoc), difficili da rimpiazzare |

