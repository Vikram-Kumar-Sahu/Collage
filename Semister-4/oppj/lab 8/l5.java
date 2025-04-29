import java.io.*;
import java.util.Scanner;

class l5 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the name of the file: ");
        String fileName = sc.nextLine();

        int charCount = 0;
        int lineCount = 0;
        int wordCount = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;

            while ((line = reader.readLine()) != null) {
                lineCount++;
                charCount += line.length();
                wordCount += line.split(" ").length;
            }

            System.out.println("No. of characters: " + charCount);
            System.out.println("No. of lines: " + lineCount);
            System.out.println("No. of words: " + wordCount);

        } catch (FileNotFoundException e) {
            System.out.println("The file " + fileName + " was not found.");
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file: " + e.getMessage());
        }
    }
}