Abbiamo un **Problema** quando ci troviamo in una rete. Vogliamo stabilire una comunicazione tra sue host, va quindi capito come:
- trovare il percorso fra sorgente e destinazione
- trasferire delle informazioni dalla porta di ingresso a quella di uscita

Ci sono delle **Tecniche di commutazione**, che sono tecniche per determinare il percorso sorgente-destinazione.

### Commutazioni del circuito (circuit switching)

- Istradamento **avviene una volta per tutte prima della comunicazione** 
- Si usano su percorso risorse alla comunicazione in modo **permanete ed esclusivo**.
- Risorse **garantite per tutta la comunicazione**

###### Frequency Division Multiplexing (FDM)
Frequenze ottiche, elettromagnetiche suddivise in bande di frequenza (strette). Ad ogni comunicazione è assegnata una certa banda.

![[Screenshot 2024-08-19 at 15.06.34.png | 300]]
###### Time Division Multiplexing (TDM) 
Tempo suddiviso in slot di tempo, ogni comunicazione ha uno o più slot periodici assegnati, può trasmettere alla velocità massima di una banda di frequenza (più ampia), ma solo durante i suoi intervalli di tempo.

![[Screenshot 2024-08-19 at 15.06.41.png | 300]]

**Svantaggi**
- Necessaria una fase di instaurazione (setup) della comunicazione.
- Le risorse rimangono inattive se non utilizzate (non c’è condivisione). Ad es. silenzi durante conversazione telefonica
**Vantaggi**
- Performance (garantita)
- Tariffa facile

### Commutazione di pacchetti (packet switching)

###### 1. Il flusso di dati punto-punto viene suddiviso in pacchetti
- Condivisione risorse.
- Pacchetto instradato singolarmente e indipendentemente dagli altri.
- Risorse usate a seconda delle necessità
###### 2. Trasmissione store and forward
- Il router deve ricevere tutto il pacchetto prima di trasmissione (**ritardo di store e forward**)
- Attesa dei pacchetti in code di output (**ritardo per code**)
- Dimensione finita buffer (**perdita pacchetti**).

###### Multiplexing statistico
La sequenza di pacchetti A e B su un collegamento non segue uno schema fisso abbiamo una **condivisione di risorse su richiesta**.
###### Contesa di risorse
La richiesta di risorse può eccedere il quantitativo disponibile. Si crea **congestione** e quindi un accodamento dei pacchetti ed una attesa per l'utilizzo del collegamento.

**Svantaggi**
- Necessità di selezionare l’uscita per ogni pacchetto.
- Ritardi variabili nel percorso end-to-end chiamato **jitter** (tempo di elaborazione ai router (routing table lookup), accodamento ai router).
- Protocolli necessari per un trasferimento dati affidabile, controllo della congestione
**Vantaggi**
- Risorse trasmissive usate solo se necessario.
- Segnalazione non richiesta.