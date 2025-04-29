public  class SharedPrinter {
    synchronized void printWords() {
        String[] words = {"i", "love", "java", "very", "much"};
        for (String word : words) {
            System.out.println(word);
            try {
                Thread.sleep(300); // Pause for visibility
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class MyThread extends Thread {
    SharedPrinter printer;

    MyThread(SharedPrinter printer) {
        this.printer = printer;
    }

    public void run() {
        printer.printWords();
    }
}

public class prog20 {
    public static void main(String[] args) {
        SharedPrinter printer = new SharedPrinter();

        MyThread t1 = new MyThread(printer);
        MyThread t2 = new MyThread(printer);

        t1.start();
        t2.start();
    }
}
{
}
