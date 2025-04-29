import java.util.Scanner;

 public class student {
     String name;
     int rollNo;
     float cgpa;

     void takeInput(Scanner scanner) {
         System.out.print("Enter student's name: ");
         name = scanner.nextLine();
         System.out.print("Enter roll number: ");
         rollNo = scanner.nextInt();
         System.out.print("Enter CGPA: ");
         cgpa = scanner.nextFloat();
         scanner.nextLine();
     }

     void display() {
         System.out.println("Name: " + name);
         System.out.println("Roll No: " + rollNo);
         System.out.println("CGPA: " + cgpa);
     }


     public static void main(String args[]) {
         Scanner scanner = new Scanner(System.in);

         System.out.print("Enter the number of students: ");
         int n = scanner.nextInt();
         scanner.nextLine();

         student[] students = new student[n];

         for (int i = 0; i < n; i++) {
             System.out.println("Enter details for student " + (i + 1) + ":");
             students[i] = new student();
             students[i].takeInput(scanner);
         }

         System.out.println("\nStudent Details:");
         for (int i = 0; i < n; i++) {
             System.out.println("Student " + (i + 1) + ":");
             students[i].display();
             System.out.println();
         }

         scanner.close();
     }

 }