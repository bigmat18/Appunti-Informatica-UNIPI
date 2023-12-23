Sono criteri per l'individuazione dei casi di input che si basano sulle specifiche. La strategia è al seguente:
- Separare le funzionalità da testare (per esempio usando i casi d'uso)
- Derivare un insieme di casi di test per ogni funzionalità
- M(p1, p2, p3, p4) < <i1, i2, i3, i4>, output atteso, ambiente >
	Per fare ciò bisogno: per ogni (tipo di) paramentro di input andare ad individurare dei valori da testare (per questo si usano alcune tecniche (metodi) che vediamo sotto), e per l'insieme dei parametri si usano tecniche che vanno sotto il nome di testing combinatorio per ridurre le combinazioni.

### Metodo statitico
I casi di test sono selezionati in base alla distribuzione di probabilità dei dati di ingresso del programma. Il test è quindi progettato per esercitare il programma sui valori di ingresso più probabili per il suo utilizzo a regime Il vantaggio è che, nota la distribuzione di probabilità, la generazione dei dati di test è facilmente automatizzabile. Non sempre corrisponde alle effettive condizioni d’utilizzo del software È oneroso calcolare il risultato atteso (problema dell’oracolo).

**Esempio**.
Si considera l'input "età il giorno della laurea" (il tipo è int). In questo caso è ragionevole usare il metodo statistico e dare la specifica di test (Test obligation):
- tutti i valori compresi tra 20 e 27,
- il 40% dei valori tra 27 e 35 (questi possono essere scelti in modo random),
- il 5% dei valori tra 36 e 100 (Questi possono essere scelti in modo random). 
Casi di test che soddisfano le test obligations: <20, _, _>,  <21, _, _>, ..., <27, _, _>, <29, _, _>, ... <51, _, _> ... (al momento non sono ancora specificati output e ambiente)

### Partizione dei dati in ingresso in classi di equivalenza 
Questo è un metodo in cui il dominio dei dati di ingresso è ripartito in **classi di equivalenza**. Due valori d'ingresso appartengono alla stessa classe di equivalenza se, in base ai requisiti, dovrebbero produrre lo stesso comportamento del programma (non necessariamente stesso output).

**Esempio**
Abbiamo un metodo ```int calcolaTasse(int reddito)```. Il test obligation è un caso di test per aliquota, i casi di test che soddisfano le test obligations sono: <10.000, 2300, _>, <20.000, 4800, _>, ...
![[Screenshot 2023-12-04 at 11.35.42.png]]

Il criterio è economicamente valido solo per quei programmi per cui il numero dei possibili comportamenti è sensibilmente inferiore alle possibili confiugurazione d'ingresso. Per come sono costruite le classi, i risultati attesi dal test sono noti e quindi non si pone il problema dell'oracolo.

Il criterio è basato su un'affermazione generalmente plausibile, ma non vera in assoluto, la deduzione che il corretto funzionamento sul valore rappresentate implichi la correttezza su tutta la classe di equivalenza dipende dalla realizzazione del programma e non è verificabile sulla base delle sole specifiche funzionali.

### Valori limite (di frontiera)
Metodo basato sull'individuazione di valori estremi. 
- Estremi delle classi di equivalenza definite in base all'eguaglianza del comportamento del programma.
- Estremi in base a considerazioni inerenti il tipo dei valori d'ingresso (per esempio se interi considerare 0 e 1).

**Esempio**.
Abbiamo il metodo ```int calcolaTasse(int reddito)```. Il test obligation è provare tutti gli intorni degli estremi degli intervalli. I casi di test che soddisfano le test obbligations sono: <14.990, 3.447,7, _> <15.000, 3450, _>, <15.010, 3452,7 ,_> ….
(Per questa specifica è poso significativo questo criterio: sui punti di frontiera non è derivabile ma è comunque continua)

**Esempio** più significativo.
Frontiera punto di discontinuità. Il metodo è sempre ```int calcolaSconto(int spesa)```
![[Screenshot 2023-12-04 at 11.43.08.png]]
I casi di test che soddisfano le test obligations: <48.99 , 0, _>, <49.00, 7.35, _>, <49.01 , 7.3515 ,_> …

Questo criterio ricorda i controlli sui valori limite tradizionali in altre discipline ingegneristiche per le quali è vera la proprietà del comportamento continuo (ad esempio in meccanica una parte provata per un certo caricoresiste con certezza a tutti i carichi inferiori).

In realtà si guardano i valori limite perché spesso è nell'intorno dei valori limite che si nascono difetti del codice.

**I casi non validi**
Per ogni input si definiscono anche i casi non validi (chedevono generare un errore): età inferiori a 20 o superiori a 120 per la laurea, reddito negativo per il calcolo delle aliquote, spesa negativa per il calcolo dello sconto.

### Metodo random
Generare in modo automatico un insieme grande a piacere di valori:
- Costo zero la generazione
- Non ripetibile e può essere difficile trovare l'output atteso
- Applicabile se costa poco l'esecuzione
- Difficilmente considera i casi limite (Per esempio trovare le radici di un'equazione di secondo grado, quasi impossibile che il caso b=0, a=0 sia generato in modo casuale)

### Test basato su catalogo
Nel tempo un organizzazione può essersi costruita un'esperienza nel definire casi di test. Collezionare questa esperienza in un catalogo può rendere più veloce il processo e automatizzare alcune decisioni riducendo l'errore umano.
I cataloghi catturano l'esperienza di coloro che definiscono i test elencando tutti i casi che devono essere considerati per ciascun possibile tipo di variabile. 

**Esempio** di voce nel catalogo.
Assumiamo che una funzione usi una variabile in cui valore deve appartenere ad un intervallo di interi, il catalogo potrebbe indicare i casi seguenti come rilevanti.
1. L'elemento che precede immediatamente il lower bound dell'intervallo.
2. Il lower bound.
3. l'upper bound
4. Un elemento non confinabile entro l'intervallo.
5. L'elemento su sussegue immediatamente l'upper bound.

Di fatto si stanno considerando: l'intervallo in cui è definita la funzione come se fosse un'unica classe di equivalenza, la sua frontiera, i valori non validi.

## Test combinatorio
Tecnica da applicare al crescere del numero dei parametri in input.
In presenza di più dati in input, se si prende il prodotto cartesiano dei casi di test individuati, facilmente si ottengono numeri non gestibili.
Occorrono quindi strategie per generare casi di test significativi in modo sistematico.

Ci sono 2 tecniche per ridurre **l'esplosione combinatoria**.
- **Vincoli**
- **Pairwise testing**

### Vincoli
Immaginiamo 5 parametri di input <x1, x2, x3, x4, x5>
- Il dominio di x1 e x2 ripartibile i 8 classi (di cui una di valori non validi -> errore)
- Il dominio di x3 e x5 ripartibile in 4 classi (di cui una di valori non validi -> errore)
- Il dominio di x4 ripartibile in 7 classi (di cui una di valori non validi -> errore)
Se prendiamo 1 rappresentare per classe: 8 * 8 * 4 * 7 * 4 = 7168 casi di test.

Si considerano 3 strategie "a vincoli" per ridurre il numero di possibili combinazioni:
- **Vincoli di errore**
	Prendiamo l'esempio di prima <x1, x2, x3, x4, x5>. Una rappresentate per classe 8 * 8 * 4 * 7 * 4 = 7168 casi di test.

	Viene perso un solo caso, per ogni posizione, con input non valido: 5 + 8 * 8 * 4 * 7 * 4 = 2.651, quindi abbiamo ridotto a quasi 1/2 i casi.
	
- **Vincoli property/if property** 
	Definiamo dei vincoli property/if property sui primi due parametri
	- x1: classe 1, classe 2, classe 3, <u>classe 4 \[property negativi\]</u> classe 5, classe 6, <u>classe 7 \[property positivi\]</u>, <u>(classe8 \[error\])</u>
	- x2: classe 1, classe 3, classe 5, <u>classe 7 \[if negativi\]</u> classe 2, classe 4, <u>classe 6 \[if positivi\]</u>,  <u>(classe8 \[error\])</u>
	
	Quindi abbiamo 5 + (4 * 4 + 3 * 3) * 3 * 6 * 3 = 5 + 1350 = 1355 un altra importante riduzione.
	
- **Vincoli single**
	Per uno o più parametri si può decidere di testare un solo valore, per esempio applichiamo il metodo "single" ad x4 quindi abbiamo:
	5 + (4*4+3*3) * 3 * 1 * 3= 5 + 225 = 230

La tecnica basata su vincoli permette di introdurre vincoli che limitino il numero di test ottenuti dalla generazione di tutte le combinazioni di valori possibili.

Funziona bene se i vincoli che imponiamo sono **reali vincoli del dominio** e non se li aggiungiamo al solo scopo di limitare le combinazioni.

### Pairwise testing
Viene anche chiamato combinazione di test basato su coppie.
Prendiamo sempre foo(x1, x2, x3, x4, x5). Nel caso in cui il dominio non contenga in sé dei vincoli è preferibile optare per un'altra tecnica: **la generazione di tutte le combinazioni solo per i sottoinsiemi di 2 variabili**

In genere si possono generare tutte le combinazioni solo per i sottoinsiemi di k variabili con k < n (pairwise quando k = 2).

L'idea: generare tutte le possibili combinazioni solo per **possibili** coppie di variabili.

**Esempio**. Riprendiamo il caso <x1, x2, x3, x4, x5>. Tutte le combinazione portano a 8 * 8 * 4 * 7 * 4 = 7.168. Quanto si risparmia con il pairwise ?
8 * 8+ 8 * 4 + 8 * 7 + 8 * 4  + 8 * 4 + 8 * 7 + 8 * 4 + 4 * 7 + 4 * 4 + 7 * 4 = 371, in realtà sono anche meno se generiamo le combinazioni in maniera efficiente.

**Esempio**.
![[Screenshot 2023-12-04 at 12.20.14.png]]
Se volessimo generare tutte le combinazioni per Display mode, screen size e fonts avremo $3^3 = 27$. Andiamo dunque a generare tutte le combinazioni per la coppia <display mode, screen size>, abbiamo quindi $3^2 = 9$.
Poi occorre generare anche tutte le combinazioni per le coppie FontsxScreen e FontsxDisplay. 
Ma in questo caso generando le combinazioni per la prima coppia il valore del terzo parametro può essere aggiunto in modo da coprire anche tutte le combinazioni di FontsxScreensize e FontsxDispay mode.

![[Screenshot 2023-12-04 at 12.22.44.png]]

La generazione di combinazioni che in maniera efficiente coprano tutte le coppie è impossibile da fare a mano per molti parametri con molti valori ma può essere fatta con euristiche.