import java.util.Scanner;

class CounterThread extends Thread {
    private int lowerRange, upperRange;

    public CounterThread(String name, int lowerRange, int upperRange) {
        super(name);
        this.lowerRange = lowerRange;
        this.upperRange = upperRange;
    }

    public void run() {
        System.out.println("Thread - " + getName());
        try {
            for (int i = lowerRange; i <= upperRange; i++) {
                System.out.print(i + "\t");
                Thread.sleep(5); // Pausing the thread for 5 milliseconds
            }
            System.out.println();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Program1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the name of the thread: ");
        String threadName = scanner.nextLine();

        System.out.print("Enter the lower range of the counter: ");
        int lowerRange = scanner.nextInt();

        System.out.print("Enter the upper range of the counter: ");
        int upperRange = scanner.nextInt();

        CounterThread thread = new CounterThread(threadName, lowerRange, upperRange);
        thread.start();

        scanner.close();
    }
}