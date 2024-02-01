Le metriche si usano per misurare le prestazioni della rette e sono:
- Ampiezza di banda e bit-rate
- Throughput
- Latenza
- Prodotto rete\*ritardo 
## Larghezza di banda e bit rate
##### Velocità di trasmissione (trasmission rate)
Quantità di dati (bits) che possono essere trasmessi ("inseriti nella linea") nell'unità di tempo (bits/secondo or bps) su un certo collegamento.
##### Larghezza di banda (Bandwidth)
Larghezza dell'intervallo di frequenze utilizzato dal sistema trasmissivo. Si misura in Hertz (Hz - cycles per second).

**N.B. La larghezza di banda ed il bit-rate non sono la stessa cosa**
La trasmission rate dipende dalla larghezza di banda ma è indluenzata anche da altri fattori (tecninca trasmissiva usata, rumore, ecc.)

**Esempio**. Il rate di un link fast ethernet è di 100 Mbps, ovvero tale rete può inviare al massimo 100 Mbps
![[esempio-bit-rate.png]]

## Throughput

*Definizione* (**Throughut**): Quantità di dati che possono essere trasmessi con successo dalla sorgente alla destinazione.

Ricordiamo che il bit-rate ed il throughput non sono la stessa cosa.
- Il Throughput indica la velocità con cui trasferiamo i dati, al netto di perdite sulla rete, duplicazioni, protocolli, ecc.
- Il rate è una misura della potenziale velocità di un link, il throughput è una misura dell'effettiva veclotà di un link (quanto velocemente riusciamo ad inviare i dati in realtà).
- Throughput < trasmission rate
![[throghpuy-vs-rate.png]]

NB. Il throughput dipende non solo dalla velocità di trasmissione del collegamento ma anche dalla quantità di dati (flussi di traffico aggiuntivi rispetto a quello di interesse), **effetti dei protocolli**, ecc…

La definizione esatta e metodologia di misura dipendono dal sistema che stiamo osservando (System UndertTest – SUT). Ad es. throughput di un dispositivo di interconnessione: The maximum rate at which none of the offered frames are dropped by the device.

In un percorso da una sorgente ad una destinazione un pacchetto può passare attraverso numerosi link, ognuno con throughput diverso. Come si determina il throughput dell'interno percorso (end to end)?
![[throughput-percorso.png]]
**Esempio**. Scenario internet.
Ipotizziamo di avere 10 collegamenti tra coppie di client-server. **End-end throughput** per connessione: min($R_c, R_s, R/10$). In pratico spesso $R_x$ o $R_s$ sono il collo di bottiglia (rete di accesso).
![[scenario-internet-throughput.png | 400]]
## Latenza (ritardo)

*Definizione* (**Latenza**): tempo richiesto affiché un messaggio arrivi a destinazione dal momento in cui il primo bit parte dalla sorgente.

Da cosa è determinato il valore della latenza in una rete a commutazione di pacchetti?
I pacchetti si accodano nei buffer dei router.
- Il ritardo di accodamento dipende dal tasso di arrivo dei pacchetti e dalla capacità del collegamento in uscita.
- I pacchetti si accodano, in attesa del proprio turno
- All'aumentare del tasso di arrivo dei pacchetti sul collegamento il ritardo i accodamento aumenta.
- Capacitò del buffer è finita.
![[latenza.png]]
##### Quattro cause principali per il ritardo per i pacchetti
1. **Ritardo di elaborazione del nodo** 
	- controllo errori sui bit, 
	- determinazione del canale di uscita
2. **Ritardo di accodamento** 
	- attesa di trasmissione, 
	- dipende da intensità e tipo di traffico che influiscono sul numero di pacchetti in coda nel buffer
![[cause-ritardo-1-2.png | 550]]
3. **Ritardo di trasmissione (L/R)** 
	- tempo impiegato per trasmettere un pacchetto, 
	- R=rate o velocità di trasmissione del collegamento in bps, 
	- L = lunghezza del pacchetto in bit, 
	- quindi il ritardo di trasmissione è uguale a L/R)
4. **Ritardo di propagazione (d/s)** 
	- Tempo impiegato da 1 bit per essere propagato da un nodo all'altro, 
	- d sta per lunghezza del collegamento fisico mentre 
	- s sta per velocità di propagazione del mezzo $\sim3-2x10*8 m/sec$, 
	- quindi il ritardo di propagazione è d/s
![[cause-ritardo-3-4.png | 550]]
**Esempio**.
- Invio di 1 file di 1 Mbit su un link di lunghezza di 4800km 
	$d_{propagation} = \Large{\frac{d[m]}{s[m/sec]}} = \Large{\frac{4800 \cdotp 10^3}{3 \cdotp 10^8 [m/sec]}} = \normalsize0.016 [sec]$
	
- Velocità di trasmissione 64 kbits
	$d_{trasmission} = \Large\frac{L[bits]}{R[bps]} = \Large\frac{10^6[bits]}{64\cdotp10^3[bps]} = \normalsize 15.625[sec]$
	
- Velocità di trasmissione 1 Gbps
	$d_trasmission = \Large\frac{L[bits]}{R[bps]} = \Large\frac{10^6[bits]}{10^9[bps]} = \normalsize0.001[sec]$

**Esempio**. Caso paragonabile a quello di un casello autostradale.
- Le automobili viaggiano (ossia "si propagano") alla velocità di 100 km/h.
- Il casello fra transitare (oss "trasmette") un'auto ogni 12 secondi.
Abbiamo quindi che un D: auto è analogo ad un bit, ed una carovana analoga ad un pacchetto. Quanto tempo occorre perché le 10 auto in carovana si trovino di fronte al secondo casello?
![[esempio-casello-stradale.png]]
#### Ricapitolando
Latenza = ritardo di propagazione + ritardo di trasmissione + ritardo di accodamento + ritardo di elaborazione
$$Ritardo = Ritardo_{pr} + Ritardno_{tr} + Ritardo_{acc} + Ritardo_{el}$$
- **Ritardo di propagazione**: tempo che serve a un bit per viaggiare da un punto A a un punto B sul mezzo trasmissivo. Dipende dalla distanza (valori tipici da pochi microsecondi a centinaia di millisecondi)
$$Ritardo_pr = distanza/velocità_{propagazione}$$
- **Ritardo trasmissione**: tempo per immettere un pacchetto sulla linea
$$Ritardo_tr = lungehzza\:del\:pacchetto/rate_{trasmissione}$$
- **Ritardo di accodamento**: tempo in cui il pacchetto attende nella coda del router (dipende dalla congestione).
- **Ritardo di elaborazione**: tempo per l’elaborazione al nodo intermedio (in genere pochi microsecondi, o anche meno).

#### Ritardo end-to-end
Il ritardo end-to-end viene calcolato come somma dei ritardi dei singoli collegamenti. Il ritardo di ogni collegamento è pari alla somma del ritardi di elaborazione $Ritardo_{el}$, di accodamento, di propagazione $Ritardo_{prop}$ e di trasmissione $Ritardo_{tr}$.
Trascurando ritardo di elaborazione e ritardo di accodamento:
$$\begin{aligned}
Ritardo_{link1} &= Ritardo_{tr1} + Ritardo_{prop1}\\
Ritardo_{link2} &= Ritardo_{tr2} + Ritardo_{prop2}\\ 
Ritardo_{link3} &= Ritardo_{tr3} + Ritardo_{prop3}\\
Ritardo_{end-to-end} &= Ritardo_{link1} + Ritardo_{link2} + Ritardo_{link3}
\end{aligned}$$
![[Screenshot 2024-01-18 at 14.39.16.png]]
**Esempio**. Considerare la topologia di rete nella figura sopra.
1. Calcolare il ritardo end-to-end:
	- a dimensione del pacchetto sia pari a L = 1000 bit 
	- il link 1 abbia rate di trasmissione R1 = 100 Mbps e lunghezza D1 = 100 m
	- il link 2 abbia rate di trasmissione R2 = 2 Mbps e lunghezza D2 = 2500 km
	- il link 3 abbia rate di trasmissione R3 = 10 Mbps e lunghezza D3 = 1 km
	- la velocità di propagazione nei tre link sia pari a V = 2.5 · 108 m/s

#### Traceroute
È un comando che traccia un pacchetto dal tuo computer all'host e mostra anche il ritardo e il numero di passaggi (salti) necessari per raggiungerlo dal mittente per ogni passaggio.
- Traceroute effettua tre volte l’esperimento -> 3 misure di latenza.
- * Perdita di pacchetti in rete 
- Notare la variazione nel tempo dei ritardi! • su windows il comando è tracert.
![[Screenshot 2024-01-18 at 14.41.16.png]]
#### Prodotto rate-ritardo
Possiamo pensare al link tra due punti come ad un tubo. La sezione trasversale del tubo rappresenta il rate e la lunghezza rappresenta il ritardo. Possiamo dire che il volume del rubo definisce il prodotto rate-ritardo. Prodotto rate-ritardo: numero massimo di bit che il link può contenere ad un certo istante.
![[Screenshot 2024-01-18 at 14.44.18.png]]
Supponiamo di avere un link con rate di 1bps ed un ritardo di 5 secondi. Cosa rappresenta il prodotto rate * ritardo ?
![[Screenshot 2024-01-18 at 14.44.07.png]]
Il massimo numero di bit che possono riempire il collegamento. Non possono esserci più di 5 bit contemporaneamente sul link.