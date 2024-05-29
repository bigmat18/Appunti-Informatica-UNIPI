I contenitori forniscono un meccanismo leggero per isolare un file l'ambiente di un applicazione. Le immagini dei contenitori possono essere eseguite in modo affidabile su qualsiasi macchina, fornendoci portabilità dallo sviluppo alla distribuzione.

È possibile posizione più carichi di lavoro sullo stessa macchina fisica, ottenendo risorse più elevate (memoria e CPU utilizzata)

### Container orchestration
Il direttore di un'orchestra gestisce la **visione** per una performance musicale e **comunica** con i musicisti per **coordinare** il loro strumento individuale per ottenere una composizione completa.

Un architetto di un sistema semplicemente **componse la musica** (definisce i contenitori che devono runnare) e successivamente prende il controllo della direzione dell'orchestra per ottenere la vision.

Kubernets fa proprio questo con i container. K8 gestisce l'intero lifecycle di un container individuale, avviando e spengendo le risorse necessarie.

K8 inoltre mette a disposizione un meccanismo per le applicazioni per comunicare con le altre anche se i singoli contenitori sottostanti vengono creati e distrutti. 

Dato un insieme di carichi di lavoro del contenitore da eseguire ed un insieme di macchine su un cluster, l'agente di orchestrazione del contenitori esamina ogni contenitore e determina la macchina ottimale dove schedulare il carico di lavoro.

## K8 principi di design

#### Dichiaratività
Andiamo a definire in maniera semplice lo **stato desiderato** del nostro sistema

K8 rileva quando lo stato attuale del sistema non soddisfa le nostre aspettative ed interviene per risolvere il problema rendendo il nostro sistema in grado di auto ripararsi.

Lo stato desiderato è definito da una raccolta di oggetti
- ogni oggetto ha una specifica in cui si fornisce lo stato desiderato e uno stato che riflette lo stato corrente dell'oggetto.
- K8 interroga costantemente ciascun oggetto per garantire che il suo stato sia uguale alle specifiche.
- Se un oggetto non risponde, K8 avvierà una nuova versione per sostituirlo.
- Se lo stato di un oggetto si è discostato dalle specifiche K8 emetterà i comandi necessari per riportare l'oggetto allo stato desiderato.
#### Distribution
K8 mette a disposizione una interfaccia unificata per interagire con un **cluster di macchine**. Senza che non ci preoccupiamo di comunicare con ogni macchina individualmente.

![[Screenshot 2024-05-27 at 22.26.47.png]]
#### Decoupling
I containers possono essere sviluppata utilizzano una architettura a micro-servizzi. 
K8 supporta naturalmente l'idea di **decomporre servizi** i quali possono scalare ed aggiornare in maniera indipendete.
#### Infrastrutture immutabili
Per ottenere il massimo dai contenitori e dall'orchestrazione dei contenitori, dovremo fare il deploy su **infrastrutture immutabili**.

Durante il ciclo di vita di un progetto (sviluppo - test - produzione) noi dovremmo utilizzare la stessa immagine del contenitore (e modificare solo le configurazioni esterne all'immagine del contenitore ad esempio montando un file di configurazione).

I contenitori sono progettati per essere effimeri, pronti per essere sostituiti da altre istanze di contenitore in qualsiasi momento.

Il mantenimento di un'infrastruttura immutabile semplifica il rollback delle applicazioni allo stato precedente (per esempio se si verifica un errore). Possiamo semplicemente aggiornare la nostra configurazione per utilizzare un'immagine contenitore precedente.

## K8 objects
Gli oggetti K8 possono essere definito in un **manifest** (YAML o JSON)

![[Screenshot 2024-05-27 at 22.38.26.png | 400]]
#### Pod
Un **Pod** cosiste in
- 1 o più container
- Un layer di network condiviso
- Un filesystem condiviso

![[Screenshot 2024-05-27 at 22.39.38.png | 400]]
#### Deployment
Un oggetto di **deployment** include un insieme di Pods definite da un template e un contatore di repliche (numero n di quante copie di un template vogliamo in run).

![[Screenshot 2024-05-27 at 22.40.53.png | 500]]

Il cluster proverà sempre ad avere n Pods available. Esempio di caso di 10 instanze di un container con un servizio di ML e sopra un REST interface.

![[Screenshot 2024-05-27 at 22.42.19.png | 500]]
#### Service
Ad ogni Pod è assegnato un indirizzo IP unico che possiamo utilizzare per comunicare con esso.

K8 **service** mette a disposizione un endpoints stabile per indirizzare il traffico al pods desiderati anche se gli esatti pod sottostati cambiano a causa di aggiornamenti, ridimensionamento, errori.

I servizi sanno a quali pod devono inviare il traffico in base alle etichette (coppie chiave-valore) che definiamo nei metadati del pod.

![[Screenshot 2024-05-27 at 22.45.32.png]]

Esempio di servizio wrappato intorno l'esempio di distribuzione precedente.

![[Screenshot 2024-05-27 at 22.46.09.png | 600]]
#### Ingress
Il servizio ci consente di esporre applicazioni dietro un endpoints stabile, soltanto disponibile all'interno di un cluster.

Per esporre la nostra applicazione al di fuori del cluster abbiamo bisogno di definire un **ingress** object. Possiamo con questo seleziona quale servizio mettere pubblico.

![[Screenshot 2024-05-27 at 23.04.58.png | 600]]

Esempio basato su quello di prima.

![[Screenshot 2024-05-27 at 23.05.26.png | 500]]
## K8 control plane

### Master node
(Spesso singolo) Una macchina che contiene la maggior parte del piano di controllo dei componenti.
#### API server e ETCD
Un utente può richiedere new/update object ad un **API Server** del master node
- API server valida le richieste di update e funge da interfaccia unificata per domande su lo stato attuale del cluster.
- Lo stato del cluster è archiviato in un archivio di chiave-valore distribuito chiamato **etcd**.

![[Screenshot 2024-05-27 at 23.09.59.png | 400]]

##### Scheduler
Lo **scheduler** determina dove gli oggetti devono runnare.
- chiede al API server quali oggetti devono essere assegnati ad una macchina
- determina quali macchine tali oggetti dovrebbero essere assegnati.
- risponde al server API per riflettere questa assegnazione.

![[Screenshot 2024-05-27 at 23.09.42.png | 600]]

##### Controller manager
Il **controller-manager** monitora lo stato dei cluster attraverso API server.
Se los tato attuale è differente dallo stato desiderato, il controller-manager effetture i cambiamenti attraverso l'API server per guidare il cluster verso lo stato desiderato.

![[Screenshot 2024-05-27 at 23.12.43.png | 500]]

### Worker node
Macchine che runnano il workload della applicazioni.
##### Kubelet
- Agisce come "agente" di un nodo con cui comunica il server API per vedere quali carichi di lavoro del contenitore sono stati assegnati al nodo.
- Responabile dell'attivazione dei pod per eseguire i workload assegnati.
- Quando un nodo si unisce al cluster per la prima, kubelet annuncia l'esistenza del nodo al API server così lo scheduler può assegnarli i pod.

![[Screenshot 2024-05-27 at 23.16.28.png | 400]]

##### Kube-proxy
I kube-proxy permettono ai containers di comunicare fra di loro attraverso i vari nodi di grappolo.

![[Screenshot 2024-05-27 at 23.17.48.png | 700]]

## Minikube
Minikube è uno strumento che consente di eseguire Kubernets localmente. Esegue un cluster kubernetes locale **all-in-one** (cioè su un solo nodo) o **multi-node** su nostro computer in modo da provare kubernets o per lo sviluppo quotidiano.

Minikube ha un ambiente docker interno, le immagini e i container presenti nel nostro sistema sono diversi da quelli al suo interno

```
minikube start --nodes <number_of_nodes>

minikube stop

minikube delete

minikube image load <image>

minikue service list

minikube kubecli -- <command>

# per entrare in una shell con cui interagie con i container
minikube ssh
```

##### K8 comandi utili
```
# mostra lo stato delle risorse (pods, nodi, servizi) con all tutte le risorse
kubectl get <resource> (all)

# crea o aggiorna una risorsa da .yaml
kubectl apply -f <manifest.yaml>

# rumove ogni cosa dal nodo <node_name>
kubeclt drain <node_name> [--ignore-daemonsets]

# segna il nodo <node_name> come schedulabile
kubeclt uncordn <node_name> 

# rimuove <resource>, con pod prima elimi pod
kubectl delete (pod) <resource>

# otteniamo info sul pod
kubectl logs <nome_pod>

# consente di avere numerose informazioni sul pod (come IP interno)
kubectl describe pod <nome_pod>
```

##### Creare un primo Pod
![[Screenshot 2024-05-28 at 20.59.05.png | 400]]
##### Lanciare più repliche

![[Screenshot 2024-05-28 at 16.52.51.png | 400]]
1. Per lanciare questo deployment con 2 repliche basta
	```kubectl apply -f NOME_FILE```
	
2. Vedere il contenuto con
	```kubectl get deployment```
	
3. Osservare i pod presenti con 
	```kubectl get pod```

##### ReplicaSet
Se runniamo il comando ```kubectl get all``` vediamo che sia stato creato anche un **ReplicaSet** per il nostro Deployment. Il suo scopo è mantenere un insieme stabile di repliche di un Pod in esecuzione in qualsiasi momento. 

Viene speso utilizzando per garantire la disponibilità di un numero specifico di Pod identici. Un deployment gestisce i ReplicaSet e fornisce aggiornamenti dichiarativi ai Pod insieme a molte altre utili funzionalità.

Per eliminare tutto basta lanciare (sia i pod, che il deployment ReplicaSet)
```kubectl delete deployment,rs,pod -all```

Il deployment con il ReplicaSet garantisce che anche in caso di terminazione di una o più repliche altrettante vengano create per rispettare i desideri dell'utente. Un Pod da solo non ci da questa garanzia.

##### Node drain
1. Quando un nodo viene "drenato" Kubernets termina tutte le pod in esecuzione su quel nodo, e ne pianifica il riavvio altrove nel cluster
2. Questa operazione è utile quando è necessario mettere offline un nodo per manutenzione o per altre ragioni, garantendo che le applicazioni in esecuzione su di esso vengano trasferite altrove prima di interrompere il nodo.
3. Un nodo può essere drenato manualmente utilizzando il comando ```kubectl drain``` specificando il nome del nodo come argomento.
##### Node Uncordon
1. Quando un nodo è "sbloccato" significa che è stato ripristinato alla piena capacità di accettare nuove pod.
2. Un nodo può essere messo in uno stato uncordoned manualmente utilizzando il comando kubectl uncordon seguite dal nome del nodo come argomento.
3. Dopo che un nodo è stato uncordoned, Kubernets può quindi pianificare nuove pod su di esso.

"node drain" è utilizzato per spostare i pod da un nodo prima di metterlo offline, "node uncordon" è utilizzato per consentire a un nodo di accettare nuovi pod dopo essere stato messo offline o aver completato la manutenzione.

##### Servizi
Attualmente per acceder alla nostra applicazione dobbiamo conoscere l'IP di uno specifico Pod ed interagire direttamente con esso. Inoltre se un Pod non è più disponibile va usano un nuovo IP di un altro po, inoltre **non accessibile al di fuori** del cluster.

Con un servizio possiamo accedere ai nostri pod sia **all'interno che all'esterno** di un servizio, senza inoltre dover specificare un particolare Pod.

1. Procediamo con apply
2. Poi lanciamo ```kubectl exec -it bash -- /bin/bash``` che permetterà di aprire una shell bash all'interno del container.
3. All'interno della bash eseguire ```apt update && apt install dnsutils curl``` per installare dei tool che ci serviranno
4. Utilizzare ora curl per accedere al deployment all'indirizzo ```IP_POD:9876/health```

Con i Servizi possiamo **disaccoppiare** l’acceso ad un deployment evitando di dover specificare un Pod specifico ed il relativo IP.

![[Screenshot 2024-05-28 at 18.17.41.png | 400]]

1. Per lanciare questo servizio basta usare il comando apply
2. Una volta fatto tramite la bash creata precedentemente eseguire il comando ```nslookup NOME_SERVIZIO```
3. Eseguiamo ora ```IP_SERVIZIO/health```

![[Screenshot 2024-05-28 at 18.19.22.png | 500]]

Accediamo ora al servizio da esterno

![[Screenshot 2024-05-28 at 18.20.01.png | 500]]

![[Screenshot 2024-05-28 at 18.20.14.png | 500]]

Ora non resta che lanciare l’Ingress con apply e ottenere l’IP del nostro cluster con ```minikube ip```
Adesso possiamo accedere al nostro servizio e quindi al nostro deployment (che gestisce le repliche del nostro Pod) dall’esterno all’IP del cluster e con la porta che abbiamo specificato nel manifesto.