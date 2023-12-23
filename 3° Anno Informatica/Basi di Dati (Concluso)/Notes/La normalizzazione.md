## Introduzione
Ci sono due metodi per produrre uno schema relazione:
1. Partire da un buon schema a oggetti e tradurlo
2. Partire da uno schema relazionale fatto da altri e modificarlo o completarlo.

Teoria della progettazione relazionale: studia cosa sono le “anomalie” e come eliminarle **(normalizzazione)**. 
È particolarmente utile se si usa il metodo (1). È moderatamente utile anche quando si usa il metodo (2).

### Schemi con anomalie
**Esempio**
StudentiEdEsami(Matricola, Nome, Provincia,AnnoNascita, Materia, Voto)

**Le anomalie sono:** 
Ridondanze, Potenziali inconsistenze, Anomalie nelle inserzioni, Anomalie nelle eliminazioni.

**Soluzione:** dividiamo lo schema in due tabelle. 
Studenti (Matricola, Nome, Provincia, AnnoNascita), Esami (Nome, Materia, Voto)
### Obbiettivi
Nozione base: dipendenze funzionali. Obiettivi della teoria:
- **Equivalenza** di schemi: in che misura si può dire che uno schema rappresenta un altro.
- **Qualità** degli schemi (forme normali).
- **Trasformazione** degli schemi (normalizzazione di schemi)

Ipotesi dello schema di relazione universale: Tutti i fatti sono descritti da attributi di un’unica relazione (relazione universale), cioè gli attributi hanno un significato globale.

*Definizione*: Lo schema di **relazione universale** U di una base di dati relazionale ha come attributi l’unione degli attributi di tutte le relazioni della base di dati.

*Definizione*: Una **forma normale** è una proprietà di una base di dati relazionale che ne garantisce la “qualità”, cioè l'assenza di determinati difetti.

Quando una relazione non è normalizzata: 
- presenta ridondanze, 
- si presta a comportamenti poco desiderabili durante gli aggiornamenti

La normalizzazione è una procedura che permette di trasformare schemi non normalizzati in schemi che soddisfano una forma normale.

**Perché questi fenomeni sono indesiderabili?**
![[Screenshot 2023-12-06 at 15.47.56.png]]
- **Ridondanza**: Lo stipendio di ciascun impiegato è ripetuto in tutte le ennuple relative. Questo perché lo stipendio dipende solo dall’Impiegato. Il costo del bilancio per ogni progetto è ripetuto.
- **Anomalia di aggiornamento**: Se lo stipendio di un impiegato varia, è necessario andarne a modificare il valore in diverse ennuple.
- **Anomalia di cancellazione**: Se un impiegato interrompe la partecipazione a tutti i progetti, dobbiamo cancellare tutte le ennuple in cui appare, e in questo modo l’impiegato non sarà più presente nel database.
- **Anomlia di inserimento**: Un nuovo impiegato non può essere inserito finché non gli viene assegnato un progetto.

### Linee guida per una corretta progettazione
**Semantica degli attributi**
Si progetti ogni schema relazionale in modo tale che sia semplice spiegarne il significato. Non si uniscano attributi provenienti da più tipi di classi e tipi di associazione in una unica relazione.

**Ridondanza**
Si progettino gli schemi relazionale in modo che nelle relazioni non siano presenti anomalie di inserimento, cancellazione o modifica. Se sono presenti delle anomalie (che si vuole mantenere), le si rilevi chiaramente e ci si assicuri che i programmi che aggiornano la base di dati operino correttamente.

**Valori nulli**
Per quanto possibile, si eviti di porre in relazione di base attributi i cui valori possono essere (frequentemente) nulli. Se è inevitabile, ci si assicuri che essi si presentino solo in casi eccezionali e che non riguardino una maggioranza di tuple nella relazione.

**Tuple spurie**
Si progettino schemi di relazione in modo tale che essi possano essere riuniti tramite JOIN con condizioni di uguaglianza su attributi che sono o chiavi primarie o chiavi esterne in modo da garantire che non vengano generate tuple spurie. Non si abbiano relazioni che contengono attributi di «accoppiamento» diversi dalle combinazioni chiave esterna-chiave primaria.

## Dipendenza funzionali
Per formalizzare la nozione di schema senza anomalie, occorre una descrizione formale della semantica dei fatti rappresentati in uno schema relazionale.

**Istanza valida di R**: è una nozione semantica, che dipende da ciò che sappiamo del dominio del discorso (non estensionale, non deducibile da alcune istanze dello schema).

Istanza valida r su R(T). Siano X, Y due sottoinsiemi non vuoti di T, esiste in r una **dipendenza funzionale** da X a Y se, per ogni coppia di ennuple $t_1, t_2$ di r con gli stessi valori su X, risulta che $t_1, t_2$ hanno gli stessi valori anche su Y.

La dipendenza funzionale da X a Y si denota con $X \rightarrow Y$.
**Esempio**
Persone (CodiceFiscale, Cognome, Nome, DataNascita).
CodiceFiscale $\rightarrow$ Cognome, Nome.

**Dipendenza funzionale vs chiave**
Istanza valida r su R(T) - Siano X e Y due sottoinsiemi non vuoti di T, esiste in r una dipendenza funzionale da X a Y (X→Y) se, per ogni coppia di ennuple t1 e t2 di r con gli stessi valori su X, risulta che t1 e t2 hanno gli stessi valori anche su Y.

**Esempio**
StudentiEdEsami(Matricola, Nome, Provincia,AnnoNascita, Materia, Voto)
Matricola → Nome, Provincia, AnnoNascita

*Definizione* (**Dipendenza funzionale**): Dato uno schema R(T) e X, $Y \subseteq T$, una dipendenza funzionale ( DF ) fra gli attributi X e Y, è un vincolo su R sulle istanze della relazione, espresso nella forma: $X \to Y$ 

i.e. X determina funzionalmente Y o Y è determinato da X, se per ogni istanza valida r di R un valore di X determina in modo univoco un valore di Y: $\forall$ r istanza valida di R:
$$\forall t1, t2 \in r \:se\: t1[X] = t2[X] \Rightarrow t1[Y] = t2[Y]$$
In altre parole: un’istanza r di R(T) soddisfa la dipendenza X → Y, (o X → Y vale in r), se per ogni coppia di ennuple t1 e t2 di r, se t1[X] = t2[X] allora t1[Y] = t2[Y].

**Esempio**
$\forall$ r istanza valida di R $\forall t1, t2 \in r \:se\: t1[X] = t2[X] \Rightarrow t1[Y] = t2[Y]$
Questa tabella soddisfa la dipendenza funzionale Matricola $\rightarrow$ Cognome.
![[Screenshot 2023-12-07 at 01.19.42.png]]

Si dice anche che:
- un instnza $r_0$ di R **soddisfa la DF** $X \rightarrow Y (r_0 |= X \rightarrow Y)$ se la proprietà vale per $r_0$ $\forall t1, t2 \in r \:se\: t1[X] = t2[X] \Rightarrow t1[Y] = t2[Y]$
- e che un istanza $r_0$ di R soddisfa un insieme F di DF se per ogni $X \rightarrow Y \in F$ vale che $r_0 |= X \rightarrow Y$ e questo se e solo se $\forall t1, t2 \in r \:se\: t1[X] = t2[X] \Rightarrow t1[Y] = t2[Y]$

**Esempio**
![[Screenshot 2023-12-07 at 01.23.42.png]]

Abbiamo usato un'unica relazione per rappresentare informazioni eterogenee:
- gli impiegati con i relativi stipendi (Impiegato → Stipendio)
- i progetti con i relativi bilanci (Progetto → Bilancio)
- le partecipazioni degli impiegati ai progetti con le relative funzioni (Impiegato Progetto → Funzione).

**Dipendente funzionali atomiche**
Ogni dipendenza funzionale X → A1 A2 …An , si può scomporre nelle dipendenze funzionali X → A1 , X → A2 , … , X → An Le dipendenze funzionali del tipo X → A si chiamano **dipendenze funzionali atomiche**.

**Esempio**. DotazioniLibri(CodiceLibro, NomeNegozio, IndNegozio, Titolo, Quantità)
CodiceLibro, NomeNegozio → IndNegozio, Titolo, Quantità ==>
CodiceLibro, NomeNegozio → IndNegozio
CodiceLibro, NomeNegozio → Titolo 
CodiceLibro,NomeNegozio → Quantità

**Esempio**
![[Screenshot 2023-12-07 at 01.27.30.png]]
PrezzoTot è il Prezzo di vendita Assumiamo che: Il tipo si riferisca ad una sola componente. Quali sono le dipendenze funzionali? Chiave: Kit, Tipo

Ridondanze:
- PrezzoTot è ripetuto in ogni tupla che si riferisce allo stesso kit.
- PrezzoComp è ripetuto in ogni tupla che ha lo stesso valore di Tipo e Fornitore
- Componente è ripetuto in ogni tupla che ha lo stesso Tipo

Quali sono le dipendenze funzionali? 
- Tipo → Componente 
- Kit → PrezzoTot 
- Kit,Tipo → PrezzoComponente, QuantComp, Fornitore

*Definizione* (**Decomposizione**): Una decomposizione della relazione che non presenti ridondaze e senza perdita di informazione.
![[Screenshot 2023-12-07 at 01.26.51.png]]
Dipendenze funzionali:
- Tipo → Componente
- Kit → PrezzoTot
- Kit,Tipo → PrezzoComponente, QuantComp, Fornitore

![[Screenshot 2023-12-07 at 01.29.40.png]]
*Definizione* (**Dipendenze banali e non**): La dipendenza funzionale del tipo ImpiegatoProgetto $\rightarrow$ Progetto è sempre valida per cui si tratta di un DF "banale". X → A è non banale se A non è contenuta in X.

Siamo interessati alle dipendenze funzionali non banali.

### Esprimere le dipendenze funzionali
Consideriamo: NomeNegozio → IndNegozio.

**Espressione diretta (P ⇒ Q):** se in due righe il NomeNegozio è uguale, anche l’IndNegozio è uguale: NomeNegozio${}_= \Rightarrow$ IndNegozio${}_=$

**Per contrapposizione (¬Q ⇒ ¬P):**  se l’IndNegozio è diverso allora il NomeNegozio è diverso:   NomeNegozio${}_\neq \Rightarrow$ IndNegozio${}_\neq$.

Per assurdo: non possono esserci due nuple in DotazioniLibri con NomeNegozio uguale e IndNegozio diverso: 
- Not (NomeNegozio${}_= \land$ IndNegozio${}_\neq$ ) 
- NomeNegozio${}_= \land$ IndNegozio${}_\neq \Rightarrow$ False

Sono **equivalenti**:
- NomeNegozio${}_= \Rightarrow$ IndNegozio${}_=$
- NomeNegozio${}_\neq \Rightarrow$ IndNegozio${}_\neq$
- NomeNegozio${}_= \Rightarrow$ IndNegozio${}_\neq \Rightarrow$ False

In generale: $A \Rightarrow B \Leftrightarrow A \land \lnot B \Rightarrow False \Leftrightarrow \lnot B \Rightarrow \lnot A$
Più in generale, in ogni clausola $A \land B \Rightarrow E \lor F$ posso spostare le sottoformule da un lato all’altro, negandole. Quindi sono equivalenti: 
- NomeNegozio$_=\: \land$ CodiceLibro$_= \Rightarrow$ Quantità$_=$ 
- NomeNegozio$_=\: \land$ CodiceLibro$_= \land$ Quantità$_\neq \Rightarrow$  False 
- CodiceLibro$_= \: \land$ Quantità$_\neq \Rightarrow$ NomeNegozio$_\neq$
- NomeNegozio$_= \: \land$ Quantità$_\neq \Rightarrow$ CodiceLibro$_\neq$

**Esempio**
Orari(CodAula, NomeAula, Piano, Posti, Materia, CDL, Docente, Giorno, OraInizio, OraFine)
1. In un dato momento, un docente si trova al più in un’aula 
2. Non è possibile che due docenti diversi siano nella stessa aula contemporaneamente 
3. Se due lezioni si svolgono su due piani diversi appartengono a due corsi di laurea diversi 
4. Se due lezioni diverse si svolgono lo stesso giorno per la stessa materia, appartengono a due CDL diversi.
    (lezioni diverse:  not(CodAula$_= \land$ and NomeAula$_=\land \dots$))

<u>Domanda 1</u>
![[Screenshot 2023-12-07 at 01.44.03.png]]

<u>Domanda 2</u>
![[Screenshot 2023-12-07 at 01.44.33.png]]

<u>Domanda 3</u>
![[Screenshot 2023-12-07 at 01.48.34.png]]

<u>Domanda 4</u>
![[Screenshot 2023-12-07 at 01.49.02.png]]

*Definizione*: R<T, F> denota uno **schema** con attributi T e dipendenze funzionali F.

Le DF sono una proprietà semantica, cioè dipendono dai fatti rappresentati e non da come gli attributi sono combinati in schemi di relazione. 

*Definizione* (**DF completa**): Si parla di **DF completa** quando X → Y e per ogni W$\subset$ X, non vale W → Y. 

Se X è una superchiave, allora X determina ogni altro attributo della relazione: X → T Se X è una chiave, allora X → T è una DF completa.

*Proprietà*: Da un insieme F di DF, in generale altre DF sono ‘implicate’ da F.

*Definizione* (**Dipendenze implicate**): Sia F un insieme di DF sullo schema R, diremo che F implica logicamente X → Y (F |= X → Y, ), se ogni istanza r di R che soddisfa F soddisfa anche X → Y.

*Definizione* (**Dipendenze banali**): implicate dal vuoto, es. {} |= X -> X.

**Esempio**
Sia r un’istanza di R, con F = {X → Y, X → Z} e X, Y, Z $\subseteq$ T. Sia X’ $\subseteq$ X. Altre DF sono soddisfatte da r, ad es.
- X $\rightarrow$ X' (DB banale) e
- X $\rightarrow$ YZ, infatti
    $t_1[X] = t_2[X] \Rightarrow t_1[Y] = t_2[Y]$
    $t_1[X] = t_2[X] \Rightarrow t_1[Z] = t_2[Z]$
    $t_1[X] = t_2[X] \Rightarrow t_1[YZ] = t_2[YZ]$
    Pertanto X → Y, Y → Z} |= X → Z
**Nota**: |= denota l'applicazione logica

**Regole di inferenza**
Come derivare DF implicate logicamente da F? Usando un insieme di regole di inferenza.

"**Assiomi**" (sono in realtà regole di inferenza) di **Armstrong**:
![[Screenshot 2023-12-07 at 02.03.25.png | 400]]

### Derivazione
*Definizione*: Sia F un insieme di DF, diremo che X → Y sia derivabile da F (F |– X → Y), se X → Y può essere inferito da F usando gli assiomi di Armstrong.

Si dimostra che valgono le regole:
- {X → Y, X → Z} |– X → YZ (unione U) 
- Z $\subset$ Y {X → Y} |– X → Z (decomposizione D) 
- L’unione: {X → Y, X → Z} |– X → YZ (unione U)
	1. X → Y (per ipotesi) 
	2. X → XY (per arricchimento da 1) 
	3. X → Z (per ipotesi) 
	4. XY → YZ (per arricchimento da 3) 
	5. X → YZ (per transitività da 2, 4)

*Definizione*: Una derivazione di f da F è una sequenza finita f1 , …, fm di dipendenze, dove fm = f e ogni fi è un elemento di F oppure è ottenuta dalle precedenti dipendenze f1 , …, fi-1 della derivazione usando una regola di inferenza.

Si dimostrano che valogono anche le regole:
- {X → Y, X → Z} |– X → YZ (unione U) 
- Z $\subseteq$ Y {X → Y} |– X → Z (decomposizione D) 
Da Unione e Decomposizione si ricava che se Y = A1A2…An allora:
- X → Y $\Leftrightarrow$ {X → A1 , X → A2 , …, X → An }

*Teorema*: Gli assiomi di Armstrong sono corretti e completi.

Attraverso gli assiomi di Armstrong, si può mostrare l’equivalenza della nozione di implicazione logica (|=) e di quella di derivazione (|-): se una dipendenza è derivabile con gli assiomi di Armstrong allora è anche implicata logicamente (correttezza degli assiomi), e viceversa se una dipendenza è implicata logicamente allora è anche derivabile dagli assiomi (completezza degli assiomi).

**Correttezza** degli assiomi: $\forall$ f, F |- f $\Rightarrow$ F |= f
**Completezza** degli assiomi: $\forall$ f, F |= f $\Rightarrow$ F |- f

### Chiusura di un insieme F
*Definizione* (**chiusura di F**): dato un insieme D di DF, la chiusura di F, denotata con $F^+$. è:
$$F^+ = \{X \rightarrow Y \:|\: F \: |- \: X \rightarrow Y\}$$
Un problema che si presenta spesso è quello di decidere se una dipendenza funzionale appartiene a $F^+$ (problema dell’implicazione); la sua risoluzione con l’algoritmo banale (di generare $F^+$ applicando ad F ripetutamente gli assiomi di Armstrong) ha una complessità esponenziale rispetto al numero di attributi dello schema.

*Definizione* (**Chiusura di X rispetto d F**): Dato R<T,F> e $X \subseteq T$ la chiusura di X rispetto ad F denota la $X_F^+$ (o $X^+$ se F è chiaro dal contesto)  è
$$X^+_F = \{A_i \in T \:|\: F|- \: X \rightarrow A_i\}$$

**Problemi dell'implicazione**: controllare se una DF V → W $\in$ $F^+$ Un algoritmo efficiente per risolvere il problema dell’implicazione senza calcolare la chiusura di F scaturisce dal seguente teorema.

*Teorema/Osservazione*: $F |- X \rightarrow Y \Leftrightarrow T \subseteq X_F^+$

**Algoritmo per calcolare $X^+_F$**
Sia X un insieme di attributi e F un insieme di dipendenze. Vogliamo calcolare $X^+_F$.
1. Inizializziamo $X^+$ con l'insieme X.
2. Se fra le dipendenze di F c'è una dipendenza $Y \rightarrow A$ con $Y \subseteq X^+$ allora si inserisce A in $X^+$ ossia $X^+ = X^+ \cup \{A\}$ 
3. Si ripete il passo 2 fino a quando non ci sono altri attributi da aggiungere ad $X^+$
4. Si da in output $X_F^+ = X^+$

**Chiusura Lenta**
input: R<T,F>  X $\subseteq$ T)
output: $X^+$
begin
	$X^+ = X$     Inizializziamo $X^+$ con l'insieme X
	while ($X^+$ cambia) do     Fino a quando non ci sono altri atrib da aggiungere a $X^+$ 
			for $W \to V$ in F with $W \subseteq X^+$ and $V \lor X^+$
				do $X^+ = X^+ \cup V$ 
			Se fra le dipendenze di F c’è una dipendenza W → V con W⊆ X+ allora si inserisce V in $X^+$ , ossia $X^+ = X^+ \cup \{V\}$ 
end

**L’algoritmo termina** perché ad ogni passo viene aggiunto un nuovo attributo a X+ . Essendo gli attributi in numero finito, a un certo punto l’algoritmo deve fermarsi.

Per dimostrare la correttezza, si dimostra che $X_F^+ + = X^+$ (per induzione)

**Esempio**
$F = \{DB \to E, B \to C, A \to B\}$ trovare $(AD)^+$:
Vogliamo conoscere gli attributi che sono determinati funzionalmente da un insieme di dipendenze A e D.
$X^+ = AD$,     $X^+ = ADB$,     $X^+ = ADBE$,      $X^+ = ADBEC$ 

Se fra le dipendenze di F c’è una dipendenza Y → A con $Y\subseteq X^+$ allora si inserisce A in $X^+$ , ossia $X^+ = X^+ \cup \{A\}$.

**Chiavi ed attributi primi**
*Definizione*: Dato lo schema R<T, F> diremo che un insieme di attributi $W \subseteq T$ è una **chiave candidata** di R se:
- $W \to T \in F^+$    (Si ricava tutto da W)
- $\forall V \subset W, V \to T \notin F^+$   (W è minimale)

**Attributo primo**: attributo che appartiene ad almeno una chiave.

**Esempio**. Prendiamo l'esempio di prima.
$F = \{DB \to E, B \to C, A \to B\}$ trovare $(AD)^+$:
Vogliamo conoscere gli attributi che sono determinati funzionalmente da un insieme di dipendenze A e D.
$X^+ = AD$,     $X^+ = ADB$,     $X^+ = ADBE$,      $X^+ = ADBEC$ 
- AD è superchiave? Si poiché contiene tutti gli attributi 
- A è superchiave? A→B, A→BC, si ferma → non è superchiave 
- ABD è superchiave? (ABD)+ è analoga a (AD)$^+$ , perché ABD è più grande di AD, quindi è superchiave
- ABC è superchiave? ABC stesso, quindi non è superchiave

Complessità: il problema di trovare tutte le chiavi di una relazione richiede un algoritmo di complessità esponenziale nel caso peggiore, il problema di controllare se un attributo è primo è NP- completo.

L’algoritmo per trovare tutte le chiavi si basa su due proprietà: 
1. Se un attributo A di T non appare a destra di alcuna dipendenza in F, allora A appartiene ad ogni chiave di R 
2. Se un attributo A di T appare a destra di qualche dipendenza in F, ma non appare a sinistra di alcuna dipendenza non banale, allora A non appartiene ad alcuna chiave.

## Copertura canonica
*Definizione*: Due insiemi di DF, F e G sullo schema R sono **equivalenti**.
$$F \equiv G \Leftrightarrow F^+ = G^+$$
Se $F \equiv G$ allora F è una **copertura** di G (e G una copertura di F).

*Definizione*: Sia F un insieme di DF. Dato una $X \to Y \in F$ si dice che X contiene un **attributo estraneo** $A_i$ sse $(X-\{A_i\}) \to Y \in F^+$ cioè $F |- (X - \{A_i\}) \to Y$

Come facciamo a stabilire che in una DF del tipo AX → B l’attributo A è estraneo? Per verificare se A è estraneo calcoliamo $X^+$ e verifichiamo se include B, ovvero se basta X a determinare B

**Esempio**. studenti(matricola, CF, Cognome, Nome, Anno)

se vale: 
- Docente, Giorno, Ora -> CodAula
- Docente, Giorno -> Ora
allora: Docente, Giorno -> CodAula, (quindi) nella prima dipendenza Ora è attributo estraneo.

*Definizione*: Sia D un insieme di DF. $X \to Y$ è una **dipendenza ridondante** sse $(F - \{X \to Y\})^+ = F^+$, Equivalentemente: $F - \{X \to Y\} |- X \to Y$.

Come facciamo a stabilire che una DF del tipo X → A è ridondante? La eliminiamo da F, calcoliamo $X^+$ e verifichiamo se include A, ovvero se con le DF che restano riusciamo ancora a dimostrare che X determina A.

**Esempio**. Orari(CodAula, NomeAula, Piano, Posti, Materia, CDL, Docente, Giorno, Ora)
se vale:
- Docente, Giorno, Ora -> CodAula 
- CodAula -> NomeAula
è inutile avere anche: Docente, Giorno, Ora -> NomeAula

**Esempio**. F = {B → C, B → A, C → A} 
B → A è ridondante poiché possiamo dedurla da B → C e C → A

*Definizione*. Sia F un insieme di DF. F è detta **copertura canonica** sse.
- la parte destra di ogni DF in F è attributo
- non esistono attributi estranei
- nessuna dipendenza in F è ridondante.

*Teorema*: Per ogni insieme di dipendenze F esiste una copertura canonica.

L'algoritmo per calcolare una copertura canonica è:
1. Trasformare le dipendenze nella forma $X \to A$. Si sostituisce l’insieme dato con quello equivalente che ha tutti i secondi membri costituiti da singoli attributi (dipendenze atomiche)
2. Eliminare gli attributi estranei. Per ogni dipendenza si verifica se esistono attributi eliminabili dal primo membro. Data una X → Y $\in$ F, si dice che X contiene un attributo estraneo $A_i$ sse $(X – \{A_i\}) \to Y \in F^+$ , cioè $F |- (X – \{A_i\}) \to Y$.
3. Eliminare le dipendenze ridondanti. $X \to Y$ è una dipendenza ridondante sse $(F - \{X \to Y\})^+ = F^+$, Equivalentemente $F - \{X \to Y\} |- X \to Y$

**Esempio**. Impiegato (Matricola, Cognome, Grado, Retribuzione, Dipartimento, Supervisore, Progetto, Anzianità).

Consideriamo il seguente insieme di dipendenze funzionali:
{M → RSDG, MS → CD, G → R, D →S, S → D, MPD → AM}
1. Creiamo le dipendenze funzionali atomiche: {M → R, M → S , M → D, M → G, MS → C, MS → D, G → R, D →S, S → D, MPD → A, MPD → M}
2. Eliminare gli attributi estranei:
	- è possibile eliminare S dal primo membro di MS → C e MS → D perché M → S (si ottiene da M → D e D → S)
	- È inoltre possibile eliminare D dal primo membro di MP<s>D</s> → A e MP<s>D</s> → M poiché M → D {M → R, M → S , M → D, M → G, M → C, M → D, G → R, D →S, S → D, MP → A, MP → M}
3. Si trova l’insieme di dipendenza funzionali non ridondante: eliminiamo le dipendenze ottenibili da altre:
	- M → R (deriva da M → G e G → R) 
	- M → S (deriva da M → D e D →S) 
	- M → D (Perché già M → D) 
	- MP → M (Perché M compare a primo membro)

## Decomposizione di schemi
In generale, per eliminare anomalie da uno schema occorre decomporlo in schemi più piccoli "equivalenti"

**Esempi** di decomposizione.
L’intuizione è che si devono “estrarre” gli attributi che sono determinati da attributi non chiave ovvero “creare uno schema per ogni funzione”.

![[Screenshot 2023-12-07 at 16.41.44.png]]

La soluzione non è tuttavia sempre così semplice, bisogna fare anche altre considerazioni; ad esempio, operando come prima:
![[Screenshot 2023-12-07 at 16.51.50.png | 500]]

**Decomposizione sulla base delle dipendenze**
![[Screenshot 2023-12-07 at 16.52.37.png | 500]]

**Proviamo a ricostruire mediante join**
![[Screenshot 2023-12-07 at 16.52.58.png | 500]]

*Definizione*: Dato uno schema R(T), $p = \{R_1(T_1), \dots, R_k(T_k)\}$ è una **decomposizione** di R sse $T_1 \cup \dots \cup T_k = T$.

**Esempio**. StudentiEdEsami(Matricola, Nome, Provincia, AnnoNascita, Materia, Voto)
- {Studenti(Matricola, Nome, Provincia,AnnoNascita), Esami(Matricola, Materia, Voto)}
- {Studenti(Matricola, Nome, Provincia,AnnoNascita), Esami(Nome, Materia, Voto)} 
- {Studenti(Matricola, Nome, Provincia,AnnoNascita), Esami(Materia, Voto)}

In generale, per eliminare anomalie da uno schema occorre decomporlo in schemi più piccoli "equivalenti"

Due proprietà desiderabili di una decomposizione: 
- **conservazione dei dati** (nozione semantica) 
- **conservazione delle dipendenze**

### Preservare i dati
*Definizione*: $p = \{R_1(T_1), \dots, R_k(T_k)\}$ è una decomposizione di uno schema R(T) che **preserva i dati** sse per ogni istanza valida r di R: 
$$r = (\pi_{T1}r) \lor (\pi_{T2}r) \lor \dots \lor (\pi_{Tk}r)$$
Dalla definizione di giunzione naturale scaturisce il seguente risultato:
*Teorema*: $p = \{R_1(T_1), \dots, R_k(T_k)\}$ è una decomposizione di R(T) allora per ogni istanza r di R: $r \subseteq (\pi_{T1}r) \lor (\pi_{T2}r) \lor \dots \lor (\pi_{Tk}r)$ 

**Decomposizione con perdita di informazioni**
Prendiamo il seguente esempio: 
StudentiEdEsami(Matricola, Nome, Provincia, AnnoNascita, Materia, Voto) ==>
{Studenti(Matricola, Nome, Provincia,AnnoNascita), Esami(Nome, Materia, Voto)}

Cosa succede quando si fa la giunzione? Nessuna tupla si perde, ma…?
Questa decomposizione crea tuple spurie: ci sono n-uple in più. Si pensi al caso di due persone con lo stesso nome che hanno sostenuto esami diversi, cosa succede dopo la giunzione? Perdita di informazione!

Mentre con:
{Studenti(Matricola, Nome, Provincia, AnnoNascita), Esami(Matricola, Materia, Voto)}
Non si perdono informazioni perché la chiave è l’unico modo per avere una decomposizione senza perdita di informazione.

**Decomposizione senza perdita**
Uno schema R(X) si decompone senza Perdita dei dati negli schemi R1(X1) ed R2(X2) se, per ogni possibile istanza r di R(X), il join naturale delle proiezioni di r su X1 ed X2 produce la tabella di partenza. (cioè non contiene ennuple spurie)
$$\pi_{X1}(r) \bowtie \pi_{X2}(r) = r$$
La decomposizione senza perdita è garantita se l’insieme degli attributi comuni alle due relazioni ($X_1 \cap X_2$) è chiave per almeno una delle due relazioni decomposte. 
Ad esempio, Sede=(Progetto, Sede)$\cap$(Impiegato, Sede) non è chiave per nessuna delle due relazioni
![[Screenshot 2023-12-07 at 17.06.12.png | 400]]

*Definizione* (**Senza perdita**): Sia r una relazione su un insieme di attributi X e siano $X_1$ e $X_2$ due sottoinsiemi di X la cui unione sia pari a X stesso; Inoltre, sia $X_0$ l’intersezione di $X_1$ e $X_2$ , allora: 
- r si decompone senza perdita su $X_1$ e $X_2$ se soddisfa la dipendenza funzionale $X_0 \to X_1$ oppure la dipendenza funzionale $X_0 \to X_2$.

*Teorema (non formale)*: Se l’insieme degli attributi comuni alle due relazioni $(X_1 \cap X_2)$ è chiave per almeno una delle due relazioni decomposte allora la decomposizione è senza perdita.

*Dimostrazione (non formale)*:
- Supponiamo r sia una relazione sugli attributi ABC e consideriamo le sue proiezioni $r_1$ su AB e $r_2$ su AC. 
- Supponiamo che r soddisfi la dipendenza funzionale A → C. Allora A è chiave per r su AC e quindi non ci sono in tale proiezione due tuple diverse sugli stessi valori di A.
Il join costruisce tuple a partire dalle tuple nelle due proiezioni: Sia t=(a,b,c) una tupla del join di $r_1$ e $r_2$. Mostriamo che appartiene ad r (cioè non è spuria):
- t è ottenuta mediante join da t1=(a,b) di r1 e t2=(a,c) su r2
- Allora per la definizione di proiezione, esistono due tuple in r, $t’_1$= (a,b,$*$) e $t'_2$= (a,$*$,c) (dove $*$ sta per un valore non noto).
- Poiché A →C, allora esiste un solo valore in C associato al valore a. Dato che (a,c) compare nella proiezione, questo valore è proprio c.
- Ma allora nella tupla $t’_1$ il valore incognito deve essere proprio c. Quindi (a,b,c) appartiene a r.

**Decomposizioni binarie**
*Teorema*: Sia R<T, F> uno schema di relazione, la decomposizione $p = \{R_1(T_1), \dots, R_k(T_k)\}$ preserva i dati sse:
$$T_1 \cap T_2 \to T_1 \in F^+ \:oppure\: T_1 \cap T_2 \to T_2 \in F^+$$
Esistono criteri anche per decomposizioni in più di due schemi.

Anche se una decomposizione è senza perdite, può comunque presentare dei problemi di conservazione delle dipendenze.

**Esempio**. Impiegato=(Impiegato, Sede)$\cap$(Impiegato, Progetto)
![[Screenshot 2023-12-07 at 17.16.52.png | 500]]
Con questa decomposizione, non ho tuple spurie

![[Screenshot 2023-12-07 at 17.17.32.png | 500]]
In questa decomposizione: trascuriamo la seconda dipendenza funzionale.

Supponiamo di voler inserire una nuova ennupla che specifica la partecipazione dell'impiegato Neri (che opera a Milano) al progetto Marte (lo schema non lo impedisce).
![[Screenshot 2023-12-07 at 17.18.28.png]]
Viene violata la seconda dipendenza funzionale (che per il momento avevamo tenuto in sospeso) Progetto → Sede.
![[Screenshot 2023-12-07 at 17.19.25.png]]
Una decomposizione conserva le dipendenze se ciascuna delle dipendenze funzionali dello schema originario coinvolge attributi che compaiono tutti insieme in uno degli schemi decomposti Nell’esempio considerato Progetto → Sede non è conservata.
![[Screenshot 2023-12-07 at 17.19.36.png | 400]]

**Esempio**. Query di verifica.
Se una DF non si preserva diventa più complicato capire quali sono le modifiche del DB che non violano la FD stessa.
In generale si devono prima eseguire query SQL di verifica (o, meglio, fare uso di trigger)
Bisogna verificare che il progetto (Marte) sia presso la stessa sede dell’impiegato (Neri). A tal fine bisogna trovare un impiegato che lavora al progetto Marte.

![[Screenshot 2023-12-07 at 17.20.36.png]]

Una decomposizione: 
- deve essere senza perdita, per garantire la ricostruzione delle informazioni originarie 
- dovrebbe preservare le dipendenze, per semplificare il mantenimento dei vincoli di integrità originari.
Nell’esempio, questo suggerisce di inserire anche: va sempre eseguita una query, ma più semplice:
```sql
SELECT * -- OK se restituisce una tupla 
FROM Impiegati I, Progetti P 
WHERE I.Impiegato = ‘Neri’ AND P.Progetto = `Marte’ AND I.Sede = P.Sede
```

### Conservazione delle dipendenze
Una decomposizione **conserva le dipendenze** se ciascuna delle dipendenze funzionali dello schema originario coinvolge attributi che compaiono tutti insieme in uno degli schemi decomposti. 
Nell’esempio considerato Progetto → Sede non è conservata

**Esempio**
Telefoni(Prefisso, Numero, Località, Abbonato, Via)
{Pref Num → Loc Abb Via, Loc → Pref} cioè: {P N → L A V, L → P}
Si considera la decomposizione: 
ρ = {Tel <{N, L, A, V}, F1 >, Pref<{L, P}, F2 >} con F1 = {LN → A V} e F2 ={L → P} 

![[Screenshot 2023-12-08 at 01.44.16.png | 450]]
Preserva dati ma non le dipendenze: PN → L non è deducibile da F1 e F2.
Esistono istanze valide della decomposizione che non sono proiezione di una istanza valida della relazione originale.

*Definizione*: Dato lo schema $R<T, F>$ e $T_1 \subseteq T$ la **proiezione di F su $T_1$** è:
$$\pi_{T1}(F) = \{X \to Y \in F^+ \:|\: XY \subseteq T_1\}$$
**Esempio**. Sia R(A, B, C) e F = $\{A \to B, B \to C, C\to A\}$
$\pi_{AB}(F) \equiv \{A \to B, B \to A\}$
$\pi_{AC} \equiv \{A \to C, C \to A\}$
Potrebbe sembrare che la decomposizione $\rho_i = \{R_1(A, B), R_2(A,C)\}$ non preservi le dipendenze perché B e C non appaiono insieme in uno schema della decomposizione, invece da B → A e A → C si ha B→ C.

Algoritmo banale per il calcolo di $\pi_{T1}(F)$:
for each $Y \subseteq T_1$ do 
	$(Z\: :=\: Y^+; output \: Y \to Z \cap T_1)$

*Definizione*: Dato lo schema R<T, F> la decomposizione $\rho = \{R_1, \dots, R_n\}$ **preserva le dipendenze** sse l'unione delle dipendenze in $\pi_{Ti}(F)$ è una copertura di F.

*Proposizione*: Dato lo schema $R<T, F>$ il problema di stabilire se la decomposizione $\rho = \{R_1, \dots, R_n\}$ preserva le dipendenze ha la complessità tempo polinimiale.

*Teorema*: sia $p = \{R_i<T_i, F_i>\}$ una decomposizione R<T,F> che preserva le dipendenze e tale che $T_j$ per qualche j, è una superchiave per $R<T,F>$  allora $\rho$ preserva i dati.

**Esempio**
Telefoni(Prefisso, Numero, Località, Abbonato, Via) F={P N → L A V, L → P}
Si considera la decomposizione: $\rho = \{Tel<\{N, L, A, V\}>, Pref<\{L, P\}>, F2\}$ con
F1 = {LN → A V}    F2 = {L → P}

Preserva dati ma non le dipendenze: PN → L non è deducibile da F1 e F2.

![[Screenshot 2023-12-08 at 12.34.23.png]]
Una decomposizione dovrebbe sempre soddisfare le seguenti proprietà:
- la **decomposizione senza perdita**, che garantisce la ricostruzione delle informazioni originarie senza generazione di tuple spurie.
- la **conservazione delle dipendenze**, che garantisce il mantenimento dei vincoli di integrità (di dipendenza funzionale) originari.

## Forme normali
Una forma normale è una proprietà di una base di dati relazionale che ne garantisce la “qualità”, cioè l'assenza di determinati difetti. Quando una relazione non è normalizzata:
- presenta ridondanze
- si presta a comportamenti poco desiderabili durante gli aggiornamenti

**1FN**: Impone una restrizione sul tipo di una relazione: ogni attributo ha un tipo elementare.
**2FN, 3FN**: Impongono restrizioni sulle dipendenze.
**FNBC**: FNBC (Boyce-Codd) è la più naturale e la più restrittiva.

Una relazione r è in forma normale di Boyce e Codd (BCNF) se, per ogni dipendenza funzionale (non banale) X → Y definita su di essa, X contiene una chiave K di r (è una superchiave).

La forma normale richiede che i concetti in una relazione siano omogenei (solo proprietà direttamente associate alla chiave).

**Esempio**. Relazione sugli impiegati
![[Screenshot 2023-12-08 at 12.39.51.png | 400]]
Non è in forma normale di Boyce and Codd perché esiste la dipendenza funzionale.
Impiegato → Stipendio (Impiegato non è (super)chiave per la relazione )

### FORME NORMALI di Boyce-Codd
**FNBC**: L'Intuizione è che se esiste in R una dipendenza X→A non banale ed X non è chiave, allora X modella l’identità di un’entità diversa da quelle modellate dall’intera R.

**Esempio**. StudentiEdEsami(<u>Matricola</u>, Nome, Provincia, AnnoNascita, <u>Materia</u>, Voto).
Matricola -> Nome e Matricola non è (super)chiave. Il Nome dipende dalla Matricola che non è chiave.

*Definizione*: R<T,F> è in BCNF $\Leftrightarrow$ per ogni $X \to A \in F^+$  con $A \notin X$ (non banale) X è una superchiave.

*Teorema*: R<T,F> è in BCNF $\Leftrightarrow$ per ogni $X \to A \in F$ non banale X è superchiave.

**Esempio**. 
Docenti(<u>CodiceFiscale</u>, Nome, Dipartimento, Indirizzo)    {CF → N D; D → I} 
Impiegati(<u>Codice</u>, Qualifica, <u>NomeFiglio</u>)                            {C → Q}

**Algoritmo di analisi**
R<T,F> è decomposta in $R_1(X,Y)$ e $R_2(X,Z)$ e su di esse si ripete il procedimento; esponenzialmente.

input: R<T, F> con F copertura canonia
output: decomposizione in BCNF che preserva i dati $\rho = \{R<T,F>\}$ 

while esiste in $\rho$ una $R_i<T_i, F_i>$ non in BCNF per la DF $X \to A$
do
	$T_a = X^+$
	$F_a = \pi_{T_a}(F_i)$
	$T_b = T_i - X^+ + X$ (Attenzione: errore nel vecchio libro)
	$F_b = \pi_{Tb}(F_i)$
	$\rho = \rho - R_i + \{R_a<T_a, F_a>, R_b<T_b, F_b>\}$    ($R_a$ ed $R_b$ sono nomi nuovi)
end

*Osservazione*: $T_b = T_i - X^+ + X$, perché aggiungiamo X?

**Preserva i dati** ma non necessariamente le dipendenze

**Esempio** di decomposizione senza perdita di dipendenze: 
Docenti(CodiceFiscale, Nome, Dipartimento, Indirizzo), {CF → N D; D → I}
(CF)+= CF N D I      è chiave 
(D) += D I                 non è chiave

Decompongono:
- R1(<u>D</u>, I)              R2(<u>CF</u>, D)
- F1 = $\{D \to I\}$    F2=$\{CF \to ND\}$

**Esempio**. Impiegati(Codice, Qualifica, NomeFiglio) {C → Q}
- R1(C, Q);            R2(C, NF) 
- F1 = { C → Q }    F2={ }

Vediamo che dato che non perdo dipendenze funzionali, posso fare la proiezione approssimata su F.

**Esempio**. Telefoni (Prefisso, Numero, Località, Abbonato, Via)
F = { P N → L A V, L → P }
- R1(L, P); R2(L, N, A, V) 
- Preserva dati ma non le dipendenze: PN → L non è deducibile da F1 e F2.

Cosa vuol dire che "non preserva le dipendenze"?
- R1 = {(Pisa, 050); (Calci, 050)}
- R2 = {(Pisa, 506070, Rossi, Piave), (Calci,506070, Bianchi, Isonzo)} 
Posso inserire due numeri telefonici (senza prefisso) con comuni differenti che hanno lo stesso prefisso?

**Esempio**.
Dato il seguente schema relazionale R<ABCDE, F= { CE→A, D→E, CB→E, CE→B }>. Applicare l’algoritmo di analisi e dire se dati e dipendenze sono stati preservati.
- Consideriamo CE→A. $CE^+$=CEAB (CE non è chiave), per cui decomponiamo:
	R1(CEAB) (gli attributi di $CE^+$), R2(CED) 
	(In R2 tutti gli altri attribuiti (D) e la chiave esterna (CE))
- Proiettiamo le dipendenze (approssimate su F): 
	R1 < CEAB, { CE → A, CB → E, CE → B } > (Proiezione in F) 
	R2 < CED, { D→E } > (Proiezione in F)
$CE^+$=CEAB e $CB^+$=CBEA, per cui R1 è in BCNF
$D^+$=DE, per cui R2 va ancora decomposta: R2 < CED, { D→E } > -> R3 , R4
La decomposizione è quindi: { R1(CBEA), R3(DE), R4(DC) }.
La decomposizione preserva dati e dipendenze ed è in questo caso è la stessa prodotta dall’algoritmo di sintesi (che vedremo dopo).
### Terza forma normale
Chiediamoci ora se data una relazione non in FNBC, è sempre possibile ottenere una decomposizione in FNBC?
![[Screenshot 2023-12-08 at 14.14.37.png | 450]]
- Progetto Sede → Dirigente: ogni progetto ha più dirigenti che ne sono responsabili, ma in sedi diverse, e ogni dirigente può essere responsabile di più progetti; però per ogni sede, un progetto ha un solo responsabile 
- Dirigente → Sede: ogni dirigente opera presso una sede 
- Dirigente → Sede è una dipendenza funzionale ma Dirigente non è una (super)chiave. Quindi la relazione non è in BCNF.
- Progetto Sede → Dirigente coinvolge tutti gli attributi e quindi nessuna decomposizione può preservare tale dipendenza. 

Quindi in alcuni casi la BCNF “non è raggiungibile”. Occorre ricorrere a una forma normale indebolita.
Quando si hanno diverse DF è difficile ragionare sullo schema, ed è quindi altrettanto difficile operare manualmente buone decomposizioni. La terza forma normale (3NF) è un target di normalizzazione che consente di ottenere automaticamente: 
- decomposizioni senza perdita
- decomposizioni che preservano tutte le dipendenze

*Definizione*: Una relazione r è in terza forma normale (3NF) se, per ogni FD (non banale) X → Y definita su r, è verificata almeno una delle seguenti condizioni:
- X contiene una chiave K di r (come nella BCNF)
- Oppure ogni attributo in Y è contenuto in almeno una chiave K di r

Prendendo l'esempio di prima. 
- Progetto Sede → Dirigente 
- Dirigente → Sede
Nella prima dipendenza funzionale il primo membro della dipendenza (Progetto, Sede) è una chiave, nella seconda il secondo membro (Sede) è contenuto in una chiave. Quindi la relazione è in terza forma normale.

**Svantaggi**
La 3FN è **meno restrittiva** della FNBC:
- Tollera alcune ridondanze ed anomalie sui dati. Es. per ogni occorrenza di un dirigente viene ripetuta la sua sede.
- Certifica meno lo qualità dello schema ottenuto.

**Vantaggi**
La 3FN è sempre ottenibile, qualsiasi sia lo schema di partenza. COME? Algoritmo di normalizzazione in TFN!

*Definizione*: $R<T,F>$ è in 3FN se per ogni $X \to A \in F^+$ con $A \notin X$ X è superchiave o A è primo.

Nota: 
- La 3FN ammette una dipendenza non banale e non-dachiave se gli attributi a destra sono primi; 
- la BCNF non ammette mai nessuna dipendenza non banale e non-da-chiave.

*Teorema*: R<T,F> è in 3FN se per ogni $X \to A \in F$ non banale, allora X è una superchiave oppure A è primo.

Non sono in 3FN (e quindi, neppure in BCNF).
- Docenti(CodiceFiscale, Nome, Dipartimento, Indirizzo)     { CF → N D; D → I }
- Impiegati(Codice, Qualifica, NomeFiglio)                             { C → Q }
- Telefoni(Prefisso, Numero, Località, Abbonato, Via)           {P N → L A V, L → P} 
	Chiavi = {PN, LN}
- Esami(Matricola, Telefono, Materia, Voto) 
	Matricola Materia → Voto, Matricola → Telefono, Telefono → Matricola
	Chiavi: Matricola Materia, Telefono Materia

### Algoritmo di sintesi
Input: Un insieme R di attributi e un insieme F di dipendenze su R.
Output: Una decomposizione $\rho = \{S_i\}_{i=1..n}$ di R tale che preservi dati e dipendenze e ogni $S_i$ sia in 3NF, rispetto alle proiezioni di F su $S_i$ .
begin:
	<u>Passo 1</u>: Trova una copertura canonica G di F e poni $\rho = \{\}$
	<u>Passo 2</u>: Sostituisci in G ogni insieme $X \to A_1 , \dots , X \to A_h$ di dipendenze con lo stesso determinante, con la dipendenza $X \to A_1$・ ・ ・ $A_h$.
	<u>Passo 3</u>: Per ogni dipendenza X → Y in G, metti uno schema con attributi XY in $\rho$.
	<u>Passo 4</u>: Elimina ogni schema di $\rho$ contenuto in un altro schema di $\rho$.
	<u>Passo 5</u>: Se la decomposizione non contiene alcuno schema i cui attributi costituiscano una superchiave per R, aggiungi ad essa lo schema con attributi W, con W una chiave di R.
end

**Esempio**. Dati R di attributi, ed un insieme di dipendenze F, l’algoritmo di sintesi di schemi in terza forma normale procede come segue.
Impiegato(Matricola, Cognome, Grado, Retribuzione, Dipartimento, Supervisore, Progetto, Anzianità)
{M → RSDG, MS → CD, G → R, D →S, S → D, MPD → AM}
- <u>Passo 1</u> Costruire una copertura canonica G di F. 
	F={M→RSDG, MS → CD, G →R, D→S, S→D, MPD→AM}
	G={M→D, M→G, M →C, G→R, D→S, S→D, MP→A}
- <u>Passo 2a</u> Decomporre G nei sottoinsiemi $G^{(1)}, G^{(2)},\dots, G^{(n)}$ , tali che ad ogni sottoinsieme appartengano dipendenze con gli stessi lati sinistri (facoltativo)
	- $G^{(1)}$ = {M→D, M →G, M→C}
	- $G^{(2)}$ = {G→R}
	- $G^{(3)}$ = {D→S}
	- $G^{(4)}$ = {S→D}
	- $G^{(5)}$ = {MP→A}
- <u>Passo 2b</u> sostituisci in G ogni insieme X → $A_1$, …, X→ $A_h$ di dipendenze con lo stesso determinante, con la dipendenza X → $A_1, \dots, A_h$.
	- $G^{(1)}$ = {M→D, M →G, M→C}             $G^{(1)}$ = {M→DGC}
	- $G^{(2)}$ = {G→R}                                     $G^{(2)}$ = {G→R}
	- $G^{(3)}$ = {D→S}                  ==>            $G^{(3)}$ = {D→S}
	- $G^{(4)}$ = {S→D}                                     $G^{(4)}$ = {S→D}
	- $G^{(5)}$ = {MP→A}                                  $G^{(5)}$ = {MP→A}
- <u>Passo 3</u>. Trasformare ciascun $G^{(i)}$ in una relazione $R^{(i)}$ con gli attributi contenuti in ciascuna dipendenza. Il lato sinistro diventa la chiave della relazione:
	 Passo 2                                                Passo 3
	- $G^{(1)}$ = {M→DGC}                               $R^{(1)}$ = {<u>M</u>DGC}
	- $G^{(2)}$ = {G→R}                                     $R^{(2)}$ = {<u>G</u>R}
	- $G^{(3)}$ = {D→S}                  ==>            $R^{(3)}$ = {<u>DS</u>}
	- $G^{(4)}$ = {S→D}                                     $R^{(4)}$ = {<u>SD</u>}
	- $G^{(5)}$ = {MP→A}                                  $R^{(5)}$ = {<u>MP</u>A}
- <u>Passo 4</u>. Si eliminano schemi contenuti in altri. 
![[Screenshot 2023-12-08 at 15.14.52.png | 500]]
- <u>Passo 5</u>. Se nessuna relazione $R^{(i)}$ così ottenuta contiene una (super)chiave K di R(U), inserire una nuova relazione $R^{(n+1)}$ contenente gli attributi della chiave.
	Impiegato (Matricola, Cognome, Grado, Retribuzione, Dipartimento, Supervisore, Progetto, Anzianità) 
	F={M→RSDG, MS → CD, G →R, D→S, S→D, MPD→AM} 
	G={M→D, M→G, M →C, G→R, D→S, S→D, MP→A}
	a chiave è costituita da: (MP). 
	Dallo step 4: $R^{(1)}$(MDGC) $R^{(2)}$(GR) $R^{(3)}$(SD) $R^{(5)}$(MPA)
	$R^{(5)}$(MPA) contiene la chiave → non c’è necessità di aggiungere altre relazioni!

In conclusione, data la relazione: R(MGCRDSPA), con dipendenze funzionali: 
Impiegato (Matricola, Cognome, Grado, Retribuzione, Dipartimento, Supervisore, Progetto, Anzianità) 
F= {M→RSDG, MS → CD, G →R, D→S, S→D, MPD→AM} 
G={M→D, M→G, M →C, G→R, D→S, S→D, MP→A}

La sua decomposizione in 3FN è la seguente:
$R^{(1)}$(MDGC)    $R^{(2)}$(GR)     $R^{(3)}$(SD)     $R^{(54}$(MPA)


### Dipendenze multi-valore
![[Screenshot 2023-12-08 at 15.22.34.png | 500]]

La coesistenza di due proprietà multivalore INDIPENDENTI, fa sì che per ogni impiegato esistono tante ennuple quante sono le possibili coppie di valori di Qualifica e NomeFiglio.

Tre casi di relazioni con proprietà multivalori. Si possono risolvere usando le decomposizioni?
La coesistenza di due proprietà multivalore indipendenti, fa sì che per ogni impiegato esistano tante ennuple quante sono le possibili coppie di valori di Stipendio e NomeFiglio.

Decomponendo lo schema in due sottoschemi in modo da modellare separatamente le proprietà multivalori indipendenti, si avrebbe una base di dati priva di anomalie:
- StipendiImpiegati(Codice, StoriaStipendio) 
- FigliImpiegati(Codice, NomeFiglio)