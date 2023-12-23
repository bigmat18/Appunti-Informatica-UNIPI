Descrive il tipo degli oggetti che fanno parte di un sistema software o del suo dominio. La relazione statiche tra essi: **gli elementi e le relazioni tra essi non cambiano nel tempo.**
### Sintassi
![[Screenshot 2023-10-19 at 11.20.01.png]]

Il diagramma delle classe è usato per:
- Descrivere il dominio
- Progettazione di dettaglio

Quando si usa il diagramma delle classi per descrivere il dominio:
- Le operazioni normalmente si omettono (esempio i Setters ed i getters)
- I dettagli implementativi si omettono (esempio ID)
- Le visibilità si omettono
### Sintassi attuali

![[Screenshot 2023-10-19 at 11.22.22.png]]

‘+’ ==> PUBLIC: accessibile ad ogni elemento che può vedere e usare la classe
‘#’ ==> PROTECTED: accessibile ad ogni elemento discendente 
‘-‘ ==> PRIVATE: solo le operazioni della classe possono vedere e usare l’elemento in questione.
‘~’ ==> PACKAGE: accessibile sono agli elementi dichiarati nello steso package
### Sintassi operazioni
![[Screenshot 2023-10-19 at 11.24.12.png]]
Un concetto si modella con classe e non come attribuito quando può avere attributi propri, ed eventualmente operazioni.

OSSERVAZIONE: gli attributi e le operazioni statiche sono sottolineati
### Enumerazione
Le enumerazioni sono usate per specificare un insieme di valori prefissati, un enumerazione è la lista completa di tutti i valori che gli attributi di un determinato tipo possono assumere.

Esempio:
![[Screenshot 2023-10-19 at 11.27.16.png]]
### Relazioni
Una relazione può rappresentare un legame tra due o più oggetti, normalmente istanze di classi diverse.
![[Screenshot 2023-10-19 at 11.30.06.png]]
### Associazioni:
Una linea retta tra le classi, almeno uno tra nome o ruoli, raramente entrambi, e sereno a caratterizzare la relazione. Esempio:
![[Screenshot 2023-10-19 at 11.35.48.png]]

Si può scrivere sotto anche la  molteplicità tipo 0..1, oppure 1..*.  Esempio:
![[Screenshot 2023-10-19 at 11.37.18.png]]
### Aggregazione e Composizione.
Aggregazione e Composizione sono tipi particolari di associazione. Entrambe specificano che un oggetto di una classe è una parte di un oggetto di un’altra classe.
- <u>Aggregazione:</u> relazione tra oggetti poco forte. Ovvero una relazione nella quale le classi parte hanno un significato anche senza che sia presente la classe tutto.

![[Screenshot 2023-10-19 at 11.43.02.png]]

La stampante nel tempo può essere collegata a calcolatori diversi, la stampante esiste anche senza calcolatore, se il calcolatore viene distrutto la stampante esiste comunque, l’aggregazione non ha un nome.

- <u>Composizione:</u> relazione tra oggetti forte. La classe parte hanno un reale significato solo se sono legate alla classe tutto.
![[Screenshot 2023-10-19 at 11.43.11.png]]
Un pulsante appartiene a un solo mouse • Non esiste senza il suo mouse • Se il mouse viene distrutto vengono distrutti anche i pulsanti • La composizione non ha un nome
### Generalizzazione
Relazione tra un elemento generico e uno più specializzato. L’elemento più specializzato è consistente con quello più generico ma contiene più informazione. 
Vale il principio di sostituzione di Liskov: l’elemento specializzato può essere usato al posto dell’elmetto generico. È un tipo di:

![[Screenshot 2023-10-19 at 11.48.24.png]]
Si usa per indicare Eredieterietà di classe. Le sottoclassi possono aggiungere caratteristiche e ridefinire le operazioni. 
### Classi astratte ed interfacce 
- Le classi astratte si segnato o mettendo il nome in corsivo o scrivendo {abstract} sopra il nome della classe.
- Mentre le interfacce si scrive \<\<interface>>. Queste si usano in fase di progettazione, per classi con solo comportamento e senza stato.

### Dipendenze
Una relazione in cui le classi hanno ruolo di cliente e fornitore. Il cliente dipende dal fornitore, una modifica del fornitore può influenzare il cliente.
![[Screenshot 2023-12-07 at 13.01.24.png | 400]]
Esempi:
- Un parametro di un’operazione di A è di tipo B.
- Un’operazione di A restituisce un oggetto di tipo B.
- Un’operazione di A crea dinamicamente un oggetto di tipo B.

![[Screenshot 2023-10-19 at 12.03.17.png | 400]]
### Classi associate
Un’associazione può avere attributi propri, rappresentati con una classe associazione. Le istanze sono collegamenti con attributi propri. Voto non è attributo né di Corso né di Studente.

![[Screenshot 2023-10-19 at 12.04.09.png]]
Visto che per ogni coppia di oggetti collegati tra loro può esistere un unico oggetto della classe associazione, nell’esempio sopra se volessimo tracciare anche i voti negativi on si possono usare le classi associative. 
### Classi di analisi
Corrispondo a concetti concreti del dominio, per esempio descritti nel glossario, normalmente ciascuna classe di analisi sarà raffinata in una o più classi di progettazione. Alcune caratteristiche di queste classi sono:
- Astrazione di uno specifico elemento del dominio.
- Hanno un numero ridotto di responsabilità (funzionalità)
- Evitare di definire cassi “onnipotenti”
- Evitare funzioni travestite da classi
- Evitare gerarchie di ereditarietà profonde (>=3)

Operazioni e attributi solo quando veramente utili, le classi di analisi dovrebbero contenere attribuiti e operazioni ad “alto livello”, limitare le specifiche di tipo, valori etc. Non inventare mai niente rispetto a quanto scritto nel documento.

Principali tecniche di indicazione:
- **Data driven:** tipico della fase di analisi, si identificano tutti i dati del sistema e si dividono in classi.
- **Responsibility driven:** Sopratutto durante la progettazione. Si identificano le responsabilità e si dividono in classi.

## Diagramma degli oggetti
Chiamato anche diagramma delle istanze, può essere utile quando le connessioni tra gli oggetti sono complicate.
![[Screenshot 2023-10-19 at 12.25.14.png]]
### Collegamenti
Un collegamento è una istanza di una associazione. Collega due (o più) oggetti e non ha un nome. Se utile si possono indicare i ruoli. Non ha molteplicità, è sempre 1 a 1, la molteplicità di una associazione dice quanti collegamenti ci saranno a livello di istanza.

![[Screenshot 2023-10-19 at 12.27.50.png]]
