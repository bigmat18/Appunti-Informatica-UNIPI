- **Distribuito**: ogni nodo aggiorna i suoi vicini solo quando il proprio DV cambia, i vicini avvisano i rispettivi vicini dei cambiamenti
- **Iterativo**: si ripetono operazioni
- **Asincrono**: non richiede che tutti i nodi operino al passo con gli altri
###### Equazione Bellman-Ford
Formula per trovare il percorso a costo minimo tra un nodo sorgente ed uno destinatario
$$d_{xy} = min_v \{c(x,v) + d_{vy}\}$$
###### Informazione mantenute da un nodo
- Conoscere il costo del collegamento verso ciascun vicino $c(x,v)$
- Vettore distanza $D_x = [D_{xy}\::\: \forall y \in N]$ 
- Vettore distanza dei vicini $D_x = [D_{xy}\::\: \forall y \in N] \:\:\forall$ vicino 

###### Algoritmo
1. Ciascuno nodo x inizia con una stima delle distanze verso tutti i nodi in N
2. Ogni nodo invia una copia del proprio vettore distanza a ciascuno dei suoi vicini
3. Quando un nodo x riceve un nuovo DV (vettore distanza) lo salva e usa l'equazione di Bellman-form per aggiornare il proprio vettore distanza.
4. Si ripete finché tutti i nodi continuano a cambiare i propri DV in maniera asincrona ciascuna stima dei costi $D_{xy}$ converge all'effettivo costo del percorso minimo.
5. Se cambia il costo del collegamento il nodo lo rileva e ricalcola il vettore distanza

###### Split-horizon con Poisoned revese
Se nodo X inoltra a V i pacchetti destinati a Z allora X invia a V $D_X[Z] = \infty$. Questo è detto **Count to infinity problem**