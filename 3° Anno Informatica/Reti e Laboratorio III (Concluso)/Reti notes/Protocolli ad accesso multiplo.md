 Algoritmo distribuito che determina come i nodi condividono il canale e determina quando il nodo può trasmettere. La comunicazione per la condivisione del canale deve usare il canale stesso

##### Condizioni ideali
1. Quando un solo nodo trasmette, può inviare dati con un rate R bps
2. Quando M nodi vogliono trasmettere, ciascuno trasmette ad un rate medio R/M
3. Decentralizzato (non ci sono nodi speciali che coordinano la trasmissione)
4. È semplice

##### [[Protocolli a suddivisione del canale]]
Dividono il canale in "pezzi" (risorse) più piccoli che sono allocate al nodo in modo esclusivo.
##### [[Protocolli ad accesso random]]
Il canale è condiviso, quindi possono esserci collisioni ma esistono meccanismi per "recuperare" da eventi di collisione.
##### [[Protocolli a rotazione]]
Si ruota fra i nodi.
