**Esempio**
Una fabbrica di cioccolato sta gestendo dei bollitori di cioccolata. Il lavoro del boiler è prendere il cioccolato ed il latte, mettere entrambi a bollire, e passarli poi alla fase successiva per fare delle barrette di cioccolato. Una delle funzionalità del sistema è di prevenire incidenti come drenare 500 litri di miscela non bollita, o filtrare il contenuto bollito quando è già pieno, o bollire un contenitore vuoto.

La caldaia è controllata dal Classe ChocolateBoiler. La classe ChocolateBoiler ha due attributi booleani vuoti e bollito cinque metodi fill(), drain(), bollire(), isEmpty() e isBoiled()

![[Screenshot 2023-11-27 at 11.58.43.png | 200]]

I metodi in questa classe sono:
- {empty} fill { !empty }
- {!empty and !boiled} boil() { !empty and boiled}
- {!empty and boiled} drain() { empty }

**Problema**
La caldaia del cioccolato è traboccata! Esso aggiunto anche più latte al mix
anche se era pieno!! Quello che è successo? Suggerimento: cosa succede se più di due le istanze di ChocolateBoiler sono creato? Il problema riguarda due casi controllare la stessa caldaia fisica.

Da qui possiamo analizzare in singletton pattern. 
- **Scopo**: Assicurati che una classe abbia solo un'istanza e fornire un punto di accesso globale ad esso.
- **Motivazioni**:  A volte vogliamo che nel sistema esista una sola istanza di una classe; Ad esempio, vogliamo un solo window manager. Oppure una sola fabbrica per una famiglia di prodotti. Dobbiamo avere quell'istanza facilmente accessibile e vogliamo garantire che non possano essere create istanze aggiuntive della classe.

**Riconoscere un singletton**
Gli oggetti unici non sono rari La maggior parte degli oggetti in un'applicazione hanno una responsabilità unica. Tuttavia le classi singleton sono relativamente rare Il fatto che un oggetto/classe sia unico non significa che il modello Singleton sia in funzione.

Come possiamo prevenire che altri sviluppatore creino nuove istanze di una tua classe?
- Creare un singolo costruttore con accesso privato.
```java 
private static ChococateBoiler _chocolateBoiler = new ChocolateBoiler()
```
- Creare un unica istanza reperibile da un metodo.
```java
public static ChocolateBoiler() getChocolateBoiler() {
	if(_chocolateBoiler == null){
		_chocolateBoiler = new ChocolateBoiler();
		// ....
	}
	return this->_chocolateBoiler
}
```
Restituisce una istanza del singleton create all'inizio, durante la prima chiamata.

![[Screenshot 2023-11-27 at 12.27.20.png]]

Perché usare una inizializzazione Lazy?
Potrebbe non avere informazioni sufficienti per istanziare a singleton al momento dell'inizializzazione statica. Esempio: un singleton ChocolateBoiler potrebbe dover attendere che le macchine della fabbrica reale stabiliscano canali di comunicazione.

Se il singleton richiede molte risorse e potrebbe non esserlo necessario. Esempio: un programma che ha una funzione di query opzionale che richiede una connessione al database.

```java
public class ChocolateBoiler {
	private static ChocolateBoiler _chocolateBoiler;
	private ChocolateBoiler() {}
	
	public static ChocolateBoiler() getChocolateBoiler() {
		if(_chocolateBoiler == null){
			_chocolateBoiler = new ChocolateBoiler();
			// ....
		}
		return _chocolateBoiler
	}
}
```

**UML class diagram**
![[Screenshot 2023-11-27 at 12.31.14.png]]

o nel nostro esempio il diagramma sarebbe:
![[Screenshot 2023-11-27 at 12.30.54.png]]
### Multi-threading
C'è però in questo caso un problema con i threads.

**Esempio**. Se il programma viene eseguito in un ambiente multi-thread è possibile che due thread inizializzino due singleton a più o meno nello stesso periodo.

![[Screenshot 2023-11-27 at 12.32.12.png]]

Nel caso del multithreading con più di un processore il metodo getInstance() potrebbe essere chiamato più o meno nello stesso momento, determinando la creazione di più di un'istanza. Possibili soluzioni:
1. Passa a un'istanza creata con eagerly anziché a una lezy. Ma la memoria può essere allocata e non utilizzata.
2. Sincronizzare il metodo getInstance(). Svantaggio: la sincronizzazione può ridurre le prestazioni del sistema.
3. Utilizzare una chiusura a doppio controllo. L'idea è quella di evitare la costosa sincronizzazione per tutte le invocazioni del metodo tranne la prima.

**Soluzione 1**
```java
// Data elements
private static Singleton uniqueInstance = new Singleton();

private Singleton() {}

public static Singleton getInstance() {
	return uniqueInstance 
}
```
Soluzione semplice, ma verrebbe allocata della memoria che potrebbe non essere usata.

**Soluzione 2**
```java
public static synchronized Singleton getInstance() {
	...
}
```
Svantaggio: la sincronizzazione può ridurre le prestazioni del sistema.
La sincronizzazione, tuttavia, è costosa ed è necessaria solo la prima volta che viene creata l'istanza univoca. Da utilizzare solo se le prestazioni del metodo getInstance() non sono critiche per l'applicazione.

**Soluzione 3**
```java
private volatile static Singleton uniqueInstance;
private Singleton() {}

public static Sinleton getInstance() {
	if(uniqueInstance == null) {
		synchronized (Singleton.class) {
			if (uniqueInstance == null) {
				uniqueInstance == new Singleton();
			}
		}
	}
	return uniqueInstance;
}
```

Spiegazione del doppio checking:
![[Screenshot 2023-11-27 at 12.40.19.png]]

### Singleton con sottoclassi
Cosa succede se vogliamo essere in grado di sottoclassare Singleton e fare in modo che la singola istanza sia un'istanza di sottoclasse? Ad esempio, supponiamo che MazeFactory abbia sottoclassi EnchantedMazeFactory e AgentMazeFactory. Noi vogliamo istanziarne solo uno. Come potremmo farlo?
1. Chiedi al metodo statico getInstance() di MazeFactory di determinare la particolare istanza della sottoclasse da istanziare. Questo potrebbe essere fatto tramite una discussione o variabile d'ambiente. I costruttori delle sottoclassi in questo caso non possono essere privati ​​e quindi i client potrebbero istanziare altre istanze delle sottoclassi.
2. Chiedi a ciascuna sottoclasse di fornire un metodo getInstance() statico. Ora i costruttori della sottoclasse possono essere privati.

**Soluzione 1**
Il metodo example() di MazeFactory determina la sottoclasse da istanziare.
```java
public abstract class MazeFactory {
// The private reference to the one and only instance. 
private static MazeFactory uniqueInstance = null; 
// Create the instance using the specified String name. 
public static MazeFactory getInstance(String name) { 
	if(uniqueInstance == null) 
		if (name.equals("enchanted")) 
			uniqueInstance = new EnchantedMazeFactory(); 
		else if (name.equals("agent")) 
			uniqueInstance = new AgentMazeFactory(); 
	return uniqueInstance;
}
//this may not be the one specified by the parameter
}
```

In questa soluzione però c'è un problema. I costruttori di EnchantedMazeFactory e
AgentMazeFactory non può essere privato, poiché MazeFactory deve essere in grado di istanziarli. Pertanto, i clienti potrebbero potenzialmente istanziare altre istanze di queste sottoclassi.

Inoltre, il metodo getInstance(String name) viola il principio OpenClosed, poiché deve essere modificato per ogni nuova sottoclasse MazeFactory. Potremmo usare i nomi delle classi Java come argomento per il file metodo example(String), che produce un codice più semplice:

```java
public static MazeFactory getInstance(String name) { 
	if (uniqueInstance == null) 
	//Usa la reflection per creare un'istanza della 
	// classe specificata da nome
	uniqueInstance = Class.forName(name).newInstance(); 
	return uniqueInstance; 
}
```

**Soluzione 2**
Per ogni sottoclasse mettiamo a disposizione uno static instance method()
```java
public abstract class MazeFactory { 
// The protected reference to the one and only instance. 
protected static MazeFactory uniqueInstance = null; 
// The MazeFactory constructor. If you have a default 
// constructor, it can not be private here! 
protected MazeFactory() {} 
// Returns a reference to the single instance. 
public static MazeFactory getInstance() {return uniqueInstance;}}
```

```java
public class EnchantedMazeFactory extends MazeFactory { 
	// Return a reference to the single instance. 
	public static MazeFactory getInstance() { 
		if(uniqueInstance == null) 
			uniqueInstance = new EnchantedMazeFactory();
		return uniqueInstance; 
	} 
	// Private subclass constructor 
	private EnchantedMazeFactory() {} 
}
```

Il codice del client per creare la factory la prima volta:
```java
MazeFactory factory = EnchantedMazeFactory.getInstance();
```
Il client code per accedere alla factory:
```java
MazeFactory factory = MazeFactory.getInstanze();
```
Si noti che ora i costruttori delle sottoclassi sono privati. È possibile creare solo un'istanza della sottoclasse! Si noti inoltre che il client può ottenere un riferimento nullo se invoca MazeFactory.getInstance() prima che l'istanza della sottoclasse univoca venga creata per la prima volta. Infine, tieni presente che uniqueInstance ora è protetta!

**Attributi statici in una classe (memento)**
Ogni oggetto di una classe ha la propria copia di tutte le variabili di istanza di quella classe. Tuttavia, in alcuni casi, tutti gli oggetti della classe dovrebbero condividere solo una copia di una particolare variabile.

Tali variabili sono chiamate variabili statiche. Un programma contiene in memoria solo una copia di ciascuna variabile statica di una classe, indipendentemente da quanti oggetti della classe sono stati istanziati.

Una variabile statica rappresenta le informazioni a livello di classe. Tutti gli oggetti della classe condividono lo stesso elemento di dati statici.

È possibile accedere agli attributi statici pubblici di una classe tramite il file
nome della classe e operatore punto (ad esempio Math.PI). È possibile accedere agli attributi statici privati ​​solo tramite metodi e proprietà di quella classe.

### Pro e contro Singleton
**Pro**:
- Con un singleton puoi passare l'oggetto come parametro a un altro
metodo. 
- Con un singleton è possibile derivare una classe base.
- Con un singleton puoi utilizzare un pattern factory per creare la tua istanza (e/o scegliere quale classe istanziare).
**Contro**:
- Questi: https://www.oracle.com/technical-resources/articles/java/singleton.html