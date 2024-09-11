## Proprietà del servizio
##### Orientato allo stream
Il TCP vede i dati come un flusso di byte ordinati ma non strutturati di lunghezza indefinita e con la capacità di correggere tutti i tipi di errori .
##### Orientato alla connessione (multiplexing/demultiplexing)
- Viene effettuato un **handshake** all'inizio
- Stato della connessione risiede sui punti terminali non su elementi intermedi (router)
- Connessione vista da utenti come **circuito dedicato**
##### Connessione full-duplex
- Flusso può avvenire contemporaneamente nelle due direzione
- Connessione punto-punto
##### Controllo della connessione
Meccanismo di inizio e fine trasmissione (controllo di sessione)
##### Controllo di flusso
Evitare di spedire più dati di quanti il ricevitore sia in grado di trattare.
##### Controllo di congestione
Ha lo scopo di recuperare situazioni di sovraccarico nella rete
##### Trasferimento bufferizzato
Il protocollo TCP è libero di suddividere i dati in **segmenti in modo indipendente dal programma applicativo**. Questo consente una riduzione del traffico sulla rete.

![[Screenshot 2024-08-21 at 18.02.01.png | 500]]

## Formato segmento TCP

![[Screenshot 2024-08-21 at 18.05.37.png | 500]]

Il numero di sequenza, numero di riscontro e la finestra permettono il **flow control**, meccanismo di **ritrasmissione**, il **riordino**  dei pacchetti.
###### Numero di sequenza (32 bit)
È il numero del primo byte del segmento. In genere si parte da un numero iniziale generato casualmente.
###### Numero di riscontro o ACK (32 bit)
È il numero dell'ultimo byte correttamente ricevuto + 1. Con "ACK=y" significa che aspetto il byte y e quindi che ho ricevuto tutti i byte fino al y-1 incluso. 
###### Porta (16 bit)
Numeri di porta della comunicazione
###### Hlen (4bit)
Lunghezza dell'header TCP espressa in parola da 4 byte
###### Bit codice (6 flags)
- **URG**: campo 'puntatore urgente' è significativo e ci sono dati in via prioritaria
- **ACK**: campo 'numero di risorse' contiene dati significativi
- **PSH**: attiva funzione 'push' (trasferimento immediato dei dati in un segmento dal trasporto al livello applicativo)
- **RST**: reset della connessione
- **SYN**: sincronizza numero di sequenza
- **FIN**: chiusura connessione
###### Finestra di ricezione (16 bit)
Indica il numero di byte che il mittente di questo segmento è in grado di accettare. Serve per il controllo di flusso.
###### Checksum (16 bit)
Si utilizzare per rilevare errori e si calcola come UDP (per il TCP è obbligatorio)
###### Opzioni
Si possono aggiungere vari parametri facoltativi, di lunghezza variabile ma massimo 40 byte. Le dimensioni sono sempre multipli di 8 bit ed il loro valore è considerato nel calcolo del checksum.
###### Puntatore urgente
Questo campo è un offset positivo a partire dal numero di sequenza del segmento, ed indica il primo byte **non** urgente, tutti i dati successivi a quello vengono fatti andare in testa alla coda di recezione se il flag è impostato ad 1.

### [[Handshake a tre vie]]

### [[Trasferimento dati]]

### [[Chiusura della connessione]]


## TCP stati
##### Listen
Rappresenta attesa per una richiesta di connessione da un TCP o porta remoto.
##### Syn-Sent
Rappresenta l'attesa della richiesta di associazione connessione dopo aver mandato una richiesta di connessione.
##### Syn-Received
Rappresenta l'attesa per la richiesta di conferma del riconoscimento connessione dopo che entrambi hanno ricevuto e mandato una richiesta di connessione.
##### Established
Rappresenta una connessione aperta, possono essere ricevuto ed inviati messaggi agli utenti. È lo stato normale per la fase di trasferimento dati.
##### Fin-Wait-1
Rappresenta l'attesa per una richiesta di terminazione della connessione dal TCP remoto o il riconoscimento della richiesta di terminazione precedentemente inviata.
##### Fin-Wait-2
Rappresenta l'attesa per una richiesta di terminazione di connessione da un TCP remoto.
##### Close-Wait
Rappresenta l'attesa di una richiesta di terminazione di connessione da un utente locale
##### Closing
Rappresenta l'attesa del riconoscimento di una richiesta di terminazione connessione da un TCP remoto.
##### Last-ack
Rappresenta l'attesa per il riconoscimento della richiesta di terminazione della connessione precedentemente inviata dal TCP remoto
##### Time-Wait
Rappresenta l'attesa per un tempo sufficiente per essere sicuri che il TCP remoto ha ricevuto al la richiesta di conferma di terminazione della connessione. 
##### Closed
Rappresenta lo stato di nessuna connessione.


