package Ex1;
/*
 * Scrivere una applicazione JAVA che:
 * - crea e attiva n thread
 * - ogni thread esegue esattamente lo stesso task, ovvero conta il numero di interi minori di 10,000,000 che sono primi
 * - il numero di thread che devono essere attivati e mandati in esecuzione viene richiesto all’utente, che lo inserisce tramite la CLI (Command Line Interface)
 Analizzare come varia il tempo di esecuzione dei thread attivati a seconda del loro numero
 Sviluppare quindi un programma in cui si creano n task, tutti eseguono la computazione descritta in precedenza e vengono sottomessi a un threadpool la cui dimensione deve essere inserita da CLI.
*/
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import Ex1.Task;

class Main {
    public static void main (String[] args){
        if(args.length != 2){
            System.out.println("Send num thread");
            return;
        }
        int numThreads = Integer.parseInt(args[1]);
        long prime = 10000000;
        ExecutorService service = Executors.newFixedThreadPool(numThreads);

        for (int i =0; i<numThreads; i++) {
            service.execute(new Task((prime / numThreads) * (i + 1)));
            System.out.println("Thread Name:" + Thread.currentThread().getName());
        } 
    }
}