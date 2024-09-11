Ogni datagramma IP è soggetto a forwarding da parte dell'host di origine e del router che sta attraversando.

###### Inoltro diretto
Il pacchetto IP ha come destinazione un host nella propria rete IP, abbiamo quindi un invio diretto senza l'interpretazione di nessun'altra entità.
1. B deve spedire pacchetto ad A
2. B conosce IP-B della propria interfaccia, e da confronto con IP-A capisce che sono nella stessa sottorete
3. B confronta tabella corrispondenza indirizzi IP e indirizzi rete per reperire MAC-A
4. B passa pacchetto a livello inferiore con destinazione MAC-A

###### Inoltro indiretto
Il pacchetto IP ha come destinazione un host di un'altra rete IP, viene delega l'invio ad un altro router.
1. B (193.17.31.55) deve spedire pacchetto all'indirizzo IP-D = 131.17.23.4
2. B confronta suo indirizzo con IP-D e capisce che sono sotto reti diverse
3. B inoltra pacchetto ad un router
4. B recupera l'indirizzo MAC del router della tabella di corrispondenza 
5. Il pacchetto viene costruito e spedito sull'interfaccia

###### Condizioni necessarie per forwarding
- esistenza di un cammino diretto, tra tutti gli host che appartengono ad una stessa sottorete.
- Ogni host coinvolto abbia un indirizzo IP che appartenga alla stessa sottorete e che sia univoco nella sottorete.