![[Screenshot 2023-11-28 at 14.26.59.png]]

**Esempio**. Cigno ed anatra.
```java
public interface Duck {
	public void display();
	public void swim();
}

public class Duckling implements Duck {
	public void display(){
		...
	}

	public void swim() {
		...
	}
}
```

```java
public interface Swan {
	public void show();
	public void swim();
}

public class HunglyDuckling implements Swan {
	public void display(){
		...
	}

	public void swim() {
		...
	}
}
```

Abbiamo così in questo caso due gerarchie e la necessità di confrontarsi con gli oggetti in modo uniforme. La soluzione con un adapter sarebbe la seguente:

![[Screenshot 2023-11-28 at 14.31.37.png]]

**Hugly duckling con Adapter**
![[Screenshot 2023-11-28 at 14.31.53.png]]

*Definizione* (**Adapter**): Il pattern Adapter converte l'interfaccia di una classe in un altra interfaccia che il client si aspetta. L'adapter lascia che le classi lavorino insieme nonostante non potrebbero visto che hanno interfacce diverse.

La delega viene utilizzata per vincolare un adattatore a un idoneo. L'ereditarietà dell'interfaccia viene utilizzata per specificare l'interfaccia della classe Adapter.
Target e Adaptee (solitamente chiamato sistema legacy) preesistono all'adattatore.
Il target può essere realizzato come interfaccia in Java.

![[Screenshot 2023-11-28 at 14.34.57.png]]

**Partecipanti**:
- **Target**: definisce l'application-specific interface che il client userà.
- **Client**: Collabora con gli oggetti conformi all'interfaccia target.
- **Adaptee**: Definisce un interfaccia esistente che ha bisogno di essere adattata.
- **Adapter**: Adatta l'interfaccia dell'adaptee all'interfaccia target.

L'adattatore può giocare il ruolo di una strategia concreta: se abbiamo diversi moduli
che implementano le stesse funzionalità e abbiamo scritto adattatori per loro, abbiamo un set di adattatori che implementano la stessa interfaccia. Possiamo quindi sostituire il
oggetti adattatori in fase di esecuzione.
