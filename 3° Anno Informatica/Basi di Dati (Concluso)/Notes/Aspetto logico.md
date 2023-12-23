*Definizione*: Un **modello dei dati** è un insieme di meccanismi di astrazione per descrivere la struttura delle conoscenza concreta.

*Definizione*: Uno **scema** è la descrizione della struttura della conoscenza concreta e dei vincoli di integrità usando un particolare modello dei dati.

Useremo come notazione grafica una variante dei cosi detti diagrammi ad oggetti o diagrammi ER (Entità-Relazione)

Nozioni fondamentali:
- Oggetti, Tipo di oggetto, classe
- Ereditarietò, Gerarchia tra tipi, Gerarchia fra classi.

![[Screenshot 2023-11-21 at 13.01.58.png]]

La conoscenza concreta riguarda i datti specifici che si vogliono rappresentare essi possono essere: le entità con le loro proprietà, le collezioni di entità omogenee e le associazioni fra entità.

*Definizione*: Le **entità** sono ciò di cui interessa rappresentare alcuni fatti (o proprietà).
Ogni entità appartiene ad un tipo detto **tipo di entità** che ne specifica la natura.

*Definizione*: Le **proprietà** sono fatti che interessano solo in quanto descrivono caratteristiche di determinate entità. Essi si possono vedere come coppie (Attributo, valore di un certo tipo).

**Esempio**
Una catena di negozi vende elettrodomestici e mantiene informazioni sui relativi centri di assistenza. Per ogni modello di elettrodomestico interessa il tipo, il peso, il prezzo di listino, e la marca.

Ogni proprietà ha associato un dominio, ovvero l’insieme dei possibili valori che tale proprietà può assumere:
- Proprietà **atomica** (o primitiva), se il suo valore non è scomponibile; altrimenti è detta strutturata.
- Proprietà **univoca**, se il suo valore è unico; altrimenti è detta multi-valore.
- Proprietà **totale** (obbligatoria), se ogni entità dell’universo del discorso ha per essa un valore specificato, altrimenti è detta **parziale** (opzionale).
- Proprietà **costante** altrimenti è detta **variabile**.
- Proprietà **calcolata** altrimenti è detta **non calcolabile**.

*Definizione*: Una **collezione** è un insieme variabile nel tempo di entità omogenee (dello stesso tipo).

![[Screenshot 2023-11-21 at 13.11.04.png]]

## Gli oggetti
Ad ogni entità del dominio corrisponde un oggetto del modello.

*Definizione*: un’entità software con stato, comportamento e identità, che modella un’entità dell’universo:
- Lo stato è modellato da un insieme di costanti o variabili con valori di qualsiasi complessità.
- Comportamento: un insieme di procedure locali chiamate metodi, che modellano le operazioni di base che riguardano l’oggetto e le proprietà derivabili da altre.

Un oggetto può rispondere a dei messaggi, restituendo valori memorizzati nello stato o calcolati con una procedura locale.

*Definizione*: una **classe** è un insieme di oggetti dello stesso tipo, modificabile con operatori per includere o estrarre elementi dall'insieme.

![[Screenshot 2023-11-21 at 13.13.22.png]]

Il primo passo nella costruzione di un modello consiste nella classificazione delle entità del dominio con la definizione dei tipi degli oggetti che le rappresentano.

*Definizione*: Un **tipo oggetto** definisce l'insieme dei messaggi (interfaccia) a cui può rispondere un insieme di possibili oggetti. I nomi dei messaggi sono detti anche attributi degli oggetti

**Il tipo oggetto dei diagrammi ER**
- I tipo oggetti non si rappresentano dei diagrammi, dove invece l'attenzione è sulle collezioni e sulle associazioni.
- Tuttavia, la rappresentazione grafica di una collezione indica anche gli attributi del tipo oggetto associato.
## Associazioni
*Definizione*: Un'istanza di associazione è un fatto che correla due o più entità stabilendo un legame logico tra di loro

*Definizione*: Un **associazione** $R(X, Y)$ fra due collezioni di entità $X$ e $Y$ è una insieme di istanze di associazioni tra elementi di $X$ ed $Y$, che varia in generale nel tempo. Essa è caratterizzata dalle seguenti due proprietà: **molteplicità** e **totalità**.

*Definizione*: Il **prodotto cartesiano** $(X \times Y)$ è detto dominio dell'associazione.

**Esempio**
![[Screenshot 2023-11-21 at 13.22.51.png]]

*Definizione*: (**vincolo di univocità**) Un'associazione $R(X,Y)$ è univoca rispetto a $X$:
- Se per ogni elementi $x \in X$ esiste al più un elemento di $Y$ che è associato a $x$.
- Se non vale questo vincolo, l'associazione è multi-valore rispetto a $X$.

Cardinalità dell'associazione:
- $R(X,Y)$ è (1:N) se essa è multi-valore su $X$ ed univoca su $y$.
- $R(X,Y)$ è (N:1) se essa è univoca su $X$ ed multi-valore su $y$.
- $R(X,Y)$ è (N:M) se essa è multi-valore su $X$ ed multi-valore su $y$.
- $R(X,Y)$ è (1:1) se essa è univoca su $X$ ed univoca su $y$.

![[Screenshot 2023-11-21 at 13.30.31.png]]

*Definizione* (Vincolo di totalità): Un'associazione $R(X,Y)$ è:
- **totale** (o surgettiva) su $X$ se per ogni elemento $x$ si $X$ esiste almeno un elemento di $Y$ che è associato ad $x$.
- se non vale questo vincolo, l'associazione è **parziale** rispetto ad $X$.

**Esempio**
Insegna(Professori, Corsi) è totale su Corsi in quanto non può esistere un corso del piano di studi senza il corrispondente docente che lo tiene.

### Rappresentazione delle associazioni
Un’associazione fra due collezioni $C_1$ e $C_2$ si rappresenta con una linea che collega le classi che rappresentano le due collezioni.

La linea è etichettata con il nome dell’associazione che di solito viene scelto utilizzando un predicato (“soggetto predicato complemento”).

L’univocità di un’associazione, rispetto ad una classe $C_1$, si rappresenta disegnando una freccia singola sulla linea che esce dalla classe $C_1$ ed entra nella classe $C_2$; l’assenza di tale vincolo è indicata da una freccia doppia. 

Similmente, la parzialità è rappresentata con un taglio sulla linea vicino alla freccia, mentre il vincolo di totalità è rappresentato dall’assenza di tale taglio.

**Esempio**. Tipi di associazioni fra Perone e Città.
- NataA(Persona, Città) ha cardinalità (N:1), totale su Persone e parziale su città.
- HaVisitato(Persone, Città) ha cardinalità (N:M), parziale su Persone e città.
- ÈSindacoDi(Persone, Città) ha cardinalità (1:1), totale su Persone e Città.
- ÈVissutaA(Persone, Città) ha cardinalità (N:M), parziale su Persone e Città.

**Terminologia**
![[Screenshot 2023-11-21 at 13.38.59.png]]

**Esempio** associazione fra studenti ed esami
Rappresentiamo le classi che rappresentano la situazione degli esami degli studenti, dove per esame si intende l’evento dell’esame superato (quindi registrato).

![[Screenshot 2023-11-21 at 13.40.23.png]]

Ogni esame riguarda uno ed un solo studente: univocità (freccia singola) e totalità (assenza del taglio). Vincolo di parzialità (taglio) e assenza di univocità sugli esami (freccia doppia) superati da uno studente.

![[Screenshot 2023-11-21 at 13.41.14.png]]

Esami (eventi degli esami): uno studente può sostenere zero o più esami. Un esame (evento, «istanza di verbalizzazione») riguarda esclusivamente uno studente.

Per dare l’informazione sulla cardinalità occorre dare 4 valori: Minimo e massimo per ciascuna delle due direzioni.

Le associazioni si modellano con un costrutto apposito.
![[Screenshot 2023-11-21 at 13.42.41.png]]

Le associazioni possono avere delle proprietà.
![[Screenshot 2023-11-21 at 13.43.12.png]]

Le associazioni possono essere ricorsive:
![[Screenshot 2023-11-21 at 13.43.36.png]]

![[Screenshot 2023-11-21 at 13.44.30.png]]

**Esempio**: molti a molti
![[Screenshot 2023-11-21 at 13.56.48.png]]

**Esempio**: una a uno.
![[Screenshot 2023-11-21 at 13.57.12.png]]
### Associazioni non binarie
Per semplicità non daremo una notazione grafica per rappresentare associazioni non binarie. Trasformazione di associazione ternaria in binarie (associazione fra Voli, Passeggeri e Posti)

![[Screenshot 2023-11-21 at 13.48.57.png]]

L'associazione è multi-valore rispetto ad ogni collezioni, poiché:
- Ogni singolo volo, passeggero, e posto, partecipa in generale a diverse istanze di associazione, ma con i vincoli che, in un singolo volo,
- ogni posto è associato al più ad un passeggero ed
- ogni passeggero può occupare al più un posto.

### Associazioni ricorsive
*Definizione*: Le **associazioni ricorsive** sono relazioni binarie fra gli elementi di una stessa collezione.

![[Screenshot 2023-11-21 at 13.51.34.png]]

Una persona può essere madre di più persone della collezione e può avere una madre nella collezione. 
Occorre etichettare la linea non solo con il nome dell’associazione, ma anche con dei nomi per specificare il ruolo che hanno le due componenti in un’istanza di associazione.

## Gerarchie 
Spesso le classi di entità sono organizzate in una gerarchia di specializzazione/generalizzazione. Una classe della gerarchia minore di altre viene detta sottoclasse (le altre sono superclassi). Due importanti caratteristiche delle gerarchie:
- **Eredietarietà** delle proprietà.
- gli elementi di una sottoclasse sono un sottoinsieme degli elementi della **superclasse**.

**Esempio**. La classe degli studenti universitari è una generalizzazione delle classi: matricole e dei laureandi, studenti in corso e studenti fuori corso, studenti pisani e studenti fuori sede.

Fra i tipi oggetto è definita una relazione di sottotipo, con le seguenti proprietà:
- È **assimentrica, rifressiva** e **transitiva** (relazione di ordine parziale).
- Se $T$ è **sottotipo** di $T'$ allora gli elementi di $T$ possono essere usati in ogni contesto in cui possano apparire valori di tipo $T'$ (sostituitività). In particolare: gli elementi di $T$ hanno tutte le proprietà degli elementi di $T'$, e per ogni proprietà di $T'$, il suo tipo in $T$ è un sottotipo del suo tipo in $T'$.
La gerarchia può essere **semplice** o **multipla**.

### Ereditarietà
*Definizione*: L'**ereditarietà** permette di definire un tipo oggetto a partire da un altro ed l'implementazioni di un tipo oggetto a partire da un'altra implementazione.

Normalmente l'eredità tra tipo si usa solo per definire sottotipi, e l'ereditarietà tra l'implementazione per definire l'implementazione di sottotipi (ereditarietà stretta); in questo caso: gli attribuiti possono essere solo aggiunti e gli attribuiti possono essere ridefiniti solo specializzandone il tipo.

![[Screenshot 2023-11-21 at 14.13.37.png]]

### Gerarchia tra classi
Fra le classi può essere definita una relazione di sottoclasse, detta anche **Sottoinsieme**, con le seguenti proprietà:
- È asimmetrica, riflessiva e transitiva.
- Se $C$ è sottoclasse di $C'$ allora il tipo degli elementi di $C$ è sottotipo del tipo degli elementi di $C'$ (vincolo *intensionale*)
- Se $C$ è sottoclasse di $C'$, allora gli elementi di $C$ sono un sottoinsieme degli elementi di $C'$ (vincolo estensionale).

**Esempio** Inclusione
![[Screenshot 2023-11-21 at 14.17.21.png]]

Vincoli su insiemi di sottoclassi.
- **Disgiunzione**: ogni coppia di sottoclassi in questo insieme è disgiunta, ovvero è priva di elementi comuni (sottoclassi disgiunte).
![[Screenshot 2023-11-21 at 14.18.52.png]]
- **Copertura**: l'unzione degli elementi delle sottoclassi coincide con l'insieme degli elementi della superclasse (sottoclassi copertura).
![[Screenshot 2023-11-21 at 14.19.46.png]]

**Esempio**.
![[Screenshot 2023-11-21 at 14.21.35.png]]

**Sottoclasi scorrelate**
Sottoclassi scorrelate, non richiedendo né il vincolo di copertura né quello di disgiunzione, si possono rappresentare anche nel seguente modo:

![[Screenshot 2023-11-21 at 14.24.52.png]]

### Gerarchie multiple
Un tipo può essere definito per ereditarietà a partire da un unico supertipo (ereditarietà singola) o da più supertipi (ereditarietà multipla).

*Definizione* (**Ereditarietà multipla**): è molto utile ma può creare alcuni problemi quando lo stesso attributo viene ereditato, con tipi diversi, da più tipi antenato.

![[Screenshot 2023-11-21 at 14.26.13.png]]
## Descrittore di classe con vincoli
I vincoli possono essere descritti in modo **dichiarativo** (da preferire), con formule del calcolo dei predicati, oppure mediante **controlli** da eseguire nelle opreazioni (di base o degli utenti).

![[Screenshot 2023-11-21 at 14.32.06.png]]

**Esempio**
Un impiegato può essere diretto solo del dipartimento a cui afferisce, nessun impiegato può guadagnare più del suo direttore, ogni impiegato deve risiedere nella città in cui ha sede il dipartimento.