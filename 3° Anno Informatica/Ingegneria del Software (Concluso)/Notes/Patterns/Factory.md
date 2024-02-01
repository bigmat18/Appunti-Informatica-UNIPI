La classe Factor è una il cui unico compito è creare e restituire facilmente istanze di altre classi. I modelli creazionali astraggono il processo di istanziazione dell'oggetto.
- Nascondono il modo in cui vengono creati gli oggetti e aiutano a creare il sistema complessivo indipendentemente da come i suoi oggetti vengono creati e composti.
- Rendono più semplice la costruzione di oggetti complessi invece di chiamare a costruttore, utilizza un metodo in una classe "factory" per impostare l'oggetto salva linee e complessità per costruire/inizializzare rapidamente oggetti

esempi in Java:
◦ bordi (BorderFactory),
◦ tasti premuti (KeyStroke),
◦ connessioni di rete (SocketFactory)

Ogni volta che is invoca la parola “new” per creare un nuovo oggetto andiamo a violare il principio “Code to an Interface”. Esempio List list = new ArrayList(). Anche se il tipo della nostra variabile è impostato su "interfaccia", in questo caso "List", la classe che contiene questa istruzione dipende da "ArrayList”.

Se hai del codice che controlla alcune variabili e istanza a particolare tipo di classe in base allo stato di tali variabili, la classe che la contiene dipende da ciascuna classe concreta a cui si fa riferimento. if (condizione) { return new ArrayList(); } else { return new LinkedList(); }

CI sono però così alcuni problemi evidenti: deve essere ricompilato se le classi cambiano, quindi se aggiungi nuove classi allora modifica questo codice o se rimuovi le classi esistenti modifica questo codice. Ciò significa che questo codice viola il principio aperto-chiuso e le informazioni che nascondono i principi di progettazione.

Vedremo da qui 3 tipologie di pattern di Factories:
1. **[[Simple factory]]** (detto anche Concrete Factory) questo non è un pattern Gof è una semplificazione molto diffusa di Abstract Factory.
2. **[[Factory method]]**: un tipo di pattern che si concentra sull’utilizzo dell’ereditarietà per capire l’oggetto da instanziare.
3. **[[Abstract factory]]**: Un pattern che si concentra sulla delegazione dell’istanziazione di altri oggetti.
4. **[[Pure fabrication]]**. Utile per la risoluzione di alcune problematiche.