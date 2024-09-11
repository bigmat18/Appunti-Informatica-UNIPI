Utilizza il modello client/sever per trasferire file a/da un host remoto

- Standard per trasferimento file in reti TCP/IP
- Servizio diverso da accesso condiviso online
- Si ottiene una **copia locale** e successivamente se modificato si ritrasferisce
- Fornisce **accesso interattivo**, utente può navigare e cambiare/modificare albero di directory nel file system remoto
- Si può specificare formato dei dati da trasferire, il tipo del file (lo fa il client)
- Fornite **autenticazione**
- Usa RFC 959
- Protocollo **STATEFUL** il server tiene traccia dello stato dell'utente.
### Control connection
Scambio di comandi e risposte tra client e server seguendo protocollo Telnet. Usa TCP

1. Client FTP contatta server FTP su porta 21
2. Client ottiene autorizzazione su connessione di controllo
3. Client invia comandi su connessione di controllo
4. La connessione di controllo rimane **persistente**

###### Comandi
- USER username
- PASS password
- LIST elenco file della directory corrente
- QUIT chiude connessione
- ecc..

### Data connection
Connessione su cui i dati sono trasferiti con modi e tipi specificati. Usa TCP

1. Server **riceve comando trasferimento file su connessione controllo**
2. Server apre connessione TCP con client(**Active mode**)
3. Server trasferisce il file sulla connessione dati
4. Finito trasferimento, server chiude connessione.
5. La connessione dati **non è persistente**

###### Uso di porti con le due connessioni
Il client usa una porta locale casuale per contattare sever su porta nota (21), tramite la connessione di controllo il client ed il server coordinano l'uso delle porte per il **trasferimento dati**.

#### Active mode
Modalità classica descritta precedentemente, server apre connessione dati TCP con client su porta che è nota tramite connessione di controllo.

#### Passive mode
Il client chiede al sever di mettersi in ascolto su una porta per una connessione dati, il numero della porta lo ottiene dal sever e lo usa per aprire la connessione al server

#### Modalità di trasmissione
###### Stream mode
FTP invia i dati a TCP con un flusso continuo di bit
###### Block mode
FTP invia i dati a TCP suddivisi in blocchi. Ogni blocco è preceduto da un header
###### Compressed mode
Si trasmette il file come dati compressi.

#### Anonymus FTP
Server che permettono una connessione FTP senza autenticazione per accedere solo ad un subset di operazione e di dati.

#### Securing FTP with TLS
Meccanismo che può essere usato da client e server FTP per implementare sicurezza e autenticazione usando protocollo TLS