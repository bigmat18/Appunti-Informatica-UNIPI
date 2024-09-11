- INTER-AS
- Distance-vector decentralizzato e asincrono
- Coppie di router si scambiano info su connessioni TCP: sessioni BGP **esterne** e sessioni **interne**

Viene messo a disposizione per ogni router un modo per
- **Ottenere informazioni sulla raggiungibilità** dei prefissi di sottorete da parte dei sistemi confinati. In particolare, BGP consente a ciascuna sottorete di comunicare la propria esistenza al resto di Internet. Basta che una sottorete invii un annuncio “Esisto, son qui” e BGP si assicura che lo sappiano tutti i router di Internet

- **Determinare i percorsi ottimo verso sottoreti**. Un router per determinare il miglior cammino esegue localmente BGP sulla base di info di raggiungibilità.

###### eBGP, IBGP connections
- **eBGP** gateway riceve informazioni da gateway di altri AS su sessioni eBGP
- **iBGP** gateway distribuisce informazioni ai router interni della propria rete su sessioni iBGP, altro gateway dell'AS può ri-pubblicizzare info con eBGP

![[Screenshot 2024-08-27 at 17.40.12.png | 500]]
###### Advertisement (ADV) di BGP
- route = prefisso + attributi
- attributo **AS_PATH** (sequenza AS attraversati)
- attributo **NEXT_HOP** (indirizzo IP del primo router)

###### Policy-based routing
Si usano le **import policy** quando il gateway riceve un route advertisement, si usa l'AS policy per determinare se **annunciare il percorso** (mandare advertise) ad altri AC vicini.

###### BGP session
Due router BGP scambiano messaggi BGP su connessione TCP semi permanente.
