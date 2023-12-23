- **Elementi**:
	- Softare: artefatti. Un artefatto è un’informazione fisica che viene utilizzata o prodotta da un processo di sviluppo software o dal funzionamento di un sistema. Esempio di artefatti includono: codice sorgente, script, file eseguibili binari, la tabella di un database, un deliverable di un progetto, un documento word, un messaggio di posta.
	- Dell’ambiente: hardware. Ambiente di esecuzione.
- **Relazione**. Elemento software allocato a elemento dell’ambiente.
- **A cosa serve **questa vista. Analisi delle prestazioni, guida per l’istallazione.

### Notazione UML per documentare la vista di dislocazione
- Parallelepipedo: denota un nodo hardware o, in generale, un ambiente di esecuzione. 
- Artefatti /sembrano classi con stereotipo \<\<artifact>>)
- La relazione tra nodi hw sono connessioni fisiche o protocolli di comunicazione.
![[Screenshot 2023-11-14 at 23.39.43.png]]

Esempio: diagramma di deployment a vitello di istanza:
![[Screenshot 2023-11-14 at 23.49.14.png]]

Esempio: vista ibrida C&C e deployment, illustrata con un esempio di architettura 3-tier:
![[Screenshot 2023-11-14 at 23.50.06.png]]
### Deployment di componenti
Normalmente si parla di deployment di componenti, mentre in realtà si disloca un artefatto, l’artefatto è una copia di un’implementazione di componente che è stata installata/rilasciata (deployed) su un particolare computer/ambiente di esecuzione.

L’installazione avviene su un ambiente in esecuzione (nodo), l’istallazione comprende la configurazione e la registrazione del componente in tale ambiente. Un artefatto (in questo caso anche chiamato componente installato) \<\<manifesta>> un componente.

Un componente (che esiste a rum-time) è un’instanza creata a partire da un artefatto in un ambiente di esecuzione.

Esempio: **Architettura a livello**
![[Screenshot 2023-11-15 at 00.11.42.png]]
In realtà questo è un concetto ambiguo. A livello di vista C&C può essere una catena di client-server, a livello di vista strutturale invece possono essere vari layers.

Esempio: **Architettura multilivello** 
![[Screenshot 2023-11-15 at 00.13.01.png]]
Ci possono essere da un livello ad N livelli, con l’introduzione di ciascun livello l’architettura guadagna in flessibilità, funzionalità e possibilità di distribuzione. Questo tipo di architettura multilivello potrebbe introdurre un problema di prestazioni, infatti aumenta il costo della comunicazione, e viene introdotta più complessità in termini di gestione ed ottimizzazione.

Esempio: **3 layers, 2 tiers (servizio per la gestione dei tirocini)**
![[Screenshot 2023-11-15 at 00.20.26.png]]
Vista ibrida (C&C e dislocazione) dell’architettura del sotto-sistema di Compilazione, assumendo che gli artefatti che manifestano le componenti citate siano: Compilazione.html, visualizzato da un browser di una macchina client e Compilazione.jsp (dislocata su un web server) e DataBaseTirocini.sql, mantenute su una macchina server.