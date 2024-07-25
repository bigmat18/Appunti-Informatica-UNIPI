**Stimatore corretto del parametro $\Theta$** 
$$\mathbb{E}[g(X_1, \dots, X_n)] = \Theta$$
la $g(X_1, \dots, X_n)$ si dice stimatore corretto.

**Funzione di verosimiglianza**
Variabile discreta $$L(\theta; x_1, \dots, x_n) = \prod_{i=1}^n p_{\theta}(x_i)$$
Variabile con densità $$L(\theta; x_1, \dots, x_n) = \prod_{i=1}^n f_{\theta}(x_i)$$
**Stima di massima verosimiglianza**
$$L(\hat{\theta}; x_1, \dots, x_n) = \max_{\theta \in \Theta} {L(\theta; x_1, \dots, x_n)} \:\:\:\:\:\forall\:\:(x1, \dots, x_n)$$

**Stima col metodo dei momenti**
$$\mathbb{E}_{\hat{\theta}}[X^k] = \frac{1}{n}\sum_{i=1}^n x_i^k \:\:\:\:\:\forall\:(x_1, \dots, x_n)$$
