opo la fase di handshake non c'è più distinzione fra client e server ma avviene uno scambio di da ti secondo i principi prima descritti.
## Trasferimento dati affidabile

Visto che un segmento può essere smarrito o corrotto TCP utilizza il **checksum** per traferire dati in modo affidabile tramite un controllo obbligatorio ed uno scarto dei segmenti corrotti.
###### Numero di sequenza
Numero del primo byte del segmento nel flusso di byte.
###### Numero di riscontro
Il numero di sequenza del byte che l'host attende dall'altro.
###### Riscontro cumulativo
Si effettua il riscontro del byte fino al primo byte mancante
###### Pipeline
Il mittente può inviare più segmenti senza attender il riscontro permettendo di aumentare la produttività

#### Eventi lato mittente
1. TCP riceve dati dall'applicazione
2. Incapsula i dati in 1 o più segmenti assegnato numero di sequenza
3. Avvia **timer di ritrasmissione** (RTO) 
4. La ritrasmissione avviene in caso di Timeout o ricezione di tre ACK duplicati

###### Timeout
In questo caso si ritrasmette il segmento che non è stato riscontrato e che ha causato il timeout. Una volta eseguita operazione viene riavviato.
###### Ack duplicato
Se il mittente riceve 3 ACK duplicati, il segmento successivo a quello riscontro è andato perso si esegue quindi una **ritrasmissione veloce** prima della scadenza del timer.
###### Segmenti fuori sequenza
I dati possono arrivare fuori sequenza ed essere memorizzati in questo modo dall'entità TCP destinataria. Si implementa nelle versioni più recenti la **Selective ACK**.
###### Selective ACK
I pacchetti ricevuti fuori sequenza vengono memorizzati, il riscontro di questi pacchetti viene inviato in OPTIONS.

![[Screenshot 2024-08-23 at 16.24.30.png | 500]]

#### Eventi lato destinatario

1. Tutti i segmenti inviati per trasmettere dati includono ACK
2. Se non ci sono dati da inviare e riceve segmento ritarda invio ACK di 500ms a meno che non riceva nuovo segmento.
3. Se si riceve segmento atteso e precedente non è stato riscontrato allora invia immediatamente ACK.
4. Segmento fuori sequenza => invia subito segmento ACK (prossimo numero atteso)
5. Segmento mancante => invia subito segmento ACK (prossimo numero atteso)
6. Segmento duplicato => invia subito segmento ACK (prossimo numero atteso)

###### Regole 1 - 2 - 3
![[Screenshot 2024-08-23 at 16.29.52.png | 500]]
###### Regole 3 - 4 - 5

![[Screenshot 2024-08-23 at 16.31.08.png | 500]]

###### Ritrasmissione veloce

![[Screenshot 2024-08-23 at 16.32.01.png | 500]]

###### Riscontro smarrito

![[Screenshot 2024-08-23 at 16.32.27.png | 500]]

#### Calcolo del timeout

- Deve essere maggiore di **RTT** (Round Trip Time) che è il **tempo trascorso da quando si invia il segmento a quando se ne riceve il riscontro**.
-  Il valore del RTT stimato si calcola come combinazione di precedenti valori Stimati e SampleRTT 
$$EstimatedRTT = (1-\alpha) * EstimatedRTT + \alpha * SimpleRTT$$
- $\alpha = 1/8$ per rendere via via meno importati gli RTT dei pacchetti vecchi
- Si calcola la variabilità di RTT (quando SampleRTT si discosta da EstimantedRTT)
$$RTT_{DEV} = (1-\beta)RTT_{DEV} + \beta \:\: \big|RTT_{SAMPLE} - RTT_{ESTIMATED}\big|$$
- $\beta = 1/4$ 
- $RTO = RTT_{ESTIMATED} + 4 RTT_{DEV}$
- In alcune implementazione, dopo un errore, si raddoppia il timeout

#### Finestra di trasmissione
È una finestra sovrapposta sulla sequenza da trasmettere, negoziata dinamicamente facendo avanzare alla ricezione di un ACK ed è dove si basa la trasmissione di dati.

![[Screenshot 2024-08-23 at 16.57.58.png |600]]
#### Finestra di ricezione

![[Screenshot 2024-08-23 at 16.58.46.png | 600]]

## Controllo di flusso

Capacità del mittente di evitare la possibilità di saturare il buffer del ricevitore, mettendo in relazione la frequenza di invio del mittente con la frequenza di lettura dell'applicazione ricevente.

- Mittente salva una **finestra di ricezione** per avere idea di quanto spazio è ancora disponibile nel buffer del ricevitore.
- Destinatario comunica la capacità residua nel buffer di ricezione tramite **rwnd** (la **dimensione di RcvBuffer** è configurabile tramite socket options)
- Mittente limita quantità di dati un ACK al valore ricevuto di rwnd.

##### Meccanismi di base
- Spazio disponibile nel buffer del destinatario
- Rwnd è dinamica
- Destinatario comunica la dimensione rwnd al mittente
- Mittente si assicura che LastByteSent - LastByteAckend < Rwn

![[Screenshot 2024-08-23 at 17.30.28.png | 500]]

## Controllo di congestione

- La congestione si crea quando la sorgente richiede più banda si quella disponibile sul percorso e causa lunghi ritardi e perdita di pacchetti.
- Si limita la frequenza di pacchetti sulla connessione per ogni mittente, in funzione della **congestione percepita**

#### Algoritmo congestione
1. Partenza lenta (**slow start**)
2. Incremento additivo e decremento moltiplicativo (**AIMD**)
3. Ripresa veloce (**fast recovery**)
4. Reazione ai time-out

#### Congestion Window
- Si misura in MSS (Maximum Segment Size) ed 1 MSS è la quantità massima di dati trasportabili da un segmento.
- Determinato in base alla MTU (unità trasmissiva massima) che è la **lunghezza massima del payload del frame di collegamento inviabile dal mittente**
- MSS scelto in modo che segmento TCP sita in un singolo frame
- RTT (Round Trip Time) tempo impiegato da segmento per effettuare andata - ritorno.

#### AIMD - Additive Increase Multiplicative Decrease

TCP mittente aumenta proporzionalmente la propria finestra di congestione ad ogni ACK ricevuto. Viene aumentata in modo che si abbia crescita pari ad 1 MSS per ogni RTT
(**congestion avoidece**).
- Ad ogni ACK non duplicato cwnd = cwnd + 1/cwnd

![[Screenshot 2024-08-23 at 18.17.32.png | 400]]

#### Slow start
- All'inizio finestra di congestion CongWin = 1 MSS
- Incremento Congwin di 1 MSS ad ogni ACK (non duplicato) così facendo abbiamo un raddoppio ad ogni RTT => crescita esponenziale

![[Screenshot 2024-08-23 at 18.32.25.png | 500]]

#### TCP Reno
Valore soglia alla quale viene assegnato valore alto.
- Se **cwnd < soglia** => cwnd aumenta esponenzialmente (si attiva slow start)
- Se **cwnd > soglia** => cwnd aumenta linearmente (si attiva additive increase)
- (Evento perdita) Se ho **3 ACK duplicati** pongo la soglia a metà di cwnd e poi cwnd = soglia + 3 MSS (**fast recovery**)
- (Evento perdita) Se ho un ACK **perso per timeout** pongo la soglia a metà cwnd e pongo cwnd = 1MSS (**slow start**)

![[Screenshot 2024-08-23 at 18.37.08.png | 500]]

###### Fast recovery
1. Se time-out si va in **slow start**
2. Finché arrivano ACK duplicati cwnd = cwnd +1
3. Se arriva ACK non duplicato si va in **congestion avoidance** e cwnd = soglia

#### TCP Tahoe
Variante di TCP reno più recente.

![[Screenshot 2024-08-23 at 18.37.45.png | 500]]
#### TCP Cubic
Alternativa migliore di AIMD per testare la banda utilizzabile

- $W_{max}$ rate di invio quando è stato rilevata congestione
- Lo stato di congestione del collegamento probabilmente non è cambiato molto
- Dopo aver dimezzato la finestra, si incrementa verso $W_{max}$ più veloce inizialmente e più lento quando ci si avvicina
- K punto nel tempo in cui cwnd raggiungerà $W_{max}$ (valore configurabile)
- Si aumenta W come funzione **cubo** della distanza tra istante di tempo attuale e k

![[Screenshot 2024-08-23 at 18.42.45.png | 400]]

### ECN - Explicit congestion notification
Meccanismo di controllo congestione network-assisted

1. Due bit in header IP settati dai router per indicare congestione
2. Informazione inviata a destinazione
3. Destinazione importa bit ECE per notificare la congestione al mittente
4. Mittente setta bit CWR per indicare che ha ricevuto la notifica di congestione

### Throughput
$$Throughput = \frac{0.75 \cdot W}{RTT}$$
- W valore massimo in byte della finestra
- Quando la è finestra è W il throuhput è W/RTT
- Dopo evento di perdita finestra va a W/2 => throughput = W/2RTT
- **Throughput medio** = 0.75 W/RTT

### Equità
Il TCP **è un protocollo equo** perché abbiamo stesso RTT e MSS e numero costante di sessione solo in CA