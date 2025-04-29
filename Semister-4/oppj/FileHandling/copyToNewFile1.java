import java.io.*;
import java.util.*;

public class copyToNewFile1 {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.println("Enter the source file and destination file:");
        String src = x.nextLine();
        String dst = x.nextLine();

        try (BufferedReader input = new BufferedReader(new FileReader(src));
             BufferedWriter output = new BufferedWriter(new FileWriter(dst))) {

            String line;
            while ((line = input.readLine()) != null) {
                output.write(line);
                output.newLine(); // Preserve line breaks
            }
            System.out.println("File copied successfully!");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        x.close();
    }
}
