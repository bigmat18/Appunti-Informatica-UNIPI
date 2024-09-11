- È un sotto gruppo locale all'interno di una LAN creato dal software anziché da dispositivi fisici.
- Riunisce le stazioni ed i dispositivi di rete in un **unico dominio di broadcast** così facendo gli host al loro interno comunicano tra loro come se fossero connessi tutti allo switch.
- La VLAN è **logica ed è implementata negli switch con il livello MAC**.
- L'obbiettivo finale è consentire al traffico di fluire in modo più efficiente all'interno di popolazioni di interesse e isolare il traffico all'interno della VLAN.
### Port-based VLAN

![[Screenshot 2024-09-04 at 21.43.53.png | 400]]
###### Trafic isolation
I frame da o verso porte 1-8 possono solo essere recuperati nelle porte 1-8.
###### Dynamic membership
Le porte possono essere assegnate dinamicamente fra le VLAN.
###### Forwarding fra le VLANs
Può essere fatto il forwarding fra le VLANs via routing.
###### Trunk port
Sono delle porte che trasportano i frame tra VLAN definite su più switch fisici. Questi frame inoltrati all'interno della VLAN tra switch non possono essere frame di tipo vanilla 802.1 ma **si deve usare il 802.1Q** che aggiunge/rimuove campi di intestazioni aggiuntivi per i frame inoltrati tra le porte trunk

![[Screenshot 2024-09-04 at 21.44.45.png | 400]]
### VLAN frame format - 802.1Q

![[Screenshot 2024-08-28 at 17.49.58.png | 600]]

#### VLAN alternative
- È possibile andare a definire una VLAN andando a specificare gli indirizzi MAC che ne appartengono.
- Si può anche definire una VLAN su un protocollo con per esempio IPv4 o IPv6