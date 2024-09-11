##### Thread
Un flusso di lavoro all'interno di un processo, condividono stesso spazio indirizzi e sono meno costosi nel context switch e nella comunicazione.

### Implements Runnable
```java
public class MyClass implements Runnable { 
	public void run() {
		System.out.println("MyRunnable running");
		System.out.println("MyRunnable finished"); 
	}
}

public static void main(String [] args) {  
	Thread thread = new Thread (new MyClass()); thread.start();  
}

```
- appartiene al package ```java.language```
- contiene solo la segnature di ```void run()``` 
- un istanza di Runnable è una **task**

### Extends Thread
```java
public class ExtendingThread {

	public static class MyThread extends Thread { 
		public void run() {
			System.out.println("MyThread running");
			System.out.println("MyThread finished"); 
		}
	}

	public static void main (String [] args) {
		MyThread myThread = new MyThread(); 
		myThread.start();
	}
}
```
- Quando invocato ```start()``` si invoca ```run()``` che può essere ridefinito con overriding
- Viene memorizzato un riferimento all'oggetto Runnable, eventualmente passato come parametro.

Metodo ```run()``` default definito come segue:
```java
public void run() {
	if(runnable != null) 
		runnagle.run()
}
```

### Threadpool
Si usa per evitare l'overhead di attivare e disattivare thread, cosa che in caso di gran numero di task può rallentare sensibilmente un programma.

Permette di riutilizzare gli stessi thread per più task, si riduce il costo di attivazione/terminazione dei threads.

```java
public interface Executor {
	public void execute(Runnable task) 
}

public interface ExectuorService extends Executor { ... }
```
- ```Executors``` è una classe che opera come [[Factory]] in grado di generare oggetti di tipo ```ExecutorService``` 
- Le tasks devono essere incapsulate in oggetti di tipo ```Runnable``` e passati con invocazione del metodo ```execute()```
##### FixedThreadPool
```java
public class ExampleFixed{

	public static void main(String[] args) {  
		// create the pool  
		ExecutorService service = Executors.newFixedThreadPool(10);
		
		//submit the task for execution  
		for (int i =0; i<100; i++) {
			service.execute(new Task(i)) 
		}
		System.out.println("Thread Name:" + 
							Thread.currentThread().getName()); 
	}
}
```
- Creazione con un numero fisso di n threads.
- Utilizza una **LinkedBlockingQueue** (coda illimitata)

##### CachedThreadPool
```java

public class ExampleCached{
	public static void main(String[] args) {  
		ExecutorService service = Executors.newCachedThreadPool(); 
		for (int i =0; i<100; i++) {
			service.execute(new Task(i)); sleep(1000); 
		} System.out.println("ThreadName:"+Thread.currentThread().getName());

}  
private static void sleep(long timeMillis) {

try { Thread.sleep(timeMillis);

} catch(InterruptedException e) {}}}
```
- se tutti i thread sono occupati viene creato un altro thread, non c'è limite alla dimensione del pool
- se un thread rimane inutilizzato per 60 secondi la esecuzione termina

##### ScheduledThreadPool
Si distanza l'esecuzione dei task con un certo delay.

##### SingleThreadExecutor
Un singolo thread, ed è equivalente ad invocare un FixedThreadPool di dimensione 1. 

Si utilizza quando si vuole essere sicuri che i thread vengano eseguiti nell'ordine con cui si trovano in coda utilizzando lo stesso thread

##### ThreadPoolExecutor
Costruttore generale che consente la personalizzazione della politica di gestione del pool.
```java
public class ThreadPoolExecutor implements ExecutorService {
	public ThreadPoolExecutor (int CorePoolSize,
							   int MaximumPoolSize,  
							   long keepAliveTime,  
							   TimeUnit unit,  
							   BlockingQueue <Runnable> workqueue
							   RejectedExecutionHandler handler)
}
```
- **workqueue** è una struttura dati necessaria per memorizzare gli eventuali tasks in attesa di esecuzione.
- **CorePoolSize** minimo numero di thread attivi. Non si scende mai sotto tranne con ```allowCoreThreadTimeOut(boolean value)``` invocato con parametro a true.
- **MaximumPoolSize** massimo numero di thread che si possono attivare
- **KeepAliveTime** per i thread aggiunti extra a quelli del core questo è il tempo massimo che possono rimanere attivi senza tasks.

### BockingQueue
Rappresenta una coda ma
- pensata per essere utilizzata con mutithread
- permettono **sincronizzazione fra thread** che inseriscono e quelli che eliminano gli elementi della coda.

##### ArrayBlockingQueue
- Dimensione liminata in base all'inizializzazione.
- Utilizza all'interno un array
- Non permette inserzioni/rimozioni in parallelo
- Una solo lock per tutta la struttura

##### LinkedBlockingQueue
- Sia limitata che illimitata
- Usa una linked list quindi maggior occupazione di memoria ed un nuovo oggetto per ogni inserzione.
- Possibili inserzioni ed estrazioni concorrenti. (lock separati per lettura e scrittura)