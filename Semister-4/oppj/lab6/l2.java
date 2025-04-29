interface Motor {
    int capacity = 100; 

    void run(); 
    void consume(); 
}

class WashingMachine implements Motor {
    @Override
    public void run() {
        System.out.println("Washing machine is running.");
    }

    @Override
    public void consume() {
        System.out.println("Washing machine is consuming power.");
    }

    public void displayCapacity() {
        System.out.println("Capacity of the motor is " + capacity);
    }
}

public class l2 {
    public static void main(String[] args) {
        WashingMachine wm = new WashingMachine();
        wm.run();
        wm.consume();
        wm.displayCapacity();
    }
}