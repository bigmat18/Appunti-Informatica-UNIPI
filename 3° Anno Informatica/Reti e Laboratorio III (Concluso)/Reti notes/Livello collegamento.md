Il livello collegamento muove i datagrammi da un nodo al nodo adiacente su un singolo link di comunicazione
###### Terminologia
- Host e router sono i **nodi**
- Canali di comunicazione che collegano nodi adiacenti lungo un cammino sono **collegamenti** (cablati o wireless)
- Le unità dati di livello 2 sono chiamate **frame** (incapsula un datagramma)
###### Collegamento punto-punto
Collegamento dedicato a due soli dispositivi (CollegamentiWAN, Switched LAN Ethernet)
###### Collegamento broadcast
Collegamento condiviso tra più dispositivi. Quando un nodo trasmette un frame, il canale lo diffonde e tutti gli altri nodi ricevono una copia (Wireless LAN, reti satellitari, Ethernet)

### Servizi offerti
###### Framing
I protocolli incapsulano i datagrammi del livello rete all'interno di frame a livello di link che separa i ari messaggi durante la trasmissione da una sorgente ad una destinazione.
###### Consegna affidabile
Usata solo nei collegamenti a elevati tassi di errori (collegamenti wireless)
###### Controllo di flusso
Evita che il nodo trasmittente saturi quello ricevente.
###### Rilevazione degli errori
Tramite inserimento di bit di controllo di errore all'interno del frame si possono rilevare errori causati dall'attenuazione del segnale e da rumore.
###### Correzioni degli errori
Il nodo che riceve determina anche il punto in cui si è verificato l'errore e lo corregge.

### Adaptor
Il livello di comunicazione è implementazione degli adaptor o schede di rete, dove avviene una combinazione fra hardware e software.

###### Comunicazione adaptor mittente
- Incapsula il datagramma in un frame
- Aggiunge error checking bits, rdt, flow control 

###### Comunicazione adaptor destinatario
 - Controllo errori, rdt, flow control etc.
 - Estrae il datagramma, lo passa al livello superiore

