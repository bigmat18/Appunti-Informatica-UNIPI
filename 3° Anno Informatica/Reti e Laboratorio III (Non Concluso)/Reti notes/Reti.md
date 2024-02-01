# Introduzione alle reti

### INTERNET: vista dei componenti

![[vista-componenti.png | 400]]
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

![[images/Screenshot 2023-10-25 at 11.35.19.png | 350]]

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

# [[Commutazioni]]

# [[Metriche]]