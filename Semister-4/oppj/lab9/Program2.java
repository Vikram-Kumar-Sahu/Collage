class SharedResource {
    public synchronized void display(String message) {
        System.out.print("[");
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(message + "]");
    }
}

class SyncThread extends Thread {
    private SharedResource resource;
    private String message;

    public SyncThread(SharedResource resource, String message) {
        this.resource = resource;
        this.message = message;
    }

    public void run() {
        resource.display(message);
    }
}

public class Program2 {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        SyncThread t1 = new SyncThread(resource, " Thread 1");
        SyncThread t2 = new SyncThread(resource, " Thread 2");

        t1.start();
        t2.start();
    }
}