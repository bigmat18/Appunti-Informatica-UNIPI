#### Componenti
- **Dispositivi connessi**  (servers spesso a data centers, pc, smartphone ecc.)
- **Reti di accesso o link di comunicazione** (fibra ottica, rame, onde radio, satelliti). 
- **Dispositivi di interconnessione** (router e switch). 
- **Le reti** (insieme di host, dispositivi di interconnessione, link gestiti da una organizzazione).

#### Servizi
- **Infrastruttura** che offre servizi alle applicazioni (web, streaming video, email ecc.)
- **Interfaccia di programmazione** alle applicazioni distribuite. Come “hooks” che permettono alle app mittenti e destinatari di collegarsi e usare il servizio di trasporto di Internet, opzioni di servizio tipo servizio Senza connessione o servizio orientato alla connessione.

#### Entità software
- **Applicazioni** elaborano e si scambino informazioni.
- **Protocolli**: regolano la trasmissione e la ricezione di messaggi.
- **Interfacce**: definite in seguito, solo le “membrane” che separano gli strati della pila protocollare.
- **Standard internet e del Web.**

###### Reti
Un’interconnessioni di dispositivi in grado di scambiarsi informazioni, quali sistemi terminali, router, switch e modem.
###### I sistemi terminali o host
- Macchina di proprietà degli utenti finali e dedicata ad eseguire applicazioni, quale un computer, un portatile, un cellulare o un tablet. 
- Server, tipicamente un computer con elevate prestazioni destinato a eseguire programmi che forniscono servizio a diverse applicazioni utente come, per esempio, la posta elettronica o il Web.
###### Dispositivi di interconnessione
- Router: dispositivi che interconnettono reti. 
- Switch: dispositivi che collegano fra loro più host a livello locale
###### Collegamenti o link
Sono i mezzi trasmissioni (cablati, wireless).


### Local area network (LAN)
Sono resti di computer circoscritte ad un'area limitata e di proprietà di una organizzazione privata, **solitamente estensione massima d qualche km**.

### Reti area metropolitana (MAN)
Rete di computer che collega computer all'interno di un area metropolitana, più grane di LAN ma più piccola di WAN.

### Wide area network (WAN)
È una rete che **connette LAN fra di loro**. Gestita da un operatore di rete esterno
- **WAN punto-punto**: collega due dispositivi tramite un mezzo di trasmissione
- **WAN a comunicazione**: collega più di due punti di terminazione
- **Elementi di comunicazione**: sono i dispositivi che si usano per la connessione fra due o più linee.
##### Rete GARR
Tipo di WAN che interconnette luoghi di istruzione, cultura ed innovazione, utilizza fibra ottica e si sviluppa su circa **15.000km** tra collegamenti di dorsale e di accesso. Capacità arriva a **200 Gbps**, ed ha **100 punti di presenza** distribuiti su territorio nazionale.

## Struttura di internet
Gli host accedono connettendosi a Internet Service Provider (ISP), gli ISP di accesso a loro volta devono essere interconnessi.

Vediamo dunque da qui che internet è un insieme mondiale di reti interconnessi **network of networks** che usano protocolli comuni (IETF, ICANN, IAB sono alcuni enti che regolani gli standard)

Abbiamo quindi alla fine che alcuni ISP centrali sono connessi fra di loto (**tier-1** ISP commerciali), ed i vari ISP di accesso si connettono a questi ISP centrali per avere connessione con tutti.

![[Screenshot 2024-08-19 at 14.57.09.png | 500]]