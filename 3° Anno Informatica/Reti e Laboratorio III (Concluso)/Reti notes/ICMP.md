## ICMP - Internet Control Message Protocol

È un protocollo che è usato da host e router per **scambiarsi messaggi di errore** ed è stato creato per **porre rimedio alle situazione in cuoi si verifica un errore**, visto che il protocollo IP non ha meccanismi integrati per renderlo noto all'host mittente. 

- Router o host devono informare il mittente di errori o di eventi avvenuti nell'inoltro di un pacchetto IP
- I pacchetti ICMP sono incapsulati all'interno di datagrammi IP e vengono instradati dai router prima dei pacchetti IP
- Messaggi ICMP non sono mai inviati in risposta a pacchetti IP con mittente che non rappresenta un host in modo univoco (0.0.0.0, 127.0.0.1)
- Messaggi ICMP non sono mai inviati in risposta a pacchetti IP con destinazione brodcast o multicast
- Messaggi ICMP non sono mai inviati in risposta ad altri errori ICMP, ma inviati per ICMP di interrogazione

###### Messaggi segnalazione errore
###### Messaggi di richiesta/risposta

###### Ping
Si utilizza per verificare il funzionamento di un altro host o in maniera grossolana per verificare l'affidabilità e la congestione del router tra due host.
###### Traceroute
È un programma utilizzato per individuare il percorso di un datagramma dalla sorgente alla destinazione tramite l'identificazione dell'indirizzo IP di tutti i router.

- Usa protocollo UDP per inviare un datagramma ad una porta su cui è improbabile che un processo sia in ascolto
- Datagrammi sono configurati per scatenare l'invio di messaggi di **errore di tempo scaduto** e **porta destinazione non raggiungibile**.
- Viene importato un **timer per trovare il tempo di round-trip** di ogni router e di destinazione
- **Invio di 3 messaggi a ogni dispositivo** con stesso TTL per miglior stima

## Wireshark

È un programma disponibile liberamente su Windows, Linux/Unix e MacOS che analizza i protocolli di rete.

###### Libreria di cattura dei pacchetti
Copia passivamente i messaggi che vengono inviati e ricevuti da una interfaccia di rete del vostro computer

###### Analizzatore di pacchetti
Visualizza il contenuto di tutti i campi