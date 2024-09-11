### Assegnazione di blocchi di indirizzi

Gli indirizzi IP sono gestiti da ICAN e assegnati agli ISP in blocchi che a loro volta assegnano ai clienti sottoblocchi di indirizzi.

![[Screenshot 2024-08-28 at 18.52.24.png | 500]]

1. Il numero di indirizzi N in ogni subnetwork deve essere potenza di 2
2. La lunghezza del prefisso di ogni sottorete va calcolata con la formula n = 32 - log2 N dove N è il numero di indirizzi della sottorete
3. Si assegnano **blocchi di indirizzi contigui**
4. Se blocchi di dimensioni diverse si parte dai blocchi più grandi

### Indirizzi speciali
###### This-host 0.0.0.0
Usato quando un host ha necessità di inviare un datagramma ma non conosce il proprio indirizzo IP.

###### Limited-broadcast 255.255.255.255
Usato quando bisogna inviare un datagramma a tutti i dispositivi nella rete. I router bloccano propagazione solo alla rete locale.

###### Loopback 127.0.0.1
Il datagramma con questo indirizzo destinazione non lascia l'host locale

###### Indirizzi privati
Ci sono quattro blocchi riservati per indirizzi privati: 10.0.0./8, 172.16.0.0/12, 192.168.0.0/16, 169.254.0.0/16

###### Indirizzi multicast
Sono il blocco 224.0.0.0/4

### DHCP - Dynamic Host Configuration Protocol

##### Configurazione con DHCP
L'host ottiene il proprio indirizzo IP e le altre configurazioni in modo automatico quando si "aggiunge" ad una rete.
- Può avvenire rinnovo dell'indirizzo in uso
- Permette riuso indirizzo precedentemente assegnato
- Supporto per utenti che si uniscono/lasciano la rete spesso
- Utilizza [[UDP]]
##### Configurazione manuale IP
Al posto di usare il protocollo DHCP per attribuire un IP all'interfaccia di un host si può importare manualmente nell'host.

##### DHCP protocollo client-server
1. Host invia in broadcast messaggio **DHCP discover**
2. Server DHCP risponde con messaggio **DHCP offer**
3. Host richiede un indirizzo IP con messaggio **DHCP request**
4. Server DHCP invia messaggio **DHCP ack** se richiesta va a buon fine

**Nota**
Il server DHCP può essere ospitato sui router servendo le sottoreti del router-

