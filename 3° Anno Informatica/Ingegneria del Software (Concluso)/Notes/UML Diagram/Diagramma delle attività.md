Modellano il flusso di lavoro (workflow, business model) di un algoritmo o di un processo. Un'attività descrive come coordinare un insieme di azioni:
- Sequenze 
- Scelte codizionali
- Iterazioni
- Concorrenza
Modellano un’attività relativa a una qualsiasi entità o collezione di entità, ad esempio: una o più classi che collaborano in una attività comune, uno o più attori con il sistema, un'operazione di classe.
Alcuni usi dei diagrammi di attività: 
- modellare un processo aziendale (analisi) 
- modellare il flusso di un caso d’uso (analisi) 
- modellare il funzionamento di un’operazione di classe(progettazione)
- modellare un algoritmo (progettazione o testing)
### Attività
Un’attività ha un nome ed è contenuta in un rettangolo con gli angoli smussati. Il contenuto di un’attività è un grafo diretto i cui:
- i **nodi** rappresentano le componenti dell’attività, come le azioni o i nodi di controllo (inizio, fine, etc)
- gli **archi** rappresentano il control flow: i possibili path eseguibili per l’attività.

![[Screenshot 2024-01-07 at 18.01.21.png | 500]]

**Inizio e fine attività**
![[Screenshot 2024-01-07 at 18.02.44.png | 500]]
## Le azioni
Le azioni sono rappresentate anche esse da rettangoli con angoli smussati. il nome deve descrivere un’azione, quindi tipicamente essere un verbo. Sono **atomiche** (e non interrompibili)![[Screenshot 2024-01-07 at 18.03.33.png | 400]]
**Nodo azione**
La freccia di uscita è presa appena è terminata l’azione. Vincolo: solo una freccia entrante e una uscente per ogni azione.
![[Screenshot 2024-01-07 at 18.04.11.png | 400]]

### Transazioni
Quando un’azione ha terminato il proprio lavoro scatta una transizione automatica in uscita dall’azione che porta all’azione successiva.
![[Screenshot 2024-01-07 at 18.04.56.png | 500]]
La semantica è descritta con il token game: l’azione può essere eseguita quando riceve il token.

### Nodi di controllo
![[Screenshot 2024-01-07 at 18.05.36.png | 500]]
### Scelta
Abbiamo detto che ogni azione si attiva appena riceve un token, si esegue e poi passa il token sull’arco uscente. Questo meccanismo di passaggio del token viene al teratoda una choice.![[Screenshot 2024-01-07 at 18.06.45.png | 500]]
### Decisione e fusione (choice and merge)
![[Screenshot 2024-01-07 at 18.07.59.png | 500]]
**Semantica**
Le guardie devono coprire tutte le possibilità, in caso si usa \[else\]. È bene (ma non necessario) che siano mutuamente esclusive altrimenti comportamento non deterministico Le condizioni di guardia sempre tra [ ] (in generale in UML).
Dato un nodo decisione non è obbligatorio un nodo fusione corrispondente. Potrebbe per esempio esserci un nodo di fine flusso.
### Iterazioni
![[Screenshot 2024-01-07 at 18.09.37.png | 500]]
### Fork
![[Screenshot 2024-01-07 at 18.10.21.png | 500]]
### Join
![[Screenshot 2024-01-07 at 18.10.57.png | 500]]
### Biforcazione e ricongiunzione (Fork & join)
Token game:
- la fork moltiplica i token: dato un token in ingresso, ne "produce" uno per ogni frecciauscente.
- La join li consuma: Si attende un token per ogni freccia entrante ◦ Si consumano tutti e ne esce solo uno.
Non è necessaria una join per ogni fork.
### Nodo di fine attività
Se un token raggiunge un nodo di fine attività , l’intera attività è terminata. Permettiamo più archi entranti su un nodo di fine attività o di fine flusso (e solo su questi). La semantica è: il primo token che arriva termina l’attività.
![[Screenshot 2024-01-07 at 18.23.49.png | 400]]
Il primo che compra i biglietti termina l'attività.
![[Screenshot 2024-01-07 at 18.25.54.png | 500]]
### Nodo di fine di flusso
Per terminare un execution path non tutta l’ attività. 
![[Screenshot 2024-01-07 at 18.27.06.png | 400]]
Il primo che compra i biglietti non termina l’attività. Vengono presi i biglietti in entrambe le code.
![[Screenshot 2024-01-07 at 18.27.43.png | 500]]
### Fork e merge 
Possibile ma le azioni dopo il merge sono eseguite due volte.
![[Screenshot 2024-01-07 at 18.29.07.png | 500]]
**Esempio**. Esempio interessante perché sbagliato.
Anche se UML permette frecce multiple entranti/uscenti in/da un nodo, se ne sconsiglia (vieta in questo corso) assolutamente l’uso: la semantica UML in è quella della fork/join, ma è facile sbagliarsi e disegnare diagrammi come questo che vanno in deadlock: eat attende due token che non possono mai arrivare.
![[Screenshot 2024-01-07 at 18.30.16.png | 500]]
**Diagramma corretto.**
Prima di eat serve un modo fusione e dopo choose dinner un nodo decisione. Sono tollerate due frecce entranti nello stato finale.
![[Screenshot 2024-01-07 at 18.31.44.png | 500]]
### Segnali ed eventi
Accettazione di evento esterno:
![[Screenshot 2024-01-07 at 18.32.42.png | 200]]
Invio di un segnale:
![[Screenshot 2024-01-07 at 18.33.03.png | 200]]
Accettazione di evento temporale:
![[Screenshot 2024-01-07 at 18.33.28.png | 200]]
Nodi specializzati che gestiscono l’invio e la ricezione di segnali. L’invio di segnali è **asincrono** e **non blocca l’attività**.
### Accettazione evento esterno o temporale
Per accettazione evento esterno e per accettazione eventi temporali: arco entrante non necessario. 
- Se assente, quando si verifica l’evento, si genera un token.
- Se presente, l’azione è abilitata quando arriva il token e si attende l’evento esterno per farlo transitare.
![[Screenshot 2024-01-07 at 18.39.10.png | 600]]
**Esempio**
![[Screenshot 2024-01-07 at 18.39.35.png | 500]]
**Esempio**. Time-out
![[Screenshot 2024-01-07 at 18.40.27.png | 500]]
### Accettazione eventi esterni e invio segnali/azioni
Quando usare un’azione e quando usare accettazione di eventi esterni o invio segnali: 
- Si usa un’**azione** quando è effettuata dall’entità/insieme di entità di cui si sta descrivendo il comportamento.
- Usare **accettazione di eventi esterni o invio segnali** quando si comunica con una entità esterna.
### Sotto-attività
Un diagramma può contenere un riferimento aun’attività secondaria (sotto-attività).
Ex: Mandare Lettera a Babbo Natale nel diagramma (Ricevere i Regali di Natale)
![[Screenshot 2024-01-07 at 18.42.26.png | 400]]
Il rastrello indica che è un riferimento a sotto- attività (ma non in Visual paradigm dove il nome è in grassetto).
![[Screenshot 2024-01-07 at 18.42.40.png | 500]]
**Esempio**
![[Screenshot 2024-01-07 at 18.43.16.png | 400]]
### Partizioni
Permettono di assegnare la responsabilità delle azioni, una **partizione** spesso corrisponde alla divisione di unità operative in un modello di business.
![[Screenshot 2024-01-07 at 18.51.11.png | 300]]
**Esempio**
![[Screenshot 2024-01-07 at 18.51.44.png | 400]]