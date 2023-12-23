# Trasformazione di schemi
L'obbiettivo della progettazione logica è quello di "tradurre" lo schema concettuale in uno schema logico relazionale che rappresenti gli stessi dati in maniera corretta ed efficiente. Questo richiede una ristrutturazione del modello concettuale.

*Osservazione*: Non si tratta di una pura e semplice traduzione. Infatti alcuni costrutti dello schema concettuale non sono direttamente rappresentabili, nel modello logico è necessario tenere conto delle prestazioni.

I dati in ingresso sono:
- Lo schema concettuale
- Le informazioni sul carico applicativo (dimensioni dei dati e caratteristiche delle operazioni)
- Un modello logico
I dati in uscita invece sono:
- Lo schema logico
- La documentazione associata

La trasformazione di uno schema ad oggetti in uno schema relazionale avviene eseguendo i seguenti passi:
1. Rappresentazione delle associazioni uno ad uno e uno a molti.
2. Rappresentazione delle associazioni molti a molti o non binarie.
3. Rappresentazione delle gerarchie di inclusione.
4. Identificazione delle chiavi primarie.
5. Rappresentazione degli attributi mutlivalore.
6. Appiattimento degli attributi composti.

L'obbiettivo finale è quello di rappresentare le stesse informazioni; minimizzando la ridondanza; e produrre uno schema comprensibile, per facilitare la scrittura e manutenzione delle applicazioni.

**Esempio**. Schema concettuale
![[Screenshot 2023-11-22 at 20.13.14.png]]

Traduzione logica di uno schema
![[Screenshot 2023-11-22 at 20.14.35.png]]

## Rappresentazione delle associazioni
### Uno a molti
Le associazioni uno a molti si rappresentano aggiungendo agli attributi della relazione rispetto a cui l’associazione è univoca una chiave esterna che riferisce l’altra relazione.![[Screenshot 2023-11-22 at 20.15.23.png]]

**Esempio**. Dirige(Professore, Dipartimento) ha cardinalità (1:1).
Un professore può o non può dirigere un solo dipartimento, un dipartimento deve avere un (solo) professore come dirigente.

![[Screenshot 2023-11-22 at 20.16.26.png]]
### Uno ad uno
Le associazioni uno a uno si rappresentano aggiungendo la chiave esterna ad una qualunque delle due relazioni che riferisce l’altra relazione, preferendo quella rispetto a cui l’associazione è totale, nel caso in cui esista un vincolo di totalità.
![[Screenshot 2023-11-22 at 20.31.51.png]]

La direzione dell’associazione rappresentata dalla chiave esterna è detta “la diretta” dell’associazione. Ci sono alcuni vincoli sulla cardinalità delle associazioni uno a molti ed uno ad uno:
- Univocità della diretta.
- Totalità della diretta: si rappressenta imponendo un vincolo not null sulla chiave esterna.
- Univocità dell'inversa e totalità della diretta: si rappresenta imponendo un vincolo not null ed un vincolo di chiave sulla chiave esterna.

![[Screenshot 2023-11-22 at 20.34.16.png]]
### Molti a molti
Un’associazione molti a molti tra due classi si rappresenta aggiungendo allo schema una nuova relazione che contiene due chiavi esterne che riferiscono le due relazioni coinvolte; la chiave primaria di questa relazione è costituita dall’insieme di tutti i suoi attributi.
![[Screenshot 2023-11-22 at 20.36.19.png]]

**Esempio**. Associazioni molti a molti
![[Screenshot 2023-11-22 at 20.35.20.png]]

## Traduzione delle gerarchie
il modello relazionale non può rappresentare direttamente le gerarchie. Bisogna eliminare le gerarchie, sostituendole con classi e relazioni:
1. accorpamento delle figlie della gerarchia nel genitore (**relazione unica**).
2. accorpamento del genitore della gerarchia nelle figlie (**partizionamento orizzontale**)
3. sostituzione della gerarchia con relazioni (**partizionamento verticale**).

### Relazione unica
Se $A_0$ è la classe genitore di $A_1$ ed $A_2$, le classi $A_1$ e $A_2$ vengono eliminate ed accorpate ad $A_0$. Ad $A_0$ viene aggiunto un **attributo (Discriminatore)** che indica da quale delle classi figlie deriva una certa istanza, e gli attributi di $A_1$ ed $A_2$ vengono assorbiti dalla classe genitore, e assumono valore nullo sulle istanze provenienti dall’altra classe. 

Infine, una relazione relativa a solo una delle classi figlie viene acquisita dalla classe genitore e avrà comunque cardinalità minima uguale a 0, in quanto gli elementi dell’altra classe non contribuiscono alla relazione.

**Esempio**. Classe Corsi con due attributi Codice (la chiave), Nome e con due sottoclassi di tipo partizione: CorsiInterni, con un attributo Crediti, CorsiEsterni, con due attributi CorsoDiLaurea, AnnoAccademico.

![[Screenshot 2023-11-22 at 20.40.16.png]]

![[Screenshot 2023-11-22 at 20.48.57.png]]
### Partizionamento orizzontale
La classe genitore $A_0$ viene eliminata, e le classi figlie $A_1$ ed $A_2$ ereditano le proprietà (attributi, identificatore e relazioni) dell’classe genitore.

**Esempio**. Classe Corsi con due attributi Codice (la chiave), Nome e con due sottoclassi di tipo partizione: CorsiInterni, con un attributo Crediti, CorsiEsterni, con due attributi CorsoDiLaurea, AnnoAccademico.

![[Screenshot 2023-11-22 at 20.47.46.png]]

Il partizionamento orizzontale divide gli elementi della superclasse in più relazioni diverse, per cui non è possibile mantenere un vincolo referenziale verso la superclasse stessa; in conclusione, questa tecnica non si usa se nello schema relazionale grafico c’è una freccia che entra nella superclasse.

![[Screenshot 2023-11-22 at 20.49.23.png]]

### Partizionamento verticale
La gerarchia si trasforma in due associazioni uno a uno che legano rispettivamente la classe genitore con le classi figlie. In questo caso non c’è un trasferimento di attributi o di associazioni e le classi figlie $A_1$ ed $A_2$ sono identificate esternamente dalla classe genitore $A_0$. 

Nello schema ottenuto vanno aggiunti dei vincoli: ogni occorrenza di $A_0$ non può partecipare contemporaneamente alle due associazioni, e se la gerarchia è totale, deve partecipare ad almeno una delle due.

**Esempio**
Classe Corsi con due attributi Codice (la chiave), Nome e con due sottoclassi di tipo partizione: CorsiInterni, con un attributo Crediti, CorsiEsterni, con due attributi CorsoDiLaurea, AnnoAccademico.

![[Screenshot 2023-11-22 at 20.51.17.png]]

![[Screenshot 2023-11-22 at 20.51.35.png]]
## Attributi mutlivalore
**Esempio**. Campo multi-valore. Gestione persone con <<più>> indirizzi email.

![[Screenshot 2023-11-22 at 20.52.35.png]]

![[Screenshot 2023-11-22 at 20.53.07.png]]

![[Screenshot 2023-11-22 at 20.53.17.png]]

![[Screenshot 2023-11-22 at 20.53.43.png]]