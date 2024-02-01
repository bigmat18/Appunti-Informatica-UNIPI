Una internet (o internetwork) è data dall’interconnessione di reti, composte da link e dispositivi capaci di scambiarsi informazioni. In particolare, i dispositivi si distinguono in: sistemi terminali (host), dispositivi di interconnessione che si trovano nel percorso (o rotta) tra i sistemi sorgente e destinazione nella comunicazione tra host.
- Problema: Voglio stabilire una comunicazione (es. invio di un messaggio) tra due host.
- Domande: Come determinare il percorso da sorgente a destinazione? Come effettuare trasferire delle informazioni dall porta di ingresso alla porta di uscita?

Tecniche di commutazione: modalità con cui viene determinato il percorso sorgente-destinazione e vengono dedicate ad esso le risorse della rete. I meccanismi principali sono:
- Circuit-switched network: Reti a commutazione di circuito.
- Packet-switched network: Reti a commutazione di pacchetto
### Commutazioni del circuito
Il percorso viene stabilito all’inizio della comunicazione (setup). Sul percorso vengono dedicate risorse alla comunicazione (canale logico o circuito) in modo esclusivo, banda di frequenza o slot di trasmissione sui collegamenti e capacità commutative nei nodi. Le risorse allocate sono garantite per tutta la durata della comunicazione, indipendentemente dall’utilizzo effettivo.

![[Screenshot 2023-10-25 at 12.32.32.png]]

Communication di circuito di tipo FDM e TDM:
- **Frequency Division Multiplexing (FDM):** frequenze ottiche, elettromagnetiche suddivise in bande di frequenza (strette). Ad ogni comunicazione è assegnata una certa banda.

![[Screenshot 2023-10-25 at 12.34.33.png]]

- **Time Division Multiplexing (TDM):** tempo suddiviso in slot di tempo, ogni comunicazione ha uno o più slot periodici assegnati, può trasmettere alla velocità massima di una banda di frequenza (più ampia), ma solo durante i suoi intervalli di tempo.

![[Screenshot 2023-10-25 at 12.34.42.png]]


SVANTAGGI:
- Necessaria una fase di instaurazione (setup) della comunicazione.
- Le risorse rimangono inattive se non utilizzate (non c’è condivisione). Ad es. silenzi durante conversazione telefonica
VANTAGGI:
- Performance (garantita)
- Tariffa facile
### Commutazione di pacchetti
1. **Il flusso di dati punto-punto viene suddiviso in pacchetti:** I pacchetti degli utenti A e G condividono le risorse di rete, ogni pacchetto è instradato singolarmente e indipendentemente dagli altri pacchetti della stessa comunicazione (possono seguire lo stesso percorso o percorsi diversi). Le risorse vengono usate a seconda delle necessità.
2. **Trasmissione store and forward:** Il commutatore (es. router) deve ricevere l’intero pacchetto prima di poter cominciare a trasmettere il primo bit del pacchetto sul collegamento in uscita -> Ritardo di store and forward. Attesa dei pacchetti in code di output (buffer) -> Ritardi di coda. I buffer hanno dimensione finita -> Perdita di pacchetti.

![[Screenshot 2023-10-25 at 12.48.30.png]]


- pacchetto dopo pacchetto la capacità trasmissiva dei collegamenti sarà condivisa solo tra gli utenti che devono trasmettere sul collegamento.
- La sequenza dei pacchetti A e B sul collegamento a 1,5 Mbps non segue uno schema prefissato -> condivisione di risorse su richiesta (detta anche multiplexing statistico delle risorse).
- Non c’è un canale dedicato, gli host comunicano scambiandosi pacchetti.
- I router possono memorizzare i pacchetti nelle code (buffer).
- Se il collegamento tra i due router è usato alla massima capacità, gli ulteriori pacchetti che arrivano vengono messi in coda. 

Contesa per le risorse: La richiesta di risorse può ecceder il quantitativo disponibile. Si crea congestione: accodamento dei pacchetti, attesa per l’utilizzo del collegamento. Questo porta ad utilizzo efficiente delle risorse ma non c’è garanzia delle prestazione (es. ritardi)

SVANTAGGI:
- Tecnologie di inoltro non efficienti (necessità di selezionare l’uscita per ogni pacchetto).
- Ritardi variabili nel percorso end-toend (jitter), tempo di elaborazione ai router (routing table lookup), accodamento ai router.
- Protocolli necessari per un trasferimento dati affidabile, controllo della congestione
VANTAGGI:
- Risorse trasmissive usate solo se necessario.
- Segnalazione non richiesta.

ESEMPIO: Circuit switching vs Packet Switching

![](Screenshot%202023-10-25%20at%2012.52.15.png)

- **Circuit Switching**: Con la commutazione di circuito, occorre riservare 100Mbps per ogni utente, in ogni istante. Il link di output può quindi supportare simultaneamente al massimo 1Gbps/100Mbps = 10 utenti.
- **Packet Switching**: 10 o meno utenti simultaneamente attivi -> banda richiesta ≤1 Mbps, ritardo trascurabile. Più di 10 utenti attivi simultaneamente -> frequenza aggregata di arrivo dei dati supera la capacità del collegamento in uscita e quindi si incrementa il ritardo di accodamento. N.B. la probabilità che ci siano 10 o meno utenti attivi contemporaneamente è 0.9996. Con alta probabilità la tecnica del packet switching supporta tutti i 35 utenti senza introdurre alcun ritardo! 16 La commutazione di pacchetto consente a più utenti di utilizzare la rete
**La commutazione di pacchetto consente a più utenti di utilizzare la rete**
### Riassunto
|  | Circuit Switching<br> | Packet Switching |
| ---- | ---- | ---- |
| Vantaggi | - Prestazioni garantite (Es. latenza end-to-end) <br>- Tecnologie di switching efficienti | - Risorse trasmissive usate solo se necessario <br>-Segnalazione non richiesta |
| Svantaggi | - È richiesta la segnalazione per istaurare il circuito (configurare le tabelle di switching) <br>- Sottoutilizzo delle risorse in presenza di traffico e raffica (burst) e rete di traffico variabile | - Tecnologie di inoltre non efficienti (necessità di selzionare l'uscita per ogni pacchetto)<br>- Ritardi variabili nel percorso end-to-end (jitter) come il tempo di elaborazione ai router (routing table lookup) e l'accodamento ai router<br>- Protocolli necessari per un trasferimento dati affidabile controllo della congestione |
