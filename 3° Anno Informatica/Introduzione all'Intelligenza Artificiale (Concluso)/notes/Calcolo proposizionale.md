**Conseguenza logica**: Data una KB ed un fatto $\alpha$ diciamo che
$$KB \models \alpha$$
**Equivalenza logica**. Diciamo che $\alpha$ e $\beta$ sono logicamente equivalenti quando
$$\alpha \equiv \beta \Leftrightarrow \alpha \models \beta \:\:\: e \:\:\: \beta \models \alpha$$
Ci sono una serie di equivalenze logiche come

![[Screenshot 2024-05-22 at 20.01.31.png]]
**Validità**. Una formula è valida in tutte le sue affermazione
$$A \:\lor\: \lnot A$$
Una formula validità si dice anche **tautologia**.

**Teorema di deduzione**. Date $\alpha, \beta$ se abbiamo che
$$\alpha \models \beta \:\:\: \Leftrightarrow\:\:\: \alpha \Rightarrow \beta \:\:è\:valida$$
**Soddisfacibilità**. Abbiamo che $\alpha$ è soddisfacibile se esiste un interpretazione che rende $\alpha$ vera. Abbiamo anche che:
$$\alpha \:\: è \: soddisfacibile\:\:\: \Leftrightarrow\:\:\: \alpha \:\: è \: valida$$
Per gli algoritmi cercare la soddisfacibilità vuol dire verificare
$$KB \models \alpha \Leftrightarrow (KB \land \lnot \alpha) \:\: insoddisfacibile$$
Detto **Teorema di refutazione**
## TV-Conseguenze
Si prova a verificare una conseguenza logica provando tutte le casistiche
```
function TV-Conseguenze(KB, alpha, simboli, modello)
	if Vuoto?(Simboli)
		if PL-Vero?(KB, modello) return PL-Vero?(alpha, modello)
		else return true
	else
		P = Primo(simboli), resto = Resto(simboli)
		return TV-Conseguence(KB, alpha, resto, modello + {P = true}) or
				TV-Conseguence(KB, alpha, resto, modello + {P = false})
```
## DPLL
Bisogna prima effettuare la trasformazione in clauselo. Quindi portare ogni formula nella forma
$$(A \:\lor\: B \:\lor\: \dots \:\lor\:) \:\land\: (C \:\lor\: D \:\lor\: \dots \:\lor\:) $$
Migliora la TV-conseguence effettuando una terminazione anticipata basata su:
- **Simboli puri**: un simbolo che appare con lo stesso «segno» in tutte le clausole
- **Clausole unitarie**: una clausola con un solo letterale non assegnato

```
function DPLL(clausole, simboli, modello) 
	if ogni clausola in clausole è vera in modello 
		return true 
	if qualche clausola in clausole è falsa in modello
		return false 
		
	P, valore ← Trova-Simbolo-Puro(simboli, clausole, modello) 
	if P è diverso da null
		return DPLL(clausole, simboli – P, modello ← {P = valore}) 
		
	P, valore ← Trova-Clausola-Unitaria(clausole, modello) 
	if P è diverso da null
		return DPLL(clausole, simboli – P, modello ← {P = valore}) 
		
	P ← Primo(simboli); resto ← Resto(simboli) 
	return DPLL(clausole, resto, modello ← {P = true}) or 
		   DPLL(clausole, resto, modello ← {P = false})
```
## WalkSAT
Ad ogni passo una clausola non ancora soddisfatta a caso. Individua un simbolo da modificare scegliendo con probabilità 50% tra
- Passo random
- Passo di ottimizzazione

```
function WalkSAT(clausole, p, max_flips) 
	modello ← un assegnamento casuale di valori di verità ai 
			  simboli in clausole 
	
	for i = 1 to max_flips do 
		if modello soddisfa clausole
			return modello 
		clausola ← una clausola, falsa in modello, 
				   scelta casualmente nell’insieme clausole 
		
		if Random(0, 1) =< p
			inverti il valore in modello di un simbolo scelto 
			casualmente in clausola 
			
		else inverti il valore di verità del simbolo in clausole che 
			massimizza il numero di clausole soddisfatte return fallimento
```
## Grafo di risoluzione

![[Screenshot 2024-05-22 at 20.50.41.png]]