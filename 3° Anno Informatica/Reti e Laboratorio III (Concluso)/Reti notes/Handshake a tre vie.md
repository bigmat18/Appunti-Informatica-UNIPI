
1. Client invia richiesta di connessione a un server TCP con
	- bit SYC attivo 
	- senza nessun dato all'interno
	- numero di seq. iniziale (ISN)

2. Server estrae segmento, alloca buffer e variabili TCP per connessione.
2. Server invia una risposta di connessione garantita (STNACK) dove si attiva 
	- SYN (num sequenza è il valore iniziale)
	- ACK (il server aspetta client_isn+1)

3. Client alloca buffer e variabili connessione TCP.
3. Client invia riscontro a con
	- SYN inattivo, quindi si possono già trasportare dati
	- Prossimo dato sarà client_isn+1 (42) e client attende server_isn+1 (79)

![[Screenshot 2024-08-22 at 17.17.03.png | 500]]
