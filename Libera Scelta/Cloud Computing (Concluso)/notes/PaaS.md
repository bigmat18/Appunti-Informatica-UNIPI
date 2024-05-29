Un provider di terze parti si occupa dell'hardware e del software per il development dell'applicazione. L'utente si occupa solo dell'applicazione e dei dati.
**Vantaggi**
- Meno gestione della infrastruttura
- Mantenimento automatico
- Facile load balancing, scaling, distribution of services.
- Facile cambiare tecnologie ed offerte.
**Rischi**
- Disponibilità dei servizi
- Vendor lock-in
- Cambiamenti interni nel PaaS

## Heroku
Heroku è una piattaforma cloud basata su un contenitore gestito sistema, con servizi dati integrati e un potente ecosistema, per la distribuzione e l'esecuzione di app moderne.
### Dynos
Heroku utilizza dei containers chiamati **dynos** per runnare e scalare le applicazioni Heroku. I dynos sono isolati, sono dei container Linux virtuali progettati per eseguire codice basato sulle esigenze ed i comandi degli utenti
- Le app scalano in nessun numero specifico di dynos
- Facile per gli utenti scalare e gestire il numero, la dimensione ed i tipi di dynos per le app.
Fare il deploy su i dynos rende facile buildare e runnare app scalabili.

Esistono vari tipi di dynos che è possibile scegliere.
![[Screenshot 2024-05-27 at 18.57.42.png]]

I dynos standard supportano la scalabilità.
I performance dynos supportano scalabilità e autoscaling.
### Buildtime
Per fare il deploy di un app, Heroku ha bisogno solo di 3 cose da un utente
- codice sorgente
- lista dipendeze
- Procfile

Il sistema di build è automatizzato
1. Viene ricevuto il codice
2. Fetch di un buildpack, language runtime, e code dependencies.
3. Produce uno slug (un insieme di source, dependecies, runtime, output che viene inserito dentro un dyno e runnato in un app)

### Runtime
Quando distribuisci o ridimensioni la tua app, Heroku lo farà creando automaticamente uno o più dynos, ciascuno con lo stesso stack e slug che rappresentano la tua app. 
Il Dyno Manager di Heroku esegue quindi i comandi forniti nel file di configurazione per avviare l'applicazione in esecuzione su Heroku.

![[Screenshot 2024-05-27 at 18.57.15.png | 700]]
1. Applicazione riceve una richiesta.
2. La richiesta viene inviata ad un random Web dyno
3. La richiesta viene messa in una queue
4. Worker dyno prende in esecuzione la richiesta e la esegue, il risultato può persistere in un database.

### Add-ons
È possibile aggiungere add-ons di terze parti, che gli sviluppatori possono usare immediatamente per estendere le loro apps con funzionalità di stores, logging, monitoring ed altro.

## Firebase
