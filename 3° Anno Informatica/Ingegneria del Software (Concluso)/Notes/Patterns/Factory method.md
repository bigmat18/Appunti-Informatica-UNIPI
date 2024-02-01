*Definizione*: Il **factory method** lascia le sotto-classi decidere quale classe istaziare, non perché le classi stesse decidono in runtime ma perché il creatore scrive senza la conoscenza dei prodotti reali che verranno creati, che viene decisa dalla scelta della sottoclasse utilizzata. 

![[Screenshot 2023-11-16 at 13.56.52.png]]
- Product: definisce l’interfaccia per i tipo di oggetti che la factory method crea.
- ConcreateProduct: implementa la product interface
- Creator: dichiara il Factory method, il quale ritorna gli oggetti del tipo product.
- ConcreteCreator: fa l’ovveride del factory method per ritornare un istanza del ConcreateProduct.

**Esempio.**
Per dimostrare il modello del metodo di fabbrica, l'esempio della pizzeria si evolve andando ad includere la nozione di franchising diversi che esistono in diverse parti del paese (California, New York, Chicago).

Ogni franchising avrà bisogno della propria fabbrica per creare pizze che soddisfino le inclinazioni della gente del posto. Tuttavia, vogliamo mantenere il processo di preparazione che ha reso PizzaStore un così grande successo

Il Factory Method Design Pattern ti consente di farlo, inserendo il codice astratto, "codice per un'interfaccia" in una superclasse, inserimento del codice di creazione dell'oggetto in una sottoclasse, PizzaStore diventa una classe astratta con un metodo createPizza() astratto Creiamo quindi sottoclassi che sovrascrivono createPizza() per ogni regione.

![[Screenshot 2023-11-16 at 14.02.07.png]]

**Esempio.** Creazione di un labirinto.
![[Screenshot 2023-11-16 at 14.03.45.png]]

MazeGame class ha un metodo createMaze() che crea le component e le assembra (2 responsabilità)

![[Screenshot 2023-11-16 at 14.17.39.png]]

Il problema con createMaze() è la sua flessibilità.
E se volessimo avere labirinti incantati con EnchantedRooms e Enchanted Doors? O un labirinto di agenti segreti con DoorWithLock e WallWithHiddenDoor? Cosa dovremmo fare con il metodo createMaze()? Come si trova adesso, dovremmo apportarvi modifiche significative a causa delle istanziazioni esplicite utilizzando il nuovo operatore degli oggetti che compongono il labirinto.
Come possiamo riprogettare le cose per rendere più semplice per createMaze() creare labirinti con nuovi tipi di oggetti?

![[Screenshot 2023-11-16 at 14.30.38.png]]

createMaze implementa l’assemblaggio
![[Screenshot 2023-11-16 at 14.36.53.png]]

Abbiamo creato createMaze() solo leggermente di più complesso, ma molto più flessibile!
![[Screenshot 2023-11-16 at 14.37.40.png]]

Il metodo createMaze() di MazeGame è ereditato da EnchantedMazeGame, può essere utilizzato per creare labirinti regolari o labirinti incantati senza modifiche!

La ragione per cui questo funzione è che il metodo createMaze() di MazeGame differisce la creazione dell’oggetto male dalle sue sottoclassi. In questo esempio abbiamo che:
- Creator => MazeGame
- ConcreateCreator => EnchantedMazeGame
- Product => Wall, Room, Door
- ConcreateProduct => EnchantedWall, EnchantedRoom, EnchantedDoor
- Maze è il concrete Product (ma anche product.

Applicabilità. Utilizza il pattern Factory Method in una qualsiasi delle seguenti situazioni:
- Una classe non può anticipare la classe di oggetti che deve creare
- Una classe vuole che le sue sottoclassi specifichino gli oggetti che crea

Benefici:
- Il codice è reso più flessibile e riutilizzabile grazie all'eliminazione della creazione di istanze di classi specifiche dell'applicazione.
- Il codice si occupa solo dell'interfaccia della classe Product e può funzionare con qualsiasi classe ConcreteProduct che supporti questa interfaccia

Passività:
- I client potrebbero dover creare una sottoclasse della classe Creator solo per istanziare un particolare ConcreteProduct.

Problemi di implementazione:
- Il creatore può essere astratto o concreto.
- Il metodo di fabbrica dovrebbe essere in grado di creare più tipi di prodotti? Se è così, allora il metodo factory ha un parametro (possibilmente utilizzato in un if-else!) per decidere quale oggetto creare.
