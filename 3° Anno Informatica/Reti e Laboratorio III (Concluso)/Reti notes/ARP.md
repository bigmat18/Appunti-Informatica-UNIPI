### Indirizzo MAC
Un indirizzo associato alla **scheda di rete**, non al nodo, ed è tipicamente permanete. Viene anche chiamato **indirizzo fisico** o **indirizzo di LAN** o **MAC**. 
###### Struttura
Ha una struttura piatta, analoga al numero di codice fiscale di una persona, è a 48 bit.
###### Adattatore
Ciascun adattatore di una LAN ha un indirizzo MAC univoco, un adattatore inserisce l'indirizzo MAC di destinazione per spedire un frame.

### ARP - Address Resolution Protocol
Serve per risolvere il problema della **risoluzione degli indirizzi**, cioè una macchina all'accensione non sa chi ha attorno, quindi deve capire le macchine che sono "visibili" direttamente.
#### Tabella ARP
Ogni nodo ha una Tabella ARP che contiene la corrispondenza tra indirizzi [[IP]] e MAC per i nodi della stessa sottorete, e non contiene necessariamente le corrispondenze per tutti i nodi. È presente anche per ogni entry della tabella un valore **TTL (tempo di vita)** che indica quando bisognerà eliminare una data voce.
#### Pacchetto ARP

![[Screenshot 2024-08-27 at 22.19.00.png | 500]]
###### Hardware type 
Protocollo a livello di collegamento (per esempio Ethernet 1).
###### Protocol type 
Protocollo a livello superior (per esempio IP)
###### Source hardware address e source protocol address
Indirizzi del nodo mittente a livello link e superiore. Questi valore hanno lunghezza variabile
###### Destination hard Address e destination protocol address
Il primo è vuoto nella richiesta.

#### Funzionamento protocollo ARP

![[Screenshot 2024-08-27 at 22.22.45.png | 500]]

- Interagisce direttamente con livello di collegamento
- Pacchetto ARP viene incapsulato in un frame e **spedito in broadcast** sulla rete, nell'header è specificato che è un pacchetto ARP.
- Ogni nodo della rete locale riceve ed elabora il pacchetto
- Il nodo che riconosce il proprio indirizzo IP restituisce un pacchetto di risposta ARP in **unicast** che contiene il proprio indirizzo IP e indirizzo MAC.

#### Forwarding diretto
1. A vuole trasmettere a B ma indirizzo MAC di B non è nella tabella di A
2. A trasmette un pacchetto in broadcast un messaggio ARP contente indirizzo IP B
3. Tutte le macchine della LAN ricevono ARP
4. B riceve ARP e risponde ad A comunicandogli il proprio indirizzo MAC
5. Il frame viene inviato all'indirizzo MAC di A

#### Forwarding indiretto
###### Ipotesi
- A conosce indirizzo IP di B
- A conosce indirizzo IP primo router
- A conosce indirizzo MAC di R

![[Screenshot 2024-08-27 at 22.38.11.png | 500]]


1. A crea un datagramma IP con IP sorgente A e destinazione B
2. A crea un frame con indirizzo MAC destinazione il MAC address di R, il frame incapsula questo datagramma 
3. A invia ad R
4. R riceve il frame viene decapsulato, il datagramma passa al livello IP
5. R estrae il datagramma IP dal frame Ethernet e vede che la sua destinazione è B
6. R inoltra il datagramma con IP sorgente A, destinazione B
7. R usa ARP per ottenere indirizzo MAC di B
8. R crea frame con destinazione il MAC address di B
9. R inoltra il datagramma con IP sorgente A e destinazione B
10. R crea un frame con destinazione il MAC address B

##### ARP Poisoning/Spoofing
È possibile alterare l'indirizzo MAC associato ad un determinato IP di un dispositivo connesso alla rete, tutti i pacchetti dati vengono automaticamente inviati al sistema che ha lanciato l'attacco ARP poisoning. I dati possono essere a questo punto analizzati, eventualmente modificati e quindi inviati al reale destinatario.