# Introduzione alle reti

### INTERNET: vista dei componenti

![[Screenshot 2023-10-25 at 11.24.50.png]]

- Internet è una rete di reti. **I protocolli** sono dappertutto, si occupano di invio e recensione di messaggi ess: HTTP, streaming, TCP, IP 4G …
- Esistono degli **internet standard**, infatti ogni rete connessa a internet deve usare l’internet protocolli (IP) e rispettare certe convenzioni su nomi e indirizzi, in questo modo nuove reti si aggiungono facilmente.
- Internet in particolare è composto da miliardi di **dispositivi connessi** o hosts, servers spesso a data centers, pc, smartphone ecc.
- Inoltre utilizza r**eti di accesso o link di comunicazione**, fibra ottica, rame, onde radio, satelliti. 
- Usa anche **dispositivi di interconnessione** come router e switch. 
- **Le reti** invece (che compongono anche esse internet) sono un insieme di host, dispositivi di interconnessione (router), link gestiti da una organizzazione.

### INTERNET: vista delle entità software
- **Infratruttura** che offre servizi alle applicazioni.
- **Interfaccia di programmazione** alle applicazioni distribuite come: “hooks” che permettono alle app mittenti e destinarie di collegarsi e usare il servizio di trasporto di Internet, opzioni di servizio tipo servizio Senza connessione o servizio orientato alla connessione. Analogia: servizio postale
- **Applicazioni**: elaborano e si scambino informazioni.
- **Protocolli**: regolano la trasmissione e la ricezione di messaggi.
- **Interfacce**: definite in seguito, solo le “membrane” che separano gli strati della pila protocollare.
- **Standard internet e del Web.**

![[Screenshot 2023-10-25 at 11.35.19.png]]

Ora alcuni definizioni importati:
- RETE: un’interconnessioni di dispositivi in grado di scambiarsi informazioni, quali sistemi terminali, router, switch e modem.
- I sistemi terminali sono chiamati host: macchina di proprietà degli utenti finali e dedicata ad eseguire applicazioni, quale un computer, un portatile, un cellulare o un tablet. Server, tipicamente un computer con elevate prestazioni destinato a eseguire programmi che forniscono servizio a diverse applicazioni utente come, per esempio, la posta elettronica o il Web.
- Dispositivi di interconnessione: Router: dispositivi che interconnettono reti. Switch: dispositivi che collegano fra loro più host a livello locale
- Collegamenti (link): mezzi trasmissioni (cablati, wireless)
### Local area network (LAN)
Le LAN (o reti locali) sono reti di computer circoscritte ad un’area limitata (ufficio, scuola, edificio, ecc.). Sono di proprietà di una organizzazione (reti private). Hanno un'estensione che arriva fino a qualche km (tipicamente). Sono molto usate per connettere sistemi terminali, es. PC, workstation, stampanti. Cavo di rame, wireless,..

![[Screenshot 2023-10-25 at 11.41.11.png]]
### Wide area network (WAN)
Una WAN (o rete geografica) è una rete il cui compito è di interconnettere LAN o singoli host separati da distanze geografiche. Gestita da un operatore di rete che fornisce servizi ai clienti.
- WAN punto-punto: collega due dispositivi tramite un mezzo trasmissivo (es. cavo in fibra ottica, ponti radio…).
- WAN a commutazione: collega più di due punti di terminazione (ad esempio usata nelle dorsali Internet).
- Elementi di commutazione: elaboratori specializzati utilizzati per connettere fra loro due o più linee di trasmissione.

Uno scenario molto comune sono reti locali interconnesse tramite WAN. Ad es. reti locali nelle sedi di aziende dislocate sul territorio nazionale. Rete internet privata che interconnette le reti locali dei vari uffici.

![[Screenshot 2023-10-25 at 11.43.22.png]]
### Rete garr
Interconnette università, centri di ricerca, biblioteche, musei, scuole e altri luoghi in cui si fa istruzione, scienza, cultura e innovazione su tutto il territorio nazionale. 
Infrastruttura in fibra ottica che utilizza le più avanzate tecnologie di comunicazione e si sviluppa su circa 15.000 km tra collegamenti di dorsale e di accesso.
Oggi la capacità delle singole tratte della dorsale arriva a200 Gbps, 100 punti di presenza distribuiti capillarmente sul territorio nazionale.

![[Screenshot 2023-10-25 at 11.47.41.png]]
### Reti area metropolitana (MAN)
Rete di computer che collega i computer all'interno di un'area metropolitana, un'unica grande città, più città e paesi o qualsiasi area di grandi dimensioni con più edifici. 
È più grande di una rete locale (LAN) ma più piccola di una rete geografica (WAN) e non necessariamente nelle aree urbane; il termine "metropolitano" implica la dimensione della rete, non i dati demografici dell'area che serve.

![[Screenshot 2023-10-25 at 11.57.19.png]]
### Networks of networks
Gli host si connettono a Internet tramite Internet Service Provider (ISP), ISP residenziali, aziendali ( universitari, commerciali).  Gli ISP di accesso a loro volta devono essere interconnessi in modo che due host qualsiasi possano inviare pacchetti l'uno all'altro. 
La risultante rete di reti è molto complessa l'evoluzione è stata guidata dall'economia e dalle politiche nazionali. Adottiamo un approccio graduale per descrivere l'attuale struttura di Internet.

Internet è un insieme mondiale di reti interconnesse (internet works o Internet in breve), che collaborano tra loro per scambiarsi informazioni utilizzando standard comuni (IP). Non è di proprietà di alcun individuo o gruppo. Si basa su tecnologie e standard coerenti e comunemente riconosciuti. Organizzazioni sviluppate allo scopo di aiutare a mantenere la struttura e la standardizzazione dei protocolli e dei processi Internet come: Internet Engineering Task Force (IETF), Internet Corporation for Assigned Names and Numbers (ICANN), Internet Architecture Board (IAB), oltre a molte altre.

![[Screenshot 2023-10-25 at 11.59.50.png]]
## Commutazione
Una internet (o internetwork) è data dall’interconnessione di reti, composte da link e dispositivi capaci di scambiarsi informazioni. In particolare, i dispositivi si distinguono in: sistemi terminali (host), dispositivi di interconnessione che si trovano nel percorso (o rotta) tra i sistemi sorgente e destinazione nella comunicazione tra host.
- Problema: Voglio stabilire una comunicazione (es. invio di un messaggio) tra due host.
- Domande: Come determinare il percorso da sorgente a destinazione? Come effettuare trasferire delle informazioni dall porta di ingresso alla porta di uscita?

Tecniche di commutazione: modalità con cui viene determinato il percorso sorgente-destinazione e vengono dedicate ad esso le risorse della rete. I meccanismi principali sono:
- Circuit-switched network: Reti a commutazione di circuito.
- Packet-switched network: Reti a commutazione di pacchetto
### Commutazioni del circuito
Il percorso viene stabilito all’inizio della comunicazione (setup). Sul percorso vengono dedicate risorse alla comunicazione (canale logico o circuito) in modo esclusivo, banda di frequenza o slot di trasmissione sui collegamenti e capacità commutative nei nodi. Le risorse allocate sono garantite per tutta la durata della comunicazione, indipendentemente dall’utilizzo effettivo.

![[Screenshot 2023-10-25 at 12.32.32.png]]

Communication di circuito di tipo FDM e TDM:
- **Frequency Division Multiplexing (FDM):** frequenze ottiche, elettromagnetiche suddivise in bande di frequenza (strette). Ad ogni comunicazione è assegnata una certa banda.

![[Screenshot 2023-10-25 at 12.34.33.png]]

- **Time Division Multiplexing (TDM):** tempo suddiviso in slot di tempo, ogni comunicazione ha uno o più slot periodici assegnati, può trasmettere alla velocità massima di una banda di frequenza (più ampia), ma solo durante i suoi intervalli di tempo.

![[Screenshot 2023-10-25 at 12.34.42.png]]


SVANTAGGI:
- Necessaria una fase di instaurazione (setup) della comunicazione.
- Le risorse rimangono inattive se non utilizzate (non c’è condivisione). Ad es. silenzi durante conversazione telefonica
VANTAGGI:
- Performance (garantita)
- Tariffa facile
### COMMUTAZIONE DI PACCHETTO
1. **Il flusso di dati punto-punto viene suddiviso in pacchetti:** I pacchetti degli utenti A e G condividono le risorse di rete, ogni pacchetto è instradato singolarmente e indipendentemente dagli altri pacchetti della stessa comunicazione (possono seguire lo stesso percorso o percorsi diversi). Le risorse vengono usate a seconda delle necessità.
2. **Trasmissione store and forward:** Il commutatore (es. router) deve ricevere l’intero pacchetto prima di poter cominciare a trasmettere il primo bit del pacchetto sul collegamento in uscita -> Ritardo di store and forward. Attesa dei pacchetti in code di output (buffer) -> Ritardi di coda. I buffer hanno dimensione finita -> Perdita di pacchetti.

![[Screenshot 2023-10-25 at 12.48.30.png]]


- pacchetto dopo pacchetto la capacità trasmissiva dei collegamenti sarà condivisa solo tra gli utenti che devono trasmettere sul collegamento.
- La sequenza dei pacchetti A e B sul collegamento a 1,5 Mbps non segue uno schema prefissato -> condivisione di risorse su richiesta (detta anche multiplexing statistico delle risorse).
- Non c’è un canale dedicato, gli host comunicano scambiandosi pacchetti.
- I router possono memorizzare i pacchetti nelle code (buffer).
- Se il collegamento tra i due router è usato alla massima capacità, gli ulteriori pacchetti che arrivano vengono messi in coda. 

Contesa per le risorse: La richiesta di risorse può ecceder il quantitativo disponibile. Si crea congestione: accodamento dei pacchetti, attesa per l’utilizzo del collegamento. Questo porta ad utilizzo efficiente delle risorse ma non c’è garanzia delle prestazione (es. ritardi)

SVANTAGGI:
- Tecnologie di inoltro non efficienti (necessità di selezionare l’uscita per ogni pacchetto).
- Ritardi variabili nel percorso end-toend (jitter), tempo di elaborazione ai router (routing table lookup), accodamento ai router.
- Protocolli necessari per un trasferimento dati affidabile, controllo della congestione
VANTAGGI:
- Risorse trasmissive usate solo se necessario.
- Segnalazione non richiesta.

ESEMPIO: Circuit switching vs Packet Switching

![[Screenshot 2023-10-25 at 12.52.15.png]]

- Circuit Switching: Con la commutazione di circuito, occorre riservare 100Mbps per ogni utente, in ogni istante. Il link di output può quindi supportare simultaneamente al massimo 1Gbps/100Mbps = 10 utenti.
- Packet Switching: 10 o meno utenti simultaneamente attivi -> banda richiesta ≤1 Mbps, ritardo trascurabile. Più di 10 utenti attivi simultaneamente -> frequenza aggregata di arrivo dei dati supera la capacità del collegamento in uscita e quindi si incrementa il ritardo di accodamento. N.B. la probabilità che ci siano 10 o meno utenti attivi contemporaneamente è 0.9996. Con alta probabilità la tecnica del packet switching supporta tutti i 35 utenti senza introdurre alcun ritardo! 16 La commutazione di pacchetto consente a più utenti di utilizzare la rete

# Lo strato Applicativo URI-HTTP

La pila protocollare di internet è formata da:
- Applicazione: supporta le applicazioni di rete ess: ftp, smtp, http
- Trasporto: trasferimento dati end-to-end (tra host terminali) TCP, UDP
- Rete: instradamento dei datagrammi della sorgente alla destinazione. Essa: IP, protocolli di instradamento.
- Link: trasferimento dati tra elementi di rete vicini esso: ppp, Ethernet.
- Fisico: bit “sul fisico”.

## Applicazione di rete
Applicazioni formate da processi distribuiti comunicanti, i processi sono programmi eseguiti dai dispositivi terminali (o host o “end System”) di una rete. All’interno dello stesso host, due processi possono anche comunicare attraverso la comunicazione inter-processo definita dal sistema operativo.
Nella comunicazione a livello applicativo fra due dispositivi terminali diversi di una rete, due o più processi girati su ciascun degli host comunicativi e si scambiano messaggi.

![[Screenshot 2023-11-08 at 12.56.30.png]]

I livelli applicazione nei due lati della comunicazione agiscono come se esistesse un collegamento diretto attraverso il quale poter inviare e ricevere messaggi.

Il protocollo dello strato di applicazione definisce:
- I tipi di messaggi scambiati a livello applicativo (es: di richiesta e di risposta)
- La sintassi dei vari tipi di messaggio (i campi del messaggio)
- La semantica dei campi (significato)
- Le regole per determinare quando come un processo invia messaggi o risponde ai messaggi

## Paradigmi del livello applicazione
Programmi applicativi su host diversi che comunicano tra di loro scambiandosi messaggi. Es. gestione di un elaboratore remoto, trasferimento e condivisione file, posta elettronica, comunicazione multimediale. I due programmi applicativi devono essere entrambi in grado di richiedere e offrire servizi, oppure ciascuno deve occuparsi di uno dei due compiti? Per rispondere a questa domanda ci sono vari paradigmi: 
- Client-server
- Peer-to-peer
- Misto