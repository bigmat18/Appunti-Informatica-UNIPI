### Problemi HTTP/1.1 (HOL blocking)

- Abbiamo che più GWT in pipeline su una singola connessione TCP ed il server risponde in ordine con ripristino di eventuali perdite
- Si crea HOL (Head of line) blocking quando **una risposta può bloccare l'invio dei contenuti**.

### HTTP/2

##### Caratteristiche
- Maggiore flessibilità lato server nell'invio di oggetti al client
- Campi di intestazioni invariati rispetto a HTTP 1.1 (retro compatibilità)
- Ordine di trasmissione di oggetti in base a priorità specificata da client
- Invia anche oggetti non richiesti al client
- Divide gli oggetti in frame e fa scheduling dei frame per mitigare HOL blocking

##### 1. Multiplexing delle richieste su una connessione TCP
###### Frame 
Unità di comunicazione in HTTP/2, una sequenza di frame costituisce messaggio HTTP

###### Stream
Un flusso bidirezionale di frame all'interno di un'unica connessione TCP, rappresenta una comunicazione richiesta-risposta. 

###### Multiplexing delle richieste
Si ottiene mediante l'astrazione degli stream.

##### 2. Definizione delle priorità
Si può associare ad ogni stream 
- un **peso** che ne indica la priorità 
- una **dipendenza** verso altri stream 

##### 3. Compressione delle intestazioni

##### 4. Server Push
Permette al server di inviare risorse aggiuntive per una singola richiesta da parte del client

### HTTP/3

- Evoluzione di HTTP/2 ed usa servizi di QUIC (UDP)
- Mantiene semantica HTTP/2 (retro compatibilità)
- Aggiunge sicurezza, controllo errori, controllo congestione a UDP

#### QUIC
Protocollo di trasporto che sfrutta UDP orientato però alla connessione che aggiunge controllo del flusso, della congestione e rilevazione delle perdite e ritrasmissione.

- Più flussi a livello di applicazione mutiplexati su una singola connessione QUIC
- Astrazione dello stream gestito a livello di trasporto
- Trasferimento dati affidabile sul singolo flusso
- Stream indipendenti tra loro, quindi perdita o rallentamento di uno stream non influisce sul progredire degli altri stream.