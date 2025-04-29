import java.io.*;
import java.util.*;

public class studentDetail {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        String name, subject, marks, file,roll;

        System.out.println("Enter Roll No:");
        roll = x.nextLine();
        System.out.println("Enter Name:");
        name = x.nextLine();
        System.out.println("Enter Subject:");
        subject = x.nextLine();
        System.out.println("Enter Marks:");
        marks = x.nextLine();
        System.out.println("Enter File Name:");
        file = x.nextLine();

        try (FileWriter output = new FileWriter(file)) {
            output.write("Name: " + name + "\n");
            output.write("Roll No: " + roll + "\n");
            output.write("Subject: " + subject + "\n");
            output.write("Marks: " + marks + "\n");
            System.out.println("Data has been written to the file.");
        } catch (IOException e) {

            e.printStackTrace();
        }

        try (BufferedReader input = new BufferedReader(new FileReader(file))) {
            System.out.println("\nReading from file:");
            String line;
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {

            e.printStackTrace();
        }
    }
}
