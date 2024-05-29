Sono tipi di algoritmi che si applicano quando:
- La sequenza di azioni non è importante ma conta solo il goal
- Tutti gli elementi della soluzione sono nello stato ma alcuni vincoli sono violati

## Hill climbing
##### Salita rapida
Si valutano i nodi successori vedendo quello che migliora lo stato attuale. Non si tiene traccia degli altri.
##### Stocastico
Si sceglie uno a caso fra i successori che comunque possono migliorare la situazione.
##### Prima scelta
Il primo successore generato fra i possibili. Più casuale. Utile quando i successori sono molti.
##### Riavvio casuale
Si riparte da un punto scelto a caso

```python
def hill_climbing(problem): """ Ricerca locale - Hill-climbing."""
	current =Node(problem.initial_state)
	while True:
		neighbors =[current.child_node(problem, action) for action in
				    problem.actions(current.state)]
	if not neighbors:
		# se current non ha successori esci e restituisci current
		break
		
	# scegli il vicino con valore piu’ alto (sulla funzione problem.value)
	neighbor =(sorted(neighbors,key =lambda x:problem.value(x), reverse =True))[0]
	if problem.value(neighbor) <=problem.value(current):
		break
	else:
		current =neighbor # (altrimenti, se vicino e migliore, continua)
return current
```
## Tempra simulata
Ad ogni passo si scegli un successore n a caso. Se migliora lo stato corrente viene espanso, in caso contrario quel nodo viene scelto con probabilità
$$p = e^{\Delta E/ T} \:\:\:\:\:\: \Delta E = f(n') - f(n) \leq 0$$
Si genera un numero casuale tra 0 e 1, se è < 0 il successore scelto , altrimenti no.
$p$ è inversamente proporzionale al peggioramento, se la mossa peggiora molto (quindi $\Delta E$ alto negativo), la p si abbassa.
T è un parametro che decresce col progredire dell'algoritmo (quindi anche p secondo un piano infinito)
## Local beam
Versione locale del Beam Search. Si tengono in memoria k stati, anziché uno solo, ad ogni passo si generano i successori di tutti i k stati, se si trova un goal ci si ferma, altrimenti si prosegue con i k migliori tra questi.
## Algoritmi evolutivi o Beam search stocastica
La popolazione iniziale è formata da:
- k stati o individui
- ogni individuo è rappresentato come una stringa

I passi sono:
1. Valutati da una **funzione di fitness**
2. Per ogni coppia viene scelto un punto di **crossing over** e vengono generati due figli
3. Si esegue una **mutazione** casuale che dà luogo alla prossima generazione

## Spazi continui (gradiant)
Se la funzione $f$ è continua e differenziabile si può andare a cercare il minimo o il massimo utilizzato il **gradiante** che restituisce la direzione di massima pendenza del punto
$$\nabla f = (\frac{\partial f}{\partial x_1}, \frac{\partial f}{\partial x_2}, \frac{\partial f}{\partial x_3})$$
Hill climbing iterativo:
$$x_new = x + \eta \nabla f(x)$$