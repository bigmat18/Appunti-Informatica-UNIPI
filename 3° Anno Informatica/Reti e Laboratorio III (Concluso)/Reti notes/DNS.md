È un protocollo che ha l'obbiettivo di **individuare il processo omologo** con il quale si vuole comunicare, il processo omologo risiede su una particolare macchina remota, anche essa da individuare.
###### Nome
Un nome identifica un oggetto (www.yahoo.com)
###### Indirizzo
Identifica dove tale oggetto è situato (indirizzi IP formati da 4 byte)

### DNS - Domanin Name System

- Posizionato nel livello applicativo
- Usa paradigma client-server
- Non interagisce direttamente con gli utenti
- Consente la conversione da nomi a indirizzi e viceversa

##### Struttura
1. **Schema di assegnazione dei nomi** gerarchico
2. **Database distribuito** che contiene i nomi e i corrispondenti indirizzi IP con una gerarchia di name server
3. **Protocollo** per distribuire le informazioni (si utilizza UDP porta 53 oppure TCP)

##### Host aliasing
Un host può avere più nomi che poi vengono tradotti in nome canonico/indirizzo IP.
##### Mail server aliasing
Sono sinonimi per mail sever. Per esempio **nome canonico** relay1.west-coast.hotmail.com, **alias** hotmail.com
##### Distribuzione carico
Distribuire carico tra server replica, ad ogni hostname corrispondono più indirizzi IP ed il DNS fa load balancing fra questi.

### Spazio dei nomi
Si usa una struttura gerarchica dove un nome è costituito da diverse parti (lab3.di.unipi.it), creando una struttura ad albero con un numero di livelli variabile.
###### Dominio
Sotto albero nello spazio dei nomi di dominio che viene identificato dal nome di dominio del nodo radice del sotto albero.

I **top-level domain** sono mantenuti da IANA (Internet Assigned Numbers Authority) e sono tipo .com, .edu, .mil, .gov ecc..

### Gerarchia dei name server
##### Name server
- È il programma che gestisce la conversione da nome di dominio a indirizzo IP
- Le informazioni sono ripartiti in più name server
##### Zona
- Porzione dello spazio dei nomi di dominio che è gestita da una specifica amministrazione.
- I server **immagazzina le info relative alla propria zona** inclusi i **riferimenti ai name server dei domini di livello inferiore**

##### Server radice (Root name server)
Responsabile dei record della zona radice, restituisce le informazioni di tutti i domini di massimo livello (TLD) e conosce il server che risolve ciascun dominio.

##### Server top-level domain (TLD)
Mantiene le informazioni di dominio di un certo TLD, e restituisce informazioni dei sotto domini di competenza.

##### Server di competenza (authoritative name server)
Esiste per una certa zona e memorizza nome-indirizzo IP di un insieme di host. Possono per una certa zona esiste sia server di competenza **primari** (mantengono il file di zona) e **secondari** (offrono i servizi di risoluzione)

##### Local name server
Non appartiene direttamente alla gerarchia ed ogni ISP ha il suo di default.
1. Programma deve trasformare un nome in un indirizzo IP
2. Chiama un programma local detto **resolver**
3. Se resolver non ha un associazione con il nome interroga il local name server di conosce l'IP
4. Il local name server cerca il nome e se lo trova restituisce l'indirizzo associato altrimenti inoltre la richiesta alla gerarchia DNS.

##### Query ricorsiva vs iterativa

![[Screenshot 2024-08-21 at 15.35.11.png | 270]]                   ![[Screenshot 2024-08-21 at 15.37.27.png |270]]   

##### Caching e aggiornamento record
- Quando un name server ha appreso una informazione la salva in **cache** 
- Dopo un certo tempo (timeout-TTL) vengono cancellati
- Meccanismi update/notifica descritti nella RFC 2136

##### Record DNS
- **name** e **value**
- **TTL** indica quando la risorsa deve essere rimossa dalla cache
- **Type** indica il significato di Name e value
	- A name=hostname | value=IP
	- CNAME name=sinonimo hostname | value=nome canonico host
	- NS name=nome domino | value=hostname authoritative name server 
	- MX name=nome dominio | value=nome canonico server posta associato

### Messaggi DNS
###### Protocollo
- Usa UDP su porta 53 (opzionalmente TCP)
- Formato da messaggi di **query** e **reply** con lo stesso formato

##### Header
- **Identification** 16 bit identification per la query
- **Flags** query si usa 0 e replu si usa 1

##### Body
- **Domande** campi per il nome richiesto e tipo di query
- **Risposte** RR nella risposta alla domanda
- **Competenza** record relativi ai server di competenza
- **Informazioni aggiuntive**

![[Screenshot 2024-08-21 at 15.49.42.png | 350]]

##### DNS Hijacking
Il DNS  è la pratica di restituire risposte non corrette alle query DNS reindirizzando il client verso siti malevoli.
- Local Hijacking
- Router Hijacking
- Rogue Hijacking
- Man-in-the-Middle Attack