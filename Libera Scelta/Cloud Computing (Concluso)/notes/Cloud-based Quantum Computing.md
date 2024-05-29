L'investimo in quantum computing è una strategia mossa verso una prospettiva a lungo termine. I quantum computer hanno il potenziale di rivoluzionale varie industrie per risolvere problemi complesi essendo esponenzialmente più veloci dei computer classici.

Per esempio ci sono alcuni problemi:
- **Fattorizzazione**: Classico è esponenziale, Quantistico è $O(\log N)$ 
- **Ricerca**: Classico è $O(\sqrt{n})$ mentre, Quantistico è $O(n)$

I computer quantistici possono risolvere vari problemi **esponenzialmente più veloce** rispetto ad i computer tradizionali.

I computer quantistici funzionano tramite il concetto di **superposition** e **entaglement** e tramite i **qubits**, che essenzialmente sfruttano i principi della meccanica quantistica per fornire un nuovo modo di rappresentare ed elaborare le informazioni, promettendo vantaggi significativi per la risoluzione di problemi specifici rispetto al calcolo classico.

Concettualmente un **qubit** è l'unità fondamentale dell'informazione quantistica. A differenza del classico bit, il suo stato può essere 0 o 1 o una sovrapposizione (cioè una combinazione lineare) di entrambi. Quando eventualmente eventualmente osservato lo stato di un qubit collasserà solo negli stati semplici 0 e 1 con probabilità diverse a seconda della sua sovrapposizione.

![[Screenshot 2024-05-28 at 20.33.36.png | 600]]

I qubit possono essere entagled, il che significa che lo stato di un qubit diventa direttamente correlato lo stato di un altro, non importa quanto siano distanti.

Diversi qubit dovrebbero essere collegati "fisicamente" per poter eseguire un multi-qubit operazione tra tali qubit. Esistono diversi modi (topoogie) in cui possiamo connettere i qubit

![[Screenshot 2024-05-28 at 20.46.03.png | 700]]

Possiamo eseguire codice su un **quantum computer in cloud**.

Dopo l'esecuzione di un circuito quantistico lo stato del quanto è solitamente in sovrapposizione di più stati finali.

Sfortunatamente le leggi fisiche ci impediscono di **osservare** direttamente lo stato quantistico.
Possiamo solo **misurare** lo stato quantistico, quando si fa ciò esso si riduce ad un singolo output statistico.

Possiamo eseguire lo stesso circuito per lo stesso input numerose volte (dette **shots**) per **approssimare il reale stato quantistico della distribuzione**.

**NISQ era**: Noisy, Intermediate, Scale Quantum

NISQ devices: molto sensibili alle interferenze esterne, non possono scalare la loro dimensione (numero di qubit)

Le conseguenze sono che possiamo eseguire solo quantum program che usano un piccolo numero di qubits e consecutive steps

Ci sono alcune limitazioni attuali nei quantim computers:
- L'affidabilità
- La scalabilità
- I costi

Alcuni limitazioni attuali dello sviluppo software quantistico
- Combina ancora principalmente porte di basso livello in circuiti
- Interoperabilità software/macchine limitata
- Scarso support per l'intero ciclo di vita del software

![[Screenshot 2024-05-28 at 23.01.42.png]]
![[Screenshot 2024-05-28 at 23.01.54.png]]
###### Introdurre un broken
![[Screenshot 2024-05-28 at 23.02.10.png]]
**Calibration**: eseguire un insieme di circuiti semplici per stimare l'affidabilità per ogni QM

###### Splitting shots
![[Screenshot 2024-05-28 at 23.03.25.png]]
Si può spolittare in maniera uniforme, random, noise-aware e cost-aware

###### Joining results
![[Screenshot 2024-05-28 at 23.04.05.png]]
