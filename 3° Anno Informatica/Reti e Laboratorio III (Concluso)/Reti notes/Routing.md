Il routing è il processo decisionale di scelta del percorso verso una destinazione, e serve a determinare i valori da inserire nella tabella di inoltre **tramite algoritmi di routing** (si occupa dei **control plane** mentre il forwarding dei **data plane**)

##### Routing decentralizzato
L'algoritmo di routing è in esecuzione su ciascun router ed i router si scambiano i messaggi.

![[Screenshot 2024-08-26 at 21.28.38.png | 500]]

##### Routing logicamente centralizzato
Un controller remoto interagisce con CA (Control Agents) locali, ricevendo informazioni dai CA sul traffico e collegamenti, ed inviando ad i CA i valori da inserire nelle tabelle.

![[Screenshot 2024-08-26 at 21.31.05.png | 500]]

# Architettura router
##### Porte di input
- **Inoltro**. Ha una copia della tabella di inoltro, usa i valori dell'header per determinare la porta di output
- **Ricerca**. Esegue una elaborazione alla velocità "line rate"
- **Accodamento**. Se la velocità con cui arrivano i datagrammi supera la velocità di inoltro nella struttura di commutazione.

![[Screenshot 2024-08-26 at 21.38.46.png | 400]]

##### Porte di output
- **buffering**. Richiesto quando i datagrammi arrivano dalla struttura di commutazione ad una velocità maggiore della velocità di trasmissione sul collegamento in uscita.
- **scheduling**. Politiche per definire l'ordine di trasmissione di datagrammi

![[Screenshot 2024-08-26 at 21.41.24.png | 400]]

##### Processore di routing
Il processore che esegue i calcoli degli algoritmi di routing all'interno del router.

##### Switching fabric
Trasferisce i pacchetti dal buffer di input al buffer di output appropriato. La velocità con cui i pacchetti possono essere trasferiti dagli ingressi alle uscite si chiama **velocità di commutazione**.

![[Screenshot 2024-08-26 at 21.38.02.png | 400]]

##### Ritardi e perdite
Si possono creare code di pacchetti di lunghezza variabile (varia per quantità di traffico, velocità relative della struttura ecc..)

# Routing

L'obbiettivo dei protocolli di routing è quello di determinare i percorsi buoni dagli host mittenti ai destinatari, per farlo si astrae una rete come un grafo.
###### Graph abstraction - Costi
Il costo viene definito dall'operatore di rete, e può essere inversamente proporzionale alla bandwidth o all congestione.
###### Routing statico
Le righe delle tabelle del router vengono configurate manualmente, usato per reti di piccole dimensioni.
###### Routing dinamico
Esistono protocolli specifici che si occupano di riempire le tabelle dei router.

## Algoritmi di instradamento 
###### Algoritmi globali
Sono globali se si basano sulla conoscenza della topologia di tutta la rete. Il calcolo viene fatto in un unico nodo o in più utilizzando info sulle connessioni e sui costi dei link.
###### Algoritmi decentralizzati 
Sono decentralizzati quando nessun nodo conosce la topologia di tuta la rete, ma ha solo info su nodi e link vicini. Il calcolo avviene in maniera **iterativa** e **distribuito**.

#### [[Distance vector algorithm]]

#### [[Link-state algorithm (LSP)]]


## Protocolli
#### Instradamento gerarchico
Nella realtà i router sono organizzati in **sistemi autonomi (AS)** e non in una semplice rete costituita da un insieme di router omogenei interconnessi
###### Sistemi autonomi (AS)
Un AS è un gruppo di router sotto lo stesso controllo amministrativo, ogni AS decide autonomamente i protocolli e le politiche di routing che vogliono usare al loro interno
- Interior Gateway Protocol (IGP): protocolli di routing all'interno di un AS
- Exterior Gateway Protocol (EGP): protocolli di routing fra gli AS

###### INTRA-AS
Il INTRA-AS routing protocol determina da solo rotte per le destinazioni interne ad AS
###### INTER-AS 
Contente di conoscere le destinazioni raggiungibili attraverso sistemi autonomi vicini e propaga le info raggiungibilità ai router interni del proprio AS.

#### [[RIP - Routing Information Protocol]]

#### [[OSPF - Open Shortest Path First]]

#### [[BGP - Border Gateway Protocol]]

### IPv6
Standard diverso creato perché 
- Abbiamo un esaurimento di indirizzi a 32 bit
- Velocizza elaborazione e forwarding pacchetti
- Risparmiare ai router costo frammentazione
- Facilitare QoS

###### Dual stack

![[Screenshot 2024-08-27 at 18.02.16.png | 500]]
###### Tunneling

![[Screenshot 2024-08-27 at 18.03.09.png | 500]]