## Valutazione strategie
#### Completezza
Se la soluzione esiste viene trovata
#### Optimality (ammissibilità)
Trova la soluzione migliore, con costo minore
#### Complessità in tempo
Tempo richiesto per trovare la soluzione
#### Complessità in spazio 
Spazio richiesto durante la ricerca

## Ricerca in ampiezza (BF)

```python
def breadth_first_search(problem): # """Ricerca-grafo in ampiezza"""
	# insieme degli stati gia visitati (implementato come una lista)
	explored =[] 
	# il costo del cammino e inizializzato nel costruttore del nodo
	node = Node(problem.initial_state) 
	
	if problem.goal_test(node.state):
		return node.solution(explored_set =explored)
		
	frontier =FIFOQueue() # la frontiera e una coda FIFO
	frontier.insert(node)
	
	while not frontier.isempty(): # seleziona il nodo per l espansione
		node = frontier.pop()
		# inserisce il nodo nell insieme dei nodi esplorati
		explored.append(node.state) 
		
		for action in problem.actions(node.state):
			child_node =node.child_node(problem,action)
			if (child_node.state not in explored) and 
			   (not frontier.contains_state(child_node.state)):
				if problem.goal_test(child_node.state):
				return child_node.solution(explored_set =explored)
		# se lo stato non e uno stato obiettivo 
		# allora inserisci il nodo nella frontiera
		frontier.insert(child_node)
		
	# in questo caso ritorna con fallimento
	return None 
```

Utilizza una coda di tipo **FIFO**. Definiamo:
- **B** = fattore di ramificazione
- **D** = profondità del noto obbiettivo
- **M** = lunghezza massima dei cammini nello spazio degli stati
#### Analisi
- **Strategia completa**: Si
- **Strategie ottimale**: Si
- **Complessità in tempo**: $O(b^2)$
- **Complessità in spazio**: $O(b^d)$

## Ricerca in profondità (DF)

```python
def recursive_depth_first_search(problem, node):
	#controlla se lo stato fel nodo è uno stato obbiettivo
	if problem.goal_test(node.state):
		return node.solution()
	#in caso contrario continua
	for action in problem.actions(node.state):
		child_node = node.child_node(proble, action)
		result = recursive_depth_first_search(problem, chidl_node)
		if result is not None:
			return result
	return None
```

Utilizza una coda di tipo **LIFO**
#### Analisi
- **Strategia completa**: Si
- **Strategie ottimale**: Si
- **Complessità in tempo**: $O(b^2)$
- **Complessità in spazio**: $O(b \cdot m)$
## Ricerca in profondità limitata (DL)
SI va in profondità fino ad un certo livello predefinito l.
#### Analisi
- **Strategia completa**: Si per problemi in cui si conosce un limite superiore per la profondità della soluzione. Completa se D < l
- **Strategie ottimale**: No
- **Complessità in tempo**: $O(b^l)$
- **Complessità in spazio**: $O(b \cdot l)$
## Ricerca con approfondimento iterativo (ID)
Si utilizza la DF con limite di profondità 0, poi 1, poi 2 ecc. fino a trovare la soluzione.

![[Screenshot 2024-05-17 at 18.03.57.png]]

#### Analisi
- **Strategia completa**: Si 
- **Strategie ottimale**: Si
- **Complessità in tempo**: $O(b^d)$
- **Complessità in spazio**: $O(b \cdot d)$
## Ricerca di costo uniforme (UC)
Generalizzazione della ricerca in ampiezza (BF). Si sceglie il nodo di costo minore sulla frontiera (si intende il costo $g(n)$ de cammino), si espande sui contorni di uguale (o meglio uniforme) costo invece che sui contorni di uguale profondità.

```python
def unform_cost_search(problem):
	# insieme (implementato come una lista) degli stati gia’ visitati
	explored =[] 
	# il costo del cammino e’ inizializzato nel costruttore del nodo
	node = Node(problem.initial_state) 
	# la frontiera e’ una coda coda con priorita’
	frontier =PriorityQueue(f =lambda x:x.path_cost) 
	#lambda serve a definire una funzione anonima a runtime
	frontier.insert(node)
	while not frontier.isempty():
		# seleziona il nodo e strae il nodo 
		# con costo minore, per l’espansione
		node = frontier.pop() 
	
		if problem.goal_test(node.state):
			return node.solution(explored_set =explored)
		else:
			# se non lo e’ inserisci lo stato nell’insieme degli esplorati
			explored.append(node.state)
			
			for action in problem.actions(node.state):
				child_node =node.child_node(problem, action)
			if (child_node.state not in explored) and 
				(not frontier.contains_state(child_node.state)):
				frontier.insert(child_node)
			elif frontier.contains_state(child_node.state) and
	(frontier.get_node(frontier.index_state(child_node.state)).path_cost >child_node.path_cost):
				frontier.remove(frontier.index_state(child_node.state))
				frontier.insert(child_node)
	return None # in questo caso ritorna con fallimento
```
Si utilizza una **Coda di priorità**
#### Analisi
Garantite purché il costo degli archi sia maggiore di $\epsilon > 0$
- **Strategia completa**: Si 
- **Strategie ottimale**: Si

Assunto che $C^*$ come il costo della soluzione ottima e $\lfloor C^* / \epsilon \rfloor$ numero di mosse nel caso peggiore arrotondare per difetto.
- **Complessità in tempo**: $O(b^{1 + \lfloor C^* / \epsilon \rfloor})$
- **Complessità in spazio**: $O(b^{1 + \lfloor C^* / \epsilon \rfloor})$

