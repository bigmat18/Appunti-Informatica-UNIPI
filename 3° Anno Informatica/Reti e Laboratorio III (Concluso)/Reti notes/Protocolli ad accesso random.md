## Protocolli ad accesso random
#### Slotted ALOHA
###### Assunzioni
- Tempo diviso in slot uguali e fissi
- I nodi iniziano a trasmettere all'inizio dello slot (sincronizzati)
- I nodi sono **sincronizzati**
- Se 2 nodi trasmettono insieme, entrambi rilevano la collisione

###### Funzionamento
1. Nodo trasmette frame all'inizio dello slot successivo
2. Verifica se sono avvenute collisione
	- se **NON ci sono collisioni** il nodo può inviare un nuovo frame
	- se **ci sono collisioni** il nodo ritrasmette con probabilità p il frame nello slot successivo finché non ha successo.

![[Screenshot 2024-08-27 at 19.15.27.png | 500]]

###### Pro
- È un protocollo semplice 
- Il nodo attivo può trasmettere alla massima velocità
- È fortemente decentralizzato visto che devono essere sincronizzati solo gli slot.

###### Contro
- Ci sono i problemi delle collisioni, quindi spreco di slot
- Non c'è un gran numero di nodi attivi, il canale usato con successo solo il 37% del tempo.

#### ALOHA puro (unslotted)

Versione più semplice dove **non serve la sincronizzazione**, quando un nodo ha dati da inviare li trasmette subito, questo porta ad una maggior probabilità di collisione. (a tempo t0 collissone a t0-1 e t0+1)

![[Screenshot 2024-09-02 at 18.31.21.png | 400]]
#### CSMA - Carrier Sense Multiple Access

- Ascolta prima di inviare
- Se **canale è libero** trasmette l'intero frame
- Se **canale è occupato** ritarda la trasmissione
- Non interrompe qualcuno che invia

#### CSMA/CD - Collision detection
Le collisione possono ancora avvenire a causa del ritardo di propagazione che fa si che due nodi non rilevino le comunicazioni reciproche. In questo caso le trasmissione che collidono **vengono abortite** (carrier sensing)
