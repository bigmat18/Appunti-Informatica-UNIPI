Tecnica basata sulla dimostrazione formale di correttezza di un modello finito (dimostrazione possibile) e istanziazione del modello.

**Esempio**. Protocollo «two-phase locking»: 
Si dimostra corretto se istanziato correttamente garantisce assenza di malfunzionamenti dovuti alla race condition.

**Osservazioni**: Ci sono applicazioni che non usano «two-phase locking» e sono corrette. Occorre comunque provare che il programma applica correttamente il protocollo, ma di solito è più facile che provare l’assenza di malfunzionamenti in generale.

**Triple di Hoare**
![[Screenshot 2023-11-29 at 19.06.47.png]]

**Model checking**
![[Screenshot 2023-11-29 at 19.07.21.png]]
