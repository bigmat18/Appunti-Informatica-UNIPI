# Larghezza di banda e bit rate
#### Velocità di trasmissione o bit rate
Quantità di dati (bits) che possono essere trasmessi (inseriti nella linea) nell'unità di tempo (**bits/sec** or **bps**) su un certo collegamento.
#### Larghezza di banda o bandwidth
Larghezza dell'intervallo di frequenze utilizzato dal sistema trasmissivo. Si misura in Hertz (**Hz**) che indicano i cicli per secondo.

**Nota**
La bandwidth ed il bit rate non solo la stessa cosa, a velocità di trasmissione dipende dal bandwidth ma anche da altri fattori (rumore, tecniche trasmissive usate)

# Throughput

Quantità di dati che possono essere trasmessi con successo dalla sorgente alla destinazione in un certo intervallo di tempo.

**Nota**
Bit-rate e throughtput non sono la stessa cosa, visto che il throughtput indica la **velocità di dati trasmessi al netto delle perdite**. Mentre il bit-rate è una **misura al caso ottimo**

Si calcola prendendo il minimo bit-rate fra le connessione di una rete (**bottleneck link**).

# Latenza (ritardo)

Tempo richiesto affinché un messaggio arrivi a destinazione dal momento in cui il primo bit parte dalla sorgente.

###### 1. Ritardo di elaborazione del nodo
- Controllo errori sui bit 
- Determinazione del canale di uscita
###### 2. Ritardo di accodamento
- Attesa di trasmissione, 
- Dipende da intensità e tipo di traffico che influiscono sul numero di pacchetti in coda nel buffer
###### 3. Ritardo di trasmissione
- Tempo impiegato per trasmettere un pacchetto. 
- Rapporto fra velocità di trasmissione (R) e lunghezza pacchetto (L) 
- **Ritardo trasmissione = L/R**.
###### 4. Ritardo di propagazione (d/s)
- Tempo impiegato da 1 bit per essere propagato da un nodo all’altro.
- Rapporto fra lunghezza del collegamento (d) e velocità di propagazione del mezzo (v)
- **Ritardo di propagazione = d/v**

![[Screenshot 2024-08-19 at 15.39.12.png | 500]]
$$Latenza = Ritardo_{pr} + Ritardo_{tr} + Ritardo_{acc} + Ritardo_{el}$$
##### Ritardo end-to-end
Il ritardo end-to-end viene calcolato come somma dei ritardi dei singoli collegamenti.

Trascurando ritardo di elaborazione e ritardo di accodamento
$$\begin{aligned}
Ritardo_{link1} &= Ritardo_{tr1} + Ritardo_{prop1}\\
Ritardo_{link2} &= Ritardo_{tr2} + Ritardo_{prop2}\\ 
Ritardo_{link3} &= Ritardo_{tr3} + Ritardo_{prop3}\\\\
Ritardo_{end-to-end} &= Ritardo_{link1} + Ritardo_{link2} + Ritardo_{link3}
\end{aligned}$$

##### Traceroute
È un comando che traccia un pacchetto dal tuo computer all'host e mostra anche il ritardo e il numero di passaggi (salti) necessari per raggiungerlo dal mittente per ogni passaggio (effettua tre volte l’esperimento ).

##### Prodotto rate-ritardo
Numero massimo di bit che il link può contenere in un certo istante.

Possiamo pensare al link tra due punti come ad un tubo. La sezione trasversale del tubo rappresenta il rate e la lunghezza rappresenta il ritardo. Possiamo dire che il volume del rubo definisce il prodotto rate-ritardo.

![[Screenshot 2024-08-19 at 15.44.56.png | 500]]