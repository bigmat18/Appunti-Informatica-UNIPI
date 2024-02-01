Consideriamo una classe con due metori, push() e pull() il comportamento cambia a seconda dello stato dell'oggetto. Per inviare la richiesta push e pull all'oggeto, utilizzeremo la seguente GUI con i pulsanti "Push" e "Pull".
![[Screenshot 2024-01-09 at 13.13.31.png | 400]]
Lo stato dell'oggetto sarà indicato dal colore della part top della gui. Gli stati sono: nero, rosso, blue e verde.
![[Screenshot 2024-01-09 at 13.15.29.png | 500]]
**Esempio**. Senza un pattern state.
```java
/*
*La classe ContextNoSP ha un comportamento che dipende dal suo stato. I metodi
*push() e pull() * fanno cose diverse a seconda dello stato dell'oggetto.
*Questa classe NON utilizza il modello State.
*/
public class ContextNoSP {
	// The state!
	public privateColor state = null;
	// Creates a new ContextNoSP with the specified state (color).
	public ContextNoSP(Color color) { state = color; }
	// Creates a new ContextNoSP with the default state 
	public ContextNoSP() {this(Color.red);}
	
	// Returns the state. 
	public Color getState() {return state;} 
	// Sets the state. 
	public void setState(Color state) {this.state = state;} 
	/** * The push() method performs different actions depending on the state of
	the object. Actually, right now the only action is to make a state
	transition. */
	public void push() { 
		if (state == Color.red) state = Color.blue; 
		else if (state == Color.green) state = Color.black; 
		else if (state == Color.black) state = Color.red; 
		else if (state == Color.blue) state = Color.green; 
	}
	/** * The pull() method performs different actions depending
	* on the state of the object. Actually, right now* the only action is to
	* make a state transition. */ 
	public void pull() { 
		if (state == Color.red) state = Color.green; 
		else if (state == Color.green) state = Color.blue; 
		else if (state == Color.black) state = Color.green; 
		else if (state == Color.blue) state = Color.red; 
	}
} 
```
Qui invece la parte che testa la GUI del programma.
```java
public class TestNoSP extends Frame implements ActionListener { 
	// GUI attributes. 
	private Button pushButton = new Button("Push Operation");
	private Button pullButton = new Button("Pull Operation");
	private Button exitButton = new Button("Exit"); 
	private Canvas canvas = new Canvas(); 
	
	// The Context. private ContextNoSP context = null;
	public TestNoSP() { 
		super("No State Pattern"); 
		context = new ContextNoSP(); 
		setupWindow(); 
	} 
	private void setupWindow() { 
	// Setup GUI 
	} 
	// Handle GUI actions. 
	public void actionPerformed(ActionEvent event) { 
		Object src = event.getSource(); 
		if (src == pushButton) { 
			context.push(); 
			canvas.setBackground(context.getState()); 
		} else if (src == pullButton) { 
			context.pull(); 
			canvas.setBackground(context.getState()); 
		} else if (src == exitButton) { 
			System.exit(0); 
		}
	}
	// Main method. public static 
	void main(String[] argv) { 
		TestNoSP gui = new TestNoSP(); 
		gui.setVisible(true); 
	}
}
```

### Intent
Consentire ad un oggetto di alterare il suo comportamento quando il suo stato interno cambia. L'oggetto apparirà come se avesse cambiato la sua classe.

**Esempio**
TCP connection risponde differentemente ai cliente in base agli stati: Established, Listening, Closed.

### Struttura
![[Screenshot 2024-01-09 at 14.50.42.png | 600]]
I **partecipanti** sono:
- **Context**: definisce l'interfacci di interesse per i client, mantiene un'instanza "ConcreateState" che definisce lo stato corrente.
- **State**: Definisce un'interfaccia per incapsulare il comportamento associato ad un particolare stato del contesto. Può anche essere una classe concreta con un'implementazione predefinita.
- **ConcreateState**: Ogni sottoclasse implementa un comportamento associato ad uno stato del contesto.

**Esempio**. State pattern esempio 1.
```java
/*
La classe astratta che definisce l'interfaccia per il comportamento di un particolare stato del Context
*/
public abstract class State {
	public abstract void handlePush(Context c);
	public abstract void handlePull(Context c);
	public abstract Color getColor();
}
```
Successivamente scriveremo le classi concrete State per ogni differente stato: RedState, BlackState, BlueState e GreenState. Per esempio qui abbiamo BlackState:
```java
public class BlackState extends State { 
	// Next state for the Black state: 
	// On a push(), go to "red" 
	// On a pull(), go to "green" 
	public void handlePush(Context c) { 
		c.setState(new RedState()); 
	} 
	public void handlePull(Context c) { 
		c.setState(new GreenState()); 
	} 
	public Color getColor() {
		return (Color.black);
	} 
}
```
Ora qui c'è la nuova classe Context che usa il pattern State le e le classi State:
```java
/** 
* Class Context has behavior dependent on its state. 
* This class uses the State pattern.
* Now when we get a pull() or push() request, we 
* delegate the behavior to our contained state object! 
* */ 
public class Context { 
	// The contained state. 
	private State state = null; // State attribute 
	
	// Creates a new Context with the specified state. 
	public Context(State state) {this.state = state;}
	
	// Creates a new Context with the default state. 
	public Context() {this(new RedState());} 
	
	// Returns the state. 
	public State getState() {return state;}
	 
	// Sets the state. 
	public void setState(State state) {this.state = state;}

	/** * The push() method performs different actions depending 
	* on the state of the object. Using the State pattern, 
	* we delegate this behavior to our contained state object. */ 
	public void push() {state.handlePush(this);} 
	
	/** * The pull() method performs different actions depending 
	* on the state of the object. Using the State pattern, 
	* we delegate this behavior to our contained state object. */ 
	public void pull() {state.handlePull(this);} 
}
```
![[Screenshot 2024-01-09 at 15.04.18.png | 600]]
### Osservazioni
1. L'invocazione dei metodi push() e pull() porta solo a una transizione di stato e nessun'altra azione viene eseguita. (Questo dipende dall'esempio scelto e potrebbe non valere in altri casi)
2. Gli stati concreti definiscono la transazione di stato, conoscono il loro "next state". Soluzione generalmente più flessibile, anche se causa dipendenza tra classi ConcreteState. Potrebbe inoltre essere il context a cambiare stato, nelle situazioni semplici.
3. Ogni volta che si cambia stato si crea un nuovo oggetto di tipo stato. Una scelta può essere creare oggetti state solo quando sono necessari e distruggerli in seguito. Ok se i cambiamenti di stato sono poco frequenti. Il pattern prevede anche il caso in cui gli oggetti stato sono creati in anticipo e non distrutti mai, questa cosa è ok se i cambiamenti di stato sono frequenti
4. Gli oggetti di tipo color hanno una variabile (final) context, anche questa è una scelta, context può essere passato per riferimento.

**Esempio**. Variante dove context viene passato come argomento.
![[Screenshot 2024-01-09 at 15.15.51.png | 600]]
**Esempio**. TCP state è abstract e definisce l'interfaccia. Ogni sotto classe di TCPState rappresenta uno stato.
![[Screenshot 2024-01-09 at 15.17.00.png | 600]]
**State: interfaccia o classe?**
State(TCPState) può essere una classe concreta dando una implementazione di default:
```java
void open(TCPConnection t) {}
void close(TCPConnection t) {}
void acknowledge(TCPConnection t, TCPOctetStream os) {}
```
ConcreateState(TCPEstablished, TCPListen, TCPClosed). Ogni sottoclasse implementa un comportamento specifico dello stato per le richieste valide nello stato.
```java
class TCPClosed extends TCPState{ 
	open( TCPConnection t ) { 
		// send SYN, receive SYN, ACK, etc. 
		ChangeState( t, new TCPEstablished: ); 
	} 
}
```
### Applicabilità
Utilizzare lo State pattern in uno dei seguenti casi:
- Il comportamento di un oggetto dipende dal suo stato e deve cambiare il suo comportamento a run-time in base a tale stato.
- Le operazioni hanno dichiarazioni condizionali complesse che dipendono dallo stato dell'oggetto.

### Applicazione del pattern in 6 passi
1. Identificare una classe esistente o crearne una nuova che funga da "macchina a stati" dal punto di vista del cliente. Questa classe è la classe "Context". 
2. Creare una classe base State che replichi i metodi dell'interfaccia della macchina a stati. Ogni metodo richiede un parametro aggiuntivo: un'istanza della classe Context. La classe State specifica qualsiasi comportamento utile "predefinito". 
3. Creare una classe derivata State per ogni stato del dominio. Queste classi derivate sovrascrivono solo i metodi che devono sovrascrivere. 
4. La classe Context mantiene un oggetto State "corrente". 
5. Tutte le richieste del client alla classe Context sono semplicemente delegate all'oggetto State corrente e viene passato il puntatore this dell'oggetto Context. 
6. I metodi State modificano lo stato "corrente" dell'oggetto Context, come specificato.

**Discussione**
- State localizza il comportamento che dipende dallo stato e lo suddivide tra i diversi stati.
- Tutti i comportamenti specifici di uno stato sono memorizzati in una classe.
- L'alternativa è costituita da case statement giganti.
- Può produrre un gran numero di classi, ma è meglio dell'alternativa.
- Rende esplicite le transizioni di stato.
- Lo stato corrente è memorizzato in un'unica posizione.
- Gli oggetti State possono essere condivisi. Quando non hanno variabili di istanza

**Implementazione**
Non possiamo usare una tabella di transizione degli Stati per tutto questo? Si ma più difficile da capire e più difficile aggiungere altre azioni e comportamenti.
State può essere una classe astratta, se c'è del comportamento comune o di default.

### State vs strategy
Ci sono delle similitudini tra i patterns State e Strategy, ad esempio, sono entrambi esempi di composizione con delega. La differenza sta nell'interno:
- Un oggetto state incapsula un comportamento dipendete dallo stato (ed eventualmente transizioni di stato)
- Un oggetto Strategy incapsula un algoritmo.
- In state un oggetto Context cambia stato in base a ben precise transizioni di stato.
![[Screenshot 2024-01-09 at 15.34.51.png]]
