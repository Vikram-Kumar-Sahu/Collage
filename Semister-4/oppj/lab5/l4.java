import java.util.Scanner;

class Account {
    int acc_no;
    double balance;

    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter account number: ");
        acc_no = sc.nextInt();
        System.out.print("Enter balance: ");
        balance = sc.nextDouble();
    }

    public void disp() {
        System.out.println("Account Number: " + acc_no);
        System.out.println("Balance: " + balance);
    }
}

class Person extends Account {
    String name;
    String aadhar_no;

    @Override
    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        name = sc.nextLine();
        System.out.print("Enter Aadhar number: ");
        aadhar_no = sc.nextLine();
    }

    @Override
    public void disp() {
        super.disp();
        System.out.println("Name: " + name);
        System.out.println("Aadhar Number: " + aadhar_no);
    }
}

public class l4 {
    public static void main(String[] args) {
        Person[] persons = new Person[3];

        for (int i = 0; i < 3; i++) {
            persons[i] = new Person();
            System.out.println("Enter details of person " + (i + 1) + ":");
            persons[i].input();
        }

        System.out.println("\nDetails of persons:");
        for (int i = 0; i < 3; i++) {
            System.out.println("Person " + (i + 1) + ":");
            persons[i].disp();
            System.out.println();
        }
    }
}