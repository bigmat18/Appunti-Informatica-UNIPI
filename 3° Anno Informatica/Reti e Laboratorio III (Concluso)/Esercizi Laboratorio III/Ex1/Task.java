package Ex1;

public class Task implements Runnable {
    long num;

    public Task(long num) { this.num = num; }

    public void run() {
        long num = 0;
        long primes = 0;

        for (long i = 1; i <= this.num; i++) {
            long counter = 0;
            for (num = i; num >= 1; num--) {
                if (i % num == 0)
                    counter = counter + 1;
            }
            if (counter == 2) primes += 1;
        }
        System.out.println("Ci sono " + primes);
    }
}
