**Esempio**.
Un caffè di starbuzz ha creato un nuovo nome per migliorare la crescita di shop. Visto che stanno crescendo così velocemente stanno decidendo come aggiornare il loro sistema di ordini. 

![[Screenshot 2023-11-27 at 13.29.37.png]]

Per un caffè si può inoltre chiedere per una serie di condimenti come latte, soya ecc. Visto che ciascuno richide un piccolo cambiamento il sistema cresce velocemente di classi.
![[Screenshot 2023-11-27 at 13.31.37.png]]

Come alternativa possiamo optare non per aggiungere classi ma per mettere degli attributi dentro beverage per dire se aggiungere o meno roba.
![[Screenshot 2023-11-28 at 13.20.06.png]]

*Definizione* (**Open closed principle**): Estendere una classe non dovrebbe richiedere modifica su quella classe. Le entità software come classi, moduli e funzioni dovrebbero essere aperti per estensioni ma chiuse per modifiche.

Come soluzione possiamo costruire un ordine di un drink con i decorators:
1. Iniziamo con l'oggetto DarkRoast.
![[Screenshot 2023-11-28 at 13.23.26.png]]
2. Se il consumatore vuole Mocha andiamo a creare un oggetto Mocha ed a wrappare esso intorno a DarkRoast.
![[Screenshot 2023-11-28 at 13.24.38.png]]
3. Se il consumatore vuole anhe Whip, creeremo anche un Whip decorator e wrap Mocha con esso.
![[Screenshot 2023-11-28 at 13.25.33.png]]
4. In fine bisognerà calcolare il costo complessivo. Dovremo chiamare la funzione cost() del decoratore più esterno, che è whip, whip chiamerà a sua volta la funzione cost() dell'oggetto che sta wrappando e così via andando a calcolare il costo complessivo.![[Screenshot 2023-11-28 at 13.27.12.png]]

*Definizione* (**Decorator Pattern**): il decorator pattern va ad aggiungere responability agli oggetti dinamicamente. È una alternativa flessibile alle sottoclassi per estendere le funzionalità.

**Decorator pattern per l'esempio Starbuzz**
![[Screenshot 2023-11-28 at 13.28.18.png]]

**Decorator pattern in generale**
![[Screenshot 2023-11-28 at 13.30.04.png]]

**Partecipanti**
- Component: l'interfaccia del decorated objects.
- ConcreateComponent: La classe base dell'oggeto che può ricevere nuove responabilities.
- Decorator: Definisce un interfaccia conforme per tutti i decorator e mantiene un riferimento ad un oggetto di tipo componente (che può essere già decorato o no).
- ConcreateDecorator: definisce nuove responsability.

**Codice**
```java
public abstract class Beverage {
	String description = "Unknown Beverage";

	public String getDescription() {
		return description;
	}

	public abstract double cost();
}
```

**The abstract class of condiments**
```java
public abstract class CondimentDecorator extends Beverage {
	public abstract String getDescription();
}
```

**Concreate Base classes**
```java
public class Espresso extends Beverage {
	public Espresso() {
		description = "Espresso";
	}

	public double cost() {
		return 1.99;	
	}
}
```

**Una classe condimento concreta**
```java
// Mocha è un decorator quindi si estende con condimentdecorator
public class Mocha extends CondimentDecorator {
	// La beverage che andiamo a wrappare
	Beverage beverage;

	public Mocha(Beverage beverage){
		this.beverage = beverage;
	}

	public String getDescription() {
		return beverage.getDescription() + ", Mocha";
	}

	public double cost() {
		return .20 + beverage.cost();
	}
}
```

**Costruzione di una nuova bevanda da una classe decorator dinamicamente**
![[Screenshot 2023-11-28 at 13.41.43.png]]

Bisogna però stare attenti si possono generalemnte aggiungere decoratori trasparenti ed il client non saprà mai il rapporto con il decorator. Inoltre, se si scrive del codice che dipende ad un tipo specifico possono accadere cose spiacevoli.![[Screenshot 2023-11-28 at 14.18.51.png]]

**Decorator PRO**
- Più facile da usare che un eredietarià multipla.
- Può essere usato per mescolare più features.
- Si possono aggiungere proprietà più volte.
- Aggiungere funzionalità è più facile.

**Decorator CONTRO**
- Se il Decorator è completto diventa costoso usarlo in grossa quantità.
- Un decoratore e i suoi componenti non sono uguali. Dal punto di vista dell'identità dell'oggetto, un decorato il componente non è identico al componente stesso.Non fare affidamento sull'identità dell'oggetto quando si utilizzano i decoratori.
- Tanti piccoli oggetti spesso finiscono con sistemi composti da molti piccoli oggetti può essere difficile da capire e da eseguire il debug.

**Implementation issues**
Diversi problemi dovrebbero essere considerati quando si applica il Modello decoratore:
1. Conformità dell'interfaccia: L'interfaccia di un oggetto decoratore deve essere conforme all'interfaccia del componente che decora.
2. Omissione della classe astratta Decorator: Se è necessaria una sola responsabilità, non definire astratta Decoratore. Unisci la responsabilità del Decoratore nel ConcreteDecoratore.
3. Mantenere leggere le classi dei componenti: La classe Component è ereditata da componenti e decoratori. La classe del componente dovrebbe essere dedicata alla definizione di un'interfaccia, nessun'altra funzione. Ad esempio, la classe Component non deve essere utilizzato per memorizzare dati e definire dati. Questo dovrebbe essere fatto nelle sottoclassi. Se la classe Component diventa complesso, potrebbero farlo anche i decoratori pesante e costoso da utilizzare in quantità. Mantienilo leggero e semplice.
4. Cambiare la skin di un oggetto rispetto alle sue "guts": Le classi Decorator dovrebbero agire come uno strato di pelle sopra un oggetto. Se è necessario cambiare l’essenza dell’oggetto, usa la Strategia modello.