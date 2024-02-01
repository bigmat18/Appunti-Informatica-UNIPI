Strategy pattern con l'esempio "Duck"
![[Screenshot 2024-01-09 at 15.38.33.png | 500]]
**Prima soluzione**
Fare l'ovverride. Il problema però è che in questo caso sottoclasse quando viene ereditata solo una parte del comportamento. Ogni volta che viene aggiunta una nuova papera, il progettista deve verificare se i metodi fly e quack devono essere sovrascritti.
```java
Override fly() 

class Rubberduck{ f
	ly() { \\ do nothing } 
	quack(){ \\ override to squeak } 
}
```
**Seconda soluzione**
Andare ad utilizzare le interfacce
![[Screenshot 2024-01-09 at 15.41.49.png | 500]]
**Terza soluzione**
Usare lo strategy pattern.
![[Screenshot 2024-01-09 at 15.42.53.png | 500]]
Definire una famiglia di algoritmi, incapsularli ciascuno e renderli intercambiabili. La strategia lascia variare l’algoritmo indipendentemente dai client che lo utilizzano. Un programma potrebbe dover fornire diverse varianti di un file algoritmo o di un comportamento.
Soluzione:
- Queste variazioni sono incapsulate in classi separate
- Esiste un accesso uniforme ad essi
### Struttura
![[Screenshot 2024-01-09 at 15.44.29.png | 600]]
I **partecipanti** sono:
- **Strategy**: definisce un'interfaccia comune per tutti gli algoritmi supportati
- **ConcreteStrategy**: Ogni concrete strategy implementa un algoritmo
- **Context**: contiene un riferimento all'oggetto strategy (con il tipo Strategy). Può definire un'interfaccia che consenta alla strategia di accedere ai propri dati. (Invece di passarli come argomenti quando si chiama la strategia metodi)

**Esempio**. Riprendendo l'esempio *duck*.
![[Screenshot 2024-01-09 at 15.47.44.png | 700]]
**Esempio**.
La classe MyArray rappresenta vettori di numeri. Uno dei suoi metodi stampo gli array in due formati:
- MathFormat (es. {12, -7, 3, ...})
- StandardFormat (es. ar\[0\]\_12, ar1[1]\_-7, ar[2]\_3, ...)
In oltre nel futuro questi formati possono essere sostituiti dal altri differenti.

**Problema**: Come si può isolare gli algoritmi usati per formattare il contenuto degli array, in modo che possa variare indipendentemente dagli altri metodi della classe?

**Soluzione**:
![[Screenshot 2024-01-09 at 15.53.08.png | 600]]
### Applicabilità 
Utilizza il modello di strategia ogni volta che:
- Molte classi correlate differiscono solo nel comportamento
- Sono necessarie diverse varianti di un algoritmo
- Un algoritmo utilizza dati di cui i client non dovrebbero essere a conoscenza. 
- Utilizzare il modello Strategia per evitare di esporre soluzioni complesse, strutture dati specifiche dell'algoritmo.
- Una classe definisce molti comportamenti e questi appaiono come più istruzioni condizionali nelle sue operazioni. Invece di molti condizionali, sposta i rami condizionali correlati nella propria classe Strategia.

### Discussione 
**Benefici**
- Fornisce un'alternativa alla sottoclasse della classe Context per ottenere una varietà di algoritmi o comportamenti.
- Elimina le istruzioni condizionali di grandi dimensioni.
- Fornisce una scelta di implementazioni per lo stesso comportamento
**Contro**
- Incrementi il numero di oggetti
- Tutti gli algoritmi devono usare la stessa Strategy interface.

ConcreteStrategy diverse potrebbero richiedere dati diversi. Molto probabilmente alcune ConcreteStrategy non utilizzeranno tutti i dati passati attraverso l'interfaccia generica. Quindi il contesto crea e inizializza parametri che non verranno mai utilizzati da nessuno. Quando questo rappresenta un problema: 
- accoppiamento più forte tra ConcreteStrategy e Contesto.
- il primo accede al secondo per richiederne i dati esigenze

**Esempio**. Sort.
Il problema è che una classe vuole decidere run-time quale algoritmo andrebbe usato per fare il sort di un array e sono disponibili molti algoritmi di sort.
La soluzione è incapsulare i different sort algorithms usando uno Strategy pattern.
![[Screenshot 2024-01-09 at 16.01.18.png | 600]]
**Esempio**. GUI.
Un oggetto componente testo della GUI desidera decidere in fase di esecuzione quale strategia utilizzare per convalidare l'input dell'utente. Sono possibili molte strategie di convalida diverse: campi numerici, campi alfanumerici, campi numerici di telefono, ecc.
La soluzione è incapsulare i differente input validation usando un Strategy pattern.
![[Screenshot 2024-01-09 at 16.02.33.png | 600]]
Questa è la tecnica utilizzata dai componenti di testo della GUI Java Swing. Ogni componente di testo ha un riferimento a un modello di documento che fornisce la strategia di convalida dell'input dell'utente richiesta.