### URI - Uniform Resource Identifier

- **Uniform** uniformità della sintassi dell'identificatore
- **Resource** qualsiasi cosa abbia  un'identità
- **Identifier** informazione che permette di distinguere un oggetto dagli altri.

###### URL (Uniform resource locator)
Sottoinsieme di URI che identifica le risorse attraverso il loro meccanismo di accesso.
Ess: https://ieeexplore.ieee.org/document/10239/

- URl schema: \<protocol>://\<user>:\<password>@\<host>:\<port>/\<path>
- HTTP URI schema: http://<host\>:\<port>/\<path>?\<query>

- **URL assoluta** identifica una risorsa indipendentemente dal contesto in cui è usata.
- **URL relativa** informazione per identificare una risorsa in relazione ad un'altra URL
###### URN (Uniform resource Name)
Sottoinsieme di URI che devono rimanere globalmente unici e persistenti anche quando la risorsa cessa di esistere e non è disponibile.
Ess: urn:oasis:names:specification:docbook:dtd:xml:4.1.2:

### HTTP - HyperText Transfer Protocol

- Protocollo di **richiesta/risposta**, client invia richiesta e server invia risposta
- Protocollo **stateless** dove ogni coppia richiesta/risposta è indipendente dalle altre
- Usa **TCP**

###### Connessione
Un circuito logico di livello trasporto stabilito tra due programmi applicativi per comunicare tra di loro
###### Connessione non persistente (HTTP/1.0)
Viene stabilita una connessione TCP separata per recuperare ciascun URL
###### Connessione persistente (HTTP/1.1)
Se non diversamente indicato il client può assumere che il server manterrà una connessione persistente
- Stessa connessione utilizzata per una serie di richieste/risposte
- Il server chiude al connessione quando viene specificato nell'header del messaggio, o quando non riceve richieste per un certo tempo.
###### Pipelining
- Il client invia molteplici richieste senza aspettare risposte (metodi HTTP indipendenti)
- Il server invia risposte nello stesso ordine in cui riceve richieste
- Migliora prestazioni

#### HTTP request

![[Screenshot 2024-08-20 at 15.25.50.png | 500]]
- **Metodo**: operazione che il client richiede di fare
- **HTTP-Version**: formato del messaggio e capacità
#### HTTP response

![[Screenshot 2024-08-20 at 15.26.29.png | 500]]
- **Status-code**: intero che rappresenta un codice di risultato dell'operazione.
- **Reason-phrase**: descrizione testuale dello status code

##### Header
Insieme di coppie (nome: valore)
- **General header**: relativi a trasmissione (data, codifica, connessione)
- **Entity header**: relativi all'entità trasmessa (content-type, content-lenght ec..)
- **Request header**: relativi alla richiesta
- **Response header**: nel messaggio di risposta

##### Content negotiation
Meccanismo per selezionare la rappresentazione appropriata quando viene servita una richiesta.

#### Request method
###### OPTIONS
Richieste solo le opzioni di comunicazione associate ad un URL o al server stesso.
###### GET
Richiesta di trasferimento di una risposta identificata da un URL. Possibile utilizzo di **conditional get** (if-modified-since) o **partial get** (range).
###### HEAD
Simile a GET ma il server non trasferisce il body ma solo l'head, utile per controllare stato dei documenti.
###### POST
Server al client per inviare informazioni inserite del body del messaggio
###### PUT
Il client chiede al server di creare/modificare una risorsa
###### DELETE
Il client chiede di cancellare una risorsa identificata dalla request URI.

##### Safe methods
Metodi che non hanno effetti "collaterali" (GET, HEAD, OPTIONS, TRACE)

##### Idempotent methods
I metodi possono avere la proprietà di "indipendenza" negli effetti collaterali se N > 0 richieste identiche hanno lo stesso effetto di una richiesta singola (GET, HEAD, PUT, DELETE, OPTIONS, TRACE)

##### WEB caching
Serve per soddisfare le richieste del client senza contattare il server e si fa memorizzando copie temporanee di risorse web e servirle al client invece di inviare le richiesta al server

- **User agent cache**: il browser mantiene copia risorse visitate recentemente
- **Proxy cache**: Salva le risposte e successivamente inoltre quelle salvate senza inoltrare richiesta al server.

Riduce tempi di risposta, riduce traffico sul collegamento.

##### Cookie
Serve per mantenere uno stato del client.
1. C  invia a S richiesta
2. S invia a C risposta + **set-cookie: 1678**
3. C memorizza cookie in un file
4. C invia nuova richiesta ad S con **cookie: 1678** nel header
5. S confronta cookie con info che ha associato ad esso internamente

Si usa per autenticazione, ricordare scelte precedenti, creare sessioni.