## Protocolli a rotazione
#### Polling
Il nodo master invita i nodi slave a trasmettere a rotazione, questo porta ad un polling overhead, latenza e single point of failure

#### Token passing
**Token** passato da nodo a nodo, questo causa token overhead, latenza, single point of failure (token)