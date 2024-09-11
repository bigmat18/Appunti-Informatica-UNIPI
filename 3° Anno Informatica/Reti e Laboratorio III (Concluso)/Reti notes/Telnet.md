Protocollo di terminale remote in cui scopo è quello di permettere l'uso iterativo di macchine remote inviando comandi dopo un login

- Include programma sever che accetta richiesta
- Include programma client che effettua le richieste

#### Protocollo TELNET
1. Client stabilisce connessione TCP con server
2. Client accetta battute di tasti dal terminale e le invia al serve. 
3. Accetta caratteri che server manda indietro e li visualizza sul terminale
4. Il server accetta la connessione TCP e trasmette i dati al sistema operativo locale

Client usa **porta 23** del server.

#### Local login
Sistema operativo assume che input fornite da tastiera e output inviati al monitor.

![[Screenshot 2024-08-20 at 16.01.21.png | 300]]

#### Remote login
Comprende un **pseudo-terminal driver** che è un entry point del sistema operativo che consente di trasferire caratteri dal server TELNET ad un processo come se provenissero dal terminale.

![[Screenshot 2024-08-20 at 16.09.47.png | 600]]

#### NVT - Network Virtual Terminal
È un terminale virtuale sulla rete, per ogni host poi si effettua una conversione da terminale locale a terminale virtuale. Sever per uniformare i terminali di host diversi.

![[Screenshot 2024-08-20 at 16.13.22.png |600]]
- Fornisce un set di caratteri e comandi universali che convertono caratteri locali in caratteri universali.
- Scambio dati in 7-bit US-ASCII
- bit più significativo usato per sequenze di comandi
- i comandi iniziano con ottetto speciale (**erase line**)

#### SSH
Versione più sicura del telnet che applica una cifratura al normale protocollo.