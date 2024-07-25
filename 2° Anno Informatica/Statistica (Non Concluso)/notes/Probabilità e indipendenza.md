**Proprietà $\sigma$-additiva**
$$\mathbb{P}\bigg(\bigcup_{n=1}^{\infty}A_n\bigg) = \sum_{n=1}^{\infty}\mathbb{P}(A_n)$$

- $\mathbb{P}(A^C) = 1 - \mathbb{P}(A)$
- $\mathbb{P}(A \cup B) = \mathbb{P}(A) + \mathbb{P}(B) - \mathbb{P}(A \cap B)$ con $A \cap B \neq \emptyset$  

**Probabilità uniforme**
$\mathbb{P}$ si dice uniforme su $\Omega$ se $\Omega$ è finito e i suoi elementi sono equiprobabili.
$$\mathbb{P}(A) = \frac{\#A}{\#\Omega} = \frac{casi\:favorevoli}{casi\:possibili}$$
**Probabilità condizionale**
$$\mathbb{P}(A \:|\: B) = \frac{\mathbb{P}(A \cap B)}{\mathbb{P}(B)}$$
**Condizioni ripetute**
$$\mathbb{P}(A_i \cap \dots \cap A_n) = \mathbb{P}(A_1) \cdot \mathbb{P}(A_2 | A_1) \dots \mathbb{P}(A_n | A_1 \cap \dots A_{n-1})$$

**Formula prob. totale o di fattorizzazione**
$$\mathbb{P}(A) = \sum^n_{i=1} \mathbb{P}(A|B_i)\mathbb{P}(B_i)$$
**Formula di Bayes**
$$\mathbb{P}(B |A) = \frac{\mathbb{P}(A|B)\mathbb{P}(B)}{\mathbb{P}(A)}$$
Permette di calcolare la probabiltà di un evento A, basandoci sulla conoscenza di condizioni correlate

In sistema di alternative
$$\mathbb{P}(B_i|A) = \frac{\mathbb{P}(A|B_i)\mathbb{P}(B_i)}{\mathbb{P}(A)} = \frac{\mathbb{P}(A|B_i)\mathbb{P}(B_i)}{\sum^n_{j=1} \mathbb{P}(A | B_j)\mathbb{P}(B_j)}$$
**Indipendenza**
$$\mathbb{P}(A \cap B) = \mathbb{P}(A) \cdot \mathbb{P}(B)$$
- due eventi disgiunti non possono essere indipendenti a meno che uno dei due non sia trascurabile
- se $\mathbb{P}(A) = 0$ o $\mathbb{P}(A) = 1$ allora A è indipendente da qualsiasi altro evento.
- Se $A, B$ sono indipendenti allora lo sono anche $A^C \:e\: B$, $B^C \:e\: A$ $A^C \:e\: B^C$ 

Abbiamo anche che $A_1, \dots, A_n$ si dicono indipendenti se per ogni intero $k$ con $2 \leq k \leq n$ e per ogni scelta di intero $1 \leq i_1 \leq i_2 \leq \dots \leq i_k \leq n$ vale
$$\mathbb{P}(A_{i_k}, \dots, A_{i_k}) = \mathbb{P}(A_{i_1})\dots \mathbb{P}(A_{i_k})$$

**Probabilità discreta**
$$\mathbb{P}(A) = \sum_{i: x:i \in A}p(x_i)$$
**Funzione di massa o densità discreta**
$$p(x_i) = \mathbb{P}(x_i)$$
**Densità di probabilità**
$$\mathbb{P}(A) = \int_A f(x) dx$$
- Perché esista densità $f(x)$ deve essere continua non negativa ed integrabile $\int_{-\infty}^{+\infty} f(x) dx = 1$

**Variabile aleatoria discreta**
$$\mathbb{P}_X(A) = \sum_{x_i\in A} p_x(x_i) $$
**Variabili aleatoria con densità**
$$\mathbb{P}(A) = \int_A f(x)dx $$
**Funzione di ripartizione**
$$F_X: \mathbb{R} \to [0, 1] \:\:\: F_X(x) = \mathbb{P}\{X \leq x\}$$
- F non decrescente
- F continua a destra
- Valgono $\lim_{x\to -\infty} F(x) = 0$ e $\lim_{x\to +\infty} F(x) = 1$

**$\beta$-quantile**
Assegnata una V.A. ad un numero $\beta$ si chiama $\beta$-quantile un numero reale $r$ tale che si ha $$\mathbb{P}(X \leq r) \geq \beta \:\:\:e\:\:\:\mathbb{P}(X \geq r) \geq 1 - \beta$$
