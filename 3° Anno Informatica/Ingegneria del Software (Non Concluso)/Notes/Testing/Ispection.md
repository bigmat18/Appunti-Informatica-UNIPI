Si esegue una lettura mirata del codice (guidata da una lista di controllo).
**L'obbiettivo** è rilevare la presenza di difetti. **La strategia** invece è quella di focalizzare la ricerca su aspetti ben definiti (error guessing). **Gli agenti **in questo caso sono diversi dai programmatori.

Possiamo definire 4 fasi:
1. Pianificazione
2. Definizione della lista di controllo.
	Le liste di controllo sono frutto dell'esperienza degli ispettori, contengono tipicamente aspetti che non possono essere controllati in maniera automatica. Le liste di controllo sono aggiornate ad ogni interazione di inspection.

	**Esempio**
	- È stato impedito a tutti gli indici di array (o di altri insiemi) di andare fuori dai limiti?
	- L'aritmetica dei numeri interi, in particolare la divisione, è utilizzata in modo appropriato? 
	- Tutti i file sono chiusi correttamente, anche in caso di errore? 
	- Tutti i riferimenti agli oggetti sono inizializzati prima dell'uso?
	- Tutti gli oggetti (comprese le stringhe) sono confrontati con "equals" e non con "\=\=" ?
	
	**Errori dei dati**: 
	- Tutte le variabili del programma sono inizializzate prima che i loro valori vengano utilizzati? 
	- A tutte le costanti è stato assegnato un nome? 
	- C'è la possibilità di un buffer overflow? ecc. 
	
	**Errori di controllo**:  
	- La condizione è corretta per ogni istruzione condizionale?
	- È certo che ogni ciclo termina?
	- Le istruzioni composte sono o non sono state messe tra parentesi in modo corretto? 
	
	**Errori di ingresso/uscita (I/O)**: 
	- Tutte le variabili di ingresso sono utilizzate o no? 
	- Tutte le variabili di uscita sono istanziate prima di essere restituite? 
	- Gli input inattesi possono essere causa di fault? ecc.

	**Difetti di interfaccia**: 
	- Tutti i metodi e le funzioni hanno il numero corretto di parametri? 
	- Il tipo di parametri, cioè effettivi e formali, corrisponde? 
	- I parametri sono presenti nell'ordine corretto? 
	- Se tutti i componenti accedono a una memoria condivisa , hanno lo stesso modello della struttura della memoria condivisa? 
	
	**Errori nella gestione della memoria**: 
	- Se si utilizza lo storage dinamico, lo spazio è stato allocato correttamente?
	- Lo spazio viene deallocato esplicitamente dopo che non è più necessario? ecc.
	
	**Gestione delle eccezioni**: 
	- Sono state prese in considerazione tutte le possibili condizioni di errore?