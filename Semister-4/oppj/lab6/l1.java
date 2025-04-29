import java.util.Scanner;

abstract class Student {
    int rollNo;
    long regNo;

    // Method to get input from the user
    public void getInput() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Roll No: ");
        rollNo = sc.nextInt();
        System.out.print("Enter Registration No: ");
        regNo = sc.nextLong();
    }

    abstract void course();
}

class Kiitian extends Student {
    @Override
    void course() {
        System.out.println("Course: B.Tech. (Computer Science & Engg)");
    }

    public void displayDetails() {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Registration No: " + regNo);
        course();
    }
}


public class l1 {
    public static void main(String[] args) {
        Kiitian student = new Kiitian();
        student.getInput();
        student.displayDetails();
    }
}