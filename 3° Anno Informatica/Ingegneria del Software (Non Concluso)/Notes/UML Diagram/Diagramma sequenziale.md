Diagramma di sequenza
Questo genere di diagrammi si usano per descrivere le interazioni: scambi di messaggi e dati tra oggetti, organizzati in sequenza temporale:
- **In fase di analisi:** formalizzano la sequenza principale degli eventi
- **In fase di progettazione**: messaggi scambiati tra componenti, eventualmente comprendono anche attori, illustrano come l’architettura realizza i requisiti

### Elementi di un diagramma di sequenza
Oggetti partecipanti alle interazioni sono rappresentati con linee di vita formate da:
- Un rettangolo, che indica il ruolo (nell’interazione) e/o tipo dell’oggetto (uno dei due obbligatorio, entrambi solo se utile)
- Una linea verticale chiamato linea di vita dell’oggetto. Questa linea è tratteggiata quanto l’oggetto è inattivo, continua e doppia quando l’oggetto è attivo, Oggetti sempre attivi (es attori) hanno l’intera linea di vita continua e doppia.

![[Screenshot 2023-11-15 at 01.05.48.png | 500]]
Messaggi scambiati, l’ordine cronologico è dall’alto in basso, di default numerati.
### I messaggi
Rappresentano invocazione di operazione o segnali. Possono essere:
- Sincroni (1)
- Di return (1.1)(opzionali)
- Asincroni (2)(es invio di email)
- Asincroni con esplicito consumo di tempo (3)

![[Screenshot 2023-11-15 at 01.07.35.png]]
Sintassi dei messaggi: Id: attributo = nomeMessaggio(arg1, arg2,…) : valore di ritorno (id, tributo e valore di ritorno sono opzionali)

### Creare e distribuire partecipanti
Alcuni partecipanti possono essere aggiunti dinamicamente (N.B. la \<\<create>> o \<\<new>> è na dipendenza), cancellati.
![[Screenshot 2023-11-15 at 01.10.04.png]]

**Esempio** (che comprende anche vincoli di tempo e durata)
![[Screenshot 2023-11-15 at 01.10.37.png | 500]]

**Esempio** self Messages (chiamate di metodo)
![[Screenshot 2023-11-15 at 01.11.41.png]]
### Frame condizionale
![[Screenshot 2023-11-15 at 01.12.23.png | 500]]
- Più guardie vere: scelte non-deterministica
- Tutte le guardie false: il frame viene saltato

Esempio: frame condizionale
![[Screenshot 2023-11-15 at 01.13.15.png | 400]]
### Frame iterativo
![[Screenshot 2023-11-15 at 01.13.50.png | 400]]
Si itera: almeno min (3) e non più di max (7) volte (indipendentemente dal valore della condizione). Tra min e max si valuta la condizione (x>0) e si esegue il frame solo se questa è vera, altrimenti si esce.

**Esempio** di frame iterativo.
![[Screenshot 2023-11-15 at 01.15.16.png]]
- Il frame deve essere eseguito almeno una volta
- Alla seconda (e se non si è già alla terza) iterazione si controlla la guardia
- Dopo 3 iterazioni si esce comunque
### Loop VS while, do-while e for
- Loop(0,*) \[guardia\] (oppure loop\[guardia\]) modella: while(guardia){}
- Loop(1,*) \[guardia\] modella: do{ … } while(guardia)
- Loop(n,n) (oppure loop(n)) (senza guardia) modella: for(i=0; i<n; i++), attenzione non loop(0,n)
### Frame opzionale
Il frame opzionale fa a modellare if then (senza else). Le iterazioni contenute nel frame vengono eseguite solo se la guardia è vera, altrimenti si salta il frame.
![[Screenshot 2023-11-15 at 01.19.11.png]]
### Frame parallelo
Le iterazioni contenute nei due sotto-frammenti sono eseguite in parallelo (semantica a interleaving). Nell’esempio: le richieste dei due clienti possono arrivare in un ordine qualsiasi. 
![[Screenshot 2023-11-15 at 01.20.07.png]]
### Inclusione di una iterazione
Inclusione di una iterazione definita altrove. ‘Ref’ include il diagramma di sequenza indicato.
![[Screenshot 2023-11-15 at 01.21.04.png | 300]]
### Vincoli di durata
![[Screenshot 2023-11-15 at 01.21.34.png | 500]]
### Gates
Un gate (cancello) è un punto sul bordo del diagramma a cui è collegato un messaggio, in ingresso o in uscita. Il Gate ha un nome e sono utili quando si riferiscono (ref) altri diagrammi.

![[Screenshot 2023-11-15 at 01.22.40.png]]

**Esempio** riassuntivo.
![[Screenshot 2023-11-15 at 01.23.00.png | 400]]