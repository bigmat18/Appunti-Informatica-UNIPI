Un container sfrutta il sistema operativo e la capacità del kernel di consentire più istanze isolate dello spazio utente.
Pro:
- ambiente più leggero
- più veloce a partire 
Contro:
- Si condivide lo stesso OS

Nel 2013 nasce **Docker** che aggiunge al concetto di container l'idea di immagini portabili e una UI più semplice da usare. È composto da:
- **Docker engine**: per creare ed eseguire il run delle istanze
- **Docker Hub**: per distribuire container

Docker è una piattaforma che ci consente di runnare applicazioni in un ambiente isolato. Ci consente anche di sviluppare e runnare applicazioni portabili sfruttando i container.

- Consente una virtualizzazione container-based 
- Volumi eterni possono essere montati per dati persistenti
### Dockerfile
File contente alcuni di questi comandi che vengono eseguiti in ordine.

![[Screenshot 2024-05-26 at 23.28.38.png]]

```dockerfile
# Ogni containerfile ha sempre come primo comando il from ed il nomde 
# di un immagine da cui partire
FROM node:13-alpine

# Definizione di variabili di ambiente
ENV MONGO_DB_USERNAME=admin \
	MONGO_DB_PWD=password

# Esecuzione comando linux all'interno del container
RUN mkdir -p /home/app

# Copia i file dall'host al container, unico comando che agisce anche sull'host
COPY . /home/app

# primo comando da eseguire quando parte il container
CMD ["node", "/home/app/server.js"]
```

##### Best practices
1. Usare un **immagine di partenza ufficiali** e vicine alle necessità
2. **Evitare di utilizzare il latest**, due build diverse potrebbero avere versioni diverse con cose non supportate.
3. **Ottimizzare la cache** quindi per esempio, prima copia un package.json all'interno e poi installa la roba. Se per esempio si modifica il codice ma non le dipende il comando npm install non verrà preso da cache.

```dockerfile
FROM node

WORKDIR /app

# prima copiamo ed istalliamo, così recupera da cache e non 
# reistalla ogni volta che c'è un aggiornamento
COPY package.json package-lock.json

RUN npm install --production

# a questo punto con aggiornamento non prende da cache
COPY myapp /app

CMD ["node", "src/index.js"]
```

4. Usare il file **.containerignore o .dockerignore** per non prendere alcuni file
5. Usare il **multi-stage builds**, quando ci sono contenuti che servono in build ma non quando l'app gira.

```dockerfile
# build stage
FROM maven AS build
...

# run stage
FROM tomcat
# richiama l'artifact di una immagine precedete
COPY --from=build ...
...
```

6. Usare **utenti con pochi privilegi**. Alcuni immagini hanno già un utente.
```dockerfile
FROM node:10-alpine
...
USER node
```

7. Usare **SCAN con SYNC**, si può configurare in molti repository, o integrarlo co pipeline CI/CD.
### Docker images
I componenti software sono impacchettati dentro **immagini** che consentono un template read-only da creare e runnare su un container.

Sono salvati dentro Docker **registry**
- Registri strutturati in repository
- Ogni repository continete un insieme di immagini per diverse versione del software
- Immagini identificate da **repository:tag**
- **Docker hub**

##### Images commands

```
# build image from dockerfile
docker build -t <image_name> 

# build image from dockerfile without cache
docker build -t <image_name> . -no-cache

# lista immagini locali
docker images 

# delete ad image
docker rmi <image_name>

# remove all ununsed images
docker image prune
```

![[Screenshot 2024-05-26 at 19.52.56.png | 500]]
##### Containers commands
Ricordiamo che i containers sono un immagine di docker runtime. Isolano software dall'ambiente ed assicurano che funzioni uniformemente 
```
# Runniamo e creaiamo un container da un immagine con un nome
docker run --name <container_name> <image_name>

# Runniamo e creaiamo un container in background
docker run --d <image_name>

# Avvia o stoppa un container esistente
docker start|stop <container_name> (o <container_id>)

# Rimuovi un container stoppato
docker rm <container_name>

# Lista container attivi
docker ps

# Lista all docker containers (running and stopped)
docker container stats
```

### Docker compose
Serve ad indicare i vari servizi che devono essere runnati, insieme ad un eventuale volume, o la porta dove esporli se hanno un webserver

```
docker-compose up
docker ps
docker-compose stop
```
### Swarm mode
Docker include la modalità swarm per la gestione di un cluster di host Docker denominato swarm.

![[Screenshot 2024-05-26 at 19.54.28.png | 500]]
I swarm node possono agire come manager (delegando compiti ai lavoratori) ed i workers eseguono le tasks.

È possibile difinire lo stato desiderato di vari servizi nello stack della tua applicazione, incluso il numero di tasks to run in ogni servizio.

I nodi swarm manager assegnano ad ogni servizio nello swarm un nome DNS unico ed un load balancer che runna i container.

Swarm manager nodes monitorano costantemente lo stato del cluster per riconciliare eventuali differenze tra lo stato attuale e lo stato desiderato.

![[Screenshot 2024-05-26 at 20.12.38.png]]

![[Screenshot 2024-05-26 at 20.12.48.png]]
