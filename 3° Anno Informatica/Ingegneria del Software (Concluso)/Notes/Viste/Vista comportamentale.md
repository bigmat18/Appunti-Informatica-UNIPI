### Componenti software
Una componente software è un'unità di software indipendente e riusabile che esegue una specifica funzione o compito all'interno di un'applicazione più ampia. È un’unità concettuale di decomposizione di un sistema a tempo d’esecuzione.
Per esempio: processo, oggetto, servizio, deposito di dati, ...
Incapsula un insieme di funzionalità e/o di dati di un sistema. Restringe l’accesso a quell’insieme di funzionalità e/o dati tramite delle interfacce definite ed ha un proprio contesto di esecuzione.
Può essere distribuito e installato in modo (possibilmente) indipendente da altri componenti

Un sistema software è una composizione di componenti software. La composizione è basata sulla “connessione” di più componenti realizzata sulla base delle interfacce dei componenti e mediante l’ausilio di connettori.

![[Screenshot 2023-10-25 at 10.36.25.png]]
### Porti
I porti identificano i punti di interazione di un componente, un componente può avere più porti, uno per ogni tipo di connessione con altri componenti. Un porto fornisce o richiede una o più interfacce (omogenee).
UML: un porto è rappresentato con un «quadratino», può avere un nome e/o avere associata una molteplicità con l’usuale sintassi (1..n).

![[Screenshot 2023-10-25 at 10.38.30.png]]

Le interfacce sono descritte in modo sintetico con lollipop e forchette oppure in modo esteso, per mostrare le operazioni richieste/offerte.
![[Screenshot 2023-10-25 at 10.41.01.png]]
### Connettori
I connettori sono canali di interazione tra componenti che collegano i porti: protocolli, flussi d’informazione, accessi ai depositi,…
I connettori collegano i porti, in UML i connettori non hanno un descrittore specifico, si modellano con un’associazione. Aggiungiamo informazione sul protocollo di comunicazione descritto sinteticamente indicando li stile della connessione (stile di quel frammento di architettura). 

![[Screenshot 2023-10-25 at 10.43.30.png]]

**Esempio**
![[Screenshot 2023-10-25 at 10.43.58.png]]
## Stili (o schemi) archittetturali
Uno stile è una proprietà di una architettura. Uno stile caratterizza una famiglia di architetture con caratteristiche comuni.
- Stile a macchine virtuali: i moduli definiscono macchine virtuali.
- Stile client-server: caratterizzato da articoli interazioni tra componenti.

Le funzionalità di componenti interagenti e le caratteristiche delle interazioni tra componenti spesso rispondono a stili (schemi) standard.
Nella vista C&C uno stile architetturale è caratterizzato da:
- caratteristiche generali delle componenti in gioco.
- particolari interazioni tra le componenti, e quindi dalle caratteristiche dei porti e dei connettori.
Vedremo gli stili di uso comune con le loro caratteristiche ed un modo per documentarli.
### Pipe e filtri
- COMPONENTI: sono di tipo filtro: trasformano uno o più flussi di dati dai porti d’ingresso in uno o più flussi sui porti d’uscita.
- CONNETTORI: sono di tipo condotta (pipe): canale di comunicazione unidirezionale bufferizzato che preserva l’ordine dei datI dal ruolo d’ingresso a quello d’uscita.
- USI: pre-elaborazione in sistemi di elaborazione di segnali ◦ analisi dei flussi dei dati, e.g. dimensioni dei buffer.

![[Screenshot 2023-10-25 at 10.51.20.png]]

**Esempio**.
![[Screenshot 2023-10-25 at 10.53.25.png]]

**Esempio** (con biforcazione)
![[Screenshot 2023-10-25 at 10.53.51.png]]

Esempio della composizione Split (push vs pull)
![[Screenshot 2023-10-25 at 10.55.47.png]]
### Stile client-server
Il sistema è formato da due componenti: il client ed il server. Spesso, ma non necessariamente, eseguiti su macchine diverse collegate in rete.
![[Screenshot 2023-11-05 at 20.29.51.png]]

Il server svolge le operazioni necessarie per realizzare un servizio: ad esempio gestisce una banda dati, o gestisce l’aggiornamento dei dati e la loro integrità. Esse aspetta le richieste dei client a un porto (ci possono essere tanti client), un client invia al server le richieste ed attende una risposta.
![[Screenshot 2023-11-05 at 20.32.37.png]]

Per realizzare un architettura client server bisogna lato server: uno (o più) thread in sconto delle richieste, più un gestore delle richieste.
Quando riceve una richiesta, il server la elabora e invia una risposta al client. I server possono essere ulteriormente classificati come statelesi o stateful. 
I client di un server stateful possono fare richieste composite che consistono in più richieste atomiche. Ciò consente un’interazione più colloquiale o transizione tra client e server. A tal fine, un server stateful conserva un record delle richieste di ciascun client corrente. Questo record è chiamato sessione.

### Stile master-slave
Un caso particolare del client-server, ma risponde a esigenze diverse.

![[Screenshot 2023-11-05 at 20.33.18.png]]

Il servente (slave) serve un solo cliente (master). Architettura usata per esempio nelle replica di database, il database master è considerato come fonte autorevole e i database slave sono sincronizzati con esso.
### Stile P2P (peer to peer)
È uno stile che è letteralmente da pari a pari. È un caso particolare di client-server, tutti i componenti agiscono sia da client che da server. Per esempio i programmi di scambio audio e video. Lo scambio di servizi avviene quindi alla pari.

![[Screenshot 2023-11-05 at 20.38.43.png]]

C’ una sola componente nello schema perché i per sono tutti sue istanze.
![[Screenshot 2023-11-05 at 20.38.53.png]]
### Stile PUBLISH-SUBSCRIBE
I componenti interagiscono annunciando eventi: un componente si “abbona” a classi di eventi rilevanti per il scopo, ciascuna componente, volendo, può essere sia produttore che consumatore di eventi. 
Disaccoppi produttori e consumatori di eventi e favorisce le modifiche dinamiche del sistema

Un componente può essere in generale sia Publisher che Subscriber. Due diversi connettori, uno per le richieste di sottoscrizione e per richieste di pubblicazione, uno per diffondere i dati.

![[Screenshot 2023-11-05 at 20.42.56.png]]

Publisher e Subscriber possono essere componenti distinte (Notify in modalità push)
![[Screenshot 2023-11-05 at 20.43.43.png]]

In questo stile, mittenti e destinatari di messaggi dialogano attraverso un tramite, che detto dispatcher o broker. Il mittente di un messaggio (detto Publisher) non deve essere consapevole dell’identità dei destinatari (detti subscriber); esso si limita a “pubblicare” (to publish) il proprio messaggio al dispatcher.

I destinatari (subscribers) si rivolgono a loro volta al dispatcher “abbonandosi” (to subscribe) alla recensione di determinati tipi di messaggi. In generale, il meccanismo di sottoscrizione consente ai subscriber di precisare nel modo più specifico possibile a quali messaggi sono interessati. Per esempio, un subscriver potrebbe “abbonarsi” solo alla ricezione di messaggi da determinati publisher, oppure aventi certe caratteristiche.

Il dispatcher inoltra ogni messaggio ricevuto da un publisher a tutti i subscriber interessati ai messaggi di quel tipo. Questo schema implica che ai publisher non sia noto quanti e quali sono i subscriver e viceversa. Questo può contribuire alla scalabilità del sistema.

La diffusione può avvenire anche in modo pull:
![[Screenshot 2023-11-05 at 20.53.38.png]]
### Modello PUSH o PULL ?
- Modello Push: 
	- Il broker invia attivamente i messaggi ai consumatori
	- È complicato per il broker trattare con diversi tipi di consumatori, in quanto controlla la frequenza con cui i dati vengono trasferiti.
	- Deve decidere se inviare un messaggio immediatamente o se accumulare più dati e inviare.
- Modello Pull:
	- Il consumatore si assume la responsabilità di recuperare i messaggi del broker. 
	- Il consumatore deve mantenere un valore che identifica il prossimo messaggio successivo da trasmettere ed elaborare.
	- Pro: migliore scalabilità (minore onere per i broker) e flessibilità (consumatori diversi con esigenze e capacità diverse)
	- Contro: nel caso in cui i broker non disponga di dati, i consumatori potrebbero essere occupati in attesa dell’arrivo dei dati.
### PUBLISH-SUBSCRIBE: middleware
- Per delle **reti** possono essere comunicazioni multicast con algoritmi di flooding
- **Advanced Message Queuing Protocolli (AMQP)** è un protocollo che realizza sia comunicazioni punto-a-punto che push-and-subscribe. Un esempio è **RabbitMQ** che è un middleware di messaggistica open-source basato su AMQP. Supporta la pubblicazione e la sottoscrizione di messaggi ed è ampiamente utilizzato per l’implementazione di architetture publish-subscribe.
- **Message Queuing Telemetry Transport (MQTT)**: MQTT è un protocollo ISO standard di messaggistica leggero, posizionato in cima a TCP/IP.
- **Apache Kafka:** Kafka è una piattaforma open-source di streaming distribuita che offre supporto per l’elaborazione di eventi in tempo reale e la trasmissione di dati tra applicazioni.
### PUBLISH-SUBSCRIBE: DDS
Il DDS (Data Distribuito Service) è un middleware standardizzato basato su paradigma pubish-subsctibe, che aiuta lo sviluppo di livello middleware per la comunicazione machine-to-machine.

È parte integrante di molti sistemi embedded e di applicazioni con requisiti in tempo reale. Mantenuto dall’Object Management Group (OMG), 7 DDS è utilizzato in tutte le classi di applicazioni critiche per implementare un livello di comunicazione affidabile tra sensori, controllori e attuatori. Usato per esempio da NASA, siemens per gli impianti eolici, Volkswagen e Bosch per i sistemi di parcheggio autonomo.

Dal punto di vista del programmatore, DDS è un Application programmino interface (API). Supporta sterilizzazione e deserializzazione dei qualsiasi tipo di dati built-in o custom attraverso un linguaggio di definizione dell’interfaccia (IDL) dedicato.

### Stile MODEL-VIEW-CONTROLLER (MVC)
Stile in cui si isola la logica di business dal controllo sull’input e dalla presentazione (vista sui dati), consentendo sviluppo indipendente, test e manutenzione di ciascuno.

- **Modello:** Il modello fornisce il nucleo funzionale di un’applicazione, ed è rappresentazione del modello dei dati su cui opera l’applicazione. Quando un modello cambia il suo stato, notifica le sue viste associate in mode che possano aggiornare: notifica alle viste la modifica dei dati; le viste recuperano le informazioni (e le mostrano all’utente).
- **Vista**: Rendere il modello in una forma adatta all’interazioni, in genere un elemento dell’interfaccia utente. Ci possono essere più viste per un singolo modello, per scopi diversi.
- **Controllore**: Riceve l’input ed effettua chiamate agli oggetti del modello. I controllori traducono gli eventi in richieste per eseguire operazioni sugli elementi del modello.

![[Screenshot 2023-11-14 at 18.02.01.png]]

1. L’utente interagisce con la vista.
2. Il controller riceve le azioni dell’utente e le interpreta (ess. Se si va un clic su un pulsante, è compito del controllore capire che cosa significhi e come il modello dovrebbe essere manipolato in base a tale azione). 
3. Il controller chiede al modello di cambiare il suo stato.
4. Il modello notifica la vista quando il stato è cambiato. Quando qualcosa cambia nel modello, in risposta a qualche azione (es. fare clic su un pulsante) o per altri motivi (es. è iniziato il brano successivo nella playlist) i modello notifica alla vista che il suo stato è cambiato.
5. La vista chiede lo stato al modello. Per esempio, se il modello notifica la vista che è iniziato un nuovo brano, la vista richiede il nome del brano al modello e lo mostra.

![[Screenshot 2023-11-14 at 18.02.30.png]]
### MODEL-VIEW-CONTROLLER vs MODEL-VIEW-PRESENTER

![[Screenshot 2023-11-14 at 18.03.16.png]]

### Stile: coordinatore di processi
È uno stile di progettazione software che prevede l’uso di un componente dedicato noto come “coordinatore” o “process coordinator”. Il coordinatore conosce la sequenza di passi necessari per realizzare un processo. Riceve la richiesta, chiama i servers secondo l’ordine prefissato, fornisce una risposta.
Normalmente usato per realizzare processi complessi com per esempio un disaccoppiamento: i server non conoscono il loro ruolo nel processo complessivo né l’ordine dei passi del processo, Ogni server semplicemente definisce un servizio.