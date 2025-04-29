import java.io.*;
import java.util.*;
import java.io.IOException;
public class StudentDetails {
    public static void main(String[] args){
        char[] arr=new char[100];

        Scanner x= new Scanner(System.in);
        String name,file,subject;
        int marks;
        System.out.println("Enter name , subject ,marks and file name");
        name=x.nextLine();
        subject=x.nextLine();
        marks=x.nextInt();
        String str = String.valueOf(marks);
        x.nextLine();
        file=x.nextLine();
        try (FileWriter output = new FileWriter(file)){
            output.write("Name: " + name + "\n");
            output.write("Subject: " + subject + "\n");
            output.write("Marks: " + marks + "\n");
            System.out.println("Data has been written to the file.");
            output.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        try(BufferedReader input = new BufferedReader(new FileReader(file))){

            String line;
            while ((line = input.readLine()) != null) {
                System.out.println(line);
            }
            input.close();
        }
        catch(Exception e){
            e.getStackTrace();
        }
    }
}
