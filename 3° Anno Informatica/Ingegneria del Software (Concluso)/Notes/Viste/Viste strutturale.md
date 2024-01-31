Formate da elementi (nodi del diagramma) sono chiamati moduli: sono le unità di software che realizzano un insieme coerente di responabilità. Per esempio: classi, collezioni di classi, package. 
Formata anche da relazioni tra elementi, ess. Parte di, eredita da, dipende da può usare..

Le viste di tipo strutturale servono:
- Costruzione: la vista può fornire lo schema del codice e directory e file sorgenti hanno una struttura corrispondente.
- Analisi: tracciabilità dei requisiti, analisi d’impatto per valutare eventuali modifiche. 
- Comunicazione: se la vista è gerarchica, offre una presentazione top-down delle suddivisione delle responsabilità nel sistema ai novizi.
- Progettazione dei testi di unità

Non sono utili per: analisi dinamiche, fatte invece con viste comportamentali o logistiche 

### UML per documentare le viste di tipo strutturale
Classi: rispetto alla descrizione del dominio, più spazio alla specifica delle operazioni.
![[Screenshot 2023-11-14 at 20.05.40.png]]

Packeges:
![[Screenshot 2023-11-14 at 20.05.52.png]]

Relazioni tra classi, tra packeges e tra classi e packages: contenimento, dipendere, generalizzazione…
- Relazione \<\<parte di>> è resa con:
![[Screenshot 2023-11-14 at 20.07.26.png]]

- Relazione “usa”: Il modula A usa il modulo B se diede dalla presenza di B (funzionante correttamente) per soddisfare i suoi requisiti. Attenzione a non confondere invocazione con dipendenza: un modulo A che segnala un errore a B funziona correttamente indipendentemente da cosa fa il modulo B che riceve la segnalazione, per cui lo invoca, ma non lo usa, quindi non è suo cliente in una dipendenza. I cicli sono permessi ma pericolosi. Serve solitamente alla pianificazione di sviluppo incrementale, ed ai testi di unità e di integrazione.
![[Screenshot 2023-11-14 at 20.09.32.png]]

Esempio:
I filtri si chiamano tra loro, ma non si usano, il main li configura per metterli in comunicazione via StdIO (realizzazione del connettore pipe), suggerisce anche una vista a strati.
![[Screenshot 2023-11-14 at 23.12.27.png]]
### Vista strutturale a strati (Macchine virtuali)
- Elementi: Strati. Uno strato è un insieme coeso di moduli, a volte raggruppati in segmenti, offre un’interfaccia pubblica per i suoi servizi (macchina virtuale).
- Relazione: può usare. Caso particolare di relazione d’uso, anti-simmetrica, non implicitamente transitiva.
- A cosa serve: modificabilità e portabilità, controllo della complessità.

![[Screenshot 2023-11-14 at 23.25.41.png]]
### Vista strutturale di generalizzazione
- Elementi: moduli (classi o package)
- Relazioni: generalizzazione
- A cosa serve: A rappresentare la relazione tipo-sottotipo (tra classi), ed a rappresentare la relazione tra un framework (collezioni di classi, anche astratte, con relazioni d’uso tra loro) e una sua specializzazione (tra packeges).

### Notazione UML per documentare la vista di generalizzazione

![[Screenshot 2023-11-14 at 23.39.59.png]]
