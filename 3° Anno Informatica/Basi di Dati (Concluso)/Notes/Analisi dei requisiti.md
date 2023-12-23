### Documentazione descrittiva
In generale, il linguaggio naturale è pieno di ambiguità e fraintendimenti. Si deve, quanto più è possibile, evitare tali ambiguità. In prima approssimazione si può procedere con le seguenti regole:
- Studiare e comprendere il sistema informativo e i bisogni informativi di tutti i settori dell'organizzazione.
- Scegliere il corretto livello di astrazione
- Standardizzare la struttura delle frasi
- Suddividere le frasi articolate
- Separare le frasi sui dati da quelle sulle funzioni.

Regoli generali (pratiche):
- Eliminare ambiguità, imprecisioni e disuniformità: individuare omonimi e sinonimi e unificare i termini; rendere esplicito il riferimento fra termini. 
- Riorganizzare le frasi per concetti, ovvero ottenendo diverse categorie di dati, vincoli e operazioni.
- Costruire un glossario dei termini.
- Disegnare lo schema.
- Specificare le operazioni.
- Verificare la coerenza fra operazioni e dati.

**Esempio 1**:
![[Screenshot 2023-11-21 at 14.49.35.png]]

**Esempio 2**:
![[Screenshot 2023-11-21 at 14.50.08.png]]

**Esempio 3**:
![[Screenshot 2023-11-21 at 14.50.47.png]]

**Esempio**: struttura glossario dei termini
![[Screenshot 2023-11-21 at 14.51.38.png]]

### Strutturazione dei requisiti in gruppi di frasi omogenee
**Frasi di carattere generale**
Si vuole realizzare una base di dati per una società che eroga corsi, di cui vogliamo rappresentare i dati dei partecipanti ai corsi e dei docenti.

![[Screenshot 2023-11-22 at 16.16.53.png]]

**Frasi relative ai partecipanti**
Per i partecipanti (circa 5000), identificati da un codice, rappresentiamo il codice fiscale, il cognome, l'età, il sesso, la città di nascita, i nomi dei loro attuali datori di lavoro e di quelli precedenti (insieme alle date di inizio e fine rapporto), le edizioni dei corsi che stanno attualmente frequentando e quelli che hanno frequentato nel passato, con la relativa votazione finale in decimi.

![[Screenshot 2023-11-22 at 16.27.51.png]]

**Frasi relative ai docenti**
Per i docenti (circa 300), rappresentiamo il cognome, l'età, la città di nascita, tutti i numeri di telefono, il titolo del corso che insegnano, di quelli che hanno insegnato nel passato e di quelli che possono insegnare. I docenti possono essere dipendenti interni della società di formazione o collaboratori esterni.

![[Screenshot 2023-11-22 at 16.17.22.png]]    ![[Screenshot 2023-11-22 at 16.20.06.png]]   

**Frasi relative ai corsi**
Per i corsi (circa 200), rappresentiamo il titolo e il codice, le varie edizioni con date di inizio e fine e, per ogni edizione, rappresentiamo il numero di partecipanti e il giorno della settimana, le aule e le ore dove sono tenute le lezioni.

![[Screenshot 2023-11-22 at 16.27.27.png]]

**Frasi relative ai datori di lavoro**
Relativamente ai datori di lavoro presenti e passati dei partecipanti, rappresentiamo il nome, l'indirizzo e il numero di telefono.

![[Screenshot 2023-11-22 at 16.20.45.png]]   ![[Screenshot 2023-11-22 at 16.21.55.png]]

**Frasi relative a tipi specifici di partecipanti**
Per i partecipanti che sono liberi professionisti, rappresentiamo l'area di interesse e, se lo possiedono, il titolo professionale. Per i partecipanti che sono dipendenti, rappresentiamo invece il loro livello e la posizione ricoperta.

![[Screenshot 2023-11-22 at 16.23.38.png]]

**Frasi relative ai partecipanti**
Per i partecipanti (circa 5000), …. i nomi dei loro attuali datori di lavoro e di quelli precedenti (insieme alle date di inizio e fine rapporto), ….

![[Screenshot 2023-11-22 at 16.25.01.png]]

**Frasi relative ai docenti**
Per i docenti (circa 300), …. I docenti possono essere dipendenti interni della società di formazione o collaboratori esterni.

![[Screenshot 2023-11-22 at 16.25.45.png]]
![[Screenshot 2023-11-22 at 16.26.49.png]]

**Risultati finale**
![[Screenshot 2023-11-22 at 16.28.17.png]]

**Specifiche sulle operazioni**
Dopo aver definito i dati, occorre stabilire le specifiche sulle operazioni da effettuare sui dati. Bisogna utilizzare la stessa terminologia usata per i dati. Bisognerebbe inoltre indicare la frequenza con cui vengono effettuare certe operazioni. La conoscenza di queste informazioni è indispensabile nella fase di progettazione logica.

Per questo esempio:
- OPERAZIONE 1: inserisci un nuovo partecipante, indicando tutti i suoi dati (in media 40 volte al giorno).
- OPERAZIONE 2: assegna un partecipante a una edizione di corso (50 volte al giorno).
- OPERAZIONE 3: inserisci un nuovo docente indicando tutti i suoi dati e i corsi che può insegnare (2 volte al giorno).
- OPERAZIONE 4: assegna un docente abilitato a una edizione di un corso (15 volte al giorno).
- OPERAZIONE 5: stampa tutte le informazioni sulle edizioni passate di un corso con titolo, orari lezioni e numero di partecipanti (10 volte al giorno).
- OPERAZIONE 6: stampa tutti i corsi offerti con informazioni sui docenti che possono insegnarli (20 volte al giorno).
- OPERAZIONE 7: per ogni docente, trova i partecipanti a tutti i corsi da lui insegnati (5 volte la settimana).
- OPERAZIONE 8: effettua una statistica su tutti i partecipanti a un corso con tutte le informazioni su di essi, sulla edizione a cui ha partecipato e la rispettiva votazione (10 volte al mese).
