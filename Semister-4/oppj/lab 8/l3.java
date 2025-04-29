import java.io.*;
import java.util.Scanner;

public class l3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the source file name: ");
        String sourceFile = sc.nextLine();
        System.out.print("Enter the destination file name: ");
        String destinationFile = sc.nextLine();


        try (FileReader fr = new FileReader(sourceFile);
             FileWriter fw = new FileWriter(destinationFile)) {

            int ch;
            while ((ch = fr.read()) != -1) {
                fw.write(ch);
            }
            System.out.println("File copied using character streams.");
        } catch (IOException e) {
            System.out.println("An error occurred while copying using character streams: " + e.getMessage());
        }

        System.out.print("\nEnter the source file name again for byte stream copy: ");
        sourceFile = sc.nextLine();
        System.out.print("Enter the destination file name again for byte stream copy: ");
        destinationFile = sc.nextLine();

        try (FileInputStream fis = new FileInputStream(sourceFile);
             FileOutputStream fos = new FileOutputStream(destinationFile)) {

            int byteData;
            while ((byteData = fis.read()) != -1) {
                fos.write(byteData);
            }
            System.out.println("File copied using byte streams.");
        } catch (IOException e) {
            System.out.println("An error occurred while copying using byte streams: " + e.getMessage());
        }
    }
}