## Least Mean Square (LMS)

Dato $l$ insieme di esempi di training, trovare $h_w(x)$ che minimizzi la perdita attesa di training. Questa perdita la definiamo come **LMS**
$$Loss(h_w) = E(w) = \sum_{p=1}^l (y_p - h_w(x_p))^2$$
Dove $x_p$ è l'input, mentre $y_p$ è l'output. Quello che dobbiamo fare è trovare i valori di $w$ t.c. questa funzione venga minimizzata.
## Gradient Descent 

Per risolvere il problema di trovare il valore di $w$ che minimizzi la $Loss(h_w)$ si utilizza questo algoritmo, dove partendo da un $w_0$ si itera:
$$w_{new}= w + \eta \Delta w$$
dove $\eta$ è una costante chiamata **learning rate**. Da questa otteniamo:
$$\Delta w_0 = - \frac{\partial E(w)}{\partial w_0} = 2(y - h_w(x)) \:\:\:\:\:\:\:\: \Delta w_1 = \frac{\partial E(w)}{\partial w_1} = 2(y - h_w(x)) \cdot x$$
- if (target y - output == 0) no correction
- if (target y - output < 0) output troppo alto
	- riduciamo $w_0$
	- if (input x > 0) riduciamo $w_1$
- if (target y - output > 0) output troppo lento

Descrizione algoritmo:
1. Inizializzare vettore pesi $w_{initial}$
2. Calcolare $\Delta w$ per ogni $w_j$
3. Calcolare $w_{new} = w + \eta \cdot \Delta w$ per ogni $w_j$
4. Ritorno al punto 2 finché non si converge
## Linear basis expansion (LBE)

Questa è una generalizzazione della funzione $h_w(x)$ utilizzata nella LMS e si definisce
$$h_w(x) = \sum_{k=0}^K w_k \phi_k(x)$$
Dove l'argomento di input è un vettore con variabili aggiuntive, le quali sono trasformazione di $x$ secondo una funzione $\phi(x)$.
Un caso particolare è quello in cui si vuole rappresentare un polinomio
$$h_w(x) = w_0 + w_1x + w_2 x^2 + \dots + w_M x^M = \sum_{j=0}^M w_j x^j$$
Si aggiunge quindi anche il parametro M, che:
- Se troppo basso $\Rightarrow$ **underfitting**
- Se troppo alto $\Rightarrow$ **overfitting**
## Regolarizzazione 

Serve per controllare i fenomeni di overfitting andando a penalizzare la complessità delle funzioni con valori di pesi grandi. Definiamo la $Loss$ con regularization come:
$$Loss(h_w) = \sum_{p = 1}^l(y_p - h_w(x_p))^2 + \lambda||w||^2 \:\:\:\:\: ||w||^2 = \sum_{i}w_i^2$$
il $\lambda$ è detto **coefficente di regolarizzazione**, l'effetto è quello del decadimento del peso
$$w_{new} = w + \eta \Delta w - 2\lambda w$$
Abbiamo in questo caso che:
- $\eta$ velocità di accrescimento (o diminuzione)
- $\lambda$ se è troppo grande, riduciamo troppo, e andiamo in **underfitting**, se invece è troppo basso non influenza a sufficente e si finisce in **overfitting**
## Classification

Usiamo i modelli lineari per andare a suddividere i risultati in due blocchi.
Versione 0, 1:
$$h(x) = \begin{cases} 1 & wx + w_0 \geq 0 \\ 0 & altrimenti\end{cases}$$

Versione -1, +1:
$$h(x) = sign(x_p^t w) = sign\bigg(\sum_{i=0}^n x_{p,i} wi\bigg)$$
Da questo definiamo due gruppi **linearmente separabili** se possono essere separati da un iperpiano di dimension $n-1$.

Possiamo applicare sia la LBE che la regularization, perdendo però la proprietà di linearmente separabile.