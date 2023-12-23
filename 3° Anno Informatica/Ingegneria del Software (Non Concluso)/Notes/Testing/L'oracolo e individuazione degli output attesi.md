Un "oracolo" è uno strumento o una metodologia utilizzati per generare i risultati attesi di un test case. L'importanza dell'oracolo risiede nel fatto che fornisce un punto di riferimento per valutare la correttezza del sistema durante il processo di testing. Un buon oracolo è cruciale per garantire la qualità del software e la corretta individuazione di eventuali difetti.

È inutile produrre automaticamente 10.000 casi di input se l'output atteso deve esser calcolato a mano!

### Come trovare l'output atteso
- <u>Risultati ricavati dalle specifiche</u>: specifiche formali, specifiche eseguibili.
- <u>Inversione delle funzioni</u>: quando l’inversa è “più facile”, a volte disponibile fra le funzionalità, limitazioni per difetti di approssimazione, partire dall’output e trovare l’input. Per esempio per testare un algoritmo di ordinamento prendere un array ordinato (output atteso) e rimescolarlo per ottenere un input.
- <u>Versioni precedenti dello stesso codice</u>: disponibili (per funzionalità non modificate), prove di non regressione.
- <u>Versioni multiple indipendenti</u>: programmi preesistenti (back-to-back), sviluppate ad hoc, semplificazione degli algoritmi, magari poco efficienti ma corrette.
- <u>Semplificazione dei dati d'ingresso</u>: provare le funzionalità su dati semplici, risultati noti o calcolabili con altri mezzi, ipotesi di comportamento costante.
- <u>Semplificazione dei risultati</u>: accontentarsi di risultati plausibili, tramite vincoli fra ingressi e uscite, tramite invarianti sulle uscite.

**Automazione dell'architettura di test**
![[Screenshot 2023-12-05 at 13.03.03.png]]

### Test di sistema
- **Facility test (test delle funzionalità)**. È il più intuitivo dei controlli, quello cioè che mira a controllare che ogni funzionalità del prodotto stabilita nei requisiti sia stata realizzata correttamente. 

- **Security test**. Cercando di accedere a dati o a funzionalità che dovrebbero essere riservate, si controlla l’efficacia dei meccanismi di sicurezza del sistema.

- **Usability test**. Si vuole valutare la facilità d’uso del prodotto da parte dell’utente finale. Valutazione fra le più soggettive; prodotto + documentazione + livello di competenza dell’utenza + caratteristiche operative dell’ambiente d’uso del prodotto. 

- **Performance test.** È un controllo mirato a valutare l’efficienza di un sistema rispetto ai tempi di elaborazione e ai tempi di risposta. ◦ controllo critico per esempio per i sistemi in tempo reale◦ Il sistema viene testato a diversi livelli di carico, per valutarne le prestazioni.

- **Volume test (o load test, test di carico).** Il sistema è sottoposto al carico di lavoro massimo previsto dai requisiti e le funzionalità sono controllate in queste condizioni. Lo scopo è sia individuare malfunzionamenti che non si presentano in condizioni normali, quali difetti nella gestione della memoria, buffer overflows, etc., sia garantire un’efficienza base anche in condizioni di massimo carico. Le tecniche e gli strumenti come per il performance test: i due tipi di test hanno scopi molto differenti, da un lato valutare le prestazioni a vari livelli di carico, non limite, dall’altro valutare il comportamento del sistema sui valori limite.

- **Stress test.** Il sistema è sottoposto a carichi di lavoro superiori a quelli previsti dai requisiti o è portato in condizioni operative eccezionali, in genere sottraendogli risorse di memoria e di calcolo. Esplicito superamento dei limiti operativi previsti dai requisiti.  Lo scopo è quello di controllare la capacità di “recovery” (recupero) del sistema dopo un fallimento.

- **Storage use test.** È ancora un controllo legato all’efficienza di un sistema, ma mirato alla richiesta di risorse – la memoria in particolare –durante il funzionamento, e ha implicazioni sull’ambiente operativo richiesto per poter installare il sistema.

- **Configuration test.** Obiettivo la prova del sistema in tutte le configurazioni previste: piattaforme di installazione diverse per sistema operativo o dispositivi hardware installati, insiemi di requisiti funzionali leggermente diversi. 

- **Compatibility test.** obiettivo valutare la compatibilità del sistema con altri prodotti software. Versioni precedenti dello stesso prodotto, sistemi diversi, ma funzionalmente equivalenti che il prodotto deve rimpiazzare, altri sistemi software con cui il prodotto deve interagire.