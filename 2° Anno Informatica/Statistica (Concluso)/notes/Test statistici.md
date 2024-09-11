### p-value
Il p-value sintetizza in un solo numero la plausibilità di un affermazione. Quindi ci può dire se l'ipotesi $H_0$ è plausibile. 
La probabilità di esiti di coda della statistica su cui il test si basa, sotto l'ipotesi nulla
### Z-test
**Formulazione del test**
$$C = \bigg\{\sqrt{n}\frac{|\overline{X}_n - m_0|}{\sigma}> q_{1 - \alpha/2}\bigg\}$$
- $\overline{X}$ media campionaria
- $m_0$ media attesa della popolazione sotto ipotesi nulla
- $\sigma$ deviazione standard
- $n$ dimensione campione

**Calcolo del p-value**
$$\overline{\alpha} = 2 \bigg[1 - \phi\bigg(\frac{\sqrt{n}}{\sigma}|\overline{x}_n - m_0|\bigg)\bigg]$$
Si usa con deviazione standard conosciuta e con campione sufficientemente grande ($n \geq 30$).
### Test su Bernoulli
**Formulazione del test**
$$C = \bigg\{\frac{\sqrt{n}|\overline{X}_n - p_0|}{\sqrt{p_0(1 - p_0)}} >q_{1 - \alpha/2}\bigg\}$$
**Calcolo p-value**
$$p_0 = 2\bigg[1 - \phi\bigg(\frac{\sqrt{n}|\overline{x} - p_0|}{\sqrt{p_0(1 - p_0)}}\bigg)\bigg]$$
Si usa con n variabili di Bernoulli quando vogliamo formulare un test relativo al paramentro p. Siamo sempre con n grandi.
### T-test di student
**Formulazione del test**
$$C = \bigg\{\sqrt{n}\frac{|\overline{X}_n - m_0|}{S_n}> \tau_{1-\alpha,n-1}\bigg\}$$
- $\overline{X}$ media campionaria
- $S_n^2 = \frac{1}{n-1}\sum_{i=1}^n (X_i - \overline{X}_n)^2$ deviazione standard del campione
- $m_0$ la media di riferimento

Si usa quando le dimensioni del campione sono relativamente piccole ($< 30$) e la deviazione standard della popolazione non è nota.
SI usa anche per determinare se esiste una differenza significativa tra le medie di due gruppi di riferimento.

**Calcolo p-value**
$$\overline{\alpha}(x_1, \dots, x_n) = 1 - F_{n-1}\bigg(\frac{\sqrt{n}}{s}(\overline{x}_n - m_0)\bigg)$$
### Test di person o chi-quadro
**Formulazione del test**
$$C_{\alpha} = \{T_n > \chi^2_{r-1, 1-\alpha}\}$$
Con: $$T_n = \sum_{j=1}^r\frac{(O_{n,j} - np_j)^2}{np_j}$$
in vui la v.a. $$O_{n,j} = \sum^n_{i=1}1_{X_i = j} = \#\{i \::\:X_i = x_j\}$$
detta **effettivo empirico** indica il numero di osservazioni $X_i$ che hanno dato valore $j$.