import java.util.Scanner;

class HrsException extends Exception {
    public HrsException(String message) {
        super(message);
    }
}

class MinException extends Exception {
    public MinException(String message) {
        super(message);
    }
}

class SecException extends Exception {
    public SecException(String message) {
        super(message);
    }
}

class Time {
    int hours;
    int minutes;
    int seconds;

    public void setTime() throws HrsException, MinException, SecException {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter hours: ");
        hours = sc.nextInt();
        if (hours > 24 || hours < 0) {
            throw new HrsException("hour is not greater than 24 or less than 0");
        }

        System.out.print("Enter minutes: ");
        minutes = sc.nextInt();
        if (minutes > 60 || minutes < 0) {
            throw new MinException("minute is not greater than 60 or less than 0");
        }

        System.out.print("Enter seconds: ");
        seconds = sc.nextInt();
        if (seconds > 60 || seconds < 0) {
            throw new SecException("second is not greater than 60 or less than 0");
        }
    }

    public void displayTime() {
        System.out.println("Correct Time -> " + hours + ":" + minutes + ":" + seconds);
    }
}

public class l3 {
    public static void main(String[] args) {
        Time time = new Time();
        try {
            time.setTime();
            time.displayTime();
        } catch (HrsException | MinException | SecException e) {
            System.out.println("Caught the exception");
            System.out.println("Exception occurred: " + e);
        }
    }
}