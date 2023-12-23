public class User implements Runnable {

    public enum TypeUser {
        STUDENT,
        PROFESSOR,
        THESIS
    }

    private Tutor tutor;
    private TypeUser type;
    private int pos;
    private final int ID;
    private int k;

    User(Tutor tutor, TypeUser type, int pos, int ID, int k) {
        this.tutor = tutor;
        this.type = type;
        this.pos = pos;
        this.ID = ID;
        this.k = k;
    }

    public void run() {
        if(type == TypeUser.PROFESSOR) {
            for(int i = 0; i < this.k; i++) {
                this.tutor.professorConsumeBuffer();
                System.out.println("Professor " + this.ID + " gets computers");

                try { Thread.sleep(1000); }
                catch(InterruptedException e) {}

                this.tutor.releaseAllBuffer();
                System.out.println("Professor " + this.ID + " release computers");
            }
        }

        else if(type == TypeUser.THESIS) {

            for(int i = 0; i < this.k; i++) {
                this.tutor.thesisConsumeBuffer(pos);
                System.out.println("Thesis " + this.ID + " gets computer " + pos);

                try { Thread.sleep(1000); }
                catch(InterruptedException e) {}

                this.tutor.releaseOneBuffer(pos);
                System.out.println("Thesis " + this.ID + " release computer " + pos);
            }
        }  

        else if(type == TypeUser.STUDENT) {
            
            for(int i = 0; i < this.k; i++) {
                int pos = this.tutor.studentConsumeBuffer();
                System.out.println("Student " + this.ID + " gets computer" + pos);

                try { Thread.sleep(1000); }
                catch(InterruptedException e) {}

                this.tutor.releaseOneBuffer(pos);
                System.out.println("Student " + this.ID + " release computer" + pos);
            }
        }
    }
}
