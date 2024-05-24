Ricerca in spazi di ipotesi. Possiamo definirli come una funzione che ritorna un valore bool
$$c: X \to \{0, 1\}$$
Con $X$ che è lo spazio di istanze.
Lo spazio di ipotesi $H$ ha cardinalita $|H| = 2^{2^n}$ con $n=$ dimensione input.
In caso di regole congiuntive
- con **letterali positivi** abbiamo che $|H| = 2^n$
- con **letterali** (che includono il not(l)) abbiamo che $|H| = 3^n + 1$

Definiamo poi 
- **Numero istanze distinte** = la moltiplicazione fra il numero di valori che possono assumere le variabile in input.
- **Concepts distinti** = $2^{numero\_istanze}$
- **Numero di ipotesi sintatticamente distinte**: come numero di istanze ma con + 2 al valore per ogni variabile in input (si aggiunge $? / \emptyset$)
- **Numero di ipotesi semanticamente distinte**: 1 + valore di numero di istanze distinte con +1 (si aggiunge solo il $?$ perché $\emptyset$ si unifica in un unico caso)

## Find-S
```python
def find_s():
	h = # il valore più SPECIFICO in H
	for x in training_set:
		if x.value >= 0: # Istanza positiva
			if a_i.is_satisfied(h, x):
				continue
			else:
				# sostituisce a_i in h dal successivo vincolo più 
				# generale, cioé soddisfatto da x [rimuovi da h 
				# i letterali non soddisfatti in x]
				h.replace(a_i, x)  
```

- Spazio di ipotesi H **descritto da congiunzioni di attributi**
- Produrrà ipotesi più specifica fra quelle coerenti con gli esempi di training positivi.
- L'ipotesi sarà coerente con gli esempi negativi $\Leftrightarrow$ il target concept sia contenuto in H.

## List-then Eliminate
Definiamo il **version space** come 
$$VS_{H, D} = \{h \in H \: |\: Consistent(h, D)\}$$
Con $H =$ spazio delle ipotesi, $D=$ insieme di training. Consistent è così definita:
$$ Consistent(h, D) = \{\forall <x, c(x)>\: \in D \: |\: h(x) = c(x)\}$$
```python
def list_then_eliminate():
	VS = # lista contentente ogni ipotesi in H
	for d in D: # per ogni esempio di training
		VS.remove("""rimuovi ogni ipotesi che è incosistente con 
			         l'esempio di training d""")
	return VS
```

## Candidate elimination
Definiamo questi modi di rappresentare il VS:
- **Confine generale** (G) = insieme di membri generali massimi
- **Confine specifico** (S) = insieme di membri specifici massimi 

```python
def candidate_elimination():
	for d in D:
		if d.value > 0: # POSITIVO
			# rimuovo da G qualsiasi ipotesi che sia incoerente con d
			G.remove_all(d)
			for s in S: # s non consistenti
				# rimuovo s da S
				S.remove(s)
				
				# Aggiungere ad S tutte le generalizzazioni minime h di s
				# t.c h consisstente con d e ci sia un membro più generico
				# in G rispetto a h
				S.append(h) 
				
			# rimovi qulsiasi ipotesi più generale rispetto ad altre 
			# ipotesi in S
			S.clear()
			
		if d.value < 0: # NEGATIVO
			# rimuovo da S qualsiasi ipotesi che sia inconsistente con d
			S.remove_all(d)
			
			for g in G: # g non consistenti
				# rimuovo g da G
				G.remove(g)
				
				# Aggiungere a G tutte le specializzazioni minime h di g
				# t.c h consisstente con d e ci sia un membro più specifico
				# in S rispetto a h
				G.append(h) 
				
			# rimovi qulsiasi ipotesi meno gnerale rispetto ad altre 
			# ipotesi in G
			G.clear()
```
