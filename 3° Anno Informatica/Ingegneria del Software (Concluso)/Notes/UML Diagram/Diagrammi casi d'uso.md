Descrive i requisiti funzionali del sistema. Cattura le funzionalità che un sistema deve offrire, visto dall’esterno: i compiti che un utente può realizzare con l’aiuto del sistema. 

*Definizione*: Un **attore** è un’entità esterna al sistema, che interagisce direttamente con esso in un determinato ruolo. Tre tipologie di attori:
- utente umano in un determinato ruolo.
- altro sistema.
- tempo (attore speciale)

*Definizione*: Un **caso d'uso** è una funzionaità o un servizio offerto dal sistema ad uno o più attori. Formalmente: un compito che un attore può svolgere con l’aiutodel sistema, espressa come un insieme di SCENARI.

*Definizione*: Uno **scenario** è una sequenza di interazioni (scambi di messaggi) tra sistemi e attori.

### Costruzione dei casi d'uso
La modellazione dei requisiti usando il diagramma dei casi d'uso prevede i seguenti passi:
1. Individuare il confie del sisteam
2. Individuare gli attori
3. Individuare i casi d'uso.
4. Specificare il caso d'uso con ia descrizione testuale (narrativa).

Il diagramma è composto da: 
- **Attori**: hanno un nome (Maiuscolo, è una classe) 
- **Casi d’uso**: ha un nome (Maiuscolo, è un verbo che denota il compito).
- **Relazioni**: relazioni significative tra gli attori e casi d’uso. Rappresentano interazione (sequenze di messaggi). 
- **Confine del sistema**: un rettangolo disegnato intorno ai casi d’uso per indicare il confine del sistema oggetto del modello.

![[Screenshot 2023-12-05 at 22.41.15.png]]

L’associazione attori—casi d’uso è molti a molti: un attore può essere associato a più casi d’uso e viceversa.
Un caso d’uso è iniziato sempre da uno e un solo attore, detto principale. Casi d’uso non collegati a un attore sono in casi particolari che vedremo. Eventualmente Tempo. 

![[Screenshot 2023-12-05 at 22.42.20.png]]

**Esempio 1**
![[Screenshot 2023-12-05 at 22.42.47.png]]

**Esempio 2**
![[Screenshot 2023-12-05 at 22.43.01.png]]

**Esempio 3**
![[Screenshot 2023-12-05 at 22.44.06.png]]
I clienti possono essere privati o società. Clienti e commerciali partecipano alla redazione dei contratti. Società e capi progetto partecipano alle revisioni. Commerciali e capi progetto gestiscono i progetti. N.B.: Non è chiaro in questi esempi chi sia l’attore principale: lo chiarisce la narrativa.

### Narrativa di un caso d'uso
Documento che descrive il modello dinamico, gli scenari rilevanti di un caso d’uso  dal punto di vista degli attori. Compreso chi lo inizia, i.e. chi è l’attore principale (aka primario). Caratteristiche:
- Inizio, fine, passi intermedi.
- Condizioni eccezionali.
- Precondizioni, post condizioni.

![[Screenshot 2023-12-05 at 22.45.45.png]]

**Esempio**
![[Screenshot 2023-12-05 at 22.46.28.png]]

### Scenario
Uno scenario è un'istanza di un caso d’uso: una sequenza di passi che produce un risultato osservabile da uno o piu' attori. Gli scenari descritti dalla sequenza principale degli eventi sono quelli che portano alla post condizione.
![[Screenshot 2023-12-05 at 22.47.04.png]]

**Nota importate per le pre condizione e post condizioni**
Pre- e post condizioni sono asserzioni che devono essere vere in uno stato. Sono quindi predicati o formule logiche che valgono vero o falso in uno stato: precondizione prima di iniziare il caso d’uso, post condizioni alla fine. Non sono MAI azioni.

**Esempio**
![[Screenshot 2023-12-05 at 22.52.25.png]]

### Sequenza principale e alternativa
Relazione tra pre condizione, post condizione, sequenza principale e sequenza alternativa. Parallelo con le triple di Hoare: 
{Precondizione} sequenza principale {Post condizione}.

Quindi per ogni stato σ che soddisfa la precondizione, l’esecuzione del caso d’uso a partire da σ termina producendo uno stato σ′ che soddisfa la post condizione, questo a meno che non si verifichi qualche imprevisto come quelli elencati nella sequenza alternativa, in questo caso la post condizione non è garantita.

**Sintassi**
La S.P.E. elenca i passi che compongono il caso d’uso. La sequenza è numerata e ogni passo dovrebbe avere la struttura:
\<numero\>, \<soggetto\>\<azione\>\<complementi\>
Il primo passo (attivazione) è sempre compiuto dall’attore principale.
1. L’utente chiede di prolungare il prestito 
2. Il sistema controlla ….. 
3. ….

Nella S.P.E. si possono descrivere condizioni e cicli.
![[Screenshot 2023-12-05 at 23.03.01.png]]

### Generalizzazione
**Generalizzazione tra attori**
![[Screenshot 2023-12-05 at 23.03.38.png]]

**Esempio 1**
![[Screenshot 2023-12-05 at 23.03.56.png]]

**Esempio 2**
L’introduzione di un attore astratto qui serve per soddisfare il vincolo di avere un solo attore principale.
![[Screenshot 2023-12-05 at 23.04.41.png]]

**Generalizzazione tra casi d'uso**
![[Screenshot 2023-12-05 at 23.05.35.png]]

**Attenti alla generalizzazione**
Usando la generalizzazione fare attenzione che il classificatore specializzato eredita tutte le relazione del classificatore padre (Liskov), quindi il ClienteStraniero NON eredita da Cliente.

![[Screenshot 2023-12-05 at 23.06.33.png]]

### Inclusione di casi d'uso
![[Screenshot 2023-12-05 at 23.07.22.png]]

Il caso d’uso 1 incorpora l’interazione descritta dal caso d’uso 2 come parte dell’interazione che esso (1) descrive.
La relazione include punta al caso d’uso che si include. Simile ad una chiamata di funzione. La narrazione del caso 1 dovrebbe invocare l’esecuzione del caso incluso (2). \<\<include\>\> è uno stereotipo, gli stereotipi sono keywords tre « » che annotano elementi di un diagramma, per precisarne il significato. In questo caso specifica che la relazione di dipendenza ----> è un’inclusione

**Esempio**
![[Screenshot 2023-12-05 at 23.08.40.png]]

Sia per prendere in prestito la copia di un libro che per estendere il prestito occorre prenotare il libro.
N.B. Questo è un uso corretto della relazione di inclusione: non usatela per fare decomposizione funzionale di un caso d’uso.

**Inclusione nella narrativa**
Si scrive nella lista numerata una cosa del tipo "include (nome caso incluso)".
Il caso d’uso incluso è specificato a parte. Può essere istanziabile (completo) (avviato da un attore) o non istanziabile (eseguito solo quando incluso).

### Estensione di un caso d'uso
![[Screenshot 2023-12-05 at 23.10.28.png]]

Il caso d’uso1 può incorporare l’interazione descritta dal caso d’uso2(non dipende da esso). La relazione extend punta al caso d’uso che viene esteso. La narrazione del caso 1 puo’ in qualche caso invocare l’esecuzione del caso (2). \<\<extend\>\> è anch’esso uno stereotipo.

**Esempio**
![[Screenshot 2023-12-05 at 23.11.26.png]]
Quando si crea un nuovo corso si può prenotare un’aula ma tale prenotazione non è normalmente parte della creazione del corso.

Altrimenti la prenotazione sarebbe stata un passo della sequenza principale degli eventi e la definizione di due casi separati un’inutile ed erronea decomposizione funzionale

### Extension points e condizioni
Le estensioni sono opzionali dal punto di vista del Caso d'uso base -> esiste una notazione aggiuntiva che aiuta a identificare quando e dove inserire l'estensione. Possiamo collegare un vincolo alla freccia "extend", indicando la condizione che deve essere vera perché l'estensione venga applicata.

![[Screenshot 2023-12-05 at 23.12.20.png]]