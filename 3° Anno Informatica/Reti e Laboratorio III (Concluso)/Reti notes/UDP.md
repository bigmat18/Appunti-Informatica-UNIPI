- Servizio di consegna dove i datagrammi possono essere perduti o consegnati fuori sequenza, quindi **trasferimento non affidabile** (checksum facoltativo)
- È orientato ai messaggi, ogni datagramma è indipendente
- Meno complesso di TCP e si usa quando c'è bisogno di un controllo completo della temporizzazione come appliccazioni multimediali
- Nessuna connessione, richiede **minor overhead**

### Datagramma UDP

![[Screenshot 2024-08-24 at 15.45.29.png | 400]]

##### Porta (source port e dest. port)
Numeri di porta della comunicazione (per demultiplexing si usa solo destinazione)

##### Lunghezza del messaggio (lenght)
Lunghezza totale (header + dati) del datagramma

##### Chechsum
È opzionale e fornisce controllo errore end-to-end. Il pacchetto corrotto viene scartato ma mittente non ne riceve notifica (calcolato su tutto datagramma + pseudo-hedaer)

###### Mittente
- Checksum = 0
- Datagramma UDP trattato come sequenza parole da 16 bit
- Checksum somma parola di 16 bit in complemento a uno (riporto aggiunto in fondo)
- Il risultato viene fatto ulteriormente in complemento a uno (inversione dei bit)
- Checksum = 1

###### Ricevente
- Calcola la checksum del segmento ricevuto
- Se valore checksum != 0 ==> errore rilevato
- Se valore checksum == 0 ==> nessun errore

![[Screenshot 2024-08-24 at 15.55.28.png | 500]]

### TCP vs UDP
##### TCP
Offre un servizio di trasporto a stream, quindi può leggere da un input di rete quanti byte si desiderano.
##### UDP
Offre un servizio a messaggi, quindi occorre leggere tutto il messaggio in arrivo. È adeguato nei casi:
- processi con scambio di dati a volume limitato con basso interesse a controllo e errori
- processi con meccanismi interni di controllo flusso e errori
- trasmissioni multicast
- applicazioni in tempo reale

### Attacco UDP flood
- Attacco volumetrico con l'obbiettivo di sovraccaricare la capacità del dispositivo di elaborare e rispondere.
- Si crea di conseguenza **denial-of-service** al traffico normale. 
- Attaccante inserisce nel pacchetto del messaggio UDP un indirizzo IP spoofed

### Attacco UDP Amplification
- UDP non controlla gli indirizzi IP di origine
- Attaccante crea un pacchetto per usare un indirizzo IP di origine arbitrario (IP vittima)
- Attaccante invia numerosi pacchetti UDP con indirizzo IP falsificato
- Server risponde alla vittima, creando un attacco DoS riflesso