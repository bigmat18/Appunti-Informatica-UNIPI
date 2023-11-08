public class Tutor {
    private boolean[] buffer;
    private static final int BUFFER_SIZE = 20;
    private int waitProf;
    private int waitThesis;
    private int freeBuffer;

    Tutor() {
        this.buffer = new boolean[BUFFER_SIZE];
        for(int i = 0; i < buffer.length; i++) this.buffer[i] = false;

        this.waitProf = 0;
        this.waitThesis = 0;
        this.freeBuffer = BUFFER_SIZE;
    }

    public synchronized void professorConsumeBuffer() {
        while(this.freeBuffer != 20) {
            this.waitProf++;
            try { wait(); }
            catch (InterruptedException e) {}
        }
        this.waitProf--;
        for(int i = 0; i < BUFFER_SIZE; i++){
            this.buffer[i] = true;
            this.freeBuffer--;
        }
    }

    public synchronized void thesisConsumeBuffer(int pos) {
        while(this.waitProf > 0 || this.buffer[pos]){
            this.waitThesis++;
            try { wait(); }
            catch (InterruptedException e) {}
        }
        this.waitThesis--;
        this.buffer[pos] = true;
        this.freeBuffer--;
        notifyAll();
    }

    public synchronized int studentConsumeBuffer() {
        while(this.waitProf > 0 || this.waitThesis > 0 || this.freeBuffer == 0) {
            try { wait(); }
            catch (InterruptedException e) {}
        }
        for(int i = 0; i < BUFFER_SIZE; i++) {
            if(!this.buffer[i]) {
                this.buffer[i] = true;
                this.freeBuffer--;
                return i;
            }
        }
        notifyAll();
        return -1;
    }

    public synchronized void releaseAllBuffer() {
        for(int i = 0; i < BUFFER_SIZE; i++){
            this.releaseOneBuffer(i);
        }
    }

    public synchronized void releaseOneBuffer(int pos){
        while (!this.buffer[pos]) {
            try { wait(); }
            catch (InterruptedException e) {}
        }
        this.buffer[pos] = false;
        this.freeBuffer++;
        notifyAll();
    }
}
