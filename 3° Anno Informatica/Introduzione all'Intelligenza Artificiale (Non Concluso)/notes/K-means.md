Algoritmo di apprendimento **Non supervisionato**. Si basa su fare clustering dei dati, ciò raggruppare i dati in K cluster cercando un centro.
 
1. Scegliere k centri di cluster random fra i punti disponibili.
2. Assegna ad ogni punto ad un cluster calcolando la distanza minima. $$i(x) = argmin_i ||x - c_i||^2$$
3. Per ogni cluster si calcola un nuovo centro facendo la media. $$c_i = \frac{1}{cluster_i}\sum_{j\: : \:x_j \in cluster_j}x_j$$
4. Torniamo al punto 2 finché non si converge oppure fino ad un massimo di iterazione

La perdita minima $L(x)$ fa dipendere il metodo dall'inizializzazione randomica. Una soluzione è inizializzare usando un euristica.