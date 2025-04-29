import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class t1.bil4 {

    public static void main(String[] args) {
        System.out.println("Enter the file names to compare: ");
        Scanner sc = new Scanner(System.in);
        String f1 = sc.nextLine();
        String f2 = sc.nextLine();
        String file1 = f1 + ".bin";
        String file2 = f2 + ".bin";

        try (FileInputStream fis1 = new FileInputStream(file1);
                FileInputStream fis2 = new FileInputStream(file2)) {

            int byte1, byte2;
            int position = 1;

            while ((byte1 = fis1.read()) != -1 && (byte2 = fis2.read()) != -1) {
                if (byte1 != byte2) {
                    System.out
                            .println("Two files are not equal: byte position at which two files differ is " + position);
                    return;
                }
                position++;
            }

            if (fis1.read() != -1 || fis2.read() != -1) {
                System.out.println("Two files are not equal: one file has extra bytes.");
            } else {
                System.out.println("Two files are equal.");
            }

        } catch (IOException e) {
            System.out.println("An error occurred while comparing files: " + e.getMessage());
        }
    }
}