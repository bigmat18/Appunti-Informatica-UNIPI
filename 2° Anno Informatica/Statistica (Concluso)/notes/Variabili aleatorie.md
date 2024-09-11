**Variabile Binomiale o Bernoulli**
$$\mathbb{P}(X = h) = \binom{n}{h}p^h (1 - p)^{n-h} \:\:\:\:\:\: 0\leq h \leq n$$
Caso di n prove di un esperimento che ha solo 2 casi ed uno di questi si chiama successo.

**Variabile geometrica**
$$\mathbb{P}(X = h) = (1-p)^{h-1}p \:\:\:\: h \in \mathbb{N}_0$$
Caso di un esperimento con 2 esiti che si esegue finché non ha successo.

**Variabile di poisson**
$$\mathbb{P}(X =h) e^{-\lambda} \frac{\lambda^h}{h!} \:\:\:\: h \in \mathbb{N}$$
Date n prove ripetute, essa conta il numero di successi. Con n grandi il numero si successi diminuisce.

**Variabili uniformi su intervalli**
$$f(x) = \begin{cases}\frac{1}{b-a} & a < x < b\\0 & altrove\end{cases}$$
**Variabili esponenziali**
$$f(x) = \begin{cases}\lambda e^{-\lambda x} & x > 0 \\ 0 & x \leq 0\end{cases}$$
Descrive ad esempio il tempo di attesa tra due eventi aleatori come per ess. due chiamate ad un call center.
Densità di probabilità
$$\int_0^{+\infty}\lambda e^{-\lambda x}dx = -[e^{\lambda x}]_0^{+\infty} = 1$$
**Variabile Gaussiana**
Variabile aleatorie di tipo STANDARD
$$\varphi(x) = \frac{1}{\sqrt{2\pi}}e^{-x^2/2} \:\:\:\:\: N(0,1)$$
Densità è una funzione pari quindi $$\phi(-x) = 1 - \phi(x)$$
Variabile aleatoria di tipo NON STANDARD
$$f_Y(t) = \frac{1}{\sqrt{2\pi \sigma}}e^{-\frac{(t-m)^2}{2\sigma^2}} \:\:\:\:\: N(m, \sigma^2)$$

Le variabili aleatorie gaussiane si usano nei casi in cui abbiamo n prove che forniscono risultati continui che hanno una distribuzione normale.
### Misurazioni su V.A.
**Cambio di variabile**
$$f_{Y}(y) = \begin{cases}
f_X(h^{-1}(y))\cdot \bigg|\frac{dh^{-1}(y)}{dy}\bigg|&y\in B\\
0 & y\notin B
\end{cases}$$

**Valore atteso o momento primo**
$$\mathbb{E}[X] = \sum_i x_i p(x_i)$$
Con densità
$$\mathbb{E}[X] = \int_{-\infty}^{+\infty}xf(x)dx$$
**Varianza o scarto quadratico medio**
$$Var(X) = \mathbb{E}[(X - \mathbb{E}[X]^2)]$$
**Momento di ordine n**
$$Se \:\:\:\mathbb{E}[|X|^n] < +\infty \Rightarrow E[X^n]$$
