# Lo strato Applicativo URI-HTTP

La pila protocollare di internet è formata da:
- Applicazione: supporta le applicazioni di rete ess: ftp, smtp, http
- Trasporto: trasferimento dati end-to-end (tra host terminali) TCP, UDP
- Rete: instradamento dei datagrammi della sorgente alla destinazione. Essa: IP, protocolli di instradamento.
- Link: trasferimento dati tra elementi di rete vicini esso: ppp, Ethernet.
- Fisico: bit “sul fisico”.

## Applicazione di rete
Applicazioni formate da processi distribuiti comunicanti, i processi sono programmi eseguiti dai dispositivi terminali (o host o “end System”) di una rete. All’interno dello stesso host, due processi possono anche comunicare attraverso la comunicazione inter-processo definita dal sistema operativo.
Nella comunicazione a livello applicativo fra due dispositivi terminali diversi di una rete, due o più processi girati su ciascun degli host comunicativi e si scambiano messaggi.

![[Screenshot 2023-11-08 at 12.56.30.png]]

I livelli applicazione nei due lati della comunicazione agiscono come se esistesse un collegamento diretto attraverso il quale poter inviare e ricevere messaggi.

Il protocollo dello strato di applicazione definisce:
- I tipi di messaggi scambiati a livello applicativo (es: di richiesta e di risposta)
- La sintassi dei vari tipi di messaggio (i campi del messaggio)
- La semantica dei campi (significato)
- Le regole per determinare quando come un processo invia messaggi o risponde ai messaggi

## Paradigmi del livello applicazione
Programmi applicativi su host diversi che comunicano tra di loro scambiandosi messaggi. Es. gestione di un elaboratore remoto, trasferimento e condivisione file, posta elettronica, comunicazione multimediale. I due programmi applicativi devono essere entrambi in grado di richiedere e offrire servizi, oppure ciascuno deve occuparsi di uno dei due compiti? Per rispondere a questa domanda ci sono vari paradigmi: 
- Client-server
- Peer-to-peer
- Misto

### Client-server
**Client**
Inizia il contatto il server ("parla per primo"), tipicamente richeide un servizio al sever per esempio: per il web, il client è implementato nel browser, per l'email, nel mail render.
**Sever**
Fornisce al client il servizio richiesto, è sempre attivo, per esempio: i web sever inviano le pagine web richieste, il mail sever invia le e-mail.
![[Screenshot 2024-01-28 at 18.51.37.png | 400]]
**Esempio**. Componenti di un'applicazione di rete. **WEB**
- Browser sul client
- Server web
- Standard per il formato dei documenti (risorse)
- Protocollo HTTP

**Esempio**. Componenti di un'applicazione di rete. **Posta elettronica**
- Standard per il formato dei messaggi
- Programmi di lettura/scrittura sul client
- Server di posta di internet 
- Protocolli SMTP, POP3, ecc.

**N.B.** il protocollo a livello applicativo è solo una parte dell'applicazione di rete!
