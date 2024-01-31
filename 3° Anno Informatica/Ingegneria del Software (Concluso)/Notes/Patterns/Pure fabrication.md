I **Pure fabrication** servono per risolvere il seguente problema: Non violare l'Alta Coesione e il Basso Accoppiamento.
La soluzione è: Assegnare una serie di responsabilità altamente coese ad una
classe artificiale che non rappresenta nulla nel problema dominio, al fine di supportare un'elevata coesione, un basso accoppiamento e riutilizzo.

Il design degli oggetti può essere approssimativamente suddiviso in due
gruppi:
- Quelli scelti dalla scomposizione rappresentazionale.
- Quelli scelti dalla scomposizione comportamentale

Quest'ultimo gruppo non rappresenta nulla nel dominio problematico, sono semplicemente inventati per il comodità del progettista, da qui il nome puro
fabbricazione: le classi sono progettate per raggrupparsi insieme comportamento correlato.

Un oggetto di pura fabbricazione è una sorta di oggetto incentrato sulla funzione (o
oggetto comportamentale).

In generale una Factory è una Pure Fabrication con l'obbiettivo di:
- confinare la responsabilità di creazioni complesse in oggetti coesi.
- Incapsulare la complessità della logica di creazione.