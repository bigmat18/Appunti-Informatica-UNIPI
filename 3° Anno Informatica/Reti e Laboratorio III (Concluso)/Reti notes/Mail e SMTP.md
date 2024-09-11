###### User agent
Si occupa della composizione, editing, lettura di messaggi di posta
###### Mail server
I messaggi in entrata ed uscita vengono archiviati sul server
###### Indirizzi email
Un destinatario è identificato da un indirizzo email **local-part@domani-name@
- **domani name** specifica il nome di dominio di una destinazione in un server mail.
- **local part** specifica la cassetta di posta nel mail server

### Schema di comunicazione spooling
1. Utente invia un messaggio
2. Il sistema pone una copia in memoria (**spool**) insieme ad id mittente, id destinatario, id macchina destinazione e tempo deposito 
3. Il sistema avvia trasferimento alla macchina remota con connessione [[TCP]] con destinatario.
4. Se connessione viene aperta inizia trasferimento
5. Se trasferimento va a buon fine il client cancella copia locale
6. Se trasferimento fallisce si riprova periodicamente per un certo intervallo di tempo, al termine i invia messaggio non consegnato a mittente.

###### Alias
Cassetta postale virtuale che ridistribuisce i messaggi verso uno o più indirizzi di posta elettronica.
###### Molti-uno
Si può assegnare un set di identificatori ad una singola persona (un utente più indirizzi)
###### Uno-molti
Associare un gruppo di destinatari ad un singolo identificatore (1 indirizzo postale, più destinatari)

### SMTP - Simple Mail Transfer Protocol

- Trasferimento **affidabile e efficiente** di mail indipendentemente dal sistema di trasmissione usato ed attraverso più reti.
- Usa **canale di trasmissione bidirezionale con un server SMTP** 
- Un client deve **determinare l'indirizzo di un host che ospita un server** risolvendo il nome della destinazione e poi **comunicare mail o insuccesso**.
- Protocollo di tipo **push**

##### Problemi
- Errore connessione con mail server mittente
- Errore connessione con mail server destinatario
- Errore durante inserimento in mail box destinatario

In ogni caso **mittente viene avvisato con notifica**.

##### Protocollo
- Avvia connessione TCP **porta 25** 
- Fase **handshaking** 
	- client stabilisce connessione e attende che il sever invii **220 READY FOR MAIL**
	- client risponde con comando **HELO**
	- server risponde **identificandosi**
- Trasferimento messaggi
- Chiusura connessione

![[Screenshot 2024-08-20 at 16.53.13.png | 400]]

##### Comandi
- HELO
- MAIL FROM
- RCPT TO
- DATA
- QUIT

##### Formato messaggi
I usa standard testo **RFC 2822**
- **linee intestazione** (to, from, subject)
- **body** (caratteri ascii a 7 bit)

### MIME - Multipurpose Internet Mail Extension

Si usa per inviare messaggi con caratteri speciali e contenuti audio, video. Utilizza sempre RFC 822 ma aggiunge una struttura al messaggio body definendo regole di **codifica per rappresentare dati binari in ASCII**. 

![[Screenshot 2024-08-20 at 17.03.10.png | 600]]

###### ASCII encoding of binary data
Base 64 encoding. Gruppi di 24 bit sono divisi in 4 unità da 6 bit e ciascuna unità viene inviata come un carattere ASCII

###### Quoted-printable encoding
Per messaggi testuali con pochi caratteri non-ASCII, più efficiente

### Protocolli accesso alla posta

##### POP3 (Pull)
1. Lo user agent apre una connessione TCP (porta 110) verso server di posta
2. **Autorizzazione** dove client specifica username e password
3. **Transazione** dove client può list, retr, dele, quit
4. **Aggiornamento** dopo quit server cancella i messaggi marcati per la rimozione

##### IMAP
- Più complesso di POP3 fornisce più feature
- Manipola messaggi memorizzati sul server
- Comandi per astrarre solo alcuni componenti dei messaggi

##### HTTP
Sono tipo Hotmail, Yahoo, Gmail etc...