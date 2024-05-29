## Maximum margin classifier
No tutti gli iperpiani risolvono allo stesso modo. Andiamo a massimizzare i margini andando a trovare i **vettori di supporto**
$$|w^T x_p + b| = 1$$
Distanza dall'iperpiano $= 1$, i punti sono correttamente classificati se $(w^T x_i + b) \geq 1 \:\:\forall\: I$ 

Massimizzare i margini $\Leftrightarrow$ minimizzare $|w|$ $\Leftrightarrow$ minimizzare $|w|^2 / 2$
Inoltre vediamo che **VC** è inversa dei margini, quindi diminuisce con alti margini.

Il **training problem** è trovare $(w, b)$ tale che tutti i punti di training sono correttamente classifica E il margine è massimizzato
##### Problema duale
Variante della versione vista sopra permette di usare i **vettori di supporto**
$$\sum_i \alpha_i - \sum_{ij} \alpha_i \alpha_j y_i y_j x_i^t x_j /2$$
con $\alpha_i \geq 0$ e $\sum_i \alpha_i y_i = 0$.

##### Soft margin
L'hard margin per tutti i punti potrebbe essere troppo restrittivo. Viene aggiunta la variabile di allentamento $\xi_i$ che serve per ridurre le classificazioni dovute da dati rumorosi.
$$minimize \:\:\: |w|^2 / 2 + C \cdot \sum_p \xi_p \:\:\:\:\:\: t.c. (wx_p + b) y_p \geq 1 - \xi_p \:\:\: e\:\: \xi_p \geq \forall\:p$$
C è un iperparamentro
- Basso C $\Rightarrow$ molti errori del TR sono concessi (underfitting)
- Alto C $\Rightarrow$ nessun errore TR, ma basso margine (overfitting)

## **Kernel**
Per risolvere alcuni problemi non classificabili linearmente possiamo mappare i punti su un **feature space** dove possono essere separabili.  

È una funzione $k: R^n \times R^n \to R$ definita come:
$$k(x_i, x_j) = \phi(x_i)^T\phi(x_j)$$
utilizzata come soluzione più semplice per calcolare il dot product per spazi di tante dim. come quando si passa in un feature space.

- **Linear**:                $K(x_i, x_j)c= x_i^T x_j$ 
- **Polinomiale**:      $K(x_i, x_j)$ = (1+x_i^Tx_j)^k$
- **RBF**:                    $K(x_i, x_j) = e^{-\frac{||x_i - x_j||^2}{2\sigma^2}}$ 