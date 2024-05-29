## Representational State Transfer (REST)
Originariamente introdotto come stile architettonico, sviluppato come modello astratto dell'architettura Web per guidare la ri-progettazione e definizione di HTTP e URI.

1. **Le risorse sono identificate attraverso un URI:** i servizi espongono un insieme di risorse identificate da un URI.
2. **Interfaccia uniforme**: il client invoca HTTP methods to create/read/update/delete resources
3. **Messaggi auto descrittivi**: le richieste contengono abbastanza informazioni per processare i messaggi. Le risorse sono disaccopiate dalla loro rappresentazione, è possibile accedere da vari formati.
4. **Interazione fra hyperlinks stateful**: ogni interazione con una risorsa è stateful, i server non contengono lo stato del client. 

![[Screenshot 2024-05-27 at 21.26.28.png]]

##### Metologie di design
1. Identificare che devono essere esposte come servizi
2. Modellare relazioni fra risorse con hyperlinks
3. Definire "buoni" URI per indirizzare le risorse
4. Capire cosa vuol dire fare GET/POST/PUT/DELETE per ogni risorsa.
5. Fare il design e la documentazione della rappresentazione delle risorse.
6. Implementare e mettere in deploy su un Web service
7. Testare con un web browser

##### URI design guidelines
- Preferire nomi a verbi
	- NO:      GET /book?isbn=24&action=delete
	- SI:        DELETE /book/24
- Mantenere gli URI corti
- Usare URI templates per costruire e parsare i parametri URI
- Non cambiare URI, eseguire un redirect se necessario

##### PRO
- **Semplicità**
	- bassa curva di apprendimento
	- minima necessità di tools: sviluppare un servizio è simile a costruire un sito web dinamico. Gli sviluppatori possono testare da un web browser ordinario
- **Efficienza**
	- protocollo leggero
	- formato messaggi leggero
- **Scalabilità**
	- un servizio stateless RESTful può servire un grande numero di clients

##### CONTRO
- I dati dei client vengono recuperati in eccesso o in difetto
- Limite al numero di richieste del client
- Convenzioni di denominazioni incoerenti

## OpenAPI
Iniziativa OpenAPI (progetto collaborativo della Linux Foundation) mira a creare un formato di descrizione standardizzato e neutrale rispetto al fornitore delle API REST. 

Il servizio si chiama **Swagger**. Linguaggio di descrizione semplice (basato su JSON) per specificare gli endpoints API HTTP, il modo in cui vengono utilizzati e la struttura dei dati che entra ed esce.

![[Screenshot 2024-05-27 at 21.39.37.png]]
##### Swagger Petstore
Petstore è un esempio classico di specifica OpenAPI
##### OAS Tools
OAS Tools è un ecosistema di strumenti server-side per la creazione di servizi REST compatibili con le specifiche OpenAPI. Sono inoltre presenti tool per la generazione automatica delle specifiche a partire da esempi concreti di risorse.

![[Screenshot 2024-05-27 at 21.49.16.png]]

![[Screenshot 2024-05-27 at 21.49.46.png]]

Un ottimo stile di sviluppo è lo spec first che consente di avere forti garanzie sulla compatibilità del codice nei confronti delle specifiche.

Una volta sviluppata le specifiche OpenAPI è possibile generare lo scheletro di un microservizio in maniera automatica.

Per farlo possiamo usare sempre ```oas-tools init``` specificando questa volta ```server```

Per lanciare il server bisognare entrare nella cartella con la definizione della REST API con yaml e eseguire sul terminale ```npm start```

## Microservices
Riduci i tempi di consegna per nuove funzionalità e aggiornamento. SI accelerano la ricostruzione e la ridistribuzione. SI scala in modo efficace.

Sviluppare applicazione come insieme di servizi:
- Ciascuno in esecuzione nel proprio contenitore di processi.
- Comunicazione con meccanismi leggeri.
- Costruito intorno alle capacità aziendali.
- Decentralizzare la gestione dei dati.
- Dispiegare in modo indipendete.
- Scalabile orizzontalmente
- Resiliente ai guasti.

##### DevOps
Concetto di stessa squadra responsabile del servizio sviluppo distribuzione e gestione.