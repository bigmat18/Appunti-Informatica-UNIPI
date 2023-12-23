Organizzazione **seriale** (**heap** file) è un tipo nel quale i dati sono memorizzati in modo disordinato uno dopo l'altro: 
- Semplice e a basso costo di memoria 
- Poco efficiente 
- Va bene per pochi dati
E’ l’organizzazione standard di ogni DBMS.

Mentre nel organizzazione **sequenziale** i dati sono ordinati sul valore di uno o più attributi:
- Ricerche più veloci
- Nuove inserzioni fanno perdere l'ordinamento

**Costo di ricerca** 
Ricerca binaria su file di dati ordinato richiede $log_2b$ accessi a blocco/pagina Se il file contiene $b_i$ blocchi, la localizzazione di un record richiede:
- ricerca binaria nel file 
- accesso al blocco che contiene il record
Quindi richiede $\log_2b_i +1$ accessi a blocco/pagina

**Esempio**. File ordinato con r = 30.000 record, dimensioni dei blocchi/pagine su disco B = 1024 byte, I record hanno dimensione fissa e sono indivisibili, lunghezza R = 100 byte, Il fattore di blocco/pagine è:
$$bfr = \lfloor (B/R) \rfloor = \lfloor (1024/100)\rfloor = 10 \: record \: per \: ogni \: blocco/pagina$$
Numero blocchi necessari $b = \lceil(r/bfr) \rceil = \lceil(30000/10) \rceil = 3000 \:blocchi$.
Una ricerca binaria su file dati richiede circa $\lceil log_2b \rceil = \lceil log_23000 \rceil = 12$ accessi ai blocchi/pagine.

