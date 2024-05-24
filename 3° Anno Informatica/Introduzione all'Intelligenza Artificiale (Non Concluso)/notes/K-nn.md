Si basa sul salvare $<x_p, y_p> \:\: p = 1, \dots, l$ successivamente dato un $x$ trovare $i$ che minimizzi la distanza
$$i(x) = argmin \:d(x, x_p) \:\:\:\:\: d(x, x_p) = ||x - x_p||$$
In sintesi viene dato al nuovo valore x l'output del valore più vicino (caso 1-NN).

Si generalizza cambiano il valore di k
$$avg_k(x) = \frac{1}{k}\sum_{x_i \in N_k (x)}y_i$$
$$h(x) = \begin{cases}1 & avg_k(x) > 0.5 \\ 0 & altrimenti\end{cases}$$
Questa versione generalizzata prende i $k$ punti più vicini e fa la media, se il valore è maggiore di 0.5 allora 1 sennò 0.

- **Limite di spazio** = dobbiamo mantenere salvato tutto il training set.
- **Limite computazionale** = per ogni nuovo x bisogna valutare tutto il training set.