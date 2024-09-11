- Realizzare una **comunicazione logica** fra processi residenti in host diversi, si dice logica perché i processi si comportano come se fossero direttamente collegati
- Lo strato applicazione interagisce con i protocolli di trasporto, ci sono due stili **sequenza di messaggi singoli** e **sequenza continua di byte**
- Utilizza i servizi dello stato di rete

#### Servizio privo di connessione
Mittente consegna i messaggi al livello di trasporto uno per uno ed il livello di trasporto tratta ogni messaggio come entità singola (i messaggi possono non arrivare in ordine o fallire)

#### Servizio orientato alla connessione
Un client ed un server stabiliscono una connessione (logica)

#### Demultiplexing
Lo strato di trasposto prevede allo **smistamento** dei pacchetti fra la rete e le applicazioni
- lato destinatario usa l'header per recapitare i segmenti al socket corretto

Questo per esempio succede se un utente scarica pagine Web, trasferisce file con FTP ed ha una sessione Telnet, ha 3 processi, il trasporto riceve tutti i dati e li smista
###### Senza connessione - UDP
Lo trasto di trasporto del ricevente prende il segmento UDP e lo conscegna al socket attivo con IP e porta corrispondenti

![[Screenshot 2024-08-21 at 17.46.31.png | 500]]

###### Orientato alla connessione - TCP
L'host ricevente usa 4 parametri (IP e porta locale, IP e porta remota) per inviare il segmento al socket appropriata

![[Screenshot 2024-08-21 at 17.47.20.png |500]]

#### Multiplexing
Lo strato trasporto prevede **all'accorpamento** dei flussi dati dei processi verso la rete.
- lato mittente gestisce i dati da più socket aggiungendo l'header di trasporto

#### Porta
Ogni comunicazione è identificata in maniera univoca dalle coppie numero IP/porta
- **System ports** (Well Know Ports) da 0 a 1023 assegnate da IANA
- **User ports** (Registered Ports) da 1024 a 49151 assegnate da IANA
- **Dynamic ports** (Private o Ephemeral Ports) non assegnate da IANA