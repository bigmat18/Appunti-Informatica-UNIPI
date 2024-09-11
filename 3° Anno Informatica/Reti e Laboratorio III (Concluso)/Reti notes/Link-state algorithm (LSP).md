- **Globale**: la topologia della rete e i costi dei collegamenti sono noti a tutti
- **Iterativo**: dopo la k-esima iterazione i cammini a costo minimo verso k nodi di destinazione sono noti
- Crea una **tabella di inoltro** per un nodo
- Ogni router invia degli LS packet a ciascun nodo che contiene le informazioni sui nodi a cui è collegato con i relativi costi (richiede con n nodi e E collegamenti l'invio di O(nE) messaggi)

###### Notazione
- **c(x,y)**: costo dei collegamenti dal nodo x al nodo y
- **D(v)**: costo del cammino dal nodo origine alla destinazione v per iterazione corrente
- **p(v)**: immediato predecessore di v lungo cammino
- **N'**: sottoinsieme di nodi per cui il cammino a costo minimo dall'origine 
###### Dijsktra’s algorithm

```
Inizializzazione del nodo u:
N' = {u}
for all nodi v
	if v adiacente a u
		D(v) = c(u,v)
	else D(v) = infinito

while finchè tutti i nodi sono in N'
	trova w non in N' t.c. D(w) sia minimo
	aggiungi w a N'
	for all v adiacenti a w e non in N':
		D(v) = min(D(v), D(w) + C(w,v))
```
