## Esempi didattici di client/server basati sui socket

Gli esempi di client/server per il calcolo di numeri primi che contengono i caratteri `p1` nel nome utilizzano il protocollo nel quale appena stabilita la connessione un byte (totalmente inutile) viene inviato dal server al client.  Questo serve per aggiungere un round di comunicazione per aggiungere lavoro al server e rendere più evidente la necessità di un server in grado di gestire più client contemporaneamente. I client con `p1` nel nome non stampano l'elenco dei primi ricevuti per non sovraccaricare la console.


Se si utilizza multip1client.py com p1server.py si osserva che il server si blocca completamente ogni volta che il server esegue l'operazione `time.sleep(6)` che simula un ritardo nella rete. Il problema non si presenta con un server che utilizza la `select` (`selrwp1server.py`), oppure più thread (`thp1sever.py` e `poolthp1server.py`).


