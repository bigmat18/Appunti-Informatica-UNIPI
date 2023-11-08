import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        if(args.length < 3) {
            System.out.println("Insert numProf, numThesis, numStudent");
            return;
        }
        ArrayList<Thread> users = new ArrayList<Thread>();
        Tutor tutor = new Tutor();
        for(int i = 0; i < Integer.parseInt(args[0]); i++) {
            User user = new User(tutor, User.TypeUser.PROFESSOR, -1, i, (int)(Math.random() * 5 + 1));
            Thread thread = new Thread(user);
            thread.start();
            users.add(thread);
        }

        for(int i = 0; i < Integer.parseInt(args[0]); i++) {
            User user = new User(tutor, User.TypeUser.THESIS, (int)(Math.random() * 20 + 1), i+100, (int)(Math.random() * 5 + 1));
            Thread thread = new Thread(user);
            thread.start();
            users.add(thread);
        }

        for(int i = 0; i < Integer.parseInt(args[0]); i++) {
            User user = new User(tutor, User.TypeUser.STUDENT, -1, i+1000, (int)(Math.random() * 5 + 1));
            Thread thread = new Thread(user);
            thread.start();
            users.add(thread);
        }

        for(int i = 0; i < users.size(); i++){
            try { users.get(i).join(); }
            catch(Exception e) {};
        }
    }
}
