###### IoT + Edge
- **PRO**
	- Bassa latenza
- **CONTRO**
	- Limitata capacità di processing e storage

###### IoT + Cloud
- **PRO**
	- Capacità illimitata di processing e storage
- **CONTRO**
	- Alta latenza
	- Moltissimi dati trasferiti
	- Connettività internet obbligatoria

L'idea quindi dietro il cloud-edge continuum è quello di estendere il cloud attraverso l'IoT con **infrastrutture distribuiti ed eterogenee**.  In questo modo prendiamo il meglio di tutte e due i mondi.
- Potenza di calcolo
- Connettività
- Buona latenza

Come posizionare adeguatamente un'applicazione composita nel continuum Cloud-Edge?
Richieste a livello **applicativo**:
- Hardware
- Software
- QoS
- Data awareness
- Security and trust
- ...

Richieste a livello di **infrastruttura**
- Eterogeneo
- Grade
- Dinamico

![[Screenshot 2024-05-28 at 18.55.11.png | 600]]

Bisogna masterare le dimensioni ortogonali

![[Screenshot 2024-05-28 at 18.56.22.png | 400]]

Approcci per application placement:
- **ML**
- **MILP**
- **Declarative programming**: facile da leggere, facile da codificare informazioni non numeriche, spiegabili.e


Le cose cambiano in maniera costante. Lato **infrastruttura**
- Il carico dei nodi cambia
- Latency e bandwidth 
- Nodi possono essere aggiunti e tolti
- Nodi e container possono fallire
- ...

Ed anche a livello **applicazione**
- La codebase cambiano
- I requirements possono cambiare
- ...

Per sostenere questo servono vari strumenti.
##### Monitoring
Necessario sia per monitorale la parte applicativa che infrastrutturale.
##### Continuous reasoning
Analisi differenziale concetrandosi sugli ultimi cambiamenti, riutilizzare i risultati precedentemente calcolati per sostituire/migrare, riavviare, scalare i servizi applicativi.

