### IP - Internal Protocol 

- Processo connection-less
- Servizio basato sul **best effort** quindi non garanzia che 
	- i pacchetti vengano ricevuti nell'ordine in cui inviati
	- i pacchetti vengano consegnati.
	- ci sia una qualità del servizio sul tempo di consegna e sul controllo del flusso

###### Inoltro (Forwarding)
Trasferimento del pacchetto sull'appropriato collegamento di uscita
###### Instradamento
Processo decisionale di scelta del percorso verso una destinazione (algoritmo di istradamento o routing)
###### Indirizzamento
Strumento per identificare gli host nell'internet
###### Modello datagram
I pacchetti vengono frammentati e riunificati, avviene un controllo degli errori (solo header) e la verifica TTL

### Datagramma IP

![[Screenshot 2024-08-25 at 16.01.30.png | 500]]

###### Versione (4 bit)
Specifica la versione di IP usata
###### Hlen (4 bit)
Specifica la lunghezza dell'header tipicamente è 20 byte
###### Tipo di servizio (8 bit)
- 6 bit per **Differentiated Services**, che indica la classe di servizio del pacchetto che darà differenti politiche di accodamento ai router
- 2 bit **Explicit Congestion Notification (ECN)** che serve per il supporto a livello di rete e trasporto per la notifica di eventi di congestione 
###### Lunghezza del datagramma (16 bit)
È la lunghezza di tutto il datagramma in byte, header incluso
###### Identificatore, flag, offset
Sono campi per la frammentazione
###### Tempo di vita o TTL (8 bit)
Valore che viene decrementato ad ogni passaggio da un router e quando raggiunge 0 viene scartato. Serve per evitare percorsi ad anello.
###### Protocollo (8 bit)
Serve a l'host destinatario per sapere quale protocollo dello strato superiore deve ricevere i dati (UDP 17 o TCP 6)
###### Checksum dell'intestazione (16 bit)
Viene fatto il checksum solo dell'intestazione ad ogni router, se si ottiene errore si scarta datagramma.
###### Indirizzo sorgente e destinazione (32 bit)
Indirizzo IP mittente e destinatario
###### Opzioni (lunghezza variabile, multiplo di 32 bit)
Varie opzioni messa sporadicamente, da 0 a 40 byte
###### Dati
Dati trasportati da datagramma IP

### Frammentazione
##### MTU - Maximum Transfer Unit
Quantità massima di dati trasportata dal protocollo di collegamento (in un frame). Può variare da una tecnologia di collegamento all'altra

##### Meccanismo di frammentazione
1. Se router riceve datagramma la cui dimensione supera l'MTU della rete verso cui deve inoltrare quel datagramma, il router frammenta il datagramma IP in più datagrammi più piccoli detti **frammenti**.
2. **Ogni frammento è a sua volta un datagramma IP completo** trasmesso attraverso una serie di reti fisiche indipendentemente dagli altri.
3. Il sistema terminare eventualmente ri-assembla
4. Se dei frammenti non arrivano a destinazione si butta via il datagramma

##### Ricomposizione dei frammenti fuori ordine
###### Identificatore (16 bit)
Associato a IP sorgente e IP destinazione identifica quel datagramma in un intervallo di tempo ragionevolmente lungo. I frammenti mantengono il valore di questo campo
###### Offset (13 bit)
Indica la posizione relativa come multiplo di 8 byte e serve ad ordinare i frammenti nell'assemblaggio.
###### Flag (3 bit)
Serve ad identificare l'ultimo frammento.
- bit 0 riservato
- bit 1 se valore = 0 pacchetto può essere frammento, valore = 1 no
- bit 2 se valore = 0 pacchetto ultimo frammento, valore = 1 no


### Indirizzi IPv4
- Gli indirizzi IP cono costituiti da 32 bit rappresentati in notazione decimale puntata
- Viene assegnato un indirizzo IP ad ogni interfaccia.
- Un host ha un indirizzo univoco diviso in due parti **Network ID + Host ID** 

![[Screenshot 2024-08-28 at 18.54.15.png | 500]]

#### Classful addressing
- Prefissi di rete di lunghezza fissa
- Reti divise in classi

![[Screenshot 2024-08-25 at 17.52.38.png | 500]]
#### Classless addressing (CIDR)

![[Screenshot 2024-08-28 at 18.55.50.png | 500]]
a.b.c.d/n con n bit più a sinistra costituiscono la parte di indirizzo di rete
###### Maschere di sottorete
Numero composto da 32 bit in cui i primi n bit a sinistra sono impostati a 1 e i rimanenti a 0. Serve a distinguere quel parte di un indirizzo IP identifica la rete e quale l'host
