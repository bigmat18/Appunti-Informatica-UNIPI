## AWS Lambda
- Si può runnare il codice senza fare ne provising ne gestire i servers (**zero amministrazione**). 
- Basta caricare il proprio codice e AWS lambda penserà sia a runnare che a fare scaling con alta disponibilità.
- Puoi far triggerare il codice da altri servizi aws.
- Si paga solo per il tempo di calcolo.
###### Prezzi
![[Screenshot 2024-05-27 at 00.09.25.png | 600]]

Esistono varie opzioni di servizi FaaS, per scegliere dobbiamo basarci o sua una vista più incentrata al **business** oppure una vista più **tecnica**. 

##### Step 1 - Creare ruolo IAM

##### Step 2 - Creare bucket s3

##### Step 3 - Creare la lambda function
Scegliere il ruolo creato e python, dopo ogni modifica ricordare di cliccare deploy
##### Step 4 - Testare la lambda function
Generare un **evento di test**, usando quello di **default**
##### Step 5 -Creare un livello in AWS Lambda
Quando creiamo funzione lambda dobbiamo specificare un Runtime da utilizzare, questo contiene però solo funzionalità di librerie di base.

Per usare utilizzare ulteriori librerie è necessario creare dei **livelli lambda** utilizzati dalle nostre funzioni.

Un livello lambda è un archivio di file con estensione .zip che può contenere codice o dati aggiuntivi. 

Per aggiungere un livello andare su "aggiungi un livello", quindi "livelli personalizzati"

Le funzioni lambda **ricevono in input e rispondono in output oggetti json**

##### Step 6 - Aggiungere trigger
Possiamo far lanciare automaticamente ogni volta che c'è un evento particolare.
Andare su "aggiungi trigger" e scegliere origine s3. Scegliere come tipo "tutti gli eventi di creazioni oggetti". 

Aggiungere un **prefisso** per far in modo che la funzione venga chiamata solo quando viene caricato un file nella cartella plan.

## Business view

##### Licenze
Tutte le piattaforme open source utilizzano licenze permissive come Apache 2.0. Tutti le piattaforme FaaS usano licenze proprietarie. Azure per esempio rilascia alcune dei suoi componenti come progetti open source.

![[Screenshot 2024-05-27 at 17.28.49.png | 500]]
##### Istallazione
Fra le piattaforme commerciali solamente Azure functions ha alcune parte installate in sede. Solitamente le piattaforme sono istallabili in vari host target o Kubernets.

![[Screenshot 2024-05-27 at 17.31.11.png | 500]]
##### Source code
Tutti le piattaforme open source sono hostate su github, e molti componenti sono implementati in Go. Azure functions è l'unica piattaforma commerciale che è parzialmente open source.

![[Screenshot 2024-05-27 at 17.32.50.png | 500]]
##### Interface
Tutte le piattaforme mettono a disposizione una CLI, altre delle API o GUI ma non tutte. Sopratutto le piattaforme open source cambiano molto.

![[Screenshot 2024-05-27 at 17.36.07.png | 700]]
##### Community
Alcuni servizi come OpenFaaS, Apache oenwhisk e Knative hanno un rating molto alto su Github, mentre le domande su Stackoverflow mostrano un interesse diverso fra i servizi commerciali ed open source platform.

![[Screenshot 2024-05-27 at 17.54.31.png]]
##### Documentation
Tutte le piattaforme forniscono una documentazione sia per la parte di deployment che per la parte di piattaforma. La parte delle piattaforme non è sempre documentate sulle piattaforma open source.

![[Screenshot 2024-05-27 at 18.00.20.png]]

## Technical view
##### Development
Java, Node.js e python sono i linguaggi più supportarti, anche docker è diventato abbastanza popolare per usare delle soluzione runtime customizzare. IDE e text editor plugins dono tanti e molto supportati

![[Screenshot 2024-05-27 at 18.02.07.png]]
##### Versioning
- Molte **piattaforme open source** sviluppano un versioning implicito, senza fornire meccanismi dedicati.
- Opposto è per i **sistemi commerciali**.

![[Screenshot 2024-05-27 at 18.08.55.png | 600]]
##### Event sources
- Tutte le piattaforme supportato sincroni, http-based function invocazione, mentre gli eventi asincroni soltanto alcune piattaforme supportano.
- Più della metà delle piattaforme open-source non supportato data store event sources.
- I sistemi di scheduling e stream dei processi è supportata dalla maggior parte delle piattaforme, come anche i sistemi di Messaging.
- Più della metà delle piattaforme viste hanno una documentazione sulla integrazione di custom event.

##### Function orchestration
Più della metà delle piattaforme FaaS supportato l'orchestrazione delle function usano il loro custom DSL, o funzioni di orchestrazione

![[Screenshot 2024-05-27 at 18.14.12.png]]

##### Testing & debugging
La maggior parte delle piattaforme supportato funzionalità di testing e debugging. 
- Solitamente le **piattaforme commerciali** offrono sistemi più sofisticati.
- I **sistemi open source** solitamente hanno sistemi di tests calls e log-based debuggings.
##### Observability
- Le **piattaforme commerciali** offrono tools dedicati per il monitoraggio ed il logging.
- Mentre i **sistemi open source** solitamente utilizzano un integrazioni con sistemi di terze-parti.
![[Screenshot 2024-05-27 at 18.20.46.png]]

##### Application delivery
La maggior parte delle piattaforme seguono un approccio dichiarativo per automaticamente il deployement. Le piattaforme commerciali supportano nativamente CI/CD attraverso tools dedicati.

![[Screenshot 2024-05-27 at 18.23.49.png | 500]]
##### Code reuse
Soltanto AWS Lambda e MS Azure functions offrono un sistema di funzione marketplace.
##### Access management
- Le piattaforme commerciali offrono nativamente sistemi di autenticazione e di controllo dell'accesso alle risorse. 
- Piattaforme open source solitamente offrono questa costa dall'host dell'enviroments per forzare autenticazione e accesso alle risorse. 

#### Vendor lock-in
Il **vincolo del fornitore** crea un cliente dipendente da un fornitore per prodotti o servizi, impossibile utilizzare un altro fornitore senza sostanziali costi di conversione.


