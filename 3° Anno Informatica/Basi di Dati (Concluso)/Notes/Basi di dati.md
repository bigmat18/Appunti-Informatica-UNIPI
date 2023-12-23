# [[Introduzione basi di dati]]

# Progettazione basi di dati
Progettare una basi di dati vuole dire progettare la struttura dei dati e le applicazioni. La progettazione dei dati è l’attività più importante , per progettare i dati al meglio è necessario che i dati siano un modello fedele del dominio del discorso, per questo studiamo ora la MODELLAZIONE.

*Definizione*: Un modello **astratto** è la rappresentazione formale di idee e conoscenze relative a un fenomeno.

Fra gli aspetti principali di un modello c'è che:
- il modello è la rappresentazione di certi fatti. 
- La rappresentazione è data con un linguaggio formale. 
- Il modello è il risultato di un processo di interpretazione, guidato dalle idee e conoscenze possedute dal soggetto che interpreta.
La stessa realtà può utilmente essere modellata in modi diversi, e a diversi livelli di astrazione.

**Fasi progettazione**
![[Screenshot 2023-11-20 at 17.19.22.png]]
Ciascuna di queste fasi è centrata sulla modellazione. La modellazione verrà discussa quindi con riferimento alla problematica della progettazione delle basi di dati.

![[Screenshot 2023-11-20 at 17.19.38.png]]

*Definizione Modello dei dati*:
Insieme di costrutti utilizzati per organizzare i dati di interesse e descriverne la dinamica. Componente fondamentale: meccanismi di strutturazione (o costruttori di tipo). Come nei linguaggi di programmazione esistono meccanismi che permettono di definire nuovi tipi, così ogni modello dei dati prevede alcuni costruttori.

Ad esempio, il modello relazionale prevede il costruttore relazione, che permette di definire insiemi di record omogenei.

### Aspetti del problema
Quale conoscenza del dominio del discorso si rappresenta?
**Aspetto Ontologico** (studio di ciò che esiste): ciò che si suppone esistere nell'universo del discorso e quindi si da modellare.

Con quali meccanismi di astrazione di modella?
**Aspetto logico**

Con quale linguaggio formale si definisce il modello?
**Aspetto linguistico**

Come si procede per costruire un modello?
**Aspetto pragmatico**: metodologia (insieme di regole finalizzare alla costruzione del modello informatico) da seguire nel processo di modellazione.

### Aspetto ontologico
- Conoscenza concreta: i fatti
- Conoscenza astratta: struttura e vincoli sulla conoscenza concreta.
- conoscenza procedurale, comunicazioni: Le operazioni di base, le operazioni degli utenti, come si comunicherà con il sistema informatico.
Nel seguito l'attenzione sarà sulla conoscenza concreta ed astratta.
### [[Aspetto logico ]]

## Costruzione di una base di dati (recap)
1. [[Analisi dei requisiti]]
	- Analizza il sistema esistente e raccoglie requisiti informali
	- Elimina ambiguità imprecisioni e disuniformità
	- Raggruppa le frasi relative a diverse categorie di dati, vincoli e operazioni.
	-  Costruisce un glossario.
	- Disegna lo schema di settore
	- Specifica le operazioni
	- Verifica le operazioni
	- verifica la coerenza tra operazioni e dati.
1. Progettazione 
	1. [[Progettazione concettuale]] -> schema concettuale
	2. [[Progettazione logica]] -> schema logico
	3. Progettazione fisica -> scema fisico
2. Realizzazione

Spesso indichiamo analisi dei requisiti all'interno della progettazione.
# [[Modello relazionale]]

# [[Algebra relazionale]]

# [[La normalizzazione]]

# [[DBMS]]
