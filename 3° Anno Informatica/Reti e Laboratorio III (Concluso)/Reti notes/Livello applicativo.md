I due lati della comunicazione di questo livello agiscono come se esistesse un collegamento diretto.

- Definisce i **tipi di messaggi** scambiati a livello applicativo (es: di richiesta e di risposta)
- La **sintassi** dei vari tipi di messaggio (i campi del messaggio)
- La **semantica** dei campi (significato)
- Le **regole** per determinare quando come un processo invia messaggi o risponde ai messaggi

##### Paradigma client-server
- Client inizia il contatto con il server chiedendo qualcosa
- Server fornisce al client il servizio richiesto, il server è sempre attivo

##### API application programming interface
Insieme di regole che un programmatore deve rispettare per utilizzare delle risorse

##### Interfaccia socket
- API che funge da interfaccia tra gli strati di applicazione e di trasporto, è un'astrazione. 
- Socket è l'API di internet per eccellenza. 
- La comunicazione client-server si realizza tra due socket

##### Indirizzare processi
Per ricevere messaggi un processo deve avere un identificatore (indirizzo IP + numero di porta)

##### Uso servizi di trasporto
I processi devono utilizzare i servizi offerti dal livello di trasporto per la comunicazione.

**TCP** 
- Connection-oriented
- Trasporto affidabile
- Controllo del flusso
- Controllo di congestione
- Non offre garanzie di timing ne di ampiezza minima di banda

**UDP**
- No orientate alle connessioni
- No Trasporto affidabile
- No controllo flusso
- No controllo congestione
- No garanzia timing ne ampiezza minima di banda