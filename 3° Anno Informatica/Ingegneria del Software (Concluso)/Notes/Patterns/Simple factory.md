**PROBLEMA.**
Chi deve essere responsabile di creare gli oggetti quando la logica di creazione è complessa e si vuole separare la logica di creazione dalle altre funzionalità di un oggetto?

**SOLUZIONE*
La delega ad un oggetto chiamato Factory che gestisce la creazione.

![[Screenshot 2023-11-15 at 15.08.38.png | 500]]

![[Screenshot 2023-11-15 at 15.15.31.png | 500]]

**Esempio.** Consideriamo una pizzeria che fa differenti tipi di pizza.
![[Screenshot 2023-11-15 at 15.16.06.png | 500]]

Idea: tirare fuori la parte di codice dedicata alla creazione ed inserita dentro un oggetto che si occupa della creazione delle pizze. Diagramma delle classi per questo esempio:
![[Screenshot 2023-11-15 at 15.17.45.png]]

Altra possibile soluzione:
![[Screenshot 2023-11-15 at 15.18.10.png | 500]]

![[Screenshot 2023-11-15 at 15.18.53.png | 500]]
