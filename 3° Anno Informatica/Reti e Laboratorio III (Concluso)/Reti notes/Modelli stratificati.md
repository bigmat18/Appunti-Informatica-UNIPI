##### Protocollo
Insieme di regole che permettono a due entità di comunicare.
##### Vantaggi stratificare
- Struttura esplicita permette l'identificazione delle relazioni tra elementi in un sistema
- Modularizzazione facilità manutenzione ed aggiornamento. Ogni modulo esegue in insieme limitato di compiti ed appare nel sistema con una black box. Ciascuno offre servizi a strato superiore ed usa strati inferiori
- Separazione tra servizi offerti e implementazioni. Se si cambia un implementazione è trasparente per il sistema.
##### Separation of Concern
Separazione degli interessi e delle responsabilità, fare ciò che compete, delegando ad altri tutto ciò che è delegabile.
##### Information Hiding
Nascondere tutte le informazioni che non sono indispensabili per il committente per definire compiutamente l'operazione.

**Nota**
In un sistema si cerca di minimizzare gli strati ed il flusso fra le interfacce.

## OSI RM (Open Systems Interconnection)
Questo è il modello di riferimento che regola le comunicazioni di rete
##### Sistemi chiusi
- Tutti componenti della reti dello stesso costruttore
- Rete altamente specializzata
- Gli apparati non riescono ad iterpretare i segnali degli altri in altre reti.
##### Sistemi aperti
Qualsiasi terminale comunica con qualsiasi fornitore di servizi mediante qualsiasi rete. Si usano degli **standard**.
- Dettagli protocollo pubblici 
- Cambiamenti gestita da organizzazione aperta al pubblico

## Modello ISO/OSI

- Divide le funzionalità del protocollo di telecomunicazione in **strati o layers** ognuno dei quali svolge una parte piccola e indipendente dalle altre.
- La comunicazione tra i vari livelli è assicurata da chiamate standard
- La modalità con cui le funzioni competenti ad un livello vengono svolte non è visibile dall'esterno.
- Uno strato n-esimo di un entità comunica con n-esimo di un'altra entità secondo protocollo assegnato.
###### Strato
È un modulo interamente definito attraverso i servizi, protocolli e le interfacce che lo caratterizzano.
###### Servizio
Servizi che uno strato fornisce ad uno strato soprastante attraverso primitive di servizio.
###### Interfaccia
Insieme di regole che governano il formato ed il significato delle unità di dati che vengono scambiati **tra due strati adiacenti della stessa entità**.
###### Protocollo
- Permettono a **due entità omologhe (stesso strato)** uno scambio efficace ed efficiente delle informazioni.
- Definiscono il formato e l'ordine dei messaggi inviti e ricevuti tra **entità omologhe** della rete e le azioni che vengono fatte per la trasmissione e ricezione dei messaggi.
###### Efficace
Un sistema che riesce a raggiungere lo scopo prefissato con la maggior frequenza possibile.
###### Efficiente
Un sistema che riesce a raggiungere lo scopo prefissato con il minor sforzo possibile.

### Gerarchia di strati

![[Screenshot 2024-08-19 at 16.18.25.png | 500]]
#### Livello fisico
- Comprende tutte le funzioni (**procedure meccaniche ed elettroniche**) che permettono una connessione a livello fisico. 
- Si occupa della trasmissione dei bit attraverso il mezzo trasmissivo e delle caratteristiche di cavi e connettori.
##### Livello di collegamento
- Definisce le regole per inviare e ricevere informazioni tra due sistemi in comunicazione, attraverso il livello fisico in moto affidabile e standard. 
- Incapsula i dati in un pacchetto provvisto di header (intestazione) e tail (code), chiamato frame.
##### Strato di rete
- Si occupa dell’istradamento (“routing”) dei pacchetti cioè di determinare la sequenza di collegamenti punto-punto necessari per trasmettere un pacchetto da un nodo generico della rete a un altro.
##### Strato di trasporto
- Questo strato fornisce un servizio di trasferimento dati end-to-end andando a instaurare, mantenere, terminare una connessione.
- Può offrire funzionalità per frammentare e riassemblare i dati, rilevare e correggere gli errori, controllare il flusso dei dati.
##### Strato di sessione 
- Assembla il dialogo tra nodi in unità logiche (gestisce la sessione).
##### Strato di presentazione
- Adatta la sintassi dei dati di ciascuna applicazione alla sintassi richiesta dalla sessione
##### Strato di applicazione
- Protocolli a supporto di applicazioni distribuite.

![[Screenshot 2024-08-19 at 16.25.44.png | 500]]

###### Servizio Connection-oriented
Associare logica tra sue o più sistemi al fine di trasferire dati gestendo una connessione.

###### Servizio Connection-less 
I dati vengono trasferiti senza stabilire una connessione permanente.

###### Flusso dell'informazione
- Informazione ha origine a livello Applicativo
- Discende i vari livelli fino al fisico 
- Ogni livello aggiunge all'informazione una propria sezione eseguendo un operazione di **incapsulamento dei dati**.
###### Incapsulamento
- **Header** qualificazione del pacchetto dati per questo livello.
- **Data** payload proveniente dal livello superiore.
- **Trailer** generalmente usato in funzione di trattamento dell'errore.

### Pila di Protocolli TCP/IP

Gerarchia di protocolli, ciascuno dei quali fornisce funzionalità specifiche. 

![[Screenshot 2024-08-19 at 16.18.04.png | 500]]

##### Applicazione
supporta le applicazioni di rete, collegamento logico end-to-end: scambio di messaggi tra due processi (ftp, smtp, http)
##### Trasporto
Trasferimento dati end-to-end, da un host sorgente all'host destinatario, (tcp, udp).
##### Rete
Instradamento dei datagrammi dalla sorgente all destinazione (ip, ICMP).
##### Datalink
Trasferimento dati in frame attraverso il collegamento tra elementi di rete vicini (ppp, ethernet, ... qualunque cosa).
##### Fisico
trasferimenti dei bit di un frame sul mezzo trasmissivo. 

### ISO/OSI vs TCP/IP
|        | ISO/OSI                                                                                                                                                                                                                | TCP/IP                                                                                                                                                             |
| ------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Pro    | - Generale<br>- Definizione di servizio, interfaccia e protocollo                                                                                                                                                      | - Standard de facto<br>- Implementation driven                                                                                                                     |
| Contro | - Poco efficiente, alcuni livelli poco utili e chiari<br>- Alcune funzioni sono presenti in più livelli<br>- Standard difficili<br>- Telco-oriented<br>- I protocolli TCP/IP già in uso non si collocano perfettamente | - Specifiche non astratte e rigorose<br>- Modello non generale<br>- Oltre e TCP/IP, presenza di protocolli minori (per problemi ad -hoc), difficili da rimpiazzare |

