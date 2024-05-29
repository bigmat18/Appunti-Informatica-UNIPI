## Hold out
È un modo con il quale si separano i dati in una serie di sotto-insiemi diversi, per poi essere utilizzati in fasi diverse sul modello.
- **TR** = training set. Usato per addestrare il modello
- **VL** = validation set. Da usare dopo il training, il risultato sarà confrontato fra i vari modelli per scegliere il migliore
- **TS** = test set. Usato per stimare l'errore di generalizzazione e valutare il modello

## K-fold
È un approccio che si utilizza quando abbiamo un insieme di dati limitato che deve essere usato sia per fare validation che training. 
**Convalida incrociata k-fold**:
1. Suddividere il set di dati D in k sottoinsiemi mutualmente esclusivi $D_1, D_2, \dots, D_k$
2. Addestrare l'algoritmo di apprendimento su $D \setminus D_i$  e testarlo su $D_i$ 
3. Riassumere la media di tutti i risultati $D_i$
4. Utilizzare tutti i dati per il training, la validation o test.

![[Screenshot 2024-05-18 at 21.17.20.png | 300]]

## SLT
La **Teoria di apprendimento statistico** è un modo per racchiudere la capacità di generalizzazione rispetto all'errore di training, l'overfitting e underfitting.

Funzione di rischio da minimizzare
$$R = \int L(d, h(x)) \: dP(x, d)$$

Rischio empirico
$$R_{emp} = \frac{1}{l}\sum_{p=1}^l(d_p - h(x_p))^2$$
Possiamo approssimare la funzione di rischio tramite il rischio empirico:
$$R \leq R_{emp} + \epsilon(1/l, VCdim, 1/\delta)$$
Con $VCdim =$ misura di complessità dello spazio di ipotesi, $\epsilon =$ VC-confidence, $l=$ dati di training, $\delta =$ la confidence.
- $\epsilon$ cresce con VC-dim
- $\epsilon$ decresce con $l$ e $\delta$ 
- Modelli troppo semplici (VC-dim bassa) $\Rightarrow$ $\epsilon$ bassa (undefitting)
- Modelli troppo complessi (VC alta) $\Rightarrow$ bassa $R_{emp}$ ma $\epsilon$ cresce (overfitting)

![[Screenshot 2024-05-18 at 21.37.17.png]]
