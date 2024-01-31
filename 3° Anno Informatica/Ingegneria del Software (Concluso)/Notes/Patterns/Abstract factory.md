Lo scopo è quello di fornire un'interfaccia per la creazione di famiglie di prodotti correlati o oggetti dipendenti senza specificarne la concreta classe.

Il modello Abstract Factory rispetto al modello Factory Method ha che una classe delega la responsabilità dell'istanziazione dell'oggetto a un altro oggetto tramite composizione, mentre il pattern Factory Method utilizza l'ereditarietà e si basa su una sottoclasse per gestire l'istanziazione dell'oggetto desiderato. 

In realtà, l'oggetto delegato utilizza spesso factory method per eseguire l'istanziazione, applicando così entrambi i modelli.

![[Screenshot 2023-11-16 at 14.53.28.png | 400]]

Abstract factory applicato a MazeGame: abstract factory
![[Screenshot 2023-11-16 at 14.53.59.png |400]]

Concrete factory
![[Screenshot 2023-11-16 at 14.54.14.png | 400]]

Il cliente implementa l'assemblaggio e delega la costruzione delle parti.
Il metodo createMaze() della classe MazeGame accetta un riferimento MazeFactory come parametro:

![[Screenshot 2023-11-16 at 15.11.10.png | 400]]

Un altro concreate factory
![[Screenshot 2023-11-16 at 15.12.09.png | 450]]

In questo esempio, la correlazione sono le seguenti:
- AbstractFactory => MazeFactory
- ConcreteFactories => BasicMazeFactory e EnchantedMazeFactory
- AbstractProcuct => Wall, Room, Door
- ConcreateProduct => BasicWall, BasicRoom, BasicDoor, EnchantedWall, EnchantedRoom EnchantedDoor.

![[Screenshot 2023-11-16 at 15.14.11.png | 500]]

**Esempio**. Pizza Store.
L’approccio del metodo fabbrica alla pizzeria è un grande successo consentendo alla nostra azienda di creare più franchising in tutto il mondo
paese in modo rapido e semplice. Ma, cattive notizie, abbiamo appreso che alcuni franchise seguendo le nostre procedure (il codice astratto in PizzaStore li obbliga a farlo) lesinano sugli ingredienti per abbassare i costi e aumentare i marginiIl successo della nostra azienda è sempre dipeso dall'utilizzo di ingredienti freschi e di qualità quindi “Bisogna fare qualcosa!”

Modificheremo il nostro design in modo tale da essere abituato a una factory fornire gli ingredienti che servono durante la pizza
processo di creazione. Poiché regioni diverse utilizzano tipi diversi di ingredienti, creeremo sottoclassi specifiche per regione della fabbrica degli ingredienti per assicurarsi che vengano utilizzati gli ingredienti giusti; ma anche con requisiti specifici della regione, dato che lo siamo fornendo le factories, ci assicureremo che gli ingredienti che soddisfano i nostri standard di qualità siano utilizzati da tutti i franchising. Dovranno escogitare qualche altro modo per ridurre i costi.

Prima cosa ci serve una Factory Interface
![[Screenshot 2023-11-16 at 15.36.17.png | 400]]

Secondo dobbiamo implementare a Region-Specific Factory
![[Screenshot 2023-11-16 at 15.36.50.png | 400]]

Questa factory garantisce che durante il processo di creazione della pizza vengano utilizzati ingredienti di qualità, tenendo conto anche dei gusti delle persone che vivono a Chicago. Ma come (o dove) viene utilizzata questa fabbrica?

Pizza abstract base class
![[Screenshot 2023-11-16 at 15.37.56.png | 500]]

A pizza subclass
![[Screenshot 2023-11-16 at 15.38.29.png | 500]]

Quindi aggiorna Pizza sottoclassi per utilizzare la fabbrica! Nota: non abbiamo più bisogno di sottoclassi come NYCheesePizza e ChicagoCheesePizza perché ora si occupa della fabbrica di ingredienti differenze regionali

![[Screenshot 2023-11-16 at 15.39.08.png | 450]]

Dobbiamo aggiornare il nostro PizzaStore sottoclassi per creare il file fabbrica degli ingredienti appropriata e passarla a ciascuna sottoclasse di Pizza nel file crearePizzafabbrica metodo.