 La logica di primo ordine è composta da:
 - **simboli costanti**: oggetti
 - **simboli predicato**: relazioni
 - **simboli di funzione**: funzioni

Abbiamo poi i quantificato:
- **Esistenziale**: $\exists$
- **Universale**: $\forall$

Dai quantificazioni possiamo avere:
- **Variabili legate**: usate con un quantificatore.
- **Variabili libere**: non usare con un quantificatore.

## Trasformazione in FOL
**Teorema**: per ogni formula chiusa $\alpha$ del FOL è possibile trovare in maniera **effettiva** un insieme di clausole $FC(\alpha$) che è soddisfacibile $\Leftrightarrow \:\: \alpha$ lo è.

**Effettiva**= esiste un procedura che può essere eseguita per trasformare la formula $\alpha$ in un insieme di clausole $FC(\alpha)$ tale che valga questo risultato.

1. Eliminazione delle implicazioni
2. Negazioni all'interno
3. Standardizzazione delle variabili. Facciamo in modo che ogni quantificatore usi variabili diverse.
4. Skolemizzazione: eliminazione dei quanitificatori esistenziali. Lo si fa mettendo al posto una funzione che prende in input la variabile nel universale.
5. Eliminazione quantificatori universali. (tutte le variabili legate al quantificatore diventato variabili libere)
6. Forma normale congiuntiva
7. Notazione a clausole
8. Separazione delle variabili, clausole diverse, variabili diverse.

## Unificazione
Operazione mediante la quale si determina se due espressioni possono essere rese identiche mediante **sostituzione** di termini a variabili.

**Sostituzione**: un insieme finito di associazioni tra variabili e termini in cui ogni variabile compare una sola volta sulla sinsitra.

```
function Unify(x, y, T)
	if T == fallimento 
		return fallimento
	else if x == y 
		return T
	else if Variabile?(x)
		return Unify-Var(x, y, T)
	else if Variabile?(y)
		return Unify-Var(y, x, T)
	else if Composta?(x) and Composta?(y)
		return Unify(Args(x), Args(y), Unify(Op(x), Op(y), T))
	else if Lita?(x) and Lista?(y)
		return Unify(Resto(x), Resto(y), Unify(Primo(x), Primo(y), T)) 
	else 
		return fallimento


function Unify-Var(var, x, T) 
	if {var/val} ∈ T per qualche val 
		return Unify(val, x, T) 
	else if {x/val} ∈ T per qualche val
		return Unify(var, val, T) 
	else if Controlla-Occorrenza?(var, x)
		return fallimento 
	else return Aggiungi {var/x} a T

Controlla-Occorrenza controlla se var occorre all’interno dell’espressione x (occur check). In tal caso fallisce.
```