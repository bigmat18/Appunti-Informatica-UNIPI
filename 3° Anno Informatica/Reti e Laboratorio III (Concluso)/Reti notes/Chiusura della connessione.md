- Il client ed il server inviano un segmento di TCP con bit FIN=1 per chiudere ciascuno il loro lato della connessione. 
- Ciascuno risponde al FIN ricevuto con un ACK, quando si riceve un FIN l'ACK può essere combinato con il proprio FIN
- Possibile anche scambio simultaneo di FIN

![[Screenshot 2024-08-22 at 17.16.19.png | 500]]

##### Stato TIME-WAIT
Stato finale in cui il capo di connessione che esegue la chiusura resta attivo prima di passare alla chiusura definitiva della connessione. Dura due volte la **MSL** (Maximum Segment Lifetime) che è **la stima del massimo periodo di tempo che un pacchetto IP può vivere sulla rete** 

Stato utilizzato perché:
1. Abbiamo la terminazione della connessione in entrambe le direzioni in modo affidabile.
2. Consente l'eliminazione dei segmenti duplicati in rete.

##### Half-close
Uno dei due processi può smettere di inviare dati metre sta ancora ricevendo dati.

![[Screenshot 2024-08-22 at 17.31.54.png | 500]]
