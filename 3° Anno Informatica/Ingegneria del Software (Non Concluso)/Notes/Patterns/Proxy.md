**Modello statico**
![[Screenshot 2023-11-28 at 14.49.39.png | 500]]

**Modello dinamico**
![[Screenshot 2023-11-28 at 14.49.59.png | 500]]

**Osservazioni**
Il proxy fornisce un surrogato (o segnaposto) per un altro oggetto, per controllarne l'accesso. È simile ad un adapter in quanto di introduce un intermediario. Sono però anche due patter diversi perché:
1. Il proxy e oggetto originale hanno la stessa interfaccia, Adapter e Adaptee no.
2. Il proxy può eseguire pre e post elaborazioni.

Ci sono vari usi/tipi di proxy:
- **Remote proxy**: Il proxy permette l'accesso ad un oggetti remoto. Usato per esempio in RMI e in Corba.
- **Protection proxy**: Il proxy implementa un controllo sugli accessi.
- **Cache proxy**: Il proxy mantiene coppie richiesta-risposta sgravando il server.
- **Synchronization Proxy**: Gestisce gli accesi concorrenti ad un servizio.
- **Virtual proxy**: Il proxy si comporta come l'originale mentre l'originale viene costruito, ppi passa le richieste a quest'ultimo.

**Case study**. Gamball machine example.
Vogliamo aggiungere dei monitor ad una collection di Gumball machines.

### Remote Proxy
Con il remote proxy, il proxy come una rappresentazione locale per un oggetto che vive in una differentet JVM. Il risultato di una chiamata di un metodo sul proxy viene trasferita nella rete verso colui che l'ha invocata in remote. Il risultato va al proxy e poi al client.
![[Screenshot 2023-11-28 at 17.08.05.png]]

**Gumball class**
```java 
public class GumballMachine {
	//other instance variables
	String location;
	public GumballMachine(String location, int count){
		//other constructo code here
		this.location = location;
	}
	public String getLocation() {
		return location;
	}
}
```

**Ruolo del proxy remoto**
![[Screenshot 2023-11-28 at 17.15.32.png]]

**Come le chiamate dei metodi avvengono**
1. L'oggetto client chiama doBigThing() sul client helper object.
![[Screenshot 2023-11-28 at 17.17.17.png]]
2. Il client helper impacchetta le informazioni riguardante la chiamata (argomenti, nome chiamata, etc.) e li spedisce sul network verso il service helper.
![[Screenshot 2023-11-28 at 17.19.29.png]]
3. Il service helper spacchetta le infomrazioni inviategli dal client helper, cerca quale metodo è stato chiamata (e su quale oggetto) e invoca il vero metodo sul vero oggetto.
![[Screenshot 2023-11-28 at 17.20.51.png]]
4. Il metodo è invocato sull'oggetto del servizio il quale ritorna qualche risultato al service helper.
![[Screenshot 2023-11-28 at 17.26.53.png]]
5. Il Service helper impacchetta le informazioni ritornate dalla chiamate e le invia sulla rete al client helper.
![[Screenshot 2023-11-28 at 17.27.47.png]]
6. Il client helper spacchetta il valore di ritorno e lo ritorna al client object. Dal punto di vista del client object questo è tutto trasparente.
![[Screenshot 2023-11-28 at 17.29.02.png]]

**Remote proxy con RMI**
Il client helper è anche chiamato stub, mentre il server helper è chiamato skeleton.

![[Screenshot 2023-11-28 at 17.30.42.png]]

Ora andiamo attraverso tutti gli steps che sono necessari per un oggetto dentro un servizio per poter accettare chiamate remote ed inoltre gli steps necessari per consentire al client di fare chiamate remote.

**Collegamenti di oggetti client al server**
![[Screenshot 2023-11-28 at 17.33.32.png]]

**Esempio**. Gumball machines.
1. Il CEO fa partire il monitor, che per prima arriva ai proxy delle gumball machines e poi chiama getState() per ognuno.
![[Screenshot 2023-11-28 at 17.49.55.png]]
2. getState() è chiamata dal proxy che inoltra la chiamata al servizio remoto. Lo skeleton riceve la richiesta e la inoltra alla gumball machine.
![[Screenshot 2023-11-28 at 17.57.18.png]]
4. La gumball machine ritornano lo stato allo skeleton, il quale le serializza e le trasforma rispedendole indietro lungo il filo verso il proxy. Il proxy deserializza e ritorna esso come un oggetto al monitor.
![[Screenshot 2023-11-28 at 17.56.59.png]]

### Virtual proxy
Lo scopo del virtual proxy è rappresentare un oggetto che potrebbe essere costoso da creare. Il virtual proxy differisce la creazione di uno oggetto prima che sia necessaria; the virtual proxy ha inoltre lo scopo di surrogato per l'oggeto prima e mentre esso viene creato. Dopo questo, il proxy delega la richiesta direttamente al RealSubject.

![[Screenshot 2023-11-28 at 18.03.57.png]]

**Esempio**. CD cover.
![[Screenshot 2023-11-28 at 18.04.15.png]]

Il processo per un ImageProxy è:
1. ImageProxy prima creare una ImageIcon ed inizia a caricare essa dal network URL.
2. Mentre i bytes dell'immagine vengono presi, l'imageproxy mostr "loading CD cover please wait...".
3. Quando l'immagine è completamente caricate, ImageProxy delega tutte le chiamate dei metodi all'image icon, inclusa paintIcon(), getWidth() e getHeight().
4. Se l'utente richiede una nuova immagine, creeremo un nuovo proxy e si inizierà il processo nuovamente.

```java
class ImageProxy implements Icon { 
	ImageIcon imageIcon; 
	URL imageURL; 
	Thread retrievalThread; 
	boolean retrieving = false; 
	
	public ImageProxy(URL url) { imageURL = url; } 
	
	public int getIconWidth() { 
		if (imageIcon != null) 
			return imageIcon.getIconWidth(); 
		else 
			return 800; 
	} 
	
	public int getIconHeight() { 
		if (imageIcon != null) 
			return imageIcon.getIconHeight(); 
		else 
			return 600;
	} 
	
	public void paintIcon(final Component c, Graphics g, int x, int y)  {
		if (imageIcon != null) 
			imageIcon.paintIcon(c, g, x, y);
		else {g.drawString("Loading CD cover, please wait...", x+300, y+190);
			if (!retrieving) { 
				retrieving = true; 
				retrievalThread = new Thread(new Runnable() { 
					public void run() { 
						try { 
							imageIcon = new ImageIcon(imageURL, "CD Cover");
							c.repaint(); } 
						catch (Exception e) { 
							e.printStackTrace();
						}
					}
				});
```

**java.lang.reflect package** può essere usato per creare proxy class dinamicamente
![[Screenshot 2023-11-28 at 18.09.49.png]]

# Introduzione alla verifica e validazione
Nel 1937 Alan turing ha dimostrato che alcuni problemi non possono essere risolti da un algoritmo (programma). Tali problemi sono quelli che coinvolgono il problema della terminazione.

*Definizione* (**Problema terminazione**): esiste un algoritmo/programma che presi in ingresso un qualsiasi altro programma e un input, stabilisce se il programma su tale input termina o no?

Si assuma che esista un programma C che prende in input un programma (a) ed un input per a che chimaimo b.
```c
bool C(a,b) {return halts(a(d));}
```
dato che un programma è a sua volta una sequenza di caratteri, si può invocare C(a,a).
Si può quindi definire K(a) come segue:
```c
bool K(a) {
	if (C(a,a)) while(true) skip;
	else return false;
}
```
A questo punto possiamo dire che:
Il programma K con input K termina (restituendo false), se e solo se C(K,K) è falso, ma C(K,K) è falso solo se halts(K(K)) è falso, va a dire se il programma K con input K non termina. K(K) termina se e solo se K(K) non termina => paradosso => Non può esistere il programma C.

In particolare,dobbiamo concludere che non esiste un programma P che per ogni programma Q e input D, dice se ilprogramma Q sull’input D termina o no (**Halting Problem**).
```c
while (x>0) 
	x = x + 1;
y = 27;
```
Purtroppo non è solo un risultato teorico: quasi tutte le proprietà interessanti dei programmi incorporano l’halting problem.

**Indecidibilità**
Esistono programmi che è possibile dimostrare corretti in tempo finito.
```java
public void printHW() {
	System.out.println("Hello, World");
}
```
Ne esistono altri per cui non è possibile. Quindi non esiste alcun programma P che prende in input altri programmi e per ognuno di questi decide in tempo finto se è corretto o meno.

**Esempio**. È indecidibile dire con un algoritmo generale se un generico programma C vada in ciclo infinito su un generico input.
```java
public void printC(myHome Home){
	Calzini calzini = myhome.calzini;
	while (!appaiati(calzini))
		calzini = appaia(calzini);
	System.out.println("Hello, world");
}
```

Per risolvere questo problema possiamo usare per esempio le **Triple di Hoare**.
Dove si nasconde il problema? La logica al primo ordine è indecidibile. In altre parole: Esiste un algoritmo che, per ogni formula $F$ in logica al primo ordine, mi permetta di decidere in tempo finito se $F$ è valida o meno? se cioè $\vDash F$ oppure $\nvDash F$? 

No, non esiste. Si possono enumerare (scrivere una dopo l’altra) tutte le formule valide, ma in tempo finito posso non arrivare a scrivere né $F$ né $\lnot F$.

**Concetti e terminologia** 
Visualizzare il "quadro generale" della qualità del software nel contesto di un progetto di sviluppo software e organizzazione: 
- attività di verifica e di validazione (V&V: verification and validation) del software. 
- La selezione e la combinazione di attività di V&V all'interno di un processo di sviluppo software.

Il sw ha alcune caratteristiche che rendono V&V particolarmente difficile.
- requisiti di qualità diversi 
- il sw è sempre in evoluzione 
- distribuzione irregolare dei guasti 
- non linearità, esempio: 
	- Se un ascensore può trasportare un carico di 1000 kg, può anchetrasportare qualsiasi carico minore. 
	- Se una procedura ordina correttamente un set di 256 elementi, potrebbe non riuscire su un set di 255 o 53 o 12 elementi, non ché su 257 o 1023.

**Dipendenze dai linguaggi**
Nuovi approcci di sviluppo possono introdurre nuovi tipi di errori. Per esempio:
- Deadlock o race conditions per il software distribuito.
- Problemi dovuti al polimorfismo o al binding dinamico nel software object-oriented.
