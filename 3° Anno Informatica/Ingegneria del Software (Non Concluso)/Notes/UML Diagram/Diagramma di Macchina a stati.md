Una macchina a stati è un grafo stati transizioni che descrive il comportamento delle istanze di una classe, in generale di un classificatore. 

Occorre individuare gli stati significativi in cui si può trovare un oggetto durante la sua vita.
Inoltre dobbiamo descrivere come da ciascuno di questi stati l’oggetto può passare (transire) in un altro.

Le transizioni avvengono in risposta al verificarsi di un evento. Esempio di eventi: messaggi inviati da altri oggetti, eventi generati internamente.

<u>Sintassi:</u>
![[Screenshot 2023-10-19 at 12.31.30.png]]
### Transizione
L’uscita da uno stato definisce la risposta dell’oggetto all’occorrenza di un evento. Viene presa solo se la condizione è vera quando occorre l’evento, comporta l’esecuzione delle azioni specificate.

![[Screenshot 2023-10-19 at 12.32.49.png]]
### Evento
Un evento occorre istantaneamente, gli eventi che occorrono quando l’oggetto è in uno stato per cui non è previsto alcuna transizione etichettata con quell’evento vengono ignorati. È ammesso il non-determinismo, un evento può fare da frigger a più transizioni che escono dallo stesso stato. 

Tipi di evento:
- **Operazione o segnale \[ op(a:T) \]:** la transizione è abilitata quando l’oggetto (in quello stato) riceve una chiamata di metodo / un segnale con parametri (a) e tipo (T) (i parametri sono opzionali).
- **Evento di variazione \[ when(export) \]**: la transizione è abilitata appena l’espressione diventa vera. L’espressione può indicare un tempo assoluto o una condizione.
- **Evento temporale \[ after(time) \]**: la transizione è abilitata dopo che l’oggetto è stato fermo "time" in quello stato
### Segnali
![[Screenshot 2023-10-19 at 12.42.23.png]]
### Eventi di variazione ed eventi temporali
![[Screenshot 2023-10-19 at 12.49.05.png]]
### Entry, Exit, Transazione ed attività interne
- **Azione di entrata:** eseguita all’ingresso in uno stato
- **Azione di uscita:** eseguita all’uscita di uno stato
- **Transizione interna:** risposta ad un evento
- **Attività interna (Do-activity):** eseguita in modo continuato mentre l’oggetto si trova in quello stato, senza necessità di un evento scatenante, al contrario di tutte le altre azioni che sono atomiche: consuma del tempo, può essere interrotta (quando un evento fa uscire dallo stato)

![[Screenshot 2023-10-19 at 12.53.40.png]]

Esempio: stato composito sequenziale
![[Screenshot 2023-11-05 at 19.40.24.png]]

### Stati composti: sequenziali e paralleli
- Composizione sequenziale: uno solo sottostato attivo in ogni istante
![[Screenshot 2023-11-05 at 19.42.07.png]]

- Composizione parallelo: sottostasti attivi contemporaneamente, uno per regione
![[Screenshot 2023-11-05 at 19.42.16.png]]

Esempio di stato composito parallelo:
![[Screenshot 2023-11-05 at 19.45.30.png]]

- INGESSO:
	- Una transazione (default entry) che arriva sul bordo prosegue in tutti gli stati iniziali
- USCITA:
	- Una transazione che “buca” il bordo (fail) si intende possibile solo se l’evento avviene quando la macchina si trova in nello stato interno a cui è collegato: fa uscire tutti i sottostasti
	- Una volta raggiunti tutti gli stati finali si prosegue nella transazione di completamento.
	- Una transazione che parte dal bordo si intende possibile da un qualsiasi stato interno, fa uscire da tutti i sottostanti (non nell’esempio).

### Sottomacchine
Si usano quando si vuole descrivere uno stato composito in un diagramma a parte, per leggibilità o per definirlo e riusarlo in più contesti. La sottomacchina ha un nome (tipo), leistanze di uso si indicano con nomeIstanza: Tipo.

![[Screenshot 2023-11-05 at 19.49.58.png]]
### Entry ed exit points in sottomacchine
Una sottomacchina può definire entry and exit points, servono per collegare le transazione della macchina principale.

![[Screenshot 2023-11-05 at 19.52.52.png]]
### Transazione di completamente
Senza evento, scattano al raggiungimento: 
1. Della terminazione di un’attività composita, i.e. al raggiungimento dello stato finale in uno stato composito sequenziale, degli stati finali di tutte le regioni ortogonali di uno stato composito parallelo, di in exit Point.
2. Alla terminazione di entry e/o di do activity (la exit activiry viene eseguita quando scatta la transazione di completamento)
3. Di uno pseudo-stato giunzione (lo vedremo in seguito)

Esempio:
![[Screenshot 2023-11-05 at 19.56.04.png]]
### Altri tipi di stati (pseudostati)
![[Screenshot 2023-11-05 at 19.57.43.png]]

Esempio di choice:
Condizione valutata dinamicamente, come per la Choice dei diagrammi di attività: le disgiunzione delle guardie deve valere “true”. È ammesso il non-determinismo.

![[Screenshot 2023-11-05 at 20.02.58.png]]

Esempio di choice (con invocazioni di sotto-macchine)
![[Screenshot 2023-11-05 at 20.03.27.png]]

Esempio di choice (in una sotto-macchina)
![[Screenshot 2023-11-05 at 20.03.52.png]]
### Giunzione
Uno pseudo-stato da cui escono e/o entrano due o più transazioni, eventuali condizioni sono valutabili in modo statico. Prima dell’evento e:

![[Screenshot 2023-11-05 at 20.04.59.png]]

Se n \< 0 l’evento ‘e’ viene ignorato e si rimane nello stato 1.
Esempio giunzione:
![[Screenshot 2023-11-05 at 20.05.43.png]]

Esempio di sopra con pseudostato giunzione:
![[Screenshot 2023-11-05 at 20.08.44.png]]

Esempio giunzione, con entry e exit Actions:
![[Screenshot 2023-11-05 at 20.10.59.png]]

### Giunzione VS Choice
- Giunzione (statica): Le guardie sono valutate prima di uscire da Stato1. Se n<0 l’evento e viene ignorato e nessuna transizione viene presa.
![[Screenshot 2023-11-05 at 20.12.51.png]]

- Choice (dinamica): Le guardie sono valutate dopo e(n). In questo esempio occorre avere garanzia che n sia maggiore o uguale a zero.
![[Screenshot 2023-11-05 at 20.13.01.png]]
### Stato history
![[Screenshot 2023-11-05 at 20.13.27.png]]

### Macchine a stato o attività
Come scegliere il diagramma più appropriato per descrivere il modello dinamico. Ricordiamo che:
- Il diagramma di macchina a stati parla dell’evoluzione del tempo delle istanze di un classificatore
- Il diagramma di attività parla di un’agenda di azioni da fare.

Quindi se il focus è:
- Mettere in ordine un insieme di azioni da fare ==> ATTIVITÀ
- Mostrare l’evoluzione di un oggetto in risposta a eventi ==> STATI
### Descrivere il modello dinamico: nomi stati ed azioni
Per I nomi degli stati si utilizza questi principi:
- Aggettivi: attivo
- Participi passati: accesa, spenta, pinned
- Gerundi: dealing, connecting
- Altri: inAttesa

Mentre per i nomi delle azioni: 
- verbi all’indicativo, imperativo o infinito: crea, inviare
- Sostativi che indicano un’azione: interrogazione DB

Non è una regola e spesso nella pratica si disattende (eccezioni anche negli esempi visti), ma seguire questa prassi aiuta a costruire i diagrammi correttamente, inoltre un errore comune nei compiti è confondere stati e azioni.