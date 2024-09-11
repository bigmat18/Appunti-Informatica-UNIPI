### V.A. multipla discreta
$$\mathbb{P}_{X,Y}(A) = \mathbb{P}(X,Y \in A) = \sum_{x_i, y_i\in A}p(x_i, y_i)$$
### Indipendenza V.A. multipla
$$\mathbb{P}\{X \in A, Y \in A\} = \mathbb{P}\{X \in A\} \cdot \{Y \in B\}$$
Se le variabili hanno valore atteso e sono indipendenti allora il valore atteso ha la forma.
$$E[XY] = E[X] \cdot E[Y]$$
### Densità di gamma
**Funzione di gamma di Eulero**
$$\Gamma(r) = \int_0^{+\infty}x^{r-1}e^{-x}dx$$
**Densità di gamma**
$$f(x) = \begin{cases}
\frac{1}{\Gamma(t)} \lambda^r x^{r-1} e^{-\lambda x} & x >0\\
0 & x \leq 0
\end{cases}$$
### Densità Chi-quadro
Variabile Gaussiana standard definita con densità $$N\bigg(\frac{n}{2}, \frac{1}{2}\bigg)$$
### Densità di student
$$T_n = \frac{X}{\sqrt{\frac{C_n}{n}}} = \sqrt{n}\frac{X}{\sqrt{C_n}}$$
ha densità
$$f_{T(n)}(t) = \frac{\Gamma(n/2 + 1/2)}{\sqrt{n\pi}\Gamma(n/2)}\bigg(1 + \frac{t^2}{n}\bigg)^{-n/2-1/2}$$
detta densità di Student a n gradi di libertà.
- La densità è una funzione pari

### Teorema centrale del limite
$$\frac{X_1 + \dots + X_n - n\mu}{\sigma \sqrt{n}} = \sqrt{n}\frac{\overline{X}_n - \mu}{\sigma}$$
Con n grande è approssimativamente la gaussiana standard.

**Versione per binomiale**
$$\mathbb{P}(X \leq t) = \bigg(\frac{\overline{X} - np}{\sqrt{np(1-p)}} \leq \frac{t - np}{\sqrt{np(1-p)}}\bigg) \simeq \phi\bigg(\frac{t-np}{\sqrt{np(1-p)}}\bigg)$$
$$\mathbb{P}(X \geq t) = 1 - \phi\bigg(\frac{t-np}{\sqrt{np(1-p)}}\bigg)$$
