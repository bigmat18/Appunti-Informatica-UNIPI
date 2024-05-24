Funzione da valutare con aggiunta di funzione di valutazione euristica:
$$f(n) = g(n) + h(n)$$
Con $g(n)$ costo cammino, $h(n)$ funzione euristica

## Best first
Stesso algoritmo di UC ma ad ogni passo si sceglie il nodo che migliora $f(n)$.
## A
A è una tipologia di algoritmo Best-first dove 
$$f(n) = g(n) + h(n)$$
Con $h(n) \geq 0$ e $h(goal) = 0$.
- $g(n)$ è il costo del cammino percorso per raggiungere n. 
- $h(n)$ una stima del costo per raggiungere da n un nodo goal.

**Completo**: Algoritmo A completo quando
$$g(n) \geq d(n) \cdot \epsilon$$
Con $d(n)$ è la profondità al nodo $n$, e $\epsilon > 0$ è il costo minimo arco
## $A^*$
È un algoritmo A in cui $h$ è una funzione **euristica ammissibile** cioè:
$$\forall n \: | \: h(n) \leq h^*(n)$$
Dove $h^*(n)$ è il costo del cammino minimo da n a goal. Ciò vuol dire che $h(n)$ è una sottostima. Questa cosa ci fa fare del lavoro extra ma non ci fa perdere il cammino migliore.

**Ottimale**: gli algoritmi $A^*$ sono sempre ottimali. Quando si utilizza un euristica **monotona o ammissibile** cioè:
$$\forall n \: | \: h(n) \leq c(n, a, n') + h(n')$$
Se un euristica è monotona $\Rightarrow$ è ammissibile.

Questo è un algoritmo vantaggioso perché:
- $A^*$ espande tutti i nodi con $f(n) <$ del costo della soluzione ottima
- $A^*$ espande alcuni nodi con $f(n) =$ del costo della soluzione ottima
- $A^*$ non espande i nodi con $f(n) >$ del costo della soluzione ottima
##### Distanza Manhattan
$$h(x, y) = MD((x, y), (x_g, y_g)) = |x - x_g| + |y - y_g|$$

## Greedy best first
Come la best first ma dove $f(n) = h (n)$ quindi si guarda solo l'euristica senza la funzione di distanza dalla radice.
## Beam search
Nel Beam first viene tenuta tutta la frontiera, se l'occupazione di memoria è eccessiva si può ricorrere a questa variane, la quale tiene ad ogni passo solo i k nodi più promettenti (k è detta ampiezza del raggio)
- **Completa**: No
## $IDA^*$
Combina $A^*$ con ID. Ad ogni iterazione si ricerca in profondità con un limite dato dal valore della funzione f, questo limite viene aumentato ad ogni iterazione.

Nel caso di un costo fisso il limite viene incrementato dal costo delle azioni.
Nel caso invece di costi azioni variabili, o si prende il costo minimo, oppure ad ogni passo si può fissare il limite successivo al valore minimo delle $f$ scartate all'iterazione precedente.

## Best first ricorsivo
Simile al DF ricorsivo cerca di usare meno memoria facendo più lavoro. Ad ogni livello tiene traccia del migliore percorso alternativo.

Invece di fare backtracking in caso di fallimento, interrompe l'esplorazione quando trova un nodo meno promettente rispetto a quello che ha salvato. Nel tornare indietro salva il migliore del sotto albero esplorato.

```
function best-first-ricorsivo(problema)
	return RBFS(problema, CreaNode(problema.stato-iniziale), +inf)

function RBFS(problema, nodo, f-limite) 
	if problema.TestObiettivo(nodo.Stato)
		return Soluzione(node)

	successori = []
	for azioni in problema.Azioni(nodo.Stato)
		aggiungi Nodo-Figlio(problema, nodo, azione) a successori

	if successori è vuoto than 
		return fallimento, +inf


	for s in successori do
		s.f = max(s.g + s.h, nodo.f)

	loop do
		migliore = il nodo con f minimo tra i successori
		if migliore.f > f_limite 
			than return fallimento, migliore.f

		alternativa = il secondo nodo con f minimo tra i successori
		risultato, migliore.f = RBFS(problema, migliore, min(f_limite, 
														     alternativa))
		if risultato != fallimento
			return risultato
```

# Invenzione euristiche

## Rilassamento del problema

## Massimizzazione di euristiche
Se si hanno una serie di euristiche ammissibili $h_1, h_2, \dots, h_k$ senza che nessuno domini su un'altra allora conviene prendere il massimo dei loro valori $$h(n) = max(h_1(n), h_2(n), \dots, h_k(n))$$
Se le $h_i$ sono ammissibili allora anche la $h$ lo è.
## Database di pattern disgiunti
Andiamo a memorizzare ogni istanza del problema con relativo costo della soluzione, usiamo questo database per calcolare $h_{DB}$.

Potremmo fare questa cosa per altri sottoproblemi ottenendo altre euristiche ammissibili, poi andiamo a prendere il valore massimo.
## Combinazione lineare
Quando diverse caratteristiche influenzano la bontà di uno stato, si può effettuare una combinazione lineare del tipo
$$h(n) = c_1 x_1(n) + c_2 x_2(n) + \dots + c_k x_k(n)$$
Il peso $c_1, \dots, c_k$ può essere aggiustato con l'esperienza. 

## Apprendere dall'esperienza
Si fa girare il programma e si raccolgono dati come coppie $<stato, h^*>$. Usare poi i dati per apprendere a predire la $h$  con algoritmi di apprendimento induttivo. 
